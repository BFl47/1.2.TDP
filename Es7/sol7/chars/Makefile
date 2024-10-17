CC=g++
CFLAGS=-I.
SOURCES=$(shell find -type f -name '*.c' -printf '%p ')
TGT=main


all: $(TGT)

$(TGT):	$(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJS) *~ $(TGT)

.PHONY:	clean
