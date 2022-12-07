//Brandon
#include <stdio.h>
#include <stdlib.h>

void part1(char* filename);
void part2(char* filename);

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: ./q.out inputs.txt output.txt");
        return 0;
    }
    part1(argv[1]);
    part2(argv[1]);
    return 0;
}

void part1(char* filename)
{
    FILE *ifs = fopen(filename, "r");
    if(!ifs)
    {
        printf("Unable to open file");
        exit(EXIT_FAILURE);
    }

    int playerscore = 0;
    char player, opp;
    char dict[3] = {'r', 'p', 's'}; // 0 - rock, 1 - paper, 2 - scissors

    while(fscanf(ifs, "%c%*c%c%*[\r\n]", &opp, &player) != EOF) // %*c to ignore space between and *[\r\n] to remove newline
    {
        opp = dict[opp - 'A']; // convert code to rps
        player = dict[player - 'X']; // convert code to rps
        switch(opp) // rps logic
        {
            case 'r': // opp rock
                playerscore += (player == 's' ? 0 : (player == 'p' ? 6 : 3));
                break;
            case 'p': // opp paper
                playerscore += (player == 'r' ? 0 : (player == 's' ? 6 : 3));
                break;
            case 's': // opp scissors
                playerscore += (player == 'p' ? 0 : (player == 'r' ? 6 : 3));
                break;
        }
        playerscore += (player == 'r') ? 1 : (player == 'p' ? 2 : (player == 's' ? 3 : 0)); // adds additional points for shape picked      
    }
    printf("Total Score 1: %d\n", playerscore);
    fclose(ifs);
    return;
}

void part2(char* filename)
{
    FILE *ifs = fopen(filename, "r");
    if(!ifs)
    {
        printf("Unable to open file");
        exit(EXIT_FAILURE);
    }

    int playerscore = 0;
    char player, opp;
    char dict[3] = {'r', 'p', 's'}; // 0 - rock, 1 - paper, 2 - scissors

    while(fscanf(ifs, "%c%*c%c%*[\r\n]", &opp, &player) != EOF) // %*c to ignore space between and *[\r\n] to remove newline
    {
        opp = dict[opp - 'A']; // convert code to rps
        
        switch(opp) // rps logic
        {
            case 'r': // opp rock
                player = (player == 'X' ? 's' : (player == 'Z' ? 'p' : 'r')); // pick rps base on X(lose), Y(draw), Z(win)
                playerscore += (player == 's' ? 0 : (player == 'p' ? 6 : 3));
                break;
            case 'p': // opp paper
                player = (player == 'X' ? 'r' : (player == 'Z' ? 's' : 'p')); // pick rps base on X(lose), Y(draw), Z(win)
                playerscore += (player == 'r' ? 0 : (player == 's' ? 6 : 3));
                break;
            case 's': // opp scissors
                player = (player == 'X' ? 'p' : (player == 'Z' ? 'r' : 's')); // pick rps base on X(lose), Y(draw), Z(win)
                playerscore += (player == 'p' ? 0 : (player == 'r' ? 6 : 3));
                break;
        }
        playerscore += (player == 'r' ? 1 : (player == 'p' ? 2 : (player == 's' ? 3 : 0))); // adds addition points for shape picked 
    }
    printf("Total Score 2: %d\n", playerscore);
    fclose(ifs);
    return;
}
