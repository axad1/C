// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;
unsigned int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int x = hash(word);
    node *head = table[x];
    while(head != NULL)
    {
    	if(strcasecmp(head->word, word) == 0)
    	{
    		return true;
		}
    	head = head->next;
	}
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *in = fopen(dictionary, "r");
    if(in == NULL)
    {
    	return false;
	}
	char word[LENGTH+1];
	while(fscanf(in, "%s", word) != EOF)
	{
		node *n = malloc(sizeof(node));
		strcpy(n->word, word);
		unsigned int x = hash(word);
		if(table[x] == NULL)
		{
			table[x] = n;
		}
		else
		{
			n->next = table[x];
			table[x] = n;
		}
		word_count++;
	}
	fclose(in);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for(int i=0; i<N; i++)
    {
		while(table[i] != NULL)
    	{
			node *head = table[i]->next;
    		free(table[i]);
			table[i] = head;
		}
	}
	return true;

}
