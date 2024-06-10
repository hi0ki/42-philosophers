FILES= philo_bonus.c ft_atoi_bonus.c utils_bonus.c fill_struct_bonus.c routine_bonus.c

OBJ= $(FILES:.c=.o)

NAME= philo_bonus
CC= cc -Werror -Wall -Wextra  #-g -fsanitize=thread
RM= rm -rf


all :$(NAME)

$(NAME): philo_bonus.h $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c philo.h
	$(CC) -c $< -o $@

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all