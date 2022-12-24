#include <stdio.h>

void Fully_OverLap_Search(void);
void Part_OverLap_Search(void);

int main(void){
    
    //Fully_OverLap_Search();
    Part_OverLap_Search();

    return 0;
}

//Part 1 Solution
void Fully_OverLap_Search(void){
    int full_overLap_cnt = 0;

    int elf_1_min = 0, elf_1_max = 0;
    int elf_2_min = 0, elf_2_max = 0;

    while (scanf("%d-%d,%d-%d", &elf_1_min, &elf_1_max, &elf_2_min, &elf_2_max) != EOF)
    {
        //Debug
        //printf("%d-%d,%d-%d\n", elf_1_min, elf_1_max, elf_2_min, elf_2_max);
        if(elf_1_min <= elf_2_min && elf_1_max >= elf_2_max
            || elf_1_min >= elf_2_min && elf_1_max <= elf_2_max
            || elf_2_min <= elf_1_min && elf_2_max >= elf_1_max
            || elf_2_min >= elf_1_min && elf_2_max <= elf_1_max){
                ++full_overLap_cnt;
            }
    }

    printf("%d\n", full_overLap_cnt);
}

//Part 2 Solution
void Part_OverLap_Search(void){
    int part_overLap_cnt = 0;

    int elf_1_min = 0, elf_1_max = 0;
    int elf_2_min = 0, elf_2_max = 0;

    while (scanf("%d-%d,%d-%d", &elf_1_min, &elf_1_max, &elf_2_min, &elf_2_max) != EOF)
    {
        //Debug
        //printf("%d-%d,%d-%d\n", elf_1_min, elf_1_max, elf_2_min, elf_2_max);
        if(     elf_1_min <= elf_2_min && elf_1_max >= elf_2_max
            ||  elf_1_min >= elf_2_min && elf_1_max <= elf_2_max
            ||  elf_2_min <= elf_1_min && elf_2_max >= elf_1_max
            ||  elf_2_min >= elf_1_min && elf_2_max <= elf_1_max){
                ++part_overLap_cnt;
            }else if(
                    elf_1_min <= elf_2_min && elf_1_max >= elf_2_min
                ||  elf_1_min >= elf_2_min && elf_1_min <= elf_2_max
                ||  elf_2_min <= elf_1_min && elf_2_max >= elf_1_min
                ||  elf_2_min >= elf_1_min && elf_2_min <= elf_1_max
            ){
                ++part_overLap_cnt;
            }
    }

    printf("%d\n", part_overLap_cnt);
}
