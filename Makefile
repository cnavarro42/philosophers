NAME =		philo

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror -pthread -o3 -g3 #-fsanitize=address

RM =		rm -rf

SRCS_C =	../philosophers.c parse.c routine.c filling.c utils.c utils2.c utils3.c

SRCS =		$(addprefix srcs/, $(SRCS_C))

OBJS =		$(SRCS:.c=.o)

INCLUDES =	headers

all: $(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJS) -o $(NAME)
%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ -c $<
clean:
	@$(RM) $(OBJS)
fclean:
	@$(RM) $(OBJS) $(NAME)
re:		fclean all

.PHONY:	all clean fclean re