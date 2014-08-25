#include <stdio.h>
#include <time.h>
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
    printf("设备：%u%02u/h%ldd\t",major(buf.st_dev),
           minor(buf.st_dev),buf.st_dev);
    printf("Inode：%ld\t硬链接：%ld\n",buf.st_ino,buf.st_nlink);

    printf("权限：%u\n",buf.st_mode);
    printf("Uid：%d\tGid：%d\n",buf.st_uid,buf.st_gid);
    printf("最近访问：%s",ctime(&buf.st_atime));
    printf("最近更改：%s",ctime(&buf.st_mtime));
    printf("最近改动：%s",ctime(&buf.st_ctime));
}
