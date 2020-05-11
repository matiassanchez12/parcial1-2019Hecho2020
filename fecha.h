#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

eFecha pedirFecha(char* msg);
