/*
 * FuncoesApoio.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: rui romao
 */

#include <vector>
#include <thread>
#include <iostream>
#include <time.h>

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
void popularBaseDados(vector<Paciente>& tPacientes, unsigned int num_pacientes) {

	for(unsigned int i = 0; i <num_pacientes; ++i){
		Paciente animal;
		int random = 0;
		random = (rand()%(2-1))+1;
		animal.setGenero(random); //atribui um genero random entre 1 e 2
		random = rand() % 10 + 1;
		animal.setIdade(random); //atribui uma idade random
		animal.setMorada("Rua numero " + to_string(i) + ",Lote " + to_string(i) +", "+ to_string(i)+"  Andar"); //concatena uma morada com o iterador do vector
		animal.setNomeDono("Nome_dono_" + to_string(i)); //concatena o nome com o iterador do vector
		animal.setNomePaciente("Nome_paciente_" + to_string(i)); //concatena o nome do animal com o iterador do vector
		animal.setRaca("Raca_generica_numero_" + to_string(i)); //concatena uma raca generica com o iterador do vector
		animal.setTelefone(2100000 + i);

		unsigned int random_visitas = rand() % 10 + 1; //gera um numero random de visitas por paciente
		for(unsigned int j = 0; j < random_visitas; ++j ){
			this_thread::sleep_for(std::chrono::seconds(1));
			int tipoevento = rand() % 3 + 1; //atribui um evento random de 1 a 3 (consulta, operacao, internamento)
			int duracao = rand() % 10 + 1;
			TipoVisita visita( tipoevento , "Visita normal numero " + to_string(j),"Nome_medico_" + to_string(j) , std::time(0), duracao );

			animal.setVisita(visita);
		}
		tPacientes.push_back(animal); //adiciona os dados gerados random ao vector passado por referencia
	}
}




