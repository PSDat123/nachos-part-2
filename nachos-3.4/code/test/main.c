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
    int n, ret;
	char tmp;
    OpenFileID input, output, sinh_vien, res;
    SpaceID sinh_vien_proc;

    ret = CreateF("output.txt");
    if (ret == -1) 
		ExitProc(-1);
    ret = CreateSemaphore("sinhvien", 0);
    if (ret == -1) 
		ExitProc(-1);
    ret = CreateSemaphore("voinuoc", 0);
    if (ret == -1) 
		ExitProc(-1);
    input = OpenF("input.txt", 1);
    if (input == -1) 
		ExitProc(-1);
    output = OpenF("output.txt", 0);
    if (output == -1) {
        CloseF(input);
        ExitProc(-1);
    } 
	// Read first line
    n = readInt(input);
	
  	while (n--) {
		ret = CreateF("sinhvien.txt");
        if (ret == -1) {
            CloseF(input);
			CloseF(output);
            ExitProc(-1);
        }
		sinh_vien = OpenF("sinhvien.txt", 0);
        if (sinh_vien == -1) {
            CloseF(input);
			CloseF(output);
            ExitProc(-1);
        }
		// Read line and write to sinhvien.txt
		do {
			if (ReadF(&tmp, 1, input) == 0) break;
            WriteF(&tmp, 1, sinh_vien);
		} while(tmp != '\n');
		
		CloseF(sinh_vien);
        sinh_vien_proc = ExecProc("test/sinhvien");
        if (sinh_vien_proc != -1) ret = JoinProc(sinh_vien_proc);
		if (ret == -1) {
            CloseF(input);
            CloseF(output);
            ExitProc(-1);
        }
        res = OpenF("result.txt", 0);
        if (res == -1) {
            CloseF(input);
            CloseF(output);
            ExitProc(-1);
        }
		while (ReadF(&tmp, 1, res) != 0) {
		    WriteF(&tmp, 1, output);
		}
	    CloseF(res);
	}
	ExitProc(0);
}
