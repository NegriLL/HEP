FILENAME = E01.tex
$(FILENAME).pdf: $(FILENAME).ps
	ps2pdf $(FILENAME).ps
$(FILENAME).ps: $(FILENAME).dvi
	dvips $(FILENAME).dvi
$(FILENAME).dvi: $(FILENAME).tex
	-latex --verbose $(FILENAME).tex