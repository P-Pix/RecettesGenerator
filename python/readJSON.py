import json
import os
import sys

def main():
    # on récupère le fichier json
    with open(sys.argv[1], 'r') as f:
        data = json.load(f)
    for i in data:
        print (i)
        print (data[i])
        print ("\n")

if __name__ == "__main__":
    main()
else:
    print("readJSON imported")