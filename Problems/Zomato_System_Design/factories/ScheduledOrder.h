#pragma once

#include <string>

#include "../models/DeliveryOrder.h"
#include "OrderFactory.h"
#include "../models/PickupOrder.h"

class ScheduledOrder : public OrderFactory
{
private:
    string scheduledTime;

public:
    explicit ScheduledOrder(string st)
    {
        this->scheduledTime = st;
    }

    Order* createOrder(
        int orderId,
        User* user,
        Cart* cart,
        Restaurant* restraunt,
        const vector<MenuItem*>& items,
        PaymentStrategy* ps,
        const string& orderType) override
    {
        Order* order = nullptr;
        if (orderType == "Delivery")
        {
            auto* deliveryOrder = new DeliveryOrder(orderId);
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        }
        else
        {
            auto* pickupOrder = new PickupOrder(orderId);
            pickupOrder->setRestrauntAddress(restraunt->getLocation());
            order = pickupOrder;
        }

        order->setUser(user);
        order->setRestraunt(restraunt);
        order->setItems(items);
        order->setPaymentStrategy(ps);
        order->setScheduled(scheduledTime);
        return order;
    }
};
