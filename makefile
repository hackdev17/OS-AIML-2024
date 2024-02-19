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

doc:
	@latexmk -cd -auxdir=tmp/ -pdf -shell-escape doc/*.tex
	@gs -dNOPAUSE -sDEVICE=pdfwrite -sOUTPUTFILE=OS-Lab.pdf -dBATCH doc/{1..5}.pdf
	@rm -rf doc/tmp/ doc/*.pdf doc/_minted*/

.PHONY: doc
