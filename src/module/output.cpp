#include <stdio.h>
#include <iostream>

#include "module\output.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"

void output(data myData) {
    system("chcp 65001 > nul");
    printf("Outputing...\n");
    for(int i = 0; i < myData.n; i++)
    {
        for(int j = 0; j < myData.m; j++)
        {
            //printf("%d ", myData.arr[i][j]);
            
            if(myData.arr[i][j] == 10)
            {
                printf("\x1b[32m@");
            }
            else if(myData.arr[i][j] == 9)
            {
                printf("\x1b[32mX");
            }
            else if(myData.arr[i][j] == 0 or myData.arr[i][j] == 2)
            {
                printf(" ");
            }
            else if(myData.arr[i][j] == 1)
            {
                printf("\x1b[31m█");
            }
            else if(myData.arr[i][j] == 11)
            {
                printf("\x1b[32m↓");
            }
            else if(myData.arr[i][j] == 12)
            {
                printf("\x1b[32m↘");
            }
            else if(myData.arr[i][j] == 13)
            {
                printf("\x1b[32m→");
            }
            else if(myData.arr[i][j] == 14)
            {
                printf("\x1b[32m↗");
            }
            else if(myData.arr[i][j] == 15)
            {
                printf("\x1b[32m↑");
            }
            else if(myData.arr[i][j] == 16)
            {
                printf("\x1b[32m↖");
            }
            else if(myData.arr[i][j] == 17)
            {
                printf("\x1b[32m←");
            }
            else if(myData.arr[i][j] == 18)
            {
                printf("\x1b[32m↙");
            }
            
        }
        printf("\n");
    }
    printf("\33[0mPrinted");
}