#pragma once
//Набор функций для чтения, обработки и вывода строк
char* Read(int* length);//Чтения строки с потока
int CommentCheck(char* str);//Проверка строки на комментарий 
int SpaceCheck(char* str, int length);//Проверка строки на пробельную строку
void Print(char* str, int length);//Вывод строки 