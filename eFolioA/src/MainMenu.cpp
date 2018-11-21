/*
 * MainMenu.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: rui romao
 */

#include "MainMenu.h"
#include <ctype.h>


void MainMenu::mostraMenuInicial() const {
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

	string nome, nomed, morada, raca;
	int genero, telefone, idade;

	cout<< "\n\n\n\n\n\n\n";
	cout << R"(
***************************************
* CLINICA VETERINARIA DO ARCO DO CEGO *
***************************************)";
	cout << "Genero (1 - Cao/ 2 - Gato): ";
	cin >> genero;

	if (genero != 1 && genero != 2){
		cout << "\nOpcao nao valida";
		adicionarPaciente();
	}
	cout << "Nome: ";
	cin >> nome;
	cout << " Nome Dono: ";
	cin >> nomed;
	cout << "Telefone: ";
	cin >> telefone;
	cout << "Morada: ";
	cin >> morada;
	cout << "Raca: ";
	cin >> raca;
	cout << " Idade: ";
	cin >> idade;

	return Paciente(genero, nome, nomed, telefone, morada, raca, idade);

}

void MainMenu::consultarCliente() const {
	cout<< "\n\n\n\n\n\n\n";
	cout << R"(
***************************************
* CLINICA VETERINARIA DO ARCO DO CEGO *
***************************************")";
	cout << "* Genero: (Cao/Gato)                  *";

}
