/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Fatma Albaz
 ******************************************************************************/

#include "Port.h"
#include "Services/tm4c123gh6pm_registers.h"
/*******************************************************************************
 *                   Incompatible Version Error Checking                       *
 *******************************************************************************/
/*include the Det.h file and check version compatibility*/
#if (STD_ON== PORT_DEV_ERROR_DETECT)

#include "Services/DET_Err/Det.h"
/* Software version incompatibility checking between (Det.h, Port)*/
#if ((DET_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
        ||  (DET_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
        ||  (DET_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
#error "The SW version of Det.h does not match the expected version"
#endif
/* AUTOSAR version incompatibility checking between (Det.h, Port)*/
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
        ||  (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
        ||  (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif
#endif
/*******************************************************************************
 *                         Global variables declaration                        *
 *******************************************************************************/
static const Port_ConfigType * g_ConfigPtr= NULL_PTR;
static boolean initialization_flag=FALSE;
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
void Port_Init(const Port_ConfigType * ConfigPtr )
{
    volatile uint32 * PortGpio_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    boolean error_FlagChecking = FALSE;
    uint8 Channels_Counter=0;
    /*
     *Development error check 1. Passing a NULL pointer
     */
#if (STD_ON== PORT_DEV_ERROR_DETECT)
    if (NULL_PTR == ConfigPtr ){
        /*this error is in PORT module Instance 0, PORT INIT function and due to passing a null pointer*/
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
        error_FlagChecking= TRUE;
    }
    else {
        g_ConfigPtr= ConfigPtr;
        initialization_flag=TRUE;
    }
#endif

    if (error_FlagChecking == FALSE){
        for (Channels_Counter=0; Channels_Counter<NUMBER_OF_PORT_PINS ; Channels_Counter++ ){
            switch(ConfigPtr->port_num)
            {
            case  PORTA_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
            break;
            case  PORTB_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
            break;
            case  PORTC_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
            break;
            case  PORTD_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
            break;
            case  PORTE_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
            break;
            case  PORTF_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
            break;
            default:
                /*invalid port id !! */
                /*this error is in PORT module Instance 0, PORT INIT function and due to passing invalid PORT ID*/
#if (STD_ON == PORT_DEV_ERROR_DETECT)
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
#endif
                error_FlagChecking= TRUE;
                break;
            }
            if (FALSE== error_FlagChecking){

                if( ((ConfigPtr->port_num == PORTD_ID) && (ConfigPtr->port_pin_num == PORTD_PIN7_ID)) || ((ConfigPtr->port_num == PORTF_ID) && (ConfigPtr->port_pin_num == PORTF_PIN0_ID))) /* PD7 or PF0 */
                {
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = PORT_MAGIC_NUMBER;                     /* Unlock the GPIOCR register */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , ConfigPtr->port_pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
                }
                else if( (ConfigPtr->port_num == PORTC_ID) && (ConfigPtr->port_pin_num <= PORTC_PIN3_ID) ) /* PC0 to PC3 */
                {
                    /* Do Nothing ...  this is the JTAG pins */
                }
                else
                {
                    /* Do Nothing ... No need to unlock the commit register for this pin */
                }

                if(ConfigPtr->port_pinDirection == OUTPUT)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->port_pin_num);               /* Set the corresponding bit in the GPIODIR register to configure it as output pin */

                    if(ConfigPtr->initial_value == STD_HIGH)
                    {
                        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->port_pin_num);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
                    }
                    else
                    {
                        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->port_pin_num);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
                    }
                }
                else if(ConfigPtr->port_pinDirection == INPUT)
                {
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->port_pin_num);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */

                    if(ConfigPtr->resistor == PULL_UP)
                    {
                        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->port_pin_num);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                    }
                    else if(ConfigPtr->resistor == PULL_DOWN)
                    {
                        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->port_pin_num);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
                    }
                    else
                    {
                        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->port_pin_num);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
                        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->port_pin_num);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
                    }
                }
                else
                {
                    /*invalid pin direction !! */
                    /*this error is in PORT module Instance 0, PORT INIT function and due to passing invalid pin direction selection*/
#if (STD_ON == PORT_DEV_ERROR_DETECT)
                    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
#endif
                }

                /*enabling or disabling digital*/
                if (ConfigPtr->port_pinDigitalEnable== TRUE){
                    /*clear the corresponding analog mode select then set the digital enable*/
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), ConfigPtr->port_pin_num);
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), ConfigPtr->port_pin_num);
                }
                else if (ConfigPtr->port_pinDigitalEnable== FALSE){
                    /*clear the corresponding digital mode select then set the analog mode enable*/
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET), ConfigPtr->port_pin_num);
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET), ConfigPtr->port_pin_num);
                }
                else{
                    /*invalid digital or analog selection !! */
                    /*this error is in PORT module Instance 0, PORT INIT function and due to passing invalid pin (dig/analog) selection*/
#if (STD_ON == PORT_DEV_ERROR_DETECT)
                    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
#endif
                }

                /*Setting the required mode for each pin*/
                if (Port_PinsValidMode[Channels_Counter] & (1<<(configured_pinsArr[Channels_Counter].port_pin_mode))){
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->port_pin_num);                                          /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->port_pin_num * 4));                                /* Clear the PMCx bits for this pin */
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |=((0x0000000F & (ConfigPtr->port_pin_mode)) << (ConfigPtr->port_pin_num * 4));   /* set the PMCx bits for this pin with the required mode */
                }
                else if ((configured_pinsArr[Channels_Counter].port_pin_mode)== PORT_PIN_DIO_MODE){
                    /*in this the mode is set pin mode as GPIO*/
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->port_pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (ConfigPtr->port_pin_num * 4));     /* Clear the PMCx bits for this pin */
                }
                else {
                    /*
                     * INVALID mode
                     * The entered mode is not PORT_PIN_DIO_MODE nor one of the alternative modes
                     */
                    /*this error is in PORT module Instance 0, PORT INIT function and due to passing invalid pin mode selection*/
#if (STD_ON == PORT_DEV_ERROR_DETECT)
                    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_INVALID_MODE);
#endif
                }
                /*to make the configuration pointer select the next configuration then it must be updated*/
                ConfigPtr++;


            }
            else{
                /* do nothing because error is found */
            }
        }
    }
    else {
        /* do nothing because error is found */
    }

}

/*
 * Description: Function to setup the pin direction
 *              - check if the port_pinDirectionChangeable is true or false
 *              if the value is true the direction of the pin can be set otherwise
 *              nothing will be changed.
 */
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction ){
    volatile uint32 * PortGpio_Ptr= NULL_PTR;
    boolean error_FlagChecking= FALSE;

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    if (FALSE == initialization_flag){
        /*port module is not initialized!! */
        /*this error is in PORT module Instance 0, Port_SetPinDirection function and due to uninitialized module usage*/
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
        error_FlagChecking= TRUE;
    }
    if (Pin>= NUMBER_OF_PORT_PINS){
        /*pin value is out of range!! */
        /*this error is in PORT module Instance 0, Port_SetPinDirection function and due to passing invalid pin ID*/
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
        error_FlagChecking= TRUE;
    }
    if (FALSE== (g_ConfigPtr[Pin].port_pinDirectionChangeable)){
        /*pin direction is unchangeable!! */
        /*this error is in PORT module Instance 0, Port_SetPinDirection function and due to unchangeable pin direction*/
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
        error_FlagChecking= TRUE;
    }
#endif

    if (FALSE== error_FlagChecking){
        switch (g_ConfigPtr[Pin].port_num)
        {
        case  PORTA_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
        break;
        case  PORTB_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
        break;
        case  PORTC_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
        break;
        case  PORTD_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
        break;
        case  PORTE_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
        break;
        case  PORTF_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
        break;
        default:
            /*invalid port id !! */
            /*this error is in PORT module Instance 0, PORT INIT function and due to passing invalid PORT ID*/
#if (STD_ON == PORT_DEV_ERROR_DETECT)

            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_CONFIG);
            error_FlagChecking= TRUE;
#endif
            break;
        }
        if (FALSE== error_FlagChecking){
            TOGGLE_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , g_ConfigPtr[Pin].port_pinDirection);

        }
        else{
            /* do nothing because error is found */
        }
    }
    else {
        /* do nothing because error is found */
    }

}

/*
 * Description: Function to refresh the port direction
 *              - this function will go to the original configuration settings and
 *              reset the direction for each individual pin all over again.
 */
void Port_RefreshPortDirection(void){
    volatile uint32 * PortGpio_Ptr= NULL_PTR;
    boolean error_FlagChecking=FALSE;
    uint8 Channels_Counter=0;
#if (STD_ON == PORT_DEV_ERROR_DETECT)
    if (FALSE == initialization_flag){
        /*port module is not initialized!! */
        /*this error is in PORT module Instance 0, Port_SetPinDirection function and due to uninitialized module usage*/
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
        error_FlagChecking= TRUE;
    }

#endif
    if (FALSE== error_FlagChecking){
        for (Channels_Counter=0; Channels_Counter<NUMBER_OF_PORT_PINS ; Channels_Counter++ ){
            switch(g_ConfigPtr[Channels_Counter].port_num)
            {
            case  PORTA_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
            break;
            case  PORTB_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
            break;
            case  PORTC_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
            break;
            case  PORTD_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
            break;
            case  PORTE_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
            break;
            case  PORTF_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
            break;
            default:
                /*invalid port id !! */
                /*this error is in PORT module Instance 0, PORT INIT function and due to passing invalid PORT ID*/
#if (STD_ON == PORT_DEV_ERROR_DETECT)
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_PARAM_CONFIG);
#endif
                error_FlagChecking= TRUE;
                break;
            }
            if (FALSE== error_FlagChecking){

                if( ((g_ConfigPtr[Channels_Counter].port_num == PORTD_ID) && (g_ConfigPtr[Channels_Counter].port_pin_num == PORTD_PIN7_ID)) || ((g_ConfigPtr[Channels_Counter].port_num == PORTF_ID) && (g_ConfigPtr[Channels_Counter].port_pin_num == PORTF_PIN0_ID))) /* PD7 or PF0 */
                {
                    *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = PORT_MAGIC_NUMBER;                     /* Unlock the GPIOCR register */
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , g_ConfigPtr[Channels_Counter].port_pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
                }
                else if( (g_ConfigPtr[Channels_Counter].port_num == PORTC_ID) && (g_ConfigPtr[Channels_Counter].port_pin_num <= PORTC_PIN3_ID) ) /* PC0 to PC3 */
                {
                    /* Do Nothing ...  this is the JTAG pins */
                }
                else
                {
                    /* Do Nothing ... No need to unlock the commit register for this pin */
                }

                if(g_ConfigPtr[Channels_Counter].port_pinDirection == OUTPUT)
                {
                    SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , g_ConfigPtr[Channels_Counter].port_pin_num);  /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
                }
                else if(g_ConfigPtr[Channels_Counter].port_pinDirection == INPUT)
                {
                    CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , g_ConfigPtr[Channels_Counter].port_pin_num); /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
                }
                else
                {
                    /*invalid pin direction !! */
                    /*this error is in PORT module Instance 0, PORT INIT function and due to passing invalid pin direction selection*/
#if (STD_ON == PORT_DEV_ERROR_DETECT)
                    Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID, PORT_E_PARAM_CONFIG);
#endif
                }
            }
            else{
                /* do nothing because error is found */
            }
        }
    }
    else{

    }
}

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
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
    /* Check if input pointer is not Null pointer */
    if(NULL_PTR == versioninfo)
    {
        /* Report to DET  */
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
    }
    else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
    {
        /* Copy the vendor Id */
        versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = (uint16)PORT_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
    }
}
#endif

/*
 * Description: Function to setup the pin direction
 *              - check if the port_pinModeChangeable is true or false if the value is true
 *              the mode of the pin can be set otherwise nothing will be changed.
 */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode){

    volatile uint32 * PortGpio_Ptr= NULL_PTR;
    boolean error_FlagChecking= FALSE;

#if (STD_ON == PORT_DEV_ERROR_DETECT)
    if (FALSE == initialization_flag){
        /*port module is not initialized!! */
        /*this error is in PORT module Instance 0, Port_SetPinDirection function and due to uninitialized module usage*/
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
        error_FlagChecking= TRUE;
    }
    if (Pin>= NUMBER_OF_PORT_PINS){
        /*pin value is out of range!! */
        /*this error is in PORT module Instance 0, Port_SetPinDirection function and due to passing invalid pin ID*/
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
        error_FlagChecking= TRUE;
    }
    if (FALSE== (g_ConfigPtr[Pin].port_pinModeChangeable)){
        /*pin direction is unchangeable!! */
        /*this error is in PORT module Instance 0, Port_SetPinDirection function and due to unchangeable pin direction*/
        Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
        error_FlagChecking= TRUE;
    }
#endif

    if (FALSE== error_FlagChecking){
        switch (g_ConfigPtr[Pin].port_num)
        {
        case  PORTA_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
        break;
        case  PORTB_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
        break;
        case  PORTC_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
        break;
        case  PORTD_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
        break;
        case  PORTE_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
        break;
        case  PORTF_ID: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
        break;
        default:
            /*invalid port id !! */
            /*this error is in PORT module Instance 0, PORT INIT function and due to passing invalid PORT ID*/
#if (STD_ON == PORT_DEV_ERROR_DETECT)

            Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_CONFIG);
            error_FlagChecking= TRUE;
#endif
            break;
        }
        if (FALSE== error_FlagChecking){
            /*Setting the required mode for each pin*/
            if (Port_PinsValidMode[Pin] & (1<<Mode)){
                SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , g_ConfigPtr[Pin].port_pin_num);                                          /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (g_ConfigPtr[Pin].port_pin_num * 4));                                /* Clear the PMCx bits for this pin */
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |=((0x0000000F & (Mode)) << (g_ConfigPtr[Pin].port_pin_num * 4));   /* set the PMCx bits for this pin with the required mode */
            }
            else if (Mode== PORT_PIN_DIO_MODE){
                /*in this the mode is set pin mode as GPIO*/
                CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , g_ConfigPtr[Pin].port_pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
                *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (g_ConfigPtr[Pin].port_pin_num * 4));     /* Clear the PMCx bits for this pin */
            }
            else {
                /*
                 * INVALID mode
                 * The entered mode is not PORT_PIN_DIO_MODE nor one of the alternative modes
                 */
                /*this error is in PORT module Instance 0, PORT INIT function and due to passing invalid pin mode selection*/
#if (STD_ON == PORT_DEV_ERROR_DETECT)
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
#endif
            }

        }
        else{
            /* do nothing because error is found */
        }
    }
    else {
        /* do nothing because error is found */
    }

}





