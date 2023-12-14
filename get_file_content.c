#include "monty.h"

/**
 * get_file_content - 
 * @file:
 *
 * Return:
*/
char *get_file_content(char *file)
{
        int fd;
        char buffer[1024], *content;
        ssize_t bytes_read = 1;
        struct stat fileStat;
        int fileSize = 0;

        fd = open(file, O_RDONLY);
        if (fd == -1)
        {
                fprintf(stderr, "Error: Can't open file %s\n", file);
                exit(EXIT_FAILURE);
        }

        fstat(fd, &fileStat);
        content = malloc(fileStat.st_size + 1);
	if (!content)
		print_err("Error: malloc failed");

        while(bytes_read > 0)
        {
                bytes_read = read(fd, buffer, sizeof(buffer));
                memcpy(content + fileSize, buffer, bytes_read);
                fileSize += bytes_read;
        }

        content[fileSize] = '\0';

        close(fd);
	
	return (content);
}
