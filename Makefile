NAME = game

INC = inc/

SRC = src/main.cpp src/Player.cpp 

BUILD_DIR = .build
OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)
DEP = $(OBJ:%.o=%.d)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++20 -fsanitize=address
LDFLAGS = -lraylib -lm -lpthread -ldl -lrt -lX11

RM = rm -rf
DIR_DUP = mkdir -p $(@D)

all: $(NAME)

$(BUILD_DIR)/%.o: %.cpp Makefile
	$(DIR_DUP)
	$(CC) $(CFLAGS) -I $(INC) -MMD -MP -c $< -o $@
	@echo "Created $@"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)
	@echo "Created $(NAME)"

-include $(DEP)

clean:
	$(RM) $(BUILD_DIR)
	@echo "Cleaned up"

fclean: clean
	$(RM) $(NAME)
	@echo "Target deleted"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
