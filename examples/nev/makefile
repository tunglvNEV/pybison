










CFLAGS = -I../include -I./ -I$(ORACLE_HOME)/precomp/public


DEBUG_FLAGS2 = -DDEBUG_TLOG


LDFLAGS = -L../lib -L$(ORACLE_HOME)/lib
LIBS =
ORA_LIBS = -lclntsh -ln10 -lnl10 -lnro10 -lsql10 -lclient10 \
           -lvsn10 -lcommon10 -lskgxp10 -lgeneric10 -lmm \
           -lnls10 -lcore10 -lplp10

.SUFFIXES: .o .c .pc

PROC = proc
CC = gcc

PROCFLAGS = INCLUDE=../include SYS_INCLUDE=/usr/include PARSE=NONE LINE=yes SQLCHECK=SEMANTICS USER=${PROC_DB}

PCSRCS = ml_ent_01.pc ml_ent_com.pc merit_cns.pc \
         merit_mtyp.pc merit_command.pc

SRCS   = ml_ent_01.c  ml_ent_com.c  merit_cns.c \
         merit_mtyp.c merit_command.c

OBJS   = ml_ent_01.o  ml_ent_com.o  merit_cns.o \
         itsh.tab.o merit_mtyp.o lex.yy.o merit_command.o

TARGET = gmrt_ml_ent01_t4a

prefix  = 

all: $(TARGET)

.pc.c:
	@echo Pre-Compiling now ... $<
	$(PROC) $(PROCFLAGS) iname=$<
	@echo Done.

.c.o:
	@echo Compiling Now... $<
	$(CC) -c $< $(CFLAGS) $(DEBUG_FLAGS) $(DEBUG_FLAGS2)
	@echo Done.

lex.yy.c : itsh.l itsh.tab.c

	flex -p itsh.l

itsh.tab.c : itsh.y

	bison -d itsh.y
	$(CC) -c $(YAC_DEBUG) $(DEBUG_FLAGS) $(DEBUG_FLAGS2) itsh.tab.c

$(TARGET): $(OBJS)
	@echo Linking Now .... $@
	$(CC) -o $@ $(OBJS) $(DEBUG_FLAGS) $(DEBUG_FLAGS2) $(LDFLAGS) $(LIBS) $(ORA_LIBS)
	@echo Done.

clean:
	rm -f $(OBJS)
	rm -f $(SRCS)
	rm -f $(TARGET)
	rm -f itsh.tab.*
	rm -f lex.yy.*
	rm -f *.lis
	rm -f core
	rm -f *.output

