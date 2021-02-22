NAME = libft.a

CYAN_CLR = \x1b[36m
GRN_CLR  = \x1b[32m
NO_CLR	 = \x1b[00m
WRN_CLR	 = \x1b[31m

SRC = ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_wordcnt.c\
		ft_sort.c\
		ft_sqrt.c\
		ft_range.c\
		ft_recursive_factorial.c\
		get_next_line.c

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = -I .

all: $(NAME)

$(NAME): $(HEADER) $(OBJ_DIR) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "$(NO_CLR)$(NAME) compilation $(GRN_CLR)SUCCESS!$(NO_CLR)\n"

$(OBJ_DIR):
	@mkdir obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)*
	@printf "$(GRN_CLR)LIBFT $(NO_CLR)object files have been $(WRN_CLR)Removed!\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(NO_CLR)$(NAME) have been $(WRN_CLR)Removed!\n"

re: fclean all

.PHONY: all clean fclean re header
