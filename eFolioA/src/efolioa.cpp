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
//void mostrarBaseDados(vector<Paciente>& tPacientes);

int main(){

	MainMenu menu;
	int escolha = 0;

	vector<Paciente> pacientes;


	popularBaseDados(pacientes, 1);
    //mostrarBaseDados(pacientes);

   do{
    	menu.mostraMenuInicial();
    	cin >> escolha;
    	switch (escolha) {
    	case (1) :
			menu.adicionarPaciente(pacientes);
    		break;
    	case (2) :
			if(pacientes.size() == 0)
				cout << "Nao existem clientes na base de dados!";
			else menu.consultarCliente(pacientes);
    		break;
    	case (3) :
			if(pacientes.size() == 0)
				cout << "Nao existem clientes na base de dados!";
			else menu.adicionarEvento(pacientes);
    		break;
    	case (4):
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



