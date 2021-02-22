#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "get_next_line.h"
# include "op.h"

# define TABLE_SIZE 10000
# define HASH_MULT 37

extern unsigned long ml;
extern unsigned long fr;

# define FCNT(x) x; fr++
# define MFAIL(x) if (!x) err_exit(); else ml++;

# define NUM_OF_INSTR 16
# define C const char
# define INSTRS (C*[]){"live", "ld", "st", "add", "sub", "and", "or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi", "lfork", "aff"}
# define U size_t
# define NUM_ARGS ((U []){1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1})
# define SET_FIRST_ARG ((U []){2, 6, 1, 1, 1, 7, 7, 7, 2, 7, 1, 2, 6, 7, 2, 1})
# define SET_SECOND_ARG ((U []){0, 1, 5, 1, 1, 7, 7, 7, 0, 3, 7, 0, 1, 3, 0, 0})
# define SET_THIRD_ARG ((U []){0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 3, 0, 0, 1, 0, 0})
# define IS_CODE_TYPES ((U []){0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1})
# define T_DIR_SIZES ((U []){4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4})

typedef enum
{
	UNKNOWN,
	NAME,
	COMMENT,
	INSTRUCTION,
	STRING,
	LABEL,
	SEPARATOR,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	NEW_LINE,
	END
}	t_type_token;

typedef	struct	s_hash
{
  char			*node_name;
  size_t		value;
  struct s_hash	*next; // Тут хранятся коллизии хэш таблицы (Список)
  struct s_hash	*prev;
}				t_hash;

typedef struct	s_token
{
	char			*str;
	t_type_token	type_token;
	struct s_token	*next;
	struct s_token	*prev;
}				t_token;

typedef struct	s_arg_list
{
	size_t		num_args;
	size_t		num_bytes;
	t_token		*begin;
	t_token		*end;
}				t_arg_list;

typedef struct	s_instr
{
	char		*name_instr;
	size_t		num_args;
	size_t		set_first_arg;
	size_t		set_second_arg;
	size_t		set_third_arg;
	size_t		is_code_types_exist;
	size_t		size_t_dir;
}				t_instr;

typedef struct	s_instr_row
{
	t_instr				instr;
	t_arg_list			arg_list;
	size_t				num_bytes;
	struct s_instr_row	*next;
	struct s_instr_row	*prev;
}				t_instr_row;

typedef struct	s_instr_list
{
	size_t		num_instrs;
	size_t		num_bytes;
	t_instr_row	*begin;
	t_instr_row	*end;
}				t_instr_list;

typedef struct	s_token_list
{
  t_token	*begin;
  t_token	*end;
}				t_token_list;

typedef struct	s_asm
{
	char			*file_name_cor;
	header_t		header;
	size_t			set_header;
	t_token_list	token_list;
	t_hash			**h_table; // Указатель на хэш таблицу
	t_instr_list	instr_list;
}				t_asm;

/*
** -------------------------- check.c -----------------------------------------
*/

int				is_whitespace(char c);
size_t			skip_whitespaces(const char *line, size_t index);
int				check_args(int argc, char **argv);

/*
** -------------------------- error_manager.c ---------------------------------
*/

void			print_error_and_exit();
void			err_exit(void);

/*
** -------------------------- free.c ------------------------------------------
*/

void			free_token_list(t_token_list *token_list);

/*
** -------------------------- get_next_line.c ---------------------------------
*/

int				get_next_line(const int fd, char **line);

/*
** -------------------------- hash.c ------------------------------------------
*/

t_hash			**hash_table_init(void);
t_hash			*assign_to_table(t_hash **table, char *node_name);
void			free_hash_table(t_hash **h_table);
t_hash			*hash_query(t_hash **h_table, char *node_name);

/*
** -------------------------- inits.c -----------------------------------------
*/

void			init_token_list(t_token_list *token_list);
void			init_instr_row(t_instr_row *instr_row, char *str, size_t index);
void			init_asm(t_asm *asm_node);

/*
** -------------------------- parse_instr.c -----------------------------------
*/

t_token			*parse_instr_row(t_instr_row *instr_row, t_token *token);

/*
** -------------------------- label_handler.c ---------------------------------
*/

void			handler_label();

/*
** -------------------------- parse.c -----------------------------------------
*/

void			parse(t_token_list *token_list, char *file_name);

/*
** -------------------------- parse_custom.c ----------------------------------
*/

//void			parse_name_cmd_string(t_asm *asm_node, char *str_token);
//void			parse_comment_cmd_string(t_asm *asm_node, char *str_token);
//void			parse_instr(t_asm *asm_node, char *str_token);
//void			parse_arg(t_asm *asm_node, char *str_token);

/*
** -------------------------- parse_tokens.c ----------------------------------
*/

void			parse_tokens(t_asm *asm_node);

/*
** -------------------------- utils.c -----------------------------------------
*/

int				is_num_from_ind(const char *str, size_t	index);
int				is_label(const char *str, size_t len);
int				is_word_from_to(const char *str,
					size_t from_inclusive, size_t to_exclusive);
int				is_instr(const char *str);
char			*char_to_string(char c);
char			*type_to_string(t_type_token type);

/*
** -------------------------- debug.c -----------------------------------------
*/

void			print_token_list(t_token_list *token_list);

#endif
