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
#include<algorithm>
#include <vector>


#include "Paciente.h"
#include "TipoVisita.h"

using namespace std;

class MainMenu {

public:
	MainMenu(){}
	~MainMenu(){}

	void mostraMenuInicial() const;
	bool adicionarPaciente(vector<Paciente>& pacientes);
	void consultarCliente() const;
};




#endif /* MAINMENU_H_ */
