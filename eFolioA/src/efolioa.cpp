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
    	cin >> escolha;
    	cin.clear();
		cin.ignore(INT_MAX, '\n');
    	switch (escolha) {
    	case (1) :
				pacientes.push_back(menu.adicionarPaciente());
    			break;
    	case (2) :
    			break;
    	}
    } while (escolha != 0);

	return 0;
}



