/*
 * efolioa.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: rui romao
 */

#include <iostream>
#include <vector>
#include <thread>


#include "Paciente.h"
#include "TipoVisita.h"

int main(){

	//Cria pacientes automaticamente

	vector<Paciente> tPacientes;

	for(unsigned int i = 0; i <10; ++i){
		Paciente animal;
		animal.setIdade(rand() % 10 + 1); //atribui uma idade random
		animal.setMorada("Rua numero " + to_string(i) + ",Lote " + to_string(i) +", "+ to_string(i)+"  Andar");
		animal.setNomeDono("Nome_dono_" + to_string(i));
		animal.setNomePaciente("Nome_paciente_" + to_string(i));
		animal.setRaca("Raca_generica_numero" + to_string(i));
		animal.setTelefone(2100000 + i);

		unsigned int random_visitas = rand() % 10 + 1;
		for(unsigned int j = 0; j < random_visitas; ++j ){
			this_thread::sleep_for(std::chrono::seconds(1));
			TipoVisita visita;
			visita.setRazao("Visita normal numero " + to_string(j));
			visita.setNomeMedico("Doutor_numero_" + to_string(j));

			animal.setVisita(visita);
		}
		tPacientes.push_back(animal);
	}

	for(unsigned int i =0 ; i< tPacientes.size(); ++i){
		cout <<"\n*****************************************************";
		cout << tPacientes[i].showPacientes();
		for(unsigned int j = 0; j < tPacientes[i].getNumVisitas(); ++j) {
			cout <<"\n-----------------------------------------------------";
			cout << tPacientes[i].registo_visitas[j].showVisitas();
			cout <<"\n-----------------------------------------------------";
		}

		cout <<"\n*****************************************************\n";

	}

	return 0;
}



