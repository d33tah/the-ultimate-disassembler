#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

MAX_FILE_SIZE = 1024;

void dump_buffer(void *buffer, int buffer_size) {
  int i;

  for(i = 0;i < buffer_size;++i)
     printf("%c", ((char *)buffer)[i]);
}

int main(int argc, char *argv[]) {

    FILE *f;
    unsigned char buffer[MAX_FILE_SIZE];
    int n;

    f = fopen("filename", "rb");
    if (f)
    {
        n = fread(buffer, MAX_FILE_SIZE, 1, f);
    }
    else
    {
        printf("error");
        return 1;
        // error opening file
    }

    dump_buffer(buffer, MAX_FILE_SIZE);

}
