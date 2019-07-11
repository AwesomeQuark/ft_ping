# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoelstudent.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 13:53:47 by conoel            #+#    #+#              #
#    Updated: 2019/04/22 08:31:40 by bghandou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#V3.0
################################### VARIABLES ##################################

NAME = haflib.a

HEADER_NAME = libft.h
HEADER_DIR = ./includes/
HEADER = ${addprefix $(HEADER_DIR), $(HEADER_NAME)}

SRCNAME = 			ft_bzero.c ft_memcpy.c ft_memccpy.c ft_iscntrl.c ft_isgraph.c \
					ft_memmove.c ft_memchr.c ft_memcmp.c ft_memdel.c ft_strlen.c \
					ft_strdup.c ft_strcpy.c ft_strncpy.c ft_islower.c ft_isupper.c \
					ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
					ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isspace.c ft_isalpha.c \
					ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strnew.c ft_strdel.c\
					ft_strclr.c ft_strsub.c \
					ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
					ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
					ft_putnbr_fd.c ft_isspace.c ft_isblank.c ft_memset.c quit.c ft_memdup.c divide.c\
					ft_strtoll.c get_the_file.c print_char_str.c free_tab.c print_int_str.c\
					garbage.c concat.c ft_atos.c ft_atoc.c\
					ft_printf.c get_args.c ft_size_flags.c additional_converters.c \
					ft_itoa_base_unsigned.c ft_itoa_base_signed.c ft_ptoa.c\
					ft_strcat2.c ft_atoi2.c ft_dprintf.c
SRCDIR = src/
SRCS = ${addprefix $(SRCDIR), $(SRCNAME)}

OBJNAME = $(SRCNAME:.c=.o)
OBJDIR = obj/
OBJ = ${addprefix $(OBJDIR), $(OBJNAME)}

PRINTF_NAME = printf.a
PRINTF_SRCNAME = 	ft_printf.c get_args.c ft_size_flags.c additional_converters.c \
					ft_ftoa.c ft_itoa_base_unsigned.c ft_itoa_base_signed.c ft_ptoa.c\
					ft_bzero.c ft_strcmp.c ft_strlen.c ft_strcat2.c ft_memset.c\
					ft_strdup.c ft_atoi2.c
PRINTF_OBJNAME = $(PRINTF_SRCNAME:.c=.o)
PRINTF_SRC = ${addprefix $(SRCDIR), $(PRINTF_SRCNAME)}
PRINTF_OBJ = ${addprefix $(OBJDIR), $(PRINTF_OBJNAME)}
PRINTF_HEADERNAME = ft_printf.h
PRINTF_HEADER = ${addprefix $(HEADER_DIR), $(PRINTF_HEADERNAME)}

FLAGS = -Wall -Wextra -Werror
CC = clang
DEPENDENCY = none

##################################### RULES #####################################

# GENERALS #

.PHONY: all clean fclean re printf

all: $(NAME)

printf: $(PRINTF_NAME)

clean :
	@rm -rf $(OBJDIR)

fclean :
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)
	@echo "\033[31m\033[1m\033[4mCleaning\033[0m\033[31m : Everything\033[0m [$(NAME)]";

re : fclean all

# COMPILATION #

$(NAME) : $(OBJDIR) $(OBJ) $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\n \033[1m\033[4m\033[35m\\^/ Done compiling \\^/\033[0m [$(NAME)] --> $(DEPENDENCY)"

$(PRINTF_NAME) : $(OBJDIR) $(PRINTF_OBJ) $(PRINTF_HEADER)
	@ar rc $(PRINTF_NAME) $(PRINTF_OBJ)
	@ranlib $(PRINTF_NAME)
	@echo "\n \033[1m\033[4m\033[35m\\^/ Done compiling \\^/\033[0m [$(PRINTF_NAME)] --> $(DEPENDENCY)"

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@clang $(FLAGS) -c $< -o $@ -I$(HEADER_DIR)
	@printf "\033[32m\033[1m\033[4mCompiling\033[0m\033[32m : %-30s\033[0m [$(NAME)]\n" $@

$(OBJDIR):
	@clear
	@mkdir $(OBJDIR)
	@echo "\n>=========== * \033[32m\033[1mCreating $(NAME) obj dir\033[0m * ===========<";

