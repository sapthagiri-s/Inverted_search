/*******************************************************************************************************************************************************************
 * Title: Save Database
 * Description: Save data base to a text file for later use.In this function has two arguments : data table and filename.
 *******************************************************************************************************************************************************/

#include "main.h"

int save_database(hash arr[], char *file)
{
    FILE *fptr = fopen(file, "w"); // Open the file in write mode
    if (fptr == NULL) // Check if the file pointer is NULL
    {
        printf("unable to open file\n"); // Print error message if file cannot be opened
        return FAILURE; // Return failure status
    }
    int i = 0; // Initialize index for hash table
    while (i < SIZE) // Loop through the hash table
    {
        main_node *temp = arr[i].mlink; // Get the main node at the current index
        while (temp != NULL) // Traverse the linked list of main nodes
        {
            fprintf(fptr, "#;%d;%s;%d;", i, temp->word, temp->file_count); // Write main node data to the file
            sub_node *sub = temp->subnode; // Get the subnode linked list
            int j = 1; // Initialize counter for subnodes
            while (j <= temp->file_count) // Loop through the subnodes
            {
                fprintf(fptr, "%s;%d;", sub->file_name, sub->word_count); // Write subnode data to the file
                j++; // Increment the subnode counter
                sub = sub->subnode; // Move to the next subnode
            }
            fprintf(fptr, "#\n"); // Write end marker for the current main node
            temp = temp->main_node; // Move to the next main node
        }
        i++; // Increment the hash table index
    }
    fclose(fptr); // Close the file
    return SUCCESS; // Return success status
}