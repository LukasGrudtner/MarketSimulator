/*!
 *  \author Luiz Felipe Ribeiro Baroncello
 *  \author Lukas Derner Grüdtner
 *  \version 1.0
 *  \copyright General Public License version 2
 *
 */

#ifndef USERINTERACTION_H
#define USERINTERACTION_H

#include <string>

using namespace std;

//! Classe InteracaoUsuario
/*!
 * Na classe InteracaoUsuario e implementado os metodos para entrada e saida
 * de dados para o usuario.
 */
class UserInteraction
{
    public:
        /*!
         *  Construtor.
         */
        UserInteraction();
        /*!
         *  Destrutor.
         */
        virtual ~UserInteraction();

        /*!
         * Retorna um bool, sendo true quando o usuario decide por entrada de
         * parametros por meio de arquivo, e falso se decidir por entrada manual.
         */
        bool select_entry_with_file();

        /*!
         * Envia uma mensagem ao usuario e retorna sua resposta em uma string.
         */
        string get_string(string msg);

        /*!
         * Envia uma mensagem ao usuario junto com um indice
         * e retorna sua resposta em uma string.
         */
        string get_string_with_index(string msg, int index);

        /*!
         * Envia uma mensagem ao usuario e retorna sua resposta em um inteiro.
         */
        unsigned int get_unsigned_int(string msg);

        /*!
         * Envia uma mensagem ao usuario junto com um indice
         * e retorna sua resposta em um inteiro.
         */
        unsigned int get_unsigned_int_with_index(string msg, int index);

        /*!
         * Envia uma mensagem ao usuario junto com um indice
         * e retorna sua resposta em um double.
         */
        double get_double_with_index(string msg, int index);

    protected:

    private:
};

#endif // USERINTERACTION_H
