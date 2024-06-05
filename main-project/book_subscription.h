#ifndef BOOK_SUBSCRIPTION_H
#define BOOK_SUBSCRIPTION_H

#include "constants.h"

struct date
{
    int CHCHCC;
    int MM;
    int CC;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};
struct NAME
{
   char name[MAX_NAME_SIZE];
};


struct book_subscription
{
    int number;
    person reader;
    date start;
    date finish;
    NAME club;
};

#endif