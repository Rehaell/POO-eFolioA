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




void popularBaseDados(vector<Paciente>& tPacientes, unsigned int num_pacientes);

int main(){

	MainMenu menu;
	int escolha = 0;

	vector<Paciente> pacientes;

	//popula a base de dados automaticamente para efeitos de T/S
	popularBaseDados(pacientes, 5);

	//Menu inicial e escolha dos sub-menus / 0 - Para sair
    do{
    	menu.mostraMenuInicial();
    	cin >> escolha;
    	switch (escolha) {
    	case (1) :
    		//Metodo adicionar clientes
			menu.adicionarPaciente(pacientes);
    		break;
    	case (2) :
    		//Metodo consultar clientes, caso existam
			if(pacientes.size() == 0)
				cout << "Nao existem clientes na base de dados!";
			else menu.consultarCliente(pacientes);
    		break;
    	case (3) :
    		//Metodo adicionar eventos a clientes, caso existem clientes
			if(pacientes.size() == 0)
				cout << "Nao existem clientes na base de dados!";
			else menu.adicionarEvento(pacientes);
    		break;
    	case (4):
    			//Consulta de eventos caso existam clientes
				if(pacientes.size() == 0)
					cout << "Nao existem clientes na base de dados!";
				else menu.consultarVisitas(pacientes);
    		break;
    	default:
    		break;
    	}
    } while (escolha != 0);

    cout << "Ate logo!";

    return 0;

}



