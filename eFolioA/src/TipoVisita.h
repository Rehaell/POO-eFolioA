/*
 * tipovisita.h
 *
 *  Created on: Nov 20, 2018
 *      Author: rui romao
 */

#ifndef TIPOVISITA_H_
#define TIPOVISITA_H_

#include <string>
#include <chrono>
#include <iostream>
#include <iomanip>


using namespace std;
using namespace chrono;

class TipoVisita {
	enum TipoEvento {
		consulta = 1,
		operacao,
		internamento
	} evento;
	string razao;
	string nome_medico;
	system_clock::time_point data;
	int duracao;
	system_clock::time_point data_alta;

public:
		TipoVisita(): evento(consulta), razao(""), nome_medico(""), data(system_clock::now()), duracao(0), data_alta(system_clock::now()){}
		TipoVisita(int event, string reason, string medic, system_clock::time_point date, int length);
		~TipoVisita(){}

		system_clock::time_point getData() const { return data; }

		bool operator > (const TipoVisita& v) const { return (data >= v.getData()); }

		void showVisita() const;
};


#endif /* TIPOVISITA_H_ */
