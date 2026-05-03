#ifndef QUAN_LY_H
#define QUAN_LY_H

#include "NhanVien.h"

class QuanLy : public NhanVien {
private:
    double luongCoBan;
    double luongTrachNhiem;
    double heSoHieuSuat;

public:
    QuanLy();
    QuanLy(string maNhanVien, string hoTen, string ngaySinh, string diaChi,
           double luongCoBan, double luongTrachNhiem, double heSoHieuSuat);
    QuanLy(const QuanLy& ql);
    ~QuanLy();

    double getLuongCoBan() const;
    double getLuongTrachNhiem() const;
    double getHeSoHieuSuat() const;

    void setLuongCoBan(double luongCoBan);
    void setLuongTrachNhiem(double luongTrachNhiem);
    void setHeSoHieuSuat(double heSoHieuSuat);

    string layLoaiNhanVien() const;
    double tinhLuong() const;

    void nhapThongTinRieng();
    void xuatThongTinRieng() const;
    void suaThongTinRieng();

    friend istream& operator>>(istream& in, QuanLy& ql);
    friend ostream& operator<<(ostream& out, const QuanLy& ql);
};

#endif
