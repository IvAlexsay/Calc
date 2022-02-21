#include"stacks.h"
#include"errors.h"
#include<stdio.h>
#include<stdlib.h>

stack_t_num* StackCreateNum() {
	stack_t_num* n = NULL;
	n = (stack_t_num*)malloc(sizeof(stack_t_num));
	if (n == NULL) {
		free(n);
		return NULL;
	}
	n->size = SIZE;
	n->top = 0;
	n->data = (elem_t*)malloc(sizeof(elem_t) * SIZE);
	if (n->data == NULL) {
		free(n);
		return NULL;
	}
	return n;
}
stack_t_char* StackCreateChar() {
	stack_t_char* n = NULL;
	n = (stack_t_char*)malloc(sizeof(stack_t_char));
	if (n == NULL) {
		free(n);
		return NULL;
	}
	n->size = SIZE;
	n->top = 0;
	n->data = (elem_t_c*)malloc(sizeof(elem_t_c) * SIZE);
	if (n->data == NULL) {
		free(n);
		return NULL;
	}
	return n;
}
void StackDeleteNum(stack_t_num* n) {
	if (n != NULL) {
		free(n->data);
		free(n);
	}
}
void StackDeleteChar(stack_t_char* n) {
	if (n != NULL) {
		free(n->data);
		free(n);
	}
}

void StackPushNum(stack_t_num* n, elem_t num, error_t* err) {
	elem_t* buf;
	if (n->top == n->size) {
		n->size++;
		buf = (elem_t*)realloc(n->data, sizeof(elem_t) * n->size);
		if (buf == NULL) {
			*err = NMEMORY;
		}
		else {
			n->data = buf;
			n->data[n->top] = num;
			n->top++;
		}
	}
	else {
		n->data[n->top] = num;
		n->top++;
	}
}
void StackPushChar(stack_t_char* n, elem_t_c num, error_t* err) {
	elem_t_c* buf;
	if (n->top == n->size) {
		n->size++;
		buf = (elem_t_c*)realloc(n->data, sizeof(elem_t_c) * n->size);
		if (buf == NULL) {
			*err = NMEMORY;
		}
		else {
			n->data = buf;
			n->data[n->top] = num;
			n->top++;
		}
	}
	else {
		n->data[n->top] = num;
		n->top++;
	}
}

void StackPopNum(stack_t_num* n, elem_t* a, error_t* err) {
	if (n->top == 0) {
		*err = STACKEMPTY;
	}
	else {
		*a = n->data[n->top - 1];
		n->top--;
	}
}
void StackPopChar(stack_t_char* n, elem_t_c* a, error_t* err) {
	if (n->top == 0) {
		*err = STACKEMPTY;
	}
	else {
		*a = n->data[n->top - 1];
		n->top--;
	}
}

elem_t StackTopNum(stack_t_num* n) {
	return n->data[n->top - 1];
}
elem_t_c StackTopChar(stack_t_char* n) {
	return n->data[n->top - 1];
}
