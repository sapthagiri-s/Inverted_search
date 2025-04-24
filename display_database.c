/********************************************************************************************************************************************************
 * Title        : Display Database
 * Description  : Function used to display the database on the screen/terminal.
 * ***************************************************************************************************************************************************/

#include "main.h" // Include the main header file

int display_database(hash arr[]) // Function to display the database
{
	int i = 0; // Initialize index variable for hash array
	while (i < SIZE) // Loop through the hash array
	{
		main_node *temp = arr[i].mlink; // Get the main linked list for the current hash index
		while (temp != NULL) // Traverse the main linked list
		{
			printf("[%d]\t", i); // Print the hash index
			printf("%s\t%d\t", temp->word, temp->file_count); // Print the word and file count
			sub_node *sub = temp->subnode; // Get the sub-node linked list
			int j = 1; // Initialize counter for sub-nodes
			while (j <= temp->file_count) // Loop through the sub-nodes
			{
				printf("%s\t%d\t", sub->file_name, sub->word_count); // Print the file name and word count
				j++; // Increment the sub-node counter
				sub = sub->subnode; // Move to the next sub-node
			}
			printf("\n"); // Print a newline after processing a main node
			temp = temp->main_node; // Move to the next main node
		}
		i++; // Increment the hash index
	}
}
