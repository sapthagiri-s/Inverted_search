/*****************************************************************************************************************************************************************************
 * Title    : Search database
 * Description : Search Database Operation for a given Word entered by the User.
 *****************************************************************************************************************************************************************************/

#include "main.h"

int search_database(hash arr[], char *data)
{
	tolowercase(data); // Convert the input word to lowercase
	int index = data[0] % 97; // Calculate the hash index based on the first character of the word
	main_node *temp = arr[index].mlink; // Get the main node at the calculated index
	while (temp != NULL) // Traverse the linked list at the hash index
	{
		/*validate data is word is present */
		if (strcmp(temp->word, data) == 0) // Check if the word matches the current node's word
		{
			printf(BLACK "[%d]\t%s\t%d\t", index, data, temp->file_count); // Print the index, word, and file count
			int i = 1; // Initialize a counter for subnodes
			sub_node *sub = temp->subnode; // Get the subnode linked list
			while (sub != NULL) // Traverse the subnode linked list
			{
				printf(BLACK "%s\t %-5d", sub->file_name, sub->word_count); // Print file name and word count
				sub = sub->subnode; // Move to the next subnode
			}
			printf(RESET "\n"); // Reset the color and print a newline
			return SUCCESS; // Return success if the word is found
		}
		temp = temp->main_node; // Move to the next main node
	}
	return FAILURE; // Return failure if the word is not found
}
