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
#include "TipoVisita.h"

using namespace std;

class Paciente{
	//string genero; FALTA IMPLEMENTAR
	string nome_paciente;
	string nome_dono;
	unsigned int telefone;
	string morada;
	string raca;
	int idade;

public:
	vector<TipoVisita> registo_visitas; //PASSAR PARA PRIVATE, PUBLICO SO PARA FASE DE TESTE

	Paciente();
	~Paciente(){}

	void setNomePaciente(string cnome) { nome_paciente = cnome; }
	void setNomeDono(string cnome) { nome_dono = cnome; }
	void setTelefone(int ctelefone) { telefone = ctelefone; }
	void setMorada(string cmorada) { morada = cmorada; }
	void setRaca(string craca) { raca = craca; }
	void setIdade(int cidade) { idade = cidade; }
    void setVisita(TipoVisita visita);

    int getNumVisitas() { return registo_visitas.size(); }
	string showPacientes() const;
};


#endif /* PACIENTE_H_ */
