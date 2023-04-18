# Pro*C Makefile
PROCC=proc code=ANSI_C include=./include
CC=gcc
INC=-I. -I./include -I$(ORACLE_HOME)/sdk/include/
CFLAGS=-Wall -g $(INC)
LIBS=-L/u01/app/oracle/product/version/db_1/lib -lclntsh

HEADERS=$(shell find ../7_Library -name "*.h")
PCFILES=$(shell find ../7_Library -name "*.pc")
CFILES=$(shell find ../7_Library ../6_Report_Program -name "*.c")
CSRC=$(PCFILES:.pc=.c)
LSRC=$(PCFILES:.pc=.lis)
OBJ=$(PCFILES:.pc=.o) $(CFILES:.c=.o)
TARGET=report

%.c:%.pc
	$(PROCC) $<

%.o:%.c $(HEADERS)
	$(CC) $(CFLAGS) $< -c -o $@

$(TARGET): $(OBJ)
	$(CC) $(LIBS) $^ -o $@
	
.PRECIOUS:%.c

.PHONI: clean

clean:
	rm -f $(TARGET) $(OBJ) $(CSRC) $(LSRC)
