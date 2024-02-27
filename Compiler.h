/**
 * @file Compiler.h
 * @author Ahmed Soliman
 * @brief AUTOSAR Base - SWS Compiler abstraction
 * @version 1.0.0
 * @details The File Compiler.h provides macros for encapsulation of definitions and declerations
 * 
 */

/**=========================================================
 * project : AUTOSAR 4.4.0 MCAL
 * platform : ARM
 * Peripheeral : STM32F103
 * Autosar Version : 4.4.0
 * Autosar Revision : ASR_REL_4_0_REV_0000
 * SW Version : 1.0.0 
 ===========================================================*/

#ifndef COMPILER_H
#define COMPILER_H


/**==================================================================
                        INCLUDES
=====================================================================*/
#include "Compiler_Cfg.h"

/**==================================================================
                SOURCE FILE VERSION INFORMATION
=====================================================================*/

/**
 * @brief Parameters that shall be published within the standard types header file and also in module's description file
 */
#define COMPILER_VENDOR_ID                       123
#define COMPILER_AR_RELEASE_MAJOR_VERSION        4
#define COMPILER_AR_RELEASE_MINOR_VERSION        4
#define COMPILER_AR_RELEASE_REVISION_VERSION     0

#define COMPILER_SW_MAJOR_VERSION                1
#define COMPILER_SW_MINOR_VERSION                0
#define COMPILER_SW_PATCH_VERSION                0

#ifndef _GNU_ARM_C_STM32F103_
    #define _GNU_ARM_C_STM32F103_
#endif

/**
 * @brief The memory class AUTOMATIC shall be provided as empty definition, used for
          the declaration of local pointers.  
 * 
 */
#define AUTOMATIC

/**
 * @brief   This memory class shall be used within type definitions, where no memory qualifier can be
            specified. This can be necessary for defining pointer types, with e.g. P2VAR,
            where the macros require two parameters. First parameter can be specified in the
            type definition (distance to the memory location referenced by the pointer), but
            the second one (memory allocation of the pointer itself) cannot be defined at this
            time. Hence, memory class TYPEDEF shall be applied
 * 
 */
#define TYPEDEF
/**
 * @brief   define with a void pointer to zero definition.
*/
#define NULL_PTR    ((void *)0U)


#ifdef  _GNU_ARM_C_STM32F103_
#define _GNU_ARM_C_STM32F103_
    /**
     * @brief INLINE define for abstraction of the keyword inline
     */
    #define INLINE          inline
    /**
     * @brief LOCAL_INLINE define for abstraction of the keyword inline in functions with “static” scope
     */
    #define LOCAL_INLINE    static inline
    #define STATIC          static
    #define INTERRUPT_FUNC
#endif

/**==================================================================
                FUNCTION DEFINITIONS
=====================================================================*/
/**
 * @brief   the declaration and definition of functions that ensures correct syntax of function declarations as
            required by a specific compiler.
 * @arg retype   --> return type of the function
        memclass --> classification of the function itself
 * 
 */
#define FUNC(rettype, memclass) \
memclass rettype

/**
 * @brief the declaration and definition of functions returning a pointer to a constant. This shall
          ensure the correct syntax of function declarations as required by a specific compiler.
 *  @arg rettype  -->  return type of the function
         ptrclass -->  defines the classification of the pointer’s distance
         memclass -->  classification of the function itsel
 */
#define FUNC_P2CONST(rettype, ptrclass, memclass) \
const ptrclass rettype * memclass

/**
 * @brief the declaration and definition of functions returning a pointer to a variable. This shall ensure the
          correct syntax of function declarations as required by a specific compiler.
 * @arg  rettype  -->  return type of the function
         ptrclass -->  defines the classification of the pointer’s distance
         memclass -->  classification of the function itsel
 */
#define FUNC_P2VAR(rettype, ptrclass, memclass) \
ptrclass rettype * memclass

/**==================================================================
                POINTER  DEFINITIONS
=====================================================================*/
/**
 * @brief the declaration and definition of pointers in RAM, pointing to variables
 * 
 * @arg ptrtype   -->  type of the referenced variable
        memclass  -->  classification of the pointer’s variable itself
        ptrclass  -->  defines the classification of the pointer’s distance
 * 
 */
#define P2VAR(ptrtype, memclass, ptrclass) \
ptrclass ptrtype * memclass

/**
 * @brief the declaration and definition of pointers in RAM pointing to constants
 * @arg ptrtype   -->   type of the referenced constant
        memclass  -->   classification of the pointer’s variable itself
        ptrclass  -->   defines the classification of the pointer’s distance
 */
#define P2CONST(ptrtype, memclass, ptrclass) \
const ptrtype memclass * ptrclass

/**
 * @brief the declaration and definition of constant pointers accessing variables.
 * @arg ptrtype   -->   type of the referenced constant
        memclass  -->   classification of the pointer’s variable itself
        ptrclass  -->   defines the classification of the pointer’s distance
 */
#define CONSTP2VAR (ptrtype, memclass, ptrclass) \
ptrclass ptrtype * const memclass

/**
 * @brief the declaration and definition of constant pointers accessing constants.
 * @arg ptrtype   -->   type of the referenced constant
        memclass  -->   classification of the pointer’s variable itself
        ptrclass  -->   defines the classification of the pointer’s distance
 * 
 */
#define CONSTP2CONST (ptrtype, memclass, ptrclass) \
const memclass ptrtype * const ptrclass

/**
 * @brief the type definition of pointers to functions.
 * @arg rettype   --> return type of the function
        ptrclass  --> defines the classification of the pointer’s distance
        fctname   --> function name respectively name of the defined type
 */
#define P2FUNC(rettype, ptrclass, fctname) \
rettype (*ptrclass fctname)

/**
 * @brief the type definition of constant pointers to functions
 * @arg rettype   --> return type of the function
        ptrclass  --> defines the classification of the pointer’s distance
        fctname   --> function name respectively name of the defined type
 */
#define CONSTP2FUNC(rettype, ptrclass, fctname)\
rettype (* const fctname)

/**==================================================================
                CONSTANT DEFINITIONS
=====================================================================*/
/**
 * @brief the declaration and definition of constants.
 * @arg consttype   -->  type of the constant
        memclass    --> classification of the constant itself
 * 
 */
#define CONST(type, memclass) memclass const type

/**==================================================================
                VARIABLE DEFINITIONS
=====================================================================*/
/**
 * @brief the declaration and definition of variables.
 * @arg vartype   --> type of the variable
        memclass  -->  classification of the variable itself
 */
#define VAR(type, memclass) memclass type
#endif