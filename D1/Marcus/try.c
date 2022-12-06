
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

            // Reset Value
            calorieSum = 0;
            printf("\n");
        }
        
    }

    printf("Elf with highest calorie: %d\nCalories: %d\n", mostCalorieElf, highestCalorie);
}
