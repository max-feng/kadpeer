#CC=i686-redhat-linux-gcc
#CXX=i686-redhat-linux-g++
CC=gcc
CXX=g++
debug=yes
ifeq ($(debug),yes)
CFLAGES= -g3 -Wno-deprecated
INCDIR= -I./include/\
	-I./include/common
LIBS= 
else 
INCDIR= -I/usr/include/mysql++ \
	-I/usr/include/mysql \
	-Ilib\
	-I./include\
	-I./include/common
CFLAGES=-g -O  $(shell mysql_config --cflags) 
LIBS=-lmysqlpp -lmysqlclient $(shell mysql_config --libs_r)
endif
SRC=$(shell ls ./src/*.cpp)
OBJ=$(SRC:.cpp=.o)
Target=kadpeer
all:clean $(Target)
$(Target):$(OBJ)
	$(CXX) $(CFLAGES) $(INCDIR) -o $(Target) $^ $(LIBS)
%.o:%.cpp
	$(CXX) $(CFLAGES) $(INCDIR) -c $< -o $@ $(LIBS) 
%.o:%.cc
	$(CXX) $(CFLAGES) -c $< -o $@ $(LIBS) 
%.o:%.c
	$(CC) $(CFLAGES) -c $< -o $@ $(LIBS)
clean:
	@cd src; rm -rf *.o	
	@ rm -f $(Target)
