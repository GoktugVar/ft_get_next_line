#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			a;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	while (a = read(fd, buffer, BUFFER_SIZE) >= 0)
	{
		temp = stack;
		stack = ft_strjoin(stack, buffer);
		if(temp)
			free(temp);
		if (ft_strchr(stack, '\n') == NULL && a != 0)
			continue ;
		line = ft_substr(stack, 0, ft_strchr(stack, '\n') - stack);
		temp = stack;
		stack = ft_substr(stack, ft_strchr(stack, '\n') - stack + 1, ft_strlen(ft_strchr(stack, '\n')));
		if(temp)
			free(temp);
		return (line);
	}
	return (NULL);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	char *a;
	a = get_next_line(fd);
	printf("-|%s|-\n",  a);
	free(a);
	a = get_next_line(fd);
	printf("-|%s|-\n",  a);
	free(a);
	a = get_next_line(fd);
	printf("-|%s|-\n",  a);
	free(a);
	a = get_next_line(fd);
	printf("-|%s|-\n",  a);
	free(a);
	a = get_next_line(fd);
	printf("-|%s|-\n",  a);
	free(a);
	a = get_next_line(fd);
	printf("-|%s|-\n",  a);
	free(a);
	a = get_next_line(fd);
	printf("-|%s|-\n",  a);
	free(a);
	a = get_next_line(fd);
	printf("-|%s|-\n",  a);
	free(a);
	close(fd);
	return (0);
}
