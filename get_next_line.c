#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>//TODO delete
#include <sys/types.h>//TODO delete
#include <sys/stat.h>//TODO delete
#include <stdio.h>
#define BUFF_SIZE 5

typedef struct	s_file
{
	char					*buffer;
	int						buff_len;
  int     			fd;
  struct s_file	*next;
}				  t_file;

void add_file(t_file **file, int fd)
{
	t_file *new_file;

	new_file = (t_file*)malloc(sizeof(t_file));
	if (new_file == NULL)
		return ;
	new_file->buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (new_file->buffer == NULL)
		return ;
	new_file->buff_len = BUFF_SIZE;
	new_file->fd = fd;
	new_file->next = *file;
	file = &new_file;
}

int get_next_line(int const fd, char **line)
{
return 0;
}

int main(int argc, char **argv)
{
  int fd;
  char *buffer;

  buffer = (char *)malloc(sizeof(char) * 5000);
  fd = open(argv[1], O_RDONLY);
  get_next_line(fd, &buffer);
  printf("%s\nfd = %i\n", buffer, fd);
  get_next_line(fd, &buffer);
  printf("%s\nfd = %i\n", buffer, fd);
}
