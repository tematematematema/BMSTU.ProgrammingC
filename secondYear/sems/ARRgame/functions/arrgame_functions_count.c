 //Функция для подсчета количества вхождений элемента в массив

#include "../headers/arrgame.h"

#define ERROR_LENGTH 2
#define INITIAL 0
#define CONSTANT 1

int arrgame_count(const int x, int const* start, const int length)
{
    int counting_element = INITIAL;
    int const* end = start + length;

    while (start <= end)
        if (*start++ == x)
            counting_element++;

    return counting_element;
}
