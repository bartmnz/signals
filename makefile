CFLAGS+= -std=c11 -Wall -Werror -Wextra -pedantic -Wfloat-equal -Waggregate-return -Wstack-usage=1024 
CFLAGS+=-D _XOPEN_SOURCE=500
CFLAGS+=-D _POSIX_C_SOURCE=200809L

TARGET=signaler
OBJS=signaler.o
.PHONY: clean debug profile

all: $(TARGET)
$(TARGET): $(OBJS) -lm

debug: CFLAGS+=-g
debug: all


clean:
	-$(RM) $(TARGET) $(OBJS)

profile: CFLAGS+=-pg
profile: LDFLAGS+=-pg
profile: $(TARGET)
