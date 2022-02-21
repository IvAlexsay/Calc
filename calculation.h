#pragma once
#include"stacks.h"
#include"errors.h"
//����� ������� ��� ����������

#define PI 3.1415926535897932384626
#define E 2.71828182845904523536028747

elem_t_c AnalyzeWords(char* str, int* i, error_t* err);//������� ��� ����������� �������������� ��������� �� ������
void WordToStack(elem_t_c symb, stack_t_char* sign, stack_t_num* nums, error_t* err);//������� ��� ������������� ���������, ������������ � ������� AnalyzeWords, �� ������.
int CheckPriority(elem_t_c sign);//������� ��� ����������� ���������� ��������
elem_t CalcFunc(elem_t a, elem_t_c sign, error_t* err);//������� ��� ���������� �������������� �������
elem_t Calculate(elem_t a, elem_t b, elem_t_c sign);//������� ��� ���������� ����������� ��������
void CalcBracket(stack_t_char* sign, stack_t_num* nums, error_t* err);//������� ��� ���������� ��������� � �������
void CalcDegree(stack_t_char* sign, stack_t_num* nums, error_t* err);//������� ��� ���������� ��������(������� ��-�� ������ ��������������� �������)

elem_t FinalCalc(stack_t_char* sign, stack_t_num* nums, error_t* err);//������� ��� �������������� ���������� ���������, ��������������� �� ������, � ������� �������������� ��������� ��� ��������� ����������������� ����������.
int WorkWithStr(char* str, int len, stack_t_char* sign, stack_t_num* nums, error_t* err);//������� ��������� ������ 
elem_t Calculation(char* str, int length, error_t* err);//������� ������� ��������������� ������ � ������� ����������