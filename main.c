#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericas.h"
#include "partido.h"
#define QUANTITY_EQUIPOS 10
#define QUANTITY_JUGADORES 10
#define QUANTITY_REFERIES 10
#define QUANTITY_PARTIDOS 10
int main()
{
    int option;
    int codigoReferies = 0;
    int codigoEquipo = 0;
    int codigoJugadores = 0;
    int codigoPartidos = 0;
    eEquipos listEquipos[QUANTITY_EQUIPOS];
    eJugadores listJugadores[QUANTITY_JUGADORES];
    eReferi listReferies[QUANTITY_REFERIES];
    ePartido listPartidos[QUANTITY_PARTIDOS];

    if(jugad_initializer(listJugadores, QUANTITY_JUGADORES)&&equip_initializer(listEquipos, QUANTITY_EQUIPOS)
       &&refe_initializer(listReferies, QUANTITY_REFERIES) && part_initializer(listPartidos, QUANTITY_PARTIDOS))
    {
        do
        {
            if(mainMenu(&option))
            {
                switch(option)
                {
                case 1:
                    equip_forceAdd(listEquipos, QUANTITY_EQUIPOS, 0, &codigoEquipo, "G", "Lomas");
                    equip_forceAdd(listEquipos, QUANTITY_EQUIPOS, 1, &codigoEquipo, "F", "Burzaco");
                    equip_forceAdd(listEquipos, QUANTITY_EQUIPOS, 2, &codigoEquipo, "D", "Luis Guillon");
                    equip_forceAdd(listEquipos, QUANTITY_EQUIPOS, 3, &codigoEquipo, "C", "Avellaneda");
                    equip_forceAdd(listEquipos, QUANTITY_EQUIPOS, 4, &codigoEquipo, "B", "Avellaneda");
                    equip_forceAdd(listEquipos, QUANTITY_EQUIPOS, 5, &codigoEquipo, "H", "Escalada");
                    //gen_checkReturnWithSwitch(equip_Add(listEquipos, QUANTITY_EQUIPOS, &codigoEquipo), "\n\nAccion finalizada con exito!", "\n\nOcurrio algo..", "\n\nError. No se encontraron datos");
                    if(equip_Sort(listEquipos, QUANTITY_EQUIPOS))
                    {
                       gen_checkReturnWithIf(equip_Print(listEquipos, QUANTITY_EQUIPOS), "\n\nAccion finalizada con exito!", "\n\nError. No se encontraron datos");
                    }
                    printf("No se pudo mostrar el listado.");
                    break;
                case 2:
                   // refe_Add(listReferies, QUANTITY_REFERIES, &codigoReferies);
                    refe_forceAdd(listReferies, QUANTITY_REFERIES, 0, &codigoReferies, "Zairo", "Gonorrea", 'f', "asdasd@hotmail.com" ,1,2,1999 );
                    refe_forceAdd(listReferies, QUANTITY_REFERIES, 1, &codigoReferies, "Albino", "Roberto Carlinios", 'f', "Carlitosdelagente@hotmail.com" ,1,2,1999 );
                    refe_forceAdd(listReferies, QUANTITY_REFERIES, 2, &codigoReferies, "Nefasto", "Tarlipes", 'm', "Eltarlipes@hotmail.com" ,1,2,1999 );
                    if(refe_Sort(listReferies, QUANTITY_REFERIES))
                    {
                        gen_checkReturnWithIf(refe_Print(listReferies, QUANTITY_REFERIES), "\n\nAccion finalizada con exito!", "\n\nError. No se encontraron datos");
                    }
                    break;
                case 3:
                    gen_checkReturnWithSwitch(part_Add(listPartidos, QUANTITY_PARTIDOS, &codigoPartidos, listReferies, QUANTITY_REFERIES, listEquipos, QUANTITY_EQUIPOS), "SE CARGO", "ALGUNO DE LOS CODIGOS ESTA MAL", "ERROR, NO HAY DATOS CARGADOS");
                    part_Print(listPartidos, QUANTITY_PARTIDOS);
                    break;
                case 4:
                    jugad_forceAdd(listJugadores, QUANTITY_JUGADORES, 0, &codigoJugadores, "Zairo", "Gonorrea", 3, 'f', 1,2,1999 );
                    jugad_forceAdd(listJugadores, QUANTITY_JUGADORES, 1, &codigoJugadores, "Albino", "Carlos", 3, 'f', 1,2,1999 );
                    jugad_forceAdd(listJugadores, QUANTITY_JUGADORES, 2, &codigoJugadores, "Elmishi", "Mishon", 3, 'f', 1,2,2000 );
                    jugad_forceAdd(listJugadores, QUANTITY_JUGADORES, 3, &codigoJugadores, "Roberto", "CarlosAlfonso", 3, 'f', 1,2,2020 );
                    if(jugad_Sort(listJugadores, QUANTITY_JUGADORES))
                    {
                        gen_checkReturnWithIf(jugad_Print(listJugadores, QUANTITY_JUGADORES), "\n\nAccion finalizada con exito!", "\n\nError. No se encontraron datos");
                    }
                    //gen_checkReturnWithSwitch(jugad_Add(listJugadores, QUANTITY_JUGADORES, listEquipos, QUANTITY_EQUIPOS, &codigoJugadores), "\n\nAccion finalizada con exito!", "\n\Ocurrio algo..", "\n\nError. No se encontraron datos");

                    break;
                }
            }
        }
        while(option != 5);
    }
    return 0;
}
