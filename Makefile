CC = clang
CFLAGS = -Wall -Wextra -O0 -g

#uses implicit rules
# .o:
# $(CC) -c $(CPPFLAGS) $(CFLAGS) $^ -o $@
# binary:
# $(CC) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) -o $@
all: e1 e2 e3 e4 e5 e6 e7 e8

clean:
	rm e1 e2 e3 e4 e5 e6 e7 e8
