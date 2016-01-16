/**
 * dictionary.c
 *
 * By Lee-Loi Chieng
 * 
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// will hold all possible 2-bit unsigned int values
#define SIZE 65536

// using a linked list for a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// create hash table
node* hashtable[SIZE];

// hashing function, got from Brenda Anderson sourced on reddit
int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % SIZE;
}

// defines variable to count amount of words loaded from dictionary
int wordcount = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // copy word to new variable because 'word' may not be altered
    int x = strlen(word);
    char newword[x + 1];
    
    // error checking
    if (newword == NULL)
    {
        printf("There was an error checking word. \n");
        return false;
    }

    // convert word to lower case
    for (int i = 0; i < x; i++)
    {
        newword[i] = tolower(word[i]);   
    }
    
    newword[x] = '\0';
    
    // hashes the word
    int index = hash_it(newword);
    
    // cursor to go through hash table
    node* cursor = hashtable[index];
    
    // while cursor hasn't reached end of linked list, search dictionary 
    while (cursor != NULL)
    {
        // checking if word is in dictionary
        if (strcmp( cursor->word, newword) == 0)
        {
            return true;
        }
        // moves cursor onto next word in list
        cursor = cursor->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open the dictionary
    FILE* fp = fopen(dictionary, "r");
    
    // error checking 
    if (fp == NULL)
    {
        printf("There was an error loading dictionary. \n");
        return false;
    }
    
    // store word on buffer including null terminator
    char BUFFER[LENGTH + 1];
    
    // read words from dictionary (cited: pg 19 of 'how stuff works')
    while(fscanf(fp, "%s", BUFFER) == 1)
    {
        // creates a new node for word
        node* new_word = malloc(sizeof(node));

        // error checking
        if (new_word == NULL)
        {
            return false;
        }
        
        // puts word from buffer into new word        
        strcpy(new_word -> word, BUFFER);
        
        // hashes word to index
        int index = hash_it(BUFFER);
        
        // puts it into the linked list
        new_word -> next = hashtable[index];    
        hashtable[index] = new_word;
        
        // counts amount of words loaded from dictionary
        wordcount++;    
    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordcount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return true;
}
