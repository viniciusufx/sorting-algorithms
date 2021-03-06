#!/bin/python3
import argparse
from ast import arg
import random

def gem(size, shuffle):
    lista = list()
    for i in range(1, size+1):
        lista.append(i)
    for i in range(1, shuffle):
        random.shuffle(lista)
    
    with open(str(size)+'.in', 'w') as myfile:
        for i in lista:
            if (i == lista[-1]):
                print(i, file=myfile, end='')
            else:
                print(i, file=myfile)
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('-si', '--size', help="Numbers to be generated", type=int)
    parser.add_argument('-sh', '--shuffle', type=int)
    args = parser.parse_args()
    if args.size is None or args.shuffle is None:
        parser.print_help()
    else:
        gem(args.size, args.shuffle)

if __name__ == "__main__":
    main()