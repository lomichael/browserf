CC = g++
CCFLAGS = -Isrc -std=c++11 -Wall -Wextra
LDFLAGS = 

MAIN_SRC = $(filter-out src/main.cpp, $(wildcard src/*.cpp))
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)
MAIN_EXE = browserf

TEST_SRC = $(wildcard test/*.cpp)
TEST_EXE = $(TEST_SRC:.cpp=)

all: main test 

main: $(MAIN_EXE)

test: $(TEST_EXE)

$(MAIN_EXE): src/main.cpp $(MAIN_OBJ)
	$(CC) $(CCFLAGS) $(LDFLAGS) -o $@ $^

$(TEST_EXE): % : $(TEST_SRC) $(MAIN_OBJ)
	$(CC) $(CCFLAGS) $(LDFLAGS) -o $@ $(filter %$(basename $(notdir $@)).cpp, $(TEST_SRC)) $(MAIN_OBJ)

clean:
	rm -f src/*.o test/*.o $(MAIN_EXE) $(TEST_EXE)

.PHONY: all clean test
