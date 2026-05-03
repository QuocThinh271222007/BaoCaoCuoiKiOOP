#include "../include/Menu.h"
#include "../include/DanhSachNhanVien.h"
#include "../include/InputHelper.h"
#include "../include/GiaoDien.h"
#include <iostream>
using namespace std;

void inMenuChinh() {
    GiaoDien::doiMau(11); // Mau cyan
    GiaoDien::inTieuDeTrang("MENU CHINH");
    GiaoDien::datLaiMauMacDinh();
    GiaoDien::doiMau(9); // Mau xanh duong
    cout << "1. Them nhan vien van phong\n";
    cout << "2. Them nhan vien san xuat\n";
    cout << "3. Them quan ly\n";
    cout << "\n";
    GiaoDien::datLaiMauMacDinh();
    GiaoDien::doiMau(6); // Mau Vang
    cout << "4. Xuat tat ca nhan vien\n";
    cout << "5. Xuat nhan vien van phong\n";
    cout << "6. Xuat nhan vien san xuat\n";
    cout << "7. Xuat quan ly\n";
    cout << "\n";
    GiaoDien::datLaiMauMacDinh();
    GiaoDien::doiMau(13); // Mau tim
    cout << "8. Tim nhan vien theo ma\n";
    cout << "9. Sua nhan vien\n";
    cout << "10. Xoa nhan vien\n";
    cout << "11. Thong ke luong\n";
    cout << "\n";
    GiaoDien::datLaiMauMacDinh();
    GiaoDien::doiMau(4); // Mau Do
    cout << "0. Thoat\n";
    GiaoDien::datLaiMauMacDinh();
    GiaoDien::doiMau(11); // Mau cyan
    GiaoDien::inDongKe('-', 72);
    GiaoDien::datLaiMauMacDinh();
}

void chayChuongTrinh() {
    DanhSachNhanVien danhSach;
    int luaChon;

    do {
        inMenuChinh();
        GiaoDien::doiMau(11); // Mau cyan
        luaChon = InputHelper::nhapSoNguyen("Nhap lua chon: ", 0, 11);
        GiaoDien::datLaiMauMacDinh();
        switch (luaChon) {
            case 1:
                GiaoDien::inTieuDeTrang("THEM NHAN VIEN VAN PHONG");
                danhSach.themNhanVien(1);
                GiaoDien::tamDung();
                break;

            case 2:
                GiaoDien::inTieuDeTrang("THEM NHAN VIEN SAN XUAT");
                danhSach.themNhanVien(2);
                GiaoDien::tamDung();
                break;

            case 3:
                GiaoDien::inTieuDeTrang("THEM QUAN LY");
                danhSach.themNhanVien(3);
                GiaoDien::tamDung();
                break;

            case 4:
                GiaoDien::inTieuDeTrang("DANH SACH TAT CA NHAN VIEN");
                danhSach.xuatTatCa();
                GiaoDien::tamDung();
                break;

            case 5:
                GiaoDien::inTieuDeTrang("DANH SACH NHAN VIEN VAN PHONG");
                danhSach.xuatTheoLoai("NHAN VIEN VAN PHONG");
                GiaoDien::tamDung();
                break;

            case 6:
                GiaoDien::inTieuDeTrang("DANH SACH NHAN VIEN SAN XUAT");
                danhSach.xuatTheoLoai("NHAN VIEN SAN XUAT");
                GiaoDien::tamDung();
                break;

            case 7:
                GiaoDien::inTieuDeTrang("DANH SACH QUAN LY");
                danhSach.xuatTheoLoai("QUAN LY");
                GiaoDien::tamDung();
                break;

            case 8:
                GiaoDien::inTieuDeTrang("TIM NHAN VIEN THEO MA");
                danhSach.timNhanVien();
                GiaoDien::tamDung();
                break;

            case 9:
                GiaoDien::inTieuDeTrang("SUA THONG TIN NHAN VIEN");
                danhSach.suaNhanVien();
                GiaoDien::tamDung();
                break;

            case 10:
                GiaoDien::inTieuDeTrang("XOA NHAN VIEN");
                danhSach.xoaNhanVien();
                GiaoDien::tamDung();
                break;

            case 11:
                GiaoDien::inTieuDeTrang("THONG KE LUONG");
                danhSach.thongKeLuong();
                GiaoDien::tamDung();
                break;

            case 0:
                GiaoDien::inTieuDeTrang("TAM BIET");
                cout << "Cam on ban da su dung chuong trinh cua nhom 2H3T!\n";
                break;
        }

    } while (luaChon != 0);
}
