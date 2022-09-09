#include <stdio.h>
#include <unistd.h>

/**
 * main - ID
 *
 * Return: Always 0.
 */
int main(void)
{
	id_t my_id;

	my_id = getid();
	printf("ali %u\n", my_id);
	my_id = getid();
	printf("lya %u\n", my_id);
	return (0);
}
