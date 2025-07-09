/***************************************************************************************
 * Author:				MAHAMMAD HESHMAT ABD EL RAHEEM
 * Creation Data:		1 May, 2024
 * Version:				v1.0
 * Application:			Software for 3DCP Machine
 * Layer:				APP Layer
 * Controller:			STM32F401CCU6
 * Compiler:			GNU ARM-GCC
 ***************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"
#include "../include/G_Code.h"
#include "../include/Functions.h"
#include "../include/Variables.h"


void main(void)
{
	RCC_voidInit();
	MSTK_voidInit();
	RCC_voidEnablePeripheralClock( RCC_AHB1 , RCC_AHB1_GPIOA ); //enable port A
	RCC_voidEnablePeripheralClock( RCC_AHB1 , RCC_AHB1_GPIOB ); //enable port B
	GPIO_SetUp(); //set all used pins mode 
	
	SetLeveling();

    for ( u16 Plan_Number = 1 ; Plan_Number <= NOF_PLANS ; Plan_Number++ )
    {
      // Making indication with buzzer
    	bzzer_indication(1000000);

  	  ACCUMELATOR2 += NOF_LINES[Plan_Number] ;
	  New_X = 0;
	  Old_Y = 0;

  	  for ( u16 Layers_Counter= 1 ; Layers_Counter <= PLANS_HEGHT[Plan_Number] ; Layers_Counter++ )
  	   {
  	      // Making indication with buzzer
  		  bzzer_indication(1000000);

  	  	  New_Z = 0;
  	  	  for( u16 Lines_Counter = ACCUMELATOR1 ; Lines_Counter <= ACCUMELATOR2 ; Lines_Counter++ )
  		   {
  	          Old_X = New_X;
  	          Old_Y = New_Y;
  	          Old_Z = New_Z;
  	          New_X = X_Axis[Lines_Counter];
  	          New_Y = Y_Axis[Lines_Counter];
  	          New_Z = Z_Axis[Lines_Counter];
  	          Wanted_X = New_X - Old_X;
  	          Wanted_Y = New_Y - Old_Y;
  	          Wanted_Z = New_Z - Old_Z;
  			  Wanted_Z = New_Z;
			
			  if (G_Commands[Lines_Counter]==1)
			  {Enable_Extrution();}
			  else
			  {Diable_Extrution();}

  	          //MSTK_voidSetBusyWait(1000000);		//waiting a sec to separate each line
  	          Move_Zaxis(Wanted_Z);

  	          //MSTK_voidSetBusyWait(1000000);		//waiting a sec to separate each line
  	          Move_XandYaxes( Wanted_X , Wanted_Y );
			  Diable_Extrution();
  		   }
  	   }
  	
	ACCUMELATOR1 += NOF_LINES[Plan_Number];
    }

	while(1)
		{
			//Making alarm as an indication that machine finished
			bzzer_alarm(200000);
		}
}















