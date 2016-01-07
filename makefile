#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# The system flag determines what OS to compile for.
SYSTEM = __OUGI_WINDOWS__# __OUGI_MAC__ __OUGI_LINUX__

# searches these directories for cpp files when a source file is missing
vpath %.cpp ./Math/src ./Collections/src

# define the C compiler to use
CC = g++

# define any compile-time flags
# -02 for optimization!
CFLAGS = -std=c++11 -Wall -g -O2 -D $(SYSTEM)

# define the cpp source files
SRCS = main.cpp \
Functions.cpp \
Vector2.cpp \
Vector3.cpp \
Vector4.cpp \
Matrix2x2.cpp \
Matrix3x3.cpp \
Matrix4x4.cpp \
MathTester.cpp

# define the cpp object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .cpp of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.cpp=.o)

# define the executable file 
MAIN = tester

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:    $(MAIN) clean
	@echo  $(MAIN) has been successfully compiled!

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

# this is a suffix replacement rule for building .o's from .cpp's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .cpp file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
