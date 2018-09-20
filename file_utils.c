#include "file_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 *
 * Opens file 1 for reading, gets the size of the file, mallocs the correct amount of memory into buffer,
 * copies the content of file 1 into buffer, closes the file and returns the size.
 *
 */
int read_file(char* filename, char **buffer ){

	// opens the file for reading.
	FILE *f = fopen(filename, "r");
	
	// checks to see if the file exists.
	// exits the progam if the file is not found.
	if(f == NULL){
		fprintf(stderr,"INVALID FILE NAME...EXITING PROGRAM\n");
		exit(1);
	}

	// finds the size of the file.
	// Code given by professor.
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;	
	
	// Gives the correct amount of memory to hold file 1 content
	*buffer = malloc(size*sizeof(char));
	
	// reads in the content of file 1 and copies it to the buffer.
	fread(*buffer, 1, size, f);

	// closes the file.
	fclose(f);
	return size;
}

/**
 *
 * Writes the value of buffer into file 2.
 *
 */
int write_file( char* filename, char *buffer, int size){
	
	// open the file for writing.
	FILE *f = fopen(filename, "w");

	// writes the value into file 2.
	fwrite(buffer,1,size,f);

	// closes the file.
	fclose(f);
	return 0;
}
