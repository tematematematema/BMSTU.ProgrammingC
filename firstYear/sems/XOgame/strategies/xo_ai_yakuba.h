/* Функция makeshot от Якуба */
/* Более сложный простейший бот с проверкой на наличие в ячейке значения */

void make_shot_yakuba(char type, char field[][DIME])
{
    int i, j, k = 0;
    srand(time(NULL));
    i = (rand() % DIME);
    j = (rand() % DIME);
    while (field[i][j] != ' ')
    {
        k += 1;
        srand(time(NULL));
        i = (0 + rand() % DIME);
        j = (0 + rand() % DIME);
        if (k == 100)
            break;
    }
    if (k == 100)
    {
        for (int q = 0; q < DIME; q++)
        {
            for (int w = 0; w < DIME; w++)
                if (field[q][w] == ' ')
                {
                    field[q][w] = type;
                    k = 99;
                    break;
                }
            if (k == 99)
                break;
        }
    }
    else
        field[i][j] = type;
}
