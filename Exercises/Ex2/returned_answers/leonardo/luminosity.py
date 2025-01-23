import re

def main():
    pattern = r'\|\s+\d+\s+\|\s+\d+\s+\|\s+\d+\s+\|\s+\d+\s+\|\s+\d+\.\d+\s+\|(\s+\d+\.\d+)'
    
    with open("brilcalc.log", "r") as file:
        for line in file:
            value = re.findall(pattern, line)
            if value:
                print('Total Recorded is: {:.1f}'.format(float(value[0])))
                break
    
main()
