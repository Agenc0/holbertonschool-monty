#include "monty.h"

/**
 * getting_stream_failed - Error handler when reading file fails
 * @fileName: The name of the file that failed to open
 */

void getting_stream_failed(char *fileName)
{
	dprintf(stderr, "Error: Can't open file %s\n", fileName);
	free_arguments();
	exit(EXIT_FAILURE);
}

/**
 * get_stream - gets the stream for reading from the specified file
 * @fileName: Name of the file to open and set as the stream.
 */

void get_stream(char *fileName)
{
	int file_descriptor;

	file_descriptor = open(fileName, O_RDONLY);
	if (file_descriptor == -1)
		getting_stream_failed(fileName);

	arguments->stream = fdopen(file_descriptor, "r");
	if (arguments->stream == NULL)
	{
		close(file_descriptor);
		getting_stream_failed(fileName);
	}
}
