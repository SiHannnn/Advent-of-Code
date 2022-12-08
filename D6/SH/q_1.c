#include <stdio.h>
#include <string.h>

int main(void){
    char input_string[10000];
    char *input_string_pntr = input_string;
    scanf("%s", input_string);

    int output = 0;

    char *start = input_string;
    char *end = input_string_pntr + strlen(input_string) - 3;
    while (input_string_pntr < end)
    {
        if(     *input_string_pntr != *(input_string_pntr + 1)
            &&  *input_string_pntr != *(input_string_pntr + 2)
            &&  *input_string_pntr != *(input_string_pntr + 3)
            &&  *(input_string_pntr + 1) != *(input_string_pntr + 2)
            &&  *(input_string_pntr + 1) != *(input_string_pntr + 3)
            &&  *(input_string_pntr + 2) != *(input_string_pntr + 3)){
                output = input_string_pntr + 3 - start + 1;
                break;
        }

        ++input_string_pntr;
    }    

    printf("%d\n", output);

    return 0;
}
