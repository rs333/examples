#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "filelocks.h"

int main(int argc, char *argv[]){
    struct flock lock; // Provided by fcntl.h
    lock.l_type = F_WRLCK;    // Write lock
    lock.l_whence = SEEK_SET; // Position relative to start of file
    lock.l_start = 0;         // Offset from whence
    lock.l_len = 0;           // Entire file no matter how big
    lock.l_pid = getpid();    // Process locking the file (this one)

    int fd;
    if(( fd = open(filename, O_RDWR | O_CREAT, 0644 )) < 0){
        perror("Error opening file.");
        exit(EXIT_FAILURE);
    }
    
    if(fcntl(fd, F_SETLK, &lock) < 0 ){
        perror("Failed to get lock.");
        exit(EXIT_FAILURE);
    }else{
        write(fd, data2write,strlen(data2write));
        printf("%s(%d) wrote to %s.\n",argv[0],lock.l_pid,filename);
    }

    lock.l_type = F_UNLCK;
    if(fcntl(fd, F_SETLK, &lock) < 0 ){
        perror("Failed to release lock.");
        exit(EXIT_FAILURE);
    }

    close(fd);
    return 0;
}