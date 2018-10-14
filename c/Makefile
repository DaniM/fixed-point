CFLAGS += -g

.PHONY: clean

default: fixed.o

test_fixed: fixed.o test_fixed.c
	$(CC) -o $@ $(CFLAGS) $+

clean:
	rm -f *.o
