 /******************************************************************************
 *
 * Module: PORT
 *
 * File Name: Port_PBCfg.h
 *
 * Description:  This file contains the post build configuration of the PORT module
 *               according to AUTOSAR specifications.
 *
 * Author: Fatma Albaz
 *
 *******************************************************************************/

#ifndef PORT_PBCFG_H_
#define PORT_PBCFG_H_

/*******************************************************************************
 *                             POST Build Version info                         *
 *******************************************************************************/
/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/*******************************************************************************
 *                               PORT vendors info                             *
 *******************************************************************************/
/* The vendors id */
#define PBCFG_VENDOR_ID                       (1000U)
/* PBCFG Module Id */
#define PBCFG_MODULE_ID                       (125U)
/* PBCFG Instance Id */
#define PBCFG_INSTANCE_ID                     (0U)


#endif /* PORT_PBCFG_H_ */
