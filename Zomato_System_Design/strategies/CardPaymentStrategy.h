#pragma once

#include <iostream>
#include <string>

#include "PaymentStrategy.h"
using namespace std;

class CardPaymentStrategy : public PaymentStrategy
{
private:
    string card;

public:
    explicit CardPaymentStrategy(string cardNumber)
    {
        card = cardNumber;
    }

    void pay(double amount) override
    {
        cout << "\nPaid Rs " << amount << " via Card " << card << " | Payment successful" << endl;
    }
};
