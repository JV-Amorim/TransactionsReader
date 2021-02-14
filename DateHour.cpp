#include <iostream>
#include "DateHour.h"

using namespace std;
using namespace TransactionReader;

DateHour::DateHour()
{
}

DateHour::DateHour(int t_day, int t_month, int t_year, int t_hour, int t_minute)
{
	day = t_day;
	month = t_month;
	year = t_year;
	hour = t_hour;
	minute = t_minute;
}

DateHour DateHour::parseToDateHour(string t_contentToParse, DateHourFormat t_format)
{
	DateHour dateHour;

	char* tempContent = _strdup(t_contentToParse.c_str());
	char* context = NULL;

	if (t_format == DateHourFormat::Brazil)
	{
		dateHour.day = stoi(strtok_s(tempContent, "/", &context));
		dateHour.month = stoi(strtok_s(NULL, "/", &context));
		dateHour.year = stoi(strtok_s(NULL, " ", &context));
		dateHour.hour = stoi(strtok_s(NULL, ":", &context));
		dateHour.minute = stoi(strtok_s(NULL, "\0", &context));
	}
	else if (t_format == DateHourFormat::UnitedStates)
	{
		dateHour.month = stoi(strtok_s(tempContent, "/", &context));
		dateHour.day = stoi(strtok_s(NULL, "/", &context));
		dateHour.year = stoi(strtok_s(NULL, " ", &context));
		dateHour.hour = stoi(strtok_s(NULL, ":", &context));
		dateHour.minute = stoi(strtok_s(NULL, "\0", &context));
	}

	free(tempContent);

	return dateHour;
}

string DateHour::dateHourToString(DateHour t_dateHour, DateHourFormat t_format)
{
	string result = "";

	if (t_format == DateHourFormat::Brazil)
	{
		result = to_string(t_dateHour.day) + "/" + to_string(t_dateHour.month) + "/" + to_string(t_dateHour.year) + " " + to_string(t_dateHour.hour) + ":" + to_string(t_dateHour.minute);
	}
	else if (t_format == DateHourFormat::UnitedStates)
	{
		result = to_string(t_dateHour.month) + "/" + to_string(t_dateHour.day) + "/" + to_string(t_dateHour.year) + " " + to_string(t_dateHour.hour) + ":" + to_string(t_dateHour.minute);
	}
	else
	{
		result = "00/00/0000";
	}

	return result;
}
