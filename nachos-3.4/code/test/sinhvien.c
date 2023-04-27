#include "syscall.h"

int main() {
    OpenFileID sinh_vien, voi_nuoc;
    SpaceID voi_nuoc_proc;
    char tmp;
    int ret;
    sinh_vien = OpenF("sinhvien.txt", 1);
    if (sinh_vien == -1) 
	ExitProc(-1);
    voi_nuoc_proc = ExecProc("test/voinuoc");
    if (voi_nuoc_proc == -1) {
        CloseF(sinh_vien);
        ExitProc(-1);
    }
    ret = -1;
    while (ret != 0) {
        ret = CreateF("voinuoc.txt");
        if (ret == -1) {
            CloseF(sinh_vien);
            ExitProc(-1);
        }
        voi_nuoc = OpenF("voinuoc.txt", 0);
        if (voi_nuoc == -1) {
            CloseF(sinh_vien);
            ExitProc(-1);
        }
        while (1) {
            if (ReadF(&tmp, 1, sinh_vien) == 0) {
                WriteF("0", 1, voi_nuoc);
                ret = 0;
                break;
            } else ret = -1;
            if (tmp == ' ' || tmp == '\n') break;
            WriteF(&tmp, 1, voi_nuoc);
        }
        CloseF(voi_nuoc);
        Signal("voinuoc");
        Wait("sinhvien");
    }
    ExitProc(0);
}
