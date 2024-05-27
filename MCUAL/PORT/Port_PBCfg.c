 /******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Port_PBCfg.c
 *
 * Description:  This file contains the post build configuration of the PORT module
 *               according to AUTOSAR specifications.
 *
 * Author: Fatma Albaz
 *
 *******************************************************************************/
#include "Port_PBCfg.h"
#include "Port.h"

Port_ConfigType configured_pinsArr [NUMBER_OF_PORT_PINS]= {
                             /**************************************
                              *                  PORT A            *
                              **************************************/
PORTA_ID, PORTA_PIN0_ID, INPUT, PULL_UP,  STD_LOW,  PORT_A0_DIO_MODE, FALSE, TRUE, FALSE,             /*A0*/
PORTA_ID, PORTA_PIN1_ID, OUTPUT, OFF,     STD_LOW,  PORT_A1_DIO_MODE, FALSE, TRUE, FALSE,             /*A1*/
PORTA_ID, PORTA_PIN2_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_A2_DIO_MODE, FALSE, TRUE, FALSE,             /*A2*/
PORTA_ID, PORTA_PIN3_ID, OUTPUT, OFF,     STD_LOW,  PORT_A3_DIO_MODE, TRUE,  TRUE, FALSE,             /*A3*/
PORTA_ID, PORTA_PIN4_ID, INPUT, OFF,      STD_LOW,  PORT_A4_DIO_MODE, FALSE, TRUE, FALSE,             /*A4*/
PORTA_ID, PORTA_PIN5_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_A5_DIO_MODE, FALSE, TRUE, FALSE,             /*A5*/
PORTA_ID, PORTA_PIN6_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_A6_DIO_MODE, FALSE, TRUE, FALSE,             /*A6*/
PORTA_ID, PORTA_PIN7_ID, INPUT, OFF,      STD_HIGH, PORT_A7_DIO_MODE, FALSE, TRUE, FALSE,             /*A7*/
                             /**************************************
                              *                  PORT B            *
                              **************************************/
PORTB_ID, PORTB_PIN0_ID, INPUT, PULL_UP,  STD_LOW,  PORT_B0_DIO_MODE, FALSE, TRUE, FALSE,             /*B0*/
PORTB_ID, PORTB_PIN1_ID, OUTPUT, OFF,     STD_LOW,  PORT_B1_DIO_MODE, FALSE, TRUE, TRUE,              /*B1*/
PORTB_ID, PORTB_PIN2_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_B2_DIO_MODE, FALSE, TRUE, FALSE,             /*B2*/
PORTB_ID, PORTB_PIN3_ID, OUTPUT, OFF,     STD_LOW,  PORT_B3_DIO_MODE, TRUE,  TRUE, FALSE,             /*B3*/
PORTB_ID, PORTB_PIN4_ID, INPUT, OFF,      STD_LOW,  PORT_B4_DIO_MODE, FALSE, TRUE, FALSE,             /*B4*/
PORTB_ID, PORTB_PIN5_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_B5_DIO_MODE, TRUE,  TRUE, FALSE,             /*B5*/
PORTB_ID, PORTB_PIN6_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_B6_DIO_MODE, FALSE, TRUE, FALSE,             /*B6*/
PORTB_ID, PORTB_PIN7_ID, INPUT, OFF,      STD_HIGH, PORT_B7_DIO_MODE, FALSE, TRUE, FALSE,             /*B7*/
                            /**************************************
                             *                  PORT C            *
                             **************************************/
PORTC_ID, PORTC_PIN0_ID, INPUT,  PULL_UP, STD_LOW,  PORT_C0_DIO_MODE, FALSE, TRUE, FALSE,             /*C0*/
PORTC_ID, PORTC_PIN1_ID, OUTPUT, OFF,     STD_LOW,  PORT_C1_DIO_MODE, FALSE, TRUE, TRUE,              /*C1*/
PORTC_ID, PORTC_PIN2_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_C2_DIO_MODE, FALSE, TRUE, FALSE,             /*C2*/
PORTC_ID, PORTC_PIN3_ID, OUTPUT, OFF,     STD_LOW,  PORT_C3_DIO_MODE, TRUE,  TRUE, FALSE,             /*C3*/
PORTC_ID, PORTC_PIN4_ID, INPUT,  OFF,     STD_LOW,  PORT_C4_DIO_MODE, FALSE, TRUE, FALSE,             /*C4*/
PORTC_ID, PORTC_PIN5_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_C5_DIO_MODE, TRUE,  TRUE, FALSE,             /*C5*/
PORTC_ID, PORTC_PIN6_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_C6_DIO_MODE, FALSE, TRUE, FALSE,             /*C6*/
PORTC_ID, PORTC_PIN7_ID, INPUT,  OFF,     STD_HIGH, PORT_C7_DIO_MODE, FALSE, TRUE, FALSE,             /*C7*/
                            /**************************************
                             *                  PORT D            *
                             **************************************/
PORTD_ID, PORTD_PIN0_ID, INPUT,  PULL_UP, STD_LOW,  PORT_D0_DIO_MODE, FALSE, TRUE, FALSE,             /*C0*/
PORTD_ID, PORTD_PIN1_ID, OUTPUT, OFF,     STD_LOW,  PORT_D1_DIO_MODE, FALSE, TRUE, TRUE,              /*C1*/
PORTD_ID, PORTD_PIN2_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_D2_DIO_MODE, FALSE, TRUE, FALSE,             /*C2*/
PORTD_ID, PORTD_PIN3_ID, OUTPUT, OFF,     STD_LOW,  PORT_D3_DIO_MODE, TRUE,  TRUE, FALSE,             /*C3*/
PORTD_ID, PORTD_PIN4_ID, INPUT,  OFF,     STD_LOW,  PORT_D4_DIO_MODE, FALSE, TRUE, FALSE,             /*C4*/
PORTD_ID, PORTD_PIN5_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_D5_DIO_MODE, TRUE,  TRUE, FALSE,             /*C5*/
PORTD_ID, PORTD_PIN6_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_D6_DIO_MODE, FALSE, TRUE, FALSE,             /*C6*/
PORTD_ID, PORTD_PIN7_ID, INPUT,  OFF,     STD_HIGH, PORT_D7_DIO_MODE, FALSE, TRUE, FALSE,             /*C7*/
                            /**************************************
                             *                  PORT E            *
                             **************************************/
PORTE_ID, PORTE_PIN0_ID, INPUT,  PULL_UP, STD_LOW,  PORT_E0_DIO_MODE, FALSE, TRUE, FALSE,             /*E0*/
PORTE_ID, PORTE_PIN1_ID, OUTPUT, OFF,     STD_LOW,  PORT_E1_DIO_MODE, FALSE, TRUE, TRUE,              /*E1*/
PORTE_ID, PORTE_PIN2_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_E2_DIO_MODE, FALSE, TRUE, FALSE,             /*E2*/
PORTE_ID, PORTE_PIN3_ID, OUTPUT, OFF,     STD_LOW,  PORT_E3_DIO_MODE, TRUE,  TRUE, FALSE,             /*E3*/
PORTE_ID, PORTE_PIN4_ID, INPUT,  OFF,     STD_LOW,  PORT_E4_DIO_MODE, FALSE, TRUE, FALSE,             /*E4*/
PORTE_ID, PORTE_PIN5_ID, OUTPUT, PULL_UP, STD_HIGH, PORT_E5_DIO_MODE, TRUE,  TRUE, FALSE,             /*E5*/
                            /**************************************
                             *                  PORT F            *
                             **************************************/
PORTF_ID, PORTF_PIN0_ID, OUTPUT,  PULL_UP, STD_LOW,  PORT_E0_DIO_MODE, FALSE, TRUE, FALSE,             /*F0*/
PORTF_ID, PORTF_PIN1_ID, OUTPUT,  OFF,     STD_LOW,  PORT_E1_DIO_MODE, FALSE, TRUE, FALSE,   /* LED USED F1*/
PORTF_ID, PORTF_PIN2_ID, OUTPUT,  PULL_UP, STD_HIGH, PORT_E2_DIO_MODE, FALSE, TRUE, FALSE,             /*F2*/
PORTF_ID, PORTF_PIN3_ID, INPUT,   PULL_UP, STD_HIGH, PORT_E3_DIO_MODE, TRUE,  TRUE, FALSE,             /*F3*/
PORTF_ID, PORTF_PIN4_ID, INPUT ,  PULL_UP, STD_HIGH, PORT_E4_DIO_MODE, FALSE, TRUE, FALSE /* BUTTON USED F4*/
};

