#include "diy.h"

int main()
{
    char a[PATH_MAX]; //PATH_MAX定义在<limits.h>中
    if(getcwd(a,PATH_MAX)==NULL)
    {
        exit(1);
    }
    printf("%s\n",a);
}
