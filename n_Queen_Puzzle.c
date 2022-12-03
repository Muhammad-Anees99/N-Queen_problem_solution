/* Task_ N-Queen_problem
-----------------------------------------------------------------------------
Complex engineering problem
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
#include"n_queen_header.h"
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
    printf("No result found in %d iterations!\nTry Again", iteration);
    return 0;
}


// End Of Program