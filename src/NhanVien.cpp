#include "../include/NhanVien.h"
#include "../include/InputHelper.h"
#include "../include/GiaoDien.h"
#include <iostream>
#include <iomanip>
using namespace std;

NhanVien::NhanVien() {
    this->maNhanVien = "";
    this->hoTen = "";
    this->ngaySinh = "";
    this->diaChi = "";
}

NhanVien::NhanVien(string maNhanVien, string hoTen, string ngaySinh, string diaChi) {
    this->maNhanVien = maNhanVien;
    this->hoTen = hoTen;
    this->ngaySinh = ngaySinh;
    this->diaChi = diaChi;
}

NhanVien::NhanVien(const NhanVien& nv) {
    this->maNhanVien = nv.maNhanVien;
    this->hoTen = nv.hoTen;
    this->ngaySinh = nv.ngaySinh;
    this->diaChi = nv.diaChi;
}

NhanVien::~NhanVien() {
}

string NhanVien::getMaNhanVien() const {
    return maNhanVien;
}

string NhanVien::getHoTen() const {
    return hoTen;
}

string NhanVien::getNgaySinh() const {
    return ngaySinh;
}

string NhanVien::getDiaChi() const {
    return diaChi;
}

void NhanVien::setMaNhanVien(string maNhanVien) {
    this->maNhanVien = maNhanVien;
}

void NhanVien::setHoTen(string hoTen) {
    this->hoTen = hoTen;
}

void NhanVien::setNgaySinh(string ngaySinh) {
    this->ngaySinh = ngaySinh;
}

void NhanVien::setDiaChi(string diaChi) {
    this->diaChi = diaChi;
}

void NhanVien::nhap() {
    GiaoDien::doiMau(11); // Mau cyan
    cout << "\n--- THONG TIN CHUNG ---\n";
    maNhanVien = InputHelper::nhapChuoiKhongRong("Nhap ma nhan vien: ");
    hoTen = InputHelper::nhapHoTen("Nhap ho ten: ");
    ngaySinh = InputHelper::nhapNgaySinh("Nhap ngay sinh (DD/MM/YYYY): ");
    diaChi = InputHelper::nhapChuoiKhongRong("Nhap dia chi: ");

    cout << "\n--- THONG TIN RIENG ---\n";
    nhapThongTinRieng();
    GiaoDien::datLaiMauMacDinh();
}

void NhanVien::xuat() const {
    GiaoDien::doiMau(3); // Mau xanh bien
    cout << left;
    cout << setw(24) << "Ma nhan vien" << ": " << maNhanVien << "\n";
    cout << setw(24) << "Ho ten" << ": " << hoTen << "\n";
    cout << setw(24) << "Ngay sinh" << ": " << ngaySinh << "\n";
    cout << setw(24) << "Dia chi" << ": " << diaChi << "\n";
    GiaoDien::datLaiMauMacDinh();
}

void NhanVien::hienThiThongTin() const {
    GiaoDien::inDongKe('-', 72);
    cout << "LOAI NHAN VIEN: " << layLoaiNhanVien() << "\n";
    GiaoDien::inDongKe('-', 72);

    xuat();
    xuatThongTinRieng();
    GiaoDien::doiMau(10); // Mau xanh la
    cout << left << setw(24) << "Luong" << ": "
         << fixed << setprecision(0) << tinhLuong() << " VND\n";
    GiaoDien::datLaiMauMacDinh();
}

void NhanVien::suaThongTinChung() {
    int luaChon;

    do {
        GiaoDien::doiMau(11); // Mau cyan
        cout << "\n--- SUA THONG TIN CHUNG ---\n";
        cout << "1. Sua ho ten\n";
        cout << "2. Sua ngay sinh\n";
        cout << "3. Sua dia chi\n";
        cout << "0. Quay lai\n";
        GiaoDien::datLaiMauMacDinh();
        GiaoDien::doiMau(12); // Mau do
        luaChon = InputHelper::nhapSoNguyen("Nhap lua chon: ", 0, 3);
        GiaoDien::datLaiMauMacDinh();
        switch (luaChon) {
            case 1:
                hoTen = InputHelper::nhapHoTen("Nhap ho ten moi: ");
                GiaoDien::thongBaoThanhCong("Cap nhat ho ten thanh cong.");
                break;

            case 2:
                ngaySinh = InputHelper::nhapNgaySinh("Nhap ngay sinh moi (DD/MM/YYYY): ");
                GiaoDien::thongBaoThanhCong("Cap nhat ngay sinh thanh cong.");
                break;

            case 3:
                diaChi = InputHelper::nhapChuoiKhongRong("Nhap dia chi moi: ");
                GiaoDien::thongBaoThanhCong("Cap nhat dia chi thanh cong.");
                break;

            case 0:
                break;
        }
    } while (luaChon != 0);
}
