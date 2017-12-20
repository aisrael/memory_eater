#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#define BLOCKS      1

int main(void)
{
    unsigned long long page_size = sysconf(_SC_PAGESIZE);
    unsigned long long avphys_pages = sysconf(_SC_AVPHYS_PAGES);
    unsigned long long availMem = page_size * avphys_pages;
    printf("page_size => %ld\n", page_size);
    printf("avphys_pages => %ld\n", avphys_pages);
    printf("availMem => %ld\n", availMem);

    unsigned long allocated = 0;
    size_t required = BLOCKS << 20;
    char *mem;
    while (1) {
        mem = malloc (required);
        allocated += BLOCKS;
        // only write once per page
        for (int i = required / page_size; i--;) {
            mem[i * page_size] = i;
        }
        printf("Allocated %ld MB\n", allocated);
        if (mem == NULL) {
            if (mem) free (mem);
            printf("Cannot allocate enough memory\n");
            return 1;
        }
    }
}
