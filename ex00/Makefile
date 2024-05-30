CXX=c++
CXXFLAGS=-std=c++98 -Wall -Wextra -Werror
SRCDIR=srcs
OBJDIR=obj
SRCS=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
	TARGET=btc

GREEN = \033[38;2;4;231;98m
BLUE = \033[38;2;119;166;182m
RED = \033[0;31m
RESET = \033[0m

all: $(TARGET)

$(TARGET): $(OBJS)
	@printf "$(GREEN)Linking...$(RESET)\n"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)
	@printf "$(GREEN)Compilation successful!$(RESET)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@printf "$(BLUE)Compiling $<...$(RESET)\n"
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "$(GREEN)Compiled $< successfully!$(RESET)\n"

clean:
	@printf "$(RED)Cleaning up object files...$(RESET)\n"
	@rm -frd obj
	@printf "$(RED)Cleaned.$(RESET)\n"

fclean: clean
	@printf "$(RED)Removing executable $(TARGET)...$(RESET)\n"
	@rm -f $(TARGET)
	@printf "$(RED)Removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re

