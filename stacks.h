#pragma once
#include"errors.h"
//����� ������� ��� ������ �� �������
#define SIZE 1//��������� ������ ������

typedef double elem_t;//����������� �������� �����
typedef char elem_t_c;//����������� �������� ��������
typedef struct{
	elem_t* data;
	int top;
	int size;
}stack_t_num;//����������� ����� ��� ����� 
typedef struct{
	elem_t_c* data;
	int top;
	int size;
}stack_t_char;//����������� ����� ��� ��������

stack_t_num* StackCreateNum();//�������� ����� �����
stack_t_char* StackCreateChar();//�������� ����� ��������
void StackDeleteNum(stack_t_num* n);//�������� ����� �����
void StackDeleteChar(stack_t_char* n);//�������� ����� ��������
//������� PushNum/PushChar ������ ������� �� �������� �����
void StackPushNum(stack_t_num* n, elem_t num, error_t* err);
void StackPushChar(stack_t_char* n, elem_t_c num, error_t* err);
//������� PopNum/PopChar ��������� ������� �� �������� �����
void StackPopNum(stack_t_num* n, elem_t* a, error_t* err);
void StackPopChar(stack_t_char* n, elem_t_c* a, error_t* err);
//������� TopNum/TopChar ���������� � ���������� ������� ������� �� �������� �����
elem_t StackTopNum(stack_t_num* n);
elem_t_c StackTopChar(stack_t_char* n);

