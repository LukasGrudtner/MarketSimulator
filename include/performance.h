/*!
 *  \author Luiz Felipe Ribeiro Baroncello
 *  \author Lukas Derner Gr�dtner
 *  \version 1.0
 *  \copyright General Public License version 2
 *
 */

#ifndef PERFORMANCE_H
#define PERFORMANCE_H

//! Classe Performance para armazenar valores da performace de um caixa.
class Performance
{
    public:
        /*!
        *   Construtor.
        *   \param time_to_spend_card tempo para passar um cartao.
        *   \param time_to_spend_item tempo para passar um item.
        */
        Performance(const unsigned int& time_to_spend_card, const unsigned int& time_to_spend_item);

        /*!
        *   \return um inteiro correspondente ao tempo que o caixa demora para passar um item.
        */
        const unsigned int& get_time_to_spend_item() const;

        /*!
        *   \return um inteiro correspondente ao tempo que o caixa demora para passar o cart�o.
        */
        const unsigned int& get_time_to_spend_card() const;

    private:
        unsigned int time_to_spend_item_; /*!< Tempo para passar cada item. */
        unsigned int time_to_spend_card_; /*!< Tempo para passar um cart�o. */
};

#endif // PERFORMANCE_H
