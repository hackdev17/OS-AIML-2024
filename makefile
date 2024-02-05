build:
	@echo "Building ..."
	@for i in *.c ; do cc $$i -Wall -o $${i%.c}.bin -lm ; done
	@echo "Build Done"

clean:
	@echo "Removing compiled files ..."
	@rm -rf *.bin

ark:
	@tar -zcvf archive.tgz *.c makefile

cdrom:	ark
	@mkisofs archive.tgz > OS-CD.iso
