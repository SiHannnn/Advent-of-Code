#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void part1(char* filename);
void part2(char* filename);

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        return 0;
    }

    //part1(argv[1]);
    part2(argv[1]);

    return 0;
}

void part1(char* filename)
{
    FILE *ifs = fopen(filename, "r");

    if(!ifs)
    {
        exit(0);
    }

    char buffer[100];
    char newline[5];
    int col = 0, row = 0, trow, clen;
    int num, dst, src;
    int dheight, sheight;
    char *stacks, *tstacks;

    // get amount of columns and rows from input file
    do
    {
        fscanf(ifs, "%[^\r]%[\r\n]", buffer, newline);
        ++row;
    }while(strlen(newline) <= 2LU); // end loop when encounter double newline
    clen = (int)strlen(buffer);
    col = (clen + 1) / 4;
    trow = col * row;
    printf("|row %d, col %d|\n", row, col);
    
    // reset file pointer
    rewind(ifs);

    // allocate memory to parse input file + 1 for null terminating
    stacks = (char*)malloc((clen + 1) * row);
    tstacks = (char*)malloc((col + 1) * (trow - 1));

    // copies crate order into stacks memory location
    for(int i = 0; i < row; ++i)
    {
        fscanf(ifs, "%[^\r]%[\r\n]", (stacks + i * (clen + 1)), newline);
        printf("%s\n", stacks + i * (clen + 1));

        // check if end of crate order
        if(strlen(newline) > 2LU)
        {
            break;
        }
    }
    
    // transpose crate order format to horizontal format
    for(int i = 0, k = row - 2; i < row; ++i, --k)
    {
        for(int j = 1, l = 0; j < clen; j += 4, l++)
        {
            *(tstacks + i + l * (trow + 1)) = *(stacks + j + k * (clen + 1));
            if(*(tstacks + i + l * (trow + 1)) == ' ')
            {
                 *(tstacks + i + l * (trow + 1)) = '\0';
            }
        }
    }

    // append transposed crate order with null terminating
    for(int i = 0; i < col; ++i)
    {
        *(tstacks + trow + i * (trow + 1)) = '\0';
        printf("-%s, %ld\n", (tstacks + i * (trow + 1)), strlen((tstacks + i * (trow + 1))));
    }
    
    // get moving instructions from input file
    while(fscanf(ifs, "move %d from %d to %d%*[\r\n]", &num, &src, &dst) != EOF)
    {
        printf("%d, %d, %d\n", num, src--, dst--);
        
        for(int i = 0; i < num; ++i)
        {
            sheight = strlen((tstacks + src * (trow + 1)));
            dheight = strlen((tstacks + dst * (trow + 1)));
            printf("|sheight %d, dheight %d, num %d|\n", sheight, dheight, num);

            printf("|Place on top of %c with %c\n", *(tstacks + (dst *(trow+1)) + dheight - 1), *(tstacks + (src *(trow+1)) + sheight - 1));
            *(tstacks + (dst *(trow+1)) + dheight) = *(tstacks + (src *(trow+1)) + sheight - 1);
            *(tstacks + (src *(trow+1)) + sheight - 1) = '\0';
        }
        for(int i = 0; i < col; ++i)
        {
            printf("Row %d: %s, %ld\n", i + 1, (tstacks + i * (trow + 1)), strlen((tstacks + i * (trow + 1))));
        }
    }
    printf("Final:");
    for(int i = 0; i < col; ++i)
    {
        printf("%c", *(tstacks + (int)strlen((tstacks + i * (trow + 1))) - 1 + i * (trow + 1)));
    }

    free(stacks);
    free(tstacks);
    fclose(ifs);
    return;
}

void part2(char* filename)
{
    FILE *ifs = fopen(filename, "r");

    if(!ifs)
    {
        exit(0);
    }

    char buffer[100];
    char newline[5];
    int col = 0, row = 0, trow, clen;
    int num, dst, src;
    int dheight, sheight;
    char *stacks, *tstacks;

    // get amount of columns and rows from input file
    do
    {
        fscanf(ifs, "%[^\r]%[\r\n]", buffer, newline);
        ++row;
    }while(strlen(newline) <= 2LU); // end loop when encounter double newline
    clen = (int)strlen(buffer);
    col = (clen + 1) / 4;
    trow = col * row;
    printf("|row %d, col %d|\n", row, col);
    
    // reset file pointer
    rewind(ifs);

    // allocate memory to parse input file + 1 for null terminating
    stacks = (char*)malloc((clen + 1) * row);
    tstacks = (char*)malloc((col + 1) * (trow - 1));

    // copies crate order into stacks memory location
    for(int i = 0; i < row; ++i)
    {
        fscanf(ifs, "%[^\r]%[\r\n]", (stacks + i * (clen + 1)), newline);
        printf("%s\n", stacks + i * (clen + 1));

        // check if end of crate order
        if(strlen(newline) > 2LU)
        {
            break;
        }
    }
    
    // transpose crate order format to horizontal format
    for(int i = 0, k = row - 2; i < row; ++i, --k)
    {
        for(int j = 1, l = 0; j < clen; j += 4, l++)
        {
            *(tstacks + i + l * (trow + 1)) = *(stacks + j + k * (clen + 1));
            if(*(tstacks + i + l * (trow + 1)) == ' ')
            {
                 *(tstacks + i + l * (trow + 1)) = '\0';
            }
        }
    }

    // append transposed crate order with null terminating
    for(int i = 0; i < col; ++i)
    {
        *(tstacks + trow + i * (trow + 1)) = '\0';
        printf("-%s, %ld\n", (tstacks + i * (trow + 1)), strlen((tstacks + i * (trow + 1))));
    }
    
    // get moving instructions from input file
    while(fscanf(ifs, "move %d from %d to %d%*[\r\n]", &num, &src, &dst) != EOF)
    {
        printf("%d, %d, %d\n", num, src--, dst--);

        sheight = strlen((tstacks + src * (trow + 1)));
        printf("|sheight %d, dheight %d, num %d|\n", sheight, dheight, num);
        
        for(int i = num - 1; i >= 0; --i)
        {
            dheight = strlen((tstacks + dst * (trow + 1)));
            //printf("|Place on top of %c with %c\n", *(tstacks + (dst *(trow+1)) + dheight - 1), *(tstacks + (src *(trow+1)) + sheight - 1));
            *(tstacks + (dst *(trow+1)) + dheight) = *(tstacks + (src *(trow+1)) + sheight - 1 - i);
            *(tstacks + (src *(trow+1)) + sheight - 1 - i) = '\0';
        }
        for(int i = 0; i < col; ++i)
        {
            printf("Row %d: %s, %ld\n", i + 1, (tstacks + i * (trow + 1)), strlen((tstacks + i * (trow + 1))));
        }
    }
    printf("Final:");
    for(int i = 0; i < col; ++i)
    {
        printf("%c", *(tstacks + (int)strlen((tstacks + i * (trow + 1))) - 1 + i * (trow + 1)));
    }

    free(stacks);
    free(tstacks);
    fclose(ifs);
    return;
}
/*
1 ZN
2 MCD
3 P

1 0NZ ZN0 
2 DCM MCD
3 00P P0

A1 A2 A3 | 0 + 0 * 3 | 1 + 0 * 3
B1 B2 B3 | 0 + 1 * 3 | 1 + 1 * 3

A1 B1 | 0 + 0 * 2 | 1 + 0 * 2
A2 B2 | 0 + 1 * 2 | 1 + 1 * 2
A3 B3

A1 A2 A3 B1 B2 B3
A1 B1 A2 B2 A3 B3
*/
