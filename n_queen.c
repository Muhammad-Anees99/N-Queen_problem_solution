/* Task_x_x.c: Topic Name
-----------------------------------------------------------------------------
Description
-----------------------------------------------------------------------------
Written by Muhammad Anees (m.anees990011@gmail.com)
_____________________________________________________________________________
IDE: Visual Studio Code 1.72.0
_____________________________________________________________________________
C Compiler: gcc (Rev1, Built by MSYS2 project) 12.2.0
_____________________________________________________________________________*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int population_size = 50, boardsize = 8;
int population(int maxpopulation[population_size][boardsize]);
int fitEvaluate(int poplation_size);
void next_Generation(int maxpopulation[population_size][boardsize]);
void printBoard();
int maxpopulation[50][8];


int main()
{
    int iteration = 0;
    int fit;
    population(maxpopulation);
    while (iteration < 10000)
    {
        next_Generation(maxpopulation);
        for (int i = 0; i < population_size; i++)
        {
            fit = fitEvaluate(i);
            if (fit == 0)
            {
                printf("\n");
                printf("%d Queens solution has been found after %d th iterations!\nSolution is ", boardsize, iteration + 1);
                for (int j = 0; j < boardsize; j++)
                {
                    printf("%d", maxpopulation[i][j]);
                     printBoard();
                }
                printf("\n");
               
                return 0;
            }
            for (int j = 0; j < boardsize; j++)
            {
                printf("%d", maxpopulation[i][j]);
            }
            printf("\t%d\n", fit);
            iteration++;
        }
    }
            printf("No result found in %d iterations!\nTry Again",iteration);

    return 0;
}
int population(int maxpopulation[population_size][boardsize])
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
void next_Generation(int maxpopulation[population_size][boardsize])
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
void printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            maxpopulation[i][j] = 0;
        }
    }
    for (int i = 0; i < boardsize; i++)
    {
        for (int j = 0; j <boardsize ; j++)
        {
            printf("|%d|",maxpopulation[i][j]);
            
        }
        printf("\n");
    }
}
// End Of Program