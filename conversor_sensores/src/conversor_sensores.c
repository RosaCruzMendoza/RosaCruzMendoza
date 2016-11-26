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
#include "conversor_sensores.h"       /* <= own header */
#define LIMIT_SUP 900
#define LIMIT_INF 450

#define CONST_TIMER 300000

void Delay (void){
uint64_t i;
for (i=CONST_TIMER;i!=0;i--);
}

void Convertir_senal1(void)
{
	uint16_t valor1;

	valor1=read_ADC_value_pooling(); //valor de la señal en el CH1

	if (valor1 > LIMIT_SUP)//cuando la barrera IR del CH1 no se corta
	    {
	    EncenderLed(LED_1);

	    }
	 else
	    {
	    if (valor1<LIMIT_INF)//cuando corto la barrera IR
	    	{

	    	ApagarLed(LED_1);
	    	}

	    }


}

void Convertir_senal2(void)
{
	uint16_t valor2;

	valor2=read_ADC_value_pooling(); //valor de la señal en el CH2

	if (valor2 > LIMIT_SUP)//cuando la barrera IR en CH2 no se corta
	    {

	    EncenderLed(LED_2);

	    }
	 else
	    {
	    if (valor2<LIMIT_INF)//cuando corto la barrera IR
	    	{

	    	ApagarLed(LED_2);
	    	}

	    }


}

void Convertir_senal3(void)
{
	uint16_t valor3;

	valor3=read_ADC_value_pooling(); //valor de la señal en el CH3

	if (valor3 > LIMIT_SUP)//cuando la barrera IR en el CH3 no se corta
	    {
	    EncenderLed(LED_3);

	    }
	 else
	    {
	    if (valor3<LIMIT_INF)//cuando corto la barrera IR
	    	{

	    	ApagarLed(LED_3);
	    	}

	    }


}
/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
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
	uint16_t valor;

	InitLeds();
	init_ADC_EDUCIAA();
	ADC_Sel(CH1);
	ADC_Sel(CH2);
	ADC_Sel(CH3);

    /*acá va mi programa principal */

    while(1)
    {
Convertir_senal1();
Convertir_senal2();
Convertir_senal3();

    };
    	return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

