#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
/*
int gen_acum(eStruct* list, int len);
int gen_count(eStruct* list, int len);*/



///TOTALMENTE GENERICAS
int mainMenu(int* option);
void gen_checkReturnWithSwitch(int function, char* msgAllRight, char* msgCancelOp, char* msgError);
void gen_checkReturnWithIf(int function, char* msgAllRight, char* msgError);
float gen_promedio(int count, int acum);

