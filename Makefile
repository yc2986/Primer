# Master Makefile

all:
	$(MAKE) -C Chapter-1
	$(MAKE) -C Chapter-2
	$(MAKE) -C Chapter-3
	$(MAKE) -C Chapter-4

clean:
	$(MAKE) -C Chapter-1 clean
	$(MAKE) -C Chapter-2 clean
	$(MAKE) -C Chapter-3 clean
	$(MAKE) -C Chapter-4 clean