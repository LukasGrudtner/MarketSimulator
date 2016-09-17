#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ Exceptions

namespace structures {

template<typename T>

//! Classe ArrayQueue para uma Lista.
/*! 
*   Na classe ArrayQueue, é implementado o funcionamento de uma fila
*   através de um vetor.
*/

class ArrayQueue {
public:

//! Construtor sem parametros.
/*!
*   Construtor que inicializa a fila com um valor pré-definido.
*/
    ArrayQueue(){
        max_size_ = DEFAULT_SIZE;
        size_ = -1;
        contents = new T[DEFAULT_SIZE];
    }

//! Construtor com parametros.
/*!
*   Construtor que recebe o tamanho máximo da fila.
*   \param max uma variável que determina o tamanho da fila.
*/
    ArrayQueue(std::size_t max){
        max_size_ = max;
        size_ = -1;
        contents = new T[max];
    }

//! Destrutor.
/*!
*   Deleta o vetor que contém a lista.
*/
    ~ArrayQueue(){
        delete[] contents;
    }

//! Função reponsável por enfileirar.
/*!
*   Enfileira um dado.
*   \param data referência de uma constante do dado que será adicionado à fila.
*   \sa full()
*/
    void enqueue(const T& data){
        if(full())
            throw std::out_of_range("listaCheia");
        else{
            size_++;
            contents[size_] = data;
        }
    }

//! Função reponsável por desenfileirar.
/*!
*   Desenfileira um dado.
*   \sa empty()
*   \return um dado.
*/
    T dequeue(){
        if(empty())
            throw std::out_of_range("listaVazia");
        else{
            size_--;
            T firstElement = contents[0];
            for(int i = 0; i < size_+1; i++){
                contents[i] = contents[i+1];
            }
            return firstElement;
        }
    }
    
//! Função reponsável por devolver o final da fila.
/*!
*   Devolve o final da fila.
*   \return um dado.
*   \sa empty()
*/
    T& back(){
        if(empty())
            throw std::out_of_range("listaVazia");
        else
            return contents[size_];
    }

//! Função reponsável por limpar a fila.
/*!
*   Faz com que a fila seja limpa.
*/
    void clear(){
        size_ = -1;
    }

//! Função reponsável por retornar a quantidade de dados.
/*!
*   Retorna a quantidade de dados que se encontram na fila.
*   \return um valor.
*/
    std::size_t size(){
        return size_+1;
    }

//! Função reponsável por retornar o tamanho máximo da fila.
/*!
*   Retorna o tamanho máximo da fila.
*   \return um valor.
*/
    std::size_t max_size(){
        return max_size_;
    }

//! Função responsável por verificar se a fila está vazia.
/*!
*   Retorna true se a fila estiver vazia.
*   \return uma variável booleana.
*/
    bool empty(){
        return size_ == -1;
    } 

//! Função responsável por verificar se a fila está cheia.
/*!
*   Retorna true se a fila estiver cheia.
*   \return uma variável booleana.
*/
    bool full(){
        return size_ == (max_size_ - 1);
    } 

private:
    
    T* contents;            /*!< Vetor no qual a fila é implementada. */
    std::size_t size_;      /*!< Valor que indica o final da fila. */
    std::size_t max_size_;  /*!< É o máximo de elementos que se pode enfileirar. */       

    const static auto DEFAULT_SIZE = 10u;
};

}

#endif
