#!/bin/bash -xe
# -xe = display commands as we go, panic on an ANY non-zero exit code.

# create an empty file
touch empty.c

# compile this empty file
gcc -c -o mbr.elf empty.c
rm empty.c

# add binary as a raw section
objcopy --add-section text=mbr.bin mbr.elf

# remove ".comment" section to join
objcopy -R .comment mbr.elf

# now disasemble it
objdump -m i8086 --disassemble-all --disassemble-zeroes mbr.elf | \
    # the third column is the assembly output
    awk -F'\t' '{ print $3 }' | \
    # skip empty lines and anything that mentions (bad)
    egrep -v '^$|\(bad\)' > mbr.asm

as mbr.asm --32 -o mbr2.elf

objdump -m i8086 --disassemble-all --disassemble-zeroes mbr2.elf | \
    awk -F'\t' '{ print $3 }' | \
    egrep -v '^$|\(bad\)' > mbr2.asm

vimdiff mbr.asm mbr2.asm
