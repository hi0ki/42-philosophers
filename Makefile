FILES= philo.c ft_atoi.c utils.c fill_struct.c routine.c

NAME= philo
CC= cc -Werror -Wall -Wextra # -g -fsanitize=thread
RM= rm -rf

all :$(NAME)

$(NAME): philo.h $(FILES)
	$(CC) $(FILES) -o $(NAME)

%.o: %.c philo.h
	$(CC) -c $< -o $@

fclean:
	$(RM) $(NAME)

re: fclean all