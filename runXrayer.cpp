#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int n=15;//重连十五次 
int main(){
	if(MessageBox(NULL,
"要在网络上开放你的计算机吗?\n\
警告:\n\
	1.请不要用此程序干别的坏事!\n\
	2.请注意你的计算机安全,不要让别人知道你的密码,否则很容易入侵你的电脑\n\
	3.请注意安全\n\
	4.可能需要 Windows 防火墙授权", "Button", MB_SYSTEMMODAL | MB_OKCANCEL)==IDOK){
		if(MessageBox(NULL,"请问你开启了远程连接吗?如果未开启对方是无法连接到您这里的,请点击否来打开设置", "Button", MB_SYSTEMMODAL | MB_YESNO)==IDNO){
			ShellExecute(NULL, "open", "control.exe", "sysdm.cpl,System,5", NULL, SW_SHOWNORMAL);
		}
		system("md Temp");
		system("cls");
		freopen("Temp\\Xrayout.log","w",stdout);
		while(n--){
			system("frpc.exe -c frpc.ini");
			
			Sleep(3000);
		}
		MessageBox(NULL,"重连已超过15次.\n现在结束内网穿透运行程序\n请检查网络连通性","TIMEOUT", MB_OK | MB_ICONERROR);
	}
//    getline(cin, myString);
	return 0;
}
