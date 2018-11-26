/*
 * MainMenu.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: rui romao
 */

#include "MainMenu.h"


void MainMenu::mostraMenuInicial() const {
	cout<< "\n\n\n\n\n\n\n";
	cout << R"(
******************************************
*   CLINICA VETERINARIA DO ARCO DO CEGO  *
******************************************
* Por favor escolha uma opcao:           *
*----------------------------------------*
* Pacientes                              *
* 1 - Adicionar                          *
* 2 - Consultar/Remover                  *
*----------------------------------------*
* Compromissos                           *
* 3 - Consulta / Operacao / Internamento *
* 4 - Consultar / Remover                *
*----------------------------------------*
* 0 - Sair                               *
******************************************
Pressione a tecla correspondente: )";

}

void MainMenu::adicionarPaciente(vector<Paciente>& pacientes){

	string nome, nomed, morada, raca;
	int genero, telefone, idade;

	cout<< "\n\n\n\n\n\n\n";

	do {
        cin.clear();
		cin.ignore();
		cout << "\nGenero (1 - Cao/ 2 - Gato): ";
		cin >> genero;
	} while (genero != 1 && genero != 2 && cin.fail());


	cin.ignore();
	cout << "Nome: ";
	getline(cin, nome);

	cout << "Nome Dono: ";
	getline(cin, nomed);


	cout << "Telefone: ";
	cin >> telefone;


	cin.ignore();
	cout << "Morada: ";
	getline(cin, morada);


	cout << "Raca: ";
	getline(cin, raca);


	cout << "Idade: ";
	cin >> idade;

	pacientes.push_back(Paciente(genero, nome, nomed, telefone, morada, raca, idade));
}

void MainMenu::consultarCliente(vector<Paciente>& pacientes) {

	int escolha = 3;
	vector<Paciente>::iterator i = pacientes.begin();
	do {

		(*i).showPacienteInfo(false);
		cout << "Escolha (1) para retroceder, (2) para avancar, (3) para voltar ao menu inicial!, e (0) para remover Paciente actual: ";
		cin >> escolha;
		switch(escolha) {
			case(1):
				if (i != pacientes.begin())
					--i;
				break;
			case(2):
				if (i != pacientes.end()-1)
					++i;
				break;
			case (0):
				pacientes.erase(i);
				escolha = 3;
				break;
			default:
				break;
		}
	} while(escolha != 3);

}

void MainMenu::setVisita(vector<Paciente>::iterator& i){

	int evento, duracao = 0;
	string razao, nome_medico;
	system_clock::time_point data;

	do {
        cin.clear();
		cin.ignore();
		cout << "Selecione o tipo de evento (1 - Consulta / 2 - Operacao / 3 - Internamento): ";
		cin >> evento;
	} while (evento != 1 && evento != 2 && evento != 3 && cin.fail());

	cin.ignore();
	cout << "Qual a razao da visita: ";
	getline(cin, razao);

	cout << "Qual o nome do medico: ";
	getline(cin, nome_medico);

	cout << "Qual a data da visita (DD/MM/AAAA): ";
	//cin >> data;

	if(evento == 3) {
		cin.ignore();
		cout << "Qual a duracao do internamento: ";
		cin >> duracao;
	}

	TipoVisita visita(evento, razao, nome_medico, data, duracao);
	(*i).setVisita(visita);
}

void MainMenu::adicionarEvento(vector<Paciente>& pacientes) {
	int escolha = 10;
	vector<Paciente>::iterator i = pacientes.begin();
	do {

		(*i).showPacienteInfo(true);
		cout << "Escolha (1) para retroceder, (2) para avancar, (3) para voltar ao menu inicial, e (6) para adicionar evento: ";
		cin >> escolha;
		switch(escolha) {
			case(1):
				if (i != pacientes.begin())
					--i;
				break;
			case(2):
				if (i != pacientes.end()-1)
					++i;
				break;
			case (6):
				setVisita(i);
				i = pacientes.begin();
				break;
			default:
				break;
		}
	} while(escolha != 3);
}
