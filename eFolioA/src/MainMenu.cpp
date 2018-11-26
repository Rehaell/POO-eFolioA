/*
 * MainMenu.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: rui romao
 */

#include "MainMenu.h"

// Funcoes de da classe MainMenu

/***************************************************************************
 * NOME: mostraMenuInicial                                                 *
 * ------------------------------------------------------------------------*
 * VARIAVEIS: NIL                                                          *
 * ------------------------------------------------------------------------*
 * FUNCAO: apresentar na consola o menu incial                             *
 *                                                                         *
 ***************************************************************************/
void MainMenu::mostraMenuInicial() const {
	cout<< "\n\n\n\n\n\n\n";
	cout << R"(
******************************************
*   CLINICA VETERINARIA DO ARCO DO CEGO  *
******************************************
* Por favor escolha uma opcao:           *
*----------------------------------------*
* Pacientes                              *
* 1 - Adicionar                          *
* 2 - Consultar/Remover                  *
*----------------------------------------*
* Compromissos                           *
* 3 - Consulta / Operacao / Internamento *
* 4 - Consultar                          *
*----------------------------------------*
* 0 - Sair                               *
******************************************
Pressione a tecla correspondente: )";

}

/***************************************************************************
 * NOME: adicionarPaciente                                                 *
 * ------------------------------------------------------------------------*
 * VARIAVEIS: Referencia para um vector de objectos do tipo Paciente       *
 * ------------------------------------------------------------------------*
 * FUNCAO: receber via input do utilizador os dados relativos a um dado    *
 *         cliente e guarda-los no vector pacientes.                       *
 *                                                                         *
 ***************************************************************************/
void MainMenu::adicionarPaciente(vector<Paciente>& pacientes){

	string nome, nomed, morada, raca;

	unsigned int genero, idade, telefone;

	cout<< "\n\n\n\n\n\n\n";

	do {
        cin.clear();
		cin.ignore();
		cout << "\nGenero (1 - Cao/ 2 - Gato): ";
		cin >> genero;
	} while (genero != 1 && genero != 2 && cin.fail());


	cin.ignore();
	cout << "Nome: ";
	getline(cin, nome); //utilizacao do getline para poder receber <espacos>

	cout << "Nome Dono: ";
	getline(cin, nomed);


	cout << "Telefone: ";
	cin >> telefone;


	cin.ignore();
	cout << "Morada: ";
	getline(cin, morada); //utilizacao do getline para poder receber <espacos>

	cout << "Raca: ";
	getline(cin, raca);

	cout << "Idade: ";
	cin >> idade;

	pacientes.push_back(Paciente(genero, nome, nomed, telefone, morada, raca, idade)); //criacao de um objecto do tipo Paciente e subsequente insercao no vector
}

/***************************************************************************
 * NOME: consultarCliente                                                  *
 * ------------------------------------------------------------------------*
 * VARIAVEIS: Referencia para um vector de objectos do tipo Paciente       *
 * ------------------------------------------------------------------------*
 * FUNCAO: apresenta na consola todos os clientes guardados no vector      *
 *         permite tambem a navegacao pelo vector pacientes e tem em conta *
 *         a positcao do iterador consoante a navegacao, para que nao      *
 *         exceda o range do vector pacientes                              *
 *                                                                         *
 *         Esta funcao permite ainda a remocao do cliente seleccionado     *
 *         atraves da sua remocao do vector pacientes                      *
 *                                                                         *
 ***************************************************************************/
void MainMenu::consultarCliente(vector<Paciente>& pacientes) {

	int escolha = 3;
	vector<Paciente>::iterator i = pacientes.begin(); //iterador usado para navegar no vector
	do {

		(*i).showPacienteInfo(false);
		cout << "Escolha (1) para retroceder, (2) para avancar, (3) para voltar ao menu inicial, e (0) para remover Paciente actual: ";
		cin >> escolha;
		switch(escolha) {
			case(1):
				if (i != pacientes.begin())
					--i;
				break;
			case(2):
				if (i != pacientes.end()-1)
					++i;
				break;
			case (0):
				pacientes.erase(i); //remove a posicao actual iterada por i e retorna ao menu principal
				escolha = 3;
				break;
			default:
				break;
		}
	} while(escolha != 3);

}

/***************************************************************************
 * NOME: setVisita                                                         *
 * ------------------------------------------------------------------------*
 * VARIAVEIS: Referencia para um iterador de um vector do tipo Paciente    *
 * ------------------------------------------------------------------------*
 * FUNCAO: recebe um iterador i que retorna um objecto do tipo Paciente    *
 *         num vector de objectos Paciente, e adiciona uma visita ao       *
 *         objecto Paciente iterado por i
 *                                                                         *
 ***************************************************************************/
void MainMenu::setVisita(vector<Paciente>::iterator& i){

	int evento, duracao = 0;
	string razao, nome_medico, data;

	tm tm = {0};
	int mes, dia, ano, hora, min;

	do {
        cin.clear();
		cin.ignore();
		cout << "Selecione o tipo de evento (1 - Consulta / 2 - Operacao / 3 - Internamento): ";
		cin >> evento;
	} while (evento != 1 && evento != 2 && evento != 3 && cin.fail());

	cin.ignore();
	cout << "Qual a razao da visita: ";
	getline(cin, razao);

	cout << "Qual o nome do medico: ";
	getline(cin, nome_medico);

	cout << "Qual a data da visita (MM/DD/AAAA HH:MM): ";
	getline(cin, data);

	sscanf(data.c_str(), "%2d/%2d/%4d %2d:%2d", &mes, &dia, &ano, &hora, &min);
	tm.tm_mon = mes - 1;
	tm.tm_mday = dia;
	tm.tm_year = ano - 1900;
	tm.tm_hour = hora;
	tm.tm_min = min;

	if(evento == 3) {
		cin.ignore();
		cout << "Qual a duracao do internamento: ";
		cin >> duracao;
	}

	TipoVisita visita(evento, razao, nome_medico, mktime(&tm), duracao); //cria um objecto do tipo TipoVisita

	(*i).setVisita(visita); //atribui uma visita a um objecto Pa	ciente iterado por i
}

/***************************************************************************
 * NOME: adicionarEvento                                                   *
 * ------------------------------------------------------------------------*
 * VARIAVEIS: Referencia para um iterador de um vector do tipo Paciente    *
 * ------------------------------------------------------------------------*
 * FUNCAO: recorre a funcao setVisita para adicionar um evento a um        *
 *         determinado objecto do tipo Paciente. Permite tambem percorrer  *
 *         o vector pacientes e verificar todos os eventos atribuidos a um *
 *         determinado paciente                                            *
 *                                                                         *
 ***************************************************************************/
void MainMenu::adicionarEvento(vector<Paciente>& pacientes) {
	int escolha = 10;
	vector<Paciente>::iterator i = pacientes.begin(); //iterador para um vector do tipo Paciente
	do {

		(*i).showPacienteInfo(false);
		cout << "Escolha (1) para retroceder, (2) para avancar, (3) para voltar ao menu inicial, e (6) para adicionar evento: ";
		cin >> escolha;
		switch(escolha) {
			case(1):
				if (i != pacientes.begin())
					--i;
				break;
			case(2):
				if (i != pacientes.end()-1)
					++i;
				break;
			case (6):
				setVisita(i); //adiciona uma visita ao objecto actual do tipo Paciente
				i = pacientes.begin();
				break;
			default:
				break;
		}
	} while(escolha != 3);
}


/***************************************************************************
 * NOME: consultarVisitas                                                  *
 * ------------------------------------------------------------------------*
 * VARIAVEIS: Referencia para um iterador de um vector do tipo Paciente    *
 * ------------------------------------------------------------------------*
 * FUNCAO: permite consultar visitas na sua totalitade, por cliente, ou    *
 *         por mes. Quando selecionada a opcao 1 o programa mostra todos   *
 *         os clientes presentes na base de dados e os seus respectivos    *
 *         eventos. A opcao numero 2 mostra apenas os totais de visitas    *
 *         por tipo de evento, e a opcao 3 mostra os totais de visitas por *
 *         tipo de evento organizado por mes
 *                                                                         *
 ***************************************************************************/
void MainMenu::consultarVisitas(vector<Paciente>& pacientes) {

	int escolha = 3;

	do {
		cout<< "\n";
		cout << R"(
******************************************
*   CLINICA VETERINARIA DO ARCO DO CEGO  *
******************************************
* Por favor escolha uma opcao:           *
*----------------------------------------*
* Compromissos                           *
* 1 - Todos                              *
* 2 - Sumario por cliente                *
* 3 - Sumario por mes                    *
*----------------------------------------*
* 4 - Voltar                             *
******************************************
Pressione a tecla correspondente: )";
		cin >> escolha;
		switch (escolha) {
			case (1):
				for(unsigned int i = 0; i < pacientes.size(); ++i)
					pacientes[i].showPacienteInfo(true);
				break;
			case (2):
				for(unsigned int i = 0; i < pacientes.size(); ++i) { //percorre o vector e imprime o nome do paciente e as respectivas visitas
					cout << "\nPaciente: " << pacientes[i].getNome() << endl;
					cout << "Total de Visitas: " << pacientes[i].getVisitas() << endl;
					cout << "Total de Consultas" << pacientes[i].getConsultas() << endl;
					cout << "Total de Operacoes: " << pacientes[i].getOperacoes() << endl;
					cout << "Total de Internamentos: " << pacientes[i].getInternamento() << endl;
				}
				break;
			case (3):
				OcorrenciasPorMes(pacientes);
				break;
			default:
				break;
		};
	} while (escolha != 4);

}

/***************************************************************************
 * NOME: OcorrenciasPorMes                                                  *
 * ------------------------------------------------------------------------*
 * VARIAVEIS: Referencia para um iterador de um vector do tipo Paciente    *
 * ------------------------------------------------------------------------*
 * FUNCAO: imprime um vector de objectos do tipo Mes de tamanho fixo 12    *
 *         e que corresponde aos 12 meses do ano. Cada posicao do vector   *
 *         armazenda na sua estrutura uma contagem do total de tipo de     *
 *         evento realizado nesse mes                                      *
 *                                                                         *
 ***************************************************************************/
void MainMenu::OcorrenciasPorMes(vector<Paciente>& pacientes) {

	struct Mes{
		int consultas = 0;
		int operacoes = 0;
		int internamentos = 0;
	};

	vector<Mes> meses(12);

	for(unsigned int i = 0; i < pacientes.size(); ++i){
		vector<TipoVisita> visitas = pacientes[i].getRegisto();
		for(unsigned int j = 0;  j< visitas.size(); ++j){
			time_t t = visitas[j].getData();
			tm* tm = localtime(&t); //retorna a data da visita
			if (visitas[j].getTipoEvento() == 1){
				meses[tm->tm_mon].consultas += 1; //itera no vector meses, na posicao dada pelo mes e soma +1 ao tipo de evento correspondente
			} else if (visitas[j].getTipoEvento() == 2){
			 	meses[tm->tm_mon].operacoes += 1; //itera no vector meses, na posicao dada pelo mes e soma +1 ao tipo de evento correspondente
			} else if (visitas[j].getTipoEvento() == 3){
				meses[tm->tm_mon].internamentos+= 1; //itera no vector meses, na posicao dada pelo mes e soma +1 ao tipo de evento correspondente
			}
		}
	}

	//no final, percorre o vector meses e imprime todas os meses e as respectivas contagens de eventos por tipo
	for(unsigned int i=0; i<meses.size(); ++i ) {
		cout << "\nOcorrencias mes: " << i + 1<< endl;
		cout << "Consultas : " << meses[i].consultas << endl;
		cout << "Operacoes : " << meses[i].operacoes << endl;
		cout << "Internamentos : " << meses[i].internamentos << endl;
	}
}
