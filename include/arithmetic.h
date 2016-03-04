#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "stack.h"

using namespace std;

const int MAX_STR_LEN = 100;

bool CheckBrackets(char* s);  // проверка скобок
bool CheckOperations(char* s); //проверка стоят ли знаки операций в начале/конце
bool CheckOperandsStandTogether(char* s);  //проверка операндов,стоящих подряд
bool CheckOperationsStandTogether(char* s); //проверка операций,стоящих подряд 
bool CheckOperandBracketStandTogether(char* s);//проверка операндов и операций,стоящих подряд
void PartitionIntoTokens(char *s);  //разделение на лексемы
int Priority(char ch);  // определение приоритета операций
void ToPolish(char *s, char *c);  //перевод в польскую запись
double PolishFindResult(char *s);  //вычисляет значение выражения