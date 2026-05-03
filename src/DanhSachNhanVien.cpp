#include "../include/DanhSachNhanVien.h"
#include "../include/NhanVienVanPhong.h"
#include "../include/NhanVienSanXuat.h"
#include "../include/QuanLy.h"
#include "../include/InputHelper.h"
#include "../include/GiaoDien.h"
#include <iostream>
#include <iomanip>
using namespace std;

DanhSachNhanVien::DanhSachNhanVien() {
}

DanhSachNhanVien::~DanhSachNhanVien() {
    for (int i = 0; i < (int)danhSach.size(); i++) {
        delete danhSach[i];
    }

    danhSach.clear();
}

bool DanhSachNhanVien::maNhanVienDaTonTai(string ma) const {
    for (int i = 0; i < (int)danhSach.size(); i++) {
        if (danhSach[i]->getMaNhanVien() == ma) {
            return true;
        }
    }

    return false;
}
bool DanhSachNhanVien::maNhanVienDaTonTaiTruViTri(string ma, int viTriBoQua) const {
    for (int i = 0; i < (int)danhSach.size(); i++) {
        if (i == viTriBoQua) {
            continue;
        }

        if (danhSach[i]->getMaNhanVien() == ma) {
            return true;
        }
    }

    return false;
}
void DanhSachNhanVien::themNhanVien(int loaiNhanVien) {
    NhanVien* nhanVienMoi = NULL;

    if (loaiNhanVien == 1) {
        nhanVienMoi = new NhanVienVanPhong();
    } else if (loaiNhanVien == 2) {
        nhanVienMoi = new NhanVienSanXuat();
    } else if (loaiNhanVien == 3) {
        nhanVienMoi = new QuanLy();
    } else {
        return;
    }

    nhanVienMoi->nhap();

    while (maNhanVienDaTonTai(nhanVienMoi->getMaNhanVien())) {
        GiaoDien::thongBaoLoi("Ma nhan vien da ton tai.");
        string maMoi = InputHelper::nhapChuoiKhongRong("Nhap ma nhan vien khac: ");
        nhanVienMoi->setMaNhanVien(maMoi);
    }

    danhSach.push_back(nhanVienMoi);
    GiaoDien::thongBaoThanhCong("Them nhan vien thanh cong.");
}

void DanhSachNhanVien::xuatTatCa() const {
    GiaoDien::doiMau(9); // Mau Do
    if (danhSach.empty()) {
        GiaoDien::thongBaoChuY("Danh sach nhan vien dang rong.");
        return;
    }

    cout << "Tong so nhan vien: " << danhSach.size() << "\n\n";

    for (int i = 0; i < (int)danhSach.size(); i++) {
        GiaoDien::doiMau(10); // Mau xanh la
        cout << "Ho so thu " << i + 1 << ":\n";
        danhSach[i]->hienThiThongTin();
        cout << "\n";
        GiaoDien::datLaiMauMacDinh();
    }
    GiaoDien::datLaiMauMacDinh();
}

void DanhSachNhanVien::xuatTheoLoai(string loaiNhanVien) const {
    GiaoDien::doiMau(10); // Mau xanh la
    bool coDuLieu = false;
    int stt = 1;

    for (int i = 0; i < (int)danhSach.size(); i++) {
        if (danhSach[i]->layLoaiNhanVien() == loaiNhanVien) {
            cout << "Ho so thu " << stt << ":\n";
            danhSach[i]->hienThiThongTin();
            cout << "\n";

            coDuLieu = true;
            stt++;
        }
    }

    if (!coDuLieu) {
        GiaoDien::thongBaoChuY("Khong co nhan vien thuoc loai nay.");
    }
    GiaoDien::datLaiMauMacDinh();
}

int DanhSachNhanVien::chonNhanVienTheoMa() const {
    GiaoDien::doiMau(12); // Mau do
    if (danhSach.empty()) {
        GiaoDien::thongBaoChuY("Danh sach dang rong.");
        return -1;
    }
    GiaoDien::datLaiMauMacDinh();
    GiaoDien::doiMau(11); // Mau cyan
    string tuKhoa = InputHelper::nhapChuoiKhongRong("Nhap ma nhan vien hoac tu khoa: ");
    vector<int> viTriPhuHop;
    for (int i = 0; i < (int)danhSach.size(); i++) {
        string ma = danhSach[i]->getMaNhanVien();

        if (ma.find(tuKhoa) != string::npos) {
            viTriPhuHop.push_back(i);
        }
    }
    GiaoDien::datLaiMauMacDinh();

    if (viTriPhuHop.empty()) {
        GiaoDien::doiMau(12); // Mau do
        GiaoDien::thongBaoLoi("Khong tim thay nhan vien phu hop.");
        return -1;
        
    }

    if (viTriPhuHop.size() == 1) {
        return viTriPhuHop[0];
    }
    GiaoDien::doiMau(5); // Mau tim
    cout << "\nTim thay nhieu ket qua:\n";
    GiaoDien::datLaiMauMacDinh();
    GiaoDien::doiMau(3); // Mau Xanh Dam
    GiaoDien::inDongKe('-', 72);
    cout << left
         << setw(6) << "STT"
         << setw(18) << "Ma NV"
         << setw(28) << "Ho ten"
         << setw(22) << "Loai"
         << "\n";
    GiaoDien::inDongKe('-', 72);
    GiaoDien::datLaiMauMacDinh();
    GiaoDien::doiMau(10); // Mau xanh la
    for (int i = 0; i < (int)viTriPhuHop.size(); i++) {
        int viTri = viTriPhuHop[i];
        cout << left
             << setw(6) << i + 1
             << setw(18) << danhSach[viTri]->getMaNhanVien()
             << setw(28) << danhSach[viTri]->getHoTen()
             << setw(22) << danhSach[viTri]->layLoaiNhanVien()
             << "\n";
    }
    GiaoDien::datLaiMauMacDinh();
    GiaoDien::doiMau(3); // Mau Xanh Dam
    GiaoDien::inDongKe('-', 72);
    GiaoDien::datLaiMauMacDinh();
    GiaoDien::doiMau(12); // Mau do
    cout << "Nhap 0 de huy.\n";
    GiaoDien::datLaiMauMacDinh();
    GiaoDien::doiMau(11); // Mau cyan
    int luaChon = InputHelper::nhapSoNguyen("Chon nhan vien: ", 0, (int)viTriPhuHop.size());

    if (luaChon == 0) {
        return -1;
    }

    return viTriPhuHop[luaChon - 1];
    GiaoDien::datLaiMauMacDinh();
}

void DanhSachNhanVien::timNhanVien() const {
    int viTri = chonNhanVienTheoMa();

    if (viTri == -1) {
        return;
    }
    GiaoDien::doiMau(10); // Mau xanh la
    cout << "\nKet qua tim kiem:\n";
    danhSach[viTri]->hienThiThongTin();
    GiaoDien::datLaiMauMacDinh();
}

void DanhSachNhanVien::suaNhanVien() {
    int viTri = chonNhanVienTheoMa();

    if (viTri == -1) {
        return;
    }

    int luaChon;

    do {
        GiaoDien::doiMau(5); // Mau tim
        cout << "\n--- MENU SUA NHAN VIEN ---\n";
        cout << "Nhan vien dang sua: "
             << danhSach[viTri]->getMaNhanVien()
             << " - "
             << danhSach[viTri]->getHoTen()
             << "\n";

        cout << "1. Sua thong tin chung\n";
        cout << "2. Sua thong tin rieng\n";
        cout << "3. Nhap lai toan bo thong tin\n";
        cout << "0. Quay lai\n";
        GiaoDien::datLaiMauMacDinh();
        GiaoDien::doiMau(12); // Mau Do
        luaChon = InputHelper::nhapSoNguyen("Nhap lua chon: ", 0, 3);
        GiaoDien::datLaiMauMacDinh();
        switch (luaChon) {
            case 1:
                danhSach[viTri]->suaThongTinChung();
                break;

            case 2:
                danhSach[viTri]->suaThongTinRieng();
                break;

            case 3: {
                string maCu = danhSach[viTri]->getMaNhanVien();

                danhSach[viTri]->nhap();

                string maMoi = danhSach[viTri]->getMaNhanVien();

                if (maMoi != maCu && maNhanVienDaTonTaiTruViTri(maMoi, viTri)) {
                    GiaoDien::thongBaoLoi("Ma moi bi trung. He thong giu lai ma cu.");
                    danhSach[viTri]->setMaNhanVien(maCu);
                    GiaoDien::thongBaoChuY("Cac thong tin khac van duoc cap nhat.");
                } else {
                    GiaoDien::thongBaoThanhCong("Nhap lai thong tin thanh cong.");
                }

                break;
            }

            case 0:
                break;
        }
    } while (luaChon != 0);
}

void DanhSachNhanVien::xoaNhanVien() {
    int viTri = chonNhanVienTheoMa();

    if (viTri == -1) {
        return;
    }

    cout << "\nNhan vien sap xoa:\n";
    danhSach[viTri]->hienThiThongTin();

    char xacNhan = InputHelper::nhapYesNo("Ban co chac muon xoa? (Y/N): ");

    if (xacNhan == 'y') {
        delete danhSach[viTri];
        danhSach.erase(danhSach.begin() + viTri);

        GiaoDien::thongBaoThanhCong("Xoa nhan vien thanh cong.");
    } else {
        GiaoDien::thongBaoChuY("Da huy thao tac xoa.");
    }
}

void DanhSachNhanVien::thongKeLuong() const {
    if (danhSach.empty()) {
        GiaoDien::thongBaoChuY("Danh sach rong, khong co du lieu thong ke.");
        return;
    }

    double tongLuong = 0;
    double luongCaoNhat = danhSach[0]->tinhLuong();
    double luongThapNhat = danhSach[0]->tinhLuong();

    int viTriLuongCaoNhat = 0;
    int viTriLuongThapNhat = 0;

    int soNhanVienVanPhong = 0;
    int soNhanVienSanXuat = 0;
    int soQuanLy = 0;

    for (int i = 0; i < (int)danhSach.size(); i++) {
        double luong = danhSach[i]->tinhLuong();
        tongLuong = tongLuong + luong;

        if (luong > luongCaoNhat) {
            luongCaoNhat = luong;
            viTriLuongCaoNhat = i;
        }

        if (luong < luongThapNhat) {
            luongThapNhat = luong;
            viTriLuongThapNhat = i;
        }

        if (danhSach[i]->layLoaiNhanVien() == "NHAN VIEN VAN PHONG") {
            soNhanVienVanPhong++;
        } else if (danhSach[i]->layLoaiNhanVien() == "NHAN VIEN SAN XUAT") {
            soNhanVienSanXuat++;
        } else if (danhSach[i]->layLoaiNhanVien() == "QUAN LY") {
            soQuanLy++;
        }
    }
    GiaoDien::doiMau(5); // Mau Tim
    GiaoDien::inDongKe('=', 72);
    cout << "                    BANG THONG KE LUONG\n";
    GiaoDien::inDongKe('=', 72);

    cout << left << setw(32) << "Tong so nhan vien" << ": " << danhSach.size() << "\n";
    cout << left << setw(32) << "Nhan vien van phong" << ": " << soNhanVienVanPhong << "\n";
    cout << left << setw(32) << "Nhan vien san xuat" << ": " << soNhanVienSanXuat << "\n";
    cout << left << setw(32) << "Quan ly" << ": " << soQuanLy << "\n";

    GiaoDien::inDongKe('-', 72);

    cout << left << setw(32) << "Tong luong" << ": "
         << fixed << setprecision(0) << tongLuong << " VND\n";

    cout << left << setw(32) << "Luong trung binh" << ": "
         << fixed << setprecision(0) << tongLuong / danhSach.size() << " VND\n";

    GiaoDien::inDongKe('-', 72);

    cout << "Luong cao nhat : "
         << danhSach[viTriLuongCaoNhat]->getMaNhanVien()
         << " - "
         << danhSach[viTriLuongCaoNhat]->getHoTen()
         << " - "
         << fixed << setprecision(0) << luongCaoNhat
         << " VND\n";

    cout << "Luong thap nhat: "
         << danhSach[viTriLuongThapNhat]->getMaNhanVien()
         << " - "
         << danhSach[viTriLuongThapNhat]->getHoTen()
         << " - "
         << fixed << setprecision(0) << luongThapNhat
         << " VND\n";

    GiaoDien::inDongKe('=', 72);
    GiaoDien::datLaiMauMacDinh();
}
