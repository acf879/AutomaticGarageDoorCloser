/*
* Author: Ashton Fritz
* File: esp32.h
* Purpose: Definitions for ESP32
* Notes: Feel free to use just give credit where credit is due. These registers were taken from the technical documentation.
* References:
* Technical documentation: https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf
* Datasheet: https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf
* Issues with ESP32: https://www.espressif.com/sites/default/files/documentation/esp32_errata_en.pdf
/*
***************************************************************************
* Definitions for ESP32
***************************************************************************
*/

#ifndef _CPU_ESP32_H_
#define _CPU_ESP32_H_

/***********************************************************************/
/*
 * The basic data types
 *
 * Those are low-level so we mark them so that they may alias anything
 */

typedef unsigned char		                      uint8;  /*  8 bits */
typedef unsigned short int	                  uint16 __attribute__((__may_alias__));           /* 16 bits */
typedef unsigned long int	                    uint32 __attribute__((__may_alias__));           /* 32 bits */

typedef signed char			                      int8;   /*  8 bits */
typedef signed short int	                    int16 __attribute__((__may_alias__));            /* 16 bits */
typedef signed long int		                    int32 __attribute__((__may_alias__));            /* 32 bits */

typedef volatile uint8		                    vuint8 __attribute__((__may_alias__));           /*  8 bits */
typedef volatile uint16		                    vuint16 __attribute__((__may_alias__));          /* 16 bits */
typedef volatile uint32		                    vuint32 __attribute__((__may_alias__));          /* 32 bits */

/***********************************************************************/
/*
 * System configuration registers
 *
 * Configure clock frequency and chip revisions
 */

#define SYSCON_SYSCLK_CONF_REG               (*(vuint8  *)(&__IPSBAR[0x3FF66000]))                 /*Configures sys clock freq*/
#define SYSCON_XTAL_TICK_CONF_REG            (*(vuint8  *)(&__IPSBAR[0x3FF66004]))                 /*Configures div value of REF_TICK*/
#define SYSCON_PLL_TICK_CONF_REG             (*(vuint8  *)(&__IPSBAR[0x3FF66008]))                 /*Configures div value of REF_TICK*/
#define SYSCON_CK8M_TICK_CONF_REG            (*(vuint8  *)(&__IPSBAR[0x3FF6600C]))                 /*Configures div value of REF_TICK*/
#define SYSCON_APLL_TICK_CONFIG_REG          (*(vuint8  *)(&__IPSBAR[0x3FF6603C]))                 /*Configures div value of REF_TICK*/
#define SYSCON_DATE_REG                      (*(vuint8  *)(&__IPSBAR[0x3FF6607C]))                 /* chip revision register*/

/***********************************************************************/
/*
 * GPIO registers
 *
 * General purpose IO configuration registers
 */

#define GPIO_OUT_REG                         (*(vuint8  *)(&__IPSBAR[0x3FF44004]))             /*GPIO 0-31 output register*/
#define GPIO_OUT_W1TS_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF44008]))             /*GPIO 0-31 output register W1TS*/
#define GPIO_OUT_W1TC_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF4400C]))             /*GPIO 0-31 output register W1TC*/
#define GPIO_OUT1_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF44010]))             /*GPIO 32-39 output register*/
#define GPIO_OUT1_W1TS_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF44014]))             /*GPIO 32-39 output register W1TS*/
#define GPIO_OUT1_W1TC_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF44018]))             /*GPIO 32-39 output register W1TC*/
#define GPIO_ENABLE_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF44020]))             /*GPIO 0-31 enable register*/
#define GPIO_ENABLE_W1TS_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF44024]))             /*GPIO 0-31 enable register W1TS*/
#define GPIO_ENABLE_W1TC_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF44028]))             /*GPIO 0-31 enable register W1TC*/
#define GPIO_ENABLE1_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF4402C]))             /*GPIO 32-39 enable register*/
#define GPIO_ENABLE1_W1TS_REG                (*(vuint32 *)(&__IPSBAR[0x3FF44030]))             /*GPIO 32-39 enable register W1TS*/
#define GPIO_ENABLE1_W1TC_REG                (*(vuint32 *)(&__IPSBAR[0x3FF44034]))             /*GPIO 32-39 enable register W1TC*/
#define GPIO_STRAP_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF44038]))             /*Bootstrap pin value register*/
#define GPIO_IN_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF4403C]))             /*GPIO 0-31 input register*/
#define GPIO_IN1_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF44040]))             /*GPIO 32-39 input register*/
#define GPIO_STATUS_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF44044]))             /*GPIO 0-31 status register*/
#define GPIO_STATUS_W1TS_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF44048]))             /*GPIO 0-31 status register W1TS*/
#define GPIO_STATUS_W1TC_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF4404C]))             /*GPIO 0-31 status register W1TC*/
#define GPIO_STATUS1_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF44050]))             /*GPIO 32-39 status register*/
#define GPIO_STATUS1_W1TS_REG                (*(vuint32 *)(&__IPSBAR[0x3FF44054]))             /*GPIO 32-39 status register W1TS*/
#define GPIO_STATUS1_W1TC_REG                (*(vuint32 *)(&__IPSBAR[0x3FF44058]))             /*GPIO 32-39 status register W1TC*/
#define GPIO_ACPU_INT_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF44060]))             /*GPIO 0-31 APP_CPU interrupt status*/
#define GPIO_ACPU_NMI_INT_REG                (*(vuint32 *)(&__IPSBAR[0x3FF44064]))             /*GPIO 0-31 APP_CPU non-maskable interrupt status*/
#define GPIO_PCPU_INT_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF44068]))             /*GPIO 0-31 PRO_CPU interrupt status*/
#define GPIO_PCPU_NMI_INT_REG                (*(vuint32 *)(&__IPSBAR[0x3FF4406C]))             /*GPIO 0-31 PRO_CPU non-maskable interrupt status*/
#define GPIO_ACPU_INT1_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF44074]))             /*GPIO 32-39 APP_CPU interrupt status*/
#define GPIO_ACPU_NMI_INT1_REG               (*(vuint32 *)(&__IPSBAR[0x3FF44078]))             /*GPIO 32-39 APP_CPU non-maskable interrupt status*/
#define GPIO_PCPU_INT1_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF4407C]))             /*GPIO 32-39 PRO_CPU interrupt status*/
#define GPIO_PCPU_NMI_INT1_REG               (*(vuint32 *)(&__IPSBAR[0x3FF44080]))             /*GPIO 32-39 PRO_CPU non-maskable interrupt status*/

#define GPIO_PIN0_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF44088]))             /*Configuration for GPIO pin 0*/
#define GPIO_PIN1_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF4408C]))             /*Configuration for GPIO pin 1*/
#define GPIO_PIN2_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF44090]))             /*Configuration for GPIO pin 2*/
#define GPIO_PIN3_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF44094]))             /*Configuration for GPIO pin 3*/
#define GPIO_PIN4_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF44098]))             /*Configuration for GPIO pin 4*/
#define GPIO_PIN5_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF4409C]))             /*Configuration for GPIO pin 5*/
#define GPIO_PIN6_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF440A0]))             /*Configuration for GPIO pin 6*/
#define GPIO_PIN7_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF440A4]))             /*Configuration for GPIO pin 7*/
#define GPIO_PIN8_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF440A8]))             /*Configuration for GPIO pin 8*/
#define GPIO_PIN9_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF440AC]))             /*Configuration for GPIO pin 9*/
#define GPIO_PIN10_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440B0]))             /*Configuration for GPIO pin 10*/
#define GPIO_PIN11_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440B4]))             /*Configuration for GPIO pin 11*/
#define GPIO_PIN12_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440B8]))             /*Configuration for GPIO pin 12*/
#define GPIO_PIN13_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440BC]))             /*Configuration for GPIO pin 13*/
#define GPIO_PIN14_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440C0]))             /*Configuration for GPIO pin 14*/
#define GPIO_PIN15_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440C4]))             /*Configuration for GPIO pin 15*/
#define GPIO_PIN16_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440C8]))             /*Configuration for GPIO pin 16*/
#define GPIO_PIN17_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440CC]))             /*Configuration for GPIO pin 17*/
#define GPIO_PIN18_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440D0]))             /*Configuration for GPIO pin 18*/
#define GPIO_PIN19_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440D4]))             /*Configuration for GPIO pin 19*/
#define GPIO_PIN20_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440D8]))             /*Configuration for GPIO pin 20*/
#define GPIO_PIN21_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440DC]))             /*Configuration for GPIO pin 21*/
#define GPIO_PIN22_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440E0]))             /*Configuration for GPIO pin 22*/
#define GPIO_PIN23_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440E4]))             /*Configuration for GPIO pin 23*/
#define GPIO_PIN24_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440E8]))             /*Configuration for GPIO pin 24*/
#define GPIO_PIN25_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440EC]))             /*Configuration for GPIO pin 25*/
#define GPIO_PIN26_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440F0]))             /*Configuration for GPIO pin 26*/
#define GPIO_PIN27_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440F4]))             /*Configuration for GPIO pin 27*/
#define GPIO_PIN28_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440F8]))             /*Configuration for GPIO pin 28*/
#define GPIO_PIN29_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF440FC]))             /*Configuration for GPIO pin 29*/
#define GPIO_PIN30_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF44100]))             /*Configuration for GPIO pin 30*/
#define GPIO_PIN31_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF44104]))             /*Configuration for GPIO pin 31*/

#define GPIO_PIN32_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF44108]))             /*Configuration for GPIO pin 32*/
#define GPIO_PIN33_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF4410C]))             /*Configuration for GPIO pin 33*/
#define GPIO_PIN34_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF44110]))             /*Configuration for GPIO pin 34*/
#define GPIO_PIN35_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF44114]))             /*Configuration for GPIO pin 35*/
#define GPIO_PIN36_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF44118]))             /*Configuration for GPIO pin 36*/
#define GPIO_PIN37_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF4411C]))             /*Configuration for GPIO pin 37*/
#define GPIO_PIN38_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF44120]))             /*Configuration for GPIO pin 38*/
#define GPIO_PIN39_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF44124]))             /*Configuration for GPIO pin 39*/

#define GPIO_FUNC0_IN_SEL_CFG_REG            (*(vuint32 *)(&__IPSBAR[0x3FF44130]))             /*Peripheral function 0 input selection register*/
#define GPIO_FUNC1_IN_SEL_CFG_REG            (*(vuint32 *)(&__IPSBAR[0x3FF44134]))             /*Peripheral function 1 input selection register*/
#define GPIO_FUNC2_IN_SEL_CFG_REG            (*(vuint32 *)(&__IPSBAR[0x3FF44138]))             /*Peripheral function 2 input selection register*/
#define GPIO_FUNC3_IN_SEL_CFG_REG            (*(vuint32 *)(&__IPSBAR[0x3FF4413C]))             /*Peripheral function 3 input selection register*/
#define GPIO_FUNC4_IN_SEL_CFG_REG            (*(vuint32 *)(&__IPSBAR[0x3FF44140]))             /*Peripheral function 4 input selection register*/
#define GPIO_FUNC5_IN_SEL_CFG_REG            (*(vuint32 *)(&__IPSBAR[0x3FF44144]))             /*Peripheral function 5 input selection register*/
#define GPIO_FUNC6_IN_SEL_CFG_REG            (*(vuint32 *)(&__IPSBAR[0x3FF44148]))             /*Peripheral function 6 input selection register*/
#define GPIO_FUNC7_IN_SEL_CFG_REG            (*(vuint32 *)(&__IPSBAR[0x3FF4414C]))             /*Peripheral function 7 input selection register*/
#define GPIO_FUNC8_IN_SEL_CFG_REG            (*(vuint32 *)(&__IPSBAR[0x3FF44150]))             /*Peripheral function 8 input selection register*/
#define GPIO_FUNC9_IN_SEL_CFG_REG            (*(vuint32 *)(&__IPSBAR[0x3FF44154]))             /*Peripheral function 9 input selection register*/
#define GPIO_FUNC10_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44158]))             /*Peripheral function 10 input selection register*/
#define GPIO_FUNC11_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4415C]))             /*Peripheral function 11 input selection register*/
#define GPIO_FUNC12_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44160]))             /*Peripheral function 12 input selection register*/
#define GPIO_FUNC13_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44164]))             /*Peripheral function 13 input selection register*/
#define GPIO_FUNC14_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44168]))             /*Peripheral function 14 input selection register*/
#define GPIO_FUNC15_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4416C]))             /*Peripheral function 15 input selection register*/
#define GPIO_FUNC16_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44170]))             /*Peripheral function 16 input selection register*/
#define GPIO_FUNC17_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44174]))             /*Peripheral function 17 input selection register*/
#define GPIO_FUNC18_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44178]))             /*Peripheral function 18 input selection register*/
#define GPIO_FUNC19_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4417C]))             /*Peripheral function 19 input selection register*/
#define GPIO_FUNC20_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44180]))             /*Peripheral function 20 input selection register*/
#define GPIO_FUNC21_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44184]))             /*Peripheral function 21 input selection register*/
#define GPIO_FUNC22_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44188]))             /*Peripheral function 22 input selection register*/
#define GPIO_FUNC23_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4418C]))             /*Peripheral function 23 input selection register*/
#define GPIO_FUNC24_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44190]))             /*Peripheral function 24 input selection register*/
#define GPIO_FUNC25_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44194]))             /*Peripheral function 25 input selection register*/
#define GPIO_FUNC26_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44198]))             /*Peripheral function 26 input selection register*/
#define GPIO_FUNC27_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4419C]))             /*Peripheral function 27 input selection register*/
#define GPIO_FUNC28_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441A0]))             /*Peripheral function 28 input selection register*/
#define GPIO_FUNC29_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441A4]))             /*Peripheral function 29 input selection register*/
#define GPIO_FUNC30_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441A8]))             /*Peripheral function 30 input selection register*/
#define GPIO_FUNC31_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441AC]))             /*Peripheral function 31 input selection register*/
#define GPIO_FUNC32_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441B0]))             /*Peripheral function 32 input selection register*/
#define GPIO_FUNC33_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441B4]))             /*Peripheral function 33 input selection register*/
#define GPIO_FUNC34_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441B8]))             /*Peripheral function 34 input selection register*/
#define GPIO_FUNC35_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441BC]))             /*Peripheral function 35 input selection register*/
#define GPIO_FUNC36_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441C0]))             /*Peripheral function 36 input selection register*/
#define GPIO_FUNC37_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441C4]))             /*Peripheral function 37 input selection register*/
#define GPIO_FUNC38_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441C8]))             /*Peripheral function 38 input selection register*/
#define GPIO_FUNC39_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441CC]))             /*Peripheral function 39 input selection register*/
#define GPIO_FUNC40_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441D0]))             /*Peripheral function 40 input selection register*/
#define GPIO_FUNC41_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441D4]))             /*Peripheral function 41 input selection register*/
#define GPIO_FUNC42_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441D8]))             /*Peripheral function 42 input selection register*/
#define GPIO_FUNC43_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441DC]))             /*Peripheral function 43 input selection register*/
#define GPIO_FUNC44_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441E0]))             /*Peripheral function 44 input selection register*/
#define GPIO_FUNC45_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441E4]))             /*Peripheral function 45 input selection register*/
#define GPIO_FUNC46_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441E8]))             /*Peripheral function 46 input selection register*/
#define GPIO_FUNC47_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441EC]))             /*Peripheral function 47 input selection register*/
#define GPIO_FUNC48_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441F0]))             /*Peripheral function 48 input selection register*/
#define GPIO_FUNC49_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441F4]))             /*Peripheral function 49 input selection register*/
#define GPIO_FUNC50_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441F8]))             /*Peripheral function 50 input selection register*/
#define GPIO_FUNC51_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF441FC]))             /*Peripheral function 51 input selection register*/
#define GPIO_FUNC52_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44200]))             /*Peripheral function 52 input selection register*/
#define GPIO_FUNC53_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44204]))             /*Peripheral function 53 input selection register*/
#define GPIO_FUNC54_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44208]))             /*Peripheral function 54 input selection register*/
#define GPIO_FUNC55_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4420C]))             /*Peripheral function 55 input selection register*/
#define GPIO_FUNC56_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44210]))             /*Peripheral function 56 input selection register*/
#define GPIO_FUNC57_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44214]))             /*Peripheral function 57 input selection register*/
#define GPIO_FUNC58_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44218]))             /*Peripheral function 58 input selection register*/
#define GPIO_FUNC59_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4421C]))             /*Peripheral function 59 input selection register*/
#define GPIO_FUNC60_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44220]))             /*Peripheral function 60 input selection register*/
#define GPIO_FUNC61_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44224]))             /*Peripheral function 61 input selection register*/
#define GPIO_FUNC62_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44228]))             /*Peripheral function 62 input selection register*/
#define GPIO_FUNC63_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4422C]))             /*Peripheral function 63 input selection register*/
#define GPIO_FUNC64_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44230]))             /*Peripheral function 64 input selection register*/
#define GPIO_FUNC65_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44234]))             /*Peripheral function 65 input selection register*/
#define GPIO_FUNC66_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44238]))             /*Peripheral function 66 input selection register*/
#define GPIO_FUNC67_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4423C]))             /*Peripheral function 67 input selection register*/
#define GPIO_FUNC68_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44240]))             /*Peripheral function 68 input selection register*/
#define GPIO_FUNC69_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44244]))             /*Peripheral function 69 input selection register*/
#define GPIO_FUNC70_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44248]))             /*Peripheral function 70 input selection register*/
#define GPIO_FUNC71_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4424C]))             /*Peripheral function 71 input selection register*/
#define GPIO_FUNC72_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44250]))             /*Peripheral function 72 input selection register*/
#define GPIO_FUNC73_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44254]))             /*Peripheral function 73 input selection register*/
#define GPIO_FUNC74_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44258]))             /*Peripheral function 74 input selection register*/
#define GPIO_FUNC75_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4425C]))             /*Peripheral function 75 input selection register*/
#define GPIO_FUNC76_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44260]))             /*Peripheral function 76 input selection register*/
#define GPIO_FUNC77_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44264]))             /*Peripheral function 77 input selection register*/
#define GPIO_FUNC78_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44268]))             /*Peripheral function 78 input selection register*/
#define GPIO_FUNC79_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4426C]))             /*Peripheral function 79 input selection register*/
#define GPIO_FUNC80_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44270]))             /*Peripheral function 80 input selection register*/
#define GPIO_FUNC81_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44274]))             /*Peripheral function 81 input selection register*/
#define GPIO_FUNC82_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44278]))             /*Peripheral function 82 input selection register*/
#define GPIO_FUNC83_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4427C]))             /*Peripheral function 83 input selection register*/
#define GPIO_FUNC84_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44280]))             /*Peripheral function 84 input selection register*/
#define GPIO_FUNC85_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44284]))             /*Peripheral function 85 input selection register*/
#define GPIO_FUNC86_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44288]))             /*Peripheral function 86 input selection register*/
#define GPIO_FUNC87_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4428C]))             /*Peripheral function 87 input selection register*/
#define GPIO_FUNC88_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44290]))             /*Peripheral function 88 input selection register*/
#define GPIO_FUNC89_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44294]))             /*Peripheral function 89 input selection register*/
#define GPIO_FUNC90_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44298]))             /*Peripheral function 90 input selection register*/
#define GPIO_FUNC91_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4429C]))             /*Peripheral function 91 input selection register*/
#define GPIO_FUNC92_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF442A0]))             /*Peripheral function 92 input selection register*/
#define GPIO_FUNC93_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF442A4]))             /*Peripheral function 93 input selection register*/
#define GPIO_FUNC94_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF442A8]))             /*Peripheral function 94 input selection register*/
#define GPIO_FUNC95_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF442AC]))             /*Peripheral function 95 input selection register*/
#define GPIO_FUNC96_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF442B0]))             /*Peripheral function 96 input selection register*/
#define GPIO_FUNC97_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF442B4]))             /*Peripheral function 97 input selection register*/
#define GPIO_FUNC98_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF442B8]))             /*Peripheral function 98 input selection register*/
#define GPIO_FUNC99_IN_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF442BC]))             /*Peripheral function 99 input selection register*/
#define GPIO_FUNC100_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442C0]))             /*Peripheral function 100 input selection register*/
#define GPIO_FUNC101_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442C4]))             /*Peripheral function 101 input selection register*/
#define GPIO_FUNC102_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442C8]))             /*Peripheral function 102 input selection register*/
#define GPIO_FUNC103_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442CC]))             /*Peripheral function 103 input selection register*/
#define GPIO_FUNC104_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442D0]))             /*Peripheral function 104 input selection register*/
#define GPIO_FUNC105_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442D4]))             /*Peripheral function 105 input selection register*/
#define GPIO_FUNC106_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442D8]))             /*Peripheral function 106 input selection register*/
#define GPIO_FUNC107_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442DC]))             /*Peripheral function 107 input selection register*/
#define GPIO_FUNC108_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442E0]))             /*Peripheral function 108 input selection register*/
#define GPIO_FUNC109_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442E4]))             /*Peripheral function 109 input selection register*/
#define GPIO_FUNC110_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442E8]))             /*Peripheral function 110 input selection register*/
#define GPIO_FUNC111_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442EC]))             /*Peripheral function 111 input selection register*/
#define GPIO_FUNC112_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442F0]))             /*Peripheral function 112 input selection register*/
#define GPIO_FUNC113_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442F4]))             /*Peripheral function 113 input selection register*/
#define GPIO_FUNC114_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442F8]))             /*Peripheral function 114 input selection register*/
#define GPIO_FUNC115_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF442FC]))             /*Peripheral function 115 input selection register*/
#define GPIO_FUNC116_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44300]))             /*Peripheral function 116 input selection register*/
#define GPIO_FUNC117_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44304]))             /*Peripheral function 117 input selection register*/
#define GPIO_FUNC118_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44308]))             /*Peripheral function 118 input selection register*/
#define GPIO_FUNC119_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4430C]))             /*Peripheral function 119 input selection register*/
#define GPIO_FUNC120_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44310]))             /*Peripheral function 120 input selection register*/
#define GPIO_FUNC121_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44314]))             /*Peripheral function 121 input selection register*/
#define GPIO_FUNC122_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44318]))             /*Peripheral function 122 input selection register*/
#define GPIO_FUNC123_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4431C]))             /*Peripheral function 123 input selection register*/
#define GPIO_FUNC124_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44320]))             /*Peripheral function 124 input selection register*/
#define GPIO_FUNC125_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44324]))             /*Peripheral function 125 input selection register*/
#define GPIO_FUNC126_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44328]))             /*Peripheral function 126 input selection register*/
#define GPIO_FUNC127_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4432C]))             /*Peripheral function 127 input selection register*/
#define GPIO_FUNC128_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44330]))             /*Peripheral function 128 input selection register*/
#define GPIO_FUNC129_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44334]))             /*Peripheral function 129 input selection register*/
#define GPIO_FUNC130_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44338]))             /*Peripheral function 130 input selection register*/
#define GPIO_FUNC131_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4433C]))             /*Peripheral function 131 input selection register*/
#define GPIO_FUNC132_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44340]))             /*Peripheral function 132 input selection register*/
#define GPIO_FUNC133_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44344]))             /*Peripheral function 133 input selection register*/
#define GPIO_FUNC134_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44348]))             /*Peripheral function 134 input selection register*/
#define GPIO_FUNC135_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4434C]))             /*Peripheral function 135 input selection register*/
#define GPIO_FUNC136_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44350]))             /*Peripheral function 136 input selection register*/
#define GPIO_FUNC137_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44354]))             /*Peripheral function 137 input selection register*/
#define GPIO_FUNC138_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44358]))             /*Peripheral function 138 input selection register*/
#define GPIO_FUNC139_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4435C]))             /*Peripheral function 139 input selection register*/
#define GPIO_FUNC140_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44360]))             /*Peripheral function 140 input selection register*/
#define GPIO_FUNC141_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44364]))             /*Peripheral function 141 input selection register*/
#define GPIO_FUNC142_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44368]))             /*Peripheral function 142 input selection register*/
#define GPIO_FUNC143_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4436C]))             /*Peripheral function 143 input selection register*/
#define GPIO_FUNC144_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44370]))             /*Peripheral function 144 input selection register*/
#define GPIO_FUNC145_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44374]))             /*Peripheral function 145 input selection register*/
#define GPIO_FUNC146_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44378]))             /*Peripheral function 146 input selection register*/
#define GPIO_FUNC147_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4437C]))             /*Peripheral function 147 input selection register*/
#define GPIO_FUNC148_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44380]))             /*Peripheral function 148 input selection register*/
#define GPIO_FUNC149_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44384]))             /*Peripheral function 149 input selection register*/
#define GPIO_FUNC150_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44388]))             /*Peripheral function 150 input selection register*/
#define GPIO_FUNC151_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4438C]))             /*Peripheral function 151 input selection register*/
#define GPIO_FUNC152_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44390]))             /*Peripheral function 152 input selection register*/
#define GPIO_FUNC153_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44394]))             /*Peripheral function 153 input selection register*/
#define GPIO_FUNC154_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44398]))             /*Peripheral function 154 input selection register*/
#define GPIO_FUNC155_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4439C]))             /*Peripheral function 155 input selection register*/
#define GPIO_FUNC156_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443A0]))             /*Peripheral function 156 input selection register*/
#define GPIO_FUNC157_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443A4]))             /*Peripheral function 157 input selection register*/
#define GPIO_FUNC158_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443A8]))             /*Peripheral function 158 input selection register*/
#define GPIO_FUNC159_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443AC]))             /*Peripheral function 159 input selection register*/
#define GPIO_FUNC160_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443B0]))             /*Peripheral function 160 input selection register*/
#define GPIO_FUNC161_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443B4]))             /*Peripheral function 161 input selection register*/
#define GPIO_FUNC162_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443B8]))             /*Peripheral function 162 input selection register*/
#define GPIO_FUNC163_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443BC]))             /*Peripheral function 163 input selection register*/
#define GPIO_FUNC164_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443C0]))             /*Peripheral function 164 input selection register*/
#define GPIO_FUNC165_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443C4]))             /*Peripheral function 165 input selection register*/
#define GPIO_FUNC166_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443C8]))             /*Peripheral function 166 input selection register*/
#define GPIO_FUNC167_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443CC]))             /*Peripheral function 167 input selection register*/
#define GPIO_FUNC168_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443D0]))             /*Peripheral function 168 input selection register*/
#define GPIO_FUNC169_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443D4]))             /*Peripheral function 169 input selection register*/
#define GPIO_FUNC170_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443D8]))             /*Peripheral function 170 input selection register*/
#define GPIO_FUNC171_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443DC]))             /*Peripheral function 171 input selection register*/
#define GPIO_FUNC172_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443E0]))             /*Peripheral function 172 input selection register*/
#define GPIO_FUNC173_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443E4]))             /*Peripheral function 173 input selection register*/
#define GPIO_FUNC174_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443E8]))             /*Peripheral function 174 input selection register*/
#define GPIO_FUNC175_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443EC]))             /*Peripheral function 175 input selection register*/
#define GPIO_FUNC176_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443F0]))             /*Peripheral function 176 input selection register*/
#define GPIO_FUNC177_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443F4]))             /*Peripheral function 177 input selection register*/
#define GPIO_FUNC178_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443F8]))             /*Peripheral function 178 input selection register*/
#define GPIO_FUNC179_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF443FC]))             /*Peripheral function 179 input selection register*/
#define GPIO_FUNC180_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44400]))             /*Peripheral function 180 input selection register*/
#define GPIO_FUNC181_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44404]))             /*Peripheral function 181 input selection register*/
#define GPIO_FUNC182_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44408]))             /*Peripheral function 182 input selection register*/
#define GPIO_FUNC183_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4440C]))             /*Peripheral function 183 input selection register*/
#define GPIO_FUNC184_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44410]))             /*Peripheral function 184 input selection register*/
#define GPIO_FUNC185_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44414]))             /*Peripheral function 185 input selection register*/
#define GPIO_FUNC186_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44418]))             /*Peripheral function 186 input selection register*/
#define GPIO_FUNC187_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4441C]))             /*Peripheral function 187 input selection register*/
#define GPIO_FUNC188_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44420]))             /*Peripheral function 188 input selection register*/
#define GPIO_FUNC189_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44424]))             /*Peripheral function 189 input selection register*/
#define GPIO_FUNC190_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44428]))             /*Peripheral function 190 input selection register*/
#define GPIO_FUNC191_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4442C]))             /*Peripheral function 191 input selection register*/
#define GPIO_FUNC192_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44430]))             /*Peripheral function 192 input selection register*/
#define GPIO_FUNC193_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44434]))             /*Peripheral function 193 input selection register*/
#define GPIO_FUNC194_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44438]))             /*Peripheral function 194 input selection register*/
#define GPIO_FUNC195_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4443C]))             /*Peripheral function 195 input selection register*/
#define GPIO_FUNC196_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44440]))             /*Peripheral function 196 input selection register*/
#define GPIO_FUNC197_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44444]))             /*Peripheral function 197 input selection register*/
#define GPIO_FUNC198_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44448]))             /*Peripheral function 198 input selection register*/
#define GPIO_FUNC199_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4444C]))             /*Peripheral function 199 input selection register*/
#define GPIO_FUNC200_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44450]))             /*Peripheral function 200 input selection register*/
#define GPIO_FUNC201_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44454]))             /*Peripheral function 201 input selection register*/
#define GPIO_FUNC202_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44458]))             /*Peripheral function 202 input selection register*/
#define GPIO_FUNC203_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4445C]))             /*Peripheral function 203 input selection register*/
#define GPIO_FUNC204_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44460]))             /*Peripheral function 204 input selection register*/
#define GPIO_FUNC205_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44464]))             /*Peripheral function 205 input selection register*/
#define GPIO_FUNC206_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44468]))             /*Peripheral function 206 input selection register*/
#define GPIO_FUNC207_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4446C]))             /*Peripheral function 207 input selection register*/
#define GPIO_FUNC208_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44470]))             /*Peripheral function 208 input selection register*/
#define GPIO_FUNC209_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44474]))             /*Peripheral function 209 input selection register*/
#define GPIO_FUNC210_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44478]))             /*Peripheral function 210 input selection register*/
#define GPIO_FUNC211_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4447C]))             /*Peripheral function 211 input selection register*/
#define GPIO_FUNC212_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44480]))             /*Peripheral function 212 input selection register*/
#define GPIO_FUNC213_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44484]))             /*Peripheral function 213 input selection register*/
#define GPIO_FUNC214_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44488]))             /*Peripheral function 214 input selection register*/
#define GPIO_FUNC215_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4448C]))             /*Peripheral function 215 input selection register*/
#define GPIO_FUNC216_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44490]))             /*Peripheral function 216 input selection register*/
#define GPIO_FUNC217_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44494]))             /*Peripheral function 217 input selection register*/
#define GPIO_FUNC218_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44498]))             /*Peripheral function 218 input selection register*/
#define GPIO_FUNC219_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4449C]))             /*Peripheral function 219 input selection register*/
#define GPIO_FUNC220_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444A0]))             /*Peripheral function 220 input selection register*/
#define GPIO_FUNC221_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444A4]))             /*Peripheral function 221 input selection register*/
#define GPIO_FUNC222_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444A8]))             /*Peripheral function 222 input selection register*/
#define GPIO_FUNC223_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444AC]))             /*Peripheral function 223 input selection register*/
#define GPIO_FUNC224_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444B0]))             /*Peripheral function 224 input selection register*/
#define GPIO_FUNC225_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444B4]))             /*Peripheral function 225 input selection register*/
#define GPIO_FUNC226_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444B8]))             /*Peripheral function 226 input selection register*/
#define GPIO_FUNC227_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444BC]))             /*Peripheral function 227 input selection register*/
#define GPIO_FUNC228_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444C0]))             /*Peripheral function 228 input selection register*/
#define GPIO_FUNC229_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444C4]))             /*Peripheral function 229 input selection register*/
#define GPIO_FUNC230_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444C8]))             /*Peripheral function 230 input selection register*/
#define GPIO_FUNC231_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444CC]))             /*Peripheral function 231 input selection register*/
#define GPIO_FUNC232_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444D0]))             /*Peripheral function 232 input selection register*/
#define GPIO_FUNC233_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444D4]))             /*Peripheral function 233 input selection register*/
#define GPIO_FUNC234_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444D8]))             /*Peripheral function 234 input selection register*/
#define GPIO_FUNC235_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444DC]))             /*Peripheral function 235 input selection register*/
#define GPIO_FUNC236_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444E0]))             /*Peripheral function 236 input selection register*/
#define GPIO_FUNC237_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444E4]))             /*Peripheral function 237 input selection register*/
#define GPIO_FUNC238_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444E8]))             /*Peripheral function 238 input selection register*/
#define GPIO_FUNC239_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444EC]))             /*Peripheral function 239 input selection register*/
#define GPIO_FUNC240_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444F0]))             /*Peripheral function 240 input selection register*/
#define GPIO_FUNC241_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444F4]))             /*Peripheral function 241 input selection register*/
#define GPIO_FUNC242_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444F8]))             /*Peripheral function 242 input selection register*/
#define GPIO_FUNC243_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF444FC]))             /*Peripheral function 243 input selection register*/
#define GPIO_FUNC244_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44500]))             /*Peripheral function 244 input selection register*/
#define GPIO_FUNC245_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44504]))             /*Peripheral function 245 input selection register*/
#define GPIO_FUNC246_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44508]))             /*Peripheral function 246 input selection register*/
#define GPIO_FUNC247_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4450C]))             /*Peripheral function 247 input selection register*/
#define GPIO_FUNC248_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44510]))             /*Peripheral function 248 input selection register*/
#define GPIO_FUNC249_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44514]))             /*Peripheral function 249 input selection register*/
#define GPIO_FUNC250_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44518]))             /*Peripheral function 250 input selection register*/
#define GPIO_FUNC251_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4451C]))             /*Peripheral function 251 input selection register*/
#define GPIO_FUNC252_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44520]))             /*Peripheral function 252 input selection register*/
#define GPIO_FUNC253_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44524]))             /*Peripheral function 253 input selection register*/
#define GPIO_FUNC254_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44528]))             /*Peripheral function 254 input selection register*/
#define GPIO_FUNC255_IN_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4452C]))             /*Peripheral function 255 input selection register*/

#define GPIO_FUNC0_OUT_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44530]))             /*Peripheral output selection register for GPIO 0*/
#define GPIO_FUNC1_OUT_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44534]))             /*Peripheral output selection register for GPIO 1*/
#define GPIO_FUNC2_OUT_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44538]))             /*Peripheral output selection register for GPIO 2*/
#define GPIO_FUNC3_OUT_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4453C]))             /*Peripheral output selection register for GPIO 3*/
#define GPIO_FUNC4_OUT_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44540]))             /*Peripheral output selection register for GPIO 4*/
#define GPIO_FUNC5_OUT_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44544]))             /*Peripheral output selection register for GPIO 5*/
#define GPIO_FUNC6_OUT_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44548]))             /*Peripheral output selection register for GPIO 6*/
#define GPIO_FUNC7_OUT_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF4454C]))             /*Peripheral output selection register for GPIO 7*/
#define GPIO_FUNC8_OUT_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44550]))             /*Peripheral output selection register for GPIO 8*/
#define GPIO_FUNC9_OUT_SEL_CFG_REG           (*(vuint32 *)(&__IPSBAR[0x3FF44554]))             /*Peripheral output selection register for GPIO 9*/
#define GPIO_FUNC10_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44558]))             /*Peripheral output selection register for GPIO 10*/
#define GPIO_FUNC11_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4455C]))             /*Peripheral output selection register for GPIO 11*/
#define GPIO_FUNC12_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44560]))             /*Peripheral output selection register for GPIO 12*/
#define GPIO_FUNC13_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44564]))             /*Peripheral output selection register for GPIO 13*/
#define GPIO_FUNC14_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44568]))             /*Peripheral output selection register for GPIO 14*/
#define GPIO_FUNC15_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4456C]))             /*Peripheral output selection register for GPIO 15*/
#define GPIO_FUNC16_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44570]))             /*Peripheral output selection register for GPIO 16*/
#define GPIO_FUNC17_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44574]))             /*Peripheral output selection register for GPIO 17*/
#define GPIO_FUNC18_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44578]))             /*Peripheral output selection register for GPIO 18*/
#define GPIO_FUNC19_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4457C]))             /*Peripheral output selection register for GPIO 19*/
#define GPIO_FUNC20_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44580]))             /*Peripheral output selection register for GPIO 20*/
#define GPIO_FUNC21_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44584]))             /*Peripheral output selection register for GPIO 21*/
#define GPIO_FUNC22_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44588]))             /*Peripheral output selection register for GPIO 22*/
#define GPIO_FUNC23_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4458C]))             /*Peripheral output selection register for GPIO 23*/
#define GPIO_FUNC24_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44590]))             /*Peripheral output selection register for GPIO 24*/
#define GPIO_FUNC25_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44594]))             /*Peripheral output selection register for GPIO 25*/
#define GPIO_FUNC26_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF44598]))             /*Peripheral output selection register for GPIO 26*/
#define GPIO_FUNC27_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF4459C]))             /*Peripheral output selection register for GPIO 27*/
#define GPIO_FUNC28_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445A0]))             /*Peripheral output selection register for GPIO 28*/
#define GPIO_FUNC29_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445A4]))             /*Peripheral output selection register for GPIO 29*/
#define GPIO_FUNC30_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445A8]))             /*Peripheral output selection register for GPIO 30*/
#define GPIO_FUNC31_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445AC]))             /*Peripheral output selection register for GPIO 31*/
#define GPIO_FUNC32_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445B0]))             /*Peripheral output selection register for GPIO 32*/
#define GPIO_FUNC33_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445B4]))             /*Peripheral output selection register for GPIO 33*/
#define GPIO_FUNC34_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445B8]))             /*Peripheral output selection register for GPIO 34*/
#define GPIO_FUNC35_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445BC]))             /*Peripheral output selection register for GPIO 35*/
#define GPIO_FUNC36_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445C0]))             /*Peripheral output selection register for GPIO 36*/
#define GPIO_FUNC37_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445C4]))             /*Peripheral output selection register for GPIO 37*/
#define GPIO_FUNC38_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445C8]))             /*Peripheral output selection register for GPIO 38*/
#define GPIO_FUNC39_OUT_SEL_CFG_REG          (*(vuint32 *)(&__IPSBAR[0x3FF445CC]))             /*Peripheral output selection register for GPIO 39*/

#define GPIO_PINn_REG(n)                     (*(vuint32 *)(&__IPSBAR[0x3FF44088 + (n * 4)]))   /*Configuration for GPIO pin n*/
#define GPIO_FUNCn_IN_SEL_CFG_REG(n)         (*(vuint32 *)(&__IPSBAR[0x3FF441FC + (n * 4)]))   /*Peripheral function n input selection register*/
#define GPIO_FUNCn_OUT_SEL_CFG_REG(n)        (*(vuint32 *)(&__IPSBAR[0x3FF44530 + (n * 4)])) /*Peripheral output selection register for GPIO n*/
/***********************************************************************/
/*
 * IO MUX Register Summary
 *
 * Configuration mux registers
 */
#define IO_MUX_PIN_CTRL                      (*(vuint32 *)(&__IPSBAR[0x3FF49000]))             /*Clock output config reg*/
#define IO_MUX_GPIO36_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49004]))             /*config reg for pad GPIO36*/
#define IO_MUX_GPIO37_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49008]))             /*config reg for pad GPIO37*/
#define IO_MUX_GPIO38_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF4900C]))             /*config reg for pad GPIO38*/
#define IO_MUX_GPIO39_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49010]))             /*config reg for pad GPIO39*/
#define IO_MUX_GPIO34_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49014]))             /*config reg for pad GPIO34*/
#define IO_MUX_GPIO35_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49018]))             /*config reg for pad GPIO35*/
#define IO_MUX_GPIO32_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF4901C]))             /*config reg for pad GPIO32*/
#define IO_MUX_GPIO33_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49020]))             /*config reg for pad GPIO33*/
#define IO_MUX_GPIO25_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49024]))             /*config reg for pad GPIO25*/
#define IO_MUX_GPIO26_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49028]))             /*config reg for pad GPIO26*/
#define IO_MUX_GPIO27_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF4902C]))             /*config reg for pad GPIO27*/
#define IO_MUX_MTMS_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF49030]))             /*config reg for pad MTMS*/
#define IO_MUX_MTDI_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF49034]))             /*config reg for pad MTDI*/
#define IO_MUX_MTCK_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF49038]))             /*config reg for pad MTCK*/
#define IO_MUX_MTDO_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF4903C]))             /*config reg for pad MTDO*/
#define IO_MUX_GPIO2_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF49040]))             /*config reg for pad GPIO2*/
#define IO_MUX_GPIO0_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF49044]))             /*config reg for pad GPIO0*/
#define IO_MUX_GPIO4_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF49048]))             /*config reg for pad GPIO4*/
#define IO_MUX_GPIO16_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF4904C]))             /*config reg for pad GPIO16*/
#define IO_MUX_GPIO17_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49050]))             /*config reg for pad GPIO17*/
#define IO_MUX_SD_DATA2_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF49054]))             /*config reg for pad SD_DATA2*/
#define IO_MUX_SD_DATA3_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF49058]))             /*config reg for pad SD_DATA3*/
#define IO_MUX_SD_CMD_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF4905C]))             /*config reg for pad SD_CMD*/
#define IO_MUX_SD_CLK_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49060]))             /*config reg for pad SD_CLK*/
#define IO_MUX_SD_DATA0_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF49064]))             /*config reg for pad SD_DATA0*/
#define IO_MUX_SD_DATA1_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF49068]))             /*config reg for pad SD_DATA1*/
#define IO_MUX_GPIO5_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF4906C]))             /*config reg for pad GPIO5*/
#define IO_MUX_GPIO18_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49070]))             /*config reg for pad GPIO18*/
#define IO_MUX_GPIO19_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49074]))             /*config reg for pad GPIO19*/
#define IO_MUX_GPIO20_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49078]))             /*config reg for pad GPIO20*/
#define IO_MUX_GPIO21_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF4907C]))             /*config reg for pad GPIO21*/
#define IO_MUX_GPIO22_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF49080]))             /*config reg for pad GPIO22*/
#define IO_MUX_U0RXD_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF49084]))             /*config reg for pad U0RXD*/
/***********************************************************************/
/*
 * RTC IO MUX registers
 *
 * real time control IO mux registers
 */

#define RTCIO_RTC_GPIO_OUT_REG               (*(vuint32 *)(&__IPSBAR[0x3FF48400]))             /*RTC GPIO output register*/
#define RTCIO_TC_GPIO_OUT_W1TS_REG           (*(vuint32 *)(&__IPSBAR[0x3FF48404]))             /*RTC GPIO output bit set register*/
#define RTCIO_RTC_GPIO_OUT_W1TC_REG          (*(vuint32 *)(&__IPSBAR[0x3FF48408]))             /*RTC GPIO output bit clear register*/
#define RTCIO_RTC_GPIO_ENABLE_REG            (*(vuint32 *)(&__IPSBAR[0x3FF4840C]))             /*RTC GPIO enable register*/
#define RTCIO_RTC_GPIO_ENABLE_W1TS_REG       (*(vuint32 *)(&__IPSBAR[0x3FF48410]))             /*RTC GPIO output enable bit set register*/
#define RTCIO_RTC_GPIO_ENABLE_W1TC_REG       (*(vuint32 *)(&__IPSBAR[0x3FF48414]))             /*RTC GPIO output enable bit clear register*/
#define RTCIO_RTC_GPIO_STATUS_REG            (*(vuint32 *)(&__IPSBAR[0x3FF48418]))             /*RTC GPIO interrupt status register*/
#define RTCIO_RTC_GPIO_STATUS_W1TS_REG       (*(vuint32 *)(&__IPSBAR[0x3FF4841C]))             /*RTC GPIO interrupt status bit set register*/
#define RTCIO_RTC_GPIO_STATUS_W1TC_REG       (*(vuint32 *)(&__IPSBAR[0x3FF48420]))             /*RTC GPIO interrupt status bit clear register*/
#define RTCIO_RTC_GPIO_IN_REG                (*(vuint32 *)(&__IPSBAR[0x3FF48424]))             /*RTC GPIO input register*/

#define RTCIO_RTC_GPIO_PIN0_REG              (*(vuint32 *)(&__IPSBAR[0x3FF48428]))             /*RTC configuration for pin 0*/
#define RTCIO_RTC_GPIO_PIN1_REG              (*(vuint32 *)(&__IPSBAR[0x3FF4842C]))             /*RTC configuration for pin 1*/
#define RTCIO_RTC_GPIO_PIN2_REG              (*(vuint32 *)(&__IPSBAR[0x3FF48430]))             /*RTC configuration for pin 2*/
#define RTCIO_RTC_GPIO_PIN3_REG              (*(vuint32 *)(&__IPSBAR[0x3FF48434]))             /*RTC configuration for pin 3*/
#define RTCIO_RTC_GPIO_PIN4_REG              (*(vuint32 *)(&__IPSBAR[0x3FF48438]))             /*RTC configuration for pin 4*/
#define RTCIO_RTC_GPIO_PIN5_REG              (*(vuint32 *)(&__IPSBAR[0x3FF4843C]))             /*RTC configuration for pin 5*/
#define RTCIO_RTC_GPIO_PIN6_REG              (*(vuint32 *)(&__IPSBAR[0x3FF48440]))             /*RTC configuration for pin 6*/
#define RTCIO_RTC_GPIO_PIN7_REG              (*(vuint32 *)(&__IPSBAR[0x3FF48444]))             /*RTC configuration for pin 7*/
#define RTCIO_RTC_GPIO_PIN8_REG              (*(vuint32 *)(&__IPSBAR[0x3FF48448]))             /*RTC configuration for pin 8*/
#define RTCIO_RTC_GPIO_PIN9_REG              (*(vuint32 *)(&__IPSBAR[0x3FF4844C]))             /*RTC configuration for pin 9*/
#define RTCIO_RTC_GPIO_PIN10_REG             (*(vuint32 *)(&__IPSBAR[0x3FF48450]))             /*RTC configuration for pin 10*/
#define RTCIO_RTC_GPIO_PIN11_REG             (*(vuint32 *)(&__IPSBAR[0x3FF48454]))             /*RTC configuration for pin 11*/
#define RTCIO_RTC_GPIO_PIN12_REG             (*(vuint32 *)(&__IPSBAR[0x3FF48458]))             /*RTC configuration for pin 12*/
#define RTCIO_RTC_GPIO_PIN13_REG             (*(vuint32 *)(&__IPSBAR[0x3FF4845C]))             /*RTC configuration for pin 13*/
#define RTCIO_RTC_GPIO_PIN14_REG             (*(vuint32 *)(&__IPSBAR[0x3FF48460]))             /*RTC configuration for pin 14*/
#define RTCIO_RTC_GPIO_PIN15_REG             (*(vuint32 *)(&__IPSBAR[0x3FF48464]))             /*RTC configuration for pin 15*/
#define RTCIO_RTC_GPIO_PIN16_REG             (*(vuint32 *)(&__IPSBAR[0x3FF48468]))             /*RTC configuration for pin 16*/
#define RTCIO_RTC_GPIO_PIN17_REG             (*(vuint32 *)(&__IPSBAR[0x3FF4846C]))             /*RTC configuration for pin 17*/

#define RTCIO_DIG_PAD_HOLD_REG               (*(vuint32 *)(&__IPSBAR[0x3FF48474]))             /*RTC GPIO hold register*/
#define RTCIO_SENSOR_PADS_REG                (*(vuint32 *)(&__IPSBAR[0x3FF4847C]))             /*RTC sensor pads config register*/
#define RTCIO_ADC_PAD_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF48480]))             /*RTC ADC config register*/
#define RTCIO_PAD_DAC1_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF48484]))             /*RTC DAC1 config register*/
#define RTCIO_PAD_DAC2_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF48488]))             /*RTC DAC2 config register*/
#define RTCIO_XTAL_32K_PAD_REG               (*(vuint32 *)(&__IPSBAR[0x3FF4848C]))             /*32 KHz crystal pads config reg*/
#define RTCIO_TOUCH_CFG_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF48490]))             /*RTC touch sensor config register*/

#define RTCIO_TOUCH_PAD0_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF48494]))             /*RTC touch sensor pad 0 config register*/
#define RTCIO_TOUCH_PAD1_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF48498]))             /*RTC touch sensor pad 1 config register*/
#define RTCIO_TOUCH_PAD2_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF4849C]))             /*RTC touch sensor pad 2 config register*/
#define RTCIO_TOUCH_PAD3_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF484A0]))             /*RTC touch sensor pad 3 config register*/
#define RTCIO_TOUCH_PAD4_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF484A4]))             /*RTC touch sensor pad 4 config register*/
#define RTCIO_TOUCH_PAD5_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF484A8]))             /*RTC touch sensor pad 5 config register*/
#define RTCIO_TOUCH_PAD6_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF484AC]))             /*RTC touch sensor pad 6 config register*/
#define RTCIO_TOUCH_PAD7_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF484B0]))             /*RTC touch sensor pad 7 config register*/
#define RTCIO_TOUCH_PAD8_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF484B4]))             /*RTC touch sensor pad 8 config register*/
#define RTCIO_TOUCH_PAD9_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF484B8]))             /*RTC touch sensor pad 9 config register*/

#define RTCIO_EXT_WAKEUP0_REG                (*(vuint32 *)(&__IPSBAR[0x3FF484BC]))             /*RTC external wakeup config register*/
#define RTCIO_XTL_EXT_CTR_REG                (*(vuint32 *)(&__IPSBAR[0x3FF484C0]))             /*Crystal power down enable GPIO source*/
#define RTCIO_SAR_I2C_IO_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF484C4]))             /*RTC I2C pad selection*/

#define RTCIO_TOUCH_PADn_REG(n)              (*(vuint32 *)(&__IPSBAR[0x3FF48494 + (n * 4)]))   /*RTC touch sensor pad n config register*/
#define RTCIO_RTC_GPIO_PINn_REG(n)           (*(vuint32 *)(&__IPSBAR[0x3FF48428 + (n * 4)]))   /*RTC configuration for pin n*/
/***********************************************************************/
/*
 * DPORT registers
 *
 * Configuration clocks, system, emmory and interrupts
 */

#define DPORT_PRO_BOOT_REMAP_CTRL_REG        (*(vuint32 *)(&__IPSBAR[0x3FF00000]))              /*remap mode for PRO_CPU*/
#define DPORT_APP_CPU_REMAP_CTRL_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00004]))              /*remap mode for APP_CPU*/
#define DPORT_CACHE_MUX_MODE_REG             (*(vuint32 *)(&__IPSBAR[0x3FF0007C]))              /*the mode of the two caches sharing memory*/

#define DPORT_CPU_PER_CONF_REG               (*(vuint32 *)(&__IPSBAR[0x3FF0003C]))              /*Selects CPU clock*/

#define DPORT_CPU_INTR_FROM_CPU_0_REG        (*(vuint32 *)(&__IPSBAR[0x3FF000DC]))              /*interrupt 0 in both CPUs*/
#define DPORT_CPU_INTR_FROM_CPU_1_REG        (*(vuint32 *)(&__IPSBAR[0x3FF000E0]))              /*interrupt 1 in both CPUs*/
#define DPORT_CPU_INTR_FROM_CPU_2_REG        (*(vuint32 *)(&__IPSBAR[0x3FF000E4]))              /*interrupt 2 in both CPUs*/
#define DPORT_CPU_INTR_FROM_CPU_3_REG        (*(vuint32 *)(&__IPSBAR[0x3FF000E8]))              /*interrupt 3 in both CPUs*/
#define DPORT_PRO_INTR_STATUS_REG_0_REG      (*(vuint32 *)(&__IPSBAR[0x3FF000EC]))              /*PRO_CPU interrupt status 0*/
#define DPORT_PRO_INTR_STATUS_REG_1_REG      (*(vuint32 *)(&__IPSBAR[0x3FF000F0]))              /*PRO_CPU interrupt status 1*/
#define DPORT_PRO_INTR_STATUS_REG_2_REG      (*(vuint32 *)(&__IPSBAR[0x3FF000F4]))              /*PRO_CPU interrupt status 2*/
#define DPORT_APP_INTR_STATUS_REG_0_REG      (*(vuint32 *)(&__IPSBAR[0x3FF000F8]))              /*APP_CPU interrupt status 0*/
#define DPORT_APP_INTR_STATUS_REG_1_REG      (*(vuint32 *)(&__IPSBAR[0x3FF000FC]))              /*APP_CPU interrupt status 1*/
#define DPORT_APP_INTR_STATUS_REG_2_REG      (*(vuint32 *)(&__IPSBAR[0x3FF00100]))              /*APP_CPU interrupt status 2*/

#define DPORT_PRO_MAC_INTR_STATUS_REG        (*(vuint32 *)(&__IPSBAR[0x3FF00104]))              /*PRO_CPU MAC interrupt status*/
#define DPORT_PRO_MAC_NMI_MAP_REG            (*(vuint32 *)(&__IPSBAR[0x3FF00108]))              /*MAC NMI interrupt map*/
#define DPORT_PRO_MAC_BB_INT_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF0010C]))              /*MAC BB interrupt map*/
#define DPORT_PRO_BT_MAC_INT_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00110]))              /*BT MAC interrupt map*/
#define DPORT_PRO_BT_BB_INT_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00114]))              /*BT BB interrupt map*/
#define DPORT_PRO_BT_BB_NMI_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00118]))              /*BT BB NMI interrupt map*/
#define DPORT_PRO_RWBT_IRQ_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF0011C]))              /*RWBT interrupt map*/
#define DPORT_PRO_RWBLE_IRQ_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00120]))              /*RWBLE interrupt map*/
#define DPORT_PRO_RWBT_NMI_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF00124]))              /*RWBT NMI interrupt map*/
#define DPORT_PRO_RWBLE_NMI_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00128]))              /*RWBLE NMI interrupt map*/
#define DPORT_PRO_SLC0_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF0012C]))              /*SLC0 interrupt map*/
#define DPORT_PRO_SLC1_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00130]))              /*SLC1 interrupt map*/
#define DPORT_PRO_UHCI0_INTR_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00134]))              /*UHCI0 interrupt map*/
#define DPORT_PRO_UHCI1_INTR_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00138]))              /*UHCI1 interrupt map*/
#define DPORT_PRO_TG_T0_LEVEL_INT_MAP_REG    (*(vuint32 *)(&__IPSBAR[0x3FF0013C]))              /*T0 level interrupt map*/
#define DPORT_PRO_TG_T1_LEVEL_INT_MAP_REG    (*(vuint32 *)(&__IPSBAR[0x3FF00140]))              /*T1 level interrupt map*/
#define DPORT_PRO_TG_WDT_LEVEL_INT_MAP_REG   (*(vuint32 *)(&__IPSBAR[0x3FF00144]))              /*WDT level interrupt map*/
#define DPORT_PRO_TG_LACT_LEVEL_INT_MAP_REG  (*(vuint32 *)(&__IPSBAR[0x3FF00148]))              /*LACT level interrupt map*/
#define DPORT_PRO_TG1_T0_LEVEL_INT_MAP_REG   (*(vuint32 *)(&__IPSBAR[0x3FF0014C]))              /*T0 level interrupt map*/
#define DPORT_PRO_TG1_T1_LEVEL_INT_MAP_REG   (*(vuint32 *)(&__IPSBAR[0x3FF00150]))              /*T1 level interrupt map*/
#define DPORT_PRO_TG1_WDT_LEVEL_INT_MAP_REG  (*(vuint32 *)(&__IPSBAR[0x3FF00154]))              /*WDT level interrupt map*/
#define DPORT_PRO_TG1_LACT_LEVEL_INT_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF00158]))              /*LACT level interrupt map*/
#define DPORT_PRO_GPIO_INTERRUPT_MAP_REG     (*(vuint32 *)(&__IPSBAR[0x3FF0015C]))              /*GPIO interrupt map*/
#define DPORT_PRO_GPIO_INTERRUPT_NMI_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF00160]))              /*GPIO NMI interrupt map*/
#define DPORT_PRO_CPU_INTR_FROM_CPU_0_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF00164]))            /*CPU interrupt 0 map*/
#define DPORT_PRO_CPU_INTR_FROM_CPU_1_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF00168]))            /*CPU interrupt 1 map*/
#define DPORT_PRO_CPU_INTR_FROM_CPU_2_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF0016C]))            /*CPU interrupt 2 map*/
#define DPORT_PRO_CPU_INTR_FROM_CPU_3_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF00170]))            /*CPU interrupt 3 map*/
#define DPORT_PRO_SPI_INTR_0_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00174]))              /*SPI interrupt 0 map*/
#define DPORT_PRO_SPI_INTR_1_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00178]))              /*SPI interrupt 1 map*/
#define DPORT_PRO_SPI_INTR_2_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF0017C]))              /*SPI interrupt 2 map*/
#define DPORT_PRO_SPI_INTR_3_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00180]))              /*SPI interrupt 3 map*/
#define DPORT_PRO_I2S0_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00184]))              /*I2S0 interrupt map*/
#define DPORT_PRO_I2S1_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00188]))              /*I2S1 interrupt map*/
#define DPORT_PRO_UART_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF0018C]))              /*UART interrupt map*/
#define DPORT_PRO_UART1_INTR_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00190]))              /*UART1 interrupt map*/
#define DPORT_PRO_UART2_INTR_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00194]))              /*UART2 interrupt map*/
#define DPORT_PRO_SDIO_HOST_INTERRUPT_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF00198]))            /*SDIO host interrupt map*/
#define DPORT_PRO_EMAC_INT_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF0019C]))              /*EMAC interrupt map*/
#define DPORT_PRO_PWM0_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF001A0]))              /*PWM0 interrupt map*/
#define DPORT_PRO_PWM1_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF001A4]))              /*PWM1 interrupt map*/
#define DPORT_PRO_LEDC_INT_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF001B0]))              /*LEDC interrupt map*/
#define DPORT_PRO_EFUSE_INT_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF001B4]))              /*EFUSE interrupt map*/
#define DPORT_PRO_TWAI_INT_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF001B8]))              /*TWAI interrupt map*/
#define DPORT_RTC_CORE_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF001BC]))              /*RTC core interrupt map*/
#define DPORT_PRO_RMT_INTR_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF001C0]))              /*RMT interrupt map*/
#define DPORT_PRO_PCNT_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF001C4]))              /*PCNT interrupt map*/
#define DPORT_PRO_I2C_EXT0_INTR_MAP_REG      (*(vuint32 *)(&__IPSBAR[0x3FF001C8]))              /*I2C_EXT0 interrupt map*/
#define DPORT_PRO_I2C_EXT1_INTR_MAP_REG      (*(vuint32 *)(&__IPSBAR[0x3FF001CC]))              /*I2C_EXT1 interrupt map*/
#define DPORT_PRO_RSA_INTR_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF001D0]))              /*RSA interrupt map*/
#define DPORT_PRO_SPI1_DMA_INT_MAP_REG       (*(vuint32 *)(&__IPSBAR[0x3FF001D4]))              /*SPI1 DMA interrupt map*/
#define DPORT_PRO_SPI2_DMA_INT_MAP_REG       (*(vuint32 *)(&__IPSBAR[0x3FF001D8]))              /*SPI2 DMA interrupt map*/
#define DPORT_PRO_SPI3_DMA_INT_MAP_REG       (*(vuint32 *)(&__IPSBAR[0x3FF001DC]))              /*SPI3 DMA interrupt map*/
#define DPORT_PRO_WDG_INT_MAP_REG            (*(vuint32 *)(&__IPSBAR[0x3FF001E0]))              /*WDG interrupt map*/
#define DPORT_PRO_TIMER_INT1_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF001E4]))              /*TIMER 1 interrupt map*/
#define DPORT_PRO_TIMER_INT2_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF001E8]))              /*TIMER 2 interrupt map*/
#define DPORT_PRO_TG_T0_EDGE_INT_MAP_REG     (*(vuint32 *)(&__IPSBAR[0x3FF001EC]))              /*T0 edge interrupt map*/
#define DPORT_PRO_TG_T1_EDGE_INT_MAP_REG     (*(vuint32 *)(&__IPSBAR[0x3FF001F0]))              /*T1 edge interrupt map*/
#define DPORT_PRO_TG_WDT_EDGE_INT_MAP_REG    (*(vuint32 *)(&__IPSBAR[0x3FF001F4]))              /*WDT edge interrupt map*/
#define DPORT_PRO_TG_LACT_EDGE_INT_MAP_REG   (*(vuint32 *)(&__IPSBAR[0x3FF001F8]))              /*LACT edge interrupt map*/
#define DPORT_PRO_TG1_T0_EDGE_INT_MAP_REG    (*(vuint32 *)(&__IPSBAR[0x3FF001FC]))              /*T0 edge interrupt map*/
#define DPORT_PRO_TG1_T1_EDGE_INT_MAP_REG    (*(vuint32 *)(&__IPSBAR[0x3FF00200]))              /*T1 edge interrupt map*/
#define DPORT_PRO_TG1_WDT_EDGE_INT_MAP_REG   (*(vuint32 *)(&__IPSBAR[0x3FF00204]))              /*WDT edge interrupt map*/
#define DPORT_PRO_TG1_LACT_EDGE_INT_MAP_REG  (*(vuint32 *)(&__IPSBAR[0x3FF00208]))              /*LACT edge interrupt map*/
#define DPORT_PRO_MMU_IA_INT_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF0020C]))              /*MMU IA interrupt map*/
#define DPORT_PRO_MPU_IA_INT_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00210]))              /*MPU IA interrupt map*/
#define DPORT_PRO_CACHE_IA_INT_MAP_REG       (*(vuint32 *)(&__IPSBAR[0x3FF00214]))              /*CACHE IA interrupt map*/
#define DPORT_APP_MAC_INTR_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF00218]))              /*APP_CPU MAC interrupt map*/
#define DPORT_APP_MAC_NMI_MAP_REG            (*(vuint32 *)(&__IPSBAR[0x3FF0021C]))              /*MAC NMI interrupt map*/
#define DPORT_APP_BB_INT_MAP_REG             (*(vuint32 *)(&__IPSBAR[0x3FF00220]))              /*BB interrupt map*/
#define DPORT_APP_BT_MAC_INT_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00224]))              /*BT MAC interrupt map*/
#define DPORT_APP_BT_BB_INT_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00228]))              /*BT BB interrupt map*/
#define DPORT_APP_BT_BB_NMI_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF0022C]))              /*BT BB NMI interrupt map*/
#define DPORT_APP_RWBT_IRQ_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF00230]))              /*RWBT interrupt map*/
#define DPORT_APP_RWBLE_IRQ_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00234]))              /*RWBLE interrupt map*/
#define DPORT_APP_RWBT_NMI_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF00238]))              /*RWBT NMI interrupt map*/
#define DPORT_APP_RWBLE_NMI_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF0023C]))              /*RWBLE NMI interrupt map*/
#define DPORT_APP_SLC0_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00240]))              /*SLC0 interrupt map*/
#define DPORT_APP_SLC1_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00244]))              /*SLC1 interrupt map*/
#define DPORT_APP_UHCI0_INTR_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00248]))              /*UHCI0 interrupt map*/
#define DPORT_APP_UHCI1_INTR_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF0024C]))              /*UHCI1 interrupt map*/
#define DPORT_APP_TG_T0_LEVEL_INT_MAP_REG    (*(vuint32 *)(&__IPSBAR[0x3FF00250]))              /*T0 level interrupt map*/
#define DPORT_APP_TG_T1_LEVEL_INT_MAP_REG    (*(vuint32 *)(&__IPSBAR[0x3FF00254]))              /*T1 level interrupt map*/
#define DPORT_APP_TG_WDT_LEVEL_INT_MAP_REG   (*(vuint32 *)(&__IPSBAR[0x3FF00258]))              /*WDT level interrupt map*/
#define DPORT_APP_TG_LACT_LEVEL_INT_MAP_REG  (*(vuint32 *)(&__IPSBAR[0x3FF0025C]))              /*LACT level interrupt map*/
#define DPORT_APP_TG1_T0_LEVEL_INT_MAP_REG   (*(vuint32 *)(&__IPSBAR[0x3FF00260]))              /*T0 level interrupt map*/
#define DPORT_APP_TG1_T1_LEVEL_INT_MAP_REG   (*(vuint32 *)(&__IPSBAR[0x3FF00264]))              /*T1 level interrupt map*/
#define DPORT_APP_TG1_WDT_LEVEL_INT_MAP_REG  (*(vuint32 *)(&__IPSBAR[0x3FF00268]))              /*WDT level interrupt map*/
#define DPORT_APP_TG1_LACT_LEVEL_INT_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF0026C]))              /*LACT level interrupt map*/
#define DPORT_APP_GPIO_INTERRUPT_MAP_REG     (*(vuint32 *)(&__IPSBAR[0x3FF00270]))              /*GPIO interrupt map*/
#define DPORT_APP_GPIO_INTERRUPT_NMI_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF00274]))              /*GPIO NMI interrupt map*/
#define DPORT_APP_CPU_INTR_FROM_CPU_0_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF00278]))            /*CPU interrupt 0 map*/
#define DPORT_APP_CPU_INTR_FROM_CPU_1_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF0027C]))            /*CPU interrupt 1 map*/
#define DPORT_APP_CPU_INTR_FROM_CPU_2_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF00280]))            /*CPU interrupt 2 map*/
#define DPORT_APP_CPU_INTR_FROM_CPU_3_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF00284]))            /*CPU interrupt 3 map*/
#define DPORT_APP_SPI_INTR_0_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00288]))              /*SPI interrupt 0 map*/
#define DPORT_APP_SPI_INTR_1_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF0028C]))              /*SPI interrupt 1 map*/
#define DPORT_APP_SPI_INTR_2_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00290]))              /*SPI interrupt 2 map*/
#define DPORT_APP_SPI_INTR_3_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00294]))              /*SPI interrupt 3 map*/
#define DPORT_APP_I2S0_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00298]))              /*I2S0 interrupt map*/
#define DPORT_APP_I2S1_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF0029C]))              /*I2S1 interrupt map*/
#define DPORT_APP_UART_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF002A0]))              /*UART interrupt map*/
#define DPORT_APP_UART1_INTR_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF002A4]))              /*UART1 interrupt map*/
#define DPORT_APP_UART2_INTR_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF002A8]))              /*UART2 interrupt map*/
#define DPORT_APP_SDIO_HOST_INTERRUPT_MAP_REG (*(vuint32 *)(&__IPSBAR[0x3FF002AC]))            /*SDIO host interrupt map*/
#define DPORT_APP_EMAC_INT_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF002B0]))              /*EMAC interrupt map*/
#define DPORT_APP_PWM0_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF002B4]))              /*PWM0 interrupt map*/
#define DPORT_APP_PWM1_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF002B8]))              /*PWM1 interrupt map*/
#define DPORT_APP_LEDC_INT_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF002C4]))              /*LEDC interrupt map*/
#define DPORT_APP_EFUSE_INT_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF002C8]))              /*EFUSE interrupt map*/
#define DPORT_APP_TWAI_INT_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF002CC]))              /*TWAI interrupt map*/
#define DPORT_RTC_CORE_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF002D0]))              /*RTC core interrupt map*/
#define DPORT_APP_RMT_INTR_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF002D4]))              /*RMT interrupt map*/
#define DPORT_APP_PCNT_INTR_MAP_REG          (*(vuint32 *)(&__IPSBAR[0x3FF002D8]))              /*PCNT interrupt map*/
#define DPORT_APP_I2C_EXT0_INTR_MAP_REG      (*(vuint32 *)(&__IPSBAR[0x3FF002DC]))              /*I2C_EXT0 interrupt map*/
#define DPORT_APP_I2C_EXT1_INTR_MAP_REG      (*(vuint32 *)(&__IPSBAR[0x3FF002E0]))              /*I2C_EXT1 interrupt map*/
#define DPORT_APP_RSA_INTR_MAP_REG           (*(vuint32 *)(&__IPSBAR[0x3FF002E4]))              /*RSA interrupt map*/
#define DPORT_APP_SPI1_DMA_INT_MAP_REG       (*(vuint32 *)(&__IPSBAR[0x3FF002E8]))              /*SPI1 DMA interrupt map*/
#define DPORT_APP_SPI2_DMA_INT_MAP_REG       (*(vuint32 *)(&__IPSBAR[0x3FF002EC]))              /*SPI2 DMA interrupt map*/
#define DPORT_APP_SPI3_DMA_INT_MAP_REG       (*(vuint32 *)(&__IPSBAR[0x3FF002F0]))              /*SPI3 DMA interrupt map*/
#define DPORT_APP_WDG_INT_MAP_REG            (*(vuint32 *)(&__IPSBAR[0x3FF002F4]))              /*WDG interrupt map*/
#define DPORT_APP_TIMER_INT1_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF002F8]))              /*TIMER 1 interrupt map*/
#define DPORT_APP_TIMER_INT2_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF002FC]))              /*TIMER 2 interrupt map*/
#define DPORT_APP_TG_T0_EDGE_INT_MAP_REG     (*(vuint32 *)(&__IPSBAR[0x3FF00300]))              /*T0 edge interrupt map*/
#define DPORT_APP_TG_T1_EDGE_INT_MAP_REG     (*(vuint32 *)(&__IPSBAR[0x3FF00304]))              /*T1 edge interrupt map*/
#define DPORT_APP_TG_WDT_EDGE_INT_MAP_REG    (*(vuint32 *)(&__IPSBAR[0x3FF00308]))              /*WDT edge interrupt map*/
#define DPORT_APP_TG_LACT_EDGE_INT_MAP_REG   (*(vuint32 *)(&__IPSBAR[0x3FF0030C]))              /*LACT edge interrupt map*/
#define DPORT_APP_TG1_T0_EDGE_INT_MAP_REG    (*(vuint32 *)(&__IPSBAR[0x3FF00310]))              /*T0 edge interrupt map*/
#define DPORT_APP_TG1_T1_EDGE_INT_MAP_REG    (*(vuint32 *)(&__IPSBAR[0x3FF00314]))              /*T1 edge interrupt map*/
#define DPORT_APP_TG1_WDT_EDGE_INT_MAP_REG   (*(vuint32 *)(&__IPSBAR[0x3FF00318]))              /*WDT edge interrupt map*/
#define DPORT_APP_TG1_LACT_EDGE_INT_MAP_REG  (*(vuint32 *)(&__IPSBAR[0x3FF0031C]))              /*LACT edge interrupt map*/
#define DPORT_APP_MMU_IA_INT_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00320]))              /*MMU IA interrupt map*/
#define DPORT_APP_MPU_IA_INT_MAP_REG         (*(vuint32 *)(&__IPSBAR[0x3FF00324]))              /*MPU IA interrupt map*/
#define DPORT_APP_CACHE_IA_INT_MAP_REG       (*(vuint32 *)(&__IPSBAR[0x3FF00328]))              /*CACHE IA interrupt map*/

#define DPORT_SPI_DMA_CHAN_SEL_REG           (*(vuint32 *)(&__IPSBAR[0x3FF005A8]))              /*Selects DMA channel for SPI1, SPI2 and SPI3*/

#define DPORT_PRO_CACHE_CTRL_REG             (*(vuint32 *)(&__IPSBAR[0x3FF00040]))              /*Determines the virtual addr modes of the external SRAM*/
#define DPORT_PRO_CACHE_CTRL1_REG            (*(vuint32 *)(&__IPSBAR[0x3FF00044]))              /*PRO cache MMU config*/
#define DPORT_APP_CACHE_CTRL_REG             (*(vuint32 *)(&__IPSBAR[0x3FF00058]))              /*Determines the virtual addr modes of the external SRAM*/
#define DPORT_APP_CACHE_CTRL1_REG            (*(vuint32 *)(&__IPSBAR[0x3FF0005C]))              /*APP cache MMU config*/
#define DPORT_IMMU_PAGE_MODE_REG             (*(vuint32 *)(&__IPSBAR[0x3FF00080]))              /*page size in the MMU for the internal SRAM 0*/
#define DPORT_DMMU_PAGE_MODE_REG             (*(vuint32 *)(&__IPSBAR[0x3FF00084]))              /*page size in the MMU for the external SRAM 2*/
#define DPORT_AHB_MPU_TABLE_0_REG            (*(vuint32 *)(&__IPSBAR[0x3FF000B4]))              /*MPU for config DMA*/
#define DPORT_AHB_MPU_TABLE_1_REG            (*(vuint32 *)(&__IPSBAR[0x3FF000B8]))              /*MPU for config DMA*/
#define DPORT_AHBLITE_MPU_TABLE_UART_REG     (*(vuint32 *)(&__IPSBAR[0x3FF0032C]))              /*MPU for config UART*/
#define DPORT_AHBLITE_MPU_TABLE_SPI1_REG     (*(vuint32 *)(&__IPSBAR[0x3FF00330]))              /*MPU for config SPI1*/
#define DPORT_AHBLITE_MPU_TABLE_SPI0_REG     (*(vuint32 *)(&__IPSBAR[0x3FF00334]))              /*MPU for config SPI0*/
#define DPORT_AHBLITE_MPU_TABLE_GPIO_REG     (*(vuint32 *)(&__IPSBAR[0x3FF00338]))              /*MPU for config GPIO*/
#define DPORT_AHBLITE_MPU_TABLE_RTC_REG      (*(vuint32 *)(&__IPSBAR[0x3FF00348]))              /*MPU for config RTC*/
#define DPORT_AHBLITE_MPU_TABLE_IO_MUX_REG   (*(vuint32 *)(&__IPSBAR[0x3FF0034C]))              /*MPU for config IO_MUX*/
#define DPORT_AHBLITE_MPU_TABLE_HINF_REG     (*(vuint32 *)(&__IPSBAR[0x3FF00354]))              /*MPU for config HINF*/
#define DPORT_AHBLITE_MPU_TABLE_UHCI1_REG    (*(vuint32 *)(&__IPSBAR[0x3FF00358]))              /*MPU for config UHCI1*/
#define DPORT_AHBLITE_MPU_TABLE_I2S0_REG     (*(vuint32 *)(&__IPSBAR[0x3FF00364]))              /*MPU for config I2S0*/
#define DPORT_AHBLITE_MPU_TABLE_UART1_REG    (*(vuint32 *)(&__IPSBAR[0x3FF00368]))              /*MPU for config UART1*/
#define DPORT_AHBLITE_MPU_TABLE_I2C_EXT0_REG (*(vuint32 *)(&__IPSBAR[0x3FF00374]))              /*MPU for config I2C_EXT0*/
#define DPORT_AHBLITE_MPU_TABLE_UHCI0_REG    (*(vuint32 *)(&__IPSBAR[0x3FF00378]))              /*MPU for config UHCI0*/
#define DPORT_AHBLITE_MPU_TABLE_SLCHOST_REG  (*(vuint32 *)(&__IPSBAR[0x3FF0037C]))              /*MPU for config SLCHOST*/
#define DPORT_AHBLITE_MPU_TABLE_RMT_REG      (*(vuint32 *)(&__IPSBAR[0x3FF00380]))              /*MPU for config RMT*/
#define DPORT_AHBLITE_MPU_TABLE_PCNT_REG     (*(vuint32 *)(&__IPSBAR[0x3FF00384]))              /*MPU for config PCNT*/
#define DPORT_AHBLITE_MPU_TABLE_SLC_REG      (*(vuint32 *)(&__IPSBAR[0x3FF00388]))              /*MPU for config SLC*/
#define DPORT_AHBLITE_MPU_TABLE_LEDC_REG     (*(vuint32 *)(&__IPSBAR[0x3FF0038C]))              /*MPU for config LEDC*/
#define DPORT_AHBLITE_MPU_TABLE_EFUSE_REG    (*(vuint32 *)(&__IPSBAR[0x3FF00390]))              /*MPU for config EFUSE*/
#define DPORT_AHBLITE_MPU_TABLE_SPI_ENCRYPT_REG (*(vuint32 *)(&__IPSBAR[0x3FF00394]))           /*MPU for config SPI_ENCRYPT*/
#define DPORT_AHBLITE_MPU_TABLE_PWM0_REG     (*(vuint32 *)(&__IPSBAR[0x3FF0039C]))              /*MPU for config PWM0*/
#define DPORT_AHBLITE_MPU_TABLE_TIMERGROUP_REG (*(vuint32 *)(&__IPSBAR[0x3FF003A0]))            /*MPU for config TIMERGROUP*/
#define DPORT_AHBLITE_MPU_TABLE_TIMERGROUP1_REG (*(vuint32 *)(&__IPSBAR[0x3FF003A4]))          /*MPU for config TIMERGROUP1*/
#define DPORT_AHBLITE_MPU_TABLE_SPI2_REG     (*(vuint32 *)(&__IPSBAR[0x3FF003A8]))              /*MPU for config SPI2*/
#define DPORT_AHBLITE_MPU_TABLE_SPI3_REG     (*(vuint32 *)(&__IPSBAR[0x3FF003AC]))              /*MPU for config SPI3*/
#define DPORT_AHBLITE_MPU_TABLE_APB_CTRL_REG (*(vuint32 *)(&__IPSBAR[0x3FF003B0]))              /*MPU for config APB_CTRL*/
#define DPORT_AHBLITE_MPU_TABLE_I2C_EXT1_REG (*(vuint32 *)(&__IPSBAR[0x3FF003B4]))              /*MPU for config I2C_EXT1*/
#define DPORT_AHBLITE_MPU_TABLE_SDIO_HOST_REG (*(vuint32 *)(&__IPSBAR[0x3FF003B8]))            /*MPU for config SDIO_HOST*/
#define DPORT_AHBLITE_MPU_TABLE_EMAC_REG     (*(vuint32 *)(&__IPSBAR[0x3FF003BC]))              /*MPU for config EMAC*/
#define DPORT_AHBLITE_MPU_TABLE_PWM1_REG     (*(vuint32 *)(&__IPSBAR[0x3FF003C4]))              /*MPU for config PWM1*/
#define DPORT_AHBLITE_MPU_TABLE_I2S1_REG     (*(vuint32 *)(&__IPSBAR[0x3FF003C8]))              /*MPU for config I2S1*/
#define DPORT_AHBLITE_MPU_TABLE_UART2_REG    (*(vuint32 *)(&__IPSBAR[0x3FF003CC]))              /*MPU for config UART2*/
#define DPORT_AHBLITE_MPU_TABLE_PWR_REG      (*(vuint32 *)(&__IPSBAR[0x3FF003E4]))              /*MPU for config PWR*/
#define DPORT_IMMU_TABLE0_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00504]))              /*MMU reg 1 for internal SRAM 0*/
#define DPORT_IMMU_TABLE1_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00508]))              /*MMU reg 2 for internal SRAM 0*/
#define DPORT_IMMU_TABLE2_REG                (*(vuint32 *)(&__IPSBAR[0x3FF0050C]))              /*MMU reg 3 for internal SRAM 0*/
#define DPORT_IMMU_TABLE3_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00510]))              /*MMU reg 4 for internal SRAM 0*/
#define DPORT_IMMU_TABLE4_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00514]))              /*MMU reg 5 for internal SRAM 0*/
#define DPORT_IMMU_TABLE5_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00518]))              /*MMU reg 6 for internal SRAM 0*/
#define DPORT_IMMU_TABLE6_REG                (*(vuint32 *)(&__IPSBAR[0x3FF0051C]))              /*MMU reg 7 for internal SRAM 0*/
#define DPORT_IMMU_TABLE7_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00520]))              /*MMU reg 8 for internal SRAM 0*/
#define DPORT_IMMU_TABLE8_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00524]))              /*MMU reg 9 for internal SRAM 0*/
#define DPORT_IMMU_TABLE9_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00528]))              /*MMU reg 10 for internal SRAM 0*/
#define DPORT_IMMU_TABLE10_REG               (*(vuint32 *)(&__IPSBAR[0x3FF0052C]))              /*MMU reg 11 for internal SRAM 0*/
#define DPORT_IMMU_TABLE11_REG               (*(vuint32 *)(&__IPSBAR[0x3FF00530]))              /*MMU reg 12 for internal SRAM 0*/
#define DPORT_IMMU_TABLE12_REG               (*(vuint32 *)(&__IPSBAR[0x3FF00534]))              /*MMU reg 13 for internal SRAM 0*/
#define DPORT_IMMU_TABLE13_REG               (*(vuint32 *)(&__IPSBAR[0x3FF00538]))              /*MMU reg 14 for internal SRAM 0*/
#define DPORT_IMMU_TABLE14_REG               (*(vuint32 *)(&__IPSBAR[0x3FF0053C]))              /*MMU reg 15 for internal SRAM 0*/
#define DPORT_IMMU_TABLE15_REG               (*(vuint32 *)(&__IPSBAR[0x3FF00540]))              /*MMU reg 16 for internal SRAM 0*/
#define DPORT_DMMU_TABLE0_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00544]))              /*MMU reg 1 for external SRAM 2*/
#define DPORT_DMMU_TABLE1_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00548]))              /*MMU reg 2 for external SRAM 2*/
#define DPORT_DMMU_TABLE2_REG                (*(vuint32 *)(&__IPSBAR[0x3FF0054C]))              /*MMU reg 3 for external SRAM 2*/
#define DPORT_DMMU_TABLE3_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00550]))              /*MMU reg 4 for external SRAM 2*/
#define DPORT_DMMU_TABLE4_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00554]))              /*MMU reg 5 for external SRAM 2*/
#define DPORT_DMMU_TABLE5_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00558]))              /*MMU reg 6 for external SRAM 2*/
#define DPORT_DMMU_TABLE6_REG                (*(vuint32 *)(&__IPSBAR[0x3FF0055C]))              /*MMU reg 7 for external SRAM 2*/
#define DPORT_DMMU_TABLE7_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00560]))              /*MMU reg 8 for external SRAM 2*/
#define DPORT_DMMU_TABLE8_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00564]))              /*MMU reg 9 for external SRAM 2*/
#define DPORT_DMMU_TABLE9_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00568]))              /*MMU reg 10 for external SRAM 2*/
#define DPORT_DMMU_TABLE10_REG               (*(vuint32 *)(&__IPSBAR[0x3FF0056C]))              /*MMU reg 11 for external SRAM 2*/
#define DPORT_DMMU_TABLE11_REG               (*(vuint32 *)(&__IPSBAR[0x3FF00570]))              /*MMU reg 12 for external SRAM 2*/
#define DPORT_DMMU_TABLE12_REG               (*(vuint32 *)(&__IPSBAR[0x3FF00574]))              /*MMU reg 13 for external SRAM 2*/
#define DPORT_DMMU_TABLE13_REG               (*(vuint32 *)(&__IPSBAR[0x3FF00578]))              /*MMU reg 14 for external SRAM 2*/
#define DPORT_DMMU_TABLE14_REG               (*(vuint32 *)(&__IPSBAR[0x3FF0057C]))              /*MMU reg 15 for external SRAM 2*/
#define DPORT_DMMU_TABLE15_REG               (*(vuint32 *)(&__IPSBAR[0x3FF00580]))              /*MMU reg 16 for external SRAM 2*/

#define DPORT_APPCPU_CTRL_REG_A_REG          (*(vuint32 *)(&__IPSBAR[0x3FF0002C]))              /*reset for APP_CPU*/
#define DPORT_APPCPU_CTRL_REG_B_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00030]))              /*clock gate for APP_CPU*/
#define DPORT_APPCPU_CTRL_REG_C_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00034]))              /*stall for APP_CPU*/
#define DPORT_APPCPU_CTRL_REG_D_REG          (*(vuint32 *)(&__IPSBAR[0x3FF00038]))              /*boot addr for APP_CPU*/

#define DPORT_PERI_CLK_EN_REG                (*(vuint32 *)(&__IPSBAR[0x3FF0001C]))              /*clock gate for peripherals*/
#define DPORT_PERI_RST_EN_REG                (*(vuint32 *)(&__IPSBAR[0x3FF00020]))              /*reset for peripherals*/
#define DPORT_PERIP_CLK_EN_REG               (*(vuint32 *)(&__IPSBAR[0x3FF000C0]))              /*clock gate for peripherals*/
#define DPORT_PERIP_RST_EN_REG               (*(vuint32 *)(&__IPSBAR[0x3FF000C4]))              /*reset for peripherals*/
#define DPORT_WIFI_CLK_EN_REG                (*(vuint32 *)(&__IPSBAR[0x3FF000CC]))              /*clock gate for WiFi*/
#define DPORT_WIFI_RST_EN_REG                (*(vuint32 *)(&__IPSBAR[0x3FF000D0]))              /*reset for WiFi*/

#define DPORT_CPU_INTR_FROM_CPU_REG(n)       (*(vuint32 *)(&__IPSBAR[0x3FF000DC + (n * 4)]))    /*interrupt n in both CPUs*/
#define DPORT_PRO_CPU_INTR_FROM_CPU_n_MAP_REG(n) (*(vuint32 *)(&__IPSBAR[0x3FF00164 + (n * 4)])) /*CPU interrupt n map*/
#define DPORT_PRO_SPI_INTR_n_MAP_REG(n)      (*(vuint32 *)(&__IPSBAR[0x3FF00174 + (n * 4)]))    /*SPI interrupt n map*/
#define DPORT_IMMU_TABLEn_REG(n)             (*(vuint32 *)(&__IPSBAR[0x3FF00504 + (n * 4)]))    /*MMU reg n for internal SRAM 0*/
#define DPORT_DMMU_TABLEn_REG(n)             (*(vuint32 *)(&__IPSBAR[0x3FF00544 + (n * 4)]))    /*MMU reg n for external SRAM 2*/
/***********************************************************************/
/*
 * SPI registers
 *
 * 
 */

#define SPI0_CTRL_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF43008]))              /*Bit order and QIO/DIO/QOUT/DOUT mode settings*/
#define SPI1_CTRL_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF42008]))              /*Bit order and QIO/DIO/QOUT/DOUT mode settings*/
#define SPI2_CTRL_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF64008]))              /*Bit order and QIO/DIO/QOUT/DOUT mode settings*/
#define SPI3_CTRL_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF65008]))              /*Bit order and QIO/DIO/QOUT/DOUT mode settings*/

#define SPI0_CTRL2_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF43014]))              /*Timing configuration*/
#define SPI1_CTRL2_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF42014]))              /*Timing configuration*/
#define SPI2_CTRL2_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF64014]))              /*Timing configuration*/
#define SPI3_CTRL2_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF65014]))              /*Timing configuration*/

#define SPI0_CLOCK_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF43018]))              /*Clock config*/
#define SPI1_CLOCK_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF42018]))              /*Clock config*/
#define SPI2_CLOCK_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF64018]))              /*Clock config*/
#define SPI3_CLOCK_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF65018]))              /*Clock config*/

#define SPI0_PIN_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF43034]))              /*Polarity and CS config*/
#define SPI1_PIN_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF42034]))              /*Polarity and CS config*/
#define SPI2_PIN_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF64034]))              /*Polarity and CS config*/
#define SPI3_PIN_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF65034]))              /*Polarity and CS config*/

#define SPI0_SLAVE_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF43038]))              /*Slave mode config and interrupt status*/
#define SPI1_SLAVE_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF42038]))              /*Slave mode config and interrupt status*/
#define SPI2_SLAVE_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF64038]))              /*Slave mode config and interrupt status*/
#define SPI3_SLAVE_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF65038]))              /*Slave mode config and interrupt status*/

#define SPI0_SLAVE1_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF4303C]))              /*Slave mode data bit lengths*/
#define SPI1_SLAVE1_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF4203C]))              /*Slave mode data bit lengths*/
#define SPI2_SLAVE1_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF6403C]))              /*Slave mode data bit lengths*/
#define SPI3_SLAVE1_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF6503C]))              /*Slave mode data bit lengths*/

#define SPI0_SLAVE2_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF43040]))              /*Dummy cycle length config*/
#define SPI1_SLAVE2_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF42040]))              /*Dummy cycle length config*/
#define SPI2_SLAVE2_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF64040]))              /*Dummy cycle length config*/
#define SPI3_SLAVE2_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF65040]))              /*Dummy cycle length config*/

#define SPI0_SLV_WR_STATUS_REG               (*(vuint32 *)(&__IPSBAR[0x3FF43030]))              /*Slave status/Part of lower master addr*/
#define SPI1_SLV_WR_STATUS_REG               (*(vuint32 *)(&__IPSBAR[0x3FF42030]))              /*Slave status/Part of lower master addr*/
#define SPI2_SLV_WR_STATUS_REG               (*(vuint32 *)(&__IPSBAR[0x3FF64030]))              /*Slave status/Part of lower master addr*/
#define SPI3_SLV_WR_STATUS_REG               (*(vuint32 *)(&__IPSBAR[0x3FF65030]))              /*Slave status/Part of lower master addr*/

#define SPI0_SLV_WRBUF_DLEN_REG              (*(vuint32 *)(&__IPSBAR[0x3FF43048]))              /*Write-buffer operation length*/
#define SPI1_SLV_WRBUF_DLEN_REG              (*(vuint32 *)(&__IPSBAR[0x3FF42048]))              /*Write-buffer operation length*/
#define SPI2_SLV_WRBUF_DLEN_REG              (*(vuint32 *)(&__IPSBAR[0x3FF64048]))              /*Write-buffer operation length*/
#define SPI3_SLV_WRBUF_DLEN_REG              (*(vuint32 *)(&__IPSBAR[0x3FF65048]))              /*Write-buffer operation length*/

#define SPI0_SLV_RDBUF_DLEN_REG              (*(vuint32 *)(&__IPSBAR[0x3FF4304C]))              /*Read-buffer operation length*/
#define SPI1_SLV_RDBUF_DLEN_REG              (*(vuint32 *)(&__IPSBAR[0x3FF4204C]))              /*Read-buffer operation length*/
#define SPI2_SLV_RDBUF_DLEN_REG              (*(vuint32 *)(&__IPSBAR[0x3FF6404C]))              /*Read-buffer operation length*/
#define SPI3_SLV_RDBUF_DLEN_REG              (*(vuint32 *)(&__IPSBAR[0x3FF6504C]))              /*Read-buffer operation length*/

#define SPI0_SLV_RD_BIT_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF43064]))              /*Read data operation length*/
#define SPI1_SLV_RD_BIT_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF42064]))              /*Read data operation length*/
#define SPI2_SLV_RD_BIT_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF64064]))              /*Read data operation length*/
#define SPI3_SLV_RD_BIT_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF65064]))              /*Read data operation length*/

#define SPI0_CMD_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF43000]))              /*Start user-defined command*/
#define SPI1_CMD_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF42000]))              /*Start user-defined command*/
#define SPI2_CMD_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF64000]))              /*Start user-defined command*/
#define SPI3_CMD_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF65000]))              /*Start user-defined command*/

#define SPI0_ADDR_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF43004]))              /*Addr data*/
#define SPI1_ADDR_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF42004]))              /*Addr data*/
#define SPI2_ADDR_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF64004]))              /*Addr data*/
#define SPI3_ADDR_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF65004]))              /*Addr data*/

#define SPI0_USER_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF4301C]))              /*User defined command config*/
#define SPI1_USER_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF4201C]))              /*User defined command config*/
#define SPI2_USER_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF6401C]))              /*User defined command config*/
#define SPI3_USER_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF6501C]))              /*User defined command config*/

#define SPI0_USER1_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF43020]))              /*Addr and dummy cycle config*/
#define SPI1_USER1_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF42020]))              /*Addr and dummy cycle config*/
#define SPI2_USER1_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF64020]))              /*Addr and dummy cycle config*/
#define SPI3_USER1_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF65020]))              /*Addr and dummy cycle config*/

#define SPI0_USER2_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF43024]))              /*Command length and value config*/
#define SPI1_USER2_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF42024]))              /*Command length and value config*/
#define SPI2_USER2_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF64024]))              /*Command length and value config*/
#define SPI3_USER2_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF65024]))              /*Command length and value config*/

#define SPI0_MOSI_DLEN_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF43028]))              /*Data length config for MOSI*/
#define SPI1_MOSI_DLEN_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF42028]))              /*Data length config for MOSI*/
#define SPI2_MOSI_DLEN_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF64028]))              /*Data length config for MOSI*/
#define SPI3_MOSI_DLEN_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF65028]))              /*Data length config for MOSI*/

#define SPI0_W0_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF43080]))               /*SPI data reg 0*/
#define SPI1_W0_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF42080]))               /*SPI data reg 0*/
#define SPI2_W0_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF64080]))               /*SPI data reg 0*/
#define SPI3_W0_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF65080]))               /*SPI data reg 0*/

#define SPI0_W1_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF43084]))               /*SPI data reg 1*/
#define SPI1_W1_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF42084]))               /*SPI data reg 1*/
#define SPI2_W1_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF64084]))               /*SPI data reg 1*/
#define SPI3_W1_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF65084]))               /*SPI data reg 1*/

#define SPI0_W2_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF43088]))               /*SPI data reg 2*/
#define SPI1_W2_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF42088]))               /*SPI data reg 2*/
#define SPI2_W2_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF64088]))               /*SPI data reg 2*/
#define SPI3_W2_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF65088]))               /*SPI data reg 2*/

#define SPI0_W3_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF4308C]))               /*SPI data reg 3*/
#define SPI1_W3_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF4208C]))               /*SPI data reg 3*/
#define SPI2_W3_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF6408C]))               /*SPI data reg 3*/
#define SPI3_W3_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF6508C]))               /*SPI data reg 3*/

#define SPI0_W4_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF43090]))               /*SPI data reg 4*/
#define SPI1_W4_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF42090]))               /*SPI data reg 4*/
#define SPI2_W4_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF64090]))               /*SPI data reg 4*/
#define SPI3_W4_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF65090]))               /*SPI data reg 4*/

#define SPI0_W5_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF43094]))               /*SPI data reg 5*/
#define SPI1_W5_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF42094]))               /*SPI data reg 5*/
#define SPI2_W5_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF64094]))               /*SPI data reg 5*/
#define SPI3_W5_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF65094]))               /*SPI data reg 5*/

#define SPI0_W6_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF43098]))               /*SPI data reg 6*/
#define SPI1_W6_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF42098]))               /*SPI data reg 6*/
#define SPI2_W6_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF64098]))               /*SPI data reg 6*/
#define SPI3_W6_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF65098]))               /*SPI data reg 6*/

#define SPI0_W7_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF4309C]))               /*SPI data reg 7*/
#define SPI1_W7_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF4209C]))               /*SPI data reg 7*/
#define SPI2_W7_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF6409C]))               /*SPI data reg 7*/
#define SPI3_W7_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF6509C]))               /*SPI data reg 7*/

#define SPI0_W8_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF430A0]))               /*SPI data reg 8*/
#define SPI1_W8_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF420A0]))               /*SPI data reg 8*/
#define SPI2_W8_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF640A0]))               /*SPI data reg 8*/
#define SPI3_W8_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF650A0]))               /*SPI data reg 8*/

#define SPI0_W9_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF430A4]))               /*SPI data reg 9*/
#define SPI1_W9_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF420A4]))               /*SPI data reg 9*/
#define SPI2_W9_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF640A4]))               /*SPI data reg 9*/
#define SPI3_W9_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF650A4]))               /*SPI data reg 9*/

#define SPI0_W10_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF430A8]))               /*SPI data reg 10*/  
#define SPI1_W10_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF420A8]))               /*SPI data reg 10*/
#define SPI2_W10_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF640A8]))               /*SPI data reg 10*/
#define SPI3_W10_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF650A8]))               /*SPI data reg 10*/

#define SPI0_W11_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF430AC]))               /*SPI data reg 11*/
#define SPI1_W11_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF420AC]))               /*SPI data reg 11*/
#define SPI2_W11_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF640AC]))               /*SPI data reg 11*/
#define SPI3_W11_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF650AC]))               /*SPI data reg 11*/

#define SPI0_W12_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF430B0]))               /*SPI data reg 12*/
#define SPI1_W12_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF420B0]))               /*SPI data reg 12*/
#define SPI2_W12_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF640B0]))               /*SPI data reg 12*/
#define SPI3_W12_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF650B0]))               /*SPI data reg 12*/

#define SPI0_W13_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF430B4]))               /*SPI data reg 13*/
#define SPI1_W13_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF420B4]))               /*SPI data reg 13*/
#define SPI2_W13_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF640B4]))               /*SPI data reg 13*/
#define SPI3_W13_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF650B4]))               /*SPI data reg 13*/

#define SPI0_W14_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF430B8]))               /*SPI data reg 14*/
#define SPI1_W14_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF420B8]))               /*SPI data reg 14*/
#define SPI2_W14_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF640B8]))               /*SPI data reg 14*/
#define SPI3_W14_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF650B8]))               /*SPI data reg 14*/

#define SPI0_W15_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF430BC]))               /*SPI data reg 15*/
#define SPI1_W15_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF420BC]))               /*SPI data reg 15*/
#define SPI2_W15_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF640BC]))               /*SPI data reg 15*/
#define SPI3_W15_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF650BC]))               /*SPI data reg 15*/

#define SPI0_DMA_CONF_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF43100]))               /*DMA conf reg*/
#define SPI1_DMA_CONF_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF42100]))               /*DMA conf reg*/
#define SPI2_DMA_CONF_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF64100]))               /*DMA conf reg*/
#define SPI3_DMA_CONF_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF65100]))               /*DMA conf reg*/

#define SPI0_DMA_OUT_LINK_REG                (*(vuint32 *)(&__IPSBAR[0x3FF43104]))               /*DMA outlink reg and config*/
#define SPI1_DMA_OUT_LINK_REG                (*(vuint32 *)(&__IPSBAR[0x3FF42104]))               /*DMA outlink reg and config*/
#define SPI2_DMA_OUT_LINK_REG                (*(vuint32 *)(&__IPSBAR[0x3FF64104]))               /*DMA outlink reg and config*/
#define SPI3_DMA_OUT_LINK_REG                (*(vuint32 *)(&__IPSBAR[0x3FF65104]))               /*DMA outlink reg and config*/

#define SPI0_DMA_IN_LINK_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF43108]))               /*DMA inlink reg and config*/
#define SPI1_DMA_IN_LINK_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF42108]))               /*DMA inlink reg and config*/
#define SPI2_DMA_IN_LINK_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF64108]))               /*DMA inlink reg and config*/
#define SPI3_DMA_IN_LINK_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF65108]))               /*DMA inlink reg and config*/

#define SPI0_DMA_STATUS_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF4310C]))               /*DMA status reg*/
#define SPI1_DMA_STATUS_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF4210C]))               /*DMA status reg*/
#define SPI2_DMA_STATUS_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF6410C]))               /*DMA status reg*/
#define SPI3_DMA_STATUS_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF6510C]))               /*DMA status reg*/

#define SPI0_IN_ERR_EOF_DES_ADDR_REG         (*(vuint32 *)(&__IPSBAR[0x3FF43120]))               /*DMA inlink error and EOF des addr*/
#define SPI1_IN_ERR_EOF_DES_ADDR_REG         (*(vuint32 *)(&__IPSBAR[0x3FF42120]))               /*DMA inlink error and EOF des addr*/
#define SPI2_IN_ERR_EOF_DES_ADDR_REG         (*(vuint32 *)(&__IPSBAR[0x3FF64120]))               /*DMA inlink error and EOF des addr*/
#define SPI3_IN_ERR_EOF_DES_ADDR_REG         (*(vuint32 *)(&__IPSBAR[0x3FF65120]))               /*DMA inlink error and EOF des addr*/

#define SPI0_IN_SUC_EOF_DES_ADDR_REG         (*(vuint32 *)(&__IPSBAR[0x3FF43124]))               /*Addr where EOF occurs*/
#define SPI1_IN_SUC_EOF_DES_ADDR_REG         (*(vuint32 *)(&__IPSBAR[0x3FF42124]))               /*Addr where EOF occurs*/
#define SPI2_IN_SUC_EOF_DES_ADDR_REG         (*(vuint32 *)(&__IPSBAR[0x3FF64124]))               /*Addr where EOF occurs*/
#define SPI3_IN_SUC_EOF_DES_ADDR_REG         (*(vuint32 *)(&__IPSBAR[0x3FF65124]))               /*Addr where EOF occurs*/

#define SPI0_INLINK_DSCR_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF43128]))               /*Current descriptor pointer*/
#define SPI1_INLINK_DSCR_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF42128]))               /*Current descriptor pointer*/
#define SPI2_INLINK_DSCR_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF64128]))               /*Current descriptor pointer*/
#define SPI3_INLINK_DSCR_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF65128]))               /*Current descriptor pointer*/

#define SPI0_INLINK_DSCR_BF0_REG             (*(vuint32 *)(&__IPSBAR[0x3FF4312C]))               /*Next descriptor data ptr*/
#define SPI1_INLINK_DSCR_BF0_REG             (*(vuint32 *)(&__IPSBAR[0x3FF4212C]))               /*Next descriptor data ptr*/
#define SPI2_INLINK_DSCR_BF0_REG             (*(vuint32 *)(&__IPSBAR[0x3FF6412C]))               /*Next descriptor data ptr*/
#define SPI3_INLINK_DSCR_BF0_REG             (*(vuint32 *)(&__IPSBAR[0x3FF6512C]))               /*Next descriptor data ptr*/

#define SPI0_INLINK_DSCR_BF1_REG             (*(vuint32 *)(&__IPSBAR[0x3FF43130]))               /*Current descriptor data ptr*/
#define SPI1_INLINK_DSCR_BF1_REG             (*(vuint32 *)(&__IPSBAR[0x3FF42130]))               /*Current descriptor data ptr*/
#define SPI2_INLINK_DSCR_BF1_REG             (*(vuint32 *)(&__IPSBAR[0x3FF64130]))               /*Current descriptor data ptr*/
#define SPI3_INLINK_DSCR_BF1_REG             (*(vuint32 *)(&__IPSBAR[0x3FF65130]))               /*Current descriptor data ptr*/

#define SPI0_OUT_EOF_BFR_DES_ADDR_REG        (*(vuint32 *)(&__IPSBAR[0x3FF43134]))               /*Relative buffer addr where EOF occurs*/
#define SPI1_OUT_EOF_BFR_DES_ADDR_REG        (*(vuint32 *)(&__IPSBAR[0x3FF42134]))               /*Relative buffer addr where EOF occurs*/
#define SPI2_OUT_EOF_BFR_DES_ADDR_REG        (*(vuint32 *)(&__IPSBAR[0x3FF64134]))               /*Relative buffer addr where EOF occurs*/
#define SPI3_OUT_EOF_BFR_DES_ADDR_REG        (*(vuint32 *)(&__IPSBAR[0x3FF65134]))               /*Relative buffer addr where EOF occurs*/

#define SPI0_OUT_EOF_DES_ADDR_REG            (*(vuint32 *)(&__IPSBAR[0x3FF43138]))               /*Descriptor addr where EOF occurs*/
#define SPI1_OUT_EOF_DES_ADDR_REG            (*(vuint32 *)(&__IPSBAR[0x3FF42138]))               /*Descriptor addr where EOF occurs*/
#define SPI2_OUT_EOF_DES_ADDR_REG            (*(vuint32 *)(&__IPSBAR[0x3FF64138]))               /*Descriptor addr where EOF occurs*/
#define SPI3_OUT_EOF_DES_ADDR_REG            (*(vuint32 *)(&__IPSBAR[0x3FF65138]))               /*Descriptor addr where EOF occurs*/

#define SPI0_OUTLINK_DSCR_REG                (*(vuint32 *)(&__IPSBAR[0x3FF4313C]))               /*Current descriptor ptr*/
#define SPI1_OUTLINK_DSCR_REG                (*(vuint32 *)(&__IPSBAR[0x3FF4213C]))               /*Current descriptor ptr*/
#define SPI2_OUTLINK_DSCR_REG                (*(vuint32 *)(&__IPSBAR[0x3FF6413C]))               /*Current descriptor ptr*/
#define SPI3_OUTLINK_DSCR_REG                (*(vuint32 *)(&__IPSBAR[0x3FF6513C]))               /*Current descriptor ptr*/

#define SPI0_OUTLINK_DSCR_BF0_REG            (*(vuint32 *)(&__IPSBAR[0x3FF43140]))               /*Next descriptor data ptr*/
#define SPI1_OUTLINK_DSCR_BF0_REG            (*(vuint32 *)(&__IPSBAR[0x3FF42140]))               /*Next descriptor data ptr*/
#define SPI2_OUTLINK_DSCR_BF0_REG            (*(vuint32 *)(&__IPSBAR[0x3FF64140]))               /*Next descriptor data ptr*/
#define SPI3_OUTLINK_DSCR_BF0_REG            (*(vuint32 *)(&__IPSBAR[0x3FF65140]))               /*Next descriptor data ptr*/

#define SPI0_OUTLINK_DSCR_BF1_REG            (*(vuint32 *)(&__IPSBAR[0x3FF43144]))               /*Current descriptor data ptr*/
#define SPI1_OUTLINK_DSCR_BF1_REG            (*(vuint32 *)(&__IPSBAR[0x3FF42144]))               /*Current descriptor data ptr*/
#define SPI2_OUTLINK_DSCR_BF1_REG            (*(vuint32 *)(&__IPSBAR[0x3FF64144]))               /*Current descriptor data ptr*/
#define SPI3_OUTLINK_DSCR_BF1_REG            (*(vuint32 *)(&__IPSBAR[0x3FF65144]))               /*Current descriptor data ptr*/

#define SPI0_DMA_RSTATUS_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF43148]))               /*DMA memory read status reg*/
#define SPI1_DMA_RSTATUS_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF42148]))               /*DMA memory read status reg*/
#define SPI2_DMA_RSTATUS_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF64148]))               /*DMA memory read status reg*/
#define SPI3_DMA_RSTATUS_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF65148]))               /*DMA memory read status reg*/

#define SPI0_DMA_TSTATUS_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF4314C]))               /*DMA memory write status reg*/
#define SPI1_DMA_TSTATUS_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF4214C]))               /*DMA memory write status reg*/
#define SPI2_DMA_TSTATUS_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF6414C]))               /*DMA memory write status reg*/
#define SPI3_DMA_TSTATUS_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF6514C]))               /*DMA memory write status reg*/

#define SPI0_DMA_INT_RAW_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF43114]))               /*Raw interrupt status reg*/
#define SPI1_DMA_INT_RAW_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF42114]))               /*Raw interrupt status reg*/
#define SPI2_DMA_INT_RAW_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF64114]))               /*Raw interrupt status reg*/
#define SPI3_DMA_INT_RAW_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF65114]))               /*Raw interrupt status reg*/

#define SPI0_DMA_INT_ST_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF43118]))               /*Masked interrupt status reg*/
#define SPI1_DMA_INT_ST_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF42118]))               /*Masked interrupt status reg*/
#define SPI2_DMA_INT_ST_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF64118]))               /*Masked interrupt status reg*/
#define SPI3_DMA_INT_ST_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF65118]))               /*Masked interrupt status reg*/

#define SPI0_DMA_INT_ENA_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF43110]))               /*Interrupt enable bits*/
#define SPI1_DMA_INT_ENA_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF42110]))               /*Interrupt enable bits*/
#define SPI2_DMA_INT_ENA_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF64110]))               /*Interrupt enable bits*/
#define SPI3_DMA_INT_ENA_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF65110]))               /*Interrupt enable bits*/

#define SPI0_DMA_INT_CLR_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF4311C]))               /*Interrupt clear bits*/
#define SPI1_DMA_INT_CLR_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF4211C]))               /*Interrupt clear bits*/
#define SPI2_DMA_INT_CLR_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF6411C]))               /*Interrupt clear bits*/
#define SPI3_DMA_INT_CLR_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF6511C]))               /*Interrupt clear bits*/

/***********************************************************************/
/*
 * SDIO slave controller
 *
 * Packets(512 bytes), interrupts, data padding, interrupt vectors and DMA for data transfer
 */

#define SLCCONF0_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF58000]))              /*SLCCONF0_SLC config*/
#define SLC0RX_LINK_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF5803C]))              /*Transmitting linked list config*/
#define SLC0TX_LINK_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF58040]))              /*Receiving linked list config*/
#define SLCINTVEC_TOHOST_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF5804C]))              /*Interrupt sector for Slave to interrupt host*/
#define SLC0TOKEN1_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF58054]))              /*Number of receiving buffer*/
#define SLCCONF1_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF58060]))              /*Control reg*/
#define SLC_RX_DSCR_CONF_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF58098]))              /*DMA transmission config*/
#define SLC0_LEN_CONF_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF580E4]))              /*Length control of transmitting packets*/
#define SLC0_LENGTH_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF580E8]))              /*Length of transmitting packets*/

#define SLC0INT_RAW_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF58004]))              /*Raw interrupt status*/
#define SLC0INT_ST_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF58008]))              /*Interrupt status*/
#define SLC0INT_ENA_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF5800C]))              /*Interrupt enable*/
#define SLC0INT_CLR_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF58010]))              /*Interrupt clear*/

#define SLC0HOST_TOKEN_RDATA_REG             (*(vuint32 *)(&__IPSBAR[0x3FF55044]))              /*Accumulated number of slaves recieving buffers*/
#define SLCHOST_PKT_LEN_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF55060]))              /*Length of the packet*/
#define SLCHOST_CONF_W0_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF5506c]))              /*Host and slave communication register0*/
#define SLCHOST_CONF_W1_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF55070]))              /*Host and slave communication register1*/
#define SLCHOST_CONF_W2_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF55074]))              /*Host and slave communication register2*/
#define SLCHOST_CONF_W3_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF55078]))              /*Host and slave communication register3*/
#define SLCHOST_CONF_W4_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF5507C]))              /*Host and slave communication register4*/
#define SLCHOST_CONF_W6_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF55088]))              /*Host and slave communication register6*/
#define SLCHOST_CONF_W7_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF5508C]))              /*Interrupt vector for Host to interrupt slave*/
#define SLCHOST_CONF_W8_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF5509C]))              /*Host and slave communication register8*/
#define SLCHOST_CONF_W9_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF550A0]))              /*Host and slave communication register9*/
#define SLCHOST_CONF_W10_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF550A4]))              /*Host and slave communication register10*/
#define SLCHOST_CONF_W11_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF550A8]))              /*Host and slave communication register11*/
#define SLCHOST_CONF_W12_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF550AC]))              /*Host and slave communication register12*/
#define SLCHOST_CONF_W13_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF550B0]))              /*Host and slave communication register13*/
#define SLCHOST_CONF_W14_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF550B4]))              /*Host and slave communication register14*/
#define SLCHOST_CONF_W15_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF550B8]))              /*Host and slave communication register15*/
#define SLCHOST_CONF_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF551F0]))              /*Edge config*/

#define SLC0HOST_INT_RAW_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF55000]))              /*Raw interrupt status*/
#define SLC0HOST_INT_ST_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF55058]))              /*Masked interrupt status*/
#define SLC0HOST_INT_CLR_REG                 (*(vuint32 *)(&__IPSBAR[0x3FF550D4]))              /*Interrupt clear*/
#define SLC0HOST_FUNC1_INT_ENA_REG           (*(vuint32 *)(&__IPSBAR[0x3FF550DC]))              /*Interrupt enable*/

#define HINF_CFG_DATA1_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF4B004]))              /*SDIO specification config*/
/***********************************************************************/
/*
 * SD/MMC Host controller registers
 *
 * 
 */

#define CTRL_REG                             (*(vuint32 *)(&__IPSBAR[0x3FF68000]))              /*Control reg*/
#define CLKDIV_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF68008]))              /*Clock divider*/
#define CLKSRC_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF6800C]))              /*Clock source*/
#define CLKENA_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF68010]))              /*Clock enable*/
#define TMOUT_REG                            (*(vuint32 *)(&__IPSBAR[0x3FF68014]))              /*Data and response timeout config reg*/
#define CTYPE_REG                            (*(vuint32 *)(&__IPSBAR[0x3FF68018]))              /*Card bus width config reg*/
#define BLKSIZ_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF6801C]))              /*Card data block size config reg*/
#define BYTCNT_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF68020]))              /*Data transfer length config reg*/
#define INTMASK_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF68024]))              /*SDIO interrupt mask reg*/
#define CMDARG_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF68028]))              /*Command argument reg*/
#define CMD_REG                              (*(vuint32 *)(&__IPSBAR[0x3FF6802C]))              /*Command and boot config reg*/
#define RESP0_REG                            (*(vuint32 *)(&__IPSBAR[0x3FF68030]))              /*Response data reg*/
#define RESP1_REG                            (*(vuint32 *)(&__IPSBAR[0x3FF68034]))              /*Long response data reg*/
#define RESP2_REG                            (*(vuint32 *)(&__IPSBAR[0x3FF68038]))              /*Long response data reg*/
#define RESP3_REG                            (*(vuint32 *)(&__IPSBAR[0x3FF6803C]))              /*Long response data reg*/
#define MINTSTS_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF68040]))              /*Masked interrupt status reg*/
#define RINTSTS_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF68044]))              /*Raw interrupt status reg*/
#define STATUS_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF68048]))              /*SD/MMC status reg*/
#define FIFOTH_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF6804C]))              /*FIFO threshold config reg*/
#define CDETECT_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF68050]))              /*Card detect reg*/
#define WRTPRT_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF68054]))              /*Card write protection (WP) status reg*/
#define TCBCNT_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF6805C]))              /*Transferred byte count reg*/
#define TBBCNT_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF68060]))              /*Transferred block count reg*/
#define DEBNCE_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF68064]))              /*Debounce filter time config reg*/
#define USRID_REG                            (*(vuint32 *)(&__IPSBAR[0x3FF68068]))              /*User ID (scratchpad) reg*/
#define RST_N_REG                            (*(vuint32 *)(&__IPSBAR[0x3FF68078]))              /*Card reset reg*/
#define BMOD_REG                             (*(vuint32 *)(&__IPSBAR[0x3FF68080]))              /*Burst mode transfer config reg*/
#define PLDMND_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF68084]))              /*Poll demand config reg*/
#define DBADDR_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF68088]))              /*Data buffer pointer reg*/
#define IDSTS_REG                            (*(vuint32 *)(&__IPSBAR[0x3FF6808C]))              /*IDMAC status reg*/
#define IDINTEN_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF68090]))              /*IDMAC interrupt enable reg*/
#define DSCADDR_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF68094]))              /*Host descriptor list base address reg*/
#define BUFADDR_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF68098]))              /*Host buffer addr ptr reg*/
#define CLK_EDGE_SEL_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF68800]))              /*Clock phase selection reg*/
/***********************************************************************/
/*
 * EMAC registers
 *
 * 
 */
#define DMABUSMODE_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF69000]))              /*DMA bus mode reg*/
#define DMATXPOLLDEMAND_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF69004]))              /*DMA transmit poll demand reg*/
#define DMARXPOLLDEMAND_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF69008]))              /*DMA receive poll demand reg*/
#define DMARXBASEADDR_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF6900C]))              /*DMA receive descriptor list base address reg*/
#define DMATXBASEADDR_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF69010]))              /*DMA transmit descriptor list base address reg*/
#define DMASTATUS_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF69014]))              /*Status of interrupts, errors and other events*/
#define DMAOPERATION_MODE_REG                (*(vuint32 *)(&__IPSBAR[0x3FF69018]))              /*Receive and transmit operating modes and command*/
#define DMAIN_EN_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF6901C]))              /*Interrupt enable reg*/
#define DMAMISSEDFR_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF69020]))              /*Missed frame and buffer overflow counter reg*/
#define DMARINTWDTIMER_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF69024]))              /*Receive interrupt watchdog timer reg*/
#define DMATXCURRDESC_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF69048]))              /*Pointer to current transmit descriptor*/
#define DMARXCURRDESC_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF6904C]))              /*Pointer to current receive descriptor*/
#define DMATXCURRADDR_BUF_REG                (*(vuint32 *)(&__IPSBAR[0x3FF69050]))              /*Pointer to current transmit buffer address*/
#define DMARXCURRADDR_BUF_REG                (*(vuint32 *)(&__IPSBAR[0x3FF69054]))              /*Pointer to current receive buffer address*/

#define EMACCONFIG_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF6A000]))              /*MAC configuration reg*/
#define EMACFF_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF6A004]))              /*Frame filter settings*/
#define EMACGMIIADDR_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF6A010]))              /*PHY config access*/
#define EMACMIIDATA_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF6A014]))              /*PHY data read access*/
#define EMACFC_REG                           (*(vuint32 *)(&__IPSBAR[0x3FF6A018]))              /*Frame flow control settings*/
#define EMACDEBUG_REG                        (*(vuint32 *)(&__IPSBAR[0x3FF6A024]))              /*Status debug bits*/
#define PMT_RWUFFER_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF6A028]))              /*Remote Wake-Up frame filter*/
#define PMT_CSR_REG                          (*(vuint32 *)(&__IPSBAR[0x3FF6A02C]))              /*PMT Control and status*/
#define EMACLPI_CSR_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF6A030]))              /*LPI control and status*/
#define EMACLPITIMERSCONTROL_REG             (*(vuint32 *)(&__IPSBAR[0x3FF6A034]))              /*LPI timers control*/
#define EMACINTS_REG                         (*(vuint32 *)(&__IPSBAR[0x3FF6A038]))              /*Interrupt status*/
#define EMACINTMASK_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF6A03C]))              /*Interrupt mask*/
#define EMACADDR0HIGH_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF6A040]))              /*Upper 16 bits of first 6-byte MAC addr*/
#define EMACADDR0LOW_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF6A044]))              /*Lower 32 bits of first 6-bytes MAC addr*/
#define EMACADDR1HIGH_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF6A048]))              /*Upper 16 bits of second 6-byte MAC addr*/
#define EMACADDR1LOW_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF6A04C]))              /*Lower 32 bits of second 6-bytes MAC addr*/
#define EMACADDR2HIGH_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF6A050]))              /*Upper 16 bits of third 6-byte MAC addr*/
#define EMACADDR2LOW_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF6A054]))              /*Lower 32 bits of third 6-bytes MAC addr*/
#define EMACADDR3HIGH_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF6A058]))              /*Upper 16 bits of fourth 6-byte MAC addr*/
#define EMACADDR3LOW_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF6A05C]))              /*Lower 32 bits of fourth 6-bytes MAC addr*/
#define EMACADDR4HIGH_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF6A060]))              /*Upper 16 bits of fifth 6-byte MAC addr*/
#define EMACADDR4LOW_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF6A064]))              /*Lower 32 bits of fifth 6-bytes MAC addr*/
#define EMACADDR5HIGH_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF6A068]))              /*Upper 16 bits of sixth 6-byte MAC addr*/
#define EMACADDR5LOW_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF6A06C]))              /*Lower 32 bits of sixth 6-bytes MAC addr*/
#define EMACADDR6HIGH_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF6A070]))              /*Upper 16 bits of seventh 6-byte MAC addr*/
#define EMACADDR6LOW_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF6A074]))              /*Lower 32 bits of seventh 6-bytes MAC addr*/
#define EMACADDR7HIGH_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF6A078]))              /*Upper 16 bits of eighth 6-byte MAC addr*/
#define EMACADDR7LOW_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF6A07C]))              /*Lower 32 bits of eighth 6-bytes MAC addr*/
#define EMACCSTATUS_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF6A0D8]))              /*Link comm status*/
#define EMACWDOGTO_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF6A0DC]))              /*Watchdog timeout control*/

#define EMAC_EX_CLKOUT_CONF_REG              (*(vuint32 *)(&__IPSBAR[0x3FF69800]))              /*RMII clock divider setting*/
#define EMAC_EX_OSCCLK_CONF_REG              (*(vuint32 *)(&__IPSBAR[0x3FF69804]))              /*RMII clock half and whole divide settings*/

#define EMAC_EX_PHYINF_CONF_REG              (*(vuint32 *)(&__IPSBAR[0x3FF6980C]))              /*Selection of MII / RMII phy*/
#define EMAC_PD_SEL_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF69810]))              /*Ethernet RAM power-down enable*/

#define EMACADDRnLOW_REG(n)                  (*(vuint32 *)(&__IPSBAR[0x3FF6A044 + (n * 8)]))   /*Lower 32 bits of n-th 6-bytes MAC addr*/
#define EMACADDRnHIGH_REG(n)                 (*(vuint32 *)(&__IPSBAR[0x3FF6A040 + (n * 8)]))   /*Upper 16 bits of n-th 6-byte MAC addr*/

/***********************************************************************/
/*
 * I2C registers
 *
 * 
 */

#define I2C0_SLAVE_ADDR_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF53010]))              /*Configures the I2C slave addr for I2C0*/
#define I2C1_SLAVE_ADDR_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF67010]))              /*Configures the I2C slave addr for I2C1*/
#define I2C0_RXFIFO_ST_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF53014]))              /*I2C0 receive FIFO status*/
#define I2C1_RXFIFO_ST_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF67014]))              /*I2C1 receive FIFO status*/
#define I2C0_FIFO_CONF_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF53018]))              /*I2C0 FIFO config*/
#define I2C1_FIFO_CONF_REG                   (*(vuint32 *)(&__IPSBAR[0x3FF67018]))              /*I2C1 FIFO config*/

#define I2C0_SDA_HOLD_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF53030]))              /*Configs the hold time after a negative SCL edge*/
#define I2C1_SDA_HOLD_REG                    (*(vuint32 *)(&__IPSBAR[0x3FF67030]))              /*Configs the hold time after a negative SCL edge*/
#define I2C0_SDA_SAMPLE_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF53034]))              /*Configs the sampling time after a positive SCL edge*/
#define I2C1_SDA_SAMPLE_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF67034]))              /*Configs the sampling time after a positive SCL edge*/
#define I2C0_SCL_LOW_PERIOD_REG              (*(vuint32 *)(&__IPSBAR[0x3FF53000]))              /*Configs the low level width of the SCL clock*/
#define I2C1_SCL_LOW_PERIOD_REG              (*(vuint32 *)(&__IPSBAR[0x3FF67000]))              /*Configs the low level width of the SCL clock*/
#define I2C0_SCL_HIGH_PERIOD_REG             (*(vuint32 *)(&__IPSBAR[0x3FF53038]))              /*Configs the high level width of the SCL clock*/
#define I2C1_SCL_HIGH_PERIOD_REG             (*(vuint32 *)(&__IPSBAR[0x3FF67038]))              /*Configs the high level width of the SCL clock*/
#define I2C0_SCL_START_HOLD_REG              (*(vuint32 *)(&__IPSBAR[0x3FF53040]))              /*Configs the delay between the SDA and SCL negative edge for an IC*/
#define I2C1_SCL_START_HOLD_REG              (*(vuint32 *)(&__IPSBAR[0x3FF67040]))              /*Configs the delay between the SDA and SCL negative edge for an IC*/
#define I2C0_RSTART_SETUP_REG                (*(vuint32 *)(&__IPSBAR[0x3FF53044]))              /*Delay between the SCL positive edge and the SDA negative edgefor ICs*/
#define I2C1_RSTART_SETUP_REG                (*(vuint32 *)(&__IPSBAR[0x3FF67044]))              /*Delay between the SCL positive edge and the SDA negative edgefor ICs*/
#define I2C0_SCL_STOP_HOLD_REG               (*(vuint32 *)(&__IPSBAR[0x3FF53048]))              /*Configs the delay after the SCL clock edge for a stop condition*/
#define I2C1_SCL_STOP_HOLD_REG               (*(vuint32 *)(&__IPSBAR[0x3FF67048]))              /*Configs the delay after the SCL clock edge for a stop condition*/

#define I2C0_SCL_FILTER_CFG_REG              (*(vuint32 *)(&__IPSBAR[0x3FF53050]))              /*SCL filter config reg*/
#define I2C1_SCL_FILTER_CFG_REG              (*(vuint32 *)(&__IPSBAR[0x3FF67050]))              /*SCL filter config reg*/
#define I2C0_SDA_FILTER_CFG_REG              (*(vuint32 *)(&__IPSBAR[0x3FF53054]))              /*SDA filter config reg*/
#define I2C1_SDA_FILTER_CFG_REG              (*(vuint32 *)(&__IPSBAR[0x3FF67054]))              /*SDA filter config reg*/

#define I2C0_INT_RAW_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF53020]))              /*Raw interrupt status*/
#define I2C1_INT_RAW_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF67020]))              /*Raw interrupt status*/
#define I2C0_INT_CLR_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF53024]))              /*Interrupt clear bits*/
#define I2C1_INT_CLR_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF67024]))              /*Interrupt clear bits*/
#define I2C0_INT_ENA_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF53028]))              /*Interrupt enable bits*/
#define I2C1_INT_ENA_REG                     (*(vuint32 *)(&__IPSBAR[0x3FF67028]))              /*Interrupt enable bits*/
#define I2C0_INT_STATUS_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF5302C]))              /*Interrupt status*/
#define I2C1_INT_STATUS_REG                  (*(vuint32 *)(&__IPSBAR[0x3FF6702C]))              /*Interrupt status*/

#define I2C0_COMD0_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF53058]))              /*Command reg for I2C0*/
#define I2C1_COMD0_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF67058]))              /*Command reg for I2C1*/
#define I2C0_COMD1_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF5305C]))              /*Command reg for I2C0*/
#define I2C1_COMD1_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF6705C]))              /*Command reg for I2C1*/
#define I2C0_COMD2_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF53060]))              /*Command reg for I2C0*/
#define I2C1_COMD2_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF67060]))              /*Command reg for I2C1*/
#define I2C0_COMD3_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF53064]))              /*Command reg for I2C0*/
#define I2C1_COMD3_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF67064]))              /*Command reg for I2C1*/
#define I2C0_COMD4_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF53068]))              /*Command reg for I2C0*/
#define I2C1_COMD4_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF67068]))              /*Command reg for I2C1*/
#define I2C0_COMD5_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF5306C]))              /*Command reg for I2C0*/
#define I2C1_COMD5_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF6706C]))              /*Command reg for I2C1*/
#define I2C0_COMD6_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF53070]))              /*Command reg for I2C0*/
#define I2C1_COMD6_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF67070]))              /*Command reg for I2C1*/
#define I2C0_COMD7_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF53074]))              /*Command reg for I2C0*/
#define I2C1_COMD7_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF67074]))              /*Command reg for I2C1*/
#define I2C0_COMD8_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF53078]))              /*Command reg for I2C0*/
#define I2C1_COMD8_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF67078]))              /*Command reg for I2C1*/
#define I2C0_COMD9_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF5307C]))              /*Command reg for I2C0*/
#define I2C1_COMD9_REG                       (*(vuint32 *)(&__IPSBAR[0x3FF6707C]))              /*Command reg for I2C1*/
#define I2C0_COMD10_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF53080]))              /*Command reg for I2C0*/
#define I2C1_COMD10_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF67080]))              /*Command reg for I2C1*/
#define I2C0_COMD11_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF53084]))              /*Command reg for I2C0*/
#define I2C1_COMD11_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF67084]))              /*Command reg for I2C1*/
#define I2C0_COMD12_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF53088]))              /*Command reg for I2C0*/
#define I2C1_COMD12_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF67088]))              /*Command reg for I2C1*/
#define I2C0_COMD13_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF5308C]))              /*Command reg for I2C0*/
#define I2C1_COMD13_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF6708C]))              /*Command reg for I2C1*/
#define I2C0_COMD14_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF53090]))              /*Command reg for I2C0*/
#define I2C1_COMD14_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF67090]))              /*Command reg for I2C1*/
#define I2C0_COMD15_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF53094]))              /*Command reg for I2C0*/
#define I2C1_COMD15_REG                      (*(vuint32 *)(&__IPSBAR[0x3FF67094]))              /*Command reg for I2C1*/

/***********************************************************************/
/*
 * I2S registers
 *
 * 
 */

#endif