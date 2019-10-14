WARNFLAGS = -W -Wall 
OPTFLAGS = -O3
DEBUGFLAGS = -ggdb3 -DDEBUG
CFLAGS += $(WARNFLAGS)

.PHONY = clean all 

ifdef DEBUG 
  CFLAGS += $(DEBUGFLAGS)
else
  CFLAGS += $(OPTFLAGS)
endif 

all : test3

test3 : process.c queue.c processmodel.c


clean :
	$(RM) *~ *.o test3


