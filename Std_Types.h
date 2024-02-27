/**
 * @file Std_Types.h
 * @author Ahmed Soliman
 * @brief AUTOSAR Base - Standard Types definitions.
 * @version 1.0.0
 * @details AUTOSAR standard types header file.
 *          It contains all types that are used across several modules of the basic software and that are platform and compiler independent
 */

/**=========================================================
 * project : AUTOSAR 4.4.0 MCAL
 * platform : ARM
 * Peripheeral : STM32F103
 * Autosar Version : 4.4.0
 * Autosar Revision : ASR_REL_4_0_REV_0000
 * SW Version : 1.0.0 
 ===========================================================*/

#ifndef STD_TYPES_H
#define STD_TYPES_H

/**==================================================================
                        INCLUDES
=====================================================================*/
#include "Platform_Types.h"
#include "Compiler.h"

/**==================================================================
                SOURCE FILE VERSION INFORMATION
=====================================================================*/
/**
 * @brief Parameters that shall be published within the standard types header file and also in module's description file
 */
#define STD_VENDOR_ID 123
#define STD_AR_RELEASE_MAJOR_VERSION        4
#define STD_AR_RELEASE_MINOR_VERSION        4
#define STD_AR_RELEASE_REVISION_VERSION     0

#define STD_SW_MAJOR_VERSION                1
#define STD_SW_MINOR_VERSION                0
#define STD_SW_PATCH_VERSION                0
/**==================================================================
                FILE VERSION CHECK
=====================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                               \
      (STD_AR_RELEASE_MAJOR_VERSION    != PLATFORM_AR_RELEASE_MAJOR_VERSION)     || \
      (STD_AR_RELEASE_MINOR_VERSION    != PLATFORM_AR_RELEASE_MINOR_VERSION)     || \
      (STD_AR_RELEASE_REVISION_VERSION != PLATFORM_AR_RELEASE_REVISION_VERSION)     \
    )
      #error "Autosar versions of PlatformTypes and std_Types are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                               \
      (STD_AR_RELEASE_MAJOR_VERSION    != COMPILER_AR_RELEASE_MAJOR_VERSION)     || \
      (STD_AR_RELEASE_MINOR_VERSION    != COMPILER_AR_RELEASE_MINOR_VERSION)     || \
      (STD_AR_RELEASE_REVISION_VERSION != COMPILER_AR_RELEASE_REVISION_VERSION)     \
    )
      #error "Autosar versions of Compiler and std_Types are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                               \
      (STD_SW_MAJOR_VERSION  !=  PLATFORM_SW_MAJOR_VERSION)                      || \
      (STD_SW_MINOR_VERSION  !=  PLATFORM_SW_MINOR_VERSION)                      || \
      (STD_SW_PATCH_VERSION  !=  PLATFORM_SW_PATCH_VERSION)                         \
    )
      #error "software versions of std_Types and PlatformTypes are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                               \
      (STD_SW_MAJOR_VERSION  !=  COMPILER_SW_MAJOR_VERSION)                      || \
      (STD_SW_MINOR_VERSION  !=  COMPILER_SW_MINOR_VERSION)                      || \
      (STD_SW_PATCH_VERSION  !=  COMPILER_SW_PATCH_VERSION)                         \
    )                                                                                     
      #error "std_Types versions of std and Compiler are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                                 \
      (STD_VENDOR_ID  !=  COMPILER_VENDOR_ID)                                          \
    )
      #error "Vendor id versions of Dio.h and Dio_cfg are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                                 \
      (STD_VENDOR_ID  !=  PLATFORM_VENDOR_ID)                                          \
    )
      #error "Vendor id versions of Dio.h and Dio_cfg are different"
#endif
#endif

/**
 * @brief standard API return Sucsess
 * @implements E_OK_Enumeration
 */
#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 0x00u
typedef unsigned char StatusType; /* OSEK compliance */
#endif
/**
 * @brief standard API return Failed
 * @implements E_NOT_OK_Enumeration
 */
#define E_NOT_OK 0x01u

/**
 * @brief Physical state HIGH
 * @implements STD_HIGH_Enumeration
*/
#define STD_HIGH 0x01u /* Physical state 5V or 3.3V */
/**
 * @brief Physical state LOW
 * @implements STD_LOW_Enumeration
*/
#define STD_LOW 0x00u /* Physical state 0V */

/**
 * @brief active logical State 
 * @implements STD_ACTIVE_Enumeration
*/
#define STD_ACTIVE 0x01u /* Logical state active */
/**
 * @brief idle Logical state
 * @implements STD_IDLE_Enumeration
*/
#define STD_IDLE 0x00u /* Logical state idle */

/**
 * @brief StandardType ON
 * @implements STD_ON_Enumeration
*/
#define STD_ON 0x01u
/**
 * @brief StandardType OFF
 * @implements STD_OFF_Enumeration
*/
#define STD_OFF 0x00u

/**
 * @brief This type can be used as standard API return type which is shared between the RTE
    and the BSW modules
 * @Range E_OK          0
          E_NOT_OK      1
          0x02-0x3F     Available to user specific errors
 * @implements Std_ReturnType_uint_8
*/
typedef uint8 Std_ReturnType;

/**
 * @brief This type shall be used to request the version of a BSW module using the <Module
          name>_GetVersionInfo() function.
 * @implements Std_VersionInfoType_structure
 */
typedef struct 
{
    uint16 vendorID;                /*vendorID*/
    uint16 moduleID;                /*moduleID*/
    uint8 sw_major_version;         /*sw_major_version*/ 
    uint8 sw_minor_version;         /*sw_minor_version*/ 
    uint8 sw_patch_version;         /*sw_patch_version*/

}Std_VersionInfoType;

#endif