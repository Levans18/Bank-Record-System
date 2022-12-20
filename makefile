CC := g++
CFLAGS := -std=c++17
TARGET := exe

SRCS := Main.cpp
OBJS := Main.o

#Compile the code
all:
	@$(CC) $(CFLAGS) -o $(TARGET) *.cpp

#Remove the executable files
clean:
	@rm -rf exe

#Run the program
run:
	@./exe