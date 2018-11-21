/*
 * Paciente.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: rui romao
 */

#include <algorithm>
#include "Paciente.h"


using namespace std;


Paciente::Paciente(): genero(Genero(0)), nome_paciente(""), nome_dono(), telefone(0), morada(""), raca(""), idade(0) {}
Paciente::Paciente(Genero generop, string nomep, string nomed, unsigned int telefonep, string moradap, string racap, int idadep){
	genero = Genero(generop);
	nome_paciente = nomep;
	nome_dono = nomed;
	telefone = telefonep;
	morada = moradap;
	raca = racap;
	idade = idadep;
}


void Paciente::setVisita(TipoVisita visita) {
	registo_visitas.push_back(visita);
	sort(registo_visitas.begin(),registo_visitas.end(), greater<TipoVisita>());

}

string Paciente::showPacientes() const{
	return "\nPaciente: " + nome_paciente + "\nDono: " + nome_dono + "\nTelefone: " + to_string(telefone) + "\nMorada: " + morada + "\nRaca: " + raca + "\nIdade: " + to_string(idade) +"\n";
}





