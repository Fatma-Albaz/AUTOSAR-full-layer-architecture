/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Fatma Tarek
 ******************************************************************************/
#ifndef PORT_H
#define PORT_H
/*******************************************************************************
 *                             PORT DET Errors ID                              *
 *******************************************************************************/
/*
 * The following errors and exceptions shall be detectable by the PORT
 * driver depending on its build version (development/production).
 */
#define PORT_E_PARAM_PIN                            (uint8)0x0A
#define PORT_E_DIRECTION_UNCHANGEABLE               (uint8)0x0B
#define PORT_E_PARAM_CONFIG                         (uint8)0x0C
#define PORT_E_PARAM_INVALID_MODE                   (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE                    (uint8)0x0E
#define PORT_E_UNINIT                               (uint8)0x0F
#define PORT_E_PARAM_POINTER                        (uint8)0x10
/*******************************************************************************
 *                                APIs IDs Macros                              *
 *******************************************************************************/
#define PORT_INIT_SID                       (uint8)0x00
#define PORT_SET_PIN_DIRECTION_SID          (uint8)0x01
#define PORT_REFRESH_PORT_DIRECTION_SID     (uint8)0x02
#define PORT_GET_VERSION_INFO_SID           (uint8)0x03
#define PORT_SET_PIN_MODE_SID               (uint8)0x04
/*******************************************************************************
 *                               PORT Version info                             *
 *******************************************************************************/
/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*******************************************************************************
 *                               PORT vendors info                             *
 *******************************************************************************/
/* The vendors id */
#define PORT_VENDOR_ID                       (1000U)
/* Port Module Id */
#define PORT_MODULE_ID                       (125U)
/* Port Instance Id */
#define PORT_INSTANCE_ID                     (0U)

/*******************************************************************************
 *                   Incompatible Version Error Checking                       *
 *******************************************************************************/
/*include the configuration.h file and check version compatibility*/
#include "Port_Cfg.h"

/* Software version incompatibility checking between (Port_cfg, Port)*/
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
        ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
        ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* AUTOSAR version incompatibility checking between (Port_cfg, Port)*/
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
        ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
        ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/*include the Std_Types.h file and check version compatibility*/
#include "Services/Std_Types.h"
/* AUTOSAR version incompatibility checking between (STD_TYPES, Port)*/
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
        ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
        ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Software version incompatibility checking between (Dio.h, Port)*/
#include "MCUAL/DIO/Dio.h"
#if ((DIO_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
        ||  (DIO_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
        ||  (DIO_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The SW version of DIO.h does not match the expected version"
#endif
/* AUTOSAR version incompatibility checking between (Dio.h, Port)*/
#if ((DIO_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
        ||  (DIO_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
        ||  (DIO_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of DIO.h does not match the expected version"
#endif

/* Software version incompatibility checking between (port_pbcfg.h, Port)*/
#include "Port_PBCfg.h"
/* Software version incompatibility checking between (Port_PBCFG, Port)*/
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
        ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
        ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The SW version of Port_PBCFG.h does not match the expected version"
#endif

/* AUTOSAR version incompatibility checking between (Port_PBCFG, Port)*/
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
        ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
        ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Port_PBCFG.h does not match the expected version"
#endif
/* Software version incompatibility checking between (compiler.h, Port)*/
#include "Services/Compiler.h"
/* Software version incompatibility checking between (Port_PBCFG, Port)*/
#if ((COMPILER_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
        ||  (COMPILER_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
        ||  (COMPILER_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The SW version of Port_PBCFG.h does not match the expected version"
#endif

/* AUTOSAR version incompatibility checking between (Port_PBCFG, Port)*/
#if ((COMPILER_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
        ||  (COMPILER_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
        ||  (COMPILER_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Port_PBCFG.h does not match the expected version"
#endif

/*******************************************************************************
 *                          include non-AUTOSAR files                          *
 *******************************************************************************/
#include "Services/Common_Macros.h"
#include "Port_REGs.h"


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

typedef uint8 Port_PinType;
typedef uint8 Port_PinModeType;
/* Description: Enum to hold PIN direction */
typedef enum
{
    INPUT,OUTPUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/* Description: Structure to configure each individual PIN:
 *      1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *      2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 *      5. the initial value given to the pin
 *      6. the mode for each pin --> DIO, UARTRx, UARTTx.. etc
 *      7. the ability to change pin mode --> TRUE, FALSE
 *      8. the ability to enable digital --> TRUE, FALSE
 *      9. the ability to change pin direction --> TRUE, FALSE
 */
typedef struct
{
    uint8 port_num;
    Port_PinType port_pin_num;
    Port_PinDirectionType port_pinDirection;
    Port_InternalResistor resistor;
    uint8 initial_value;
    Port_PinModeType port_pin_mode;
    boolean port_pinModeChangeable;
    boolean port_pinDigitalEnable;
    boolean port_pinDirectionChangeable;
}Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/*
 * Service Name: Port_SetupGpioPin
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Setup the pin configuration:
 *              - Setup the pin as Digital GPIO pin
 *              - Setup the direction of the GPIO pin
 *              - Setup the internal resistor for i/p pin
 */
void Port_Init(const Port_ConfigType *ConfigPtr );
/*
 * Description: Function to setup the pin direction
 *              - check if the port_pinDirectionChangeable is true or false
 *              if the value is true the direction of the pin can be set otherwise
 *              nothing will be changed.
 */
#if (PORT_SET_PIN_DIRECTION_API== STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif
/*
 * Description: Function to refresh the port direction
 *              - this function will go to the original configuration settings and
 *              reset the direction for each individual pin all over again.
 */
void Port_RefreshPortDirection(void);
/*
 * Service Name: Port_GetVersionInfo
 * Service ID[hex]: 0x12
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): VersionInfo - Pointer to where to store the version information of this module.
 * Return value: None
 * Description: Function to get the version information of this module.
 */
#if (PORT_VERSION_INFO_API== STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif
/*
 * Description: Function to setup the pin direction
 *              - check if the port_pinModeChangeable is true or false if the value is true
 *              the mode of the pin can be set otherwise nothing will be changed.
 */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

/************************************************************************************
 *    using extern classifier to declare variables to be used in other files        *
 *************************************************************************************/
/*
 * creating an array of structures
 * each element of the array carries the configuration of a specific pin
 * we have  43 pins in TIVAC, so we need to configure all of them
 */
extern Port_ConfigType configured_pinsArr [NUMBER_OF_PORT_PINS];/*From PBCFG file*/
extern const uint16 Port_PinsValidMode [NUMBER_OF_PORT_PINS]; /*modes are from 0: 14 so their hex values require uint16 data type*/


#endif /* PORT_H */
