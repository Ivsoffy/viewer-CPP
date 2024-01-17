# CC=g++ -g
# PROGRAMM_NAME=3d_viewer
# FLAGS=-std=c++17 -lgtest -lstdc++ 
# # WCHECK=-Wall -Werror -Wextra
# BUILD_DIR=build
# SOURCES=model/*.cc view/*.cpp controller/*.cc
# HEADERS=model/*.h view/*.h controller/*.h
# # SOURCES=model/*.cc
# # HEADERS=model/*.h
# OBJECT_FOLDER=obj

# OS=$(shell uname)
# ifeq ($(OS), Linux)
# 	LINUX := $(shell cat /etc/os-release | grep ID_LIKE | sed 's|.*=||')

# 	ifeq ($(LINUX), fedora)
# 	LIBS_CHECK = -lm
# 	endif

# 	ifeq ($(LINUX), arch)
# 	LIBS_CHECK = -lm
# 	endif
	
# 	ifeq ($(LINUX), debian)
# 	LIBS_CHECK = -lm -pthread -lsubunit -lrt
# 	endif

# endif

# LIBS_TEST = -L. -l$(PROGRAMM_NAME) -lcheck $(LIBS_CHECK)

# PATH_OBJ=obj
# PATH_TESTS=tests
# PATH_REPORT=report
# PATH_3D_VIEWER_LIB=$(PROGRAMM_NAME)_lib
# PATH_3D_VIEWER_v2.0=$(PROGRAMM_NAME)_v2.0

# .PHONY: all install uninstall clean dvi dist test test_coverage gcov_report lcov_report make_$(PROGRAMM_NAME)_lib
# all: install

# install: lib$(PROGRAMM_NAME).a 
# 	qmake -makefile $(PATH_3D_VIEWER_v2.0)/$(PROGRAMM_NAME).pro -o $(PATH_3D_VIEWER_v2.0)/Makefile
# 	cd $(PATH_3D_VIEWER_v2.0); make;rm -rf tmp

# uninstall:
# 	@rm -rf build/$(PROGRAMM_NAME)*

# clean:
# 	@rm -rf $(PATH_OBJ)/*/*.o
# 	@rm -rf $(PATH_OBJ)/*/*.gcda $(PATH_OBJ)/*/*.gcno
# 	@rm -rf lib$(PROGRAMM_NAME).a
# 	@rm -rf $(PATH_TESTS)/test
# 	@rm -rf $(PATH_TESTS)/$(PATH_REPORT)/* $(PATH_TESTS)/report.info
	
# 	@rm -rf $(PATH_3D_VIEWER_v2.0)/.qmake.stash
# 	@rm -rf $(PATH_3D_VIEWER_v2.0)/tmp

# # dvi:
# # 	doxygen ../dox/conf
# # 	open ./../dox/html/index.html

# # dist:
# # 	tar -cvf arhive.tar .

# # test: lib$(PROGRAMM_NAME).a $(wildcard $(PATH_TESTS)/*.h) $(patsubst %.c,%.o,$(wildcard $(PATH_TESTS)/*.c))
# # 	$(CC) $(LFLAGS) $(PATH_OBJ)/$(PATH_TESTS)/*.o $(LIBS_TEST) -o $(PATH_TESTS)/test
# # 	tests/test

# # gcov_report: test_coverage


# # lcov_report: gcov_report
# # 	lcov -t "$(TESTS_PATH)" -o $(PATH_TESTS)/report.info -c -d .
# # 	genhtml $(PATH_TESTS)/report.info -o $(PATH_TESTS)/$(PATH_REPORT)
# # 	open $(PATH_TESTS)/$(PATH_REPORT)/index.html


# # test_coverage: 
# # 	make test LIBS_TEST="$(LIBS_TEST) -lgcov" CFLAGS="$(CFLAGS) --coverage"

# lib$(PROGRAMM_NAME).a : $(wildcard $(PATH_3D_VIEWER_LIB)/*.h) $(patsubst %.c,%.o,$(wildcard $(PATH_3D_VIEWER_LIB)/*.c))
# 	ar rc lib$(PROGRAMM_NAME).a $(PATH_OBJ)/$(PATH_3D_VIEWER_LIB)/*.o
# 	ranlib lib$(PROGRAMM_NAME).a

# %.o : %.c
# 	@$(CC) $(CFLAGS) $< -o $(PATH_OBJ)/$@

###############################################################################
###############################################################################
###############################################################################
###############################################################################
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
