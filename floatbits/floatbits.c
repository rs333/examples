#include <stdio.h>

void print_bits_le(float val)
{
    unsigned char *val_bytes_ptr = (unsigned char *)(&val + 1) - 1;

    while (val_bytes_ptr >= (unsigned char *)&val)
    {
        for (int i = 7; i >= 0; i--)
        {
            printf("%u", (*val_bytes_ptr >> i) & 0x01);
        }
        val_bytes_ptr--;
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    float a = 42.0;

    printf("a = %3.2f\n", a);

    print_bits_le(a);

    a -= a;

    printf("a = %3.2f\n", a);

    print_bits_le(a);

    return 0;
}