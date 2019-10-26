#compiler
CC = gcc
#FLAGS 
CFLAGS = -g -Wall
#SOURCE FILES
src = $(wildcard src/*.c)
obj = $(src: *.c=*.o)
#TARGET FOLDER
TARGET_FLDR = output
#TARGET
TARGET = clox

#MAKE INSTRUCTIONS
default:$(TARGET)

$(TARGET): $(obj)
	$(CC) $(CFLAGS) -o $(TARGET_FLDR)/$@ $^

.PHONY: clean
clean:
	rm -f $(TARGET_FLDR)/$(TARGET) 	
