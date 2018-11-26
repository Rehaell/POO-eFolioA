/*
 * paciente.h
 *
 *  Created on: Nov 20, 2018
 *      Author: rui romao
 */

#ifndef PACIENTE_H_
#define PACIENTE_H_

#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>
#include <iostream>
#include <iomanip>

#include "TipoVisita.h"

using namespace std;

class Paciente {
	enum Genero {
		CAO = 1,
		GATO
	} genero;
	string nome_paciente;
	string nome_dono;
	unsigned int telefone;
	string morada;
	string raca;
	int idade;

	int num_consulta;
	int num_operacoes;
	int num_internamento;

	vector<TipoVisita> registo_visitas;

public:

	Paciente(): genero(CAO), nome_paciente(""), nome_dono(), telefone(0), morada(""), raca(""), idade(0), num_consulta(0), num_operacoes(0), num_internamento(0) {}
	Paciente(int generop, string nomep, string nomed, unsigned int telefonep, string moradap, string racap, int idadep);
	~Paciente(){}

	inline void setGenero(int cgenero) { genero = Genero(cgenero); }
	inline void setNomePaciente(string cnome) { nome_paciente = cnome; }
	inline void setNomeDono(string cnome) { nome_dono = cnome; }
	inline void setTelefone(int ctelefone) { telefone = ctelefone; }
	inline void setMorada(string cmorada) { morada = cmorada; }
	inline void setRaca(string craca) { raca = craca; }
	inline void setIdade(int cidade) { idade = cidade; }

	void setVisita(TipoVisita visita);

	inline string getNome() { return nome_paciente; };

	inline unsigned int getVisitas() const { return registo_visitas.size(); }
	inline vector<TipoVisita> getRegisto() { return registo_visitas; }

	void showPacienteInfo(bool visitas) const;

	inline int getConsultas() const { return num_consulta; }
	inline int getOperacoes() const { return num_operacoes; }
	inline int getInternamento() const { return num_internamento; }
};


#endif /* PACIENTE_H_ */
