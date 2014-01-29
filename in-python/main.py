#!/usr/bin/python

import sys

def disassemble(filename):
    with open(filename) as f:
        while True:
            byte = f.read(1)
            if byte == '':
                break
            print("db %s" % hex(ord(byte)))

if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit("Usage: %s <filename>" % sys.argv[0])
    disassemble(sys.argv[1])
