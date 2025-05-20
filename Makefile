NAME		= todo_list

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++11 -Iinc/ #I. flag -> include current directory

RM			= rm -f

ifdef DEBUG
	CXXFLAGS += -g -fsanitize=address
endif	

# --- Files ---
SRCS		= src/main.cpp \
			  src/handlers/handle_addTask.cpp \
			  src/Task.cpp \
			  src/utils.cpp

OBJS		= $(SRCS:.cpp=.o)

# --- Rules ---

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

debug:
	CXXFLAGS += -g -fsanitize=address
	$(CXX) $(CXXFLAGS) -O $(NAME) $(SRCS)

.PHONY: all clean fclean re debug

#.SILENT