VM_NAME = corewar

FLAGS = -Wall -g -Wextra -Werror

VM_SRC_DIR = ./vm_src/
VM_OBJ_DIR = ./vm_obj/
LIB_DIR = ./libft/

VM_SRC = $(addprefix $(VM_SRC_DIR),$(VM_SRC_NAMES))
VM_SRC_NAMES = clear_vm.c ft_lst_nocpy.c parse_champion.c main.c lst_functions.c \
		print_memory.c initialize_corewar.c initialize_cars.c op.c \
		introduce_champions.c corewar.c cw_helpers.c action.c \
		action2.c action_bitwise.c action_fork.c get_bits.c action_load.c \
		action_load_store_index.c get_debug_mode.c read_champ.c \
		attach_champ.c corewar_check.c visual.c rew.c car_chat.c \
		print_name_com_im.c other_viz.c
VM_OBJ = $(addprefix $(VM_OBJ_DIR),$(VM_OBJ_NAMES))
VM_OBJ_NAMES = $(VM_SRC_NAMES:.c=.o)

all: $(VM_NAME)

$(VM_NAME): $(VM_OBJ)
	make -C $(LIB_DIR)
	gcc $(FLAGS) -o $(VM_NAME) $(VM_OBJ) -L $(LIB_DIR) -lft -lncurses

$(VM_OBJ_DIR)%.o:$(VM_SRC_DIR)%.c
	@mkdir -p $(VM_OBJ_DIR)
	@gcc -I $(LIB_DIR) -o $@ -c $<

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(VM_OBJ_DIR)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(VM_NAME)

re: fclean all
