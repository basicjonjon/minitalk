NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SERVEUR_FILE = serveur
CLIENT_FILE = client

# ALGO_FILE = random

# All directories
SERVEUR_DIR = ./serveur/
CLIENT_DIR = ./client/
OBJS_DIR = ./objet/
LIBFT_PATH = ./libft

# Create the full names of the files (path + name + extension)
CLIENT = $(addprefix $(CLIENT_DIR), $(addsuffix .c, $(CLIENT_FILE)))
SERVEUR = $(addprefix $(SERVEUR_DIR), $(addsuffix .c, $(SERVEUR_FILE)))

# Create the full names of the objects (path + name + extension)
CLIENT_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(CLIENT_FILE)))
SERVEUR_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SERVEUR_FILE)))

GREEN = \033[1;32m
BLUE = \033[1;34m
RED = \033[1;31m
NC = \033[0m

LIBFT = $(LIBFT_PATH)/libft.a

$(OBJS_DIR)%.o: $(SERVEUR_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(OBJS_DIR)%.o: $(CLIENT_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(LIBFT) $(CLIENT_OBJ) $(SERVEUR_OBJ)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(CLIENT_DIR)$(CLIENT_FILE)
	@$(CC) $(CFLAGS) $(SERVEUR_OBJ) $(LIBFT) -o $(SERVEUR_DIR)$(SERVEUR_FILE)
	@echo "$@ : $(BLUE)[READY]$(NC)"
	@echo "\n$(BLUE)============ [ serveur START ] ============$(NC)\n"
	@./serveur/serveur


$(LIBFT):
	@make -C $(LIBFT_PATH) all
	@clear
	@echo "libft : $(GREEN)[OK]$(NC)"

all: $(NAME)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@make clean -C $(LIBFT_PATH)
	clear
	@echo "$(RED)============== [OBJECT DELETED] ==============$(NC)"

fclean: clean
	@$(RM) $(CLIENT_DIR)$(CLIENT_FILE) $(SERVEUR_DIR)$(SERVEUR_FILE)
	@make fclean -C $(LIBFT_PATH)
	clear
	@echo "$(RED)========== [ OBJECT / EX DELETED ] ==========$(NC)"

re: fclean all

.PHONY: all clean fclean re
