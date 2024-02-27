/**
 * @file  Compiler_Cfg.h
 * @author Ahmed Soliman
 * @brief AUTOSAR Base - Module Specific memory and pointer classes
 * @version 1.0.0
 * @details The file Compiler_Cfg.h contains  the module specific parameters (ptrclass and memclass)
 */

/**=========================================================
 * project : AUTOSAR 4.4.0 MCAL
 * platform : ARM
 * Peripheeral : STM32F103
 * Autosar Version : 4.4.0
 * Autosar Revision : ASR_REL_4_0_REV_0000
 * SW Version : 1.0.0 
 ===========================================================*/

 #ifndef COMPILER_CFG_H
 #define COMPILER_CFG_H

/**
 * @brief DIO memory class and pointer class
 * 
 */
#define DIO_CODE
#define DIO_CONST
#define DIO_APPL_DATA
#define DIO_APPL_CONST
#define DIO_APPL_CODE
#define DIO_CALLOUT_CODE
#define DIO_VAR_NOINIT
#define DIO_VAR_POWER_ON_INIT
#define DIO_VAR_FAST
#define DIO_VAR


/**
 * @brief PORT memory class and pointer class
 * 
 */
#define PORT_CODE
#define PORT_CONST
#define PORT_APPL_DATA
#define PORT_APPL_CONST
#define PORT_APPL_CODE
#define PORT_CALLOUT_CODE
#define PORT_VAR_NOINIT
#define PORT_VAR_POWER_ON_INIT
#define PORT_VAR_FAST
#define PORT_VAR


 #endif 