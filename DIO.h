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

#ifndef DIO_H
#define DIO_H

/**==================================================================
                        INCLUDES
=====================================================================*/
#include "Std_Types.h"
#include "DIO_Cfg.h"

/**==================================================================
                SOURCE FILE VERSION INFORMATION
=====================================================================*/
/**
 * @brief Parameters that shall be published within the standard types header file and also in module's description file
 */
#define DIO_VENDOR_ID                       123
#define DIO_MODULE_ID                       120
#define DIO_AR_RELEASE_MAJOR_VERSION        4
#define DIO_AR_RELEASE_MINOR_VERSION        4
#define DIO_AR_RELEASE_REVISION_VERSION     0

#define DIO_SW_MAJOR_VERSION                1
#define DIO_SW_MINOR_VERSION                0
#define DIO_SW_PATCH_VERSION                0
/**==================================================================
                FILE VERSION CHECK
=====================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                                  \
      (STD_AR_RELEASE_MAJOR_VERSION    != DIO_AR_RELEASE_MAJOR_VERSION)             || \
      (STD_AR_RELEASE_MINOR_VERSION    != DIO_AR_RELEASE_MINOR_VERSION)             || \
      (STD_AR_RELEASE_REVISION_VERSION != DIO_AR_RELEASE_REVISION_VERSION)             \
    )
      #error "Autosar versions of DIO and std_Types are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                                 \
      (DIO_AR_RELEASE_MAJOR_VERSION     != DIO_AR_RELEASE_MAJOR_VERSION_CFG)       || \
      (DIO_AR_RELEASE_MINOR_VERSION     != DIO_AR_RELEASE_MINOR_VERSION_CFG)       || \
      (DIO_AR_RELEASE_REVISION_VERSION  != DIO_AR_RELEASE_REVISION_VERSION_CFG)       \
    )      
      #error "Autosar versions of Dio.h and Dio_cfg are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                                 \
      (DIO_SW_MAJOR_VERSION  !=  DIO_SW_MAJOR_VERSION_CFG)                         || \
      (DIO_SW_MINOR_VERSION  !=  DIO_SW_MINOR_VERSION_CFG)                         || \
      (DIO_SW_PATCH_VERSION  !=  DIO_SW_PATCH_VERSION_CFG)                            \
    )
      #error "software versions of Dio.h and Dio_cfg are different"
#endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (                                                                                 \
      (DIO_VENDOR_ID  !=  DIO_VENDOR_ID_CFG)                                          \
    )
      #error "Vendor id versions of Dio.h and Dio_cfg are different"
#endif
#endif

/**==================================================================
                ERROR CLASSIFICATION
=====================================================================*/
/**
 * @brief Invalid channel requested
 * 
 */
#define DIO_E_PARAM_INVALID_CHANNEL_ID  ((uint8)0x0A)

/**
 * @brief Invalid port requested
 * 
 */
#define DIO_E_PARAM_INVALID_PORT_ID     ((uint8)0x14)

/**
 * @brief Invalid channel group requested
 * 
 */
#define DIO_E_PARAM_INVALID_GROUP       ((uint8)0x1F)

/**
 * @brief API service called with a NULL pointer
 * 
 */
#define DIO_E_PARAM_POINTER             ((uint8)0x20)


/**==================================================================
                SERVICE ID
=====================================================================*/
/**
 * @brief @p Dio_ReadChannel service id
 */
#define DIO_READCHANNEL_SERVICE_ID  ((uint8)0x00)

/**
 * @brief @p Dio_WriteChannel service id
 */
#define DIO_WRITECHANNEL_SERVICE_ID  ((uint8)0x01)

/**
 * @brief @p Dio_ReadPort service id
 */
#define DIO_READPORT_SERVICE_ID  ((uint8)0x02)

/**
 * @brief @p Dio_WritePort service id
 */
#define DIO_WRITEPORT_SERVICE_ID  ((uint8)0x03)

/**
 * @brief @p Dio_ReadChannelGroup  service id
 */
#define DIO_READCHANNELGROUP_SERVICE_ID  ((uint8)0x04)

/**
 * @brief @p Dio_WriteChannelGroup  service id
 */
#define DIO_WRITECHANNELGROUP_SERVICE_ID  ((uint8)0x05)

/**
 * @brief @p Dio_GetVersionInfo  service id
 */
#define DIO_GETVERSIONINFO_SERVICE_ID  ((uint8)0x12)

/**
 * @brief @p Dio_FlipChannel  service id
 */
#define DIO_FLIPCHANNEL_SERVICE_ID  ((uint8)0x11)

/**
 * @brief @p Dio_MaskedWritePort  service id
 */
#define DIO_MASKEDWRITEPORT_SERVICE_ID  ((uint8)0x13)

/**
 * @brief Instance ID of the DIO driver 
 */
#define DIO_INSTANCE_ID     ((uint8)0x00)

/**==================================================================
                FUNCTIONS PROTOTYPES
=====================================================================*/

/**
 * @brief Returns the value of the specified DIO channel.
 * @arg ChannelId --> ID of DIO channel
 * @return Dio_LevelType 
 *          STD_HIGH The physical level of the corresponding Pin is STD_HIGH
 *          STD_LOW The physical level of the corresponding Pin is STD_LOW
 */
FUNC(Dio_LevelType,DIO_CODE) Dio_ReadChannel
(
  VAR(Dio_ChannelType,AUTOMATIC)ChannelId
);

/**
 * @brief Service to set a level of a channel
 * @arg ChannelId --> ID of DIO channel
 *      Level --> Value to be written
 * @return void
 */
FUNC(void,DIO_CODE) Dio_WriteChannel
(
  VAR(Dio_ChannelType,AUTOMATIC)ChannelId,
  VAR(Dio_LevelType,AUTOMATIC)Level
);

/**
 * @brief Returns the level of all channels of that port.
 * @arg PortId --> ID of DIO Port
 * @return Dio_PortLevelType --> Level of all channels of that port
 */
FUNC(Dio_PortLevelType,DIO_CODE) Dio_ReadPort
(
  VAR(Dio_PortType,AUTOMATIC)PortId
);

/**
 * @brief Service to set a value of the port
 * @arg PortId --> ID of DIO Port
 *      Level --> Value to be written
 * @return void
 */
FUNC(void,DIO_CODE) Dio_WritePort
(
  VAR(Dio_PortType,AUTOMATIC)PortId,
  VAR(Dio_PortLevelType,AUTOMATIC)Level
);

/**
 * @brief This Service reads a subset of the adjoining bits of a port
 * @arg ChannelGroupIdPtr --> Pointer to ChannelGroup
 * @return Dio_PortLevelType --> Level of a subset of the adjoining bits of a port
 */
FUNC(Dio_PortLevelType,DIO_CODE) Dio_ReadChannelGroup
(
  P2CONST(Dio_ChannelGroupType,AUTOMATIC,DIO_APPL_CONST)ChannelGroupIdPtr
);

/**
 * @brief Service to set a subset of the adjoining bits of a port to a specified level.
 * @arg ChannelGroupIdPtr --> Pointer to ChannelGroup
 *      Level --> Value to be written
 * @return void
 */
FUNC(void,DIO_CODE) Dio_WriteChannelGroup
(
  P2CONST(Dio_ChannelGroupType,AUTOMATIC,DIO_APPL_CONST)ChannelGroupIdPtr,
  VAR(Dio_PortLevelType,AUTOMATIC)Level
);

/**
 * @brief Service to get the version information of this module
 * @arg VersionInfo --> Pointer to where to store the version information of this module
 * @return void
 */
FUNC(void,DIO_CODE) Dio_GetVersionInfo
(
  P2VAR(Std_VersionInfoType,AUTOMATIC,DIO_APPL_DATA)VersionInfo
);

/**
 * @brief Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip
 * @arg ChannelId --> ID of DIO channel
 * @return Dio_LevelType 
 *        STD_HIGH: The physical level of the corresponding Pin is STD_HIGH.
 *        STD_LOW: The physical level of the corresponding Pin is STD_LOW.
 */
FUNC(Dio_LevelType,DIO_CODE) Dio_FlipChannel
(
  VAR(Dio_ChannelType,AUTOMATIC)ChannelId
);

/**
 * @brief Service to set the value of a given port with required mask.
 * @arg PortId --> ID of DIO Port
*       Level --> Value to be written
*       Mask --> Channels to be masked in the por
 * @return void
 */
FUNC(void,DIO_CODE) Dio_MaskedWritePort
(
  VAR(Dio_PortType,AUTOMATIC)PortId,
  VAR(Dio_PortLevelType,AUTOMATIC)Level,
  VAR(Dio_PortLevelType,AUTOMATIC)Mask
);

#endif
