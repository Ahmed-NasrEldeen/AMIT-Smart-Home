/*
 * auth.h
 *
 * Created: 1/1/2023 7:41:44 PM
 *  Author:D
 */ 


#ifndef AUTH_H_
#define AUTH_H_

u8 is_Remote_User_Logged();
u8 login(char *usernamePassword , u8 remote);
u8 isSystemlocked();
u8 is_Remote_User_Admin();
u8 is_Offline_User_Logged();
u8 register_User(char *usernamePassword);
u8 ask_Admin_To_Allow_User();
u8 set_Admin_Allow_User(u8 val);
u8 get_Asked_Admin();
u8 get_Admin_Set_Autherization();
u8 get_Admin_Allow_User();


#endif /* AUTH_H_ */