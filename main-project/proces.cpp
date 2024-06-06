#include "processing.h"
int secunds(date d)
{
	int result = 0;

	result = d.CHCHCC*3600+d.MM*60+d.CC;
	return result;
}

int diff(date a, date b)
{
	int x = secunds(a);
	int y = secunds(b);
	return (x > y ? x - y : y - x) + 1;
}

int process(book_subscription* array[], int size)
{
	int max = diff(array[0]->start, array[0]->finish);
	for (int i = 1; i < size; i++)
	{
		int curr = diff(array[i]->start, array[i]->finish);
		if (curr > max)
		{
			max = curr;
		}
	}
	return max;
}


