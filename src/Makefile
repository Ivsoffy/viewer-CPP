CC=g++ -g
FLAGS=-lgtest -lstdc++ -std=c++17
WCHECK=-Werror -Wall -Wextra
NAME=3d_viewer_v2
BUILD_DIR=build
SOURCES=model/*.cc view/*.cpp controller/*.cc dto/*.cc
HEADERS=model/*.h view/*.h controller/*.h dto/*.h
TEST_CC=tests/main_test.cc tests/model/model_test.cc model/figure.cc model/file_parser.cc model/affine_transformations.cc dto/dto.cc

OS=$(shell uname)
ifeq ($(OS), Linux)
APP=$(NAME)
LIBS=-lcheck -lpthread -lrt -lm -lsubunit
LEAKS=valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./test.out
OPEN=xdg-open
else
APP=$(NAME).app
LIBS=-lcheck -lgtest -pthread
LEAKS=leaks --atExit -- ./test.out
OPEN=open
endif

all: install

install: clean
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR)/; qmake ../view/$(NAME).pro
	make -C $(BUILD_DIR)/
	@rm -rf build/obj

open:
	$(OPEN) build/3d_viewer_v2.app

uninstall:
	@rm -rf $(BUILD_DIR)/

tests: clean_for_tests $(TEST_CC)
	$(CC) $(TEST_CC) $(FLAGS) $(LIBS) $(WCHECK) -o test.out
	./test.out

dist:
	mkdir -p ./dist
	tar -cvzf ./dist/$(NAME).tgz Makefile model controller view dto tests dox images

dvi:
	doxygen dox/conf
	open ./dox/html/index.html
	
clang-format-n:
	clang-format -style=Google -n $(SOURCES) $(HEADERS)
clang-format-i:
	clang-format -style=Google -i $(SOURCES) $(HEADERS)

cppcheck:
	cppcheck --enable=all --language=c++ --std=c++17 --suppress=unusedFunction --suppress=missingInclude $(SOURCES) $(HEADERS)

leaks: tests
	$(LEAKS)

clean_for_tests:
	@rm -rf *.o *.out *.info *.dSYM

clean:
	@rm -rf ./report ./dist ./build
	@rm -rf *.gcno *.gcda *.gcov *.info
	@rm -rf dox/html
