FINAL = all
COMPILER = gcc
ASSEMBLER = nasm
CFLAGS = -std=c99 -c -m32
SFLAGS = -f elf32
OFLAGS = -no-pie -z  noexecstack -m32

$(FINAL) : main1.o functions2.o
        $(COMPILER) main1.o functions2.o $(OFLAGS) -o $(FINAL) -lm
main1.o : main1.c
        $(COMPILER) $(CFLAGS) -o main1.o main1.c
functions2.o : functions2.asm
        $(ASSEMBLER) $(SFLAGS) -o functions2.o functions2.asm
clean :
        rm $(FINAL) *.o
