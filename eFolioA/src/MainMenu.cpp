/*
 * MainMenu.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: rui romao
 */

#include "MainMenu.h"

void MainMenu::mostraMenuInicial(){
	cout<< "\n\n\n\n\n\n\n";
	cout << R"(
***************************************
* CLINICA VETERINARIA DO ARCO DO CEGO *
***************************************
* Por favor escolha uma opcao:        *
*-------------------------------------*
* Pacientes                           *
* 1 - Adicionar                       *
* 2 - Consultar                       *
* 3 - Remover                         *
*-------------------------------------*
* Compromissos                        *
* 4 - Consulta / Operacao             *
* 5 - Internamento                    *
* 6 - Consultar                       *
* 7 - Remover                         * 
*-------------------------------------*
* 0 - Sair                            *
***************************************
Pressione a tecla correspondente: )";

}

Paciente MainMenu::adicionarPaciente(){
	Paciente paciente;
	cout << R"(
***************************************
* CLINICA VETERINARIA DO ARCO DO CEGO *
***************************************
* Genero:                             *
* Nome:                               *
* Nome Dono:                          *
* Telefone:                           *
* Morada:                             *
* Raca                                *
* Idade:                              *
***************************************)";
	return paciente;

}


