#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void Move_Zaxis(s16 Z_axis)
{
    if (Z_axis>0)
    {
  	  MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN5, GPIO_LOW); 		//Set forward direction to z axis
		  for (s32 i = 0; i < (Z_axis * 4000); i++) 				// MOVING Z_AXIS
		  {
				MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
				MSTK_voidSetBusyWait(100);
				MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
				MSTK_voidSetBusyWait(100);
		  }
    }
    else if (Z_axis<0)
    {
  	  MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH);		//Set reverse direction to z axis
  	  Z_axis*=(-1);
		  for (s32 i = 0; i < (Z_axis * 4000); i++) 				// MOVING Z_AXIS
		  {
				MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
				MSTK_voidSetBusyWait(100);
				MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
				MSTK_voidSetBusyWait(100);
		  }
    }
}

/*	in this function below we have two main cases :	1- moving (Y and X) axes together	(CASE_1)
 * 													2- moving only one axis (X or Y) 	(CASE_2)
 *
 * and these cases include some cases:
 * ->(CASE_1):In that case we have 4 sub-cases: 	1- (X) moving forward & (Y) moving forward	(CASE_1.1)
 * 													2- (X) moving forward & (Y) moving reverse	(CASE_1.2)
 * 													3- (X) moving reverse & (Y) moving forward	(CASE_1.3)
 * 													4- (X) moving reverse & (Y) moving reverse	(CASE_1.4)
 *
 * to handle moving two axes together I made a simple piece of code to different rate of pulses of to X&Y axes and to make that
 * you should to know which axis need higher rate and then you should to know the factor between those two factors to make pulses
 * according that factor
 *
 * ->(CASE_2):In that case we have 4 sub-cases:		1- (X) moving forward 	(CASE_2.1)
 * 													2- (X) moving reverse 	(CASE_2.2)
 * 													3- (Y) moving forward 	(CASE_2.3)
 * 													4- (Y) moving reverse 	(CASE_2.4)
 */
void Move_XandYaxes( s16 X_axis , s16 Y_axis )
{
	if((X_axis!=0) && (Y_axis!=0))//***************************  -> ->    (CASE_1)    <- <-    **************************************
	{
		if((X_axis>0) && (Y_axis>0))//*************************  -> ->   (CASE_1.1)   <- <-    **************************************
		{
			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN3, GPIO_LOW);	//Set X_axis forward direction
			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN4, GPIO_LOW);	//Set Y_axis forward direction

			if( X_axis >= Y_axis )
			{
				f32 factor = ((f32)X_axis/(f32)Y_axis);
				f32 S = factor;

				for( u32 M=1 ; M <= ((u32)X_axis*4000) ; M++)
				{
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
					MSTK_voidSetBusyWait(100);

					if( M >= S )
					{
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
						MSTK_voidSetBusyWait(100);
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
						MSTK_voidSetBusyWait(100);

						+=factor;
					}S
				}
			 }

			if( Y_axis > X_axis )
			{
				f32 factor = ((f32)Y_axis/(f32)X_axis);
				f32 S = factor;

				for( u32 M=1 ; M <= ((u32)Y_axis*4000) ; M++)
				{
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
					MSTK_voidSetBusyWait(100);

					if( M >= S )
					{
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
						MSTK_voidSetBusyWait(100);
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
						MSTK_voidSetBusyWait(100);

						S+=factor;
					}
				}
			}
		}
		else if((X_axis>0) && (Y_axis<0))//**********************  -> ->   (CASE_1.2)   <- <-    ***********************************
		{
			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN3, GPIO_LOW);	//Set X_axis forward direction
			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN4, GPIO_HIGH);	//Set Y_axis reverse direction
			Y_axis*=(-1);
			if( X_axis >= Y_axis )
			{
				f32 factor = ((f32)X_axis/(f32)Y_axis);
				f32 S = factor;

				for( u32 M=1 ; M <= ((u32)X_axis*4000) ; M++)
				{
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
					MSTK_voidSetBusyWait(100);

					if( M >= S )
					{
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
						MSTK_voidSetBusyWait(100);
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
						MSTK_voidSetBusyWait(100);

						S+=factor;
					}
				}
			 }

			if( Y_axis > X_axis )
			{
				f32 factor = ((f32)Y_axis/(f32)X_axis);
				f32 S = factor;

				for( u32 M=1 ; M <= ((u32)Y_axis*4000) ; M++)
				{
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
					MSTK_voidSetBusyWait(100);

					if( M >= S )
					{
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
						MSTK_voidSetBusyWait(100);
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
						MSTK_voidSetBusyWait(100);

						S+=factor;
					}
				}
			}
		}
		else if((X_axis<0) && (Y_axis>0))//**********************  -> ->   (CASE_1.3)   <- <-    ***********************************
		{
			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);	//Set X_axis reverse direction
			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN4, GPIO_LOW);	//Set Y_axis forward direction
			X_axis*=(-1);

			if( X_axis >= Y_axis )
			{
				f32 factor = ((f32)X_axis/(f32)Y_axis);
				f32 S = factor;

				for( u32 M=1 ; M <= ((u32)X_axis*4000) ; M++)
				{
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
					MSTK_voidSetBusyWait(100);

					if( M >= S )
					{
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
						MSTK_voidSetBusyWait(100);
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
						MSTK_voidSetBusyWait(100);

						S+=factor;
					}
				}
			 }

			if( Y_axis > X_axis )
			{
				f32 factor = ((f32)Y_axis/(f32)X_axis);
				f32 S = factor;

				for( u32 M=1 ; M <= ((u32)Y_axis*4000) ; M++)
				{
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
					MSTK_voidSetBusyWait(100);

					if( M >= S )
					{
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
						MSTK_voidSetBusyWait(100);
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
						MSTK_voidSetBusyWait(100);

						S+=factor;
					}
				}
			}
		}
		else if((X_axis<0) && (Y_axis<0))//***********************  -> ->   (CASE_1.4)   <- <-    ***********************************
		{
			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN4, GPIO_HIGH);	//Set X_axis reverse direction
			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);	//Set Y_axis reverse direction
			Y_axis*=(-1);
			X_axis*=(-1);
			if( X_axis >= Y_axis )
			{
				f32 factor = ((f32)X_axis/(f32)Y_axis);
				f32 S = factor;

				for( u32 M=1 ; M <= ((u32)X_axis*4000) ; M++)
				{
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
					MSTK_voidSetBusyWait(100);

					if( M >= S )
					{
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
						MSTK_voidSetBusyWait(100);
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
						MSTK_voidSetBusyWait(100);

						S+=factor;
					}
				}
			 }

			if( Y_axis > X_axis )
			{
				f32 factor = ((f32)Y_axis/(f32)X_axis);
				f32 S = factor;

				for( u32 M=1 ; M <= ((u32)Y_axis*4000) ; M++)
				{
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
					MSTK_voidSetBusyWait(100);

					if( M >= S )
					{
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
						MSTK_voidSetBusyWait(100);
						MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
						MSTK_voidSetBusyWait(100);

						S+=factor;
					}
				}
			}

		}
	}
	else	//*******************************************  -> ->    (CASE_2)    <- <-    ********************************************
	{
		if (X_axis>0)	//*******************************  -> ->   (CASE_2.1)   <- <-    ********************************************
		  {
			  MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN3, GPIO_LOW);	// Set X_axis forward direction
			  for (s32 i = 0; i < (X_axis * 4000); i++) 				// MOVING X_AXIS
			  {
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
					MSTK_voidSetBusyWait(100);
			  }
		  }
		  else if (X_axis<0)//*******************************  -> ->   (CASE_2.2)   <- <-    ****************************************
			{
			  MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN3, GPIO_HIGH);		//Set X_axis reverse direction
			  X_axis*=(-1);
			  for (s32 i = 0; i < (X_axis * 4000); i++) 					// MOVING X_AXIS
			  {
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
					MSTK_voidSetBusyWait(100);
			  }
			}


		  if (Y_axis>0)//*******************************  -> ->   (CASE_2.3)   <- <-    ****************************************
		  {
			  MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN4, GPIO_LOW);		// Set Y_axis forward direction
			  for (s32 i = 0; i < (Y_axis * 4000); i++) 					// MOVING Y_AXIS
			  {
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
					MSTK_voidSetBusyWait(100);
			  }
		  }
		  else if (Y_axis<0)//*******************************  -> ->   (CASE_2.4)   <- <-    ****************************************
		  {
			  MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN4, GPIO_HIGH);		//Set Y_axis reverse direction
			  Y_axis*=(-1);
			  for (s32 i = 0; i < (Y_axis * 4000); i++) 					// MOVING Y_AXIS
			  {
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
					MSTK_voidSetBusyWait(100);
					MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
					MSTK_voidSetBusyWait(100);
			  }
		  }


	}

}

void Enable_Extrution(void)
{
	MGPIO_VoidSetPin_Value(GPIO_PORTB, GPIO_PIN7, GPIO_HIGH);
}

void Enable_Extrution(void)
{
	MGPIO_VoidSetPin_Value(GPIO_PORTB, GPIO_PIN7, GPIO_LOW);
}

void bzzer_indication(u32 time)
{
	  MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN6, GPIO_HIGH);
	  MSTK_voidSetBusyWait(time);
	  MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN6, GPIO_LOW);
}

void bzzer_alarm(u32 time)
{
	  MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN6, GPIO_HIGH);
	  MSTK_voidSetBusyWait(time);
	  MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN6, GPIO_LOW);
	  MSTK_voidSetBusyWait(time);
}

void GPIO_SetUp(void)
{
	MGPIO_VoidSetPin_Mode( GPIO_PORTA , GPIO_PIN0 , GPIO_OUTPUT );	//A0 pulse to motor X
	MGPIO_VoidSetPin_Mode( GPIO_PORTA , GPIO_PIN1 , GPIO_OUTPUT );	//A1 pulse to motor Y
	MGPIO_VoidSetPin_Mode( GPIO_PORTA , GPIO_PIN2 , GPIO_OUTPUT );	//A2 pulse to motor Z

	MGPIO_VoidSetPin_Mode( GPIO_PORTA , GPIO_PIN3 , GPIO_OUTPUT );	//A3 direction motor X
	MGPIO_VoidSetPin_Mode( GPIO_PORTA , GPIO_PIN4 , GPIO_OUTPUT );	//A4 direction motor Y
	MGPIO_VoidSetPin_Mode( GPIO_PORTA , GPIO_PIN5 , GPIO_OUTPUT );	//A5 direction motor Z

	MGPIO_VoidSetPin_Mode( GPIO_PORTA , GPIO_PIN6 , GPIO_OUTPUT );	//A6 to buzzer

	MGPIO_VoidSetPin_OutputMode( GPIO_PORTA , GPIO_PIN0 , GPIO_PUSH_PULL );
	MGPIO_VoidSetPin_OutputMode( GPIO_PORTA , GPIO_PIN1 , GPIO_PUSH_PULL );
	MGPIO_VoidSetPin_OutputMode( GPIO_PORTA , GPIO_PIN2 , GPIO_PUSH_PULL );
	MGPIO_VoidSetPin_OutputMode( GPIO_PORTA , GPIO_PIN3 , GPIO_PUSH_PULL );
	MGPIO_VoidSetPin_OutputMode( GPIO_PORTA , GPIO_PIN4 , GPIO_PUSH_PULL );
	MGPIO_VoidSetPin_OutputMode( GPIO_PORTA , GPIO_PIN5 , GPIO_PUSH_PULL );
	MGPIO_VoidSetPin_OutputMode( GPIO_PORTA , GPIO_PIN6 , GPIO_PUSH_PULL );

	MGPIO_VoidSetPin_OutputSpeed( GPIO_PORTA , GPIO_PIN0 , GPIO_VERY_HIGH_SPEED );
	MGPIO_VoidSetPin_OutputSpeed( GPIO_PORTA , GPIO_PIN1 , GPIO_VERY_HIGH_SPEED );
	MGPIO_VoidSetPin_OutputSpeed( GPIO_PORTA , GPIO_PIN2 , GPIO_VERY_HIGH_SPEED );
	MGPIO_VoidSetPin_OutputSpeed( GPIO_PORTA , GPIO_PIN3 , GPIO_VERY_HIGH_SPEED );
	MGPIO_VoidSetPin_OutputSpeed( GPIO_PORTA , GPIO_PIN4 , GPIO_VERY_HIGH_SPEED );
	MGPIO_VoidSetPin_OutputSpeed( GPIO_PORTA , GPIO_PIN5 , GPIO_VERY_HIGH_SPEED );
	MGPIO_VoidSetPin_OutputSpeed( GPIO_PORTA , GPIO_PIN6 , GPIO_VERY_HIGH_SPEED );
}

void SetLeveling(void)
{
	while(MGPIO_u8GetPinValue( GPIO_PORTB , GPIO_PIN0 )==GPIO_HIGH)
	{
		MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
		MSTK_voidSetBusyWait(100);
		MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
		MSTK_voidSetBusyWait(100);
	}
	while(MGPIO_u8GetPinValue( GPIO_PORTB , GPIO_PIN1 )==GPIO_HIGH)
	{
		MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_HIGH);
		MSTK_voidSetBusyWait(100);
		MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN1, GPIO_LOW);
		MSTK_voidSetBusyWait(100);
	}
	while(MGPIO_u8GetPinValue( GPIO_PORTB , GPIO_PIN2 )==GPIO_HIGH)
	{
		while(MGPIO_u8GetPinValue( GPIO_PORTB , GPIO_PIN3 )==GPIO_HIGH)
		{
			if(MGPIO_u8GetPinValue( GPIO_PORTB , GPIO_PIN3 )==GPIO_HIGH)
			{MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN5, GPIO_LOW);}

			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
			MSTK_voidSetBusyWait(100);
			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
			MSTK_voidSetBusyWait(100);
		}
		while(MGPIO_u8GetPinValue( GPIO_PORTB , GPIO_PIN4 )==GPIO_HIGH)
		{
			if(MGPIO_u8GetPinValue( GPIO_PORTB , GPIO_PIN4 )==GPIO_HIGH)
			{MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH);}
			
			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN2, GPIO_HIGH);
			MSTK_voidSetBusyWait(100);
			MGPIO_VoidSetPin_Value(GPIO_PORTA, GPIO_PIN2, GPIO_LOW);
			MSTK_voidSetBusyWait(100);
		}
	}
}

#endif
