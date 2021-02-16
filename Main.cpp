#include <iostream>

#include "Main.h"
#include "DateHour.h"
#include "TransactionReader.h"

using namespace std;
using namespace TransactionReader;

int main()
{
    showInitialView();
    return 0;
}

void showInitialView()
{
    cout << "LEITOR DE ARQUIVOS DE TRANSACOES" << endl;
    cout << endl << "Digite uma opcao:" << endl << "[1] Abrir um arquivo de transacoes (contido na pasta \"Data\");" << endl << "[0] Sair;" << endl;

    int choice = -1;
    cin >> choice;

    if (choice == 0)
    {
        return;
    }
    else if (choice == 1)
    {
        showFileSelectionView();
    }
    else
    {
        cout << "Nao foi digitada uma opcao valida." << endl;
        return;
    }
}

void showFileSelectionView()
{
    cout << endl << "Digite o nome completo do arquivo (com a extensao):" << endl;

    string fileName = "";
    cin >> fileName;

    vector<Transaction> transactions = readTransactionsFromFile("Data/" + fileName);

    cout << endl << "O arquivo foi lido com sucesso. O que deseja fazer com os dados?" << endl;
    cout << "Digite uma opcao:" << endl;
    cout << "[1] Mostrar todas as transacoes;" << endl << "[2] Pesquisar transacoes de acordo com uma certa data;" << endl << "[0] Sair" << endl;

    int choice = -1;
    cin >> choice;

    if (choice == 0)
    {
        return;
    }
    else if (choice == 1)
    {
        cout << endl;
        printTransactions(transactions);
    }
    else if (choice == 2)
    {
        showSearchView(transactions);
    }
}

void showSearchView(vector<Transaction> t_transactions)
{
    if (APP_DATE_HOUR_FORMAT == DateHourFormat::Brazil)
    {
        cout << endl << "Digite a data desejada (DD/MM/AAAA):" << endl;
    }
    else if (APP_DATE_HOUR_FORMAT == DateHourFormat::UnitedStates)
    {
        cout << endl << "Digite a data desejada (MM/DD/AAAA):" << endl;
    }
    else
    {
        cout << "O formato de data e hora nao foi definido na aplicacao. Nao sera possivel continuar." << endl;
        return;
    }

    string searchDate;
    cin >> searchDate;

    vector<Transaction> filteredTransactions = filterTransactions(t_transactions, searchDate);

    cout << endl << "RESULTADO DA PESQUISA:" << endl;

    if (filteredTransactions.size() == 0)
    {
        cout << "Nenhuma transacao com a data informada foi encontrada." << endl;
    }
    else
    {
        printTransactions(filteredTransactions);
        showSaveFileView(filteredTransactions);
    }
}

void showSaveFileView(vector<Transaction> t_transactions)
{
    cout << endl << "Deseja salvar as transacoes em um novo arquivo?" << endl;
    cout << "Digite uma opcao:" << endl << "[1] Salvar;" << endl << "[0] Sair" << endl;

    int choice = -1;
    cin >> choice;

    if (choice != 1)
    {
        return;
    }

    cout << endl << "Digite um nome para o arquivo (com a extensao):" << endl;

    string fileName = "";
    cin >> fileName;

    saveTransactionsToFile(t_transactions, fileName);
}