/*
 * MainMenu.h
 *
 *  Created on: Nov 21, 2018
 *      Author: rui romao
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <iterator>
#include <chrono>

#include "Paciente.h"
#include "TipoVisita.h"

using namespace std;

class MainMenu {

public:
	MainMenu(){}
	~MainMenu(){}

	void mostraMenuInicial() const;
	void adicionarPaciente(vector<Paciente>& pacientes);
	void consultarCliente(vector<Paciente>& pacientes);

	void adicionarEvento(vector<Paciente>& pacientes);
	void setVisita(vector<Paciente>::iterator& i);

	void consultarVisitas(vector<Paciente>& pacientes);

	void OcorrenciasPorMes(vector<Paciente>& pacientes);
};




#endif /* MAINMENU_H_ */
