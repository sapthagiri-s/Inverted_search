/******************************************************************************************************************************************************************
 * Title       : create hash table
 * Description : This function use to create hash table (has two parts key and link )

******************************************************************************************************************************************************************* */

#include "main.h" // Include the header file "main.h" for necessary declarations

int createhash(hash arr[], int size) // Function to create a hash table
{
    for (int i = 0; i < size; i++) // Loop through each index of the hash table
    {
        arr[i].key = i; // Assign the index value as the key
        arr[i].mlink = NULL; // Initialize the link (mlink) to NULL
    }
    return SUCCESS; // Return SUCCESS to indicate successful creation
}