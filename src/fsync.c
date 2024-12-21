#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF_SIZE 4096 // 4KB
#define FILE_SIZE ((4096 * 1024)) // 4MB

int main (int argc, char *argv[])
{
    int  fd, sum, r;
    char buf[BUF_SIZE];

    clock_t start, end;
    double elapsed;

    fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
    if (fd == -1) {
        perror("open file");
        return 1;
    }

    memset((void*)buf, 0, BUF_SIZE);

    start = clock();

    // 書き込んだバイト数の総和
    sum = 0;
    while ( (r = write(fd, buf, BUF_SIZE)) >= 0 ) {
        // 書き込んだバイト数を加算(1ページ(4KB)ずつ書き込まれる)
        sum += r;
	    // 4MBに達したら終了
        if (sum >= FILE_SIZE) {
            break;
        }
    }

    fsync(fd);

    close(fd);

    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("Time taken with fsync: %f msec\n", elapsed);

    return 0;
}