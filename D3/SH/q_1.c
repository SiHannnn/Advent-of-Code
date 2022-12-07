#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to seach for common item type
char search(char *check_string, char *search_string, size_t pocket_size);

int main(void){
    char input_arr[1000];
    int input_arr_index = 0;
    int prio_sum = 0;

    while(scanf("%s", &input_arr[input_arr_index]) != EOF){
        size_t pocket_size = strlen(&input_arr[input_arr_index]) / 2;
        char *pocket_1 = &input_arr[input_arr_index];
        char *pocket_2 = &input_arr[input_arr_index] + pocket_size;

        char common_item = search(pocket_1, pocket_2, pocket_size);
        if(common_item){
            printf("%c\n", common_item);
            if('a' <= common_item && common_item <= 'z'){
                prio_sum += common_item - 96;
            }else if ('A' <= common_item && common_item <= 'Z'){
                prio_sum += common_item - 38;
            }
        }
        ++input_arr_index;
    }

    printf("%d\n", prio_sum);

    return 0;
}

char search(char *check_string, char *search_string, size_t pocket_size){
    char* end = search_string;
    while(check_string < end){
        while(*search_string){
            if(*search_string == *check_string){
                return *check_string;
            }else{
                ++search_string;
            }
        }
        //Reset seach string to the start (end for check string)
        search_string = end;        
        ++check_string;
    }

    return 0;
}
