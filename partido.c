#include "partido.h"

int part_initializer(ePartido* list, int len)
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
int part_Add(ePartido* listPartidos,int lenPartidos, int* codigo, eReferi* listReferies, int lenReferies, eEquipos* listEquipos, int lenEquipos)
{
    int retorno = -1;
    ePartido auxPartido;
    int index;
    index = part_findIndexEmpty(listPartidos, lenPartidos);
    printf(">>Menu de altas\n");
    if(listPartidos != NULL && lenPartidos > 0 && index < lenPartidos && index >= 0 && codigo != NULL)
    {
        retorno = 0;
        if(part_getOneData(&auxPartido, *codigo, "Ingresar Codigos del partido\n",listEquipos, lenEquipos, listReferies, lenReferies) == 1)
        {
            retorno = 1;
            auxPartido.isEmpty = 0;
            listPartidos[index] = auxPartido;
            (*codigo)++;
        }
    }
    return retorno;
}

int part_forceAdd(ePartido* list,int limite, int indice, int* codigo,int codigoVis,int codigoLocal,int codigoReferi)
{
    int retorno = 0;
    ePartido auxPartido;

    if(list != NULL && limite > 0 && indice < limite && indice >= 0 && codigo != NULL)
    {
        retorno = 1;
        auxPartido.codEquiLocal = codigoLocal;
        auxPartido.codEquiVisitante = codigoVis;
        auxPartido.codReferi = codigoReferi;
        auxPartido.codigo = *codigo;
        auxPartido.isEmpty = 0;
        list[indice] = auxPartido;
        (*codigo)++;
    }
    return retorno;
}
///-1 no se pudo encontrar id, 0 accion cancelada, 1 todo ok
/*
int part_Modify(ePartido* list, int len)
{
    int retorno = -1;
    char confirm;
    ePartido auxPartido;
    int id;
    int index;
    printf(">>Menu de modificaciones");
    if(list != NULL && len > 0 && utn_getNumber(&id, "Ingresar un id: ", "Error, fuera de rango.", 0, 10000, 2))
    {
        index = part_findById(list, len, id);
        if(index >= 0 && list[index].isEmpty != 1)
        {
            retorno = 0;
            printf("Ingresar nuevos datos:");
            if(prod_getOneData(&auxPartido, *id, "Ingresar nuevos datos:") == 1)
            {
                printf("Realizar modificacion? [s] o [n]");
                if(utn_getOnlyTwoChars(&confirm, "\nIngresar una opcion:", "Error solo [s] o [n].", 's', 'n', 2)
                        && confirm == 's')
                {
                    auxPartido.isEmpty = 0;
                    list[index] = auxPartido;
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}
///-1 no se pudo encontrar id, 0 accion cancelada, 1 todo ok
int part_Remove(ePartido* list, int len)
{
    int retorno = -1;
    char confirm;
    int id;
    int index;
    printf(">>Menu de bajas");
    if(list != NULL && len > 0 && utn_getNumber(&id, "Ingresar un id: ", "Error, fuera de rango.", 0, 10000, 2))
    {
        index = part_findById(list, len, id);
        if(index >= 0 && list[index].isEmpty != 1)
        {
            retorno = 0;
            printf("Seguro desea realizar la baja? [s] o [n] ");
            if(utn_getOnlyTwoChars(&confirm, "\nIngresar una opcion: ", "Error solo [s] o [n].", 's', 'n', 2)
                    && confirm == 's')
            {
                list[index].isEmpty = 0;
                retorno = 1;
            }
        }
    }
    return retorno;
}*/

int part_Sort(ePartido* list, int len)
{
    int retorno = 0;
    int flagSwap;
    int i;
    int auxiliarCmpDia;
    int auxiliarCmpMes;
    do
    {
        flagSwap = 0;
        for(i=0; i<len-1; i++)
        {
            if(list[i].isEmpty == 1 || list[i+1].isEmpty == 1)
            {
                continue;
            }
            auxiliarCmpDia = list[i].fecha.dia > list[i+1].fecha.dia;
            auxiliarCmpMes = list[i].fecha.mes > list[i+1].fecha.mes;
            if(auxiliarCmpDia > 0 || (auxiliarCmpDia == 0 && auxiliarCmpMes < 0))
            {
                retorno = 1;
                flagSwap = 1;
                part_swapForSort(list, i);
            }
        }
        len--;
    }
    while(flagSwap);


    return retorno;
}

int part_Print(ePartido* list, int len)
{
    int retorno = 0;
    int i;
    if(list != NULL && len > 0)
    {
        retorno = 1;
        printf("Mostrando listado...\n\n");
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty != 1)
            {
                printf("\nCodigo: %d - Codigo Equipo Visitante: %d - Codigo Equipo Local: %d", list[i].codigo, list[i].codEquiVisitante, list[i].codEquiLocal);
                printf("Codigo Referi: %d - D %1d/ M %1d/ A %2d", list[i].codReferi, list[i].fecha.dia, list[i].fecha.mes, list[i].fecha.anio);
            }
        }
    }
    return retorno;
}
int part_findById(ePartido* list, int len,int codigo)
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
                break;
            }
        }
    }
    return retorno;
}
int part_findIndexEmpty(ePartido* list, int tam)
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
void part_swapForSort(ePartido* list, int iControl)
{
    ePartido auxPartido;

    auxPartido = list[iControl];
    list[iControl] = list[iControl+1];
    list[iControl+1] = auxPartido;
}


int part_getOneData(ePartido* getOne, int codigo, char* msg, eEquipos* listEquipos, int lenEquipos, eReferi* listReferies, int lenReferies)
{
    int retorno = 0;
    int comprobe;
    printf("%s", msg);
    if(utn_getNumber(&getOne->codEquiLocal, "Ingresar codigo equipo local: ", "Error, fuera de rango.", 0, 11111, 3))
    {
        comprobe = part_verifyCodes(listEquipos, lenEquipos, getOne->codEquiLocal);
        if(comprobe == 1)
        {
            printf("\nCodigo Equipo LOCAL cargado con exito!\n");
            if(utn_getNumber(&getOne->codEquiVisitante, "Ingresar codigo equipo visitante: ", "Error, fuera de rango.", 0, 11111, 3))
            {
                comprobe = part_verifyCodes(listEquipos, lenEquipos, getOne->codEquiVisitante);
                if (comprobe == 0)
                {
                    printf("\nCodigo Equipo VISITANTE cargado con exito!\n");
                    if(utn_getNumber(&getOne->codReferi, "Ingresar codigo referi: ", "Error, fuera de rango.", 0, 11111, 3))
                    {
                        comprobe = refe_findById(listReferies, lenReferies, getOne->codReferi);
                        if(comprobe >= 0)
                        {
                            printf("\nCodigo Referi cargado con exito.\n");
                            getOne->fecha = pedirFecha("\n>>Ingresar fecha del partido\n");
                            getOne->codigo = codigo;
                            getOne->isEmpty = 0;
                            retorno = 1;
                        }
                        else
                        {
                            printf("\nCodigo REFERI incorrecto.\n");
                        }
                    }
                }
                else
                {
                    printf("\nCodigo VISITANTE incorrecto.\n");
                }
            }
        }
        else
        {
            printf("\nCodigo local incorrecto.\n");
        }
    }
    return retorno;
}
/// 0 EL CODIGO ES VISITANTE 1 ES LOCAL -1 NO EXISTE
int part_verifyCodes(eEquipos* list, int len, int codigoEquipo)
{
    int retorno = -1;
    int i;
    for(i = 0; i < len; i++)
    {
        if(codigoEquipo == list[i].codigo && list[i].isEmpty == 0)
        {
            retorno = 0; /// EL CODIGO EXISTE PERO NO ES VISITANTE
            if(strcmp(list[i].localidad, "Avellaneda")== 0)
            {
                retorno = 1;///EXISTE Y ES LOCAL
            }
        }
    }
    return retorno;
}

