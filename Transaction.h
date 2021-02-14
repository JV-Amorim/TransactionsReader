#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "DateHour.h"

namespace TransactionReader
{
	class Transaction
	{
	public:
		DateHour dateHour;
		double price;
		std::string product, paymentMethod, personName, city, state, country;
	};
}

#endif
