CXX= g++
SRC_DIR= src

CXXFLAGS= -std=c++14 -pedantic -Wextra -Wall -Werror -g3

SRC= main.cc particle.cc opti_func.cc function.cc swarm.cc
# SRC:= $(addprefix $(SRC_DIR)/, $(SRC))

OBJ= ${SRC:.cc=.o}

PROJECT=meta

all: $(PROJECT)

$(PROJECT): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@


clean:
	$(RM) $(OBJ) $(PROJECT)

.PHONY: clean
