#include "shell.h"

/**
 * *_strcpy - copies a string.
 *
 * @dest: pointer to destionation string.
 * @src: pointer to source string
 *
 * Return: a char string
 */

char *
_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = ('\0');
	return (dest);
}

/**
 * _calloc - Allocates memory for an array of nmemb elements of size bytes.
 * @nmemb: Number of elements of the array.
 * @size: size bytes of the element type.
 * Return: Pointer to the allocated memory.
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *s;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	s = malloc(nmemb * size);
	if (s == NULL)
		return (NULL);

	for (i = 0; i < (size * nmemb); i++)
		s[i] = 0;
	return (s);
}

/**
 * a_exit - Closes the program properly if the user types exit.
 * @text: used to free memory.
 * @i: total of commands typed by user.
 * @cmd_line: 1st command typed by user.
 * @exit_status: exit status
 * Return: Pointer to the allocated memory.
 */

void a_exit(char **text, int i, char *cmd_line, int exit_status)
{
	int l = 0;

	while (l < i)
	{
		free(text[l]);
		l++;
	}
	free(text);
	free(cmd_line);
	exit(exit_status);
}

/**
 * _env - Prints the environment.
 */

void _env(void)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		/*printf("%s\n", environ[i]);*/
		i++;
	}
}

/**
 * signal_handler - Writes the prompt if CRL + c.
 * @signal: Previous value of the signal handler.
*/
void signal_handler(int signal __attribute__((unused)))
{
	write(STDOUT_FILENO, "\n$ ", 3);
}

