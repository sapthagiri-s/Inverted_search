#ifndef MAIN_H // Include guard to prevent multiple inclusions of this header file
#define MAIN_H

#include <stdio.h> // Standard I/O library
#include <stdlib.h> // Standard library for memory allocation, process control, etc.
#include <string.h> // String handling functions
#include <ctype.h> // Character handling functions

#include "colors.h" // Custom header file for color definitions
#define SIZE 28 // Define the size of the hash table
#define SUCCESS 0 // Define SUCCESS as 0
#define FAILURE -1 // Define FAILURE as -1
#define ext ".txt" // Define the file extension as ".txt"

// Define a structure for a linked list node
typedef struct node
{
    char string[20]; // String data
    struct node *link; // Pointer to the next node
} list;

// Define a structure for a sub-node in the database
typedef struct sub_node
{
    int word_count; // Count of words in the file
    char file_name[20]; // Name of the file
    struct sub_node *subnode; // Pointer to the next sub-node
} sub_node;

// Define a structure for a main node in the database
typedef struct main_node
{
    int file_count; // Count of files containing the word
    char word[50]; // Word stored in the node
    sub_node *subnode; // Pointer to the first sub-node
    struct main_node *main_node; // Pointer to the next main node
} main_node;

// Define a structure for the hash table
typedef struct Hash_table
{
    int key; // Key for the hash table
    main_node *mlink; // Pointer to the main node
} hash;

// Function prototypes
int read_and_validate(char *argv[], list **head); // Read and validate input files
int insert_at_last(list **head, char *string); // Insert a string at the end of the list
void print_list(list *head); // Print the linked list

int checkdublicate(list *head, char *str); // Check for duplicate strings in the list
list *createnode(list **new, char *str); // Create a new node in the list
int createhash(hash arr[], int size); // Create a hash table
void tolowercase(char *str); // Convert a string to lowercase

int create_database(hash arr[], list **head); // Create the database from the list
int display_database(hash arr[]); // Display the database
int search_database(hash arr[], char *data); // Search for a word in the database
int save_database(hash arr[], char *file); // Save the database to a file
int update_database(hash arr[], list **head); // Update the database with new data

main_node *create_main_node(char *word, char *file); // Create a main node
int insert_word_at_last(main_node *Main, char *word, char *file); // Insert a word at the end of the main node
sub_node *findfile(sub_node *sub, char *file); // Find a file in the sub-node list
int insert_file_at_last(sub_node *sub, char *file); // Insert a file at the end of the sub-node list
void delete_file(list **head, char *file); // Delete a file from the list

#endif // End of include guard