/* Copyright 2016, XXXX
 *
 *  * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "03_blinking_bm.h"       /* <= own header */



/*==================[macros and definitions]=================================*/
#define CONST_TIMER 300000

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

#define PERIODO_LED 3000000
#define NUM_LED 5

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

void delay(uint32_t periodo)
{
	uint64_t i;
for(i=periodo;i!=0;i--);
}

void Delay (uint8_t c){
uint64_t a;
for (a=CONST_TIMER * c;a!=0;a--);
}


/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */



int main(void)
{
   /* inicializaciones */
   uint32_t periodo_blinking=PERIODO_LED;

   InitLeds();
   Init_Switches();

   uint8_t tecla, LedPrendido=LED_1;
   uint8_t contador=0;
   uint8_t frecuencia=1;
    while(1)
    {
    do
    {
    	delay(frecuencia);
    	LedPrendido=1<<contador;
    	ToggleLed(LedPrendido);
    	delay(PERIODO_LED);
    	tecla=Read_Switches();

    }while(tecla==0);
     ApagarLed(LedPrendido);


     if(tecla==TEC1)
     {

    	 contador++;
    	 if (contador>NUM_LED)
    	 {
    		 contador=0;
     	 }

      }

     if(tecla==TEC2)
          {

         	 if (contador>0)
         	 {
         		 contador--;
         	 }
         	 else {
         		 contador=NUM_LED;
         	 }

           }

     if(tecla==	TEC3)
     		{

     			frecuencia++;
     			//ToggleLed(LedPrendido);
     			Delay(frecuencia);
     		}

     		if(tecla== TEC4)
     		{
     			if (frecuencia>1)
     			{
     				frecuencia--;
     				//ToggleLed(LedPrendido);
     			    Delay(frecuencia);
     			}
     			else
     			{
     				frecuencia=1;
     			}

     		}

    } ;
    return 0;
    

}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

