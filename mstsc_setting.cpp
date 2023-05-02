#include<Windows.h>
#include<bits/stdc++.h>

int main(){
    // 打开 远程桌面连接 设置
    ShellExecute(NULL, "open", "control.exe", "sysdm.cpl,System,5", NULL, SW_SHOWNORMAL);
    return 0;
}

