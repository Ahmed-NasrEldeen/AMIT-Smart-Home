
#include "SevSeg_interface.h"
#include "TIMERS_interface.h"
#include "MCAL/EEPROM/EEPROM_interface.h"
#include "HAL/LED/LED_interface.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include <avr/interrupt.h>
#include <avr/delay.h>
#include <string.h>
#include "APP/auth.h"
u8 counter=0 ,Sec=0;
u8 LCD_c=1000;
u8 led =0;
u8 displayDevices = 1;
//#include <avr/interrupt.h>

char devices [8][10] = {"LED1\0","LED1\0","LED2\0","LED3\0","LED4\0","LED5\0","AC\0","DOOR\0"};

int main(void)
{
	UART_INIT();
	LCD_init();
	KEYPAD_init();
	DIO_SetPinMode(DIO_PORTA,PIN3,OUTPUT); //* 
	LED_INIT();
	LED_MODE(LED0,ON);
	LED_MODE(LED1,ON);
	LED_MODE(LED2,ON);
	LED_MODE(LED3,ON);
	LED_MODE(LED4,ON);
	LED_MODE(LED5,ON);
	sei(); //interrupt enable 
	u8 loginStep = 0; //to check that the username and password are being entered
	char actionStr[30] = ""; // array that receives and stores the username 
	u8 actionStrCounter =0; // to determine the postion of the char that should be inserted
	
	ADC_init();
	DIO_SetPinMode(DIO_PORTC,PIN0,OUTPUT); // to set DC motor as OUTPUT
	TIMER1_INIT();
	Timer0_INIT();
	Timer0_Start();
	DIO_SetPinMode(DIO_PORTA,PIN3,OUTPUT); //*
	DIO_SetPinMode(DIO_PORTA,PIN0,OUTPUT); //*
	DIO_SetPinValue(DIO_PORTD,PIN3,1); // to set Bluetooth HIGH
	DIO_SetPinValue(DIO_PORTD,PIN0,1); // to set LED2 as HIGH
	DIO_SetPinMode(DIO_PORTD,PIN6,OUTPUT); // to set BUZZER as OUTPUT
	DIO_SetPinValue(DIO_PORTD,PIN6,1); // to set BUZZER as HIGH

	while(1)
	{
		
		if(isSystemlocked()){
			continue;
		}

		u8 val=ADC_Read(ADC1)/4;                 // temperate value (val) reads value of ADC and the reading should be always divided by 4
		if(val >28){                             // if temperature is >28
			DIO_SetPinValue(DIO_PORTC,PIN0,ON);  // DC MOTOR ON
			}if(val<21){                         // if temperature is <21
			DIO_SetPinValue(DIO_PORTC,PIN0,OFF); // DC MOTOR OFF
		}
		char keypadKey = KEYPAD_GetKey();        
		if(keypadKey != NO_KEY ){                // something is pressed now
			if(displayDevices==1 ){              // check if something is written on the screen to clear it
				LCD_Clear();

			}
			displayDevices = 0;
			LCD_Write_CHAR(keypadKey);
			_delay_ms(200);                     // loop is faster so that the button would be pressed only one time
			actionStr[actionStrCounter] = keypadKey;
			actionStrCounter++;
			if(!is_Offline_User_Logged() && ! loginStep){ //check if no user is already logged 
				LCD_Clear();               
				loginStep++;                              // get password next time
				actionStrCounter--;                       // reset the string in order to input username
				LCD_Write_String("Enter username");       
				LCD_GOTO(1,0);                            // next line
				continue;
			}
			if(keypadKey == '*'){                        // username, password or action is entered (* is like an OK button)
				actionStr[actionStrCounter-1]='\0';      // select which action is required 
			       
				if(!is_Offline_User_Logged()){           
					if(loginStep == 1){                   // username is entered 
						actionStr[actionStrCounter-1]=' '; // getting password
						LCD_Clear();
						LCD_Write_String("Enter password"); 
						LCD_GOTO(1,0);                       // ordering user to enter password
						loginStep++;
						continue;
					}
					if(loginStep == 2){                      // password is entered
						actionStr[actionStrCounter-1]=' ';   
						actionStr[actionStrCounter]='0';
						actionStrCounter++;                  // next action ---> Login
						u8 loginStatus = login(actionStr,0); // login status is true
						if(loginStatus){
							LCD_Clear();
							LCD_Write_String("Login success");
							displayDevices=1;               // continue displaying the other modules after login
							}else{
							LCD_Clear();
							LCD_Write_String("Login fail"); // login failed due to incorrect username or password
							_delay_ms(1000);
							LCD_Clear();
							LCD_Write_String("Enter username");
							LCD_GOTO(1,0);
							loginStep=1;
						}
						loginStep=1;                        // restart Login steps
						actionStrCounter=0;
						
					}
					
					}else{          
					//offline user logged
					
					LCD_Clear();
				
					if(is_Remote_User_Logged() && is_Remote_User_Admin() && !get_Admin_Set_Autherization()){ // if admin is logged remotely offline user must take permission  
						LCD_Clear();
						LCD_Write_String("asking for");                                           
						LCD_GOTO(1,0);
						LCD_Write_String("permission");
						ask_Admin_To_Allow_User();        //requesting access via bluetooth                             
						displayDevices=1;               

						continue;                        // skips any other actions
					}
					if(is_Remote_User_Logged()&& is_Remote_User_Admin() && ! get_Admin_Allow_User() ){ // case that admin did not give permission
						LCD_Clear();
						LCD_Write_String("Not allowed by");
						LCD_GOTO(1,0);
						LCD_Write_String("admin");

						}else{
						takeAction(actionStr,0); //permission granted
					}
					actionStrCounter=0; //reset counter to get ready for a new string
					displayDevices=1;
				}
			}
		}
	}
}

u8 LCDDevice = 0; // counter to detect current device displayed
ISR(TIMER0_OVF_vect){     // interrupt service routine depends on timer zero overflow vector
	counter++;            
	if(counter==245) {    // 1 second passed
		counter=0;        //reset counter
		TCNT0=220;        
		Sec++;
	}
	if(Sec==60) Sec=0;
	if(isSystemlocked() && counter == 0){ //system is locked if password is entered wrong 
		if(Sec%2==0){                     // Toggling LEDS each second
			LED_MODE(LED0,ON);            
			LED_MODE(LED1,ON);
			LED_MODE(LED2,ON);
			LED_MODE(LED3,ON);
			LED_MODE(LED4,ON);
			DIO_SetPinValue(DIO_PORTD,PIN6,OFF); // BUZZER ON (ON Works with LOW instead of HIGH)
			LCD_Clear();
			LCD_Write_String("System locked");   

			}else{                              // system is unlocked and all LEDS are OFF and BUZZER is OFF(ON Works with HIGH instead of LOW)
			LED_MODE(LED0,OFF);
			LED_MODE(LED1,OFF);
			LED_MODE(LED2,OFF);
			LED_MODE(LED3,OFF);
			LED_MODE(LED4,OFF);
			DIO_SetPinValue(DIO_PORTD,PIN6,ON);


		}
		return;
	}
	if( displayDevices && counter == 244 && !isSystemlocked() ){ // Displaying current selected device
		LCD_Clear();
		char *str= devices[0];                                   // Pointer for the current device
		for (int i =0; i<8;i++)                                  // Display Device name
		{
			if(devices[LCDDevice][i]== '\0')break;              
			LCD_Write_CHAR(devices[LCDDevice][i]);              
		}
		
		LCD_Write_CHAR(' ');  
		int value=0;
		switch (LCDDevice)                                     // Get the device OUTPUT is LOW or HIGH from DIO
		{
			case 0:                                            // LED0
			value=DIO_GetPinValue(DIO_PORTC,PIN2);
			if(value){
				LCD_Write_String("ON");
				}else{
				LCD_Write_String("OFF");
			}
			break;
			case 1:                                            //LED1
			value=DIO_GetPinValue(DIO_PORTC,PIN7);
			if(value){
				LCD_Write_String("ON");
				}else{
				LCD_Write_String("OFF");
			}
			break;
			case 2:                                            //LED2
			value=DIO_GetPinValue(DIO_PORTD,PIN3);
			if(value){
				LCD_Write_String("ON");
				}else{
				LCD_Write_String("OFF");
			}
			break;
			case 3:                                            //LED3
			value=DIO_GetPinValue(DIO_PORTC,PIN1);
			if(value){
				LCD_Write_String("ON");
				}else{
				LCD_Write_String("OFF");
			}
			break;
			case 4:                                            //LED4
			value=DIO_GetPinValue(DIO_PORTD,PIN2);
			if(value){
				LCD_Write_String("ON");
				}else{
				LCD_Write_String("OFF");
			}
			break;
			case 5:                                            //LED5
			value=DIO_GetPinValue(DIO_PORTB,PIN0);
			if(value){
				LCD_Write_String("ON");
				}else{
				LCD_Write_String("OFF");
			}
			break;
			case 6:                                           
			value=DIO_GetPinValue(DIO_PORTC,PIN0);             //AC (DC Motor)
			if(value){
				LCD_Write_String("ON");
				}else{
				LCD_Write_String("OFF");
			}
			break;
			case 7:                                            //Door (Servo Motor)
			if(getDoorState()){
				LCD_Write_String("OPENED");
				}else{
				LCD_Write_String("CLOSED");
			}
			break;
		}
		LCDDevice++;                                          // Display next device
		if(LCDDevice > 7){
			LCDDevice=0;
		}
	};

}

static char logUserNamePassword[20] = ""; 
u8 logCharCounter=0;
u8 enterPassword = 0;
u8 enterPasswordSent =0;
u8 authMessage =0;
static char actionStr[30] = "";
static actionStrCounter = 0;
static resetActionStrCounter = 1;
u8 registerStep = 0;
u8 loginStep = 0;

ISR(USART_RXC_vect){                               //Interrupt Service Routine for Bluetooth Module/ Actions

	char receivedChar = UDR;                       //Char recieved from UART
	if(!is_Remote_User_Logged() && ! authMessage){ // if remote user is not logged and a message is not sent to enter username
		char message[] ="Please enter username";
		UART_SendString(message);                  // send message to Bluetooth device
		loginStep++;                               
		authMessage=1;                             // message is sent
		actionStrCounter=0;                           
		return;
	}
	actionStr[actionStrCounter] = receivedChar;   //concatinate the string   
	actionStrCounter++;                           
	if(receivedChar == '*'){                      //OK
		actionStrCounter--;
		actionStr[actionStrCounter] = '\0';       
		if(is_Remote_User_Logged()){              //in case remote user in logged in
			
			if(registerStep>0){                   // admin is registering a new user

				if(registerStep == 1){            // a new username is entered
					actionStr[actionStrCounter] = ' ';
					actionStrCounter++;
					registerStep++;
					char message[] ="Please enter new password";
					UART_SendString(message);     // a password is sent via Bluetooth
					return;
					
				}
				if(registerStep==2){             // asks if user is remote or offline
					actionStr[actionStrCounter] = ' ';
					actionStrCounter++;
					registerStep++;
					char message[] = "Please enter 1 if user is remote otherwise 0";
					UART_SendString(message);
					return;
					
				}
				if(registerStep == 3){          // asks if user is admin or normal user
					registerStep++;
					char message[] = "Please enter 1 if user is admin otherwise 0";
					UART_SendString(message);
					return;
					
				}
				if(registerStep == 4 ){
			
					static char  usernamePasswordCopy[30] ="";
					strcpy(usernamePasswordCopy, actionStr);        // takes a copy of the username and password
					
					u8 registerStatus = register_User(usernamePasswordCopy); // check for registering status (success or failure)
					registerStep = 0;                                        // reset registering steps
					if(registerStatus ==2){                                  // username is a duplicate
						char message[] = "User already exists";
						UART_SendString(message);
						}else{                                               //Registering is a success
						char message[] = "Register success";
						UART_SendString(message);
					}
					
				}
				}else{                                                      
				// action is taken (Ex: LED toggling)
				u8 actionStatus =  takeAction(actionStr,is_Remote_User_Admin());
				if(actionStatus == 83){                                     // normal user trying to register a new user so action is denied
					if(!is_Remote_User_Admin()){
						char message[] ="Action denied";
						UART_SendString(message);
					}
					else{
							char message[] ="Please enter new username";    // registering a new user
							UART_SendString(message);
							registerStep++;
						
					}
				actionStrCounter=0;
				}
				if(actionStatus == 50 && get_Asked_Admin()){               // admin allowed normal user to control system
					LCD_Clear();
					LCD_Write_String("admin allowed");
					LCD_GOTO(1,0);
					LCD_Write_String("actions");
					set_Admin_Allow_User(1);
					LCD_Clear();
				}
				if(actionStatus == 20 && get_Asked_Admin()){              // admin denied normal user to control system
					LCD_Clear();
					LCD_Write_String("admin not");
					LCD_GOTO(1,0);
					LCD_Write_String("allowing actions");
					set_Admin_Allow_User(0);
					
				}
				
			}
			
		}
		else{                                                           // user trying to log in 
			if(loginStep ==1){                                          // username entered so now password should be entered
				actionStr[actionStrCounter] = ' ';
				actionStrCounter++;
				loginStep++;
				char message[] ="Please enter password";
				UART_SendString(message);
				return;
			}
			if(loginStep ==2){                                         
				actionStr[actionStrCounter] = ' ';
				actionStrCounter++;
				actionStr[actionStrCounter] = '1';                                 
				actionStrCounter++;
				actionStr[actionStrCounter] = '\0';
				loginStep=1;
				u8 loginStatus = login(actionStr,1);                               // check if username and password are correct
				if(loginStatus == 1){                                        
					char message[] = "login success";
					UART_SendString(message);
					}else{
					char message[] = "login fail\n";
					UART_SendString(message);
					char message1[] = "Please enter username";
					UART_SendString(message1);
				}
			}
		}
		if(resetActionStrCounter){
			actionStrCounter=0;
		}
	}
}



