SRCS		 =	ft_memset.c\
				ft_bzero.c\
				ft_memcpy.c\
				ft_memccpy.c\
				ft_memmove.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_calloc.c\
				ft_isprint.c\
				ft_strdup.c\
				ft_strncmp.c\
				ft_tolower.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_strlcat.c\
				ft_strnstr.c\
				ft_toupper.c\
				ft_atoi.c\
				ft_isascii.c\
				ft_strlcpy.c\
				ft_strrchr.c\
				ft_isdigit.c\
				ft_strchr.c\
				ft_strlen.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_split.c\
				ft_itoa.c\

NAME		= libft.a

OBJS		= ${SRCS:.c=.o}

OBJB		= ${SRCB:.c=.o}

CFLAGS		= -Wall -Wextra -Werror

.c.o:	
			cc ${CFLAGS} -c $< -o ${<:.c=.o}


${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:		
			rm -f ${OBJS} ${OBJB}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

bonus:		${OBJS} ${OBJB}
			ar rc ${NAME} ${OBJS} ${OBJB}

.PHONY:		clean fclean all re