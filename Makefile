GXX = g++ --std=c++14
INCLUDE = -Iinclude
FLAGS = -Wall -Wextra -pedantic

REPONAME = dsc
LIB_NAME = build/$(REPO_NAME).so

INC = $(shell find include -type f -name '*.hpp')
SRC = $(shell find src -type f -name '*.cpp')
OBJ = $(patsubst src/%.c, build/obj/%.o, $(SRC))

TEST_SRC = $(shell find test/ -type f -name '*.cpp' ! -path 'test/main.cpp')
TEST_OBJ = $(patsubst test/%.cpp, build/test_obj/%.o, $(TEST_SRC))
TEST_BIN = $(patsubst test/%.cpp, build/test_bin/%, $(TEST_SRC))

EXAMPLES_SRC = $(shell find examples -type f -name '*.cpp')
EXAMPLES_BIN = $(patsubst examples/%.c, build/examples/%, $(EXAMPLES_SRC))

.PHONY: display loc clear external test
.PRECIOUS: $(TEST_OBJ)

all: $(OBJ) $(EXAMPLES_BIN) $(TEST_BIN)

test: $(TEST_BIN)
	@python run_tests.py
    
build/obj/%.o: src/%.cpp
	@mkdir -p "$(@D)"
	@echo Compiling "$<"...
	@$(GXX) $(INCLUDE) -c "$<" -o "$@" $(FLAGS)

build/examples/%: examples/%.cpp $(OBJ)
	@mkdir -p "$(@D)"
	@echo Compiling "$<"...
	@$(GXX) $(INCLUDE) $(OBJ) "$<" -o "$@" $(FLAGS)

build/test_obj/%.o: test/%.cpp
	@mkdir -p "$(@D)"
	@echo Compiling "$<"...
	@$(GXX) $(INCLUDE) -c "$<" -o "$@" $(FLAGS)

build/test_bin/%: build/test_obj/%.o $(OBJ)
	@mkdir -p "$(@D)"
	@echo Compiling "$<"...
	@$(GXX) $(INCLUDE) $(OBJ) "$<" -o "$@" $(FLAGS)

loc: 
	@find . -type f \( -iname \*.cpp -o -iname \*.hpp \) -exec wc -l {} +

clear:
	@rm -rf build

display:
	@echo INC=$(INC)
	@echo SRC=$(SRC)
	@echo OBJ=$(OBJ)
	@echo TEST_SRC=$(TEST_SRC)
	@echo TEST_OBJ=$(TEST_OBJ)
	@echo TEST_BIN=$(TEST_BIN)
	@echo EXAMPLES_SRC=$(EXAMPLES_SRC)
	@echo EXAMPLES_BIN=$(EXAMPLES_BIN)
	@echo LIB_NAME=$(LIB_NAME)


