#include "processing.h"

#include <cstring>
#include <iostream>

int duration(book_subscription* element)
{
    return (element->finish.CHCHCC * 3600 + element->finish.MM*60 + element->finish.CC - element->start.CHCHCC * 3600 - element->start.MM * 60 - element->start.CC);
}

bool compare_by_duration(book_subscription* a, book_subscription* b) {
    return duration(a) < duration(b);
}

bool compare_by_club(book_subscription* a, book_subscription* b) {
    int club = strcmp(a->club.name, b->club.name);
    if (club < 0) {
        return true;
    }
    else if (club > 0) {
        return false;
    }
    else {
        int theme_comparison = strcmp(a->reader.last_name, b->reader.last_name);
        if (theme_comparison < 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

void quik(book_subscription* array[], int left, int mid, int right, bool (*compare)(book_subscription*, book_subscription*)) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    book_subscription** L = new book_subscription * [n1];
    book_subscription** R = new book_subscription * [n2];

    for (int i = 0; i < n1; ++i)
        L[i] = array[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            array[k] = L[i];
            ++i;
        }
        else {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        array[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        array[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void quik_sort(book_subscription* array[], int left, int right, bool (*compare)(book_subscription*, book_subscription*)) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        quik_sort(array, left, mid, compare);
        quik_sort(array, mid + 1, right, compare);

        quik(array, left, mid, right, compare);
    }
}

void swap(book_subscription* array[], int i, int j) {
    book_subscription* temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void Bubble(book_subscription* array[], int size, int index, bool (*compare)(book_subscription*, book_subscription*)) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;


    if (left < size && compare(array[left], array[largest]) == false)
        largest = left;

    if (right < size&& compare(array[right], array[largest]) == false)
        largest = right;

    if (largest != index) {
        swap(array, index, largest);
        Bubble(array, size, largest, compare);
    }
}

void Bubble_sort(book_subscription* array[], int size, bool (*compare)(book_subscription*, book_subscription*)) {
    for (int i = size / 2 - 1; i >= 0; --i)
        Bubble(array, size, i, compare);

    for (int i = size - 1; i > 0; --i) {
        swap(array, 0, i);

        Bubble(array, i, 0, compare);
    }
}