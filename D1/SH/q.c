#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct elf{
    int cal_cnt;
    int cal_arr[100];
};

struct elf elf_arr[1000];

int main(void){
    char input_arr[100000];
    int arr_index = 0;
    int nl_cntr = 0;

    int elf_index = 0;
    int elf_cal_arr_index = 0;

    int cal_1st = 0;
    int cal_2nd = 0;
    int cal_3rd = 0;

    while(scanf("%c", &input_arr[arr_index]) != EOF){
        if(input_arr[arr_index] == '\n'){
            if(!nl_cntr){
                nl_cntr = 1;

                input_arr[++arr_index] = '\0';
                elf_arr[elf_index].cal_arr[elf_cal_arr_index++] = atoi(input_arr);
                ++elf_arr[elf_index].cal_cnt;

                arr_index = 0;
            }else{
                int total_cal_current = 0;
                for(int i = 0; i < elf_arr[elf_index].cal_cnt; ++i){
                    total_cal_current += elf_arr[elf_index].cal_arr[i];
                }

                if(total_cal_current > cal_1st){
                    cal_3rd = cal_2nd;
                    cal_2nd = cal_1st;
                    cal_1st = total_cal_current;
                }else if(total_cal_current > cal_2nd){
                    cal_3rd = cal_2nd;
                    cal_2nd = total_cal_current;
                }else if(total_cal_current > cal_3rd){
                    cal_3rd = total_cal_current;
                }

                arr_index = 0;
                ++elf_index;
                elf_cal_arr_index = 0;
            }
        }else if(input_arr[arr_index] != '\r'){
            nl_cntr = 0;
            ++arr_index;
        }
    }

    printf("%d\n", cal_1st);
    printf("%d\n", cal_2nd);
    printf("%d\n", cal_3rd);
    printf("%d\n", cal_1st + cal_2nd + cal_3rd);

    return 0;
}
