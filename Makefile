SRCS		= 	ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJS		=	${SRCS:.s=.o}

NAME		=	libasm.a

BONUS		=	ft_list_size.s ft_list_push_front.s

BONOBJS		=	${BONUS:.s=.o}

# INCLUDE		=	libasm.h

RM			=	rm -f

AR			=	ar rc

CFLAGS		=	-f macho64

.s.o: 		${OBJS}
			nasm ${CFLAGS} $<

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

bonus:		${BONOBJS} ${OBJS}
			${AR} ${NAME} ${OBJS} ${BONOBJS} 
			ranlib ${NAME}

clean:
			${RM} ${OBJS} ${BONOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re
