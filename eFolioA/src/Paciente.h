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

	vector<TipoVisita> registo_visitas; //PASSAR PARA PRIVATE, PUBLICO SO PARA FASE DE TESTE

public:

	Paciente(): genero(CAO), nome_paciente(""), nome_dono(), telefone(0), morada(""), raca(""), idade(0) {}
	Paciente(int generop, string nomep, string nomed, unsigned int telefonep, string moradap, string racap, int idadep);
	~Paciente(){}

	inline void setGenero(int cgenero) { genero = Genero(cgenero); }
	inline void setNomePaciente(string cnome) { nome_paciente = cnome; }
	inline void setNomeDono(string cnome) { nome_dono = cnome; }
	inline void setTelefone(int ctelefone) { telefone = ctelefone; }
	inline void setMorada(string cmorada) { morada = cmorada; }
	inline void setRaca(string craca) { raca = craca; }
	inline void setIdade(int cidade) { idade = cidade; }

	inline string getGenero() { return (genero == 1 ? "Cao" : "Gato"); }

	void setVisita(TipoVisita visita);

	inline int getNumVisitas() { return registo_visitas.size(); }

	void showPacienteInfo(bool visitas) const;

};


#endif /* PACIENTE_H_ */
