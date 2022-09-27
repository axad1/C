#include <cs50.c>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
//    if (argc < 2)
//    {
//        printf("Usage: tideman [candidate ...]\n");
//        return 1;
//    }

    // Populate array of candidates
    candidate_count = 3;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = get_string(NULL,"Enter name : ");
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
    	puts("Give Vote");
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
        	printf("%i ",j+1);
            string name = get_string(NULL,"Rank: ");

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
//        print ranks
        for(int i=0; i<3; i++)
        printf("rank %i is %i\n",i,ranks[i]);

        record_preferences(ranks);

        printf("\n");
        
		//	print preferences
		printf("preferences\n");
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				printf("%i ", preferences[i][j]);
			}
			printf("\n");
		}
		printf("\n");
    }

    add_pairs();
//	print pairs
	printf("pair count = %i\n",pair_count);
	for(int i=0;i<pair_count;i++)
		{
			printf("winner = %i\n",pairs[i].winner);
			printf("loser = %i\n",pairs[i].loser);
		}
		
    sort_pairs();
//    sort pairs
    printf("\npair sort = %i\n",pair_count);
	for(int i=0;i<pair_count;i++)
		{
			printf("winner = %i\n",pairs[i].winner);
			printf("loser = %i\n",pairs[i].loser);
		}
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for(int i=0;i<candidate_count;i++)
    {
    	if(strcmp(candidates[i],name) == 0)
    	{
    		ranks[rank] = i;
    		return true;
		}
	}
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for(int i=0;i<candidate_count;i++)
    {
    	for(int j=i+1; j<candidate_count; j++)
    	{
    		printf("i = %i\n",i);
    		printf("j = %i\n",j);
    		printf("irank[%i] = %i\n",i,ranks[i]);
    		printf("jrank[%i] = %i\n",j,ranks[j]);
    		preferences[ranks[i]][ranks[j]]++;
		}
	}
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for(int i=0;i<candidate_count;i++)
    {
    	for(int j=0;j<candidate_count;j++)
    	{
    		if(preferences[i][j]>preferences[j][i])
    		{
    			pairs[pair_count].winner = i;
    			pairs[pair_count].loser = j;
    			pair_count++;
			}
		}
	}
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
	printf("\nSorting start\n");
    for(int i=pair_count; i>0; i--)
    {
    	for(int j=0; j<i; j++)
    	{	
    		if(preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j+1].winner][pairs[j+1].loser])
    		{
    			printf("\nj = %i\t",j);
    			printf("preference[j] = %i\n", preferences[pairs[j].winner][pairs[j].loser]);
    			printf("preference[j+1] = %i\n", preferences[pairs[j+1].winner][pairs[j+1].loser]);
    			
    			
    			pair temp = pairs[j];
    			pairs[j] = pairs[j+1];
    			pairs[j+1] = temp;
			}
		}
	}
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}
