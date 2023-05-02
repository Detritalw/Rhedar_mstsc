#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;

// 宏定义
#define ID_BUTTON1 1001
#define ID_BUTTON2 1002
#define ID_BITMAP1 1003

// 全局变量
HINSTANCE hInstance;
int n;
HWND hwndButton1,hwndButton2,hwndButton3,hwndButton4,hwndPicture;
stringstream ss;
string computername,Temp,backgr;
// 添加背景图片
void AddBitmap(HWND hwnd, LPCSTR szFileName, HINSTANCE hInstance){
    HBITMAP hBitmap=(HBITMAP)LoadImage(hInstance, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    if(hBitmap==NULL){
        MessageBox(NULL,"无法加载背景图片！\n请确保你设定的背景在目录下并能打开\n或者您可以...\n 1.更换背景图片地址\n 2.更换图片\n 3.检测图片是否能正常打开", "错误", MB_OK | MB_ICONERROR);
    }
    hwndPicture=CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP, 0, 0, 400, 400, hwnd, (HMENU)ID_BITMAP1, hInstance, NULL);
    SendMessage(hwndPicture, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
}
// 添加文字 
void AddBitaText(HWND hwnd, LPCSTR lpText, int x, int y, int w, int h, HINSTANCE hInstance){
    HWND hwndText = CreateWindow("STATIC", lpText, WS_VISIBLE | WS_CHILD, x, y, w, h, hwnd, NULL, hInstance, NULL);
//    SendMessage(hwndText, WM_SETFONT, (WPARAM)GetStockObject(DEFAULT_GUI_FONT), MAKELPARAM(TRUE, 0));
}
// 窗口消息处理函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg){
        case WM_COMMAND:
            if ((HWND)lParam == hwndButton1){
                system("start runXrayer");
            }else if((HWND)lParam == hwndButton2){
                system("mstsc /v:153.36.240.58:15348");
                if(MessageBox(NULL,"请问你开启了远程连接吗?如果未开启对方是无法连接到您这里的,请点击否来打开设置", "Button", MB_SYSTEMMODAL | MB_YESNO)==IDNO){
					ShellExecute(NULL, "open", "control.exe", "sysdm.cpl,System,5", NULL, SW_SHOWNORMAL);
				}
            }else if((HWND)lParam == hwndButton3){
                // 打开 关于本机 设置
    			ShellExecute(NULL,"open","ms-settings:about",NULL,NULL,SW_SHOWNORMAL);
            }else if((HWND)lParam == hwndButton4){
            	printf("请键入背景图片地址...\n(允许路径、本目录下文件名称、本目录下子目录文件短路径等)\n警告:如果输入的内容中有\n  ");
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
        return "获取失败:" + ss.str();
    }
    return string(name, len);
}
// 添加按钮
void AddButton(HWND hwnd, LPCSTR lpButtonName, int x, int y, int w, int h, HINSTANCE hInstance){
    HWND hwndButton = CreateWindow("BUTTON", lpButtonName, WS_TABSTOP | WS_VISIBLE 
        | WS_CHILD | BS_DEFPUSHBUTTON, x, y, w, h, hwnd, NULL, hInstance, NULL);
    if(lpButtonName == "开放"){
        hwndButton1 = hwndButton;
        return;
    }
	if(lpButtonName == "连接"){
        hwndButton2 = hwndButton;
        return;
    }
	if(lpButtonName == computername.data()){
        hwndButton3 = hwndButton;
        return;
    }
    if(lpButtonName == "修改背景"){
        hwndButton4 = hwndButton;
        return;
    }
}
// WinMain主程序函数
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	system("title 远程桌面韵连衫接 - CON");
    hInstance = hInst;

    RegisterWindowClass(hInstance);

    HWND hWnd = CreateWindow("WindowClass", NULL, WS_OVERLAPPEDWINDOW | WS_VISIBLE,0, 0, 400, 400, NULL, NULL, hInstance, NULL);
    SetWindowText(hWnd, "远程桌面韵连衫接");
    
	computername=getcompname();
    AddButton(hWnd, "开放", 40, 300, 100, 50, hInstance); // 添加按钮1
    AddButton(hWnd, "连接", 240, 300, 100, 50, hInstance); // 添加按钮2
    AddButton(hWnd, computername.data(), 75, 200, 240, 50, hInstance); // 添加按钮3
//    AddButton(hWnd, "修改背景", 140, 325, 100, 25, hInstance); // 添加按钮4
    AddBitmap(hWnd, "background.bmp", hInstance); // 添加背景图片
	AddBitaText(hWnd, "计算机名称 - 单击以打开关于本机", 75, 175, 240, 20, hInstance);//添加文字 

    MSG msg;
    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

// 注册窗口类
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
[v][1]连接成功
2023/05/01 20:18:17 [I] [service.go:299] [0090646707038d10] login to server success, get run id [0090646707038d10], server udp port [0]
2023/05/01 20:18:17 [I] [proxy_manager.go:142] [0090646707038d10] proxy added: [mstsc]
2023/05/01 20:18:17 [I] [control.go:172] [0090646707038d10] [mstsc] start proxy success

[x][2]无法登录到服务器
2023/05/01 14:54:29 [W] [service.go:134] login to server failed: EOF  (单词9)
EOF (这行才是有用的)

^这种情况是登录到服务器失败 
读取方法
	getline(cin)
	
[x][3]连接超时
2023/05/01 16:11:10 [W] [service.go:134] login to server failed: dial tcp 153.36.240.58:15342: i/o timeout
dial tcp 153.36.240.58:15342: i/o timeout
*/ 
