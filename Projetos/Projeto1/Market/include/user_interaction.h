#ifndef USERINTERACTION_H
#define USERINTERACTION_H
#include <string>

using namespace std;

class UserInteraction
{
    public:
        UserInteraction();
        virtual ~UserInteraction();
        bool select_entry_with_file();
        string get_market_name();
        unsigned int get_unsigned_int(string msg);
        unsigned int get_average_arrival_time_of_customers();
        unsigned int get_number_of_box();
        string get_identifier_box(int index);
        unsigned int get_performance_box(int index);
        unsigned int get_salary_box(int index);

    protected:

    private:
};

#endif // USERINTERACTION_H
