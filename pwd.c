#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
int main()
{
    char a[PATH_MAX];
    if(getcwd(a,PATH_MAX)==NULL)
    {
        exit(1);
    }
    printf("%s\n",a);
}
