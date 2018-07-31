#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main (void)
{
    // int rolls[21] = {1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 0, 1, 7, 3, 6, 4, 10, 0, 2, 8, 6};
     int rolls[21] = {10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10};

    int finalscore = 0;
    bool strike = false;
    bool spare = false;

    for (int i = 0; i < 20; i++)
    {
        // the frame
        if (i%2 == 0)
        {
            if (strike || spare)
            {
                finalscore += rolls[i] * 2;
                spare = false;
            }
            else
            {
                finalscore += rolls[i];
            }

            if (strike)
            {
                printf("finalscore mod2 is %i\n", finalscore);
                strike = false;
                if (rolls[i] == 10)
                {
                    strike = true;
                }
                else if (rolls[i] + rolls[i+1] == 10)
                {
                    spare = true;
                    finalscore += rolls[i+1] * 2;
                    printf("finalscore spare is %i\n", finalscore);
                }
                else
                {
                    finalscore += rolls[i+1] * 2;
                    printf("finalscore else is %i\n", finalscore);
                }

                // reset spare to false
            }
            else
            {
                printf("finalscore mod2 is %i\n", finalscore);
                if (rolls[i] == 10)
                {
                    strike = true;

                }
                else if (rolls[i] + rolls[i+1] == 10)
                {
                    spare = true;
                    finalscore += rolls[i+1];
                    printf("finalscore spare is %i\n", finalscore);
                }
                else
                {
                    finalscore += rolls[i+1];
                    printf("finalscore else is %i\n", finalscore);
                }
                // reset spare to false
            }



        }
    }
    finalscore += rolls[20];
    printf("finalscore is %i\n", finalscore);


}