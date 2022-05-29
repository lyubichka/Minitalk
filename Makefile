# ------------------------------ Sources ------------------------------

# Files
SERVER		=	server.c

CLIENT		=	client.c

SERVER_B	=	server_bonus.c

CLIENT_B	=	client_bonus.c

LIBFT		=	cd libft && make

LIB			=	libft/libft.a

# Sources and objects
SERVER_SRC	=	$(SERVER)

SERVER_OBJS	=	$(SERVER_SRC:.c=.o)

CLIENT_SRC	=	$(CLIENT)

CLIENT_OBJS	=	$(CLIENT_SRC:.c=.o)

OBJS		=	$(CLIENT_OBJS) \
				$(SERVER_OBJS)

# Sources and objects bonus
SERVER_SRC_B	=	$(SERVER_B)

SERVER_OBJS_B	=	$(SERVER_SRC_B:.c=.o)

CLIENT_SRC_B	=	$(CLIENT_B)

CLIENT_OBJS_B	=	$(CLIENT_SRC_B:.c=.o)

OBJS_B		=	$(CLIENT_OBJS_B) \
				$(SERVER_OBJS_B)

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

INCLUDE		=	-I include

SERVER_NAME	=	server

CLIENT_NAME	=	client

SERVER_NAME_B	=	server_bonus

CLIENT_NAME_B	=	client_bonus

NAME		=	server

# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME): comp_start ft_server ft_client

b: comp_start ft_server_b ft_client_b

comp_start:
	@$(LIBFT)

ft_server: $(SERVER_OBJS)
	@$(GCC) $(FLAGS) $(SERVER_OBJS) $(LIB) -o $(SERVER_NAME)

ft_client: $(CLIENT_OBJS)
	@$(GCC) $(FLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT_NAME)

ft_server_b: $(SERVER_OBJS_B)
	@$(GCC) $(FLAGS) $(SERVER_OBJS_B) $(LIB) -o $(SERVER_NAME_B)

ft_client_b: $(CLIENT_OBJS_B)
	@$(GCC) $(FLAGS) $(CLIENT_OBJS_B) $(LIB) -o $(CLIENT_NAME_B)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_B)
	@cd libft && make clean

fclean: clean
	@rm -rf $(SERVER_NAME) $(CLIENT_NAME)
	@rm -rf $(SERVER_NAME_B) $(CLIENT_NAME_B)
	@cd libft && make fclean

.c.o:
	@${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re:	fclean all
