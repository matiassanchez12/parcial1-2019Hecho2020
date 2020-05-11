#include "equipos.h"

int equip_initializer(eEquipos* list, int len)
{
    int retorno = 0;
    int i;
    if(list != NULL && len > 0)
    {
        retorno = 1;
        for(i = 0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
    }
    return retorno;///ERROR
}
int equip_Add(eEquipos* list,int len, int* codigo)
{
    int retorno = -1;
    eEquipos auxEquipo;
    int index;
    index = equip_findIndexEmpty(list, len);

    if(list != NULL && len > 0 && index < len && index >= 0 && codigo != NULL)
    {
        retorno = 0;
        if(utn_getString(auxEquipo.nombre, LEN_NOMBRE, "Ingresar un nombre: ", "Error. Dato invalido.", 2)
                && utn_getDireccion(auxEquipo.localidad, LEN_LOCALIDAD, "Ingresar una localidad: ", "Error. Dato invalido.", 2))
        {
            retorno = 1;
            auxEquipo.codigo = *codigo;
            auxEquipo.isEmpty = 0;
            list[index] = auxEquipo;
            (*codigo)++;
        }
    }
    return retorno;
}
int equip_forceAdd(eEquipos* list,int limite, int indice, int* codigo,char* nombre,char* localidad)
{
    int retorno = 0;
    eEquipos auxEquipo;

    if(list != NULL && limite > 0 && indice < limite && indice >= 0 && codigo != NULL)
    {
        retorno = 1;
        strcpy(auxEquipo.nombre,nombre);
        strcpy(auxEquipo.localidad,localidad);

        auxEquipo.codigo = *codigo;
        auxEquipo.isEmpty = 0;
        list[indice] = auxEquipo;
        (*codigo)++;
    }
    return retorno;
}
int equip_Modify(eEquipos* list, int len)
{
    int retorno = -1;
    char confirm;
    eEquipos auxEquipo;
    int codigo;
    int index;
    codigo = utn_getNumber(&codigo, "Ingresar un id: ", "Error, fuera de rango.", 0, 10000, 2);
    index = equip_findById(list, len, codigo); /// SI ES DIFERENTE A 1 EL ID EXISTE
    if(list != NULL && len > 0 && index >= -1 && list[index].isEmpty != 1)
    {
        retorno = 0;

        printf("Ingresar nuevos datos:");
        if(utn_getString(auxEquipo.nombre, LEN_NOMBRE, "Ingresar un nombre: ", "Error. Dato invalido.", 2)
                && utn_getDireccion(auxEquipo.localidad, LEN_LOCALIDAD, "Ingresar una localidad: ", "Error. Dato invalido.", 2))
        {
            printf("Realizar modificacion? [s] o [n]");
            if(utn_getOnlyTwoChars(&confirm, "\nIngresar una opcion:", "Error solo [s] o [n].", 's', 'n', 2)
                    && confirm == 's')
            {
                auxEquipo.codigo = codigo;
                auxEquipo.isEmpty = 0;
                list[index] = auxEquipo;
                retorno = 1;
            }
        }
    }
    return retorno;
}
int equip_Remove(eEquipos* list, int len)
{
    int retorno = -1;
    char confirm;
    int codigo = utn_getNumber(&codigo, "Ingresar un id: ", "Error, fuera de rango.", 0, 10000, 2);
    int index = equip_findById(list, len, codigo);
    if(list != NULL && len > 0 && index >= 0 && list[index].isEmpty != 1)
    {
        retorno = 0;
        printf("Seguro desea realizar la baja? [s] o [n] ");
        if(utn_getOnlyTwoChars(&confirm, "\nIngresar una opcion: ", "Error solo [s] o [n].", 's', 'n', 2)
                && confirm == 's')
        {
            list[index].isEmpty = 1;
            retorno = 1;
        }
    }
    return retorno;
}

int equip_Sort(eEquipos* list, int len)
{
    int retorno = 0;
    int flagSwap;
    int i;
    int auxiliarCmpNom;
    int auxiliarCmpLoc;
    do
    {
        flagSwap = 0;
        for(i=0; i<len-1; i++)
        {
            if(list[i].isEmpty == 1 || list[i+1].isEmpty == 1)
            {
                continue;
            }
            auxiliarCmpNom = strcmp(list[i].nombre,list[i+1].nombre);
            auxiliarCmpLoc = strcmp(list[i].localidad,list[i+1].localidad);
            if(auxiliarCmpNom > 0 || (auxiliarCmpNom == 0 && auxiliarCmpLoc < 0))
            {
                retorno = 1;
                flagSwap = 1;
                equip_swapForSort(list, i);
            }
        }
        len--;
    }
    while(flagSwap);


    return retorno;
}

int equip_Print(eEquipos* list, int len)
{
    int retorno = 0;
    int i;
    if(list != NULL && len > 0)
    {
        retorno = 1;
        printf("\n");
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty != 1)
            {
                printf("\nCodigo: %d - Nombre: %s - Localidad: %s", list[i].codigo, list[i].nombre, list[i].localidad);
            }
        }
    }
    return retorno;
}
int equip_findById(eEquipos* list, int len,int codigo)
{
    int retorno = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i ++)
        {
            if(list[i].codigo == codigo && list[i].isEmpty != 1)
            {
                retorno = i;
            }
        }
    }
    return retorno;
}
int equip_findIndexEmpty(eEquipos* list, int tam)
{
    int retorno = -1;
    int i;
    if(list != NULL && tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            if(list[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
void equip_swapForSort(eEquipos* list, int iControl)
{
    eEquipos auxEquipo;

    auxEquipo = list[iControl];
    list[iControl] = list[iControl+1];
    list[iControl+1] = auxEquipo;
}

