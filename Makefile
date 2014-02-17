# $Id: Makefile 21207 2009-10-08 12:27:18Z henry $
# ken@chumby.com

CROSS_COMPILE=${TARGET}-
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
VIDEO_X_RES ?= 320
VIDEO_Y_RES ?= 240
# henry@chumby.com - removed -I/usr/src/linux/include
CFLAGS += -O2 -DWIDTH=$(VIDEO_X_RES) -DHEIGHT=$(VIDEO_Y_RES) -DCNPLATFORM_${CNPLATFORM} -DCONFIGNAME_${CONFIGNAME} fbtext.c

TARGETS = fbwrite

all: $(TARGETS)

fbwrite: fbwrite.c fbtext.c fbtext.h $(wildcard font*.c)
	${CC} ${CFLAGS} fbwrite.c -o $@

clean:
	rm -f *.o $(TARGETS)
