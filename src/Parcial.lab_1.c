/*
 ============================================================================
 Name        : lab_1.c
 Author      : alex zalazar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "operacione.h"
#include <ctype.h>
#include <string.h>
#define TAMCALLES 25
#define TAMCENSISTAS 3
#define TAMTIPO 4
#define TAMVIVIENDA 5

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int opcionesId;

	int contadorViviendas =0;

	char calle[TAMCALLES];
	int habitantes;
	int habitaciones;
	int tipoVivienda;
	int legajoCensista;
	int id= 20000;

	int modificar;
	int modificarId;
	int inicioViviendas;
	eVivienda viviendas[TAMVIVIENDA];
	eCensista censistas[TAMCENSISTAS]={{100,"Ana",34,"1203-2345"},{101,"Juan",24,"4301-54678"},{102,"Sol",47,"5902-37487"}};
	eTipo tipos[TAMTIPO]={{1,"CASA"},{2,"DEPARTAMENTO"},{3,"CASILLA"},{4,"RANCHO"}};
	inicioViviendas =inicializar(viviendas,TAMVIVIENDA);
	if(inicioViviendas == 0)
	{
		printf("ERORR AL INICIALIZAR VIVIENDAS!!!");
	}

	do
	{
		menu(&opcion);
		switch(opcion)
		{

			case 1:
				if(contadorViviendas == TAMVIVIENDA){
					printf("\nLa lista esta llena");
				}
				else
				{
					ingresoCalles("\nIngrese la calle:","\nERROR,vuelva a ingresar la calle",calle,TAMCALLES);
					ingreseInt(&habitantes,"\nIngrese cantidad de habitantes:","\nERROR,vuelva a ingresar la cantidad de habitantes:",1,50,3);
					ingreseInt(&habitaciones,"\nIngrese cantidad de habitaciones:","\nERROR,vuelva a ingresar la cantidad de habitaciones:",1,10,3);
					ingreseInt(&tipoVivienda,"\nIngrese el tipo de vivienda (Ingrese 1 para casa, 2 para departamento, 3 para casilla, 4 para rancho): ", "Error, vuelva ingresar el tipo de vivienda.",1,4,3);
					ingreseInt(&legajoCensista, "Ingrese el legajo del censista(Ingrese 100 para Ana, 101 para Juan, 102 para Sol): ", "Error, ingrese un legajo valido.\n", 100, 102,3);
				}
				if(ingresos(viviendas,TAMVIVIENDA,calle,habitantes,habitaciones,tipoVivienda,legajoCensista,id)== 0)
				{
					contadorViviendas++;
					id ++;
					printf("\nSe dio de alta correctamente la vivienda");

				}
				else
				{
					printf("\nERROR,en la carga de datos");
				}

				break;
			case 2:
				if(contadorViviendas >0)
				{
					printf("\nIngrese el id que quiere modificar(desde 20000)");
					fflush(stdin);
					scanf("%d",&modificar);
					while(!(modificar>=20000))
					{
						printf("\nERROR!!!,Ingrese el id que desea modificar(desde 20000)");
						fflush(stdin);
						scanf("%d",&modificar);
					}
					modificarId = buscarId(modificar,viviendas,TAMVIVIENDA);
					if(modificarId >= 0)
					{
						do
						{
							opcionModificar(&opcionesId);
							switch(opcionesId)
							{
							case 1:
								ingresoCalles("\nIngrese la calle:","\nERROR,vuelva a ingresar la calle",calle,TAMCALLES);
								strcpy(viviendas[modificarId].calle,calle);
								printf("\nFue modificado.");
								break;
							case 2:
								ingreseInt(&habitantes,"\nIngrese cantidad de habitantes:","\nERROR,vuelva a ingresar la cantidad de habitantes:",1,50,3);
								viviendas[modificarId].personas = habitantes;
								printf("\nFue modificado.");
								break;
							case 3:
								ingreseInt(&habitaciones,"\nIngrese cantidad de habitaciones:","\nERROR,vuelva a ingresar la cantidad de habitaciones:",1,10,3);
								viviendas[modificarId].habitaciones = habitaciones;
								printf("\nFue modificado.");
								break;
							case 4:
								ingreseInt(&tipoVivienda,"\nIngrese el tipo de vivienda (Ingrese 1 para casa, 2 para departamento, 3 para casilla, 4 para rancho): ", "Error, vuelva ingresar el tipo de vivienda.",1,4,3);
								viviendas[modificarId].tipoVivienda=tipoVivienda;
								printf("\nFue modificado.");
								break;
							case 5:
								printf("\nVolviendo al menu principal:");
								break;

							}
						}while(opcionesId!=5);
					}
					else
					{
						printf("ERROR,el id no existe");
					}

				}
				break;
			case 3:
				if(contadorViviendas >0)
				{
					printf("\nIngrese el id que quiere dar de baja(desde 20000):");
					fflush(stdin);
					scanf("%d",&modificar);
					while(!(modificar>=20000))
					{
						printf("\nERROR!!!,Ingrese el id que desea dar de baja(desde 20000):");
						fflush(stdin);
						scanf("%d",&modificar);
					}
					modificarId = buscarId(modificar,viviendas,TAMVIVIENDA);
					if(modificarId >= 0)
					{
						if(darBaja(viviendas,TAMVIVIENDA,modificarId) ==0)
						{
							printf("\nSe dio de baja con exito");
						}
						else
						{
							printf("\nERROR,al dar de baja");
						}
					}
					else{
						printf("\nERROR,el id no existe");
					}
				}
				break;
			case 4:
				if(contadorViviendas >0)
				{
					if(ordenarVivienda(viviendas,TAMVIVIENDA) == 0)
					{
						mostrarVivienda(viviendas,tipos,censistas,TAMVIVIENDA,TAMCENSISTAS,TAMTIPO);
					}
					else
					{
						printf("\nERROR, AL ORDENAR");
					}
				}
				break;
			case 5:

					mostrarCensista(censistas,TAMCENSISTAS);

				break;
			case 6:
				printf("\nGracias por usar nuestros servicios.");
				break;
			default:
				printf("\nLA OPCION NO EXISTE!!!");
		}
	}while(opcion !=6);
	return EXIT_SUCCESS;
}
