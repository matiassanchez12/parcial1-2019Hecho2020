#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "referi.h"

typedef struct
{
    int codigo;
    int codEquiVisitante;
    int codEquiLocal;
    int codReferi;
    int isEmpty;
    eFecha fecha;
}ePartido;


int part_initializer(ePartido* list, int len);
int part_forceAdd(ePartido* list,int limite, int indice, int* codigo,int codigoVis,int codigoLocal,int codigoReferi);
int part_Add(ePartido* listPartidos,int lenPartidos, int* codigo, eReferi* listReferies, int lenReferies, eEquipos* listEquipos, int lenEquipos);
int part_Modify(ePartido* list, int len);
int part_Remove(ePartido* list, int len);
int part_Sort(ePartido* list, int len);
int part_Print(ePartido* list, int len);
int part_findIndexEmpty(ePartido* list, int tam);
int part_findById(ePartido* list, int len,int codigo);
void part_swapForSort(ePartido* list, int iControl);
int part_getOneData(ePartido* getOne, int codigo, char* msg, eEquipos* listEquipos, int lenEquipos, eReferi* listReferies, int lenReferies);
int part_verifyCodes(eEquipos* list, int len, int codigoEquipo);
