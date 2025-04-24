/***************************************************************************************************************************************************
 * Title       : Create database function
 * Description : This function create database In this hashing is used to create database.
                 It has two arguments : database and list which contains file names
 **********************************************************************************************************************************************/

#include "main.h"

int create_database(hash arr[], list **head)
{
    // Check if the list is empty
    if (*head == NULL)
    {
        // Print error message if no files are available in the list
        printf(BOLDRED "Error : NO files Available in the list\n" RESET);
        return FAILURE; // Return failure
    }

    list *temp = *head; // Initialize temp pointer to traverse the list

    // Loop through the list of files
    while (temp != NULL)
    {
        // Open the current file in read mode
        FILE *fptr = fopen(temp->string, "r");
        if (fptr == NULL)
        {
            // Print error message if file cannot be opened
            printf(BOLDRED);
            ferror(fptr); // Display file error
            printf(RESET);
            return FAILURE; // Return failure
        }

        char ch[50]; // Buffer to store words read from the file
        int index;   // Variable to store the hash index

        // Read words from the file
        while (fscanf(fptr, "%s", ch) != -1)
        {
            tolowercase(ch); // Convert the word to lowercase

            // Determine the hash index based on the first character of the word
            if (isalpha(ch[0]))
            {
                index = ch[0] - 97; // Index for alphabetic characters
            }
            else
            {
                if (isdigit(ch[0]))
                    index = 26; // Index for numeric characters
                else
                    index = 27; // Index for special characters
            }

            // Check if the hash index is empty
            if (arr[index].mlink == NULL)
            {
                // Create a new main node for the word
                main_node *Main = create_main_node(ch, temp->string);
                if (Main == NULL)
                    return FAILURE; // Return failure if node creation fails

                arr[index].mlink = Main; // Link the new node to the hash table
            }
            else
            {
                // Insert the word at the end of the linked list
                insert_word_at_last(arr[index].mlink, ch, temp->string);
            }
        }

        fclose(fptr); // Close the file
        temp = temp->link; // Move to the next file in the list
    }

    return SUCCESS; // Return success
}