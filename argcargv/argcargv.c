#include <stdio.h>
#include <string.h>
#include <stdint.h>

const char *NULL_STR="[NULL]";

int main(int argc, char *argv[]){
    int total_argv_length=argc; // account for null characters
    printf("&argv=%p\n",&argv);
    for(int i=0; i<argc; i++){
        total_argv_length+=strlen(argv[i]);
        printf("&argv[%d]=%p\targv[%d]=%p\t*argv[%d]=%c\n",
            i,&argv[i] ,i,argv[i] ,i,*argv[i]
        );
    }
    printf("Length of data pointed to by argv=%d\n",total_argv_length);

    printf("Printing %d bytes as characters following argv[0]:\n",total_argv_length);
    for(int i=0; i<total_argv_length; i++){
        switch(argv[0][i]){
            case '\0':
                printf("%s",NULL_STR);
                break;
            case '\n':
                printf("[\n]");
                break;
            case '\r':
                printf("[\r]");
                break;
            default:
                printf("%c",argv[0][i]);
        }
    }
    printf("\n");
    int offset=0;
    for(int i=0; i<argc; i++){
        for(int j=0; j<offset; j++){
            printf(" ");
        }
        printf("^- %p\n", argv[i]);
        offset+=strlen(argv[i])+strlen(NULL_STR);
    }
    printf("\n");


    return 0;
}