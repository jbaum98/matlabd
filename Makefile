PREFIX = /usr/local
CC = gcc

all: matlabroot bin/waitforsig sigusr1 src/sigusr1.m

sigusr1: src/sigusr1.c
	$(MATLABROOT)/bin/mex $<

bin/waitforsig: src/waitforsig.c
	$(CC) $< -o $@

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	mkdir -p $(DESTDIR)$(PREFIX)/lib/matlabd
	cp -R bin completions libexec $(DESTDIR)$(PREFIX)/lib/matlabd/
	ln -sf $(DESTDIR)$(PREFIX)/lib/matlabd/bin/matlabd $(DESTDIR)$(PREFIX)/bin/
	mkdir -p $(MATLABROOT)/toolbox/matlabd
	cp $(wildcard sigusr1.mex*) src/sigusr1.m $(MATLABROOT)/toolbox/matlabd
	@echo "\nAdd the following to your startup.m: \
	\n\n\taddpath(toolboxdir('matlabd'))"
	@echo "\nFor shell completions, add the following to your startup files: \
	\n\n \teval \"\$$($(DESTDIR)$(PREFIX)/bin/matlabd init -)\""

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/matlabd
	rm -rf $(MATLABROOT)/toolbox/matlabd
	rm -rf $(DESTDIR)$(PREFIX)/lib/matlabd/

matlabroot:
ifndef MATLABROOT
	$(error MATLABROOT is undefined)
endif
