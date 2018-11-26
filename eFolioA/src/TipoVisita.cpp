/*
 * TipoVisita.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: romaor
 */
#include <ctime>

#include "TipoVisita.h"

TipoVisita::TipoVisita(int event, string reason, string medic, system_clock::time_point date, int length){
	evento = TipoEvento(event);
	razao = reason;
	nome_medico = medic;
	data = date;
	if(event == internamento){
		duracao = length;
		data_alta += chrono::hours(length * 24);
	}
	else
		duracao = 0;
}

void TipoVisita::showVisita() const {
	time_t dataEvento = time_t(system_clock::to_time_t(data));
	time_t alta = time_t(system_clock::to_time_t(data_alta));

	string tipoEvento = "";

	switch (evento) {
		case (1):
				tipoEvento =  "Consulta";
				break;
		case (2):
				tipoEvento = "Operacao";
				break;
		case (3):
				tipoEvento = "Internamento";
				break;
	};

	cout << "\nEvento: " << setw(tipoEvento.length())  << tipoEvento << endl;
	cout << "Razao: "  << setw(razao.length() + 1)       << razao << endl;
	cout << "Medico: " << setw(nome_medico.length()) << nome_medico << endl;
	cout << "Data: "   << ctime(&dataEvento);
	if (tipoEvento=="Internamento"){
		cout << "Duracao: "   << setw(to_string(duracao).length()) << to_string(duracao) << " dias" << endl;
		cout << "Data alta: " << ctime(&alta);
	}

}

