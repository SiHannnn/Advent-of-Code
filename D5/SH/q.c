#include <stdio.h>

#define stack_cnt 3

int main(void){
    int move_amount = 0;
    int move_from = 0;
    int move_to = 0;

    int stacks[stack_cnt][100];

    int input_index_row = 0;
    int input_index_col = 0;

    while (scanf("%d %d %d", &stacks[0][input_index_col], &stacks[1][input_index_col], &stacks[2][input_index_col]) != EOF)
    {
        printf("%d %d %d\n", stacks[0][input_index_col], stacks[1][input_index_col], stacks[2][input_index_col]);
        ++input_index_col;
    }
    

    return 0;
}