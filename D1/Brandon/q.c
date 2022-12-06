//Brandon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: ./q.out inputs.txt output.txt");
        return 0;
    }

    FILE *ifs = fopen(argv[1], "r");

    if(!ifs)
    {
        printf("Error opening file\n");
        return 0;
    }

    int calories, sumCalories = 0, top1, top2, top3;
    int count;
    top1 = top2 = top3 = 0;

    while(fscanf(ifs,"%d", &calories) != EOF)//get integer from file
    {        
        count = 0;
        int buffer;
        while((buffer = fgetc(ifs)) != EOF) //loop to check for newlines
        {
            if(isdigit(buffer)) //if digit exit loop
            {
                fseek(ifs, -1L, SEEK_CUR); //reverse file pointer by 1 for scanf %d
                break;
            }
            if(buffer == '\r' || buffer == '\n') //increment if newline
            {
                ++count;
            }
        }        
        sumCalories += calories;
        if(count > 2 || buffer == EOF)
        {
            if(sumCalories >= top1)
            {
                top3 = top2;
                top2 = top1;
                top1 = sumCalories;
            }
            else if(sumCalories >= top2)
            {
                top3 = top2;
                top2 = sumCalories;
            }
            else if(sumCalories >= top3)
            {
                top3 = sumCalories;
            }
            sumCalories = 0;
        }         
    }
    sumCalories = top3 + top2 + top1;
    printf("Top 3 calories: %d, %d, %d\nTotal sum of calories: %d", top1, top2, top3, sumCalories);
    return 0;
}