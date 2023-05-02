#include<bits/stdc++.h>
using namespace std;
string Temp;
int main(){
	freopen("pinginfo.out","w",stdout);
	system("tcping -n 1 153.36.240.58 15348");
	freopen("CON","w",stdout);
	freopen("pinginfo.out","r",stdin);
	for(int i=1;i<=;i++){
		getline(cin,Temp);
	}
	return 0;
}

/*
Probing 153.36.240.58:15348/tcp - Port is open - time=26.160ms

Ping statistics for 153.36.240.58:15348
     1 probes sent.
     1 successful, 0 failed.  (0.00% fail)
Approximate trip times in milli-seconds:
     Minimum = 26.160ms, Maximum = 26.160ms, Average = 26.160ms*/
/*
     参考翻译 
     
     探测153.36.240.58:15348/tcp - 端口已打开 - time=27.619ms
Ping统计153.36.240.58:15348
发送了1个探针。
1成功，0失败。（0.00%失败）
近似跳闸时间（毫秒）：
最小27.619ms，最大27.619ms、平均27.619ms
*/
