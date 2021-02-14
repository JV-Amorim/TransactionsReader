#include <iostream>
#include <vector>
#include "DateHour.h"
#include "Transaction.h"
#include "TransactionReader.h"

using namespace std;
using namespace TransactionReader;

int main()
{
    vector<Transaction> transactions = readTransactionsFromFile("Data/transactions-data-1.txt");

    for (int i = 0; i < transactions.size(); i++)
    {
        cout << transactions[i].toString() << endl;
    }

    return 0;
}
