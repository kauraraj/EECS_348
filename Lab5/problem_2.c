#include <stdio.h>

void combinations(int score) { // Print all combinations that can lead to an inputed score
    int td, fg, safety, td_plus_2, td_plus_1; 

    for(td_plus_2 = 0; td_plus_2 <= score / 8; td_plus_2++) { // Loop through all possible combinations of scoring plays while making sure that the values are less than the score
        for(td_plus_1 = 0; td_plus_1 <= score / 7; td_plus_1++) {
            for(td = 0; td <= score/6; td++) {
                for(fg = 0; fg <= score/3; fg++) {
                    for(safety = 0; safety <= score / 2; safety++){

                        if ((td_plus_2 * 8) + (td_plus_1 * 7) + (td * 6) + (fg * 3) + (safety * 2) == score) { // Check to make sure that the combination generated equals score; if it does, print it
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", td_plus_2, td_plus_1, td, fg, safety);

                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (100) { 
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) { // End program if 0 or 1 and inputted
            printf("Program ending...");
            break;
        }
        printf("Possible combinations of scoring plays:\n"); // Print all combintions
        combinations(score); 
    }
    return 0;
}