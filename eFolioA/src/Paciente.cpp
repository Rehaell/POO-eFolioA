/*
 * Paciente.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: rui romao
 */




#include "Paciente.h"


using namespace std;

Paciente::Paciente(int generop, string nomep, string nomed, unsigned int telefonep, string moradap, string racap, int idadep){
	genero = Genero(generop);
	nome_paciente = nomep;
	nome_dono = nomed;
	telefone = telefonep;
	morada = moradap;
	raca = racap;
	idade = idadep;
	num_consulta = 0;
	num_operacoes = 0;
	num_internamento = 0;
}


void Paciente::setVisita(TipoVisita visita) {
	registo_visitas.push_back(visita);
	sort(registo_visitas.begin(),registo_visitas.end(), greater<TipoVisita>());
	switch (visita.getTipoEvento()) {
		case (1):
			num_consulta += 1;
			break;
		case (2):
			num_operacoes += 1;
			break;
		case (3):
			num_internamento += 1;
			break;
		default:
			break;
	};
}

void Paciente::showPacienteInfo(bool visitas) const{
	string pgenero = (genero == 1 ? "Cao" : "Gato");
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "Genero: "    << setw(pgenero.length() + 2) << pgenero << endl;
	cout << "Paciente: "  << setw(nome_paciente.length())         << nome_paciente << endl;
	cout << "Dono: "      << setw(nome_dono.length() + 4)         << nome_dono << endl;
	cout << "Telefone: "  << setw(to_string(telefone).length())   << to_string(telefone) << endl;
	cout << "Morada: "    << setw(morada.length() + 2)            << morada << endl;
	cout << "Raca: "      << setw(raca.length() + 4)              << raca << endl;
	cout << "Idade: "     << setw(to_string(idade).length() + 3)  << to_string(idade) << endl;

	if (visitas) {
		for (unsigned int i = 0; i < registo_visitas.size(); ++i){
			registo_visitas[i].showVisita();
		}
	}
}
