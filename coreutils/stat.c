#include <stdio.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
char *file_type(mode_t st_mode,char *type);
void permission(mode_t st_mode,char *per,int *code);
int o2d(int mode);

int main(int argc,char *argv[])
{
    struct stat buf;
    stat(argv[1],&buf);
    printf("  文件：\"%s\"\n",argv[1]);
    printf("  大小：%ld\t\t块: %ld\t\tIO 块：%ld\t",buf.st_size,
           buf.st_blocks,buf.st_blksize);
    char type;
    printf("%s\n",file_type(buf.st_mode,&type));
    printf("设备：%u%02uh/%ldd\t",major(buf.st_dev),
           minor(buf.st_dev),buf.st_dev);
    printf("Inode：%ld\t硬链接：%ld\n",buf.st_ino,buf.st_nlink);

    char per[]="---------";
    int code;
    permission(buf.st_mode,per,&code);
    printf("权限：(%04d/%c%s)  ",code,type,per);

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
char *file_type(mode_t st_mode,char *type)
{
    char *ptr;
    if (S_ISREG(st_mode)) 
    {
        ptr = "regular"; 
        *type = '-';
    }
    else if (S_ISDIR(st_mode)) 
    {
        ptr = "directory"; 
        *type = 'd';
    }
    else if (S_ISCHR(st_mode)) 
    {
        ptr = "character special"; 
        *type = 'c';
    }
    else if (S_ISBLK(st_mode)) 
    {
        ptr = "block special"; 
        *type = 'b';
    }
    else if (S_ISFIFO(st_mode)) 
    {
        ptr = "fifo"; 
        *type = 'p';
    }
    else if (S_ISLNK(st_mode)) 
    {
        ptr = "symbolic link"; 
        *type = 'l';
    }
    else if (S_ISSOCK(st_mode)) 
    {
        ptr = "socket"; 
        *type = 's';
    }
    else 
    ptr = "unknown mode"; 
    return ptr;
}
void permission(mode_t st_mode,char *per,int *code)
{
    *code=o2d(st_mode)%10000;
    int len=9;
    int bit;
    while(len--)
    {
        bit=st_mode&1;
        st_mode>>=1;
        if(!bit)
        continue;
        switch(len%3)
        {
            case 2:per[len]='x';break;
            case 1:per[len]='w';break;
            case 0:per[len]='r';break;
        }
    }
    len=3;
    while(len--)
    {
        bit=st_mode&1;
        st_mode>>=1;
        if(!bit)
        continue;
        switch(len%3)
        {
            case 2:per[8]='t';break;
            case 1:per[5]='s';break;
            case 0:per[2]='s';break;
        }
    }
}
int o2d(int mode)
{
    int res=0;
    int base=1;
    while(mode)
    {
        res+=mode%8*base;
        base*=10;
        mode/=8;
    }
    return res;
}
