#ifndef LUKAS_H
#define LUKAS_H
#include "linked_queue.h"
#include <iostream>
#include "client.h"
#include "market_box.h"

using namespace std;

class Lukas
{
    public:
        Lukas()
        {
            TESTLinkedQueue();
            TESTMarketBox();
        }
        virtual ~Lukas(){}

        TESTLinkedQueue()
        {
            cout << "===================LINKED QUEUE===================" << endl;
            LinkedQueue* lqueue = new LinkedQueue();
            Client* client = new Client();

            cout << "Empty | 1 = " << lqueue->empty() << endl;
            lqueue->enqueue(*client);
            cout << "Empty | 0 = " << lqueue->empty() << endl;
            lqueue->enqueue(*client);
            cout << "Num People | 2 = " << lqueue->num_people_proc() << endl;
            lqueue->dequeue();
            lqueue->dequeue();
            cout << "Num People | 0 = " << lqueue->num_people_proc() << endl;
            cout << "===================LINKED QUEUE===================\n" << endl;
        }

        TESTMarketBox()
        {
            cout << "===================MARKET BOX===================" << endl;
            MarketBox* box = new MarketBox();
            cout << "MarketBox initialized." << endl;
            cout << "===================MARKET BOX===================" << endl;
        }

    protected:

    private:
};

#endif // LUKAS_H
