#!/usr/bin/env python

import sys
import ROOT
import os

if len(sys.argv) == 1:
    print("###")
    print("### Usage:  ",os.path.basename(sys.argv[0]),"rootfile")
    print("###")
    sys.exit()

filename = sys.argv[1]


fIN = ROOT.TFile.Open(filename)
tree = fIN.Get("Events")
tree.MakeSelector("MyAnalysis")
fIN.Close()
