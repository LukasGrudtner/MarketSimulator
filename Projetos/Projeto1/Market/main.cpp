#include <iostream>
#include <stdio.h>
#include "performance.h"

using namespace std;

int main()
{
    cout << "============Test1=============\n";

    Performance* teste = new Performance(60u, 4);

    cout << "Tempo cartao: 60 = " << teste->get_time_to_spend_card() << "\n";
    cout << "Tempo item: 4 = " << teste->get_time_to_spend_item() << "\n";

    cout << "============Test2=============\n";





}
