#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to seach for common item type
char search(char *string_1, char *string_2, char *string_3);

int main(void){
    char input_arr[1000];
    int input_arr_index = 0;
    char string_arr[3][100];
    int prio_sum = 0;

    while(scanf("%s", &input_arr[input_arr_index]) != EOF){
        strcpy(string_arr[input_arr_index], &input_arr[input_arr_index]);
        
        if(input_arr_index == 2){

            char common_item = search(string_arr[0], string_arr[1], string_arr[2]);
            if(common_item){
                if('a' <= common_item && common_item <= 'z'){
                    prio_sum += common_item - 96;
                }else if ('A' <= common_item && common_item <= 'Z'){
                    prio_sum += common_item - 38;
                }
            }
        }

        if(input_arr_index < 2){
            ++input_arr_index;
        }else{
            input_arr_index = 0;
        }
    }

    printf("%d\n", prio_sum);

    return 0;
}

char search(char *string_1, char *string_2, char *string_3){
    char* string_1_start = string_1;
    char* string_1_end = string_1 + strlen(string_1);
    char* string_2_start = string_2;
    char* string_2_end = string_2 + strlen(string_2);
    char* string_3_start = string_3;
    char* string_3_end = string_3 + strlen(string_3);

    while(string_1 < string_1_end){
        while(string_2 < string_2_end){
            if(*string_2 == *string_1){
                while (string_3 < string_3_end)
                {
                    if(*string_3 == *string_2){
                        return *string_3;
                    }

                    ++string_3;
                }                
            }
            string_3 = string_3_start;
            ++string_2;
        }
        string_2 = string_2_start;
        ++string_1;
    }

    return 0;
}
