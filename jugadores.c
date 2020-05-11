#include "jugadores.h"

int jugad_initializer(eJugadores* list, int len)
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
int jugad_Add(eJugadores* listJugadores,int lenJugadores, eEquipos* listEquip, int lenEquip, int* codigo)
{
    int retorno = -1;
    eJugadores auxJugador;
    int index;
    index = jugad_findIndexEmpty(listJugadores, lenJugadores);

    if(listJugadores != NULL && listEquip != NULL && lenJugadores > 0 && index < lenJugadores && index >= 0 && codigo != NULL)
    {
        retorno = 0;
        if(utn_getString(auxJugador.nombre, LEN_NOMBRE, "Ingresar un nombre: ", "Error. Dato invalido.", 2)
                && utn_getString(auxJugador.apellido, LEN_APELLIDO, "Ingresar apellido: ", "Error. Dato invalido.", 2)
                &&utn_getOnlyTwoChars(&auxJugador.sexo, "Ingresar sexo [f] o [m] :", "Error, dato invalido.", 'f','m', 3))
        {
            if(utn_getNumber(&auxJugador.codigoEquipo, "Ingresar codigo de equipo: ", "Error, dato invalido.", 0, 1000, 3)
                    &&equip_findById(listEquip,lenEquip, auxJugador.codigoEquipo) != -1)
            {
                pedirFecha(">>Ingrese fecha de nacimiento");
                auxJugador.codigo = *codigo;
                auxJugador.isEmpty = 0;
                listJugadores[index] = auxJugador;
                (*codigo)++;
                retorno = 1;
            }

        }
    }
    return retorno;
}
int jugad_forceAdd(eJugadores* list,int limite, int indice, int* codigo,char* nombre,char* apellido, int codigoEq, char sexo,int dia, int mes, int anio)
{
    int retorno = 0;
    eJugadores auxJugador;

    if(list != NULL && limite > 0 && indice < limite && indice >= 0 && codigo != NULL)
    {
        retorno = 1;
        strcpy(auxJugador.nombre,nombre);
        strcpy(auxJugador.apellido,apellido);
        auxJugador.codigoEquipo = codigoEq;
        auxJugador.sexo = sexo;
        auxJugador.fechaCumple.dia = dia;
        auxJugador.fechaCumple.mes = mes;
        auxJugador.fechaCumple.anio = anio;

        auxJugador.codigo = *codigo;
        auxJugador.isEmpty = 0;
        list[indice] = auxJugador;
        (*codigo)++;
    }
    return retorno;
}/*
int jugad_Modify(eJugadores* list, int len)
{
    int retorno = -1;
    char confirm;
    eJugadores auxJugador;
    int codigo;
    int index;
    codigo = utn_getNumber(&codigo, "Ingresar un codigo: ", "Error, fuera de rango.", 0, 10000, 2);
    index = jugad_findById(list, len, codigo); /// SI ES DIFERENTE A 1 EL ID EXISTE
    if(list != NULL && len > 0 && index >= -1 && list[index].isEmpty != 1)
    {
        retorno = 0;

        printf("Ingresar nuevos datos:");
        if(utn_getString(auxJugador.nombre, LEN_NOMBRE, "Ingresar un nombre: ", "Error. Dato invalido.", 2)
                && utn_getDireccion(auxJugador.localidad, LEN_LOCALIDAD, "Ingresar una localidad: ", "Error. Dato invalido.", 2))
        {
            printf("Realizar modificacion? [s] o [n]");
            if(utn_getOnlyTwoChars(&confirm, "\nIngresar una opcion:", "Error solo [s] o [n].", 's', 'n', 2)
                    && confirm == 's')
            {
                auxJugador.codigo = codigo;
                auxJugador.isEmpty = 0;
                list[index] = auxJugador;
                retorno = 1;
            }
        }
    }
    return retorno;
}
int jugad_Remove(eJugadores* list, int len)
{
    int retorno = -1;
    char confirm;
    int codigo = utn_getNumber(&codigo, "Ingresar un id: ", "Error, fuera de rango.", 0, 10000, 2);
    int index = jugad_findById(list, len, codigo);
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
}*/

int jugad_Sort(eJugadores* list, int len)
{
    int retorno = 0;
    int flagSwap;
    int i;
    int auxiliarCmpNom;
    int auxiliarCmpApe;
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
            auxiliarCmpApe = strcmp(list[i].apellido,list[i+1].apellido);
            if(auxiliarCmpNom > 0 || (auxiliarCmpNom == 0 && auxiliarCmpApe < 0))
            {
                retorno = 1;
                flagSwap = 1;
                jugad_swapForSort(list, i);
            }
        }
        len--;
    }
    while(flagSwap);

    return retorno;
}

int jugad_Print(eJugadores* list, int len)
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
                printf("\nCodigo: %d - Nombre: %s - Apellido: %s - Codigo de equipo: %d ", list[i].codigo, list[i].nombre, list[i].apellido, list[i].codigoEquipo);
                printf("Sexo: %c - Fecha de nacimiento: %1d / %1d / %2d", list[i].sexo, list[i].fechaCumple.dia, list[i].fechaCumple.mes, list[i].fechaCumple.anio);
            }
        }
    }
    return retorno;
}
int jugad_findById(eJugadores* list, int len,int codigo)
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
int jugad_findIndexEmpty(eJugadores* list, int tam)
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
void jugad_swapForSort(eJugadores* list, int iControl)
{
    eJugadores auxJugador;

    auxJugador = list[iControl];
    list[iControl] = list[iControl+1];
    list[iControl+1] = auxJugador;
}

