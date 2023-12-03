/*============================================================================================
 * Module : GPIO
 *
 * File Name : stm32f103c8_gpio_driver.h
 *
 * Author: Abdullah Maher
 *
 * Description : Header File Of STM32F103C8 GPIO Driver
 *
 * Created on: Sep 1, 2023
 =============================================================================================*/

#ifndef INC_STM32F103C8_GPIO_DRIVER_H_
#define INC_STM32F103C8_GPIO_DRIVER_H_

/*===============================================================================
 *                                Includes                                       *
 ================================================================================*/

#include "stm32f103c8.h"

/*===============================================================================
 *                            User Type Definitions                              *
 ================================================================================*/
typedef struct
{
	uint8_t GPIO_PinNumber;  /* Specifies The GPIOx Pin Number According to @ref GPIO_PIN_NUMBER_DEFINE */

	uint8_t GPIO_Mode;        /* Specifies The GPIOx Pin Mode According to @ref GPIO_PIN_MODE_DEFINE */

	uint8_t GPIO_Output_Speed;/* Specifies The GPIOx Pin Output Speed According to @ref GPIO_PIN_OUTPUT_SPEED_DEFINE */

}GPIO_PinConfig_t;

/*===============================================================================
 *                       Macros Configuration References                         *
 ================================================================================*/

				/*	@ref GPIO_PIN_NUMBER_DEFINE */
#define GPIO_PIN0								(0)
#define GPIO_PIN1								(1)
#define GPIO_PIN2								(2)
#define GPIO_PIN3								(3)
#define GPIO_PIN4								(4)
#define GPIO_PIN5								(5)
#define GPIO_PIN6								(6)
#define GPIO_PIN7								(7)
#define GPIO_PIN8								(8)
#define GPIO_PIN9								(9)
#define GPIO_PIN10								(10)
#define GPIO_PIN11								(11)
#define GPIO_PIN12								(12)
#define GPIO_PIN13								(13)
#define GPIO_PIN14								(14)
#define GPIO_PIN15								(15)


               /*  @ref GPIO_PIN_MODE_DEFINE*/
#define GPIO_MODE_INPUT_ANALOG						(0x00U)/* 00: Analog mode*/
#define GPIO_MODE_INPUT_FLOATING					(0x01U)/* 01: Floating input (reset state)*/
#define GPIO_MODE_INPUT_PULLUP						(0x02U)/* 10: Input with pull-up*/
#define GPIO_MODE_INPUT_PULLDOWN					(0x03U)/* 11: Input with pull-down*/
#define GPIO_MODE_OUTPUT_PUSHPULL					(0x04U)/* 00: General purpose output push-pull*/
#define GPIO_MODE_OUTPUT_OPENDRAIN					(0x05U)/* 01: General purpose output Open-drain*/
#define GPIO_MODE_OUTPUT_AF_PUSHPULL				(0x06U)/* 10: Alternate function output Push-pull*/
#define GPIO_MODE_OUTPUT_AF_OPENDRAIN				(0x07U)/* 11: Alternate function output Open-drain*/
#define GPIO_MODE_INPUT_AF_FLOATING					(0x08U)/* For alternate function inputs, the port must be configured in Input mode (floating, pullup or pull-down) and the input pin must be driven externally*/

              /*  @ref GPIO_PIN_OUTPUT_SPEED_DEFINE */
/*00: Input mode (reset state)
01: Output mode, max speed 10 MHz.
10: Output mode, max speed 2 MHz.
11: Output mode, max speed 50 MHz.*/
#define GPIO_OUTPUT_SPEED_10M						(0x01U)
#define GPIO_OUTPUT_SPEED_2M						(0x02U)
#define GPIO_OUTPUT_SPEED_50M						(0x03U)

/*===============================================================================
 *                                	   APIs 		   		                     *
 ================================================================================*/

/**===============================================================================
 * Function Name  : MCAL_GPIO_Init.
 * Brief          : Function To Initiate a Pin in PORTx.
 * Parameter (in) : GPIOx x Could Be A,B,C,D and E.
 * Parameter (in) : a_PinConfig is Pointer to GPIO_PinConfig_t that Contain Configuration of Pin.
 * Return         : None.
 * Note           : That in LQFP48 GPIOA and GPIOB are fully included, GPIOC and GPIOD Partially Included, GPIOE Not Included*/
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t* p_PinConfig);

/**===============================================================================
 * Function Name  : MCAL_GPIO_DeInit.
 * Brief          : Function To Reset The PORTx.
 * Parameter (in) : GPIOx x Could Be A,B,C,D and E.
 * Return         : None.
 * Note           : None																				*/
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx);

/**===============================================================================
 * Function Name  : MCAL_GPIO_ReadPin.
 * Brief          : Function To Read Specific Pin in Specific Port
 * Parameter (in) : GPIOx x Could Be A,B,C,D and E.
 * Parameter (in) : a_PinNumber the Number Of Pin To Read it.
 * Return         : State Of Pin.
 * Note           : None																				*/
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t a_PinNumber);

/**===============================================================================
 * Function Name  : MCAL_GPIO_WritePin.
 * Brief          : Function To Write Specific Pin in Specific Port
 * Parameter (in) : GPIOx x Could Be A,B,C,D and E.
 * Parameter (in) : a_PinNumber the Number Of Pin To Write on it.
 * Return         : None.
 * Note           : None																				*/
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint8_t a_PinNumber, uint8_t a_Value);

/**===============================================================================
 * Function Name  : MCAL_GPIO_ReadPort.
 * Brief          : Function To Read Specific Port
 * Parameter (in) : GPIOx x Could Be A,B,C,D and E.
 * Return         : Value Of PORTx.
 * Note           : None																				*/
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx);

/**===============================================================================
 * Function Name  : MCAL_GPIO_WritePort.
 * Brief          : Function To Write Specific Port
 * Parameter (in) : GPIOx x Could Be A,B,C,D and E.
 * Parameter (in) : Value To be Written on The Port.
 * Return         : None.
 * Note           : None																				*/
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx,uint16_t a_Value);

/**===============================================================================
 * Function Name  : MCAL_GPIO_TogglePin.
 * Brief          : Function To Toggle Specific Pin in Specific Port
 * Parameter (in) : GPIOx x Could Be A,B,C,D and E.
 * Parameter (in) : a_PinNumber the Number Of Pin To Toggle it.
 * Return         : None.
 * Note           : None																				*/
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t a_PinNumber);

/**===============================================================================
 * Function Name  : MCAL_GPIO_LockPin.
 * Brief          : Function To Lock Specific Pin in Specific Port
 * Parameter (in) : GPIOx x Could Be A,B,C,D and E.
 * Parameter (in) : a_PinNumber the Number Of Pin To Lock it.
 * Return         : Locked Is Done Or Not.
 * Note           : Feature In STM32F103C8																*/
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint8_t a_PinNumber);



#endif /* INC_STM32F103C8_GPIO_DRIVER_H_ */
