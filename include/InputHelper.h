#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

#include <string>
using namespace std;

class InputHelper {
public:
    static void xoaBoDem();

    static string nhapChuoiKhongRong(string thongBao);
    static string nhapHoTen(string thongBao);
    static string nhapNgaySinh(string thongBao);

    static int nhapSoNguyen(string thongBao, int nhoNhat, int lonNhat);
    static double nhapSoThuc(string thongBao, double nhoNhat, double lonNhat);
    static char nhapYesNo(string thongBao);

private:
    static bool hoTenHopLe(string hoTen);
    static bool ngaySinhHopLe(string ngaySinh);
};

#endif
