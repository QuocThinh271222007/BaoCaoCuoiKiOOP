#ifndef NHAN_VIEN_SAN_XUAT_H
#define NHAN_VIEN_SAN_XUAT_H

#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien {
private:
    int soSanPham;
    double donGiaSanPham;
    double thuong;

public:
    NhanVienSanXuat();
    NhanVienSanXuat(string maNhanVien, string hoTen, string ngaySinh, string diaChi,
                    int soSanPham, double donGiaSanPham, double thuong);
    NhanVienSanXuat(const NhanVienSanXuat& nv);
    ~NhanVienSanXuat();

    int getSoSanPham() const;
    double getDonGiaSanPham() const;
    double getThuong() const;

    void setSoSanPham(int soSanPham);
    void setDonGiaSanPham(double donGiaSanPham);
    void setThuong(double thuong);

    string layLoaiNhanVien() const;
    double tinhLuong() const;

    void nhapThongTinRieng();
    void xuatThongTinRieng() const;
    void suaThongTinRieng();

    friend istream& operator>>(istream& in, NhanVienSanXuat& nv);
    friend ostream& operator<<(ostream& out, const NhanVienSanXuat& nv);
};

#endif
