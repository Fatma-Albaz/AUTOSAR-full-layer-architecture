 /******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Port_Cfg.c
 *
 * Description:  This file contains the configuration of the PORT module
 *               according to AUTOSAR specifications.
 *
 * Author: Fatma Albaz
 *
 *******************************************************************************/
#include "Port_Cfg.h"
#include "Port.h"
/*
 * The following array of available mode bits is declared to check available modes per pin
 * Ex: PORT A PIN 0 (PA0) has three different modes
 * 1. DIO    at bit 0
 * 2. U0Rx   at bit 1
 * 3. CAN1Rx at bit 8
 * then the index zero of the array representing (PA0) will contain the hex
 * value to be able to activate one of the three modes.
 * arr[0] = 0x102= 0b00010000010.
 * this value will be checked before setting the given mode in the port.c file
 */
const uint16 Port_PinsValidMode[NUMBER_OF_PORT_PINS]= {

                                             /*PA0*/         0x102, /*1, 8*/
                                             /*PA1*/         0X102, /*1, 8*/
                                             /*PA2*/         0X004, /*2*/
                                             /*PA3*/         0X004, /*2*/
                                             /*PA4*/         0X004, /*2*/
                                             /*PA5*/         0X004, /*2*/
                                             /*PA6*/         0X028, /*3, 5*/
                                             /*PA7*/         0X028, /*3, 5*/
                                             /*PB0*/         0X082, /*1, 7*/
                                             /*PB1*/         0X082, /*1, 7*/
                                             /*PB2*/         0X088, /*3, 7*/
                                             /*PB3*/         0X088, /*3, 7*/
                                             /*PB4*/         0X194, /*2, 4, 7, 8 */
                                             /*PB5*/         0X194, /*2, 4, 7, 8 */
                                             /*PB6*/         0X094, /*2, 4, 7 */
                                             /*PB7*/         0X094, /*2, 4, 7 */
                                             /*PC0*/         0x000, /*JTAG */
                                             /*PC1*/         0x000, /*JTAG */
                                             /*PC2*/         0x000, /*JTAG */
                                             /*PC3*/         0x000, /*JTAG */
                                             /*PC4*/         0X1D6, /*1, 2, 4, 6, 7, 8 */
                                             /*PC5*/         0X1D6, /*1, 2, 4, 6, 7, 8 */
                                             /*PC6*/         0X1C2, /*1, 6, 7, 8 */
                                             /*PC7*/         0x182, /*1, 7, 8 */
                                             /*PD0*/         0x0BE, /*0, 6 */
                                             /*PD1*/         0x0BE, /*0, 6 */
                                             /*PD2*/         0X196, /*1, 2, 4, 7, 8 */
                                             /*PD3*/         0X1C6, /*1, 2, 6, 7, 8 */
                                             /*PD4*/         0X082, /*1, 7 */
                                             /*PD5*/         0X082, /*1, 7 */
                                             /*PD6*/         0X0D2, /*1, 4, 6, 7 */
                                             /*PD7*/         0X1C2, /*1, 6, 7, 8 */
                                             /*PE0*/         0X002, /*1 */
                                             /*PE1*/         0X002, /*1 */
                                             /*PE2*/         0X000, /*DIO */
                                             /*PE3*/         0X000, /*DIO */
                                             /*PE4*/         0X13A, /*1, 3, 4, 5, 8 */
                                             /*PE5*/         0X13A, /*1, 3, 4, 5, 8 */
                                             /*PF0*/         0X3EE, /*NOT 4 */
                                             /*PF1*/         0X6E6, /*1, 2, 5, 6, 7, 9, 14 */
                                             /*PF2*/         0X4B4, /*2, 4, 5, 7, 14 */
                                             /*PF3*/         0X4AC, /*2, 3, 5, 7, 14 */
                                             /*PF4*/         0X1E0  /*5, 6, 7, 8 */
};
