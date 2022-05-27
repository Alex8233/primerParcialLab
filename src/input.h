/*
 * input.h
 *
 *  Created on: 23 may. 2022
 *      Author: fatim
 */

#ifndef INPUT_H_
#define INPUT_H_

#endif /* INPUT_H_ */
/// \fn void menu(int*)
/// \brief
///
/// \pre
/// \post
/// \param opcion
void menu(int* opcion);
/// \fn void ingresoCalles(char*, char*, char[], int)
/// \brief
///
/// \pre
/// \post
/// \param mensaje
/// \param mensajeError
/// \param calle
/// \param tam
void ingresoCalles(char* mensaje,char* mensajeError,char calle[],int tam);
/// \fn void ingreseInt(int*, char*, char*, int, int, int)
/// \brief
///
/// \pre
/// \post
/// \param cantidad
/// \param mensaje
/// \param mensajeError
/// \param minimo
/// \param maximo
/// \param intentos
void ingreseInt(int* cantidad,char* mensaje,char* mensajeError,int minimo,int maximo,int intentos);
/// \fn void opcionModificar(int*)
/// \brief
///
/// \pre
/// \post
/// \param opcion
void opcionModificar(int* opcion);
