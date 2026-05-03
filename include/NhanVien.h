#ifndef NHAN_VIEN_H
#define NHAN_VIEN_H

#include <iostream>
#include <string>
using namespace std;

class NhanVien {
private:
    string maNhanVien;
    string hoTen;
    string ngaySinh;
    string diaChi;

public:
    NhanVien();
    NhanVien(string maNhanVien, string hoTen, string ngaySinh, string diaChi);
    NhanVien(const NhanVien& nv);
    virtual ~NhanVien();

    string getMaNhanVien() const;
    string getHoTen() const;
    string getNgaySinh() const;
    string getDiaChi() const;

    void setMaNhanVien(string maNhanVien);
    void setHoTen(string hoTen);
    void setNgaySinh(string ngaySinh);
    void setDiaChi(string diaChi);

    virtual string layLoaiNhanVien() const = 0;
    virtual double tinhLuong() const = 0;

    virtual void nhap();
    virtual void xuat() const;

    virtual void nhapThongTinRieng() = 0;
    virtual void xuatThongTinRieng() const = 0;
    virtual void suaThongTinRieng() = 0;

    void suaThongTinChung();
    void hienThiThongTin() const;
};

#endif
