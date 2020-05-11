#include "fecha.h"

eFecha pedirFecha(char* msg)
{
    eFecha auxFecha;
    printf("%s", msg);
    utn_getNumber(&auxFecha.dia, "Ingresar dia :  ", "Error, ingresar solo del 1 al 31.", 1, 31, 30);
    utn_getNumber(&auxFecha.mes, "Ingresar mes :  ", "Error, ingresar solo del 1 al 12.", 1, 12, 30);
    utn_getNumber(&auxFecha.anio, "Ingresar anio :  ", "Error, ingresar solo del 1900 al 2020.", 1900, 2020, 30);
    return auxFecha;
}
