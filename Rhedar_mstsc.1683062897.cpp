#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;

// �궨��
#define ID_BUTTON1 1001
#define ID_BUTTON2 1002
#define ID_BITMAP1 1003

// ȫ�ֱ���
HINSTANCE hInstance;
int n;
HWND hwndButton1,hwndButton2,hwndButton3,hwndButton4,hwndPicture;
stringstream ss;
string computername,Temp,backgr;
// ��ӱ���ͼƬ
void AddBitmap(HWND hwnd, LPCSTR szFileName, HINSTANCE hInstance){
    HBITMAP hBitmap=(HBITMAP)LoadImage(hInstance, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    if(hBitmap==NULL){
        MessageBox(NULL,"�޷����ر���ͼƬ��\n��ȷ�����趨�ı�����Ŀ¼�²��ܴ�\n����������...\n 1.��������ͼƬ��ַ\n 2.����ͼƬ\n 3.���ͼƬ�Ƿ���������", "����", MB_OK | MB_ICONERROR);
    }
    hwndPicture=CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, 0, 0, 400, 400, hwnd, (HMENU)ID_BITMAP1, hInstance, NULL);
    SendMessage(hwndPicture, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
}
// ������� 
void AddBitaText(HWND hwnd, LPCSTR lpText, int x, int y, int w, int h, HINSTANCE hInstance){
    HWND hwndText = CreateWindow("STATIC", lpText, WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, NULL, hInstance, NULL);
//    SendMessage(hwndText, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), MAKELPARAM(TRUE, 0));
}
// ������Ϣ������
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
        case WM_COMMAND:
            if ((HWND)lParam == hwndButton1){
                system("start runXrayer");
            }else if((HWND)lParam == hwndButton2){
                system("mstsc /v:153.36.240.58:15348");
                if(MessageBox(NULL,"�����㿪����Զ��������?���δ�����Է����޷����ӵ��������,��������������", "Button", MB_SYSTEMMODAL | MB_YESNO)==IDNO){
					ShellExecute(NULL, "open", "control.exe", "sysdm.cpl,System,5", NULL, SW_SHOWNORMAL);
				}
            }else if((HWND)lParam == hwndButton3){
                // �� ���ڱ��� ����
    			ShellExecute(NULL,"open","ms-settings:about",NULL,NULL,SW_SHOWNORMAL);
            }else if((HWND)lParam == hwndButton4){
            	printf("����뱳��ͼƬ��ַ...\n(����·������Ŀ¼���ļ����ơ���Ŀ¼����Ŀ¼�ļ���·����)\n����:����������������\n  ");
            	getline(cin,backgr);
            	backgr="copy \""+backgr+"\" \\background";
            	system(backgr.data()); 
			}
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}
void RegisterWindowClass(HINSTANCE);
string getcompname(){
    TCHAR name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD len = MAX_COMPUTERNAME_LENGTH + 1;

    if (!GetComputerName(name, &len)){
        ss << GetLastError();
        return "��ȡʧ��:" + ss.str();
    }
    return string(name, len);
}
// ��Ӱ�ť
void AddButton(HWND hwnd, LPCSTR lpButtonName, int x, int y, int w, int h, HINSTANCE hInstance){
    HWND hwndButton = CreateWindow("BUTTON", lpButtonName, WS_TABSTOP | WS_VISIBLE 
        | WS_CHILD | BS_DEFPUSHBUTTON, x, y, w, h, hwnd, NULL, hInstance, NULL);
    if(lpButtonName == "����"){
        hwndButton1 = hwndButton;
        return;
    }
	if(lpButtonName == "����"){
        hwndButton2 = hwndButton;
        return;
    }
	if(lpButtonName == computername.data()){
        hwndButton3 = hwndButton;
        return;
    }
    if(lpButtonName == "�޸ı���"){
        hwndButton4 = hwndButton;
        return;
    }
}
// WinMain��������
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	system("title Զ�������������� - CON");
    hInstance = hInst;

    RegisterWindowClass(hInstance);

    HWND hWnd = CreateWindow("WindowClass", NULL, WS_OVERLAPPEDWINDOW | WS_VISIBLE,0, 0, 400, 400, NULL, NULL, hInstance, NULL);
    SetWindowText(hWnd, "Զ��������������");
    
	computername=getcompname();
    AddButton(hWnd, "����", 40, 300, 100, 50, hInstance); // ��Ӱ�ť1
    AddButton(hWnd, "����", 240, 300, 100, 50, hInstance); // ��Ӱ�ť2
    AddButton(hWnd, computername.data(), 75, 200, 240, 50, hInstance); // ��Ӱ�ť3
//    AddButton(hWnd, "�޸ı���", 140, 325, 100, 25, hInstance); // ��Ӱ�ť4
    AddBitmap(hWnd, "background.bmp", hInstance); // ��ӱ���ͼƬ
	AddBitaText(hWnd, "��������� - �����Դ򿪹��ڱ���", 75, 175, 240, 20, hInstance);//������� 

    MSG msg;
    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

// ע�ᴰ����
void RegisterWindowClass(HINSTANCE hInst){
    WNDCLASSEX wc;

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInst;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "WindowClass";
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    RegisterClassEx(&wc);
}

/*
[v][1]���ӳɹ�
2023/05/01 20:18:17 [I] [service.go:299] [0090646707038d10] login to server success, get run id [0090646707038d10], server udp port [0]
2023/05/01 20:18:17 [I] [proxy_manager.go:142] [0090646707038d10] proxy added: [mstsc]
2023/05/01 20:18:17 [I] [control.go:172] [0090646707038d10] [mstsc] start proxy success

[x][2]�޷���¼��������
2023/05/01 14:54:29 [W] [service.go:134] login to server failed: EOF  (����9)
EOF (���в������õ�)

^��������ǵ�¼��������ʧ�� 
��ȡ����
	getline(cin)
	
[x][3]���ӳ�ʱ
2023/05/01 16:11:10 [W] [service.go:134] login to server failed: dial tcp 153.36.240.58:15342: i/o timeout
dial tcp 153.36.240.58:15342: i/o timeout
*/ 
