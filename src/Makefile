CC=gcc
CFLAGS = -c -g -std=c11 -Wall -Werror -Wextra

PROGRAMM_NAME=3d_viewer

LIBS_CHECK =

OS := $(shell uname -s)

ifeq ($(OS), Linux)
	LINUX := $(shell cat /etc/os-release | grep ID_LIKE | sed 's|.*=||')

	ifeq ($(LINUX), fedora)
	LIBS_CHECK = -lm
	endif

	ifeq ($(LINUX), arch)
	LIBS_CHECK = -lm
	endif
	
	ifeq ($(LINUX), debian)
	LIBS_CHECK = -lm -pthread -lsubunit -lrt
	endif

endif

LIBS_TEST = -L. -l$(PROGRAMM_NAME) -lcheck $(LIBS_CHECK)

PATH_OBJ=obj
PATH_TESTS=tests
PATH_REPORT=report
PATH_3D_VIEWER_LIB=$(PROGRAMM_NAME)_lib
PATH_3D_VIEWER_v1.0=$(PROGRAMM_NAME)_v1.0

.PHONY: all install uninstall clean dvi dist test test_coverage gcov_report lcov_report make_$(PROGRAMM_NAME)_lib
all: install

install: lib$(PROGRAMM_NAME).a 
	qmake -makefile $(PATH_3D_VIEWER_v1.0)/$(PROGRAMM_NAME).pro -o $(PATH_3D_VIEWER_v1.0)/Makefile
	cd $(PATH_3D_VIEWER_v1.0); make;rm -rf tmp

uninstall:
	@rm -rf build/$(PROGRAMM_NAME)*

clean:
	@rm -rf $(PATH_OBJ)/*/*.o
	@rm -rf $(PATH_OBJ)/*/*.gcda $(PATH_OBJ)/*/*.gcno
	@rm -rf lib$(PROGRAMM_NAME).a
	@rm -rf $(PATH_TESTS)/test
	@rm -rf $(PATH_TESTS)/$(PATH_REPORT)/* $(PATH_TESTS)/report.info
	
	@rm -rf $(PATH_3D_VIEWER_v1.0)/.qmake.stash
	@rm -rf $(PATH_3D_VIEWER_v1.0)/tmp

dvi:
	doxygen ../dox/conf
	open ./../dox/html/index.html

dist:
	tar -cvf arhive.tar .

test: lib$(PROGRAMM_NAME).a $(wildcard $(PATH_TESTS)/*.h) $(patsubst %.c,%.o,$(wildcard $(PATH_TESTS)/*.c))
	$(CC) $(LFLAGS) $(PATH_OBJ)/$(PATH_TESTS)/*.o $(LIBS_TEST) -o $(PATH_TESTS)/test
	tests/test

gcov_report: test_coverage


lcov_report: gcov_report
	lcov -t "$(TESTS_PATH)" -o $(PATH_TESTS)/report.info -c -d .
	genhtml $(PATH_TESTS)/report.info -o $(PATH_TESTS)/$(PATH_REPORT)
	open $(PATH_TESTS)/$(PATH_REPORT)/index.html


test_coverage: 
	make test LIBS_TEST="$(LIBS_TEST) -lgcov" CFLAGS="$(CFLAGS) --coverage"

lib$(PROGRAMM_NAME).a : $(wildcard $(PATH_3D_VIEWER_LIB)/*.h) $(patsubst %.c,%.o,$(wildcard $(PATH_3D_VIEWER_LIB)/*.c))
	ar rc lib$(PROGRAMM_NAME).a $(PATH_OBJ)/$(PATH_3D_VIEWER_LIB)/*.o
	ranlib lib$(PROGRAMM_NAME).a

%.o : %.c
	@$(CC) $(CFLAGS) $< -o $(PATH_OBJ)/$@
