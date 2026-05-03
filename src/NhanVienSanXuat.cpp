#include "../include/NhanVienSanXuat.h"
#include "../include/InputHelper.h"
#include "../include/GiaoDien.h"
#include <iostream>
#include <iomanip>
using namespace std;

NhanVienSanXuat::NhanVienSanXuat() : NhanVien() {
    soSanPham = 0;
    donGiaSanPham = 0;
    thuong = 0;
}

NhanVienSanXuat::NhanVienSanXuat(string maNhanVien, string hoTen, string ngaySinh, string diaChi,
                                 int soSanPham, double donGiaSanPham, double thuong)
    : NhanVien(maNhanVien, hoTen, ngaySinh, diaChi) {
    this->soSanPham = soSanPham;
    this->donGiaSanPham = donGiaSanPham;
    this->thuong = thuong;
}

NhanVienSanXuat::NhanVienSanXuat(const NhanVienSanXuat& nv) : NhanVien(nv) {
    this->soSanPham = nv.soSanPham;
    this->donGiaSanPham = nv.donGiaSanPham;
    this->thuong = nv.thuong;
}

NhanVienSanXuat::~NhanVienSanXuat() {
}

int NhanVienSanXuat::getSoSanPham() const {
    return soSanPham;
}

double NhanVienSanXuat::getDonGiaSanPham() const {
    return donGiaSanPham;
}

double NhanVienSanXuat::getThuong() const {
    return thuong;
}

void NhanVienSanXuat::setSoSanPham(int soSanPham) {
    this->soSanPham = soSanPham;
}

void NhanVienSanXuat::setDonGiaSanPham(double donGiaSanPham) {
    this->donGiaSanPham = donGiaSanPham;
}

void NhanVienSanXuat::setThuong(double thuong) {
    this->thuong = thuong;
}

string NhanVienSanXuat::layLoaiNhanVien() const {
    return "NHAN VIEN SAN XUAT";
}

double NhanVienSanXuat::tinhLuong() const {
    double luong = soSanPham * donGiaSanPham + thuong;

    if (soSanPham >= 1000) {
        luong = luong + 1000000;
    }

    return luong;
}

void NhanVienSanXuat::nhapThongTinRieng() {
    cin >> *this;
}

void NhanVienSanXuat::xuatThongTinRieng() const {
    cout << *this;
}

void NhanVienSanXuat::suaThongTinRieng() {
    int luaChon;

    do {
        cout << "\n--- SUA THONG TIN NHAN VIEN SAN XUAT ---\n";
        cout << "1. So san pham\n";
        cout << "2. Don gia san pham\n";
        cout << "3. Thuong\n";
        cout << "0. Quay lai\n";

        luaChon = InputHelper::nhapSoNguyen("Nhap lua chon: ", 0, 3);

        switch (luaChon) {
            case 1:
                soSanPham = InputHelper::nhapSoNguyen("Nhap so san pham moi: ", 0, 1000000);
                break;

            case 2:
                donGiaSanPham = InputHelper::nhapSoThuc("Nhap don gia san pham moi: ", 1, 1000000000);
                break;

            case 3:
                thuong = InputHelper::nhapSoThuc("Nhap thuong moi: ", 0, 1000000000);
                break;

            case 0:
                break;
        }

        if (luaChon != 0) {
            GiaoDien::thongBaoThanhCong("Cap nhat thanh cong.");
        }
    } while (luaChon != 0);
}

istream& operator>>(istream& in, NhanVienSanXuat& nv) {
    nv.soSanPham = InputHelper::nhapSoNguyen("Nhap so san pham: ", 0, 1000000);
    nv.donGiaSanPham = InputHelper::nhapSoThuc("Nhap don gia san pham: ", 1, 1000000000);
    nv.thuong = InputHelper::nhapSoThuc("Nhap thuong: ", 0, 1000000000);

    return in;
}

ostream& operator<<(ostream& out, const NhanVienSanXuat& nv) {
    out << left;
    out << setw(24) << "So san pham" << ": " << nv.soSanPham << "\n";
    out << setw(24) << "Don gia san pham" << ": " << fixed << setprecision(0) << nv.donGiaSanPham << " VND\n";
    out << setw(24) << "Thuong" << ": " << fixed << setprecision(0) << nv.thuong << " VND\n";

    if (nv.soSanPham >= 1000) {
        out << setw(24) << "Thuong nang suat" << ": 1000000 VND\n";
    }

    return out;
}
