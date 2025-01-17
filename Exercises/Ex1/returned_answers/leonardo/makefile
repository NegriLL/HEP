SRC = $(basename $(wildcard *.tex))

all:
	$(MAKE) -i tex
	$(MAKE) mf
	$(MAKE) tex
	$(MAKE) dvips
	$(MAKE) clean

tex:
	# the reference does not appear unless I run latex twice
	latex $(SRC)
	bibtex $(SRC)
	latex $(SRC)

mf:
	mf "\mode=localfont; input first-diagram.mf;"
	mf "\mode=localfont; input second-diagram.mf;"

dvips:
	dvips $(SRC) -o

RM = $(sort $(wildcard *.dvi *.log *.aux *diagram* *.sty *.tmp *.bbl *.blg))
clean:
	@rm -rf $(RM)

cleanAll:
	$(MAKE) clean
	rm -rf *.ps

test:
	echo $(SRC)
