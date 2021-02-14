#include <iostream>
#include "DateHour.h"
#include "Transaction.h"

using namespace std;
using namespace TransactionReader;

const DateHourFormat APP_DATE_HOUR_FORMAT = DateHourFormat::UnitedStates;

int main()
{
    DateHour dateHour = DateHour::parseToDateHour("01/02/2009 06:17", APP_DATE_HOUR_FORMAT);

    cout << DateHour::dateHourToString(dateHour, APP_DATE_HOUR_FORMAT) << endl;

    return 0;
}
