#include <stdio.h>
#include <string.h>

#define DISTINCT_CHAR_CNT 14

int check_match(char *input_string, char *input_string_pntr);

int main(void){
    char input_string[10000];
    char *input_string_pntr = input_string;
    scanf("%s", input_string);

    int output = 0;

    char *start = input_string;
    char *end = input_string_pntr + strlen(input_string) - (DISTINCT_CHAR_CNT - 1);
    while (input_string_pntr < end)
    {
        output = check_match(input_string, input_string_pntr);

        if(output){
            break;
        }else{
            ++input_string_pntr;
        }
    }    

    printf("%d\n", output);

    return 0;
}

int check_match(char *input_string, char *input_string_pntr){
    
    for(int i = 1; i < DISTINCT_CHAR_CNT; ++i){
        char *check_pntr = input_string_pntr + i;

        char *check_start = input_string_pntr;
        char *check_end = input_string_pntr + (DISTINCT_CHAR_CNT - 1);

        while (check_start < check_end)
        {
            if(check_start - check_pntr != 0){
                if(*check_pntr == *check_start){
                    return 0;
                }
            }
            ++check_start;
        }                    
    }

    return input_string_pntr + (DISTINCT_CHAR_CNT - 1) - input_string + 1;
}
