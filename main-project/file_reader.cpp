#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>


date convert_date(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.CHCHCC = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.MM = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.CC = atoi(str_number);
    return result;
}




void read(const char* file_name, book_subscription* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            book_subscription* item = new book_subscription;
            file >> tmp_buffer;
            item->number = atoi(tmp_buffer);
            file >> item->reader.last_name;
            file >> item->reader.first_name;
            file >> item->reader.middle_name;
            file >> tmp_buffer;
            item->start = convert_date(tmp_buffer);
            file >> tmp_buffer;
            item->finish = convert_date(tmp_buffer);
            file.getline(item->club.name, MAX_NAME_SIZE); 
            //file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}