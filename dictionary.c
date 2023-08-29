// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <stdio.h>

#include "dictionary.h"
 int sizex =0;
  FILE *f;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N =26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int x = hash(word);

    node *cursor;

    cursor = table[x];

    while(cursor!=NULL)
    {

    if(strcasecmp(word,cursor->word)!=0)
    {

        cursor= cursor->next;

    }

    else{

        return true;
    }

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
    f =fopen(dictionary,"r");

    if(f == NULL){

        printf("invalid file");
        return false;

    }

    char word1[LENGTH + 1];

    while(fscanf(f, "%s", word1)!= EOF)
    {

         node *n = malloc(sizeof(node));

         if(n==NULL)
         {

            return false;

         }

         strcpy(n->word, word1);


         int index = hash(word1);

         n->next = table[index];

         table[index] = n;

           sizex++;


}
 fclose(f);

      return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return sizex;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *tmp;

    node *cursor;

    for(int i = 0;i<N; i++){

        tmp = table[i];

         while(tmp!=NULL)
         {

          cursor = tmp->next;

          free(tmp);

          tmp = cursor;
    }
    }

    return false;
}
