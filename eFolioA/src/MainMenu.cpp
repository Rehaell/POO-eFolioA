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
*-------------------------------------*
* Compromissos                        *
* 3 - Consulta / Operacao             *
* 4 - Internamento                    *
* 5 - Consultar                       *
* 6 - Remover                         * 
*-------------------------------------*
* 0 - Sair                            *
***************************************
Pressione a tecla correspondente: )";

}

bool MainMenu::adicionarPaciente(vector<Paciente>& pacientes){

	string nome, nomed, morada, raca;
	int genero, telefone, idade;

	cout<< "\n\n\n\n\n\n\n";
	cout << R"(
***************************************
* CLINICA VETERINARIA DO ARCO DO CEGO *
***************************************)";
	cin.clear();
	cout << "\nGenero (1 - Cao/ 2 - Gato): ";
	cin >> genero;
	if (genero != 1 && genero != 2){
		cout << "\nOpcao nao valida";
		return false;
	}
	cout << "Nome: ";
	cin >> nome;
	cout << "Nome Dono: ";
	cin >> nomed;
	cout << "Telefone: ";
	cin >> telefone;
	if (!isdigit(telefone)){
		cout << "\nOpcao nao valida";
		return false;
	}
	cout << "Morada: ";
	cin >> morada;
	cout << "Raca: ";
	cin >> raca;
	cout << " Idade: ";
	cin >> idade;
	if (!isdigit(idade)){
		cout << "\nOpcao nao valida";
		cin.clear();
		return false;
	}
	pacientes.push_back(Paciente(genero, nome, nomed, telefone, morada, raca, idade));
	return true;

}

void MainMenu::consultarCliente() const {
	cout<< "\n\n\n\n\n\n\n";
	cout << R"(
***************************************
* CLINICA VETERINARIA DO ARCO DO CEGO *
***************************************")";
	cout << "* Genero: (Cao/Gato)                  *";

}
