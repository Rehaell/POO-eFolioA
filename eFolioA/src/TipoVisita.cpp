/*
 * TipoVisita.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: romaor
 */

#include "TipoVisita.h"
#include <ctime>

string TipoVisita::showVisitas() const {
	time_t t = time_t(system_clock::to_time_t(consulta_operacao.data));
	return "\nRazao: " + consulta_operacao.razao + "\nMedico: " + consulta_operacao.nome_medico + "\nData: " + ctime(&t);
}

