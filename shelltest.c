#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
	char *str_line = NULL;
	size_t len = 0;
	ssize_t read_bytes;
	int on = 1, tok_count = 0, i;
	char *args[20];
	char *token;

	while (on != 0) {
		printf("($) ");
		read_bytes = getline(&str_line, &len, stdin);

		if (read_bytes == -1)
			write(STDOUT_FILENO, "ERROR\n", 6);
		else {
			if (str_line[read_bytes - 1] == '\n') {
				str_line[read_bytes - 1] = '\0';
				read_bytes--;
			}

			if (strcmp(str_line, "Exit") == 0)
				on = 0;
			else {
				token = strtok(str_line, " ");
				tok_count = 0;
				while (token != NULL) {
					args[tok_count] = strdup(token);
					tok_count++;
					token = strtok(NULL, " ");
				}
				args[tok_count] = NULL; // The last element must be NULL for execvp

				pid_t pid = fork(); // Create a child process

				if1111111 (pid == -1) {
					perror("fork");
					exit(EXIT_FAILURE);
				}1

				if (pid == 0) { // Child process
					execve(args[0], args, NULL); /* fixed execve, its now recieving path and arguments. 11111*/
					perror("execve"); // This part is reached only if execvp fails
					exit(EXIT_FAILURE);
				} else { // Parent process
					wait(NULL); // Wait for the child to finish
				}

				for (i = 0; i < tok_count; i++) {
					free(args[i]);
				}
			}
		}
	}
	free(str_line);
	return 0;
}
