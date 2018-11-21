/*
 * FuncoesApoio.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: rui romao
 */

#include <vector>
#include <thread>
#include <iostream>

#include "Paciente.h"
#include "TipoVisita.h"

/***************************************************************************
 * NOME: popularBaseDados                                                  *
 * ------------------------------------------------------------------------*
 * VARIAVEIS: Referencia para um vector de objectos do tipo Paciente       *
 * ------------------------------------------------------------------------*
 * FUNCAO: Popular a base de dados automaticamente com valores aleatorios  *
 *         cada vez que o programa e inicializado                          *
 *                                                                         *
 ***************************************************************************/
void popularBaseDados(vector<Paciente>& tPacientes) {

	for(unsigned int i = 0; i <10; ++i){
		Paciente animal;
		animal.setGenero((rand()%(2-1))+1);
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
}

/***************************************************************************
 * NOME: mostrarBaseDados                                                  *
 * ------------------------------------------------------------------------*
 * VARIAVEIS: Referencia para um vector de objectos do tipo Paciente       *
 * ------------------------------------------------------------------------*
 * FUNCAO: Imprime na consola o conteudo do vector pacientes para efeitos  *
 *         de troubleshooting                                              *
 *                                                                         *
 ***************************************************************************/
void mostrarBaseDados(vector<Paciente>& tPacientes){
	for(unsigned int i =0 ; i< tPacientes.size(); ++i){
		cout <<"\n*****************************************************";
		cout << tPacientes[i].showPacientes();
		for(int j = 0; j < tPacientes[i].getNumVisitas(); ++j) {
			cout <<"\n-----------------------------------------------------";
			cout << tPacientes[i].registo_visitas[j].showVisitas();
			cout <<"\n-----------------------------------------------------";
		}

		cout <<"\n*****************************************************\n";
	}

}




