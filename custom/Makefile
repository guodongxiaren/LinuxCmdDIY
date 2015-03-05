SRCS = $(wildcard *.sh)
OBJS = $(patsubst %.sh,%,$(SRCS))
ALL: $(OBJS)

%: %.sh
	@echo moving $^ ...
	@install -p -D -m 0755 $^ /usr/local/bin/$@

