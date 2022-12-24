#include <stdio.h>
#include <stdlib.h>

void part1(char *filename);

int main(int argc, char *argv[])
{

    if(argc <2)
    {
        return 0;
    }

    part1(argv[1]);
    return 0;
}

void part1(char *filename)
{
    FILE *ifs = fopen(filename, "r");
    if(!ifs)
    {
        exit(0);
    }

    fclose(ifs);
}