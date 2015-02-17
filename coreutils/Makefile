CC = gcc
BIN_DIR = bin
INC_DIR = include
LIB_DIR = lib
OP = -O2
OBJ = stat pwd mkfifo mkdir uname  

#ALL为无用的最终目标文件。仅仅是为了编译各个源文件而已。
ALL:$(BIN_DIR) $(OBJ)
	
$(BIN_DIR): 
	mkdir $@
uname: $(LIB_DIR)/version.o uname.c
	$(CC) $(OP) -I $(INC_DIR) -o $(BIN_DIR)/$@ $^

$(LIB_DIR)/version.o: $(LIB_DIR)/version.c
	$(CC) $(OP) -I $(INC_DIR) -o $@ $^ -c
%: %.c 
	$(CC) $(OP) -I $(INC_DIR) -o $(BIN_DIR)/$@ $^

.PHONY:love
love:
	rm -f $(BIN_DIR)/*

