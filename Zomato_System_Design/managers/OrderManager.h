#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "../models/Order.h"
using namespace std;

class OrderManager
{
private:
    vector<Order*> orders;

public:
    void addOrder(Order* order)
    {
        orders.push_back(order);
    }

    void listOrder()
    {
        cout << "\n---All Orders---" << endl;
        for (auto* order : orders)
        {
            cout << order->getType() << " order for " << order->getUser()->getName()
                 << " | Total: Rs " << order->getTotal()
                 << " | At " << order->getScheduled() << endl;
        }
    }

    ~OrderManager()
    {
        for (auto* order : orders)
        {
            delete order;
        }
    }
};
