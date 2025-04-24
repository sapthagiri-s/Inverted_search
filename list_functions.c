/****************************************************************************************************************************************************************************
 * Title    : list_functions
 * Description : This file contains functions that are useful for creating list, deleting elements from the list
 *                converting upper case to lower case etc
 *****************************************************************************************************************************************************************************/

#include "main.h" // Include the header file

// Function to insert a node at the end of the list
int insert_at_last(list **head, char *string)
{
    list *new; // Pointer to the new node
    if (createnode(&new, string) == NULL) // Create a new node and check for failure
    {
        return FAILURE; // Return failure if node creation fails
    }

    if (*head == NULL) // If the list is empty
    {
        *head = new; // Set the new node as the head
        return SUCCESS; // Return success
    }
    list *temp = *head; // Temporary pointer to traverse the list

    while (temp->link != NULL) // Traverse to the last node
    {
        temp = temp->link; // Move to the next node
    }
    temp->link = new; // Link the new node at the end
    return SUCCESS; // Return success
}

// Function to create a new node
list *createnode(list **new, char *str)
{
    *new = malloc(sizeof(list)); // Allocate memory for the new node
    if (*new == NULL) // Check if memory allocation failed
    {
        printf("Node not created\n"); // Print error message
        return NULL; // Return NULL
    }
    strcpy((*new)->string, str); // Copy the string to the new node
    (*new)->link = NULL; // Set the link of the new node to NULL
    return *new; // Return the new node
}

// Function to print the list
void print_list(list *head)
{
    if (head == NULL) // Check if the list is empty
    {
        printf("List empty\n"); // Print message
        return; // Return
    }
    while (head != NULL) // Traverse the list
    {
        printf("%s ", head->string); // Print the string in the current node
        head = head->link; // Move to the next node
    }
    printf("\n"); // Print a newline
}

// Function to check for duplicates in the list
int checkdublicate(list *head, char *str)
{
    if (head == NULL) // Check if the list is empty
    {
        return FAILURE; // Return failure
    }
    while (head != NULL) // Traverse the list
    {
        if (!strcmp(head->string, str)) // Compare the strings
        {
            return SUCCESS; // Return success if duplicate is found
        }
        head = head->link; // Move to the next node
    }
    return FAILURE; // Return failure if no duplicate is found
}

// Function to convert a string to lowercase
void tolowercase(char *str)
{
    int i = 0; // Initialize index
    while (str[i] != '\0') // Traverse the string
    {
        if (str[i] >= 'A' && str[i] <= 'Z') // Check if the character is uppercase
        {
            str[i] = str[i] + 32; // Convert to lowercase
        }
        i++; // Increment index
    }
}

// Function to delete a file from the list
void delete_file(list **head, char *file)
{
    if (*head == NULL) // Check if the list is empty
    {
        printf("List Empty: "); // Print message
        return; // Return
    }
    list *temp = *head; // Temporary pointer to traverse the list
    list *prev = NULL; // Pointer to the previous node

    while (temp != NULL) // Traverse the list
    {
        if (strcmp(temp->string, file) == 0) // Check if the file matches
        {
            if (prev == NULL) // If the node to delete is the head
            {
                *head = temp->link; // Update the head
            }
            else // If the node to delete is not the head
            {
                prev->link = temp->link; // Update the link of the previous node
            }
            free(temp); // Free the memory of the deleted node
            return; // Return
        }
        prev = temp; // Update the previous node
        temp = temp->link; // Move to the next node
    }
}

// Function to create a main node
main_node *create_main_node(char *word, char *file)
{
    main_node *Main = malloc(sizeof(main_node)); // Allocate memory for the main node
    sub_node *sub = malloc(sizeof(sub_node)); // Allocate memory for the sub node
    if (Main == NULL || sub == NULL) // Check if memory allocation failed
        return NULL; // Return NULL
    Main->file_count = 1; // Initialize file count
    strcpy(Main->word, word); // Copy the word to the main node
    Main->subnode = sub; // Link the sub node to the main node
    Main->main_node = NULL; // Set the link of the main node to NULL
    sub->word_count = 1; // Initialize word count
    strcpy(sub->file_name, file); // Copy the file name to the sub node
    sub->subnode = NULL; // Set the link of the sub node to NULL

    return Main; // Return the main node
}

// Function to insert a word at the end of the main node list
int insert_word_at_last(main_node *Main, char *word, char *file)
{
    main_node *temp = Main; // Temporary pointer to traverse the main node list
    main_node *prev = NULL; // Pointer to the previous main node

    while (temp != NULL) // Traverse the main node list
    {
        if (strcmp(temp->word, word) == 0) // Check if the word matches
        {
            sub_node *sub = findfile(temp->subnode, file); // Find the file in the sub node list
            if (sub != NULL) // If the file is found
            {
                sub->word_count++; // Increment the word count
                return SUCCESS; // Return success
            }
            else // If the file is not found
            {
                temp->file_count++; // Increment the file count
                insert_file_at_last(temp->subnode, file); // Insert the file at the end of the sub node list
                return SUCCESS; // Return success
            }
        }
        prev = temp; // Update the previous main node
        temp = temp->main_node; // Move to the next main node
    }
    temp = create_main_node(word, file); // Create a new main node
    prev->main_node = temp; // Link the new main node to the previous main node
}

// Function to find a file in the sub node list
sub_node *findfile(sub_node *sub, char *file)
{
    while (sub != NULL) // Traverse the sub node list
    {
        if (strcmp(sub->file_name, file) == 0) // Check if the file matches
        {
            return sub; // Return the sub node
        }
        sub = sub->subnode; // Move to the next sub node
    }
    return NULL; // Return NULL if the file is not found
}

// Function to insert a file at the end of the sub node list
int insert_file_at_last(sub_node *sub, char *file)
{
    while (sub->subnode != NULL) // Traverse to the last sub node
    {
        sub = sub->subnode; // Move to the next sub node
    }
    sub_node *temp = malloc(sizeof(sub_node)); // Allocate memory for the new sub node
    if (temp == NULL) // Check if memory allocation failed
    {
        return FAILURE; // Return failure
    }
    temp->word_count = 1; // Initialize word count
    strcpy(temp->file_name, file); // Copy the file name to the new sub node
    temp->subnode = NULL; // Set the link of the new sub node to NULL
    sub->subnode = temp; // Link the new sub node to the last sub node

    return SUCCESS; // Return success
}
