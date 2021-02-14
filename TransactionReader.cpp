#include <iostream>
#include <fstream>
#include "DateHour.h"
#include "TransactionReader.h"

using namespace std;

namespace TransactionReader
{
	vector<Transaction> readTransactionsFromFile(string t_fileName)
	{
		ifstream openedFile(t_fileName);
		string output;

		if (openedFile.fail())
		{
			cout << "Não foi possível abrir o arquivo especificado.";
			abort();
		}

		// Lendo a primeira linha (cabeçalho do arquivo).
		getline(openedFile, output);

		vector<Transaction> transactions;

		while (getline(openedFile, output))
		{
			char* contentCopy = _strdup(output.c_str());
			char* context = NULL;
			Transaction newTransaction;

			string dateHourString = strtok_s(contentCopy, ";", &context);
			newTransaction.dateHour = DateHour::parseToDateHour(dateHourString, APP_DATE_HOUR_FORMAT);

			newTransaction.product = strtok_s(NULL, ";", &context);
			newTransaction.price = atof(strtok_s(NULL, ";", &context));
			newTransaction.paymentType = strtok_s(NULL, ";", &context);
			newTransaction.personName = strtok_s(NULL, ";", &context);
			newTransaction.city = strtok_s(NULL, ";", &context);
			newTransaction.state = strtok_s(NULL, ";", &context);
			newTransaction.country = strtok_s(NULL, "\0", &context);

			transactions.push_back(newTransaction);

			free(contentCopy);
		}

		openedFile.close();

		return transactions;
	}
}