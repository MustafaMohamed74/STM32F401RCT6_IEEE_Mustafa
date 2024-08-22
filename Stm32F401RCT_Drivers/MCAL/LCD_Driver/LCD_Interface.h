/*
 * LCD_Interface.h
 *
 *  Created on: Aug 23, 2024
 *      Author: 20128
 */

#ifndef LCD_DRIVER_LCD_INTERFACE_H_
#define LCD_DRIVER_LCD_INTERFACE_H_

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

void LCD_Init(void);
void LCD_Write_Command(uint8 Command);
void LCD_Write_Data(uint8 Data);
void LCD_Write_String(uint8 * Str, uint8 Length);
void LCD_Go_To(uint8 y,uint8 x);
void LCD_Arabic(uint8 y,uint8 x);
void LCD_Send_SpecialChar(uint8 Copy_Char);
void LCD_Write_Number(uint32 Copy_Num);
uint8 LCD_GOTO_XY(uint8 Copy_lineNum , uint8 Copy_Location);

void GPIO_PINS_INIT(void);

typedef enum {
    ASCII_NULL = 0,
    ASCII_START_OF_HEADER = 1,
    ASCII_START_OF_TEXT = 2,
    ASCII_END_OF_TEXT = 3,
    ASCII_END_OF_TRANSMISSION = 4,
    ASCII_ENQUIRY = 5,
    ASCII_ACKNOWLEDGE = 6,
    ASCII_BEL = 7,
    ASCII_BACKSPACE = 8,
    ASCII_HORIZONTAL_TAB = 9,
    ASCII_LINE_FEED = 10,
    ASCII_VERTICAL_TAB = 11,
    ASCII_FORM_FEED = 12,
    ASCII_CARRIAGE_RETURN = 13,
    ASCII_SHIFT_OUT = 14,
    ASCII_SHIFT_IN = 15,
    ASCII_DATA_LINK_ESCAPE = 16,
    ASCII_DEVICE_CONTROL_1 = 17,
    ASCII_DEVICE_CONTROL_2 = 18,
    ASCII_DEVICE_CONTROL_3 = 19,
    ASCII_DEVICE_CONTROL_4 = 20,
    ASCII_NEGATIVE_ACKNOWLEDGE = 21,
    ASCII_SYNCHRONOUS_IDLE = 22,
    ASCII_END_OF_TRANSMISSION_BLOCK = 23,
    ASCII_CANCEL = 24,
    ASCII_END_OF_MEDIUM = 25,
    ASCII_SUBSTITUTE = 26,
    ASCII_ESCAPE = 27,
    ASCII_FILE_SEPARATOR = 28,
    ASCII_GROUP_SEPARATOR = 29,
    ASCII_RECORD_SEPARATOR = 30,
    ASCII_UNIT_SEPARATOR = 31,
    ASCII_SPACE = 32,
    ASCII_EXCLAMATION_MARK = 33,
    ASCII_DOUBLE_QUOTE = 34,
    ASCII_HASH = 35,
    ASCII_DOLLAR = 36,
    ASCII_PERCENT = 37,
    ASCII_AMPERSAND = 38,
    ASCII_SINGLE_QUOTE = 39,
    ASCII_LEFT_PARENTHESIS = 40,
    ASCII_RIGHT_PARENTHESIS = 41,
    ASCII_ASTERISK = 42,
    ASCII_PLUS = 43,
    ASCII_COMMA = 44,
    ASCII_MINUS = 45,
    ASCII_PERIOD = 46,
    ASCII_SLASH = 47,
    ASCII_0 = 48,
    ASCII_1 = 49,
    ASCII_2 = 50,
    ASCII_3 = 51,
    ASCII_4 = 52,
    ASCII_5 = 53,
    ASCII_6 = 54,
    ASCII_7 = 55,
    ASCII_8 = 56,
    ASCII_9 = 57,
    ASCII_COLON = 58,
    ASCII_SEMICOLON = 59,
    ASCII_LESS_THAN = 60,
    ASCII_EQUAL = 61,
    ASCII_GREATER_THAN = 62,
    ASCII_QUESTION_MARK = 63,
    ASCII_AT = 64,
    ASCII_A = 65,
    ASCII_B = 66,
    ASCII_C = 67,
    ASCII_D = 68,
    ASCII_E = 69,
    ASCII_F = 70,
    ASCII_G = 71,
    ASCII_H = 72,
    ASCII_I = 73,
    ASCII_J = 74,
    ASCII_K = 75,
    ASCII_L = 76,
    ASCII_M = 77,
    ASCII_N = 78,
    ASCII_O = 79,
    ASCII_P = 80,
    ASCII_Q = 81,
    ASCII_R = 82,
    ASCII_S = 83,
    ASCII_T = 84,
    ASCII_U = 85,
    ASCII_V = 86,
    ASCII_W = 87,
    ASCII_X = 88,
    ASCII_Y = 89,
    ASCII_Z = 90,
    ASCII_LEFT_BRACKET = 91,
    ASCII_BACKSLASH = 92,
    ASCII_RIGHT_BRACKET = 93,
    ASCII_CARET = 94,
    ASCII_UNDERSCORE = 95,
    ASCII_BACKTICK = 96,
    ASCII_a = 97,
    ASCII_b = 98,
    ASCII_c = 99,
    ASCII_d = 100,
    ASCII_e = 101,
    ASCII_f = 102,
    ASCII_g = 103,
    ASCII_h = 104,
    ASCII_i = 105,
    ASCII_j = 106,
    ASCII_k = 107,
    ASCII_l = 108,
    ASCII_m = 109,
    ASCII_n = 110,
    ASCII_o = 111,
    ASCII_p = 112,
    ASCII_q = 113,
    ASCII_r = 114,
    ASCII_s = 115,
    ASCII_t = 116,
    ASCII_u = 117,
    ASCII_v = 118,
    ASCII_w = 119,
    ASCII_x = 120,
    ASCII_y = 121,
    ASCII_z = 122,
    ASCII_LEFT_BRACE = 123,
    ASCII_VERTICAL_BAR = 124,
    ASCII_RIGHT_BRACE = 125,
    ASCII_TILDE = 126,
    ASCII_DELETE = 127
} ASCII_Character;

#endif /* LCD_DRIVER_LCD_INTERFACE_H_ */
