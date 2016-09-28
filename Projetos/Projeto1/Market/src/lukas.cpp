#include "lukas.h"

Lukas::Lukas()
{
    linked_queue = new LinkedQueue();
}

Lukas::~Lukas()
{
    //dtor
}

Lukas::Enqueue()
{
    linked_queue->enqueue(0);
    cout << "Queue Front | Esperado: 0, Resultado: " << linked_queue->front() << endl;
    cout << "Queue Back  | Esperado: 0, Resultado: " << linked_queue->back() << endl;
}
