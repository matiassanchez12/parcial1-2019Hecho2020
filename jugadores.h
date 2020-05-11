#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "equipos.h"

#define LEN_NOMBRE 51
#define LEN_APELLIDO 31

typedef struct
{
    int codigo;
    char nombre[20];
    char apellido[20];
    int codigoEquipo;
    int isEmpty;
    char sexo;
    eFecha fechaCumple;
}eJugadores;

int jugad_initializer(eJugadores* list, int len);
int jugad_forceAdd(eJugadores* list,int limite, int indice, int* codigo,char* nombre,char* apellido, int codigoEq, char sexo, int dia, int mes, int anio);
int jugad_Add(eJugadores* listJugadores,int lenJugadores, eEquipos* listEquip, int lenEquip, int* codigo);
int jugad_Modify(eJugadores* list, int len);
int jugad_Remove(eJugadores* list, int len);
int jugad_Sort(eJugadores* list, int len);
int jugad_Print(eJugadores* list, int len);
int jugad_findIndexEmpty(eJugadores* list, int tam);
int jugad_findById(eJugadores* list, int len,int codigo);
void jugad_swapForSort(eJugadores* list, int iControl);
