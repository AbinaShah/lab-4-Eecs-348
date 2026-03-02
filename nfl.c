#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        printf("\nPossible combinations of scoring plays if a team’s score is %d:\n\n", score);

        int td2, td1, td, fg, safety;

        for (td2 = 0; td2 <= score / 8; td2++) {
            for (td1 = 0; td1 <= score / 7; td1++) {
                for (td = 0; td <= score / 6; td++) {
                    for (fg = 0; fg <= score / 3; fg++) {
                        for (safety = 0; safety <= score / 2; safety++) {

                            int total = 8*td2 + 7*td1 + 6*td + 3*fg + 2*safety;

                            if (total == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                       td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }

        printf("\n");
    }

    return 0;
}
