#include<Windows.h>
#include<bits/stdc++.h>

int main(){
    // �� Զ���������� ����
    ShellExecute(NULL, "open", "control.exe", "sysdm.cpl,System,5", NULL, SW_SHOWNORMAL);
    return 0;
}

