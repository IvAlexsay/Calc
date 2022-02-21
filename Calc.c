#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<float.h>
#include"errors.h"
#include"stacks.h"
#include"read1print.h"
#include"calculation.h"
//#include <crtdbg.h>
//#define _CRTDBG_MAP_ALLOC
#pragma warning(disable:4996)



int main(int argc, char* argv[]){
	char*str = NULL;
	int length, lol = 1;
	elem_t answer;

	error_t err = OKEY;
	
	if(argc >= 3){
		printf("ERROR: Too much arguments\n");
		return -1;
	}
	if(argc == 2 && freopen(argv[1],"r",stdin) == NULL){
		printf("ERROR: Wrong name of file\n");
		return -1;
	}


	do{
	  if(str != NULL){
		  free(str);
	  }
    str = Read(&length);
		if(length == -1){
			break;
		}
	  if(str == NULL){
		  printf("ERROR: %s", err_s[1]);
			if(length != -2){
				scanf("%*[^\n]");
        getchar();
			}
			length = 0;
			continue;
		}
	  if(str[0] == EOF){
		  break;
	  }

		answer = Calculation(str, length, &err);
		if (err == STRSPORCOM) {
			Print(str, length);
			printf("\n");
			err = OKEY;
			continue;
		}
		Print(str, length);
		printf(" == ");
		if (err != OKEY) {
			printf("ERROR: %s", err_s[err]);
			err = OKEY;
			continue;
		}
		else {
			printf("%g\n", answer);
			continue;
		}

	}while(lol == 1);
	 
	free(str);
	fclose(stdin);

	//_CrtDumpMemoryLeaks();
	return 0;
}