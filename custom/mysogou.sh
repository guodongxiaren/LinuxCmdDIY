echo "正在关闭fcitx"
pkill -9 fcitx

echo "正在重启fcitx"
fcitx -r --enable sogou-qimpanel &> /dev/null

echo "正在打开sogou面板"
sogou-qimpanel & &> /dev/null 

