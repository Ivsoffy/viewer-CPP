CC=g++ -g
FLAGS=-lgtest -lstdc++ -std=c++17
# WCHECK=-Werror -Wall -Wextra
NAME=3d_viewer_v2
BUILD_DIR=build
SOURCES=model/*.cc view/*.cpp controller/*.h
HEADERS=model/*.h view/*.h controller/*.h
# TEST_CC=tests/main_test.cc tests/model/model_test.cc model/figure.cc model/file_parser.cc
TEST_CC=tests/main_test.cc tests/model/model_test.cc model/figure.cc model/file_parser.cc model/affine_transformations.cc

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

# ----------------------------------------------------------
all: install

# install: clean
# 	mkdir -p $(BUILD_DIR)
# 	cd $(BUILD_DIR)/; qmake  ../view/$(NAME).pro
# 	cp config/settings.conf $(BUILD_DIR)
# 	make -C $(BUILD_DIR)
# 	# @rm -rf build/obj
# 	$(OPEN) build/3d_viewer_v2.0.app

install: clean
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR)/; qmake  ../view/$(NAME).pro
	cp config/settings.conf $(BUILD_DIR)
	make -C $(BUILD_DIR)/
	@rm -rf build/obj
	cd $(BUILD_DIR); $(OPEN) 3d_viewer_v2.app


uninstall:
	@rm -rf $(BUILD_DIR)/

# tests: model/figure.h
tests: $(TEST_CC)
	$(CC) $(TEST_CC) $(FLAGS) $(LIBS) $(WCHECK) -o test.out
# $(CC) tests/main_test.cc tests/model/model_test.cc model/figure.h $(FLAGS) $(LIBS) $(WCHECK) -o test.out
	./test.out

# tests: $(TEST_CC)  
# 	$(CC) $(TEST_CC) model/facade.cc controller/controller.cc controller/controller_dto.cc $(FLAGS) $(LIBS) $(WCHECK) -o test.out
# 	./test.out

dist:
	mkdir -p ./dist
	tar -cvzf ./dist/$(NAME).tgz Makefile model/* controller/* view/* config/* tests

dvi:
	doxygen ../dox/conf
	open ./../dox/html/index.html
	
# style:
# 	cp ../materials/linters/.clang-format .clang-format
# 	clang-format -i $(SOURCES) $(HEADERS)
# 	clang-format -n $(SOURCES) $(HEADERS)
# 	rm -rf .clang-format

cppcheck:
	cppcheck --enable=all --language=c++ --std=c++17 --suppress=unusedFunction --suppress=missingInclude $(SOURCES) $(HEADERS)

leaks: clean tests
	$(LEAKS)

clean:
	rm -rf ./report ./dist ./build
	rm -rf *.o *.out *.gcno *.gcda *.gcov *.info *.dSYM *.DS_Store ../.DS_Store .DS_Store
# rm -rf $(HOME)/settings.conf
