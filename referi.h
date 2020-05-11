#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "jugadores.h"

#define REFE_LEN_NOMBRE 51
#define REFE_LEN_APELLIDO 31
#define REFE_LEN_EMAIL 31
typedef struct
{
    int codigo;
    char nombre[REFE_LEN_NOMBRE];
    char apellido[REFE_LEN_APELLIDO];
    char sexo;
    int isEmpty;
    char email[REFE_LEN_EMAIL];
    eFecha fechaCumple;
}eReferi;

int refe_initializer(eReferi* list, int len);
int refe_forceAdd(eReferi* list,int limite, int indice, int* codigo,char* nombre,char* apellido, char sexo, char* email, int dia, int mes, int anio);
int refe_Add(eReferi* list,int len, int* id);
int refe_Modify(eReferi* list, int len);
int refe_Remove(eReferi* list, int len);
int refe_Sort(eReferi* list, int len);
int refe_Print(eReferi* list, int len);
int refe_findIndexEmpty(eReferi* list, int tam);
int refe_findById(eReferi* list, int len,int codigo);
void refe_swapForSort(eReferi* list, int iControl);
