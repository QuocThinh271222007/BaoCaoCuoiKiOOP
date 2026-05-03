#ifndef DANH_SACH_NHAN_VIEN_H
#define DANH_SACH_NHAN_VIEN_H

#include "NhanVien.h"
#include <vector>
#include <string>
using namespace std;

class DanhSachNhanVien {
private:
private:
    vector<NhanVien*> danhSach;

    bool maNhanVienDaTonTai(string ma) const;
    bool maNhanVienDaTonTaiTruViTri(string ma, int viTriBoQua) const;
    int chonNhanVienTheoMa() const;

public:
    DanhSachNhanVien();
    ~DanhSachNhanVien();

    void themNhanVien(int loaiNhanVien);
    void xuatTatCa() const;
    void xuatTheoLoai(string loaiNhanVien) const;
    void timNhanVien() const;
    void suaNhanVien();
    void xoaNhanVien();
    void thongKeLuong() const;
};

#endif
