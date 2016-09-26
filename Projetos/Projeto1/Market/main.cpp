#include <iostream>
#include <stdio.h>
#include "performance.h"
#include "bad_performance.h"

using namespace std;

int main()
{
    BadPerformance* desempenho = new BadPerformance();
    desempenho->time_to_spend_card();
    //cout << desempenho->time_to_spend_item() << "\n";
}
