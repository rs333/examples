#include <stdint.h>
#include <stdio.h>

union positive_bits_union {
  uint64_t all_bits;
    struct positive_bits{
      uint64_t a: 1;
      uint64_t : 7;
      uint64_t b: 2;
      uint64_t : 6;
      uint64_t c: 4;
    } bits;
};
union negative_bits_union {
  uint64_t all_bits;
  struct negative_bits{
    int64_t a: 1;
    int64_t : 7;
    int64_t b: 2;
    int64_t : 6;
    int64_t c: 4;
  } bits;
};

int main(int argc, char *argv[]){
  // No real reason for initializing these differently.
  union positive_bits_union some_positive_bits = {
    .bits ={ -1,-1,-1} 
  };
  union negative_bits_union some_negative_bits = {
    .bits.a = -1,
    .bits.b = -1,
    .bits.c = -1
  };

  printf("sizeof(some_positive_bits) = %lu\n",sizeof(some_positive_bits));
  printf("sizeof(some_negative_bits) = %lu\n",sizeof(some_negative_bits));

  // Observe wrap
  printf("------------------------------------+--------------------------------\n");
  printf("           Negative Bits            |          Positive Bits \n");
  printf("------------------------------------+--------------------------------\n");
  for( int i=0; i< 32; i++){
    some_positive_bits.bits.a++;
    some_positive_bits.bits.b++;
    some_positive_bits.bits.c++;
    some_negative_bits.bits.a++;
    some_negative_bits.bits.b++;
    some_negative_bits.bits.c++;
    printf("a=%d\tb=%d\tc=%d\t%#010lx %c%c%c %#010lx a=%u\tb=%u\tc=%u  \n",
        some_negative_bits.bits.a,
        some_negative_bits.bits.b,
        some_negative_bits.bits.c,
        some_negative_bits.all_bits,
        ( some_negative_bits.bits.a < some_positive_bits.bits.a ? '<' : some_negative_bits.bits.a == some_positive_bits.bits.a ? '=' : '>' ),
        ( some_negative_bits.bits.b < some_positive_bits.bits.b ? '<' : some_negative_bits.bits.b == some_positive_bits.bits.b ? '=' : '>' ),
        ( some_negative_bits.bits.c < some_positive_bits.bits.c ? '<' : some_negative_bits.bits.c == some_positive_bits.bits.c ? '=' : '>' ),
        some_positive_bits.all_bits,
        some_positive_bits.bits.a,
        some_positive_bits.bits.b,
        some_positive_bits.bits.c
    );
  }
  printf("------------------------------------+--------------------------------\n");

  return 0;
}