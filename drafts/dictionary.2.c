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

// initalises index
int index = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    
    // read words from dictionary (cited: pg 19 of 'how stuff works')
    //while(fgets(BUFFER, LENGTH, fp))
    {
        
        // converts everything to lower case letters
        //for (int i = 0, n = strlen(BUFFER); i< n ; i++)
        //{
         //   BUFFER[i] = tolower(BUFFER[i]);
            
            // creates a new node for word
       //     node* new_word = malloc(sizeof(node));
       //     strcpy(new_word -> word, BUFFER);
            
            // 
       //     int index = hash_it(BUFFER);
            
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
    char BUFFER[LENGTH+1];
    
    
    // read words from dictionary (cited: pg 19 of 'how stuff works')
    while(fgets(BUFFER, LENGTH, fp))
   //while (fscanf(fp,"%s", new_word->word))
    {
        
        // converts everything to lower case letters
        for (int i = 0, n = strlen(BUFFER); i< n ; i++)
        {
            BUFFER[i] = tolower(BUFFER[i]);
            
            // creates a new node for word
            node* new_word = malloc(sizeof(node));
            strcpy(new_word -> word, BUFFER);
            
            // hashes word to index
            index = hash_it(BUFFER);
            
        }
            
    }
    fclose(fp);
    
    
    //fscanf(fp, "%s", new_node-> word)

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
