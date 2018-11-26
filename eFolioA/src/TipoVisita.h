/*
 * tipovisita.h
 *
 *  Created on: Nov 20, 2018
 *      Author: rui romao
 */

#ifndef TIPOVISITA_H_
#define TIPOVISITA_H_

#include <string>
#include <iostream>
#include <iomanip>


using namespace std;


class TipoVisita {
	enum TipoEvento {
		consulta = 1,
		operacao,
		internamento
	} evento;
	string razao;
	string nome_medico;
	time_t data;
	int duracao;
	time_t data_alta;

public:
		TipoVisita(): evento(consulta), razao(""), nome_medico(""), data(time(0)), duracao(0), data_alta(time(0)){}
		TipoVisita(int event, string reason, string medic, time_t date, int length);
		~TipoVisita(){}

		time_t getData() const { return data; }

		inline int getTipoEvento () const { return evento; }

		bool operator > (const TipoVisita& v) const { return difftime(data, v.getData()) >= 0.0 ? true : false; }

		void showVisita() const;
};


#endif /* TIPOVISITA_H_ */
