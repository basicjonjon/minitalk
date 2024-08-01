# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 15:15:00 by jle-doua          #+#    #+#              #
#    Updated: 2024/07/31 17:12:31 by jle-doua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

MEM = 	ft_memset \
		ft_memcpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp

PUT =	ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putstr \
		ft_putnbr \
		ft_putunsigned \
		ft_putnbrbase \
		ft_putchar \
		ft_putadresse

STR	=	ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_strdup \
		ft_strjoin \
		ft_straddchar \
		ft_strtrim \
		ft_strmapi \
		ft_striteri

PRINTF = ft_printf

IS = 	ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint

TO = 	ft_toupper \
		ft_tolower

OTHER = ft_bzero \
		ft_atoi \
		ft_calloc \
		ft_substr \
		ft_split \
		ft_itoa \
		ft_itoa_base

LST = 	ft_lstnew \
	  	ft_lstadd_front \
	  	ft_lstsize \
	  	ft_lstlast \
	  	ft_lstadd_back \
	  	ft_lstdelone \
	  	ft_lstclear \
	  	ft_lstiter \
	  	ft_lstmap

OBJS_DIR 	= ./objet/
MEM_DIR 	= ./ft_mem/
PUT_DIR 	= ./ft_put/
STR_DIR 	= ./ft_str/
PRINTF_DIR 	= ./ft_printf/
IS_DIR 		= ./ft_is/
TO_DIR 		= ./ft_to/
OTHER_DIR 	= ./ft_other/
LST_DIR 	= ./ft_lst/

MEM_C	 = $(addprefix $(MEM_DIR), $(addsuffix .c, $(MEM)))
PUT_C	 = $(addprefix $(PUT_DIR), $(addsuffix .c, $(PUT)))
STRS_C	 = $(addprefix $(STR_DIR), $(addsuffix .c, $(STR)))
PRINTF_C = $(addprefix $(PRINTF_DIR), $(addsuffix .c, $(PRINTF)))
IS_C	 = $(addprefix $(IS_DIR), $(addsuffix .c, $(IS)))
TO_C	 = $(addprefix $(TO_DIR), $(addsuffix .c, $(TO)))
OTHER_C	 = $(addprefix $(OTHER_DIR), $(addsuffix .c, $(OTHER)))
LST_C	 = $(addprefix $(LST_DIR), $(addsuffix .c, $(LST)))

MEM_O	 = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(MEM)))
PUT_O	 = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(PUT)))
STRS_O	 = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(STR)))
PRINTF_O = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(PRINTF)))
IS_O	 = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(IS)))
TO_O	 = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(TO)))
OTHER_O	 = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(OTHER)))
LST_O	 = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(LST)))

OBJS = $(MEM_O) $(PUT_O) $(STRS_O) $(PRINTF_O) $(IS_O) $(TO_O) $(OTHER_O) $(LST_O)

$(OBJS_DIR)%.o: $(MEM_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)%.o: $(PUT_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)%.o: $(STR_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)%.o: $(PRINTF_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)%.o: $(IS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)%.o: $(TO_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)%.o: $(OTHER_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OBJS_DIR)%.o: $(LST_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
