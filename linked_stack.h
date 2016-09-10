#include <cstdint>
#include <stdexcept> 

namespace structures {

template<typename T>

//! Classe LinkedStack para uma Pilha.
/*! 
*   Na classe LinkedStack, e implementado o funcionamento de uma pilha
*   encadeada.
*/
class LinkedStack{
public:

//! Construtor.
/*!
*   Construtor que inicializa o elemento top_ que sera usado como topo para a pilha.
*/
    LinkedStack(){
        top_ = new Node(0u);
        size_ = 0;
    }
    
//! Destrutor.
/*!
*   Deleta todos os elementos da pilha.
*   \sa clear()
*/
    ~LinkedStack() {
        clear();
        delete top_;
    }

//! Funcao reponsavel por limpar a pilha.
/*!
*   Faz com que a pilha seja limpa.
*   \sa empty(), pop()
*/
    void clear() {
        while(!empty()){
            pop();
        }
    }

//! Função reponsavel por adicionar um elemento na pilha.
/*!
*   Adiciona um elemento no fim da pilha.
*   \param data dado a ser adicionado. 
    \sa empty()
*/
    void push(const T& data) {
        Node* novo = new Node(data);
        
        if(novo == NULL)
            throw std::out_of_range("pilhaCheia");
        else{
            if(!empty())
                novo->next(top_->next());
            top_->next(novo);
            size_++;
        }
    }

//! Funcao reponsavel por retornar e retirar o elemento da pilha.
/*!
*   \return retorna o ultimo dado da pilha".
*   \sa empty(), size()
*/
    T pop() {
        Node *saiu;
        T volta;
        if(empty())
            throw std::out_of_range("pilhaVazia");
        else{
            saiu = top_->next();
            volta = saiu->data();
            if(size() != 1)
                top_->next(saiu->next());
            size_--;
            delete saiu;
            
            return volta;
        } 
    }
    
/*!
*   \return Retorna o elemento no topo da pilha.
*/
    T& top() const{
        if (empty())
            throw std::out_of_range("pilhaVazia");
        else
            return top_->next()->data();   
    }

//! Funcao responsavel por verificar se a pilha esta vazia.
/*!
*   Retorna true se a pilha estiver vazia.
*   \return uma variavel booleana.
*/
    bool empty() const{
        return size_ == 0;
    }

//! Funcao reponsavel por retornar a quantidade de dados.
/*!
*   Retorna a quantidade de dados que se encontram na pilha.
*   \return um valor.
*/
    std::size_t size() const{
        return size_;
    }

private:

//! Classe Node para referenciar dado e proximo elemento na pilha.
/*!
*   Na classe Node sao implementados os metodos basicos para a referencia de um dado T e ao proximo Node.
*/
class Node {
public:

//! Construtor.
/*!
*   Construtor que referencia o dado a ser guardado atraves de parametro.
*   \param data dado que sera armazenado.
*/
        Node(const T& data):
            data_{data}
        {}

//! Construtor.
/*!
*   Construtor que referencia o dado a ser guardado e o proximo Node.
*   \param data dado que sera armazenado.
*   \param next ponteiro para o proximo Node.
*/
        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

/*!
*   Retorna o dado que esta salvo.  
*/
        T& data() {
            return data_;
        }

/*!
*   Retorna o dado que esta salvo.  
*/
        const T& data() const {
            return data_;
        }


/*!
*   Retorna o proximo elemento.  
*/
        Node* next() {
            return next_;
        }

/*!
*   Retorna o proximo elemento.  
*/
        const Node* next() const {
            return next_;
        }

/*!
*   Recebe um ponteiro indicando qual sera o proximo Node.
*   \param node.
*/
        void next(Node* node) {
            next_ = node;
        }
        
    private:
        T data_;                /*!< Dado contido. */
        Node* next_{nullptr};   /*!< Proximo Node. */
    };

    Node* top_;          /*!< Indica posicao do ultimo elemento da pilha. */
    std::size_t size_;   /*!< Indica tamanho da pilha. */
};

}