#无用的最终目标文件。仅仅是为了编译各个源文件而已。
CC = gcc
BIN_PATH = bin
OP = -O2
OBJ = stat pwd mkfifo mkdir uname
INC = lib

ALL:$(BIN_PATH) $(OBJ)
	
$(BIN_PATH): 
	mkdir $@
%: %.c
	$(CC) $(OP) -I $(INC) -o $(BIN_PATH)/$@ $<

clean:
	rm -f $(BIN_PATH)/*

