#ifndef NHAN_VIEN_VAN_PHONG_H
#define NHAN_VIEN_VAN_PHONG_H

#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;
    int soNgayLe;
    double donGiaNgay;
    double phuCap;
    double gioTangCaNgayThuong;
    double gioTangCaCuoiTuan;
    double gioTangCaLeTet;

public:
    NhanVienVanPhong();
    NhanVienVanPhong(string maNhanVien, string hoTen, string ngaySinh, string diaChi,
                     int soNgayLamViec, int soNgayLe, double donGiaNgay,
                     double phuCap, double gioTangCaNgayThuong,
                     double gioTangCaCuoiTuan, double gioTangCaLeTet);
    NhanVienVanPhong(const NhanVienVanPhong& nv);
    ~NhanVienVanPhong();

    int getSoNgayLamViec() const;
    int getSoNgayLe() const;
    double getDonGiaNgay() const;
    double getPhuCap() const;
    double getGioTangCaNgayThuong() const;
    double getGioTangCaCuoiTuan() const;
    double getGioTangCaLeTet() const;

    void setSoNgayLamViec(int soNgayLamViec);
    void setSoNgayLe(int soNgayLe);
    void setDonGiaNgay(double donGiaNgay);
    void setPhuCap(double phuCap);
    void setGioTangCaNgayThuong(double gioTangCaNgayThuong);
    void setGioTangCaCuoiTuan(double gioTangCaCuoiTuan);
    void setGioTangCaLeTet(double gioTangCaLeTet);

    string layLoaiNhanVien() const;
    double tinhLuong() const;

    void nhapThongTinRieng();
    void xuatThongTinRieng() const;
    void suaThongTinRieng();

    friend istream& operator>>(istream& in, NhanVienVanPhong& nv);
    friend ostream& operator<<(ostream& out, const NhanVienVanPhong& nv);
};

#endif
