#include"calculation.h"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<float.h>
#include"read1print.h"
#include"stacks.h"
#include"errors.h"

elem_t_c AnalyzeWords(char* str, int* i, error_t* err) {
	if (str[*i] == 'p' && str[*i + 1] == 'i') {
		*i += 1;
		return 'p';//p - pi
	}
	if (str[*i] == 'e') {
		return 'e';//e - экспонента
	}
	if (str[*i] == 's' && str[*i + 1] == 'q' && str[*i + 2] == 'r' && str[*i + 3] == 't') {
		*i += 3;
		return 'q';//q - sqrt
	}
	if (str[*i] == 's' && str[*i + 1] == 'i' && str[*i + 2] == 'n') {
		*i += 2;
		return 's';//s - sin
	}
	if (str[*i] == 'c' && str[*i + 1] == 'o' && str[*i + 2] == 's') {
		*i += 2;
		return 'c';//c - cos
	}
	if (str[*i] == 't' && str[*i + 1] == 'g') {
		*i += 1;
		return 't';//t - tg
	}
	if (str[*i] == 'c' && str[*i + 1] == 't' && str[*i + 2] == 'g') {
		*i += 2;
		return 'g';//g - ctg
	}
	if (str[*i] == 'l' && str[*i + 1] == 'n') {
		*i += 1;
		return 'l';//l - ln
	}
	if (str[*i] == 'f' && str[*i + 1] == 'l' && str[*i + 2] == 'o' && str[*i + 3] == 'o' && str[*i + 4] == 'r') {
		*i += 4;
		return 'f';//f - floor
	}
	if (str[*i] == 'c' && str[*i + 1] == 'e' && str[*i + 2] == 'i' && str[*i + 3] == 'l') {
		*i += 3;
		return 'i';//i - ceil
	}
	if (str[*i] == 'a' && str[*i + 1] == 'r' && str[*i + 2] == 'c' && str[*i + 3] == 't' && str[*i + 4] == 'g') {
		*i += 4;
		return 'a';//a - arctg
	}
	if (str[*i] == 'a' && str[*i + 1] == 'r' && str[*i + 2] == 'c' && str[*i + 3] == 'c' && str[*i + 4] == 'o' && str[*i + 5] == 's') {
		*i += 5;
		return 'o';//o - arccos
	}
	if (str[*i] == 'a' && str[*i + 1] == 'r' && str[*i + 2] == 'c' && str[*i + 3] == 's' && str[*i + 4] == 'i' && str[*i + 5] == 'n') {
		*i += 5;
		return 'n';//n - arcsin
	}
	*err = WRONGSYMBOL;
	return 'E';
}
void WordToStack(elem_t_c symb, stack_t_char* sign, stack_t_num* nums, error_t* err) {
	if (symb == 'p' || symb == 'e') {
		if (symb == 'p') {
			StackPushNum(nums, PI, err);
		}
		else {
			StackPushNum(nums, E, err);
		}
	}
	else {
		StackPushChar(sign, symb, err);
	}
}
int CheckPriority(elem_t_c sign) {
	switch (sign) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '~':
		return 3;
	case '^':
		return 4;
	case 'q':
	case 's':
	case 'c':
	case 't':
	case 'g':
	case 'l':
	case 'f':
	case 'i':
	case 'a':
	case 'o':
	case 'n':
		return 5;
	case '(':
	case ')':
		return 0;
	}
	return 0;
}
elem_t CalcFunc(elem_t a, elem_t_c sign, error_t* err) {
	switch (sign) {
	case '~':
		return a * (-1);
	case 'q':
		if (a < 0) {
			*err = FUNCTION;
			return -1;
		}
		return (elem_t)sqrt((double)a);
	case 's':
		return (elem_t)sin((double)a);
	case 'c':
		return (elem_t)cos((double)a);
	case 't':
		if (cos(a) == 0) {
			*err = FUNCTION;
			return -1;
		}
		return (elem_t)tan((double)a);
	case 'g':
		if (sin(a) == 0) {
			*err = FUNCTION;
			return -1;
		}
		return 1 / ((elem_t)tan((double)a));
	case 'f':
		return (elem_t)floor((double)a);
	case 'i':
		return (elem_t)ceil((double)a);
	case 'l':
		if (a <= 0) {
			*err = FUNCTION;
			return -1;
		}
		return (elem_t)log((double)a);
	case 'a':
		return (elem_t)atan((double)a);
	case 'o':
		if (a > 1 || a < -1) {
			*err = FUNCTION;
			return -1;
		}
		return (elem_t)acos((double)a);
	case 'n':
		if (a > 1 || a < -1) {
			*err = FUNCTION;
			return -1;
		}
		return (elem_t)asin((double)a);
	}
	return 'E';
}
elem_t Calculate(elem_t a, elem_t b, elem_t_c sign) {
	switch (sign) {
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	case '^':
		return pow(a, b);
	}
	return 0;
}
void CalcBracket(stack_t_char* sign, stack_t_num* nums, error_t* err) {
	elem_t a, b;
	elem_t_c sn;
	while (StackTopChar(sign) != '(') {
		if (CheckPriority(StackTopChar(sign)) == 5 || CheckPriority(StackTopChar(sign)) == 3) {
			StackPopChar(sign, &sn, err);
			StackPopNum(nums, &a, err);
			StackPushNum(nums, CalcFunc(a, sn, err), err);
			continue;
		}
		StackPopChar(sign, &sn, err);
		StackPopNum(nums, &b, err);
		StackPopNum(nums, &a, err);
		if (b == 0 && sn == '/') {
			*err = DIVISIONBYZERO;
		}
		StackPushNum(nums, Calculate(a, b, sn), err);
	}
	StackPopChar(sign, &sn, err);
}
void CalcDegree(stack_t_char* sign, stack_t_num* nums, error_t* err) {
	elem_t a, b;
	elem_t_c sn;
	while (StackTopChar(sign) == '^') {
		StackPopChar(sign, &sn, err);
		StackPopNum(nums, &b, err);
		StackPopNum(nums, &a, err);
		StackPushNum(nums, Calculate(a, b, sn), err);
	}
	if (StackTopChar(sign) == '~') {
		StackPopChar(sign, &sn, err);
		StackPopNum(nums, &a, err);
		StackPushNum(nums, CalcFunc(a, sn, err), err);
	}
}

elem_t FinalCalc(stack_t_char* sign, stack_t_num* nums, error_t* err) {
	elem_t a, b, c;
	elem_t_c sn;
	while (nums->top != 1 || sign->top != 0) {
		if (CheckPriority(StackTopChar(sign)) == 5 || CheckPriority(StackTopChar(sign)) == 3) {
			StackPopChar(sign, &sn, err);
			StackPopNum(nums, &a, err);
			StackPushNum(nums, CalcFunc(a, sn, err), err);
			continue;
		}
		StackPopChar(sign, &sn, err);
		StackPopNum(nums, &b, err);
		StackPopNum(nums, &a, err);
		if (b == 0 && sn == '/') {
			*err = DIVISIONBYZERO;
		}
		StackPushNum(nums, Calculate(a, b, sn), err);
	}
	StackPopNum(nums, &c, err);
	return c;
}
int WorkWithStr(char* str, int len, stack_t_char* sign, stack_t_num* nums, error_t* err) {
	int i, a = 0, b = 0, presymbol = 2, checkbr = 0;
	elem_t num, numa, numb;
	elem_t_c s;
	char* adress;
	for (i = 0; i < len; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			num = strtod(&str[i], &adress);
			StackPushNum(nums, num, err);
			if (*err != 0) {
				return -1;
			}
			while (&str[i] != adress) {
				i++;
			}
			i--;
			if (str[i] == '.') {
				*err = WRONGSYMBOL;
				return -1;
			}
			presymbol = 1;//Что было до?
		}
		else {
			if (str[i] < -1 || str[i] > 255) {
				*err = WRONGSYMBOL;
				return -1;
			}
			if (str[i] < 'a' || str[i] > 'z') {
				if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '^' && str[i] != '(' && str[i] != ')' && isspace(str[i]) == 0) {
					*err = WRONGSYMBOL;
					return -1;
				}
			}
			if (str[i] >= 'a' && str[i] <= 'z') {
				s = AnalyzeWords(str, &i, err);
				if (s == 'E') {
					return -1;
				}
				else {
					WordToStack(s, sign, nums, err);
					if (*err != 0) {
						return -1;
					}
					if (s == 'p' || s == 'e') {
						presymbol = 1;//Что было до?
					}
					else {
						presymbol = 2;//Что было до?
					}
					continue;
				}
			}
			if (isspace(str[i]) != 0) {
				continue;
			}
			if (str[i] == '-' && presymbol == 2) {
				if (StackTopChar(sign) != '~') {
					StackPushChar(sign, '~', err);
					if (*err != 0) {
						return -1;
					}
				}
				else {
					StackPopChar(sign, &s, err);
					if (*err != 0) {
						return -1;
					}
				}
				continue;
			}
			if (str[i] == '(') {
				StackPushChar(sign, str[i], err);
				if (*err != 0) {
					return -1;
				}
				presymbol = 2;//Что было до?
				checkbr += 1;
				continue;
			}
			if (str[i] == ')') {
				if (checkbr > 0) {
					if (StackTopChar(sign) == '(' && presymbol == 2) {
						*err = BRACKETS;
						return -1;
					}
					CalcBracket(sign, nums, err);
					if (*err != 0) {
						return -1;
					}
					checkbr -= 1;
				}
				else {
					*err = BRACKETS;
					return -1;
				}
				continue;
			}
			b = CheckPriority(str[i]);
			a = CheckPriority(StackTopChar(sign));
			if ((a == 5 && b < 5) || (a == 3 && b < 3)) {
				StackPopNum(nums, &numa, err);
				StackPopChar(sign, &s, err);
				StackPushNum(nums, CalcFunc(numa, s, err), err);
				while (CheckPriority(StackTopChar(sign)) == 5 || (CheckPriority(StackTopChar(sign)) == 3 && b != 4)) {
					StackPopNum(nums, &numa, err);
					StackPopChar(sign, &s, err);
					StackPushNum(nums, CalcFunc(numa, s, err), err);
				}
				if (*err != 0) {
					return -1;
				}
			}
			b = CheckPriority(str[i]);
			a = CheckPriority(StackTopChar(sign));
			if (a == 5 && b == 5) {
				StackPushChar(sign, str[i], err);
				if (*err != 0) {
					return -1;
				}
				presymbol = 2;
				continue;
			}
			if (a == 4 && b != 4 && nums->top != 1) {
				CalcDegree(sign, nums, err);
				if (*err != 0) {
					return -1;
				}
			}
			b = CheckPriority(str[i]);
			a = CheckPriority(StackTopChar(sign));
			if (b > a || (a == 4 && (b == 4 || b == 0))) {
				StackPushChar(sign, str[i], err);
				if (*err != 0) {
					return -1;
				}
				presymbol = 2;//Что было до?
				continue;
			}
			if (b <= a && b != 0 && b != 4) {
				StackPopNum(nums, &numb, err);
				StackPopNum(nums, &numa, err);
				if (*err != 0) {
					return -1;
				}
				if (numb == 0 && StackTopChar(sign) == '/') {
					*err = DIVISIONBYZERO;
					return -1;
				}
				StackPushNum(nums, Calculate(numa, numb, StackTopChar(sign)), err);
				if (*err != 0) {
					return -1;
				}
				StackPopChar(sign, &s, err);
				b = CheckPriority(str[i]);
				a = CheckPriority(StackTopChar(sign));
				if (b > a) {
					StackPushChar(sign, str[i], err);
				}
				else {
					StackPopNum(nums, &numb, err);
					StackPopNum(nums, &numa, err);
					if (*err != 0) {
						return -1;
					}
					if (numb == 0 && StackTopChar(sign) == '/') {
						*err = DIVISIONBYZERO;
						return -1;
					}
					StackPushNum(nums, Calculate(numa, numb, StackTopChar(sign)), err);
					if (*err != 0) {
						return -1;
					}
					StackPopChar(sign, &s, err);
					StackPushChar(sign, str[i], err);
				}
				if (*err != 0) {
					return -1;
				}
				presymbol = 2;//Что было до?
				continue;
			}
		}
	}
	if (checkbr != 0) {
		*err = BRACKETS;
		return -1;
	}
	return 0;
}
elem_t Calculation(char* str, int length, error_t* err) {
	elem_t answer;
	int check, chc = 0, chs = 0;

	stack_t_char* stackChar;
	stack_t_num* stackNum;

	chc = CommentCheck(str);
	chs = SpaceCheck(str, length);

	if (chs == 1 || chc == 1) {
		return 0;
	}

	stackChar = StackCreateChar();
	stackNum = StackCreateNum();

	if (stackNum == NULL || stackChar == NULL) {
		*err = NMEMORY;
		StackDeleteChar(stackChar);
		StackDeleteNum(stackNum);
		return 0;
	}

	check = WorkWithStr(str, length, stackChar, stackNum, err);
	if (check == -1) {
		StackDeleteChar(stackChar);
		StackDeleteNum(stackNum);
		return 0;
	}
	answer = FinalCalc(stackChar, stackNum, err);
	if (_isnan(answer) != 0) {
		*err = FUNCTION;
		return 0;
	}
	if (*err != 0) {
		StackDeleteChar(stackChar);
		StackDeleteNum(stackNum);
		return 0;
	}

	StackDeleteChar(stackChar);
	StackDeleteNum(stackNum);

	return answer;
}