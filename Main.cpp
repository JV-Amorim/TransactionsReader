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

    if (APP_DATE_HOUR_FORMAT == DateHourFormat::Brazil)
    {
        cout << "Digite a data desejada (DD/MM/AAAA):" << endl;
    }
    else if (APP_DATE_HOUR_FORMAT == DateHourFormat::UnitedStates)
    {
        cout << "Digite a data desejada (MM/DD/AAAA):" << endl;
    }
    else
    {
        cout << "O formato de data e hora nao foi definido na aplicacao. Nao sera possivel continuar." << endl;
        abort();
    }

    string searchDate;
    cin >> searchDate;

    vector<Transaction> filteredTransactions = filterTransactions(transactions, searchDate);

    cout << endl << "RESULTADO DA PESQUISA:" << endl;

    if (filteredTransactions.size() == 0)
    {
        cout << "Nenhuma transacao com a data informada foi encontrada.";
    }
    else
    {
        printTransactions(filteredTransactions);
    }

    return 0;
}
