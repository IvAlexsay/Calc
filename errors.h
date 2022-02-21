#ifndef ERRORS_H   
#define ERRORS_H
typedef enum{
	OKEY,
	NMEMORY,
	STACKEMPTY,
	WRONGSYMBOL,
	DIVISIONBYZERO,
	BRACKETS,
	FUNCTION,
	STRSPORCOM
}error_t;//Тип перечесления ошибок

static char err_s[7][25] = {
	"OKEY\n","Not enought memory\n", 
	"Problem in expression\n",
	"Wrong symbol\n", 
	"Division by zero\n", 
	"Problem-bracket\n", 
	"Error in function\n"
};//Массив строк для вывода ошибок пользователю
#endif