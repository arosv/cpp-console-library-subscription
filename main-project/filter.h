#ifndef FILTER_H#define FILTER_H
#include "book_subscription.h"
book_subscription** filter(book_subscription* array[], int size, bool (*check)(book_subscription* element), int& result_size);
bool check_by_name(book_subscription* element);
bool check_by_time(book_subscription* element);
#endif

