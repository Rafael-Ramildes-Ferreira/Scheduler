PROJECT_MAIN := Scheduler
CXX := g++

FLAGS := -I./inc/

SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.cpp)
INC := $(wildcard $(INC_DIR)/*.h)
OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(PROJECT_MAIN)

$(PROJECT_MAIN): $(OBJ)
	$(CXX) -o $@ $^

obj/%.o: $(SRC_DIR)/%.cpp $(INC) obj
	$(CXX) -o $@ -c $< $(FLAGS)

obj: 
	mkdir obj

clean:
	rm -rf obj
	rm Scheduler