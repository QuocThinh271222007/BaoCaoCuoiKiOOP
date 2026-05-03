#include "../include/QuanLy.h"
#include "../include/InputHelper.h"
#include "../include/GiaoDien.h"
#include <iostream>
#include <iomanip>
using namespace std;

QuanLy::QuanLy() : NhanVien() {
    luongCoBan = 0;
    luongTrachNhiem = 0;
    heSoHieuSuat = 1;
}

QuanLy::QuanLy(string maNhanVien, string hoTen, string ngaySinh, string diaChi,
               double luongCoBan, double luongTrachNhiem, double heSoHieuSuat)
    : NhanVien(maNhanVien, hoTen, ngaySinh, diaChi) {
    this->luongCoBan = luongCoBan;
    this->luongTrachNhiem = luongTrachNhiem;
    this->heSoHieuSuat = heSoHieuSuat;
}

QuanLy::QuanLy(const QuanLy& ql) : NhanVien(ql) {
    this->luongCoBan = ql.luongCoBan;
    this->luongTrachNhiem = ql.luongTrachNhiem;
    this->heSoHieuSuat = ql.heSoHieuSuat;
}

QuanLy::~QuanLy() {
}

double QuanLy::getLuongCoBan() const {
    return luongCoBan;
}

double QuanLy::getLuongTrachNhiem() const {
    return luongTrachNhiem;
}

double QuanLy::getHeSoHieuSuat() const {
    return heSoHieuSuat;
}

void QuanLy::setLuongCoBan(double luongCoBan) {
    this->luongCoBan = luongCoBan;
}

void QuanLy::setLuongTrachNhiem(double luongTrachNhiem) {
    this->luongTrachNhiem = luongTrachNhiem;
}

void QuanLy::setHeSoHieuSuat(double heSoHieuSuat) {
    this->heSoHieuSuat = heSoHieuSuat;
}

string QuanLy::layLoaiNhanVien() const {
    return "QUAN LY";
}

double QuanLy::tinhLuong() const {
    return luongCoBan * heSoHieuSuat + luongTrachNhiem;
}

void QuanLy::nhapThongTinRieng() {
    cin >> *this;
}

void QuanLy::xuatThongTinRieng() const {
    cout << *this;
}

void QuanLy::suaThongTinRieng() {
    int luaChon;

    do {
        cout << "\n--- SUA THONG TIN QUAN LY ---\n";
        cout << "1. Luong co ban\n";
        cout << "2. Luong trach nhiem\n";
        cout << "3. He so hieu suat\n";
        cout << "0. Quay lai\n";

        luaChon = InputHelper::nhapSoNguyen("Nhap lua chon: ", 0, 3);

        switch (luaChon) {
            case 1:
                luongCoBan = InputHelper::nhapSoThuc("Nhap luong co ban moi: ", 1, 1000000000);
                break;

            case 2:
                luongTrachNhiem = InputHelper::nhapSoThuc("Nhap luong trach nhiem moi: ", 0, 1000000000);
                break;

            case 3:
                heSoHieuSuat = InputHelper::nhapSoThuc("Nhap he so hieu suat moi (0.5 - 3.0): ", 0.5, 3.0);
                break;

            case 0:
                break;
        }

        if (luaChon != 0) {
            GiaoDien::thongBaoThanhCong("Cap nhat thanh cong.");
        }
    } while (luaChon != 0);
}

istream& operator>>(istream& in, QuanLy& ql) {
    ql.luongCoBan = InputHelper::nhapSoThuc("Nhap luong co ban: ", 1, 1000000000);
    ql.luongTrachNhiem = InputHelper::nhapSoThuc("Nhap luong trach nhiem: ", 0, 1000000000);
    ql.heSoHieuSuat = InputHelper::nhapSoThuc("Nhap he so hieu suat (0.5 - 3.0): ", 0.5, 3.0);

    return in;
}

ostream& operator<<(ostream& out, const QuanLy& ql) {
    out << left;
    out << setw(24) << "Luong co ban" << ": " << fixed << setprecision(0) << ql.luongCoBan << " VND\n";
    out << setw(24) << "Luong trach nhiem" << ": " << fixed << setprecision(0) << ql.luongTrachNhiem << " VND\n";
    out << setw(24) << "He so hieu suat" << ": " << fixed << setprecision(2) << ql.heSoHieuSuat << "\n";

    return out;
}
