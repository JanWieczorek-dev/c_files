#include<stdio.h>
#include <stdlib.h>
#include "tldlist.h"
#include "date.h"
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


long count;


struct tldnode
{
    char* tldname;
    long entries;
    TLDNode *left_child;
    TLDNode *right_child;
    TLDNode *parent;
    bool visited_by_iter;
};

struct tldlist
{
    Date* start;
    Date* finish;
    TLDNode *root;
};

struct tlditerator
{
    TLDNode* current_node_iter;
    TLDNode* previous;
};



TLDList *tldlist_create(Date *begin, Date *end)
{   
    if((!begin) || (!end))
    {
        return NULL;
    }
    TLDList *list = malloc(sizeof(TLDList));
    if (list)
    {
        list ->start = begin;
        list ->finish = end;
        list ->root = NULL;
        return list;
    }
    else
    {
        return NULL;
    }

}

TLDNode * search(TLDNode * node, char* key)
{

    if (node == NULL)
    {
        return node;
    }

    if ((strcmp(node->tldname, key)) == 0)
    {
        return node;
    }

    if ((strcmp(node->tldname, key)) > 0 )
    {
        return search(node->left_child, key);
    }
    else 
    {
        return search(node->right_child, key);
    }

}


void destroy_nodes(TLDNode* node)
{
    if(node){
        destroy_nodes(node->left_child);
        destroy_nodes(node->right_child);
        free(node);
    }
    
}

void tldlist_destroy(TLDList *tld)
{
    TLDNode *curr_node;

    if (tld)
    {
        curr_node = tld ->root;
    }
    else
    {
        return;
    }

    if (curr_node) {
        destroy_nodes(curr_node->left_child);
        destroy_nodes(curr_node->right_child);
        free( curr_node );
    }
    free(tld);

}

int tldlist_add(TLDList *tld, char *hostname, Date *d)
{

    char* tld_str_unprocessed;
    char tld_str_processed[3];
    int i = 0;
    TLDNode* our_node; 
    TLDNode* temp_node_curr;
    TLDNode* temp_node_trail;

    //check if the passed pointers don't point to NULL
    if ((!tld) || (!hostname) || (!d))
    {
        return 0;
    }


    // check if dates are within the range 
    if ( date_compare((tld ->start), d) > 0  ||  date_compare((tld ->finish), d) < 0)
    {
        return 0;
    }


    // find the tld:
    //get the pointer to the start of the tld
    tld_str_unprocessed = strrchr(hostname, '.') + 1;

    //check the lenght
    if (strlen(tld_str_unprocessed)>3 || strlen(tld_str_unprocessed) < 2)
    {
        return 0;
    }
    //finally, convert to lower

    while (i< strlen(tld_str_unprocessed))
    {
        tld_str_processed[i] = tolower(tld_str_processed[i]);
        i++;
    }



    // check if the hostname is already in the BST, if so increase the count
    if ( (our_node = search(tld->root, tld_str_processed)) != NULL)
    {
        (our_node->entries) ++ ;
        return 1;
    }


    // if not, create a new node 
    our_node = (TLDNode* )malloc(sizeof(TLDNode));
    if(our_node) 
    {
        our_node->left_child = NULL;
        our_node->left_child = NULL;
        our_node->parent = NULL;
        our_node -> entries = 1;
        our_node->visited_by_iter =false;
        our_node -> tldname = tld_str_processed;

    //and insert it
        temp_node_curr = tld->root;
        temp_node_trail = NULL;
    // find a suitable NULL
        while (temp_node_curr)
        {
            temp_node_trail = temp_node_curr;
            
            if(strcmp(tld_str_processed, temp_node_curr->tldname) < 0)
            {
                temp_node_curr = temp_node_curr ->left_child;
            } 
            else
            {
                temp_node_curr = temp_node_curr->right_child;
            }
        }

        //if there is nothing in the list our_node will be the root
        if (!temp_node_trail)
        {
            tld->root = our_node;
        }

        //otherwise it will be one of the children of the node to which the trailing pointer points
        else if (strcmp(tld_str_processed, temp_node_trail->tldname) < 0)
        {
            temp_node_trail ->left_child = our_node;
            our_node ->parent = temp_node_trail;
        }
        else
        {
            temp_node_trail -> right_child = our_node;
            our_node ->parent = temp_node_trail;
        }
        return 1;
    }

    else 
    {
        return 0;
    }
}


void set_to_unvisited(TLDNode* node )

{
    if(node)
    {
        set_to_unvisited(node->left_child);
        set_to_unvisited(node->right_child);
        node->visited_by_iter=false;
    }
    
}



TLDIterator *tldlist_iter_create(TLDList *tld)
{
    TLDIterator* iter;
    if (tld)
    {
        iter = (TLDIterator*)malloc(sizeof(TLDIterator));
    }

    else 
    {
        return NULL;
    }

    if (iter)
    {
        iter->current_node_iter = tld->root;
        iter->previous = tld->root;
        return iter;
        set_to_unvisited(tld->root);
    }
    else
    {
        return NULL;
    }
}


void tldlist_iter_destroy(TLDIterator *iter)
{
    free(iter);
}


//iterate over a tree - in-order traversal - I'm not sure how to implement the iterator 
//so that it works on all ADTs - this one is only suitable for a BST

//helper fuctions - to avoid to many nested if and repeated branches without risking dereferncing a null pointer

bool check_left (TLDNode* node)
{
    if (!node->left_child){
        return false;
    }
    if (node->left_child->visited_by_iter)
    {
        return false;
    }
    return true;
}

bool check_right (TLDNode* node)
{
    if (!node->right_child)
    {
        return false;
    }
    if (node->right_child->visited_by_iter)
    {
        return false;
    }
    return true;
}




//iterator


TLDNode *tldlist_iter_next(TLDIterator *iter)
{
    if(!iter)
    {
        return NULL;
    } 

    TLDNode* curr_node = (TLDNode*)malloc(sizeof(TLDNode));
    curr_node = iter->current_node_iter;

// return NULL if there is nothing in the list

    if (!curr_node)
    {
        return NULL;
    }

//iterate through the tree util a suitable node is found    
    while(true)
    {
//reached the end of the BST - return NULL
        if (curr_node->visited_by_iter)
        {
            free(curr_node);
            return NULL;
        }
//traverse the tree

//check if there are any unvsited nodes on the left if so go down the left branch
        if (check_left(curr_node))
        {
            curr_node = curr_node->left_child;
        }
//check if there are any unvsited nodes on the right if so go down the right branch
        else if (check_right(curr_node))
        {
            curr_node = curr_node->right_child;
        }

//if both childern (which means the entire left and right branches) have been visited/are NULL
//go up and set the current node to visited
        else 
        {
            if (curr_node->parent)
            {
                curr_node->visited_by_iter = true;
                iter->previous = curr_node;
                iter->current_node_iter = iter->current_node_iter->parent;
                free(curr_node);
                return iter->previous;

            }
//if both children have been visited and there is no parent we are back at the root
            else
            {
                curr_node->visited_by_iter =true;
                free(curr_node);
                return iter->current_node_iter;
            }
        }
    
    }




}


long tldlist_count(TLDList *tld)
{
    count = 0;
    TLDIterator* iter = tldlist_iter_create(tld);
    while( tldlist_iter_next(iter))
    {
        count += (tldlist_iter_next(iter)->entries);
    }
    tldlist_iter_destroy(iter);
    return count;
}




char *tldnode_tldname(TLDNode *node)
{
    if (node)
    {
        return node->tldname;
    }
    else
    {
        return NULL;
    }

}

long tldnode_count(TLDNode *node)
{
    if (node)
    {
        return node->entries;
    }
    else
    {
        return 0;
    }
}









