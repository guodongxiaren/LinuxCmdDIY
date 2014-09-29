自定义的命令
===========
即系统中没有的命令
##命令脚本
将该目录中的脚本转变为系统可用的命令，可以执行如下脚本完成：
```bash
#!/bin/bash
dir="/usr/local/bin/"
for i in *sh
do
    chmod u+x $i
    cp $i $dir/${i%*.sh}
done
```
