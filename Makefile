define \n


endef

PREFIX = /usr/local
CC = gcc

all: bin/waitforsig

bin/waitforsig: src/waitforsig.c
	$(CC) $< -o $@

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	mkdir -p $(DESTDIR)$(PREFIX)/lib/matlabd
	cp -R bin completions libexec $(DESTDIR)$(PREFIX)/lib/matlabd/
	ln -sf $(DESTDIR)$(PREFIX)/lib/matlabd/bin/matlabd $(DESTDIR)$(PREFIX)/bin/
	@echo "\nFor shell completions, add the following to your startup files: \
	\n\n\
	For bash users: \n\
        echo 'eval "\$($(DESTDIR)$(PREFIX)/bin/matlabd init -)"' >> ~/.bash_profile \
	\n\n\
	For zsh users: \n\
        echo 'eval "\$($(DESTDIR)$(PREFIX)/bin/matlabd init -)"' >> ~/.zshenv"

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/matlabd
	rm -rf $(DESTDIR)$(PREFIX)/lib/matlabd/
