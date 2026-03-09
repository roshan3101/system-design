#pragma once

#include <iostream>
#include <string>

#include "PaymentStrategy.h"
using namespace std;

class UPIPaymentStrategy : public PaymentStrategy
{
private:
    string upiId;

public:
    explicit UPIPaymentStrategy(string id)
    {
        upiId = id;
    }

    void pay(double amount) override
    {
        cout << "\nPaid Rs " << amount << " via UPI ID " << upiId << " | Payment successful" << endl;
    }
};
