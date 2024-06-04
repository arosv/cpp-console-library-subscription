#include "filter.h" 
#include <cstring> 
#include <iostream> 

book_subscription** filter(book_subscription* array[], int size, bool (*check)(book_subscription* element), int& result_size)
{
	book_subscription** result = new book_subscription * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_by_name(book_subscription* element)
{
	return strcmp(element->club.name, "Спартак") == 0;

}

bool check_by_time(book_subscription* element)
{
	return element->finish.CHCHCC <15;
}
