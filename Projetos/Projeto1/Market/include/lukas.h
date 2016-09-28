#ifndef LUKAS_H
#define LUKAS_H
#include "linked_queue.h"
#include <iostream>
#include "client.h"

using namespace std;

class Lukas
{
    public:
        Lukas()
        {
            lqueue = new LinkedQueue();
            client = new Client();
            Enqueue();
        }
        virtual ~Lukas(){}

        Enqueue()
        {
            cout << "Empty | 1 = " << lqueue->empty() << endl;
            lqueue->enqueue(*client);
            cout << "Empty | 0 = " << lqueue->empty() << endl;
            lqueue->enqueue(*client);
            cout << "Num People | 2 = " << lqueue->num_people_proc() << endl;
            lqueue->dequeue();
            lqueue->dequeue();
            cout << "Num People | 0 = " << lqueue->num_people_proc() << endl;
        }

    protected:

    private:
        LinkedQueue* lqueue;
        Client* client;
};

#endif // LUKAS_H
