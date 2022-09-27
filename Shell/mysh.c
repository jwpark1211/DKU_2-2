/* mysh.c / 2021.11.02 / Park Jeong Woon / 1211abc@naver.com */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define DELIMS " \t\r\n"
int status;

int tokenization(char* line, char* tokens[])
{
	int tokensize=0;
	char* token = strtok(line, DELIMS);
	
	while (token != NULL)
	{
		tokens[tokensize++] = token;
		token = strtok(NULL, DELIMS);
	}
	tokens[tokensize] = NULL;
	return tokensize;
}
int redirection(char* tokens[])
{
	int i;
	int fd;

	for (i = 0; tokens[i] != NULL; i++) {
		if (!strcmp(tokens[i], ">"))
		{
			break;
		}
	}

	if (tokens[i]) {
		if (!tokens[i + 1]) {
			return -1;
		}
		else {
			if ((fd = open(tokens[i + 1], O_RDWR | O_CREAT | S_IROTH, 0644)) == -1) {
				perror(tokens[i + 1]);
				return -1;
			}
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
		tokens[i] = NULL;
		tokens[i + 1] = NULL;

		for (i = i; tokens[i] != NULL; i++) {
			tokens[i] = tokens[i + 2];
		}
		tokens[i] = NULL;
	}
	return 0;
}
bool run(char* line)
{
	char* tokens[300];
	int tokensize ;
	int i;
	pid_t pid = -1;
	bool back; 

        for (i = 0; i < strlen(line); i++) {
		if (line[i] == '&') {
			back = true;
			line[i] = '\0';
			break;
		}
	}

	tokensize = tokenization(line, tokens);

	if (tokensize == 0)
	{
		printf("Tokenization error\n");
		return true;
	}

	if (strcmp(tokens[0],"exit")==0)
		return false;

	pid = fork();

	if (pid == 0)
	{
		if(redirection(tokens)==0){
			execvp(tokens[0], tokens);
			printf(" No such file\n ");
			exit(1);
		}
		else {
			printf("Redirection Error\n");
			exit(1);
		}
	}
	else if (pid < 0)
	{
		printf("Fork error\n");
		exit(1);
	}
	else if(back == false)
		waitpid(pid, &status, WUNTRACED);

	return true; 
}

int main(void)
{
	char line[1024];

	while (1)
	{
		printf("%s $ ", get_current_dir_name());
		fgets(line, sizeof(line) - 1, stdin);
		if (run(line) == false)
			break;
	}

	return 0;
}
