#ifndef JSMN_H
# define JSMN_H
# include <stddef.h>
# define JSMN_API extern

typedef enum e_jsmntype {
	JSMN_UNDEFINED = 0,
	JSMN_OBJECT = 1,
	JSMN_ARRAY = 2,
	JSMN_STRING = 3,
	JSMN_PRIMITIVE = 4
}	t_jsmntype;

enum e_jsmnerr {
	JSMN_ERROR_NOMEM = -1,
	JSMN_ERROR_INVAL = -2,
	JSMN_ERROR_PART = -3
};

typedef struct s_jsmntok {
	t_jsmntype	type;
	int			start;
	int			end;
	int			size;
}				t_jsmntok;
typedef struct s_jsmn_parser {
	unsigned int	pos;
	unsigned int	toknext;
	int				toksuper;
}					t_jsmn_parser;

void	jsmn_init(t_jsmn_parser *parser);
int		jsmn_parse(t_jsmn_parser *parser, const char *js,
			t_jsmntok *tokens, const unsigned int num_tokens);

#endif
