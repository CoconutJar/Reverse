#include "file_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/***
 *
 * Reverses the content on file 1 into file 2 over writes file 2 content.
 *
 **/
int main(int argc, char** argv){
	
	// Pointer to store content of file 1
	char *buffer;	
	
	// Reads in file 1 and sets buffer equal to the contents.
	// Returns the size of the file.
	int size = read_file(argv[1], &buffer);
	
	// Reverses the from file 1 now stored in buffer.
	// Using a pointer at the start and end of buffer along with a temp, the string is reversed.
	char *start = buffer, *end = buffer + size-1;
	while(end > start){
		char temp = *start;
		*start++ = *end;
		*end-- = temp;
	}	
	
	// Writes the content of buffer to a newfile with the name the 2nd arguement given.
	write_file(argv[2], buffer, size); 
	
	// Frees the memory used by buffer.
	free(buffer);
		
	return 0;
}
