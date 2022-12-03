#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int population_size = 50, boardsize = 8;
int population(int maxpopulation[50][8]);
int fitEvaluate(int poplation_size);
void next_Generation(int maxpopulation[50][8]);
void printBoard();
int maxpopulation[50][8];

int population(int maxpopulation[50][8])
{
    srand(time(NULL));
    for (int i = 0; i < population_size; i++)
    {
        for (int j = 0; j < boardsize; j++)
        {
            maxpopulation[i][j] = rand() % boardsize + 1;
        }
    }
}
int fitEvaluate(int population_size)
{
    int fit = 0;

    for (int i = 0; i < boardsize; i++)
    {
        for (int j = i + 1; j < boardsize; j++)

        {
            if (maxpopulation[population_size][i] == maxpopulation[population_size][j])
            {
                fit++;
            }
            if (abs(maxpopulation[population_size][i] - maxpopulation[population_size][j]) == abs(i - j))
            {
                fit++;
            }
        }
    }
    return fit;
}
void next_Generation(int maxpopulation[50][8])
{

    for (int k = 0; k < population_size; k++)
    {
        for (int i = 0; i < population_size; i++)
        {
            if (fitEvaluate(i) > fitEvaluate(i + 1))
            {
                for (int j = 0; j < boardsize; j++)
                {
                    int temp[boardsize];
                    temp[j] = maxpopulation[i][j];
                    maxpopulation[i][j] = maxpopulation[i + 1][j];
                    maxpopulation[i + 1][j] = temp[j];
                }
            }
        }
    }
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            maxpopulation[i + 25][j] = maxpopulation[i][j];
        }
        for (int j = 4; j < boardsize; j++)
        {
            maxpopulation[i + 25][j] = maxpopulation[i + 1][j];
        }
    }
    for (int i = 0; i < population_size; i++)
    {
        maxpopulation[i][rand() % boardsize + 1] = rand() % boardsize + 1;
    }
}