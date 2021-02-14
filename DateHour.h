#ifndef DATE_HOUR
#define DATE_HOUR

#include <string>
#include "DateHourFormat.h"

namespace TransactionReader
{
	class DateHour
	{
	public:
		int day{ 0 }, month{ 0 }, year{ 0 }, hour{ 0 }, minute{ 0 };
		DateHour();
		DateHour(int t_day, int t_month, int t_year, int t_hour, int t_minute);
		static DateHour parseToDateHour(std::string t_contentToParse, DateHourFormat t_format);
		static std::string dateHourToString(DateHour t_dateHour, DateHourFormat t_format);
	};
}

#endif
