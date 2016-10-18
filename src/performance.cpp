#include "performance.h"

Performance::Performance(const unsigned int& time_to_spend_card, const unsigned int& time_to_spend_item)
{
    time_to_spend_card_ = time_to_spend_card;
    time_to_spend_item_ = time_to_spend_item;
}

const unsigned int& Performance::get_time_to_spend_item() const
{
    return time_to_spend_item_;
}

const unsigned int& Performance::get_time_to_spend_card() const
{
    return time_to_spend_card_;
}
