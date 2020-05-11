#include "referi.h"

int refe_initializer(eReferi* list, int len)
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
int refe_Add(eReferi* list,int len, int* codigo)
{
    int retorno = -1;
    eReferi auxReferi;
    int index;
    index = refe_findIndexEmpty(list, len);
    if(list != NULL && len > 0 && index < len && index >= 0 && codigo != NULL)
    {
        retorno = 0;
        if(utn_getString(auxReferi.nombre, REFE_LEN_NOMBRE, "Ingresar un nombre: ", "Error. Dato invalido.", 2)
        && utn_getString(auxReferi.apellido, REFE_LEN_APELLIDO, "Ingresar apellido: ", "Error. Dato invalido.", 2)
        && utn_getOnlyTwoChars(&auxReferi.sexo, "Ingresar sexo [f] o [m]: ", "Error. Solo [f] o [m].", 'f', 'm', 3)
        && utn_getEmail(auxReferi.email,REFE_LEN_EMAIL, "Ingresar eMail: ", "Error. fuera de rango.", 3 ))
        {
            auxReferi.fechaCumple = pedirFecha(">>Ingresar fecha de nacimiento \n");
            auxReferi.codigo = *codigo;
            auxReferi.isEmpty = 0;

            list[index] = auxReferi;
            (*codigo)++;
            retorno = 1;
        }
    }
    return retorno;
}
int refe_forceAdd(eReferi* list,int limite, int indice, int* codigo,char* nombre,char* apellido, char sexo, char* email, int dia, int mes, int anio)
{
    int retorno = 0;
    eReferi auxReferi;

    if(list != NULL && limite > 0 && indice < limite && indice >= 0 && codigo != NULL)
    {
        retorno = 1;
        strcpy(auxReferi.nombre,nombre);
        strcpy(auxReferi.apellido,apellido);
        strcpy(auxReferi.email,email);
        auxReferi.sexo = sexo;
        auxReferi.fechaCumple.dia = dia;
        auxReferi.fechaCumple.mes = mes;
        auxReferi.fechaCumple.anio = anio;
        auxReferi.codigo = *codigo;
        auxReferi.isEmpty = 0;
        list[indice] = auxReferi;
        (*codigo)++;
    }
    return retorno;
}/*
int refe_Modify(eReferi* list, int len)
{
    int retorno = -1;
    char confirm;
    eReferi auxReferi;
    int codigo;
    int index;
    codigo = utn_getNumber(&codigo, "Ingresar un id: ", "Error, fuera de rango.", 0, 10000, 2);
    index = refe_findById(list, len, codigo); /// SI ES DIFERENTE A 1 EL ID EXISTE
    if(list != NULL && len > 0 && index >= -1 && list[index].isEmpty != 1)
    {
        retorno = 0;

        printf("Ingresar nuevos datos:");
        if(utn_getString(auxReferi.nombre, LEN_NOMBRE, "Ingresar un nombre: ", "Error. Dato invalido.", 2)
                && utn_getDireccion(auxReferi.localidad, LEN_LOCALIDAD, "Ingresar una localidad: ", "Error. Dato invalido.", 2))
        {
            printf("Realizar modificacion? [s] o [n]");
            if(utn_getOnlyTwoChars(&confirm, "\nIngresar una opcion:", "Error solo [s] o [n].", 's', 'n', 2)
                    && confirm == 's')
            {
                auxReferi.codigo = codigo;
                auxReferi.isEmpty = 0;
                list[index] = auxReferi;
                retorno = 1;
            }
        }
    }
    return retorno;
}
int refe_Remove(eReferi* list, int len)
{
    int retorno = -1;
    char confirm;
    int codigo = utn_getNumber(&codigo, "Ingresar un id: ", "Error, fuera de rango.", 0, 10000, 2);
    int index = refe_findById(list, len, codigo);
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
*/
int refe_Sort(eReferi* list, int len)
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
                refe_swapForSort(list, i);
            }
        }
        len--;
    }
    while(flagSwap);


    return retorno;
}

int refe_Print(eReferi* list, int len)
{
    int retorno = 0;
    int i;
    if(list != NULL && len > 0)
    {
        retorno = 1;
        printf("\n\nCodigo\tNombre\t\tApellido\tSexo\tEmail\t\t\t\tFecha de Nacimiento");
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty != 1)
            {
                printf("\n%d\t%s\t%15s", list[i].codigo, list[i].nombre, list[i].apellido);
                printf(" \t%c\t%23s\t\t%1d / %1d / %2d ", list[i].sexo, list[i].email, list[i].fechaCumple.dia, list[i].fechaCumple.mes, list[i].fechaCumple.anio);
            }
        }
    }
    return retorno;
}
int refe_findById(eReferi* list, int len,int codigo)
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
int refe_findIndexEmpty(eReferi* list, int tam)
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
void refe_swapForSort(eReferi* list, int iControl)
{
    eReferi auxReferi;

    auxReferi = list[iControl];
    list[iControl] = list[iControl+1];
    list[iControl+1] = auxReferi;
}
