#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept> 

namespace structures {

//! Classe ArrayList para uma Lista.
/*! 
*   Na classe ArrayList, é implementado o funcionamento de uma lista
*   através de um vetor.
*/

template<typename T>
class ArrayList {
public:

//! Construtor sem parametros.
/*!
*   Construtor que inicializa a lista com um número de elementos pré-definido.
*/
    ArrayList(){
        contents = new T[DEFAULT_SIZE];
        max_size_ = DEFAULT_SIZE;
        size_ = -1;
    }

//! Construtor com parametros.
/*!
*   Construtor que recebe o tamanho máximo da lista.
*   \param max uma variável que determina o tamanho da lista.
*/
    ArrayList(std::size_t max_size){
        contents = new T[max_size];
        max_size_ = max_size;
        size_ = -1;
    }

//! Destrutor.
/*!
*   Deleta o vetor que contém a lista.
*/
    ~ArrayList(){
        delete[] contents;
    }

//! Função responsável por verificar se a lista está vazia.
/*!
*   Retorna true se a lista estiver vazia.
*   \return uma variável booleana.
*/
    bool empty(){
        return size_ == -1;
    }

//! Função responsável por verificar se a lista está cheia.
/*!
*   Retorna true se a lista estiver cheia.
*   \return uma variável booleana.
*/
    bool full(){
        return size_+1 == max_size_;
    }

//! Função responsável por verificar se um elemento existe no vetor.
/*!
*   Retorna true se o elemento realmente se encontra no vetor.
*   \param data elemento a ser procurado na lista.
*   \return uma variável booleana.
*/
    bool contains(const T& data){
        for(int i = 0; i<max_size_; i++){
            if(data == contents[i])
                return true;
        }
        return false;
    }
    
//! Função responsável por retornar a posicao de um elemento no vetor.
/*!
*   Retorna a posicao atual de um elemento no vetor.
*   \param data elemento o qual se deseja saber a posicao.
*   \return um inteiro.
*/
    std::size_t find(const T& data) const{
        int atual = 0;
        
        while(atual <= size_ && data != contents[atual]){
            atual++;
        }
            return atual;
    }
    
//! Função responsável por sobre escrever o operador [].
/*!
*   Define que quando o operador [] for usado com um long, ira retornar o elemento na posicao correspondente ao long.
*   \param index posicao a qual sera usada para retornar o elemento.
*   \return o elemento correspondente a posicao.
*/
    T& operator[](std::size_t index){
        return contents[index];
    }
    
//! Função responsável por devolver o elemento na posicao index, além de garantir que o objeto nao sera alterado.
/*!
*   Devolve o elemento na posicao solicitada, e caso a mesma nao esteja correta lanca uma excecao.
*   \param index posicao a qual sera usada para retornar o elemento.
*   \return o elemento correspondente a posicao.
*   \sa empty()
*/
     const T& at(std::size_t index) const{
         if(empty() || index > size_)
             throw std::out_of_range("erroPosicao");
         else{
             return contents[index];
         }
     }
     
//! Função responsável por devolver o elemento na posicao index.
/*!
*   Devolve o elemento na posicao solicitada, e caso a mesma nao esteja correta lanca uma excecao. 
*   \param index posicao a qual sera usada para retornar o elemento.
*   \return o elemento correspondente a posicao.
*   \sa empty()
*/
    T at(std::size_t index){
         if(empty() || index > size_)
             throw std::out_of_range("erroPosicao");
         else{
             return contents[index];
         }
    }

//! Função responsável por sobre escrever o operador []. Além de garantir que o objeto não sera alterado.
/*!
*   Define que quando o operador [] for usado com um long, ira retornar o elemento na posicao correspondente ao long.
*   \param index posicao a qual sera usada para retornar o elemento.
*   \return o elemento correspondente a posicao.
*/
     const T& operator[](std::size_t index) const{
         return contents[index];
     }

//! Função reponsável por retornar a quantidade de dados.
/*!
*   Retorna a quantidade de dados que se encontram na lista.
*   \return um valor.
*/
    std::size_t size(){
        return size_+1;
    }
    
//! Função reponsável por retornar o tamanho máximo da lista.
/*!
*   Retorna o tamanho máximo da lista.
*   \return um valor.
*/
    std::size_t max_size(){
        return max_size_;
    }

//! Função reponsável por adicionar um elemento ao final da lista.
/*!
*   Adiciona um elemento ao final da lista.
*   \param data dado a ser adicionado no final da lista. 
*   \sa insert()
*/
    void push_back(T data){
       insert(data, size_+1);
    }

//! Função reponsável por adicionar um elemento no inicio da lista.
/*!
*   Adiciona um elemento no inicio da lista.
*   \param data dado a ser adicionado no inicio da lista. 
*   \sa insert()
*/
    void push_front(T data){
        insert(data, 0);
    }

//! Função reponsável por adicionar um elemento em uma posicao x da lista.
/*!
*   Adiciona um elemento na posicao solicitada.
*   \param data dado a ser adicionado na lista. 
*   \sa full()
*/
    void insert(T data, std::size_t index){
        int atual;
        
         if(full())
            throw  std::out_of_range("listaCheia");
        else{
            if(index > size_+1 || index < 0)
                throw std::out_of_range("posicaoInvalida");
            else{
                size_++;
                atual = size_;
                while(atual > index){
                    contents[atual] = contents[atual-1];
                    atual--;
                }
                contents[index] = data;
            }
        }
            
    }

//! Função reponsável por adicionar um elemento em ordem na lista.
/*!
*   Adiciona um elemento em ordem na lista.
*   \param data dado a ser adicionado na lista. 
*   \sa insert(), full()
*/
    void insert_sorted(T data){
        int atual;
        
        if(full())
            throw std::out_of_range("listaCheia");
        else{
            atual = 0;
            while(atual < size_+1 && data > contents[atual]){
                atual++;
            }
            insert(data,atual);
        } 
    }

//! Função reponsável por retornar e retirar um elemento de uma posicao x.
/*!
*   Retira um elemento da posicao que lhe foi solicitada e o retorna.
*   \param index posicao na qual o elemento se encontra.
*   \return o dado retirado.
*   \sa empty()
*/
    T pop(std::size_t index){
        T data;
        int atual;
        
        if(empty())
            throw std::out_of_range("listaVazia");
        else{
            if(index >= size_+1 || index < 0)
                throw std::out_of_range("posicaoInvalida");
            else{
                size_--;
                data = contents[index];
                atual = index;
                while(atual <= size_+1){
                    contents[atual] = contents[atual+1];
                    atual++;
                }
                return data;
            }
        }
        
    }

//! Função reponsável por retornar e retirar o primeiro elemento da lista.
/*!
*   Retira o primeiro elemento da lista.
*   \return o dado encontrado na primeira posicao da lista.
*   \sa pop()
*/
    T pop_front(){
        return pop(0);
    }

//! Função reponsável por retornar e retirar o ultimo elemento da lista.
/*!
*   Retira o ultimo elemento da lista.
*   \return o dado encontrado na ultima posicao da lista.
*   \sa pop()
*/
    T pop_back(){
        return pop(size_);
    }

//! Função reponsável por limpar a lista.
/*!
*   Faz com que a lista seja limpa.
*/
    void clear(){
        size_ = -1;
    }

//! Função reponsável por remover um dado da lista.
/*!
*   Remove um dado da lista.
*   \param data dado a ser removido.
*   \sa empty(), contains(), pop(), find()
*/
    void remove(T data){
        if(empty())
            throw std::out_of_range("listaVazia");
        else{
            if(contains(data)){
                pop(find(data));  
            }else{
                throw std::out_of_range("dataNotFound");
            }
        }
    }

private:
    T* contents;            /*!< Vetor no qual a lista é implementada. */
    std::size_t size_;      /*!< Posicao do ultimo elemento na lista. */
    std::size_t max_size_;  /*!< Tamanho maximo da lista    . */

    const static auto DEFAULT_SIZE = 10u;   /*!< Tamanho padrao da lista. */
};

}

#endif