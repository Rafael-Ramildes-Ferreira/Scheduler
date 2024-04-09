PROJECT_MAIN := Scheduler
CXX := g++

SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.cpp)
INC := $(wildcard $(INC_DIR)/*.h)
OBJ := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

all: $(PROJECT_MAIN)

$(PROJECT_MAIN): $(OBJ)
	echo $(SRC)
	$(CXX) -o $@ $^

obj/%.o: $(SRC) $(INC) obj
	$(CXX) -o $@ -c $<

obj: 
	mkdir obj

clean:
	rm -rf obj
	rm Scheduler