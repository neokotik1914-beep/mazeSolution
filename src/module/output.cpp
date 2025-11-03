#include <stdio.h>
#include <iostream>

#include "module\output.h"

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
                printf("@");
            }
            else if(myData.arr[i][j] == 9)
            {
                printf("X");
            }
            else if(myData.arr[i][j] == 0 or myData.arr[i][j] == 2)
            {
                printf(" ");
            }
            else if(myData.arr[i][j] == 1)
            {
                printf("█");
            }
            else if(myData.arr[i][j] == 11)
            {
                printf("↓");
            }
            else if(myData.arr[i][j] == 12)
            {
                printf("↘");
            }
            else if(myData.arr[i][j] == 13)
            {
                printf("→");
            }
            else if(myData.arr[i][j] == 14)
            {
                printf("↗");
            }
            else if(myData.arr[i][j] == 15)
            {
                printf("↑");
            }
            else if(myData.arr[i][j] == 16)
            {
                printf("↖");
            }
            else if(myData.arr[i][j] == 17)
            {
                printf("←");
            }
            else if(myData.arr[i][j] == 18)
            {
                printf("↙");
            }
            
        }
        printf("\n");
    }
}