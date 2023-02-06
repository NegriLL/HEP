FILE = feynman

$(FILE).pdf:	$(FILE).tex	$(FILE).bib	# check of dependences
	$(MAKE) All

all:						# no check of dependences
	$(MAKE) All
All:
	-$(MAKE) tex
	$(MAKE) metafont
	$(MAKE) bibtex
	$(MAKE) tex
	$(MAKE) tex
	$(MAKE) dvips
	$(MAKE) pdf
#	$(MAKE) view;

tex:
	latex $(FILE).tex

dvips:
	dvips $(FILE) -o

metafont:
	mf '\mode:=localfont; input ep_annihilation'

bibtex:
	bibtex $(FILE)

pdf:
#	dvipdf $(FILE)
	ps2pdf $(FILE).ps

view:
#	acroread $(FILE).pdf &
	okular $(FILE).pdf &

clean:
	@rm *.aux *.dvi *.log *.blg *.bbl ep_annihilation.* \
	if[-f *~] rm -f *~ fi


cleanAll:
	@$(MAKE) clean; rm *.ps *.pdf

