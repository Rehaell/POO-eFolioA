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

using namespace std;
using namespace chrono;

class TipoVisita {
	//string tipo_evento; IMPLEMENTAR TIPO DE CONSULTA

	struct Consulta_operacao {
		string razao;
		string nome_medico;
		system_clock::time_point data;

		Consulta_operacao(): razao(""), nome_medico(""), data(system_clock::now()){}
		~Consulta_operacao(){}
	} consulta_operacao;

	struct Internamento: Consulta_operacao {
		int duracao;

		Internamento(): duracao(0){}
		//int getFinalDate(); IMPLEMENTAR SOMAR A DATA DE HOJE O NUMERO DE DIAS
	} internamento;

public:
		TipoVisita(){}
		~TipoVisita(){}

		void setRazao(string crazao) { consulta_operacao.razao = crazao; }
		void setNomeMedico(string cnome_medico){ consulta_operacao.nome_medico = cnome_medico; }
		void setDuracao(int cduracao) { internamento.duracao = cduracao; }

		system_clock::time_point getData() const { return consulta_operacao.data; }

		bool operator > (const TipoVisita& v) const { return (consulta_operacao.data >= v.getData()); }

		string showVisitas() const;

};


#endif /* TIPOVISITA_H_ */
