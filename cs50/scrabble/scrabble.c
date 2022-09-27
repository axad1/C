#include <ctype.h>
#include <cs50.c>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("","Player 1: ");
    string word2 = get_string("","Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Printing the winner
    if(score1 > score2)
    	printf("Player 1 wins! with %i\n",score1);
	else if(score1 < score2)
    	printf("Player 2 wins! with %i\n",score2);
    else
    	printf("Tie!\n");
}

int compute_score(string word)
{
    //Compute
    int score = 0;

    for(int i=0; i<strlen(word); i++)
    {
	//  convert each character of word to lowerCase
		switch(tolower(word[i]))
		{
			case 'a':
				score += POINTS[0];
				break;
			case 'b':
				score += POINTS[1];
				break;
			case 'c':
				score += POINTS[2];
				break;
			case 'd':
				score += POINTS[3];
				break;
			case 'e':
				score += POINTS[4];
				break;
			case 'f':
				score += POINTS[5];
				break;
			case 'g':
				score += POINTS[6];
				break;
			case 'h':
				score += POINTS[7];
				break;
			case 'i':
				score += POINTS[8];
				break;
			case 'j':
				score += POINTS[9];
				break;
			case 'k':
				score += POINTS[10];
				break;
			case 'l':
				score += POINTS[11];
				break;
			case 'm':
				score += POINTS[12];
				break;
			case 'n':
				score += POINTS[13];
				break;
			case 'o':
				score += POINTS[14];
				break;
			case 'p':
				score += POINTS[15];
				break;
			case 'q':
				score += POINTS[16];
				break;
			case 'r':
				score += POINTS[17];
				break;
			case 's':
				score += POINTS[18];
				break;
			case 't':
				score += POINTS[19];
				break;
			case 'u':
				score += POINTS[20];
				break;
			case 'v':
				score += POINTS[21];
				break;
			case 'w':
				score += POINTS[22];
				break;
			case 'x':
				score += POINTS[23];
				break;
			case 'y':
				score += POINTS[24];
				break;
			case 'z':
				score += POINTS[25];
				break;
			default:
				break;
		}
	}

//	Return score for string
	return score;
}
