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
PROGS = simplebitsettest bitsettest1 bitsettest2

all: $(PROGS)

t1: simplebitsettest
	./simplebitsettest

t2: bitsettest1
	./bitsettest1

t3: bitsettest2
	./bitsettest2

t4: bitsettest1 bitsettest2
	./bitsettest1 && ./bitsettest2
# Targets rely on implicit rules for compiling and linking
simplebitsettest: simplebitset.o
bitsettest1: bitset.o bitreference.o
bitsettest2: bitset.o bitreference.o
nstime: vns.o mns.o umns.o hns.o
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
