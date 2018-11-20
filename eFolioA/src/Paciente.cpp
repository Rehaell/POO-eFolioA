/*
 * Paciente.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: rui romao
 */

#include <algorithm>
#include "Paciente.h"


using namespace std;


Paciente::Paciente(): nome_paciente(""), nome_dono(), telefone(0), morada(""), raca(""), idade(0) {}

void Paciente::setVisita(TipoVisita visita) {
	registo_visitas.push_back(visita);
	sort(registo_visitas.begin(),registo_visitas.end(), greater<TipoVisita>());

}

string Paciente::showPacientes() const{
	return "\nPaciente: " + nome_paciente + "\nDono: " + nome_dono + "\nTelefone: " + to_string(telefone) + "\nMorada: " + morada + "\nRaca: " + raca + "\nIdade: " + to_string(idade) +"\n";
}





