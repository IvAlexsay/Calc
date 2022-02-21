#pragma once
#include"stacks.h"
#include"errors.h"
//Набор функций для вычислений

#define PI 3.1415926535897932384626
#define E 2.71828182845904523536028747

elem_t_c AnalyzeWords(char* str, int* i, error_t* err);//Функция для определения арифметических элементов из строки
void WordToStack(elem_t_c symb, stack_t_char* sign, stack_t_num* nums, error_t* err);//Функция для распределения элементов, определенных в функции AnalyzeWords, по стакам.
int CheckPriority(elem_t_c sign);//Функция для определения приоритета операции
elem_t CalcFunc(elem_t a, elem_t_c sign, error_t* err);//Функция для вычисления арифметических функций
elem_t Calculate(elem_t a, elem_t b, elem_t_c sign);//Функция для вычисления стандартных операций
void CalcBracket(stack_t_char* sign, stack_t_num* nums, error_t* err);//Функция для вычисления выражения в скобках
void CalcDegree(stack_t_char* sign, stack_t_num* nums, error_t* err);//Функция для вычисления степеней(создана из-зи правой ассоциативности степени)

elem_t FinalCalc(stack_t_char* sign, stack_t_num* nums, error_t* err);//Функция для окончательного вычисления выражения, распределенного по стекам, в котором предварительно выполнены все возможные равноприоритетные вычисления.
int WorkWithStr(char* str, int len, stack_t_char* sign, stack_t_num* nums, error_t* err);//Функция обработки строки 
elem_t Calculation(char* str, int length, error_t* err);//Главная функция инициализиующая работу с модулем вычислений