/**
 * @file Platform_Types.h
 * @author Ahmed Soliman
 * @brief AUTOSAR Base - Platform dependent data type definitions
 * @version 1.0.0
 * @details AUTOSAR Platform types header file.
 *          It contains all platform dependent types and symbols.
 *          Those types must be abstracted in order to become platform and compiler independent
 */

/**=========================================================
 * project : AUTOSAR 4.4.0 MCAL
 * platform : ARM
 * Peripheeral : STM32F103
 * Autosar Version : 4.4.0
 * Autosar Revision : ASR_REL_4_0_REV_0000
 * SW Version : 1.0.0 
 ===========================================================*/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H


/**==================================================================
                SOURCE FILE VERSION INFORMATION
=====================================================================*/
/**
 * @brief Parameters that shall be published within the standard types header file and also in module's description file
 */
#define PLATFORM_VENDOR_ID                       123
#define PLATFORM_AR_RELEASE_MAJOR_VERSION        4
#define PLATFORM_AR_RELEASE_MINOR_VERSION        4
#define PLATFORM_AR_RELEASE_REVISION_VERSION     0

#define PLATFORM_SW_MAJOR_VERSION                1
#define PLATFORM_SW_MINOR_VERSION                0
#define PLATFORM_SW_PATCH_VERSION                0

/**
 * @brief register width of the CPU used
 * 
*/
#define CPU_TYPE_8  8        // -- Indicating a 8 bit processor
#define CPU_TYPE_16 16       // -- Indicating a 16 bit processor
#define CPU_TYPE_32 32       // -- Indicating a 32 bit processor
#define CPU_TYPE_64 64       // -- Indicating a 64 bit processor
/**
 * @brief big endian bit ordering
 * 
*/
#define MSB_FIRST 0
/**
 * @brief little endian bit ordering
 * 
*/
#define LSB_FIRST 1

/**
 * @brief big endian byte ordering
 * 
 */
#define HIGH_BYTE_FIRST 0
/**
 * @brief little endian byte ordering
 * 
*/
#define LOW_BYTE_FIRST 1


/**
 * @brief CPU register width
 * @implements CPU_TYPE_Enumeration
 * 
 * @Range 
 *       CPU_TYPE_8     Indicating a 8 bit processor
 *       CPU_TYPE_16    Indicating a 16 bit processor
 *       CPU_TYPE_32    Indicating a 32 bit processor
 *       CPU_TYPE_64    Indicating a 64 bit processor
 */
#define CPU_TYPE    CPU_TYPE_32
/**
 * @brief  bit order on register level
 * @implements CPU_BIT_ORDER_Enumeration
 * @Range 
 *   MSB_FIRST  big endian bit ordering
 *   LSB_FIRST  littile endian bit ordering
 */
#define CPU_BIT_ORDER   LSB_FIRST

/**
 * @brief    byte order on memory level
 * @implements CPU_BYTE_ORDER_Enumeration
 * @Range 
 *   HIGH_BYTE_FIRST    big endian byte ordering
 *   LOW_BYTE_FIRST     little endian byte ordering
 */
#define CPU_BYTE_ORDER  LOW_BYTE_FIRST

/**
 * @brief The standard AUTOSAR type boolean True
 * @implements TRUE_Enumeration
 */
#ifndef TRUE
#define TRUE 1
#endif
/**
 * @brief The standard AUTOSAR type boolean False
 * @implements FALSE_Enumeration
 */
#ifndef FALSE
#define FALSE 0
#endif

#if CPU_TYPE == CPU_TYPE_32
typedef unsigned char boolean;
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef unsigned long uint8_least;
typedef unsigned long uint16_least;
typedef unsigned long uint32_least;
typedef signed long sint8_least;
typedef signed long sint16_least;
typedef signed long sint32_least;
typedef float float32;
typedef double float64;
#elif CPU_TYPE == CPU_TYPE_8
typedef unsigned char boolean;
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8_least;
typedef unsigned char uint8_least;
typedef signed short sint16_least;
typedef unsigned short uint16_least;
typedef signed long sint32_least;
typedef unsigned long uint32_least;
typedef float float32;
typedef double float64;
#elif CPU_TYPE == CPU_TYPE_16
typedef unsigned char boolean;
typedef signed char sint8;
typedef unsigned char uint8;
typedef signed short sint16;
typedef unsigned short uint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8_least;
typedef unsigned char uint8_least;
typedef signed short sint16_least;
typedef unsigned short uint16_least;
typedef signed long sint32_least;
typedef unsigned long uint32_least;
typedef float float32;
typedef double float64;
#elif CPU_TYPE == CPU_TYPE_64
typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;
typedef unsigned int uint8_least;
typedef unsigned int uint16_least;
typedef unsigned int uint32_least;
typedef signed int sint8_least;
typedef signed int sint16_least;
typedef signed int sint32_least;
typedef float float32;
typedef double float64;
#endif

#endif