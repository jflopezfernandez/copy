
vpath %.c src
vpath %.h include

CP       = cp -f -u
RM       = rm -f

TARGET   = copy
VERSION  = 1.0.0

OBJS     = $(patsubst %.c,%.o,$(notdir $(wildcard src/*.c)))

CC       = gcc
CFLAGS   = -std=c17 -Wall -Wextra -Wpedantic -g -O0 -ggdb
CPPFLAGS = -DPACKAGE_NAME=\"$(TARGET)\" -DPACKAGE_VERSION=\"$(VERSION)\" -D_GNU_SOURCE -D_XOPEN_SOURCE=700
LDFLAGS  = -lm

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I include    -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I include -c -o $@ $^

.PHONY: clean
clean:
	$(RM) ./*.{o,copy} $(TARGET)

.PHONY: install
install: $(TARGET)
	$(CP) ./$(TARGET) /usr/bin

.PHONY: uninstall
uninstall:
	$(RM) /usr/bin/$(TARGET)

