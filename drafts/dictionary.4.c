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

// defines variable to count amount of words loaded from dictionary
int wordcount = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // copy word to new variable because 'word' may not be altered
    char* wordcopy = NULL;
    strcpy(wordcopy, word);
    
    // convert word to lower case
    wordcopy = tolower(wordcopy);
    
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
        index = hash_it(BUFFER);
        
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
    // returns 0 until dictionary loads and contains one word or more
    do
    {
        return 0;
    }
    while (wordcount == 0);
    
    // returns amount of words loaded in from dictionary
    return wordcount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
