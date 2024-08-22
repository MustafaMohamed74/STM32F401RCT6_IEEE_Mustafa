/*
 * LCD_Program.c
 *
 *  Created on: Aug 23, 2024
 *      Author: 20128
 */
#include "../LIB/STD_Types.h"
#include "../LIB/Bit_Math.h"
#include "../SYSTICK_Driver/SYSTICK_Interface.h"
#include "../GPIO_Driver/GPIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"

void GPIO_PINS_INIT(void){

	GPIO_Pin_Cofig RS ={CONTROL_PORT,RS_PIN,GPIO_Speed_Medium,GPIO_PIN_OUTPUT,GPIO_OUTPUT_PushPull};
	GPIO_Pin_Cofig RW ={CONTROL_PORT,RW_PIN,GPIO_Speed_Medium,GPIO_PIN_OUTPUT,GPIO_OUTPUT_PushPull};
	GPIO_Pin_Cofig EN ={CONTROL_PORT,E_PIN,GPIO_Speed_Medium,GPIO_PIN_OUTPUT,GPIO_OUTPUT_PushPull};

	GPIO_Pin_Cofig DATA_D4 ={DATA_PORT,DATA_D4_PIN,GPIO_Speed_Medium,GPIO_PIN_OUTPUT,GPIO_OUTPUT_PushPull};
	GPIO_Pin_Cofig DATA_D5 ={DATA_PORT,DATA_D5_PIN,GPIO_Speed_Medium,GPIO_PIN_OUTPUT,GPIO_OUTPUT_PushPull};
	GPIO_Pin_Cofig DATA_D6 ={DATA_PORT,DATA_D6_PIN,GPIO_Speed_Medium,GPIO_PIN_OUTPUT,GPIO_OUTPUT_PushPull};
	GPIO_Pin_Cofig DATA_D7 ={DATA_PORT,DATA_D7_PIN,GPIO_Speed_Medium,GPIO_PIN_OUTPUT,GPIO_OUTPUT_PushPull};

	GPIO_PinConfig(&RS);
	GPIO_PinConfig(&RW);
	GPIO_PinConfig(&EN);

	GPIO_PinConfig(&DATA_D4);
	GPIO_PinConfig(&DATA_D5);
	GPIO_PinConfig(&DATA_D6);
	GPIO_PinConfig(&DATA_D7);

}
void LCD_Init(void){
#if LCD_Mode == LCD_8Bit_Mode

	GPIO_PINS_INIT();
	SYSTICK_delayMilliSeconds(30);

	LCD_Write_Command(lcd_FunctionSet8bit);

	SYSTICK_delayMilliSeconds(3);

	LCD_Write_Command(lcd_DisplayOn);

	SYSTICK_delayMilliSeconds(3);

	LCD_Write_Command(lcd_Clear);

	SYSTICK_delayMilliSeconds(3);

	LCD_Write_Command(lcd_EntryMode);

	SYSTICK_delayMilliSeconds(3);

	LCD_Write_Command(lcd_Home);

	SYSTICK_delayMilliSeconds(3);
#elif LCD_Mode == LCD_4Bit_Mode
	GPIO_PINS_INIT();

	SYSTICK_delayMilliSeconds(30);

	LCD_Write_Command(0X02);
	LCD_Write_Command(0X28);
	SYSTICK_delayMilliSeconds(3);

	LCD_Write_Command(lcd_DisplayOn);

	SYSTICK_delayMilliSeconds(3);

	LCD_Write_Command(lcd_Clear);

	SYSTICK_delayMilliSeconds(3);

	LCD_Write_Command(lcd_EntryMode);

	SYSTICK_delayMilliSeconds(3);

	LCD_Write_Command(lcd_Home);

	SYSTICK_delayMilliSeconds(3);

#endif

}

void LCD_Write_Command(uint8 Command){
#if LCD_Mode == LCD_8Bit_Mode
	GPIO_SetPinValue(CONTROL_PORT,RS_PIN,PIN_LOW);
	GPIO_SetPinValue(CONTROL_PORT,RW_PIN,PIN_LOW);
	GPIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_LOW);

	DIO_SetPortValue(DATA_PORT,Command);//0b00110011

	SYSTICK_delayMilliSeconds(3);
	GPIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_HIGH);
	SYSTICK_delayMilliSeconds(3);
	GPIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_LOW);
#elif LCD_Mode == LCD_4Bit_Mode
	GPIO_SetPinValue(CONTROL_PORT,RS_PIN,GPIO_Pin_LOW);
	GPIO_SetPinValue(CONTROL_PORT,RW_PIN,GPIO_Pin_LOW);
	GPIO_SetPinValue(CONTROL_PORT,E_PIN,GPIO_Pin_LOW);


	// Send upper nibble
	GPIO_SetPinValue(DATA_PORT, DATA_D7_PIN, Get_Bit(Command, 7));
	GPIO_SetPinValue(DATA_PORT, DATA_D6_PIN, Get_Bit(Command, 6));
	GPIO_SetPinValue(DATA_PORT, DATA_D5_PIN, Get_Bit(Command, 5));
	GPIO_SetPinValue(DATA_PORT, DATA_D4_PIN, Get_Bit(Command, 4));
	GPIO_SetPinValue(CONTROL_PORT, E_PIN, GPIO_Pin_High);
	SYSTICK_delayMilliSeconds(3);  // Short delay
	GPIO_SetPinValue(CONTROL_PORT, E_PIN, GPIO_Pin_LOW);
	SYSTICK_delayMilliSeconds(3);  // Delay for processing

	// Send lower nibble
	GPIO_SetPinValue(DATA_PORT, DATA_D7_PIN, Get_Bit(Command, 3));
	GPIO_SetPinValue(DATA_PORT, DATA_D6_PIN, Get_Bit(Command, 2));
	GPIO_SetPinValue(DATA_PORT, DATA_D5_PIN, Get_Bit(Command, 1));
	GPIO_SetPinValue(DATA_PORT, DATA_D4_PIN, Get_Bit(Command, 0));
	GPIO_SetPinValue(CONTROL_PORT, E_PIN, GPIO_Pin_High);
	SYSTICK_delayMilliSeconds(3);  // Short delay
	GPIO_SetPinValue(CONTROL_PORT, E_PIN, GPIO_Pin_LOW);
	SYSTICK_delayMilliSeconds(3);  // Delay for processing

#endif
}

void LCD_Write_Data(uint8 Data){
#if LCD_Mode == LCD_8Bit_Mode

	GPIO_SetPinValue(CONTROL_PORT,RS_PIN,PIN_HIGH);
	GPIO_SetPinValue(CONTROL_PORT,RW_PIN,PIN_LOW);
	GPIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_LOW);

	DIO_SetPortValue(DATA_PORT,Data);

	SYSTICK_delayMilliSeconds(3);
	GPIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_HIGH);
	SYSTICK_delayMilliSeconds(3);
	GPIO_SetPinValue(CONTROL_PORT,E_PIN,PIN_LOW);
#elif LCD_Mode == LCD_4Bit_Mode

	GPIO_SetPinValue(CONTROL_PORT,RS_PIN,GPIO_Pin_High);
	GPIO_SetPinValue(CONTROL_PORT,RW_PIN,GPIO_Pin_LOW);
	GPIO_SetPinValue(CONTROL_PORT,E_PIN,GPIO_Pin_LOW);

	GPIO_SetPinValue(DATA_PORT,DATA_D7_PIN,Get_Bit(Data,7));
	GPIO_SetPinValue(DATA_PORT,DATA_D6_PIN,Get_Bit(Data,6));
	GPIO_SetPinValue(DATA_PORT,DATA_D5_PIN,Get_Bit(Data,5));
	GPIO_SetPinValue(DATA_PORT,DATA_D4_PIN,Get_Bit(Data,4));
	//	DIO_SetPortValue(DATA_PORT,Data);

	GPIO_SetPinValue(CONTROL_PORT,E_PIN,GPIO_Pin_High);
	SYSTICK_delayMilliSeconds(3);
	GPIO_SetPinValue(CONTROL_PORT,E_PIN,GPIO_Pin_LOW);
	SYSTICK_delayMilliSeconds(3);
	GPIO_SetPinValue(DATA_PORT,DATA_D7_PIN,Get_Bit(Data,3));
	GPIO_SetPinValue(DATA_PORT,DATA_D6_PIN,Get_Bit(Data,2));
	GPIO_SetPinValue(DATA_PORT,DATA_D5_PIN,Get_Bit(Data,1));
	GPIO_SetPinValue(DATA_PORT,DATA_D4_PIN,Get_Bit(Data,0));
	//	DIO_SetPortValue(DATA_PORT,Data<<4);

	GPIO_SetPinValue(CONTROL_PORT,E_PIN,GPIO_Pin_High);
	SYSTICK_delayMilliSeconds(3);
	GPIO_SetPinValue(CONTROL_PORT,E_PIN,GPIO_Pin_LOW);
	SYSTICK_delayMilliSeconds(3);
#endif
}

void LCD_Write_String(uint8 * Str, uint8 Length){
	uint8 i=0;
	for(i=0;i<Length;i++){
		LCD_Write_Data(Str[i]);
	}
}

void LCD_Go_To(uint8 y,uint8 x){
	LCD_Write_Command((128+(y*0x40)+x));
}

void LCD_special_char(void){
	/* Char 1 */
	LCD_Write_Command(0b01000000);
	LCD_Write_Data(0b11101010);
	LCD_Write_Data(0b11011111);
	LCD_Write_Data(0b11111111);
	LCD_Write_Data(0b11111111);
	LCD_Write_Data(0b11111111);
	LCD_Write_Data(0b11101110);
	LCD_Write_Data(0b11100100);
	LCD_Write_Data(0b11110000);

	/* Char 2 */
	LCD_Write_Data(0b11111111);
	LCD_Write_Data(0b11111111);
	LCD_Write_Data(0b11111111);
	LCD_Write_Data(0b11111111);
	LCD_Write_Data(0b11111111);
	LCD_Write_Data(0b11111111);
	LCD_Write_Data(0b11111111);
	LCD_Write_Data(0b11111111);
	/* Char 3 */
	LCD_Write_Data(0b11101110);
	LCD_Write_Data(0b11101110);
	LCD_Write_Data(0b11100100);
	LCD_Write_Data(0b11101110);
	LCD_Write_Data(0b11110101);
	LCD_Write_Data(0b11100100);
	LCD_Write_Data(0b11101110);
	LCD_Write_Data(0b11110001);
	/* Char 4 */

	/* Char 5 */

	/* Char 6 */

	/* Char 7 */

	/* Char 8 */

}

//void LCD_Write_Number(uint32 Copy_Num){
//	uint32 rev=0;
//	uint8 i=0 ;
//	while (Copy_Num > 0)
//	{
//		rev = rev * 10;
//		rev = rev + Copy_Num%10;
//		Copy_Num = Copy_Num /10;
//		i++;
//	}
//	uint16  separated=0 ;
//	uint16 arr[i];
//	i=0;
//	//	if(rev==0){
//	//		LCD_Write_Data('0');
//	//	}
//	//	else{
//	while(rev!=0){
//		separated =rev%10;
//		arr[i]=separated;
//		LCD_Write_Data(separated+'0');
//		rev/=10;
//		i++;
//		//	}
//	}
//}
