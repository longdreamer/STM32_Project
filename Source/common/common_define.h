/**
  ******************************************************************************
  * @file    common_define.h
  * @author  fei long
  * @version V1.0
  * @date    2017-12-23
  * @brief   General defines,typedefs,structs,etc used by other module
  ******************************************************************************
  * @attention 
  * 
  *
  ******************************************************************************
  */ 

#ifndef __COMMON_DEFINE_H_
#define __COMMON_DEFINE_H_
/*Boolean type define*/
#ifndef FALSE
#define FALSE (0)
#endif

#ifndef TRUE
#define TRUE (1)
#endif

#ifndef NULL
#define NULL 0
#endif

/**@name Typedefs for 8, 16, and 32 bit wide types.
 *@{
 */
typedef signed char				    		T_S8;
typedef unsigned char			    		T_U8;
typedef signed short			    		T_S16;
typedef unsigned short		    	  T_U16;
typedef signed long				    		T_S32;
typedef unsigned long			    		T_U32;
typedef signed long				    		T_SWord;
typedef unsigned long			    		T_UWord;
typedef signed long long int		  T_S64;
typedef unsigned long long int    T_U64;
/**@}
 */

typedef enum{
    E_FALSE,
    E_TRUE
}TE_BOOLEAN;

/**@name Limits for the fixed-width types.
  *@{
	*/
#define MAX_T_S8    0x7F
#define MIN_T_S8    (-128)
#define MAX_T_S16   0x7FFF
#define MIN_T_S16   (-32768)
#define MAX_T_S32   0x7FFFFFFF
#define MIN_T_S32   (-2147483647L - 1)
#define MAX_T_S64   0x7FFFFFFFFFFFFFFF
#define MIN_T_S64   (-9223372036854775807LL - 1)

#define MAX_T_U8    0xFF
#define MIN_T_U8    0
#define MAX_T_U16   0xFFFF
#define MIN_T_U16   0
#define MAX_T_U32   0xFFFFFFFF
#define MIN_T_U32   0
#define MAX_T_U64   0xFFFFFFFFFFFFFFFF
#define MIN_T_U64   0
/**
 *@}
 */


#endif  
/********************END of FILE************************************/
