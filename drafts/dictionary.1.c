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

#include <stdbool.h>

#include "dictionary.h"

// using a linked list for a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
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
    
    
    // TODO
    return false;
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
