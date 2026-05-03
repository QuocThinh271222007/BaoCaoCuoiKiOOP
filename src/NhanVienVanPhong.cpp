#include "../include/NhanVienVanPhong.h"
#include "../include/InputHelper.h"
#include "../include/GiaoDien.h"
#include <iostream>
#include <iomanip>
using namespace std;

NhanVienVanPhong::NhanVienVanPhong() : NhanVien() {
    soNgayLamViec = 0;
    soNgayLe = 0;
    donGiaNgay = 0;
    phuCap = 0;
    gioTangCaNgayThuong = 0;
    gioTangCaCuoiTuan = 0;
    gioTangCaLeTet = 0;
}

NhanVienVanPhong::NhanVienVanPhong(string maNhanVien, string hoTen, string ngaySinh, string diaChi,
                                   int soNgayLamViec, int soNgayLe, double donGiaNgay,
                                   double phuCap, double gioTangCaNgayThuong,
                                   double gioTangCaCuoiTuan, double gioTangCaLeTet)
    : NhanVien(maNhanVien, hoTen, ngaySinh, diaChi) {
    this->soNgayLamViec = soNgayLamViec;
    this->soNgayLe = soNgayLe;
    this->donGiaNgay = donGiaNgay;
    this->phuCap = phuCap;
    this->gioTangCaNgayThuong = gioTangCaNgayThuong;
    this->gioTangCaCuoiTuan = gioTangCaCuoiTuan;
    this->gioTangCaLeTet = gioTangCaLeTet;
}

NhanVienVanPhong::NhanVienVanPhong(const NhanVienVanPhong& nv) : NhanVien(nv) {
    this->soNgayLamViec = nv.soNgayLamViec;
    this->soNgayLe = nv.soNgayLe;
    this->donGiaNgay = nv.donGiaNgay;
    this->phuCap = nv.phuCap;
    this->gioTangCaNgayThuong = nv.gioTangCaNgayThuong;
    this->gioTangCaCuoiTuan = nv.gioTangCaCuoiTuan;
    this->gioTangCaLeTet = nv.gioTangCaLeTet;
}

NhanVienVanPhong::~NhanVienVanPhong() {
}

int NhanVienVanPhong::getSoNgayLamViec() const {
    return soNgayLamViec;
}

int NhanVienVanPhong::getSoNgayLe() const {
    return soNgayLe;
}

double NhanVienVanPhong::getDonGiaNgay() const {
    return donGiaNgay;
}

double NhanVienVanPhong::getPhuCap() const {
    return phuCap;
}

double NhanVienVanPhong::getGioTangCaNgayThuong() const {
    return gioTangCaNgayThuong;
}

double NhanVienVanPhong::getGioTangCaCuoiTuan() const {
    return gioTangCaCuoiTuan;
}

double NhanVienVanPhong::getGioTangCaLeTet() const {
    return gioTangCaLeTet;
}

void NhanVienVanPhong::setSoNgayLamViec(int soNgayLamViec) {
    this->soNgayLamViec = soNgayLamViec;
}

void NhanVienVanPhong::setSoNgayLe(int soNgayLe) {
    this->soNgayLe = soNgayLe;
}

void NhanVienVanPhong::setDonGiaNgay(double donGiaNgay) {
    this->donGiaNgay = donGiaNgay;
}

void NhanVienVanPhong::setPhuCap(double phuCap) {
    this->phuCap = phuCap;
}

void NhanVienVanPhong::setGioTangCaNgayThuong(double gioTangCaNgayThuong) {
    this->gioTangCaNgayThuong = gioTangCaNgayThuong;
}

void NhanVienVanPhong::setGioTangCaCuoiTuan(double gioTangCaCuoiTuan) {
    this->gioTangCaCuoiTuan = gioTangCaCuoiTuan;
}

void NhanVienVanPhong::setGioTangCaLeTet(double gioTangCaLeTet) {
    this->gioTangCaLeTet = gioTangCaLeTet;
}

string NhanVienVanPhong::layLoaiNhanVien() const {
    return "NHAN VIEN VAN PHONG";
}

double NhanVienVanPhong::tinhLuong() const {
    double luongNgayThuong = soNgayLamViec * donGiaNgay;
    double luongNgayLe = soNgayLe * donGiaNgay * 2;

    double luongTangCa = 0;
    luongTangCa = luongTangCa + gioTangCaNgayThuong * donGiaNgay / 8 * 1.5;
    luongTangCa = luongTangCa + gioTangCaCuoiTuan * donGiaNgay / 8 * 2;
    luongTangCa = luongTangCa + gioTangCaLeTet * donGiaNgay / 8 * 3;

    return luongNgayThuong + luongNgayLe + phuCap + luongTangCa;
}

void NhanVienVanPhong::nhapThongTinRieng() {
    cin >> *this;
}

void NhanVienVanPhong::xuatThongTinRieng() const {
    cout << *this;
}

void NhanVienVanPhong::suaThongTinRieng() {
    int luaChon;
    
    do {
        GiaoDien::doiMau(11); // Mau cyan
        cout << "\n--- SUA THONG TIN NHAN VIEN VAN PHONG ---\n";
        cout << "1. So ngay lam viec\n";
        cout << "2. So ngay le/tet\n";
        cout << "3. Don gia ngay\n";
        cout << "4. Phu cap\n";
        cout << "5. Gio tang ca ngay thuong\n";
        cout << "6. Gio tang ca cuoi tuan\n";
        cout << "7. Gio tang ca le/tet\n";
        cout << "0. Quay lai\n";
        luaChon = InputHelper::nhapSoNguyen("Nhap lua chon: ", 0, 7);
        GiaoDien::datLaiMauMacDinh();
        GiaoDien::doiMau(12); // Mau Do
        switch (luaChon) {
            case 1:
                soNgayLamViec = InputHelper::nhapSoNguyen("Nhap so ngay lam viec moi: ", 0, 31);
                break;

            case 2:
                soNgayLe = InputHelper::nhapSoNguyen("Nhap so ngay le/tet moi: ", 0, 31);
                break;

            case 3:
                donGiaNgay = InputHelper::nhapSoThuc("Nhap don gia ngay moi: ", 1, 1000000000);
                break;

            case 4:
                phuCap = InputHelper::nhapSoThuc("Nhap phu cap moi: ", 0, 1000000000);
                break;

            case 5:
                gioTangCaNgayThuong = InputHelper::nhapSoThuc("Nhap gio tang ca ngay thuong moi: ", 0, 300);
                break;

            case 6:
                gioTangCaCuoiTuan = InputHelper::nhapSoThuc("Nhap gio tang ca cuoi tuan moi: ", 0, 300);
                break;

            case 7:
                gioTangCaLeTet = InputHelper::nhapSoThuc("Nhap gio tang ca le/tet moi: ", 0, 300);
                break;

            case 0:
                break;
        }
        GiaoDien::datLaiMauMacDinh();
        if (luaChon != 0) {
            GiaoDien::doiMau(10); // Mau xanh la
            GiaoDien::thongBaoThanhCong("Cap nhat thanh cong.");
            GiaoDien::datLaiMauMacDinh();
        }
    } while (luaChon != 0);
    GiaoDien::datLaiMauMacDinh();
}

istream& operator>>(istream& in, NhanVienVanPhong& nv) {
    nv.soNgayLamViec = InputHelper::nhapSoNguyen("Nhap so ngay lam viec thuong: ", 0, 31);
    nv.soNgayLe = InputHelper::nhapSoNguyen("Nhap so ngay lam le/tet: ", 0, 31);
    nv.donGiaNgay = InputHelper::nhapSoThuc("Nhap don gia ngay: ", 1, 1000000000);
    nv.phuCap = InputHelper::nhapSoThuc("Nhap phu cap: ", 0, 1000000000);
    nv.gioTangCaNgayThuong = InputHelper::nhapSoThuc("Nhap gio tang ca ngay thuong: ", 0, 300);
    nv.gioTangCaCuoiTuan = InputHelper::nhapSoThuc("Nhap gio tang ca cuoi tuan: ", 0, 300);
    nv.gioTangCaLeTet = InputHelper::nhapSoThuc("Nhap gio tang ca le/tet: ", 0, 300);

    return in;
}

ostream& operator<<(ostream& out, const NhanVienVanPhong& nv) {
    out << left;
    GiaoDien::doiMau(11); // Mau cyan
    out << setw(24) << "So ngay lam viec" << ": " << nv.soNgayLamViec << "\n";
    out << setw(24) << "So ngay le/tet" << ": " << nv.soNgayLe << "\n";
    out << setw(24) << "Don gia ngay" << ": " << fixed << setprecision(0) << nv.donGiaNgay << " VND\n";
    out << setw(24) << "Phu cap" << ": " << fixed << setprecision(0) << nv.phuCap << " VND\n";
    out << setw(24) << "Tang ca ngay thuong" << ": " << nv.gioTangCaNgayThuong << " gio\n";
    out << setw(24) << "Tang ca cuoi tuan" << ": " << nv.gioTangCaCuoiTuan << " gio\n";
    out << setw(24) << "Tang ca le/tet" << ": " << nv.gioTangCaLeTet << " gio\n";
    GiaoDien::datLaiMauMacDinh();
    return out;
}
