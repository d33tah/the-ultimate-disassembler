#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

MAX_FILE_SIZE = 2048;

//void dump_buffer(void *buffer, int buffer_size) {
void dump_buffer(char *buffer, int buffer_size) {

    int i;

    for(i = 0; i < buffer_size; ++i) {
        if (buffer[i] == -112) {
            printf("nop\n");
        }
        else {
            printf("db 0x%x\n", buffer[i]);
        }
    }
}

int main(int argc, char *argv[]) {

    FILE *f;
    unsigned char buffer[MAX_FILE_SIZE];
    int n;

    if (argc < 2) {
        printf("./dissasembler <binary_file>");
        return 0;
    }

    f = fopen(argv[1], "rb");
    if (f) {
        //while(!feof(f))
        n = fread(buffer, MAX_FILE_SIZE, 1, f);
    }
    else {
        // error opening file
        printf("error");
        return 0;
    }

    dump_buffer(buffer, MAX_FILE_SIZE);

}
