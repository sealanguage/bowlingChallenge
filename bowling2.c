// tdd used in creatig bowling solution

#include <cs50.h>
#include <stdio.h>
#include <assert.h>

void tests(void);
    // int five = 5;
    // assert(five == 5 && "five should contain the int 5");
void bowlGameInit(void);
void bowlGameRoll(int pins);
void bowlGameScore();

int main(void)
{
    tests();
}

void rollMany(int rolls, int pins)
{
    for (int i = 0; i < rolls; i++)
    {
        bowlGameRoll(pins);
    }
}
void testGutterGame(void)
{
    bowlGameInit();
    rollMany(20, 0);
    assert(bowlGameScore() == 0 && "Gutter game should result in 0");
}
void testAllOnes(void)
{
   bowlGameInit();
   rollMany(20, 1);
   assert(bowlGameScore() == 20 && "Gutter game should result in 20");
}
void testOneSpare(void)
{
    bowlGameInit();
    bowlGameRoll(5);
    bowlGameRoll(5);
    bowlGameRoll(3);
    rollMany(17, 0);
    assert(bowlGameScore() == 16 && "one spare with 3 bonus should be 16");

}
void testOneStrike()
{
    bowlGameInit();
    bowlGameRoll(10);
    bowlGameRoll(3);
    bowlGameRoll(4);
    rollMany(16, 0);
    assert(bowlGameScore() == 24 && "one spare with 3 and 4 bonus should be 24");
}
void testPerfectGame()
{
    bowlGameInit();
    rollMany(20, 10);
    assert(bowlGameScore() == 24 && "a perfect game is 300 points");
}
void testGiven()
{
    bowlGameInit();
    int bowlGame[21] = {1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 0, 1, 7, 3, 6, 4, 10, 0, 2, 8, 6};
    int frameIndex = 0;
    for (int frame = 0; frame < 10; frame++)
    {
        if (bowlGame[frameIndex] == 10)
        {
            bowlGameRoll(10);
            frameIndex += 2;
        }
        else
        {
            bowlGameRoll(bowlGame[frameIndex++]);
            bowlGameRoll(bowlGame[frameIndex++]);
        }
        bowlGameRoll(bowlGame[frameIndex]);
        printf("%i", bowlGameScore());
        assert(bowlGameScore() == 133 && "given game");
    }

}
void tests(void)
{
    testGutterGame();
    testAllOnes();
    testOneSpare();
    testOneStrike();
    testPerfectGame();
    testGiven();
}

int MAXROLLS = 21;
int rolls[21];
int currentRoll = 0;

void bowlGameInit(void)
{
    for (int i = 0; i < MAXROLLS; i++)
    {
        rolls[i] = 0;
    }
    currentRoll = 0;
}

void bowlGameRoll(int pins)
{
    // score +- pint;
    rolls[currentRoll++] = pins;      //  ++ then variable increments then uses, variable then ++ uses then  increments
}
bool isSpare(int frameIndex)
{
    return rolls[frameIndex] + rolls[frameIndex + 1] == 10;
}
bool isStrike(int frameIndex)
{
    return rolls[frameIndex] == 10;
}

void bowlGameScore(void)
{
    int score = 0;
    int frameIndex = 0;
    for (int frame = 0; frame < 10; frame++)
        {
            if (isStrike(frameIndex))
            {
                score += 10 + rolls[frameIndex + 1] + rolls[frameIndex + 2];
                frameIndex += 1;
            }
            else if(isSpare(frameIndex))
            {
                score += 10 + rolls[frameIndex + 2];
                frameIndex += 2;
            }
            else
            {
                score = rolls[frameIndex] + rolls[frameIndex + 1];
                frameIndex += 2;
            }
        }
    return score;

}