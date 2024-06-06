//#include "processing.h"
//int secunds(date d)
//{
//	int result = 0;
//
//	result = d.CHCHCC*3600+d.MM*60+d.CC;
//	return result;
//}
//
//int diff(date a, date b)
//{
//	int x = secunds(a);
//	int y = secunds(b);
//	return (x > y ? x - y : y - x) + 1;
//}
//
//int process(book_subscription* array[], int size)
//{
//	int max = diff(array[0]->start, array[0]->finish);
//	for (int i = 1; i < size; i++)
//	{
//		int curr = diff(array[i]->start, array[i]->finish);
//		if (curr > max)
//		{
//			max = curr;
//		}
//	}
//	return max;
//}
#include "processing.h"
#include <algorithm>
#include <ctime>

int time_between(const date& start, const date& end) {
    tm start_tm = {}; 
    start_tm.tm_mday = start.CHCHCC;
    start_tm.tm_mon = start.MM;
    start_tm.tm_year = start.CC;

    tm end_tm = {};
    end_tm.tm_mday = end.CHCHCC;
    end_tm.tm_mon = end.MM;
    end_tm.tm_year = end.CC;

    time_t start_time = mktime(&start_tm);
    time_t end_time = mktime(&end_tm);

    const int seconds_per_day = 60;
    return difftime(end_time, start_time) / seconds_per_day;
}

int calculate_marafon_duration(book_subscription* array[], int size) {
    if (size == 0) {
        return 0;
    }

    date min_date = array[0]->start;
    date max_date = array[0]->finish;

    for (int i = 1; i < size; ++i) {
       /* if (array[i]->start.CHCHCC < min_date.CHCHCC ||
            (array[i]->start.CHCHCC == min_date.CHCHCC && array[i]->start.MM < min_date.MM) ||
            (array[i]->start.CHCHCC == min_date.CHCHCC && array[i]->start.MM == min_date.MM && array[i]->start.CC < min_date.CC)) {
            min_date = array[i]->start;
        }*/
        if (array[i]->finish.CHCHCC < max_date.CHCHCC ||
            (array[i]->finish.CHCHCC == max_date.CHCHCC && array[i]->finish.MM < max_date.MM) ||
            (array[i]->finish.CHCHCC == max_date.CHCHCC && array[i]->finish.MM == max_date.MM && array[i]->finish.CC > max_date.CC)) {
            max_date = array[i]->finish;
        }
    }

    return time_between(min_date, max_date);
}


