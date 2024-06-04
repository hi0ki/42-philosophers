FILES= philo.c ft_atoi.c utils.c fill_struct.c routine.c

OBJ= $(FILES:.c=.o)

NAME= philo
CC= cc -Werror -Wall -Wextra  -g -fsanitize=thread
RM= rm -rf


all :$(NAME)

$(NAME): philo.h $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all