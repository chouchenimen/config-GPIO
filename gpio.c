
#include "gpio.h"

void GPIO_Clock_Enable(uint32_t *GPIOx)
{
  assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
  uint16_t *RCCAHB1 = (uint16_t*)(0x40023830);
  
  if (GPIOx == GPIOA){
    *RCCAHB1 |= (1<<0);
  }
  else if (GPIOx == GPIOB){ 
    *RCCAHB1 |= (1<<1);
  }
  else if (GPIOx == GPIOC){
    *RCCAHB1 |= (1<<2);
      }
  else if (GPIOx ==GPIOD ){ 
    *RCCAHB1 |= (1<<3); 
  }
  
}
void GPIO_Config(uint32_t *GPIOx, uint8_t Pin, uint8_t Mode, uint8_t Type)
{
  assert(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC || GPIOx == GPIOD);
  assert(Pin == 0 || Pin == 1 || Pin == 2 || Pin == 3 || Pin == 4 || Pin == 5 || Pin == 6 || Pin == 7 || Pin == 8 || Pin == 9 || Pin == 10 || Pin == 11 || Pin == 12 || Pin == 13 || Pin == 14 || Pin == 15 );
  assert(Mode == OUTPUT || Mode == INPUT || Mode == ALTERNATE || Mode == ANALOG_INPUT);
  assert(Type == OUTPUT_PUSH_PULL || Type == OUTPUT_OPEN_DRAIN);
  uint16_t *GPIOx_MODER = (uint16_t*)(0x40020C00); 
  uint32_t *GPIOx_OTYPER = (uint32_t*)(0x40020C04);
  
  
  if (GPIOx == GPIOD && Pin == 12 ){ 
  if (Mode == OUTPUT ) {
    *GPIOx_MODER |= (1<<24); 
    *GPIOx_MODER &= (0<<25);
  }
  else if (Mode == INPUT) {
    *GPIOx_MODER |= (0<<24);
    *GPIOx_MODER &= (0<<25);
  }
  else if (Mode == ALTERNATE) {
    *GPIOx_MODER |= (0<<24);
    *GPIOx_MODER &= (1<<25);
  }
  else if (Mode == ANALOG_INPUT) {
    *GPIOx_MODER |= (1<<24);
    *GPIOx_MODER &= (1<<25);
  }
  
  if (Type == OUTPUT_PUSH_PULL) {
    *GPIOx_OTYPER |= (0<<12);  
 }
  else if (Type == OUTPUT_OPEN_DRAIN) {
    *GPIOx_OTYPER |= (1<<12);
 }
}
}