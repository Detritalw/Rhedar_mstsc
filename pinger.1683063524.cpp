#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("pinginfo.out","w",stdout);
	system("tcping -n 1 153.36.240.58 15348");
	
	return 0;
}

/*
(1      2                       3 4            5 6
Probing 153.36.240.58:15348/tcp - Port is open - time=27.619ms  x6
(1    2          3   4)
Ping statistics for 153.36.240.58:15348   x10
(	 1  2     3)
     1 probes sent.   x13
     (1 2          3  4       5      6)
     1 successful, 0 failed.  (0.00% fail)  x19
     (1     2      3    4  5)
Approximate trip times in milli-seconds: x24
	(1		 2  3        4		 5  6		 7		 8	9)
     Minimum = 27.619ms, Maximum = 27.619ms, Average = 27.619ms   x33*/
/*
     �ο����� 
     
     ̽��153.36.240.58:15348/tcp - �˿��Ѵ� - time=27.619ms
Pingͳ��153.36.240.58:15348
������1��̽�롣
1�ɹ���0ʧ�ܡ���0.00%ʧ�ܣ�
������բʱ�䣨���룩��
��С27.619ms�����27.619ms��ƽ��27.619ms
*/
