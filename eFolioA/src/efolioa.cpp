/*
 * efolioa.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: rui romao
 */

#include <iostream>
#include <vector>
#include <thread>


#include "Paciente.h"
#include "TipoVisita.h"
#include "MainMenu.h"




void popularBaseDados(vector<Paciente>& tPacientes);
void mostrarBaseDados(vector<Paciente>& tPacientes);

int main(){

	vector<Paciente> pacientes;

	//popularBaseDados(pacientes);
    //mostrarBaseDados(pacientes);

	MainMenu menu;
	int escolha = 0;
    do{
    	menu.mostraMenuInicial();
    	cin.clear();
    	cin >> escolha;
    	switch (escolha) {
    	case (1) :
				if(menu.adicionarPaciente(pacientes)){
					cout << "Paciente adicionado com sucesso!";
				}
				else
					cout << "Ocorreu um erro ao adicionar paciente!";
    			break;
    	case (2) :
    			menu.consultarCliente();
    			break;
    	}
    } while (escolha != 0);

    cout << "Ate logo!";
	return 0;
}



