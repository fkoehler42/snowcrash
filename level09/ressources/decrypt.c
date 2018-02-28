#include <string.h>
#include <stdio.h>

int	main(int ac, char **av) {
	if (ac != 2)
		return (0);
	for (int i = 0; i < strlen(av[1]); i++) {
		av[1][i]-= i;
	}
	puts(av[1]);
	return (0);
}