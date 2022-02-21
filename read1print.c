#include"read1print.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char* Read(int* length) {
	char* str = NULL;
	char* strr = NULL;
	char buffer = 1;
	int size = 1;
	int i;


	str = (char*)malloc(size * sizeof(char) + 1);
	if (str == NULL) {
		buffer = (char)getchar();
		if (buffer == EOF) {
			*length = -1;
		}
		if (buffer == '\n') {
			*length = -2;
		}
		free(str);
		return NULL;
	}

	for (i = 0; buffer != '\n'; i++) {
		buffer = (char)getchar();
		if (buffer == '\n') {
			i--;
			continue;
		}
		if (buffer == EOF) {
			str[i] = buffer;
			*length = i;
			return str;
		}
		size += 1;
		strr = (char*)realloc(str, size * sizeof(char));
		if (strr == NULL) {
			free(str);
			return NULL;
		}
		str = strr;
		str[i] = buffer;
	}

	*length = i;
	return str;
}
int CommentCheck(char* str) {
	if (str[0] == '/' && str[1] == '/') {
		return 1;
	}
	else {
		return 0;
	}
}
int SpaceCheck(char* str, int length) {
	int i, ch = 0;
	for (i = 0; i < length; i++) {
		if (str[i] < -1 || str[i] > 255) {
			continue;
		}
		if (isspace(str[i]) != 0) {
			ch++;
		}
	}
	if (length == ch) {
		return 1;
	}
	else {
		return 0;
	}
}
void Print(char* str, int length) {
	int i;
	for (i = 0; i < length; i++) {
		printf("%c", str[i]);
	}
}