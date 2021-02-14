#ifndef TRANSACTION_HEADER_H
#define TRANSACTION_HEADER_H

#include <vector>
#include <string>
#include "Transaction.h"

namespace TransactionReader
{
	std::vector<Transaction> readTransactionsFromFile(std::string t_fileName);
}

#endif
