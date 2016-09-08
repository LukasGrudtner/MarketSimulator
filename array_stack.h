#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>
#include <stdexcept> 

namespace structures {

template<typename T>

//! Classe ArrayStack para uma Pilha.
/*! 
*   Na classe ArrayStack, é implementado o funcionamento de uma pilha
*   através de um vetor.
*/

class ArrayStack {  
public:

//! Construtor sem parametros.
/*!
*   Construtor que inicializa a pilha com um valor pré-definido.
*/
    ArrayStack(){
        max_size_ = DEFAULT_SIZE;
        contents = new T[DEFAULT_SIZE];
        top_ = -1;
    }

//! Construtor com parametros.
/*!
*   Construtor que recebe o tamanho máximo da pilha.
*   \param max uma variável que determina o tamanho da pilha.
*/
    ArrayStack(std::size_t max){
        max_size_ = max;
        contents = new T[max];
        top_ = -1;
    }

//! Destrutor.
/*!
*   Deleta o vetor que contém a pilha.
*/
    ~ArrayStack(){
        delete[] contents;
    }

//! Função reponsável por empilhar.
/*!
*   Empilha um dado.
*   \param data referência de uma constante do dado que será adicionado à pilha.
*   \sa full()
*/
    void push(const T& data){
        if(full())
            throw std::out_of_range("pilhaCheia");
        else{
            top_++;
            contents[top_] = data;
        }
    } 

//! Função reponsável por desempilhar.
/*!
*   Desempilha um dado.
*   \sa empty()
*   \return um dado.
*/
    T pop(){
        if(empty())
            throw std::out_of_range("pilhaVazia");
        else{
            top_--;
            return contents[top_+1];
        }
    }

//! Função reponsável por devolver o topo.
/*!
*   Devolve o topo da pilha
*   \return um dado.
*   \sa empty()
*/
    T& top(){
        if(empty())
            throw std::out_of_range("pilhaVazia");
        else
            return contents[top_];
    }

//! Função reponsável por limpar a pilha.
/*!
*   Faz com que a pilha seja limpa.
*/
    void clear(){
        top_ = -1;
    }

//! Função reponsável por retornar a quantidade de dados.
/*!
*   Retorna a quantidade de dados que se encontram na pilha.
*   \return um valor.
*/
    std::size_t size(){
        return top_+1;
    }

//! Função reponsável por retornar o tamanho máximo da pilha.
/*!
*   Retorna o tamanho máximo da pilha.
*   \return um valor.
*/
    std::size_t max_size(){
        return max_size_;
    }

//! Função responsável por verificar se a pilha está vazia.
/*!
*   Retorna true se a pilha estiver vazia.
*   \return uma variável booleana.
*/
    bool empty(){
        return top_ == -1;
    } 

//! Função responsável por verificar se a pilha está cheia.
/*!
*   Retorna true se a pilha estiver cheia.
*   \return uma variável booleana.
*/
    bool full(){
        return top_ == (max_size_ - 1);
    } 

private:
    T* contents;            /*!< Vetor no qual a pilha é implementada. */
    int top_;               /*!< Inteiro que indica o topo da pilha. */
    std::size_t max_size_;  /*!< É o máximo de elementos que se pode empilhar. */

    const static auto DEFAULT_SIZE = 10u;
};

}

#endif
