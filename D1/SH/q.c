#include <stdio.h>

int main(void){
    char input_arr[1000000];

    int arr_index = 0;

    while(scanf("%c", &input_arr[arr_index]) != EOF){
        printf("%c", input_arr[arr_index++]);
    }

    return 0;
}