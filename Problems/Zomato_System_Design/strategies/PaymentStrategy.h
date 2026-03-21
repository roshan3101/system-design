#pragma once

#include <iostream>
#include <string>

class PaymentStrategy
{
	public:
		virtual void pay(double amount) = 0;
		virtual ~PaymentStrategy() {}
};