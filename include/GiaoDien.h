#ifndef GIAO_DIEN_H
#define GIAO_DIEN_H

#include <string>
using namespace std;

class GiaoDien {
public:
    static void caiDatMauConsole();
    static void xoaManHinh();
    static void tamDung();

    static void doiMau(int mauChu, int mauNen = 0);
    static void datLaiMauMacDinh();

    static void inDongKe(char kyTu, int soLuong);
    static void inBanner();
    static void inTieuDeTrang(string tieuDe);

    static void thongBaoThanhCong(string noiDung);
    static void thongBaoLoi(string noiDung);
    static void thongBaoChuY(string noiDung);
};

#endif