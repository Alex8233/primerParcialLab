/*
 * operacione.h
 *
 *  Created on: 23 may. 2022
 *      Author: fatim
 */

#ifndef OPERACIONE_H_
#define OPERACIONE_H_
typedef struct
{
	int legajoCensista;
	char nombre[25];
	int edad;
	char tenefono[25];

}eCensista;
typedef struct
{
	int idVivienda;
	char calle[25];
	int personas;
	int habitaciones;
	int tipoVivienda;
	int legajoCensista;

}eVivienda;
typedef struct
{
	int vivienda;
	char tipo[25];
}eTipo;


#endif /* OPERACIONE_H_ */
/// \fn int inicializar(eVivienda[], int)
/// \brief inicializamos la id con -1
///
/// \pre
/// \post
/// \param viviendas
/// \param tam
/// \return
int inicializar(eVivienda viviendas[],int tam);
/// \fn int ingresos(eVivienda[], int, char[], int, int, int, int, int)
/// \brief validacion estructura eVivienda
///
/// \pre
/// \post
/// \param viviendas
/// \param tam
/// \param calle
/// \param habitantes
/// \param habitaciones
/// \param tipoVivienda
/// \param legajoCensista
/// \param id
/// \return
int ingresos(eVivienda viviendas[],int tam,char calle[],int habitantes,int habitaciones,int tipoVivienda,int legajoCensista,int id);
/// \fn int espacioLibre(eVivienda[], int)
/// \brief busco el espacio libre
///
/// \pre
/// \post
/// \param viviendas
/// \param tam
/// \return retorna el indice del array libre
int espacioLibre(eVivienda viviendas[],int tam);
/// \fn int buscarId(int, eVivienda[], int)
/// \brief buscamos el id que se desea encontrar
///
/// \pre
/// \post
/// \param id
/// \param viviendas
/// \param tam
/// \return retorna el indice del array donde se encuentra el id
int buscarId(int id, eVivienda viviendas[],int tam);
/// \fn int darBaja(eVivienda[], int, int)
/// \brief da de baja al id
///
/// \pre
/// \post
/// \param viviendas
/// \param tam
/// \param id
/// \return retorna 0 si se dio de baja correctamente,y 1 cuando no se dio de baja
int darBaja(eVivienda viviendas[],int tam,int id);
/// \fn int ordenarVivienda(eVivienda[], int)
/// \brief ordeno la estructura de eVivienda
///
/// \pre
/// \post
/// \param viviendas
/// \param tam
/// \return retorna 0 si se dio de ordeno la estructura correctamente,y 1 cuando ocurrio un error al ordenar
int ordenarVivienda(eVivienda viviendas[],int tam);
/// \fn void mostrarVivienda(eVivienda[], eTipo[], eCensista[], int, int, int)
/// \brief muestro la estructura de eVivienda
///
/// \pre
/// \post
/// \param viviendas
/// \param tipos
/// \param censistas
/// \param tamVivienda
/// \param tamCensista
/// \param tamTipo
void mostrarVivienda(eVivienda viviendas[],eTipo tipos[],eCensista censistas[],int tamVivienda,int tamCensista,int tamTipo);
/// \fn void mostrarCensista(eCensista[], int)
/// \brief muestro la estructura de eCensista
///
/// \pre
/// \post
/// \param censistas
/// \param tam
void mostrarCensista(eCensista censistas[],int tam, eVivienda viviendas[],eTipo tipos[],int tamVivienda,int tamTipo);
/// \fn void censistaMaximo(eCensista[], int, eVivienda[], int)
/// \brief
///
/// \pre
/// \post
/// \param censistas
/// \param tamCensista
/// \param viviendas
/// \param tamVivienda
void censistaMaximo(eCensista censistas[],int tamCensista,eVivienda viviendas[],int tamVivienda);
