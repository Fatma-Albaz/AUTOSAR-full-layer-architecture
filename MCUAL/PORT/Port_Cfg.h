 /******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Port_Cfg.h
 *
 * Description:  This file contains the configuration of the PORT module
 *               (vendor info, version info, PORT macros for modes and IDs)
 *               according to AUTOSAR specifications.
 *
 * Author: Fatma Albaz
 *
 *******************************************************************************/
#ifndef PORT_CFG_H_
#define PORT_CFG_H_
/*******************************************************************************
 *                           CFG PORT Version info                             *
 *******************************************************************************/
/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION           (1U)
#define PORT_CFG_SW_MINOR_VERSION           (0U)
#define PORT_CFG_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION   (3U)
/*******************************************************************************
 *                            CFG PORT Vendor info                             *
 *******************************************************************************/
/* The vendors id
 * My ID is 1000*/
#define PORT_VENDOR_ID                                      (1000U)

/* Port Module Id */
#define PORT_MODULE_ID                                      (125U)

/* Port Instance Id */
#define PORT_INSTANCE_ID                                    (0U)

/*******************************************************************************
 *              pre-compiler options of being a valid option or not            *
 *******************************************************************************/
/* pre-compile option to detect the development errors */
#define PORT_DEV_ERROR_DETECT               (STD_ON)

/* pre-compile option to keep the set pin direction API */
#define PORT_SET_PIN_DIRECTION_API          (STD_ON)

/* Pre-compile option to keep get version info API or not */
#define PORT_VERSION_INFO_API               (STD_ON)

/* Number of the port pins on the ECU */
#define NUMBER_OF_PORT_PINS                 (Port_PinType)43

/* The general case for any port pin to be DIO */
#define PORT_PIN_DIO_MODE                   (Port_PinModeType)0
/*******************************************************************************
 *                            PORTS Pins mode values                           *
 *******************************************************************************/
/**************************
 *   PORTA Modes Macros   *
 **************************/
/*portA pin 0 modes*/
#define PORT_A0_DIO_MODE  0
#define PORT_A0_UART0_RX  1
#define PORT_A0_CAN1      8
/*portA pin 1 modes*/
#define PORT_A1_DIO_MODE  0
#define PORT_A1_UART0_TX  1
#define PORT_A1_CAN1      8
/*portA pin 2 modes*/
#define PORT_A2_DIO_MODE  0
#define PORT_A2_SSI0CLK   2
/*portA pin 3 modes*/
#define PORT_A3_DIO_MODE  0
#define PORT_A3_SSI0FSS   2
/*portA pin 4 modes*/
#define PORT_A4_DIO_MODE  0
#define PORT_A4_SSI0_RX   2
/*portA pin 5 modes*/
#define PORT_A5_DIO_MODE  0
#define PORT_A5_SSI0_TX   2
/*portA pin 6 modes*/
#define PORT_A6_DIO_MODE  0
#define PORT_A6_I2C1_SCL  3
#define PORT_A6_M1PWM2    5
/*portA pin 7 modes*/
#define PORT_A7_DIO_MODE  0
#define PORT_A6_I2C1_SDA  3
#define PORT_A6_M1PWM3    5

/**************************
 *   PORTB Modes Macros   *
 **************************/
/*portB pin 0 modes*/
#define PORT_B0_DIO_MODE  0
#define PORT_B0_UART1_RX  1
#define PORT_B0_T2CCP0    7
/*portB pin 1 modes*/
#define PORT_B1_DIO_MODE  0
#define PORT_B1_UART1_RX  1
#define PORT_B1_T2CCP1    7
/*portB pin 2 modes*/
#define PORT_B2_DIO_MODE  0
#define PORT_B2_I2C0_SCL  3
#define PORT_B2_T3CCP0    7
/*portB pin 3 modes*/
#define PORT_B3_DIO_MODE  0
#define PORT_B3_I2C0_SDA  3
#define PORT_B3_T3CCP1    7
/*portB pin 4 modes*/
#define PORT_B4_DIO_MODE  0
#define PORT_B4_SSI2_CLK  2
#define PORT_B4_M0PWM2    4
#define PORT_B4_T1CCP0    7
#define PORT_B4_CAN0_RX   8
/*portB pin 5 modes*/
#define PORT_B5_DIO_MODE  0
#define PORT_B5_SSI2_FSS  2
#define PORT_B5_M0PWM3    4
#define PORT_B5_T1CCP1    7
#define PORT_B5_CAN0_TX   8
/*portB pin 6 modes*/
#define PORT_B6_DIO_MODE  0
#define PORT_B6_SSI2_RX   2
#define PORT_B6_M0PWM0    4
#define PORT_B6_T1CCP0    7
/*portB pin 7 modes*/
#define PORT_B7_DIO_MODE  0
#define PORT_B7_SSI2_TX   2
#define PORT_B6_M0PWM1    4
#define PORT_B6_T0CCP1    7

/**************************
 *   PORTC Modes Macros   *
 **************************/
/*portC pin 0 modes*/
#define PORT_C0_DIO_MODE  0
/*portC pin 1 modes*/
#define PORT_C1_DIO_MODE  0
/*portC pin 2 modes*/
#define PORT_C2_DIO_MODE  0
/*portC pin 3 modes*/
#define PORT_C3_DIO_MODE  0
/*portC pin 4 modes*/
#define PORT_C4_DIO_MODE  0
#define PORT_C4_UART4_RX  1
#define PORT_C4_UART1_RX  2
#define PORT_C4_M0PWM6    4
#define PORT_C4_IDX1      6
#define PORT_C4_WT0CCP0   7
#define PORT_C4_U1_RTS    8
/*portC pin 5 modes*/
#define PORT_C5_DIO_MODE  0
#define PORT_C5_UART4_TX  1
#define PORT_C5_UART1_TX  2
#define PORT_C5_M0PWM7    4
#define PORT_C5_PHA1      6
#define PORT_C5_WT0CCP1   7
#define PORT_C5_U1_CTS    8
/*portC pin 6 modes*/
#define PORT_C6_DIO_MODE  0
#define PORT_C6_UART3_RX  1
#define PORT_C6_PHB1      6
#define PORT_C6_WT1CCP0   7
#define PORT_C6_USB0_EPEN 8
/*portC pin 7 modes*/
#define PORT_C7_DIO_MODE  0
#define PORT_C7_UART3_TX  1
#define PORT_C7_WT1CCP1   7
#define PORT_C7_USB0_PFLT 8

/**************************
 *   PORTD Modes Macros   *
 **************************/
/*portD pin 0 modes*/
#define PORT_D0_DIO_MODE  0
#define PORT_D0_SSI3CLK   1
#define PORT_D0_SSI1CLK   2
#define PORT_D0_I2C3_SCL  3
#define PORT_D0_M0PWM6    4
#define PORT_D0_M1PWM0    5
#define PORT_D0_WT2CCP0   7
/*portD pin 1 modes*/
#define PORT_D1_DIO_MODE  0
#define PORT_D1_SSI3_FSS  1
#define PORT_D1_SSI1_FSS  2
#define PORT_D1_I2C3_SDA  3
#define PORT_D1_M0PWM7    4
#define PORT_D1_M1PWM1    5
#define PORT_D1_WT2CCP1   7
/*portD pin 2 modes*/
#define PORT_D2_DIO_MODE  0
#define PORT_D2_SSI3_RX   1
#define PORT_D2_SSI1_RX   2
#define PORT_D2_M0_FAULT0 4
#define PORT_D2_WT3CCP0   7
#define PORT_D2_USB0_EPEN 8
/*portD pin 3 modes*/
#define PORT_D3_DIO_MODE  0
#define PORT_D3_SSI3_TX   1
#define PORT_D3_SSI1_TX   2
#define PORT_D3_IDX0      6
#define PORT_D3_WT3CCP1   7
#define PORT_D3_USB0_PFLT 8
/*portD pin 4 modes*/
#define PORT_D4_DIO_MODE  0
#define PORT_D4_U6RX      1
#define PORT_D4_WT4CCP0  7
/*portD pin 5 modes*/
#define PORT_D5_DIO_MODE  0
#define PORT_D5_U6TX      1
#define PORT_D5_WT4CCP1   7
/*portD pin 6 modes*/
#define PORT_D6_DIO_MODE  0
#define PORT_D6_U2RX      1
#define PORT_D6_M0_FAULT0 4
#define PORT_D6_PHA0      6
#define PORT_D6_WT5CCP0   7
/*portD pin 7 modes*/
#define PORT_D7_DIO_MODE  0
#define PORT_D7_U2TX      1
#define PORT_D7_PHB0      6
#define PORT_D7_WT5CCP1   7
#define PORT_D7_NMI       8

/**************************
 *   PORTE Modes Macros   *
 **************************/
/*portE pin 0 modes*/
#define PORT_E0_DIO_MODE  0
#define PORT_E0_U7RX      1
/*portE pin 1 modes*/
#define PORT_E1_DIO_MODE  0
#define PORT_E1_U7TX      1
/*portE pin 2 modes*/
#define PORT_E2_DIO_MODE  0
/*portE pin 3 modes*/
#define PORT_E3_DIO_MODE  0
/*portE pin 4 modes*/
#define PORT_E4_DIO_MODE  0
#define PORT_E4_U5RX      1
#define PORT_E4_I2C_2SCL  3
#define PORT_E4_M0PWM4    4
#define PORT_E4_M1PWM2    5
#define PORT_E4_CAN0_RX   8
/*portE pin 5 modes*/
#define PORT_E5_DIO_MODE  0
#define PORT_E5_U5TX      1
#define PORT_E5_I2C_2SDA  3
#define PORT_E5_M0PWM5    4
#define PORT_E5_M1PWM3    5
#define PORT_E5_CAN0_TX   8

/**************************
 *   PORTF Modes Macros   *
 **************************/
/*portF pin 0 modes*/
#define PORT_F0_DIO_MODE  0
#define PORT_F0_U1RTS     1
#define PORT_F0_SSI1_RX   2
#define PORT_F0_CAN0_RX   3
#define PORT_F0_M1PWM4    5
#define PORT_F0_PHA0      6
#define PORT_F0_T0CCP0    7
#define PORT_F0_NMI       8
#define PORT_F0_C0O       9
/*portF pin 1 modes*/
#define PORT_F1_DIO_MODE  0
#define PORT_F1_U1CTS     1
#define PORT_F1_SSI1_TX   2
#define PORT_F1_M1PWM5    5
#define PORT_F1_PHB0      6
#define PORT_F1_T0CCP1    7
#define PORT_F1_C1O       9
#define PORT_F1_TRD1      14
/*portF pin 2 modes*/
#define PORT_F2_DIO_MODE  0
#define PORT_F2_SSI1_CLK  2
#define PORT_F2_M0_FAULT0 2
#define PORT_F2_M1PWM6    5
#define PORT_F2_T1CCP0    7
#define PORT_F2_TRD0      14
/*portF pin 3 modes*/
#define PORT_F3_DIO_MODE  0
#define PORT_F3_SSI1_FSS  2
#define PORT_F3_CAN0_TX   3
#define PORT_F3_M1PWM7    5
#define PORT_F3_T1CCP1    7
#define PORT_F3_TR_CLK    14
/*portF pin 4 modes*/
#define PORT_F4_DIO_MODE  0
#define PORT_F4_M1_FAULT0 5
#define PORT_F4_IDX0      6
#define PORT_F4_T2CCP0    7
#define PORT_F4_USB0_EPEN 8

/*******************************************************************************
 *                                     PORTs IDs                               *
 *******************************************************************************/
#define PORTA_ID                (uint8) 0
#define PORTB_ID                (uint8) 1
#define PORTC_ID                (uint8) 2
#define PORTD_ID                (uint8) 3
#define PORTE_ID                (uint8) 4
#define PORTF_ID                (uint8) 5
/*******************************************************************************
 *                                PORTA Pins IDs                               *
 *******************************************************************************/
#define PORTA_PIN0_ID           (Port_PinType) 0
#define PORTA_PIN1_ID           (Port_PinType) 1
#define PORTA_PIN2_ID           (Port_PinType) 2
#define PORTA_PIN3_ID           (Port_PinType) 3
#define PORTA_PIN4_ID           (Port_PinType) 4
#define PORTA_PIN5_ID           (Port_PinType) 5
#define PORTA_PIN6_ID           (Port_PinType) 6
#define PORTA_PIN7_ID           (Port_PinType) 7
/*******************************************************************************
 *                                PORTB Pins IDs                               *
 *******************************************************************************/
#define PORTB_PIN0_ID           (Port_PinType) 0
#define PORTB_PIN1_ID           (Port_PinType) 1
#define PORTB_PIN2_ID           (Port_PinType) 2
#define PORTB_PIN3_ID           (Port_PinType) 3
#define PORTB_PIN4_ID           (Port_PinType) 4
#define PORTB_PIN5_ID           (Port_PinType) 5
#define PORTB_PIN6_ID           (Port_PinType) 6
#define PORTB_PIN7_ID           (Port_PinType) 7
/*******************************************************************************
 *                                PORTC Pins IDs                               *
 *******************************************************************************/
#define PORTC_PIN0_ID           (Port_PinType) 0
#define PORTC_PIN1_ID           (Port_PinType) 1
#define PORTC_PIN2_ID           (Port_PinType) 2
#define PORTC_PIN3_ID           (Port_PinType) 3
#define PORTC_PIN4_ID           (Port_PinType) 4
#define PORTC_PIN5_ID           (Port_PinType) 5
#define PORTC_PIN6_ID           (Port_PinType) 6
#define PORTC_PIN7_ID           (Port_PinType) 7
/*******************************************************************************
 *                                PORTD Pins IDs                               *
 *******************************************************************************/
#define PORTD_PIN0_ID           (Port_PinType) 0
#define PORTD_PIN1_ID           (Port_PinType) 1
#define PORTD_PIN2_ID           (Port_PinType) 2
#define PORTD_PIN3_ID           (Port_PinType) 3
#define PORTD_PIN4_ID           (Port_PinType) 4
#define PORTD_PIN5_ID           (Port_PinType) 5
#define PORTD_PIN6_ID           (Port_PinType) 6
#define PORTD_PIN7_ID           (Port_PinType) 7
/*******************************************************************************
 *                                PORTE Pins IDs                               *
 *******************************************************************************/
#define PORTE_PIN0_ID           (Port_PinType) 0
#define PORTE_PIN1_ID           (Port_PinType) 1
#define PORTE_PIN2_ID           (Port_PinType) 2
#define PORTE_PIN3_ID           (Port_PinType) 3
#define PORTE_PIN4_ID           (Port_PinType) 4
#define PORTE_PIN5_ID           (Port_PinType) 5

/*******************************************************************************
 *                                PORTF Pins IDs                               *
 *******************************************************************************/
#define PORTF_PIN0_ID           (Port_PinType) 0
#define PORTF_PIN1_ID           (Port_PinType) 1
#define PORTF_PIN2_ID           (Port_PinType) 2
#define PORTF_PIN3_ID           (Port_PinType) 3
#define PORTF_PIN4_ID           (Port_PinType) 4

/*******************************************************************************
 *  TIVAC pins indexes in the array of configuration structure definitions    *
 *******************************************************************************/

#define PORTA_PIN0_IDX                        (Port_PinType)0
#define PORTA_PIN1_IDX                        (Port_PinType)1
#define PORTA_PIN2_IDX                        (Port_PinType)2
#define PORTA_PIN3_IDX                        (Port_PinType)3
#define PORTA_PIN4_IDX                        (Port_PinType)4
#define PORTA_PIN5_IDX                        (Port_PinType)5
#define PORTA_PIN6_IDX                        (Port_PinType)6
#define PORTA_PIN7_IDX                        (Port_PinType)7

#define PORTB_PIN0_IDX                        (Port_PinType)8
#define PORTB_PIN1_IDX                        (Port_PinType)9
#define PORTB_PIN2_IDX                        (Port_PinType)10
#define PORTB_PIN3_IDX                        (Port_PinType)11
#define PORTB_PIN4_IDX                        (Port_PinType)12
#define PORTB_PIN5_IDX                        (Port_PinType)13
#define PORTB_PIN6_IDX                        (Port_PinType)14
#define PORTB_PIN7_IDX                        (Port_PinType)15

#define PORTC_PIN0_IDX                        (Port_PinType)16
#define PORTC_PIN1_IDX                        (Port_PinType)17
#define PORTC_PIN2_IDX                        (Port_PinType)18
#define PORTC_PIN3_IDX                        (Port_PinType)19
#define PORTC_PIN4_IDX                        (Port_PinType)20
#define PORTC_PIN5_IDX                        (Port_PinType)21
#define PORTC_PIN6_IDX                        (Port_PinType)22
#define PORTC_PIN7_IDX                        (Port_PinType)23

#define PORTD_PIN0_IDX                        (Port_PinType)24
#define PORTD_PIN1_IDX                        (Port_PinType)25
#define PORTD_PIN2_IDX                        (Port_PinType)26
#define PORTD_PIN3_IDX                        (Port_PinType)27
#define PORTD_PIN4_IDX                        (Port_PinType)28
#define PORTD_PIN5_IDX                        (Port_PinType)29
#define PORTD_PIN6_IDX                        (Port_PinType)30
#define PORTD_PIN7_IDX                        (Port_PinType)31

#define PORTE_PIN0_IDX                        (Port_PinType)32
#define PORTE_PIN1_IDX                        (Port_PinType)33
#define PORTE_PIN2_IDX                        (Port_PinType)34
#define PORTE_PIN3_IDX                        (Port_PinType)35
#define PORTE_PIN4_IDX                        (Port_PinType)36
#define PORTE_PIN5_IDX                        (Port_PinType)37

#define PORTF_PIN0_IDX                        (Port_PinType)38
#define PORTF_PIN1_IDX                        (Port_PinType)39
#define PORTF_PIN2_IDX                        (Port_PinType)40
#define PORTF_PIN3_IDX                        (Port_PinType)41
#define PORTF_PIN4_IDX                        (Port_PinType)42
/*******************************************************************************
 *                                PORT MACROS                              *
 *******************************************************************************/
#define PORT_MAGIC_NUMBER                     0x4C4F434B

#endif
/* PORT_CFG_H_ */
