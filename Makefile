# Master Makefile

all:
	$(MAKE) -C Chapter-1
	$(MAKE) -C Chapter-2
	$(MAKE) -C Chapter-3
	$(MAKE) -C Chapter-4
	$(MAKE) -C Chapter-5
	$(MAKE) -C Chapter-6
	$(MAKE) -C Chapter-7

clean:
	$(MAKE) -C Chapter-1 clean
	$(MAKE) -C Chapter-2 clean
	$(MAKE) -C Chapter-3 clean
	$(MAKE) -C Chapter-4 clean
	$(MAKE) -C Chapter-5 clean
	$(MAKE) -C Chapter-6 clean
	$(MAKE) -C Chapter-7 clean