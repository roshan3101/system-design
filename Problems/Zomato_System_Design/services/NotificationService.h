#pragma once

#include <iostream>

#include "../models/Order.h"
using namespace std;

class NotificationService
{
public:
    static void notify(Order* order)
    {
        cout << "\nNotification: New " << order->getType() << " order placed" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Order Id: " << order->getOrderId() << endl;
        cout << "Customer: " << order->getUser()->getName() << endl;
        cout << "Restraunt: " << order->getRestraunt()->getName() << endl;
        cout << "Items Ordered:" << endl;

        const vector<MenuItem*>& items = order->getItems();
        for (const auto* item : items)
        {
            if (item)
            {
                cout << " - " << item->getName() << " (Rs " << item->getPrice() << ")" << endl;
            }
        }

        cout << "Total: Rs " << order->getTotal() << endl;
        cout << "Scheduled For: " << order->getScheduled() << endl;
        cout << "Payment: Done" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }
};
