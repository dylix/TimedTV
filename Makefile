# basic GTK+ app makefile
SOURCES = main_window.c
OBJS    = ${SOURCES:.c=.o}
CFLAGS  = `pkg-config gtk+-2.0 --cflags`
LDADD   = `pkg-config gtk+-2.0 --libs`
CC      = gcc -pthread
PACKAGE = timedtv

all : ${OBJS}
	${CC} -o ${PACKAGE} ${OBJS} ${LDADD}

.c.o:
	${CC} ${CFLAGS} -c $<

# end of file
