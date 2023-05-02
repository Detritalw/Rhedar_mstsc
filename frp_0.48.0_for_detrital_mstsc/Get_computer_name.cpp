#include<Windows.h>
#include<bits/stdc++.h>

using namespace std;

int main(){
    TCHAR name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD len = MAX_COMPUTERNAME_LENGTH + 1;

    if (!GetComputerName(name, &len)){
        cout << "Error getting computer name: " << GetLastError() << endl;
        return 1;
    }
    cout << "Computer name: " << name << endl;
    return 0;
}
