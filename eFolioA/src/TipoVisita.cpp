/*
 * TipoVisita.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: romaor
 */
#include <ctime>

#include "TipoVisita.h"

TipoVisita::TipoVisita(int event, string reason, string medic, time_t date, int length){
	evento = TipoEvento(event);
	razao = reason;
	nome_medico = medic;
	data = date;
	if(event == internamento){
		duracao = length;
		struct tm* tm = localtime(&date);
		tm->tm_mday += length;
		data_alta = mktime(tm);
	}
	else
		duracao = 0;
}

void TipoVisita::showVisita() const {

	string tipoEvento = "";
	tm* now = localtime(&data);

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
	cout << "Data: "   << now->tm_mon << "/" << now->tm_mday << "/" << now->tm_year << " " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec<< endl;
	if (tipoEvento=="Internamento"){
		cout << "Duracao: "   << setw(to_string(duracao).length()) << to_string(duracao) << " dias" << endl;
		now = localtime(&data_alta);
		cout << "Data: "   << now->tm_mon << "/" << now->tm_mday << "/" << now->tm_year << " " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec<< endl;
	}

}

