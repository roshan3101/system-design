#pragma once

#include <string>
#include <vector>

#include "../models/Cart.h"
#include "../models/MenuItem.h"
#include "../models/Order.h"
#include "../strategies/PaymentStrategy.h"
#include "../models/Restraunt.h"
#include "../models/User.h"

using namespace std;

class OrderFactory
{
public:
    virtual Order* createOrder(
        int orderId,
        User* user,
        Cart* cart,
        Restaurant* restraunt,
        const vector<MenuItem*>& items,
        PaymentStrategy* ps,
        const string& orderType) = 0;

    virtual ~OrderFactory() {}
};
