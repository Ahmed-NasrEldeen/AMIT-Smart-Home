
/*
* BIT_MATH.h
*
* Created: 9/10/2022 11:23:24 AM
*  Author: En.EslamEid
*/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define  CLR_BIT(REG,BN)  ((REG)&=(~(1<<(BN))))
#define  SET_BIT(REG,BN)  ((REG)= (REG)|(1<<(BN)))


#define  TOG_BIT(REG,BN)  ((REG)^=(1<<(BN)))
#define  GET_BIT(REG,BN)  (((REG)>>(BN))&1)
#define  SET_BIT_Value(REG,BN,VAL)    (((VAL)==1)? SET_BIT(REG,BN):CLR_BIT(REG,BN))


 #define IS_HIGH(REG,N) 	 (((REG)>>(N))&1)
 #define IS_LOW(REG,N)	 (!(((REG)>>(N))&1))
 #define ROR(REG,N)       (((REG)>>(N))|((REG)<<(8-(N))))
 #define ROL(REG,N)       (((REG)<<(N))|((REG)>>(8-(N))))


#endif /* BIT_MATH_H_ */