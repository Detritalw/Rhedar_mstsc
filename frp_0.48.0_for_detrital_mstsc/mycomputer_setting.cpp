#include<Windows.h>
#include<bits/stdc++.h>

int main(){
    // 打开 关于本机 设置
    ShellExecute(NULL, "open", "ms-settings:about", NULL,NULL, SW_SHOWNORMAL);
    return 0;
}

