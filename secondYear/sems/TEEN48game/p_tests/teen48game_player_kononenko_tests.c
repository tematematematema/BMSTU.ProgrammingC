#include <matrixgame.h>

#include "../p_headers/teen48game_player_kononenko.h"
#include "../f_headers/teen48game_to_step.h"
#include "../f_headers/teen48game_gorandom.h"

#define OK 0

void fill(matrix_t *const matrix)
{
    for (int row = 0; row < matrix->rows; ++row)
    {
        for (int col = 0; col < matrix->columns; ++col)
        {
            *(*(matrix->matrix + row) + col) = 0;
        }
    }
}

void strat_test()
{
    int elite = 1337;
    matrix_t playfield;
    matrixgame_create_matrix(&playfield, elite, elite);
    fill(&playfield);

    gorandom(&playfield);
    gorandom(&playfield);

    while (elite)
    {
        teen48game_player_kononenko(&playfield, to_step);
        gorandom(&playfield);
        --elite;
    }

    matrixgame_free_matrix(&playfield);
}

int main()
{
    strat_test();

    return OK;
}