CC=cc
AR=ar r

objects = src/md5.o src/xkey.o

LIB=libxkey.a

all: $(LIB)

$(LIB): $(objects)
	ar rcs $@ $^

md5.o: src/md5.c
xkey.o: src/xkey.h src/xkey.c

TEST_OBJS=test/test.o

test: xkeytest
	$(CC) -o xkeytest $(TEST_OBJS) $(LIB)

xkeytest: src/xkey.h $(TEST_OBJS) $(LIB)

test.o: ../src/xkey.h test/test.c

clean:
	rm libxkey.a $(objects) $(TEST_OBJS) xkeytest
