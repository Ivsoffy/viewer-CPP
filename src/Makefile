CC=g++ -g
PROGRAMM_NAME=3d_viewer_2
FLAGS=-std=c++17 -lgtest -lstdc++ 
WCHECK=-Wall -Werror -Wextra
BUILD_DIR=build
SOURCES=model/*.cc view/*.cc controller/*.cc
HEADERS=model/*.h view/*.h controller/*.h

OS=$(shell uname)
ifeq ($(OS), Linux)
	APP_NAME=$(PROGRAMM_NAME)
	LIBS=-lcheck -lpthread -lrt -lm -lsubunit
	LEAKS=CK_FORK=no valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./test.out
	OPEN=xdg-open
else
	APP_NAME=$(PROGRAMM_NAME).app
	LIBS=-lcheck -lgtest -pthread
	LEAKS=leaks --atExit -- ./test.out
	OPEN=open
endif

all: install

install: clean
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR)/; qmake ../view/$(PROGRAMM_NAME).pro
	cp conf/settings.conf $(BUILD_DIR)
	make -C $(BUILD_DIR)
	rm $(BUILD_DIR)/*.o

uninstall:
	rm -rf $(PROGRAMM_NAME)

# tests:
# 	$(CC) test/test.cc $(FLAGS) $(LIBS) $(WCHECK) -o test.out
# 	./test.out

# dist:
# 	mkdir -p ./dist
# 	tar -cvzf ./dist/$(PROGRAMM_NAME).tgz Makefile model/* config/* controller/* view/* test/* object/* *.html

# dvi:
# 	$(OPEN) text.html
	
# style:
# 	cp ../materials/linters/.clang-format .clang-format
# 	clang-format -i $(SOURCES) $(HEADERS)
# 	clang-format -n $(SOURCES) $(HEADERS)
# 	rm -rf .clang-format

# cppcheck:
# 	cppcheck --enable=all --language=c++ --std=c++17 --suppress=unusedFunction --suppress=missingInclude $(SOURCES) $(HEADERS)

# leaks: clean tests
# 	valgrind -s --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./test.out

clean:
	rm -rf ./report ./dist ./build
	rm -rf *.o *.out *.gcno *.gcda *.gcov *.info *.dSYM *.DS_Store ../.DS_Store .DS_Store
	rm -rf $(HOME)/settings.conf

1:	
	# rm model/a.out
	g++ model/main.cc model/FileParser.cc model/Figure.cc -o model/a.out
	model/a.out