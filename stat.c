#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
char *file_type(mode_t st_mode);

int main(int argc,char *argv[])
{
    struct stat buf;
    stat(argv[1],&buf);
    printf("  文件：\"%s\"\n",argv[1]);
    printf("  大小：%ld\t\t块: %ld\t\tIO 块：%ld\t",buf.st_size,
           buf.st_blocks,buf.st_blksize);
    printf("%s\n",file_type(buf.st_mode));
    printf("设备：%u%02uh/%ldd\t",major(buf.st_dev),
           minor(buf.st_dev),buf.st_dev);
    printf("Inode：%ld\t硬链接：%ld\n",buf.st_ino,buf.st_nlink);

    printf("权限：%u\n",buf.st_mode);

    struct passwd *passwd;
    struct group *group;
    passwd = getpwuid(buf.st_uid);
    group = getgrgid(buf.st_gid);
    printf("Uid：(%5d/%8s)\tGid：(%5d/%8s)\n",buf.st_uid,
           passwd->pw_name,buf.st_gid,group->gr_name);
    printf("最近访问：%s",ctime(&buf.st_atime));
    printf("最近更改：%s",ctime(&buf.st_mtime));
    printf("最近改动：%s",ctime(&buf.st_ctime));
}
char *file_type(mode_t st_mode)
{
    char *ptr;
    if (S_ISREG(st_mode)) 
    ptr = "regular"; 
    else if (S_ISDIR(st_mode)) 
    ptr = "directory"; 
    else if (S_ISCHR(st_mode)) 
    ptr = "character special"; 
    else if (S_ISBLK(st_mode)) 
    ptr = "block special"; 
    else if (S_ISFIFO(st_mode)) 
    ptr = "fifo"; 
    else if (S_ISLNK(st_mode)) 
    ptr = "symbolic link"; 
    else if (S_ISSOCK(st_mode)) 
    ptr = "socket"; 
    else 
    ptr = "** unknown mode **"; 
    return ptr;
}
