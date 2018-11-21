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

#include "TipoVisita.h"

using namespace std;

class Paciente {
	unsigned short genero;
	string nome_paciente;
	string nome_dono;
	unsigned int telefone;
	string morada;
	string raca;
	int idade;

public:
	vector<TipoVisita> registo_visitas; //PASSAR PARA PRIVATE, PUBLICO SO PARA FASE DE TESTE

	Paciente();
	Paciente(unsigned short generop, string nomep, string nomed, unsigned int telefonep, string moradap, string racap, int idadep);
	~Paciente(){}

	inline void setGenero(unsigned short cgenero) { genero = cgenero; }
	inline void setNomePaciente(string cnome) { nome_paciente = cnome; }
	inline void setNomeDono(string cnome) { nome_dono = cnome; }
	inline void setTelefone(int ctelefone) { telefone = ctelefone; }
	inline void setMorada(string cmorada) { morada = cmorada; }
	inline void setRaca(string craca) { raca = craca; }
	inline void setIdade(int cidade) { idade = cidade; }

	void setVisita(TipoVisita visita);

	inline int getNumVisitas() { return registo_visitas.size(); }

	string showPacientes() const;
};


#endif /* PACIENTE_H_ */
