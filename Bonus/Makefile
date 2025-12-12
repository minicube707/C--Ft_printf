# =======================================
#            MAKEFILE PROJET
# =======================================

# =======================================
#                FLAGS
# =======================================
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -g 

# =======================================
#              FILE
# =======================================
FILE_NAMES = 	ft_printf \
				get_flags \
				mini_libft \
				manage_string \
				printchar \
				printstring \
				printmemory \
				printhexadecimal \
				printinteger \
				printunsignedinteger \

# =======================================
#              VARIABLE
# =======================================	
SRC_PATH = src
OBJ_PATH = obj
HEA_PATH = include

SRC_FILES = $(FILE_NAMES:%=$(SRC_PATH)/%.c)
OBJ_FILES = $(FILE_NAMES:%=$(OBJ_PATH)/%.o)
DEP_FILES = $(OBJ_FILES:.o=.d)
HEA_FILES = $(HEA_PATH)/ft_printf.h

INCLUDE = -I $(HEA_PATH)

NAME = libftprintf.a	

# =======================================
#              RULES
# =======================================
all: $(NAME)

bonus: all

.PHONY: all clean fclean re bonus

$(OBJ_PATH) :
	mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ_FILES)
	@ar rcs $(NAME) $(OBJ_FILES)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEA_FILES) | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INCLUDE)	-c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(DEP_FILES)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Inclusion automatique des fichiers .d s’ils existent
-include $(DEP_FILES)
