SRCS = $(wildcard *.sh)
OBJS = $(patsubst %.sh,%,$(SRCS))
ifeq ($(prefix),)
	prefix = /usr/local/bin
endif
ALL: $(OBJS)

%: %.sh
	@echo moving $^ to $(prefix)/ ...
	@install -p -D -m 0755 $^ $(prefix)/$@

.PHONY: help
help:
	@echo "指定安装路径，请加参数prefix=路径"
	@echo "如：make prefix=~/bin"

