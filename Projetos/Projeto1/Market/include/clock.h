#ifndef CLOCK_H
#define CLOCK_H

#include "time.h"

//! Classe Clock para constrolar o tempo de simulacao.
class Clock
{
    public:
        /*!
        *   Construtor.
        */
        Clock();

        /*!
        *   Destrutor.
        */
        ~Clock();

        /*!
        *   Adiciona n segundos ao tempo decorido.
        *   \param seconds tempo a ser adicionado.
        */
        void add_seconds(const unsigned int& seconds);

        /*!
        *   Adiciona um segundo ao contador.
        */
        void set_one_more_second();

        /*!
        *   Retorna o tempo.
        *   \return tempo correspondente ao tempo do contador.
        */
        const Time* get_time() const;

    private:
        Time* time = new Time(); /*!< Tempo. */

};

#endif // CLOCK_H
