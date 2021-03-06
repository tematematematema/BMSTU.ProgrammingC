/**
 * \file matrixgame_functions_get_by_pos.c
 * \brief Функция, возвращающая значение ячейки матрицы
 */
#include "../headers/matrixgame.h"

/**
 * \def DIMENSION_OUT_OF_RANGE_ERROR
 * \brief Код ошибки: выход за пределы матрицы
 */
#define DIMENSION_OUT_OF_RANGE_ERROR 218
/**
 * \def FALSE_POINTER_ERROR
 * \brief Код ошибки: в функцию был передан пустой указатель
 */
#define FALSE_POINTER_ERROR 219

/*
Get matrix element by it's position.

Input data:
* const matrix_t *const matrix - matrix struct where need to get element.
* const int index_row - index of needed element's row.
* const int index_column - index of needed elements's column.

Output data:
* Found element or return code - DIMENSION_OUT_OF_RANGE_ERROR or
FALSE_POINTER_ERROR.
*/
/**
 * \fn int get_by_pos(const matrix_t *const init_matrix, const int index_row,
 * const int index_column)
 *
 * \param const matrix_t *const init_matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param const int index_row - Индекс строки искомой ячейки матрицы
 * \param const int index_column - Индекс столбца искомой ячейки матрицы
 *
 * \brief Возвращает значение заданной ячейки
 *
 * \return Значение ячейки
 */
int matrixgame_get_by_pos(const matrix_t *const init_matrix,
               const int index_row,
               const int index_column)
{
    if (init_matrix->rows - 1 < index_row || init_matrix->columns - 1 < index_column ||
        index_row < 0 || index_column < 0)
    {
        return DIMENSION_OUT_OF_RANGE_ERROR;
    }

    for (int row = 0; row < init_matrix->rows; ++row)
    {
        for (int col = 0; col < init_matrix->columns; ++col)
        {
            if (!(init_matrix->matrix + row))
            {
                return FALSE_POINTER_ERROR;
            }
        }
    }

    return *(*(init_matrix->matrix + index_row) + index_column);
}
