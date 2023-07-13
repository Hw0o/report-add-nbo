#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    FILE * f1 = fopen(argv[argc-2], "rb");
    FILE * f2 = fopen(argv[argc-1], "rb");
    uint8_t buf1[4];
    uint8_t buf2[4];
    uint32_t *ptr1;
    uint32_t *ptr2;

    fread(buf1, sizeof(uint8_t), 4, f1);
    fread(buf2, sizeof(uint8_t), 4, f2);

    ptr1 = (uint32_t*)buf1;
    ptr2 = (uint32_t*)buf2;

    *ptr1 = ntohl(*ptr1);
    *ptr2 = ntohl(*ptr2);

    printf("%u(%x) + %u(%x) = %u(%x)\n", *ptr1, *ptr1, *ptr2, *ptr2, (*ptr1 + (*ptr2)), (*ptr1 + (*ptr2)));

    fclose(f1);
    fclose(f2);

    return 0;
}
