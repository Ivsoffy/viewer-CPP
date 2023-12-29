CC=g++
PROGRAMM_NAME=3d_viewer_2
FLAGS=-std=c++17 -lgtest -lstdc++ 
# WCHECK=-Wall -Werror -Wextra
BUILD_DIR=build
# SOURCES=model/*.cc view/*.cc controller/*.cc
# HEADERS=model/*.h view/*.h controller/*.h
SOURCES=model/*.cc
HEADERS=model/*.h
OBJECT_FOLDER=obj

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

#######################################################################
## working one
#######################################################################
test.o: tests/main_test.cc tests/*/*.cc
	$(CC) $(FLAGS) -c tests/main_test.cc tests/*/*.cc

tests: test.o
	$(CC) $(SOURCES) *.o $(FLAGS) $(LIBS) $(WCHECK) -o test.out
	./test.out
#######################################################################

#######################################################################	

clean:
	rm *.o test.out

##############################################################################################################################################
##############################################################################################################################################
##############################################################################################################################################
##############################################################################################################################################
# LDLIBS = -lgtest -pthread

# PATH_OBJ=obj
# PATH_TESTS=tests

# HEADERS_LIB = $(wildcard model/*.h) $(wildcard tests/model/*.h)
# HEADERS_TEST = $(wildcard $(PATH_TESTS)/model/*.h)
# CXXFILES_TEST = $(wildcard $(PATH_TESTS)/model/*.cc)

# CXXOBJECTS_TEST = $(addprefix $(PATH_OBJ)/, $(patsubst %.cc,%.o,$(CXXFILES_TEST)))

# CXXOBJECTS = $(CXXOBJECTS_TEST)

# test: $(HEADERS_TEST) $(CXXOBJECTS_TEST)
# 	$(CC) $(CXXOBJECTS_TEST) $(LDLIBS) -o $(PATH_TESTS)/test
# 	tests/test

# $(CXXOBJECTS): $(PATH_OBJ)/%.o: %.cc $(HEADERS_LIB)
# 	$(CC) $(FLAGS) -c $< -o $@
##############################################################################################################################################
##############################################################################################################################################
##############################################################################################################################################

# test.o: tests/*.cc tests/model/*.cc
# 	$(CC) $(FLAGS) -o $(OBJECT_FOLDER)/test.o - c tests/*.cc tests/model/*.cc

# # test.o: tests/*.cc tests/model/*.cc
# # 	$(CC) $(FLAGS) -o $(OBJECT_FOLDER)/test.o -c tests/model/*.cc

# tests: test.o
# 	$(CC) $(SOURCES) *.o $(FLAGS) $(LIBS) $(WCHECK) -o test.out
# 	./test.out



# tests: s21_viewer.a
# 	$(CC) tests/main_test.cc tests/model/model_test.cc s21_viewer.a $(FLAGS) $(LIBS) $(WCHECK) -o test.out
# 	./test.out
# 	# rm *.o *.a

# s21_viewer.a: build_s21_viewer

# build_s21_viewer:
# 	$(CC) -c $(SOURCES)
# 	ar rcs s21_viewer.a *.o
# 	ranlib s21_viewer.a

# test: clean smart_calc.a test.o
# 	$(CXX) $(CXXFLAGS) smart_calc.a *.o -o $(PATH_TESTS)/test $(LDLIBS)
# 	$(PATH_TESTS)/test
# 	@rm -rf *.o

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

# clean:
# 	rm -rf ./report ./dist ./build
# 	rm -rf *.o *.out *.gcno *.gcda *.gcov *.info *.dSYM *.DS_Store ../.DS_Store .DS_Store
# 	rm -rf $(HOME)/settings.conf

1:	
	rm model/a.out
	g++ model/main.cc model/FileParser.cc model/Figure.cc -o model/a.out
	model/a.out