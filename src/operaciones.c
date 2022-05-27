/*
 * operaciones.c
 *
 *  Created on: 23 may. 2022
 *      Author: fatim
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "input.h"
#include "operacione.h"

int inicializar(eVivienda viviendas[],int tam)
{
	int retorno =0;
	if(viviendas !=NULL && tam >0)
	{
		for(int i=0;i< tam;i++)
		{
			viviendas[i].idVivienda = -1;
		}
		retorno =1;
	}
	return retorno;
}
int ingresos(eVivienda viviendas[],int tam,char calles[],int habitantes,int habitaciones,int tipoVivienda,int legajoCensista,int id)
{
	int retorno =1;
	int libre;
	eVivienda cargaDeDatos;
	if(viviendas != NULL && tam > 0)
	{
		libre = espacioLibre(viviendas,tam);
		if(libre >=0)
		{
			cargaDeDatos.idVivienda = id;
			strcpy(cargaDeDatos.calle,calles);
			cargaDeDatos.personas=habitantes;
			cargaDeDatos.habitaciones = habitaciones;
			cargaDeDatos.tipoVivienda = tipoVivienda;
			cargaDeDatos.legajoCensista = legajoCensista;
			viviendas[libre] = cargaDeDatos;
			retorno=0;
		}
	}

	return retorno;
}
int espacioLibre(eVivienda vivienda[],int tam)
{
	int retorno = -1;
	if(vivienda != NULL && tam > 0)
	{
		for(int i=0;i<tam;i++)
		{
			if( vivienda[i].idVivienda == -1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
int buscarId(int id, eVivienda viviendas[],int tam)
{
	int retorno = -1;
	if(viviendas != NULL && tam>0 && id >= 20000)
	{

		for(int i=0;i<tam;i++)
		{
			if(viviendas[i].idVivienda == id)
			{

				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int darBaja(eVivienda viviendas[],int tam,int id)
{
	int retorno =1;
	if(viviendas != NULL && tam > 0)
	{
		viviendas[id].idVivienda=-1;
		retorno =0;
	}
	return retorno;
}
int ordenarVivienda(eVivienda viviendas[],int tam)
{
	eVivienda aux;
	int retorno = 1;
	if(viviendas !=NULL && tam > 0)
	{
		for(int i = 0;i<tam-1;i++)
		{
			for(int j=i+1;j<tam;j++)
			{
				if(strcmp(viviendas[i].calle, viviendas[j].calle) > 0)
				{
					aux = viviendas[j];
					viviendas[j] = viviendas[i];
					viviendas[i]=viviendas[j];
				}
				if(strcmp(viviendas[i].calle, viviendas[j].calle)== 0)
				{
					if(viviendas[i].personas > viviendas[j].personas)
					{
						aux = viviendas[j];
						viviendas[j] = viviendas[i];
						viviendas[i]=aux;
					}
				}

			}
		}
		retorno =0;
	}

	return retorno;
}
void mostrarVivienda(eVivienda viviendas[],eTipo tipos[],eCensista censistas[],int tamVivienda,int tamCensista,int tamTipo)
{

		if(viviendas != NULL)
		{
			printf("\nCalle\t\t ID\t Cantidad de Personas  Cantidad de Habitaciones  Tipo de Vivienda  Legajo Censista\n");
			for (int i = 0; i < tamVivienda; i++)
			{
				if(viviendas[i].idVivienda >= 20000)
				{
					for(int j = 0; j < tamCensista; j++)
					{
						if(censistas[i].legajoCensista == censistas[j].legajoCensista)
						{
							for(int y = 0; y < tamTipo; y++)
							{
								if(tipos[i].vivienda == tipos[y].vivienda)
								{
									printf("%-16s %-7d %-21d %-25d %-17d %d\n",viviendas[i].calle, viviendas[i].idVivienda, viviendas[i].personas,viviendas[i].habitaciones, tipos[y].vivienda, censistas[j].legajoCensista);
									break;
								}
							}
							break;
						}
					}

				}
			}
		}
}
void mostrarCensista(eCensista censistas[],int tam)
{

	if(censistas != NULL && tam>0)
	{
		printf("\nLegajo\t Nombre\t  Edad\t Numero de telefono\n");
		for(int i = 0; i < tam; i++)
		{
			printf("%-8d %-8s %-6d %s\n", censistas[i].legajoCensista, censistas[i].nombre, censistas[i].edad, censistas[i].tenefono);
		}
	}
}
