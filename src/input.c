/*
 * input.c
 *
 *  Created on: 23 may. 2022
 *      Author: fatim
 */


#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "operacione.h"
#include <ctype.h>
#include <string.h>
void menu(int* opcion)
{
	printf("\n-------------------OPCIONES---------------------\n"
			"1. Alta vivienda.\n"
			"2. Modificar vivienda\n"
			"3. Baja vivienda\n"
			"4. Listar viviendas\n"
			"5. Listar censistas\n"
			"6. Censista con mas censos realizados:\n"
			"7. salir:\n"
			"Ingrese la opcion deseada:");
	scanf("%d", opcion);
}
void ingresoCalles(char* mensaje,char* mensajeError,char calle[],int tam)
{
	int retorno;
	if(calle !=NULL && tam > 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			gets(calle);
			retorno = 0;
			for(int i = 0; i<tam;i++)
			{
				if(isdigit(calle[i])==0 && isalpha(calle[i]) && calle[i] == 'ñ')
				{
					printf("%s",mensajeError);
					retorno =1;
					break;
				}
			}
		}while(retorno !=0);
	}
}
void ingreseInt(int* cantidad,char* mensaje,char* mensajeError,int minimo,int maximo,int intentos)
{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%d",cantidad);
			if(*cantidad >= minimo && *cantidad <= maximo)
			{
				break;
			}
			else
			{
				intentos--;
				printf("%s",mensajeError);
			}
		}while(intentos > 0);

	if(intentos == 0)
	{
		printf("\nGasto la cantidad de intentos\n"
				"\nVuelve al menu");
	}
}
void opcionModificar(int* opcion)
{
	printf("\nMenu de Modificación:\n"
			"  1- Modificar la calle.\n"
			"  2- Modificar la cantidad de personas.\n"
			"  3- Modificar la cantidad de habitaciones.\n"
			"  4- Modificar el tipo de vivienda.\n"
			"  5- Volver al menú principal.\n"
			"Elija una opción: ");
	fflush(stdin);
	scanf("%d",opcion);
	while(!(*opcion >0 && *opcion <6))
	{
		printf("Error ingrese una opcion correcta\n\n");
		printf("\nMenu de Modificación:\n"
				"  1- Modificar la calle.\n"
				"  2- Modificar la cantidad de personas.\n"
				"  3- Modificar la cantidad de habitaciones.\n"
				"  4- Modificar el tipo de vivienda.\n"
				"  5- Volver al menú principal.\n"
				"Elija una opción: ");
		fflush(stdin);
		scanf("%d",opcion);
	}
}

