NAME = spam
AUTEUR = "conoel"

SRC_NAME =	main.c\
			connect.c\
			loop.c\
			send.c\
			statistics.c\

SRC_DIR = ./sources/
SRC = ${addprefix $(SRC_DIR), $(SRC_NAME)}

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_DIR = ./objects/
OBJ = ${addprefix $(OBJ_DIR), $(OBJ_NAME)}

HEADER_DIR = ./includes/
HEADER_NAME =	spam.h\
	      		conf.h
HEADER = ${addprefix $(HEADER_DIR), $(HEADER_NAME)}

LIB_NAME = haflib.a
LIB_DIR = ./haflib/
LIB_HEADER = ./haflib/includes/
LIB = ${addprefix $(LIB_DIR), $(LIB_NAME)}

FLAGS = -Ofast
FLAGS += -Weverything
#FLAGS += -g3 -fsanitize=address
CC = clang

#################################################################################
##################################### RULES #####################################
#################################################################################

########## GENERALS ##########

.PHONY: all clean fclean re lre

all: $(LIB) $(OBJ_DIR) $(NAME)

re: fclean all

lre: clean all

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_DIR)

fclean:
	@make fclean -C $(LIB_DIR)
	@rm -rf $(OBJ_DIR) $(NAME)
	@echo "\033[31m\033[1m\033[4mCleaning\033[0m\033[31m : Everything\033[0m [$(NAME)]";

sclean: clean
	@rm -f $(NAME)

######### COMPILATION #########

$(NAME): ./auteur $(OBJ_DIR) $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME) -I$(HEADER_DIR) -I$(LIB_DIR)
	@echo "\033[31m### SPAM successfully compilated ###\033[0m"

$(OBJ_DIR):
	@clear
	@mkdir $(OBJ_DIR)
	@echo "\n>=========== * \033[32m\033[1mCreating $(NAME) obj dir\033[0m * ===========<";

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@$(CC) $(FLAGS) -c $< -o $@ -I$(HEADER_DIR) -I$(LIB_HEADER)
	@printf "\033[32m\033[1m\033[4mCompiling\033[0m\033[32m : %-30s \033[0m [$(NAME)]\n" $@

./auteur:
	@echo $(AUTEUR) > ./auteur
	@echo "\033[32m<Created Author file>\033[0m"

############# LIB #############

$(LIB):
	@make -C $(LIB_DIR)
