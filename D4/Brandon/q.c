#include <stdio.h>
#include <stdlib.h>

void part1(char *filename);
void part2(char *filename);

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        return 0;
    }

    part1(argv[1]);
    part2(argv[1]);

    return 0;
}

void part1(char *filename)
{
    FILE *ifs = fopen(filename, "r");

    if(!ifs)
    {
        printf("Fail open");
        exit(0);
    }
    
    int p1, p2, q1, q2;
    int count = 0;
    
    while(fscanf(ifs, "%d-%d,%d-%d", &p1, &p2, &q1, &q2) != EOF) // scan values base on format
    {
        if(p1 <= q1 && p2 >= q2) // check if first pair is fully within second pair
        {
            ++count;
        }
        else if(p1 >= q1 && p2 <= q2) // else check if 2nd pair is fully within first pair
        {
            ++count;
        }
    }
    printf("Pairs fully containing the other: %d\n", count);
    fclose(ifs);
    return;
}

void part2(char *filename)
{
    FILE *ifs = fopen(filename, "r");

    if(!ifs)
    {
        printf("Fail open");
        exit(0);
    }
    
    int p1, p2, q1, q2;
    int count = 0;

    while(fscanf(ifs, "%d-%d,%d-%d", &p1, &p2, &q1, &q2) != EOF)
    {
        if((p1 >= q1 && p1 <= q2) || (p2 >= q1 && p2 <= q2)) // check if first pair overlaps with second pair
        {
            ++count;
        }
        else if((q1 >= p1 && q1 <= p2) || (q2 >= p1 && q2 <= p2)) //check if second pair overlaps with first pair
        {
            ++count;
        }
    }
    printf("Pairs overlapping: %d\n", count);
    fclose(ifs);
    return;
}
