#ifndef PROCESSING_H
#define PROCESSING_H

#include "book_subscription.h"

int duration(book_subscription* element);

bool compare_by_duration(book_subscription* a, book_subscription* b);

bool compare_by_club(book_subscription* a, book_subscription* b);

void quik(book_subscription* array[], int left, int mid, int right, bool (*compare)(book_subscription*, book_subscription*));

void quik_sort(book_subscription* array[], int left, int right, bool (*compare)(book_subscription*, book_subscription*));

void swap(book_subscription* array[], int i, int j);

void Bubble(book_subscription* array[], int size, int index, bool (*compare)(book_subscription*, book_subscription*));

void Bubble_sort(book_subscription* array[], int size, bool (*compare)(book_subscription*, book_subscription*));

#endif