#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "fecha.h"

#define LEN_NOMBRE 51
#define LEN_LOCALIDAD 31

typedef struct
{
    int codigo;
    char nombre[LEN_NOMBRE];
    char localidad[LEN_LOCALIDAD];
    int isEmpty; /// 0 = LLENO 1 = VACIO
}eEquipos;

int equip_initializer(eEquipos* list, int len);
int equip_forceAdd(eEquipos* list,int limite, int indice, int* codigo,char* nombre,char* localidad);
int equip_Add(eEquipos* list,int len, int* id);
int equip_Modify(eEquipos* list, int len);
int equip_Remove(eEquipos* list, int len);
int equip_Sort(eEquipos* list, int len);
int equip_Print(eEquipos* list, int len);
int equip_findIndexEmpty(eEquipos* list, int tam);
int equip_findById(eEquipos* list, int len,int codigo);
void equip_swapForSort(eEquipos* list, int iControl);
