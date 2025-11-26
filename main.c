/**************************************************************************************************************************************************************
 *Title		    : main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/

#include "main.h" // Include the header file

int createDB = 0; // Flag to track if the database is created
int updateDB = 0; // Flag to track if the database is updated

int main(int argc, char *argv[])
{
	int choice;	   // Variable to store user choice
	if (argc == 1) // Check if no arguments are passed
	{
		printf(BOLDRED "Error: Invalid Number of arguments \n" RESET);			  // Print error message
		printf(BOLDRED "INFO: Usage ./a.out <file.txt> <file1.txt> ...\n" RESET); // Print usage info
		return 0;																  // Exit the program
	}
	list *head = NULL;					 // Initialize the file list head to NULL
	read_and_validate(argv, &head);		 // Validate and store file names in the list
	printf(BOLDMAGENTA "Files are:   "); // Print message
	print_list(head);					 // Print the list of files
	printf(RESET);						 // Reset terminal color
	hash arr[SIZE];						 // Declare hash array
	createhash(arr, SIZE);				 // Initialize the hash array

	// Display menu options
	printf(BLACK "1.Create Database\n2.Diaplay Database\n3.Search database \n4.Save data base\n5.Update data base\n6.Exit\n" RESET);
	while (1) // Infinite loop for menu
	{
		printf("Enter choice : "); // Prompt user for choice
		scanf("%d", &choice);	   // Read user choice
		switch (choice)			   // Switch case for menu options
		{
		case 1:													   // Create database
			if (createDB == 0 && (updateDB == 1 || updateDB == 0)) // Check if database can be created
			{
				if (create_database(arr, &head) == SUCCESS) // Call create_database function
				{
					printf(BLACK "Info: Database created successfully\n" RESET); // Print success message
					createDB = 1;												 // Set createDB flag
				}
				else
				{
					printf(BOLDRED "Info: DB creation is unsuccessfull\n" RESET); // Print failure message
				}
			}
			else
			{
				printf(BOLDRED "Info: Database for entered file already created\n" RESET); // Print already created message
			}
			break;
		case 2:					   // Display database
			display_database(arr); // Call display_database function
			break;
		case 3: // Search database
		{
			char data[50];							   // Buffer to store search data
			printf("Enter data to be search: ");	   // Prompt user for data
			scanf("%s", data);						   // Read data
			if (search_database(arr, data) == FAILURE) // Call search_database function
			{
				printf(BOLDRED "Error: Data not found\n" RESET); // Print not found message
			}
		}
		break;
		case 4: // Save database
		{
			char file[50]; // Buffer to store file name
		index:
			printf("Enter file name : ");	  // Prompt user for file name
			scanf(" %s", file);				  // Read file name
			char *sub = strstr(file, ".txt"); // Check file extension
			//printf("Sub -> %s\n", sub);
			if (sub != NULL && strcmp(sub, ext) == 0) // Validate file extension
			{
				if (save_database(arr, file) == SUCCESS) // Call save_database function
				{
					printf(BLACK "Info: Data saved successfully\n" RESET); // Print success message
				}
			}
			else
			{
				printf("Enter a valid filename : \n"); // Print invalid filename message
				goto index;							   // Retry input
			}
		}
		break;
		case 5:									// Update database
			if (updateDB == 0 && createDB == 0) // Check if database can be updated
			{
				if (update_database(arr, &head) == SUCCESS) // Call update_database function
					updateDB = 1;							// Set updateDB flag
			}
			else
			{
				printf(BOLDRED "Info : May be database is created or data base is already updated \n" RESET); // Print already updated message
			}
			break;
		case 6:									// Exit
			printf(BLACK "Exit......\n" RESET); // Print exit message
			exit(0);							// Exit the program

		default:											  // Invalid choice
			printf(BOLDRED "Error : Invalid Choice\n" RESET); // Print invalid choice message
		}
	}
}

// To Validate the File Names passed as CLA and store them in the File List.
int read_and_validate(char *args[], list **head)
{
	int i = 1;		// Start from the second argument
	while (args[i]) // Loop through all arguments
	{
		char *sub = strstr(args[i], ext);		  // Check file extension
		if (sub != NULL && strcmp(sub, ext) != 0) // Validate file extension
		{
			printf(BOLDRED "Error: %s should be have .txt extention\n" RESET, args[i]); // Print invalid extension message
			i++;																		// Move to the next argument
			continue;																	// Skip to the next iteration
		}
		FILE *fptr = fopen(args[i], "r"); // Open the file
		if (fptr == NULL)				  // Check if file exists
		{
			printf(BOLDRED "Error: %s named file not available\n" RESET, args[i]); // Print file not found message
			i++;																   // Move to the next argument
			continue;															   // Skip to the next iteration
		}
		if (fgetc(fptr) == EOF) // Check if file is empty
		{
			printf(BOLDRED "Error: %s is empty\n" RESET, args[i]); // Print empty file message
			i++;												   // Move to the next argument
			continue;											   // Skip to the next iteration
		}
		fclose(fptr);								   // Close the file
		if (checkdublicate(*head, args[i]) == SUCCESS) // Check for duplicate file
		{
			printf(BOLDRED "Error: %s already exist\n" RESET, args[i]); // Print duplicate file message
			i++;														// Move to the next argument
			continue;													// Skip to the next iteration
		}
		insert_at_last(head, args[i]); // Insert file into the list
		i++;						   // Move to the next argument
	}
}
