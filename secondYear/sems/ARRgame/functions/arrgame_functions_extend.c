#include <stdlib.h>
#include <string.h>

#include "../headers/arrgame.h"

/*
  OFFSET_LEN - длина массива, запрошенная пользователем
  OFFSET_ALLOC_COUNT - количество выделенных элементов в массиве
  OFFSET_REAL_COUNT - количество занятых ячеек
  OFFSET_START - начало массива элементов
 */

#define OFFSET_LEN 0
#define OFFSET_ALLOC_COUNT 1
#define OFFSET_REAL_COUNT 2
#define OFFSET_START 3

#define GET_LEN(arr_ptr) *(arr_ptr + OFFSET_LEN)
#define GET_ALC(arr_ptr) *(arr_ptr + OFFSET_ALLOC_COUNT)
#define GET_REC(arr_ptr) *(arr_ptr + OFFSET_REAL_COUNT)
#define GET_START_PTR(arr_ptr) arr_ptr + OFFSET_START

#define SUCCESS 0

#define EXTEND_REALLOC_FAIL -602

int *arrgame_extend(int *arra, const int *const arrb);


/*
  simpl_extend - копирует элеметны массива arrb за конец массива arrb
  @arra - указатель на заголовок расширяемого массива
  @arrb - указатель на заголовок копируемого массива
 */
static void simple_extend(int *arra, const int *const arrb)
{
    const int ncpy = GET_REC(arrb);

    int *const offset_dst = GET_START_PTR(arra) + GET_REC(arra);
    const int *const offset_src = GET_START_PTR(arrb);

    memcpy(offset_dst, offset_src, ncpy * sizeof(int));

    GET_REC(arra) += ncpy;
}


/*
  safe_realloc - безопасно расширяет область выделенной памяти массива arra
  @**arra - указатель на заголовок расширяемого массива
  @desired_size - желаемый новый размер массива
 */
static int safe_realloc(int **arra, const size_t desired_size)
{
    const size_t realloc_size = OFFSET_START + desired_size;

    int *const temp = realloc((void*) * arra, realloc_size * sizeof(int));
    if (!temp)
        return EXTEND_REALLOC_FAIL;

    *arra = temp;
    GET_ALC(*arra) = realloc_size - OFFSET_START;

    return SUCCESS;
}


/*
  extend - прибавляет элементы массива arrb к массиву arra
  @*arra - указатель на заголовок расширяемого массива
  @*arrb - указатель на заголовок прибавляемого массива

  При расширении адрес расширяемого массива arra может изменится.

  @return возвращает указатель на новую область памяти,
  или NULL и код ошибки в errno.
*/
int *arrgame_extend(int *arra, const int *const arrb)
{
    const int reall_a = GET_REC(arra);
    const int allc_a = GET_ALC(arra);
    const int reall_b = GET_REC(arrb);

    if (reall_a + reall_b > allc_a)
    {
        const int rc = safe_realloc(&arra, reall_a + reall_b);
        if (rc != SUCCESS)
        {
            return (void*)0;
        }
    }

    simple_extend(arra, arrb);

    return arra;
}
