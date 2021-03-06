# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =   -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g
# LDLIBS = -llab1
# LDFLAGS += -L.
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = test_tagremover date_test test_findprimes test_tostring

all: $(PROGS)

t1: test_tagremover
	./test_tagremover

t2: test_findprimes
	./test_findprimes

t3: date_test
	./date_test

t4: test_tostring
	./test_tostring

# Targets rely on implicit rules for compiling and linking
test_tagremover: tagremover.o test_tagremover.o
test_findprimes: findprimes.o
test_tostring: test_tostring.o date.o
date_test: date.o
# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS) *.enc *.dec *.d

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
