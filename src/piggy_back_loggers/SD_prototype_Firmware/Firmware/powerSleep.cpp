#include "powerSleep.h"

#include <avr/sleep.h>
#include <avr/power.h>
#include "state.h"

void enterSleep(State_t* State)
{
  /*** Setup Sleep options ***/
  
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  // Lowest powerdown mode
  sleep_enable();                       // Enable sleep

  /*** Put processor to sleep ***/

  sleep_mode();

  /*** Continue ***/
  
  sleep_disable();

  /*** Re-enable necessary peripherals ***/
  if(State->serialOn)
  {
    power_usart0_enable();
  }
  power_spi_enable();

  return;
}
void disableUnneededPeripherals()
{
  /*** Disable Uneeded Peripherals ***/
  ADCSRA = 0;   // Disable ADC
  power_adc_disable();
  power_timer0_disable();
  power_timer1_disable();
  power_timer2_disable();
  power_twi_disable();
  power_usart0_disable();

  /*** Enable needed Peripherals ***/     // May actually disable this too, and re-enable them later.
  power_spi_enable();

  return;
}