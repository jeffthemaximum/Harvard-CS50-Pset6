
/**
 * linked_completed.c
 *
 * week 7 section
 * fall 2013
 *
 * practice using linked lists
 */

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>

// typedef a node for the linked list
typedef struct node
{
    int n;
    struct node* next;
}
node;

// function prototypes
bool insert_node(int value);
void print_nodes(node* list);
void free_nodes(node* list);

// global variable for the head of the list
node* head = NULL;

int main(void)
{
    // offer the user two options
    while (true)
    {
        printf("Please choose an option (0, 1, 2): ");
        int option = GetInt();
        
        switch (option)
        {
            // quit
            case 0:
                free_nodes(head);
                printf("Goodbye!\n");
                return 0;
            
            // insert int into linked list
            case 1:
                printf("Please enter an int: ");
                int v = GetInt();
                char* success = insert_node(v) ? "was" : "was not";
                printf("The insert %s successful.\n", success);
                break;
            
            // print all ints
            case 2:
                print_nodes(head);
                break;
            
            default:
                printf("Not a valid option.\n");
                break;
        }
    }
}

/**
 * Create a new node for a given value and insert it into a list.
 */
bool insert_node(int value)
{
    // malloc space for a new node
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        return false;
    }
    
    //set new node n to value
    new_node->n = value;
    
    // first insertion
    if (head == NULL)
    {
        new_node->next = head;
        head = new_node;
        return true;
    }
    
    // create curr and prev pointers
    node* curr = head;
    node* prev = NULL;
    
    // go through list 
    while (curr != NULL)
    {  
        //if value == node
        if (value == curr->n)
        {
            //free node return false
            free(new_node);
            return false;
        }  
        
        // if value < thisNode
        if (value < curr->n)
        {
            //insert before
            new_node->next = curr;
            if (prev == NULL)
            {
                head = new_node;
            }
            else
            {
                prev->next = new_node;
            }
            return true;
        }
        // if value > thisNode
        if (value > curr->n)
        {
            //go to next node
            prev = curr;
            curr = curr->next;
            
            // update pointers
        } 
    }
    return true; 
}
   
/**
 * Print out all of the ints in a list.
 */
void print_nodes(node* list)
{
    // TODO
}

/**
 * Frees all of the nodes in a list upon exiting the program.
 */
void free_nodes(node* list)
{   
    // TODO
}
