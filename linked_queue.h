#include <cstdint>
#include <stdexcept> 

namespace structures {

template<typename T>

//! Classe LinkedStack para uma Fila.
/*! 
*   Na classe LinkedStack, e implementado o funcionamento de uma fila
*   encadeada.
*/
class LinkedQueue {
public:

//! Construtor.
/*!
*   Construtor que inicializa o elemento head que sera usado como inicio para a fila.
*/
    LinkedQueue(){
        head = new Node(0u);
        tail = NULL;
        size_ = 0;
    }

//! Destrutor.
/*!
*   Deleta todos os elementos da fila.
*   \sa clear()
*/
    ~LinkedQueue(){
        clear();
        delete head;
    }

//! Funcao reponsavel por limpar a fila.
/*!
*   Faz com que a fila seja limpa.
*   \sa empty(), dequeue()
*/
    void clear(){
        while(!empty()){
            dequeue();
        }
    }

//! Função reponsavel por adicionar um elemento na fila.
/*!
*   Adiciona um elemento no fim da fila.
*   \param data dado a ser adicionado. 
    \sa empty()
*/
    void enqueue(const T& data){
        Node* novo = new Node(data);
      
        if (empty()) {
            head->next(novo);
        }else{
            tail->next(novo);
        }
        tail = novo;
        size_++;
    } 

//! Funcao reponsavel por retornar e retirar o primeiro elemento da fila.
/*!
*   \return retorna o primeiro dado da fila".
*   \sa empty(), size()
*/
    T dequeue(){
        Node *saiu;
        T volta;
        if(empty())
            throw std::out_of_range("filaVazia");
        else{
            saiu = head->next();
            volta = saiu->data();
            if(size() != 1)
                head->next(saiu->next());
            size_--;
            delete saiu;
            
            return volta;
        } 
    }

/*!
*   \return Retorna o elemento no começo da fila.
*/
    T& front() const{
        if (empty())
            throw std::out_of_range("filaVazia");
        else
            return head->next()->data();
    }

/*!
*   \return Retorna o elemento no fim da fila.
*/
    T& back() const{
        if (empty())
            throw std::out_of_range("filaVazia");
        else{
            return tail->data();
        }
        
    }

//! Funcao responsavel por verificar se a fila esta vazia.
/*!
*   Retorna true se a fila estiver vazia.
*   \return uma variavel booleana.
*/
    bool empty() const{
        return size_ == 0;
    }

//! Funcao reponsavel por retornar a quantidade de dados.
/*!
*   Retorna a quantidade de dados que se encontram na fila.
*   \return um valor.
*/
    std::size_t size() const{
        return size_;
    }


private:

//! Classe Node para referenciar dado e proximo elemento na fila.
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
*   \return um T.  
*/
        T& data() {
            return data_;
        }

/*!
*   Retorna o dado que esta salvo.   
*   \return um T.
*/
        const T& data() const {
            return data_;
        }


/*!
*   Retorna o proximo elemento. 
*   \return um Node.  
*/
        Node* next() {
            return next_;
        }

/*!
*   Retorna o proximo elemento. 
*   \return um Node.
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

    Node* head;                 /*!< O proximo elemento de head eh o inicio da fila. */
    Node* tail;                 /*!< Representa o ultimo elementp da fila. */
    std::size_t size_;          /*!< Tamanho da fila. */
};

}
