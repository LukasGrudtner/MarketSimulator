#ifndef TIME_H
#define TIME_H


//! Classe Time para tempos gerais.
class Time
{
    public:
        /*!
        *   Construtor.
        */
        Time();

        /*!
        *   Construtor.
        *   \param tempo predefinido.
        */
        Time(unsigned int& time);

        /*!
        *   Adiciona n segundos ao tempo decorido.
        *   \param seconds tempo a ser adicionado.
        */
        void add_seconds(const unsigned int& seconds);

        /*!
        *   Retorna tempo em segundos.
        *   \param inteiro correspondente ao tempo em segundos.
        */
        const int& get_time_in_seconds() const;

        /*!
        *   Retorna tempo em minutos.
        *   \param inteiro correspondente ao tempo em minutos.
        */
        const int& get_time_in_minutes() const;

        /*!
        *   Retorna tempo em horas.
        *   \param inteiro correspondente ao tempo em horas.
        */
        const int& get_time_in_hours() const;

    private:
        unsigned int time_in_seconds; /*!< Tempo em segundos. */

};

#endif // TIME_H
