//Brandon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void part1(char* filename);
void part2(char* filename);

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
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
        exit(EXIT_FAILURE);
    }

    char buffer;
    int rsLength, commonType, sumPriorities = 0;
    char *rucksack;
    rsLength = 0;
    
    while((buffer = fgetc(ifs)) != EOF) //check if EOF
    {
        if(buffer != '\r')
        {
            fseek(ifs, -1L, SEEK_CUR); //reverse file pointer by 1 byte
        }
        else
        {
            fgetc(ifs);
        }
        rsLength = 0;
        while((buffer = fgetc(ifs)) != '\r' && buffer != EOF) // fgets until newline
        {
            ++rsLength; // get length of 1 rucksack line
        }
        if(buffer == '\r')
        {
            ++rsLength; // increment 1 for newline check
        }
        fseek(ifs, -(long)(rsLength), SEEK_CUR); // reverse pointer back
        if(buffer == '\r')
        {
            --rsLength; // decrement 1 to remove newline count
        }
        rucksack = (char*)malloc((size_t)rsLength); // allocate memory for 1 rucksack
        for(int i = 0; i < rsLength; ++i)
        {
            *(rucksack + i) = fgetc(ifs); // fill memory with line of rucksack
        }

        for(int i = 0, j; i < rsLength/2; ++i)
        {
            for(j = rsLength/2; j < rsLength; ++j)
            {
                if(*(rucksack + i) == *(rucksack + j)) // check for common type in both comparments
                {
                    commonType = (int)*(rucksack + i);
                }
            }
        }
        if(isupper(commonType))
        {
            commonType -= 'A' - 27; // change to priority number uppercase 27 - 52
        }
        else
        {
            commonType -= 'a' - 1; // change to priority number lowercase 1 - 26
        }
        sumPriorities += commonType; // sum of priorities of item type
        free(rucksack);
    }    
    printf("Part1: %d\n", sumPriorities);
    fclose(ifs);
    return;
}

void part2(char* filename)
{
    FILE *ifs = fopen(filename, "r");

    if(!ifs)
    {
        exit(EXIT_FAILURE);
    }

    char buffer;
    int rsLength, commonType, sumPriorities = 0;
    char *rucksack[3];
    rsLength = 0;
    
    while(buffer != EOF) //check if EOF
    {
        for(int k = 0; k < 3; ++k, buffer = fgetc(ifs)) // loop 3 times to allocate and fill memory for group of 3 rs
        {
            rsLength = 0;

            if(buffer != '\r')
            {
                fseek(ifs, -1L, SEEK_CUR); //reverse file pointer by 1 byte
            }
            else
            {
                fgetc(ifs);
            }

            while((buffer = fgetc(ifs)) != '\r' &&  buffer != EOF) // fgets until newline
            {
                ++rsLength; // length of one rucksack
            }
            if(buffer == '\r')
            {
                ++rsLength; // increment 1 for newline check
            }
            fseek(ifs, -(long)(rsLength), SEEK_CUR); // reverse pointer back
            if(buffer == '\r')
            {
                --rsLength; // decrement 1 to remove newline count
            }
            *(rucksack + k) = (char*)malloc((size_t)(rsLength+1)); // allocate memory for 1 rucksack
            for(int i = 0; i < rsLength; ++i)
            {
                *(*(rucksack + k) + i) = fgetc(ifs); // fill memory with line of rucksack
            }
            *(*(rucksack + k) + rsLength) = '\0';
            //printf("%s\n", *(rucksack + k));
        }
        
        for(int i = 0; rucksack[1][i]; ++i)
        {
            for(int j = 0; rucksack[0][j]; ++j)
            {
                if(rucksack[0][j] == rucksack[1][i]) // check if 1st string and 2nd string character matches
                {
                    for(int k = 0; rucksack[2][k]; ++k) 
                    {
                        if(rucksack[0][j] == rucksack[2][k]) // check if matched character exists in 3rd string
                        {
                            commonType = rucksack[0][j];
                        }
                    }
                }
            }
        }

        if(isupper(commonType))
        {
            commonType -= 'A' - 27; // change to priority number uppercase 27 - 52
        }
        else
        {
            commonType -= 'a' - 1; // change to priority number lowercase 1 - 26
        }
        sumPriorities += commonType; // sum of priorities of item type

        for(int i = 0; i < 3; ++i)
        {
            free(rucksack[i]);
        }
    }    
    printf("Part2: %d\n", sumPriorities);
    fclose(ifs);
    return;
}