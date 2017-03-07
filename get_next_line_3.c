#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>//TODO delete
#include <sys/types.h>//TODO delete
#include <sys/stat.h>//TODO delete
#include <stdio.h>
#include "libft/libft.h"
#define BUFF_SIZE 5

typedef struct	s_buff
{
	char					*buffer;
  struct s_buff	*next;
  int           is_last;
  int           start;
}				  t_buff;

t_buff *init_buffer()
{
  t_buff *buffer;

  buffer = (t_buff*)malloc(sizeof(t_buff));
  buffer->buffer = (char*)malloc(sizeof(char) * BUFF_SIZE);
  buffer->next = NULL;
  buffer->is_last = 0;
  buffer->start = 0;
  return buffer;
}
/* 1 for left, 2 for right*/
int get_buff_dim(t_buff *buffer, int option)
{
  int i, k;

  if (option == 1)
  {
    i = 0;
    while (i < BUFF_SIZE) {
			if (buffer->buffer[i] == EOF)
				return -1;
      if (buffer->buffer[i] == '\n')
        return i;
      i++;
    }
    return i;
  }
  k = 0;
  i = BUFF_SIZE - 1;
  while (i >= 0) {
    if (buffer->buffer[i] == '\n')
      return k;
    i--;
    k++;
  }
  return BUFF_SIZE;
}

int read_until_eol(t_buff **buff, int fd)
{
  t_buff  *buffer;
  t_buff  **buffer_start;
  int total_size;
	int x;

  buffer = init_buffer();
  read(fd, buffer->buffer, BUFF_SIZE);
	buffer_start = (t_buff**)malloc(sizeof(t_buff*));
  *buffer_start = buffer;
  total_size = get_buff_dim(buffer, 1);
  while (get_buff_dim(buffer, 1) == BUFF_SIZE)
  {
    buffer->next = init_buffer();
    buffer = buffer->next;
    x = read(fd, buffer->buffer, BUFF_SIZE);
    total_size += get_buff_dim(buffer, 1);
		if (!x)
			return 0;
  }
  if (*buff == NULL)
    buff[0] = buffer_start[0];
	else if (buff[0]->buffer[BUFF_SIZE - 1] == '\n')
		buff[0] = buffer_start[0];
  else
  {
    (buff[0])->next = *buffer_start;
    total_size += get_buff_dim(buff[0], 2);
  }
  return(total_size);
}

int second_case(t_buff *buffer, char **line)
{
	char *str;
	int dim;

	if (get_buff_dim(buffer, 1) == -1)
		return (-1);
	dim = get_buff_dim(buffer, 1) - buffer->start;
	str = (char*)malloc(sizeof(char) * (dim + 1));
	strncat(str, buffer->buffer + buffer->start, dim);
	buffer->start = get_buff_dim(buffer, 1) + 1;
	buffer->buffer[buffer->start - 1] = 'z';
	*line = str;
	return 1;
}

int get_next_line(int const fd, char **line)
{
	static t_buff *buffer = NULL;
  int bytes_read;
  char *str;

  bytes_read = 0;
	if (buffer == NULL || get_buff_dim(buffer, 1) == BUFF_SIZE)
		bytes_read += read_until_eol(&buffer, fd);
	else
		return second_case(buffer, line);

  str = (char*)malloc(sizeof(char) * bytes_read + 1);

	while(buffer->next != NULL)
	{
		strcat(str, buffer->buffer + buffer->start);
		buffer = buffer->next;
	}
	strncat(str, buffer->buffer, get_buff_dim(buffer, 1));
	buffer->start = get_buff_dim(buffer, 1) + 1;
	buffer->buffer[buffer->start - 1] = 'z';
	str[bytes_read] = 0;
	*line = str;
	return 1;
}

int main(int argc, char const *argv[]) {

	char *buffer;
	int fd;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &buffer);
	printf("1st:\n%s\n", buffer);
	get_next_line(fd, &buffer);
	printf("2nd:\n%s\n", buffer);
	get_next_line(fd, &buffer);
	printf("3nd:\n%s\n", buffer);
	get_next_line(fd, &buffer);
	printf("4th:\n%s\n", buffer);
}
