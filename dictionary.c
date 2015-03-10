/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>

#include "dictionary.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHTABLE_SIZE 5000
/**
 * Creates a linked list.
 */
typedef struct newNode
{
	char* word;
	struct newNode* next;
}
// create an intitial linked list
newNode;

//setup hashtable as table of pointers
newNode* hashtable[HASHTABLE_SIZE];

// initialize hash funcion
int hash(char* word);

// initialize counter size
int count;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    //word will be in hashtable[hash(word)]
    //search in that linked list using strcmp
    int check;
    char lowerWord[LENGTH + 1];
    
    //change all words to lowercase for easier comparisons
    for (int i = 0; i < strlen(word); i++)
    {
        lowerWord[i] = tolower(word[i]);
    }
    
    // terminate this word
    lowerWord[strlen(word)] = '\0';
    
    check = hash(lowerWord);
    
    if (hashtable[check] == NULL)
    {
        return false;
    }
    else
    {
        newNode* ptr = hashtable[check];
        while (ptr != NULL)
        {
            if (strcmp(lowerWord, ptr->word) == 0) //getting stuck on this for loop...
            {
                return true;
            }
            ptr = ptr->next;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    FILE* fp = NULL;
    //newNode* head = NULL;
    //newNode* prev = NULL;
    int index;
    char dictWord[LENGTH+1];
    count = 0;
    
    // open the dictionary
    fp = fopen(dictionary, "r");

    // if dictionary is empty return false
    if(fp == NULL)
    {
        return false;
    }

    while(fscanf(fp,"%s\n", dictWord) != EOF)
    {
        count++;
        index = 0;
        //create a newNode size of node
        newNode* newNode = malloc(sizeof(newNode));
        
        //allocate the maximum size of the word for memory
        newNode->word = malloc(strlen(dictWord)+1);
        
        //copy the new word into the linked list
        strcpy(newNode->word, dictWord);
        
        //assign next node pointers
        //if first insertion
        
        //use hash function to get index value of word
        index = hash(newNode->word);
        
        //insert node into hashtable at index position
        if (hashtable[index] == NULL)
        {
            newNode->next = NULL;
            hashtable[index] = newNode;
        }
        else //(head == newNode)
        {
            newNode->next = hashtable[index];
            hashtable[index] = newNode;
        }

    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    //to do
    //free every element in the hashtable and free every node in linked list
    /*
    Zamalya's plan
    
    node* cursor = head;
    
    while (cursor != NULL)
    {
        node* temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    */
    
    /* use valgrind to check if all is free
    
    valgrind -v --leak-check=full ./speller ~cs50/pset6/texts.austinpowers.txt
    
    */   
    int index = 0;
    for (index= 0; index < 100; index++)
    {
        newNode* cursor =  hashtable[index];
        while (cursor != NULL)
        {
            newNode* temp = cursor;
            cursor = cursor->next;
            free(temp);    
        }
    }
    return true;
}

//hash function that sums the ASCII values of the letters in the word
int hash(char* word)
{
    int result = 0;
    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        result = result + word[i];
    }
    return result % HASHTABLE_SIZE;
}
