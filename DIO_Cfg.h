/**
 * @file DIO.h
 * @author Ahmed Soliman
 * @brief AUTOSAR Base Dio high level code
 * @version 1.0.0
 * @details DIO driver header file contains API Specification , funtions, and variables 
 */

/**=========================================================
 * project : AUTOSAR 4.4.0 MCAL
 * platform : ARM
 * Peripheeral : STM32F103
 * Autosar Version : 4.4.0
 * Autosar Revision : ASR_REL_4_0_REV_0000
 * SW Version : 1.0.0 
 ===========================================================*/

#ifndef DIO_CFG_H
#define DIO_CFG_H
/**==================================================================
                        INCLUDES
=====================================================================*/
#include "Std_Types.h"
/**==================================================================
                SOURCE FILE VERSION INFORMATION
=====================================================================*/
/**
 * @brief Parameters that shall be published within the standard types header file and also in module's description file
 */
#define DIO_VENDOR_ID_CFG                       123
#define DIO_MODULE_ID_CFG                       120

#define DIO_AR_RELEASE_MAJOR_VERSION_CFG        4
#define DIO_AR_RELEASE_MINOR_VERSION_CFG        4
#define DIO_AR_RELEASE_REVISION_VERSION_CFG     0

#define DIO_SW_MAJOR_VERSION_CFG                1
#define DIO_SW_MINOR_VERSION_CFG                0
#define DIO_SW_PATCH_VERSION_CFG                0

/**==================================================================
                FILE VERSION CHECK
=====================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                                   \
      (STD_AR_RELEASE_MAJOR_VERSION    != DIO_AR_RELEASE_MAJOR_VERSION_CFG   )       || \
      (STD_AR_RELEASE_MINOR_VERSION    != DIO_AR_RELEASE_MINOR_VERSION_CFG   )       || \
      (STD_AR_RELEASE_REVISION_VERSION != DIO_AR_RELEASE_REVISION_VERSION_CFG)          \
    )
      #error "Autosar versions of Dio_cfg and std_Types are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                        \
      (STD_SW_MAJOR_VERSION   != DIO_SW_MAJOR_VERSION_CFG)                || \
      (STD_SW_MINOR_VERSION   != DIO_SW_MINOR_VERSION_CFG)                || \
      (STD_SW_PATCH_VERSION   != DIO_SW_PATCH_VERSION_CFG)                   \
    )      
      #error "Software versions of std_Types and Dio_cfg are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ( DIO_VENDOR_ID_CFG != STD_VENDOR_ID)      
      #error "Vendor IDs of std_Types and Dio_cfg are different"
#endif
#endif

/**==================================================================
                DIO TYPE DEFINIATIONS
=====================================================================*/
/**
 * @brief Numeric ID of a DIO channel.
 */
typedef uint16 Dio_ChannelType;

/**
 * @brief Numeric ID of a DIO port
 */
typedef uint16 Dio_PortType;

/**
 * @brief Type for the definition of a channel group, which consists of several adjoining channels within a port
 * 
 */

typedef struct
{
    uint32 mask;  /*This element mask which defines the positions of the channel group*/
    uint8 offset; /*This element shall be the position of the Channel Group on the port, counted from the LSB*/
    Dio_PortType port; /*This shall be the port on which the Channel group is defined*/
}Dio_ChannelGroupType;

/**
 * @brief These are the possible levels a DIO channel can have (input or output)
 * @Range 
 * STD_LOW  --> Physical state 0V
 *  STD_HIGH --> Physical state 5V or 3.3V
 */
typedef uint8 Dio_LevelType;

/**
 * @brief f the μC owns ports of different port widths (e.g. 4, 8,16...Bit) Dio_PortLevelType inherits the size of the largest por
 * 
 */
typedef uint16 Dio_PortLevelType;
#endif
