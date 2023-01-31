/*
 * dio_src.c
 *
 *  Created on: Dec 23, 2022
 *      Author: thund
 */

#include "../../SERV/bit_math.h"
#include "../../SERV/stdtypes.h"
#include "dio_reg.h"
#include "dio_int.h"


uint8 DIO_u8Set_Port_Dir(uint8 u8PortIdCopy , uint8 u8DirCopy)
{
	uint8 Error_Status=E_OK;

		switch(u8PortIdCopy)
		{
			case PORT_A :	DDRA_REG = u8DirCopy;
										break;
			case PORT_B :	DDRB_REG = u8DirCopy;
										break;
			case PORT_C :	DDRC_REG = u8DirCopy;
										break;
			case PORT_D :	DDRD_REG = u8DirCopy;
										break;
			default		:	Error_Status = E_NOK ;
										break;

		}



	return Error_Status;
}
uint8 DIO_u8Set_Port_Val(uint8 u8PortIdCopy , uint8 u8ValCopy)
{
	uint8 Error_Status=E_OK;


			switch(u8PortIdCopy)
			{
				case PORT_A :	PORTA_REG = u8ValCopy;
											break;
				case PORT_B :	PORTB_REG =	u8ValCopy;
											break;
				case PORT_C :	PORTC_REG = u8ValCopy;
											break;
				case PORT_D :	PORTD_REG = u8ValCopy;
											break;
				default		:	Error_Status=E_NOK;
											break;

			}



	return Error_Status;

}
uint8 DIO_u8Get_Port_Val(uint8 u8PortIdCopy , uint8 * u8pValCopy)
{
	uint8 Error_Status=E_OK;


				switch(u8PortIdCopy)
				{
					case PORT_A :	*u8pValCopy = PINA_REG;
												break;
					case PORT_B :	*u8pValCopy = PINB_REG;
												break;
					case PORT_C :	*u8pValCopy = PINC_REG;
												break;
					case PORT_D :	*u8pValCopy = PIND_REG;
												break;
					default		:	Error_Status=E_NOK;
												break;

				}
	return Error_Status;

}
uint8 DIO_u8TOG_PORT_Val (uint8  u8PortIdCopy 	)
{
	uint8 Error_Status=E_OK;

		switch(u8PortIdCopy)
			{
				case PORT_A :	PORTA_REG = ~PORTA_REG;
													break;
				case PORT_B :	PORTB_REG = ~PORTB_REG;
													break;
				case PORT_C :	PORTC_REG = ~PORTC_REG;
													break;
				case PORT_D :	PORTD_REG = ~PORTD_REG;
													break;
				default		:	Error_Status=E_NOK;
													break;

			}









	return Error_Status;

}

uint8 DIO_u8Set_Pin_Dir(uint8 u8PortIdCopy ,uint8 u8Pin_IdCopy ,uint8 u8DirCopy)
{
	uint8 Error_Status=E_OK;

	if((u8Pin_IdCopy>=PIN_0)&&(u8Pin_IdCopy<=PIN_7))
	{
		if(u8DirCopy==INPUT)
		{
			switch(u8PortIdCopy)
				{
					case PORT_A :	CLR_BIT(DDRA_REG,u8Pin_IdCopy);
													break;
					case PORT_B :	CLR_BIT(DDRB_REG,u8Pin_IdCopy);
													break;
					case PORT_C :	CLR_BIT(DDRC_REG,u8Pin_IdCopy);
													break;
					case PORT_D :	CLR_BIT(DDRD_REG,u8Pin_IdCopy);
													break;
					default		:	Error_Status=E_NOK;
													break;

				}
		}
		else if(u8DirCopy==OUTPUT)
		{
			switch(u8PortIdCopy)
				{
					case PORT_A :	SET_BIT(DDRA_REG,u8Pin_IdCopy);
													break;
					case PORT_B :	SET_BIT(DDRB_REG,u8Pin_IdCopy);
													break;
					case PORT_C :	SET_BIT(DDRC_REG,u8Pin_IdCopy);
													break;
					case PORT_D :	SET_BIT(DDRD_REG,u8Pin_IdCopy);
													break;
					default		:	Error_Status=E_NOK;
													break;
					}
				}

		else
		{
			Error_Status=E_NOK;
		}
	}
	else
	{
		Error_Status=E_NOK;
	}


	return Error_Status;


}
uint8 DIO_u8Set_Pin_Val(uint8 u8PortIdCopy ,uint8 u8Pin_IdCopy ,uint8 u8ValCopy)
{
	uint8 Error_Status=E_OK;

	if((u8Pin_IdCopy>=PIN_0)&&(u8Pin_IdCopy<=PIN_7))
	{
		if(u8ValCopy==LOW)
		{
			switch(u8PortIdCopy)
				{
					case PORT_A :	CLR_BIT(PORTA_REG,u8Pin_IdCopy);
													break;
					case PORT_B :	CLR_BIT(PORTB_REG,u8Pin_IdCopy);
													break;
					case PORT_C :	CLR_BIT(PORTC_REG,u8Pin_IdCopy);
													break;
					case PORT_D :	CLR_BIT(PORTD_REG,u8Pin_IdCopy);
													break;
					default		:	Error_Status=E_NOK;
													break;

				}
		}
		else if(u8ValCopy==HIGH)
		{
			switch(u8PortIdCopy)
				{
					case PORT_A :	SET_BIT(PORTA_REG,u8Pin_IdCopy);
													break;
					case PORT_B :	SET_BIT(PORTB_REG,u8Pin_IdCopy);
													break;
					case PORT_C :	SET_BIT(PORTC_REG,u8Pin_IdCopy);
													break;
					case PORT_D :	SET_BIT(PORTD_REG,u8Pin_IdCopy);
													break;
					default		:	Error_Status=E_NOK;
													break;

				}
		}

		else
		{
			Error_Status=E_NOK;
		}
	}
	else
	{
		Error_Status=E_NOK;
	}


	return Error_Status;
}
uint8 DIO_u8Get_Pin_Val(uint8 u8PortIdCopy ,uint8 u8Pin_IdCopy ,uint8 * u8pValCopy)
{
	uint8 Error_Status=E_OK;

		if((u8Pin_IdCopy>=PIN_0)&&(u8Pin_IdCopy<=PIN_7))
		{

			switch(u8PortIdCopy)
				{
					case PORT_A : *u8pValCopy=GET_BIT(PINA_REG,u8Pin_IdCopy);
													break;
					case PORT_B : *u8pValCopy=GET_BIT(PINB_REG,u8Pin_IdCopy);
													break;
					case PORT_C : *u8pValCopy=GET_BIT(PINC_REG,u8Pin_IdCopy);
													break;
					case PORT_D : *u8pValCopy=GET_BIT(PIND_REG,u8Pin_IdCopy);
													break;
					default		:	Error_Status=E_NOK;
													break;

				}

		}
		else
		{
			Error_Status=E_NOK;
		}

	return Error_Status;

}
uint8 DIO_u8TOG_Pin_Val(uint8 u8PortIdCopy ,uint8 u8Pin_IdCopy )
{
	uint8 Error_Status=E_OK;

		if((u8Pin_IdCopy>=PIN_0)&&(u8Pin_IdCopy<=PIN_7))
		{

			switch(u8PortIdCopy)
				{
					case PORT_A : TOGGLE_BIT(PORTA_REG,u8Pin_IdCopy);
																		break;
					case PORT_B : TOGGLE_BIT(PORTB_REG,u8Pin_IdCopy);
																		break;
					case PORT_C : TOGGLE_BIT(PORTC_REG,u8Pin_IdCopy);
																		break;
					case PORT_D : TOGGLE_BIT(PORTD_REG,u8Pin_IdCopy);
																		break;
					default		:	Error_Status=E_NOK;
																		break;

				}

		}
		else
		{
			Error_Status=E_NOK;
		}

	return Error_Status;

}

