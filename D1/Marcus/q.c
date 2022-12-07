#include <stdio.h>

int main(void)
{
    FILE *inputFile = fopen("./SHIT.txt", "r");

    int mostCalorieElf = 0;
    int currentElf = 0;
    int calorie = 0;
    int calorieSum = 0;
    int highestCalorie = 0;
    char buffer[2] = {};

    int top1 = 0, top2 = 0, top3 = 0;

    while (fscanf(inputFile, "%d%2[\n]", &calorie, buffer) != EOF)
    {
        // Debug
        printf("%d\n", calorie);
        calorieSum += calorie;

        // When it's new elf
        if (buffer[0] == '\n' && buffer[1] == '\n')
        {
            currentElf += 1;
            printf("Current Elf: %d\n", currentElf);
            
            // If previous is lesser than current, set mostCalorieElf to currentElf;
            if (calorieSum > highestCalorie)
            {
                mostCalorieElf = currentElf;
                highestCalorie = calorieSum;
            }

            printf("Sum of Calories: %d\n", calorieSum);
            printf("highest cal: %d\n", highestCalorie);
            
            if(calorieSum > top1)
            {
                top3 = top2;
                top2 = top1;
                top1 = calorieSum;
            }
            printf("1st: %d\n", top1);
            if(calorieSum < top1 && calorieSum > top2)
            {
                top3 = top2;
                top2 = calorieSum;
            }
            printf("2nd: %d\n", top2);
            if(calorieSum < top2 && calorieSum > top3)
            {
                top3 = calorieSum;
            }
            printf("3rd: %d\n", top3);

            // Reset values
            calorieSum = 0;

            //  Debug
            printf("\n");
        }
    }

    printf("3rd: %d\n", top3);
    printf("2nd: %d\n", top2);
    printf("1st: %d\n", top1);

    printf("Sum of top 3: %d\n", top1 + top2 + top3);

    printf("Elf with the most calories: %d\nCalories he has: %d\n", mostCalorieElf, highestCalorie);
}