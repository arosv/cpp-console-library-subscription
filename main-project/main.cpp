#include <iostream>
#include <iomanip>

using namespace std;

#include "book_subscription.h"
#include "file_reader.h"
#include "filter.h"
#include "constants.h"
void output(book_subscription* subscription) {
    cout << "Number...............";
    cout << subscription->number << '\n';
    cout << "Name...............";
    cout << subscription->reader.last_name << " ";
    cout << subscription->reader.first_name[0] << ". ";
    cout << subscription->reader.middle_name[0] << ".";
    cout << '\n';
    cout << "Start.................";
    cout << setw(2) << setfill('0') << subscription->start.CHCHCC << ':';
    cout << setw(2) << setfill('0') << subscription->start.MM << ':';
    cout << setw(2) << setfill('0') << subscription->start.CC << '\n';
    cout << "Finish.................";
    cout << setw(2) << setfill('0') << subscription->finish.CHCHCC << ':';
    cout << setw(2) << setfill('0') << subscription->finish.MM << ':';
    cout << setw(2) << setfill('0') << subscription->finish.CC << '\n';
    cout << "Club.................";
    cout << subscription->club.name << '.';
    cout << '\n';
    cout << '\n';
    
}

int main()
{

    setlocale(LC_ALL, "Russian");
    cout << "Lab №4. GIT\n";
    cout << "Variant №1. Marafon\n";
    cout << "Author: Vadim Yarosh\n\n";
    cout << "Grupp: 23PI1d\n";

    book_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** Marafon *****\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << "Number...............";
            cout << subscriptions[i]->number << '\n';
            cout << "Name...............";
            cout << subscriptions[i]->reader.last_name << " ";
            cout << subscriptions[i]->reader.first_name[0] << ". ";
            cout << subscriptions[i]->reader.middle_name[0] << ".";
            cout << '\n';
            cout << "Start.................";
           // cout << setw(2) << setfill('0') << subscriptions[i]->start.CHCHCC << ':';
            //cout << setw(2) << setfill('0') << subscriptions[i]->start.MM << ':';
           // cout << setw(2) << setfill('0') << subscriptions[i]->start.CC << '\n';
            cout << "Finish.................";
           // cout << setw(2) << setfill('0') << subscriptions[i]->finish.CHCHCC << ':';
            //cout << setw(2) << setfill('0') << subscriptions[i]->finish.MM << ':';
            //cout << setw(2) << setfill('0') << subscriptions[i]->finish.CC << '\n';
            cout << "Club.................";
            cout << subscriptions[i]->club.name << '.';
            cout << '\n';
            cout << '\n';
        }
        bool (*check_function)(book_subscription*) = NULL;
        cout << "\n     :\n";
        cout << "1)Check by name 'Спартак'\n";
        cout << "2)Check by time\n";
        cout << "\n   : ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:
            check_function = check_by_name;
            cout << " name \n\n";
            break;
        case 2:
            check_function = check_by_time;
            cout << " time<2:50 \n\n";
            break;
        default:
            throw "Invalid variant";
        }
        if (check_function)
        {
            int new_size;
            book_subscription** filtered = filter(subscriptions, size, check_function, new_size);
            for (int i = 0; i < new_size; i++)
            {
                output(filtered[i]);
            }
            delete[] filtered;
        }


        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }



    return 0;
}