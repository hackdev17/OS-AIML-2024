build:
	@echo "Building ..."
	@for i in *.c ; do cc $$i -Wall -o $${i%.c}.bin -lm ; done
	@echo "Build Done"

clean:
	@echo "Removing compiled files ..."
	@rm -rf *.bin test/

ark:
	@tar -zcvf archive.tgz *.c makefile doc/

cdrom:	ark
	@mkisofs archive.tgz > DSA-CD.iso

.PHONY:	doc
