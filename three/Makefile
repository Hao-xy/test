BIN=surl
OBJ=surl.o
CC=gcc
$(BIN):$(OBJ)
	$(CC) -o  $@ $(OBJ) -lcurl
$(OBJ):surl.c 
	$(CC) -w -c $^ -o $@
clean:
	rm $ (OBJ) $(BIN)