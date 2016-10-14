/*!
 *  \author Luiz Felipe Ribeiro Baroncello
 *  \author Lukas Derner Grüdtner
 *  \version 1.0
 *  \copyright General Public License version 2
 *
 */

#ifndef CONTROL_H
#define CONTROL_H

#include <string>
#include <fstream>
#include <sstream>

#include "market.h"

using namespace std;

namespace read {

//! Classe Control
/*!
 *  Na classe Controle é implementado os métodos para abrir, ler e fechar o
 *  arquivo. Assim como métodos para inicialização do Mercado com seus atributos
 *  e a inicialização dos Caixas.
 */

class Control
{
    public:
        /*!
         *  Construtor.
         */
        Control();

        void type_of_entry();
        /*!
         *  Abre arquivo
         *  \param ifstream& file.dat para ser aberto.
         */
        void open_file(std::ifstream &);

        /*!
         *  Lê arquivo.
         *  \param ifstream& file.dat para ser lido e carregado.
         */
        void read_file(std::ifstream &);

        /*!
         *  Fecha arquivo.
         *  \param ifstrem& file.dat para ser fechado.
         */
        void close_file(std::ifstream &);

        /*!
         *  Verifica se a linha é comentário.
         * \param ifstream& file.dat para verificar se a linha é um comentário.
         */
        bool read_comment(std::ifstream &);

        /*!
         *  Insere os valores do vetor para os atributos do Mercado.
         *  \param buffer[] vetor do tipo string.
         */
        void insert(std::string buffer[]);

        std::string get_market_name();
        unsigned int get_time_of_simulation_in_hours();
        unsigned int get_average_arrival_time_of_customers_in_seconds();
        unsigned int get_number_of_market_box();

    private:
        ifstream file;  /*!< Arquivo. */
        std::string line;   /*!< Linha, uma variável do tipo string. */
        std::string market_name;    /*!< Nome do mercado, do tipo string. */
        unsigned int time_of_simulation_in_hours;   /*!< Tempo de simulação. */
        unsigned int average_arrival_time_of_customers_in_seconds;  /*!< Tempo médio de chegada de clientes. */
        unsigned int number_of_market_box;  /*!< Número de caixas do mercado. */
        Market* market; /*!< Ponteiro para a instância do Mercado. */
};

}

#endif
