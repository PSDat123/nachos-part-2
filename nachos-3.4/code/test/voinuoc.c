#include "syscall.h"

int readInt(OpenFileID f) {
	int res = 0;
	char c;
	while (1) {
        if (ReadF(&c, 1, f) == 0) break;
        if (c >= '0' && c <= '9') res = res * 10 + c - '0';
        else break;
    }
	return res;
}

int main() {
    int n, v1, v2;
	char tmp;
    OpenFileID voi_nuoc, res;
    CreateF("result.txt");
    res = OpenF("result.txt", 0);
    n = -1;
    v1 = v2 = 0;
    while (1) {
        if (n == 0) break;
        Wait("voinuoc");
        voi_nuoc = OpenF("voinuoc.txt", 1);
        n = readInt(voi_nuoc);
        CloseF(voi_nuoc);
        if (n != 0) {
            if (v1 <= v2) {
                v1 += n;				
                if (res != -1) {
					tmp = n + '0';
					WriteF(&tmp , 1, res);
                    WriteF(" 1\t", 3, res);
				}
            } else {
                v2 += n;
                if (res != -1) {
					tmp = n + '0';
					WriteF(&tmp, 1, res);
                    WriteF(" 2\t", 3, res);
				}
            }
        }
        Signal("sinhvien");
    }
    if (res != -1) {
        WriteF("\n", 1, res);
        CloseF(res);
    }
    ExitProc(0);
}
