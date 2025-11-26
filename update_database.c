/****************************************************************************************************************************************************************
 * Title        : Update database
 * Description  : Update Database Operation to fill the Words of a New File in the Database.
 *                Update Database can be called only after the Database has been created.
 *****************************************************************************************************************************************************************/

#include "main.h"

int update_database(hash arr[], list **head)
{
    /* To read the File Name to be updated in the Database. */
    char file[50];
    printf("Enter file name : "); // Prompt user to enter the file name
    scanf("%s", file); // Read the file name from user input

    /* Validate file name */
    char *sub = strstr(file, ext); // Check if the file name contains the expected extension
    if (sub != NULL && (strcmp(sub, ext)) != 0) // If the extension is invalid
    {
        printf(RED "Info: Enter a valid file name\n" RESET); // Print error message
        return update_database(arr, head); // Recursively call the function to re-enter file name
    }

    /* Open file */
    FILE *fptr = fopen(file, "r"); // Open the file in read mode
    if (fptr == NULL) // Check if file opening failed
    {
        ferror(fptr); // Print file error
        return FAILURE; // Return failure
    }
    if (fgetc(fptr) != '#') // Check if the first character in the file is not '#'
    {
        return FAILURE; // Return failure
    }
    rewind(fptr); // Reset file pointer to the beginning of the file

    char str[100]; // Buffer to store each line from the file
    while (fscanf(fptr, " %s", str) != -1) // Read each word from the file
    {
        char *temp = strtok(str, "#;"); // Tokenize the string using '#' and ';' as delimiters
        int index = atoi(temp); // Convert the first token to an integer (index)

        if (arr[index].mlink == NULL) // If the main node at the index is NULL
        {
            main_node *Main = malloc(sizeof(main_node)); // Allocate memory for a new main node
            if (Main == NULL) // Check if memory allocation failed
            {
                return FAILURE; // Return failure
            }
            temp = strtok(NULL, ";"); // Get the next token (word)
            strcpy(Main->word, temp); // Copy the word to the main node
            temp = strtok(NULL, ";"); // Get the next token (file count)
            Main->file_count = atoi(temp); // Convert file count to integer
            Main->subnode = NULL; // Initialize subnode to NULL

            int i = 0; // Initialize counter for subnodes
            while (i < Main->file_count) // Loop through the file count
            {
                if (i == 0) // If it's the first subnode
                {
                    temp = strtok(NULL, ";"); // Get the next token (file name)
                    sub_node *sub = malloc(sizeof(sub_node)); // Allocate memory for a new subnode
                    if (sub == NULL) // Check if memory allocation failed
                    {
                        return FAILURE; // Return failure
                    }
                    delete_file(head, temp); // Delete the file from the list
                    strcpy(sub->file_name, temp); // Copy the file name to the subnode
                    temp = strtok(NULL, ";"); // Get the next token (word count)
                    sub->word_count = atoi(temp); // Convert word count to integer
                    sub->subnode = NULL; // Initialize subnode to NULL
                    Main->subnode = sub; // Link the subnode to the main node
                }
                else // For subsequent subnodes
                {
                    sub_node *tempsub = Main->subnode; // Get the first subnode
                    while (tempsub->subnode != NULL) // Traverse to the last subnode
                    {
                        tempsub = tempsub->subnode; // Move to the next subnode
                    }
                    temp = strtok(NULL, ";"); // Get the next token (file name)
                    delete_file(head, temp); // Delete the file from the list
                    sub_node *sub = malloc(sizeof(sub_node)); // Allocate memory for a new subnode
                    if (sub == NULL) // Check if memory allocation failed
                    {
                        return FAILURE; // Return failure
                    }
                    strcpy(sub->file_name, temp); // Copy the file name to the subnode
                    temp = strtok(NULL, ";"); // Get the next token (word count)
                    sub->word_count = atoi(temp); // Convert word count to integer
                    sub->subnode = NULL; // Initialize subnode to NULL
                    tempsub->subnode = sub; // Link the new subnode to the last subnode
                }
                i++; // Increment the counter
            }
            arr[index].mlink = Main; // Link the main node to the hash array
        }
        else // If the main node at the index is not NULL
        {
            main_node *tempmain = arr[index].mlink; // Get the first main node
            while (tempmain->main_node != NULL) // Traverse to the last main node
            {
                tempmain = tempmain->main_node; // Move to the next main node
            }
            main_node *Main = malloc(sizeof(main_node)); // Allocate memory for a new main node
            if (Main == NULL) // Check if memory allocation failed
            {
                return FAILURE; // Return failure
            }
            temp = strtok(NULL, ";"); // Get the next token (word)
            strcpy(Main->word, temp); // Copy the word to the main node
            temp = strtok(NULL, ";"); // Get the next token (file count)
            Main->file_count = atoi(temp); // Convert file count to integer
            Main->subnode = NULL; // Initialize subnode to NULL

            int i = 0; // Initialize counter for subnodes
            while (i < Main->file_count) // Loop through the file count
            {
                if (i == 0) // If it's the first subnode
                {
                    temp = strtok(NULL, ";"); // Get the next token (file name)
                    sub_node *sub = malloc(sizeof(sub_node)); // Allocate memory for a new subnode
                    if (sub == NULL) // Check if memory allocation failed
                    {
                        return FAILURE; // Return failure
                    }
                    strcpy(sub->file_name, temp); // Copy the file name to the subnode
                    temp = strtok(NULL, ";"); // Get the next token (word count)
                    sub->word_count = atoi(temp); // Convert word count to integer
                    sub->subnode = NULL; // Initialize subnode to NULL
                    Main->subnode = sub; // Link the subnode to the main node
                }
                else // For subsequent subnodes
                {
                    sub_node *tempsub = Main->subnode; // Get the first subnode
                    while (tempsub->subnode != NULL) // Traverse to the last subnode
                    {
                        tempsub = tempsub->subnode; // Move to the next subnode
                    }
                    temp = strtok(NULL, ";"); // Get the next token (file name)
                    sub_node *sub = malloc(sizeof(sub_node)); // Allocate memory for a new subnode
                    if (sub == NULL) // Check if memory allocation failed
                    {
                        return FAILURE; // Return failure
                    }
                    strcpy(sub->file_name, temp); // Copy the file name to the subnode
                    temp = strtok(NULL, ";"); // Get the next token (word count)
                    sub->word_count = atoi(temp); // Convert word count to integer
                    sub->subnode = NULL; // Initialize subnode to NULL
                    tempsub->subnode = sub; // Link the new subnode to the last subnode
                }
                i++; // Increment the counter
            }
            tempmain->main_node = Main; // Link the new main node to the last main node
        }
    }

    
    char ch; // Variable to store user choice
    printf(RED "Do you want to update the database ?(Y/y) : " RESET); // Prompt user to update the database
    scanf(" %c", &ch); // Read user choice
    if (ch == 'y' || ch == 'Y') // If user chooses to update
        save_database(arr, file); // Save the database
    else // If user chooses not to update
        printf(BOLDWHITE "Info Database is not updated " RESET); // Print info message

    return SUCCESS; // Return success
}