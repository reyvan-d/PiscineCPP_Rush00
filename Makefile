NAME = ft_retro
CFLAGS2 = 	-lncurses
CC = clang++
INCLUDES_PATH = includes/
SRCS_PATH = src/

SRCS_NAME = main.cpp \
			entities.class.cpp \
			player.class.cpp \
			enemy.class.cpp \
			window.class.cpp \
			engine.class.cpp \
			bullet.class.cpp \
			ammo.class.cpp  \
			score.class.cpp \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/

OBJS_NAME = $(SRCS_NAME:.cpp=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))
 
INCLUDES = -I includes/

HEADER = 	$(INCLUDES_PATH)retro.h		\

all: odir $(NAME)

$(NAME): $(OBJS)
	@clear
	@$(CC) $(CFLAGS2) -o $(NAME) $^ $(INCLUDES) -I$(INCLUDES_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.cpp
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< -I$(INCLUDES_PATH)

odir:
	@mkdir -p $(OBJS_PATH)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re odir