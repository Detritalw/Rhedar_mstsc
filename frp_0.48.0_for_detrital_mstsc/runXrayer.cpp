#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int n=15;//����ʮ��� 
int main(){
	if(MessageBox(NULL,
"Ҫ�������Ͽ�����ļ������?\n\
����:\n\
	1.�벻Ҫ�ô˳���ɱ�Ļ���!\n\
	2.��ע����ļ������ȫ,��Ҫ�ñ���֪���������,���������������ĵ���\n\
	3.��ע�ⰲȫ\n\
	4.������Ҫ Windows ����ǽ��Ȩ", "Button", MB_SYSTEMMODAL | MB_OKCANCEL)==IDOK){
		if(MessageBox(NULL,"�����㿪����Զ��������?���δ�����Է����޷����ӵ��������,��������������", "Button", MB_SYSTEMMODAL | MB_YESNO)==IDNO){
			ShellExecute(NULL, "open", "control.exe", "sysdm.cpl,System,5", NULL, SW_SHOWNORMAL);
		}
		system("md Temp");
		system("cls");
		freopen("Temp\\Xrayout.log","w",stdout);
		while(n--){
			system("frpc.exe -c frpc.ini");
			
			Sleep(3000);
		}
		MessageBox(NULL,"�����ѳ���15��.\n���ڽ���������͸���г���\n����������ͨ��","TIMEOUT", MB_OK | MB_ICONERROR);
	}
//    getline(cin, myString);
	return 0;
}
