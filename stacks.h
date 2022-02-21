#pragma once
#include"errors.h"
//Набор функций для работы со стеками
#define SIZE 1//Начальный размер стеков

typedef double elem_t;//Определение элемента числа
typedef char elem_t_c;//Определение элемента символов
typedef struct{
	elem_t* data;
	int top;
	int size;
}stack_t_num;//Определение стека для чисел 
typedef struct{
	elem_t_c* data;
	int top;
	int size;
}stack_t_char;//Определение стека для символов

stack_t_num* StackCreateNum();//Создание стека чисел
stack_t_char* StackCreateChar();//Создание стека символов
void StackDeleteNum(stack_t_num* n);//Удаление стека чисел
void StackDeleteChar(stack_t_char* n);//Удаление стека символов
//Функции PushNum/PushChar кладут элемент на верхушку стека
void StackPushNum(stack_t_num* n, elem_t num, error_t* err);
void StackPushChar(stack_t_char* n, elem_t_c num, error_t* err);
//Функции PopNum/PopChar извлекают элемент из верхушки стека
void StackPopNum(stack_t_num* n, elem_t* a, error_t* err);
void StackPopChar(stack_t_char* n, elem_t_c* a, error_t* err);
//Функции TopNum/TopChar показывают и возвращают элемент лежащий на верхушке стека
elem_t StackTopNum(stack_t_num* n);
elem_t_c StackTopChar(stack_t_char* n);

