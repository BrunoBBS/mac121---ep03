CC:=gcc
CFLAGS:=-Wall -pedantic -ansi -O2
BIN:=ep3

#make binaries

$(BIN):tresReversao.o pilha.o
	$(CC) $(CFLAGS) -o $@ $^

#make objects

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

#make objects with headers

%.o:%.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

#make clean

clean:
	rm -f $(BIN)
	rm -f tresReversao.o

