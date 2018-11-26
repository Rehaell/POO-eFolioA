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
	//Enum para guardar o tipo de eventos
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

		//Compara dois objectos do TipoVisita, calculando a diferenca entre as suas datas, se a diferenca for negativa
		//significa que o objecto corrente e' menor que o objecto a que queremos comparar
		inline bool operator > (const TipoVisita& v) const { return difftime(data, v.getData()) >= 0.0 ? true : false; }

		//Mostra os detalhes de uma dada visita
		void showVisita() const;
};


#endif /* TIPOVISITA_H_ */
