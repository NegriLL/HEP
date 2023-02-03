import re
import sys

# I found it easier to use exact text matching rather than regex for this exercise

path = r"./Ex2/brilcalc.log"

with open(path) as f:
    while f.readline() != '#Summary: \n':
        pass
    f.readline()
    f.readline()
    f.readline()
    values = f.readline().split('|')
    totrecorded = float(values[-2].strip())

    print("{:.1f} fb^-1".format(totrecorded*0.001))