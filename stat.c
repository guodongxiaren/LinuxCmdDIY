#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argc,char *argv[])
{
    struct stat buf;
    stat(argv[1],&buf);
    printf("  文件：\"%s\"\n",argv[1]);
    printf("  大小：%ld\t\t块: %ld\t\tIO 块：%ld\n",buf.st_size,
         buf.st_blocks,buf.st_blksize);
    printf("设备：%u%02u/h%ldd\n",major(buf.st_dev),
           minor(buf.st_dev),buf.st_dev);
}
