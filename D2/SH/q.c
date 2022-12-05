#include <stdio.h>

int main(void){
    int total_score = 0;

    char opp, me;
    int score_curround = 0;

    while (scanf(" %c %c", &opp, &me) == 2)
    {
        switch (me)
        {
        case 'X':
            score_curround = 1;
            switch (opp)
            {
            case 'A':
                score_curround += 3;
                break;
            case 'B':
                score_curround += 0;
                break;
            case 'C':
                score_curround += 6;
                break;
            }
            break;
        case 'Y':
            score_curround = 2;
            switch (opp)
            {
            case 'A':
                score_curround += 6;
                break;
            case 'B':
                score_curround += 3;
                break;
            case 'C':
                score_curround += 0;
                break;
            }
            break;
        case 'Z':
            score_curround = 3;
            switch (opp)
            {
            case 'A':
                score_curround += 0;
                break;
            case 'B':
                score_curround += 6;
                break;
            case 'C':
                score_curround += 3;
                break;
            }
            break;
        }
        total_score += score_curround;
    }
    

    printf("%d\n", total_score);

    return 0;
}