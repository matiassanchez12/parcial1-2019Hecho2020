#include "genericas.h"
int mainMenu(int* option)
{
    int retorno = 0;
    if(option != NULL)
    {
        printf(">> Bienvenido al menu<<\n");
        printf("\n[1] EQUIPOS");
        printf("\n[2] REFERI");
        printf("\n[3] PARTIDOS");
        printf("\n[4] JUGADORES");
        printf("\n[5] SALIR\n");
        if(utn_getNumber(option, "\nSeleccionar una opcion: ", "Error, fuera de rango.", 1, 5, 2))
        {
            retorno = 1;
        }
    }
    return retorno;
}

/*
int gen_count(eStruct* list, int len)
{
    int retorno = 0;
    int i;
    int count = 0;
    if(list != NULL && len > 0)
    {
        retorno = 1;
        for(i = 0; i < len; i ++)
        {
        if(list[i].isEmpty == 0)
        {
            count ++;
        }
        }
    }
    if(count != 0)
    {
        retorno = count;
    }
    return retorno;
}
int gen_acum(eStruct* list, int len)
{
    int retorno = 0;
    int i;
    int acum = 0;
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i ++)
        {
        if(list[i].isEmpty == 0)
        {
            acum = acum + list[i].salary;
        }
        }
    }
    if(acum != 0)
    {
        retorno = acum;
    }
    return retorno;
}
*/
float gen_promedio(int count, int acum)
{
    float prom;
    if(count > 0 && acum > 0)
    {
        prom = (float)acum / count;
    }
    return prom;
}
void gen_checkReturnWithIf(int function, char* msgAllRight, char* msgError)
{
    if(function)
    {
        printf("%s", msgAllRight);
    }
    else
    {
        printf("%s", msgError);
    }
}
void gen_checkReturnWithSwitch(int function, char* msgAllRight, char* msgCancelOp, char* msgError)
{
    switch(function)
    {
    case -1:
        printf("%s", msgError);
        break;

    case 0:
        printf("%s", msgCancelOp);
        break;

    case 1:
        printf("%s", msgAllRight);
        break;
    }
}
