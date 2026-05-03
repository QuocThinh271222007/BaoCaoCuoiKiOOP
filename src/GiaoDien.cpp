#include "../include/GiaoDien.h"
#include <iostream>
#include <cstdlib>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

void GiaoDien::caiDatMauConsole() {
#ifdef _WIN32
    system("color 0B");

    // Chuyen CMD/Console sang UTF-8 de hien thi ky tu dac biet.
    // Vi du: █, ╚, ═, ║, ╔, ╗
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

void GiaoDien::doiMau(int mauChu, int mauNen) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, mauNen * 16 + mauChu);
#endif
}

void GiaoDien::datLaiMauMacDinh() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
#endif
}

void GiaoDien::xoaManHinh() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void GiaoDien::tamDung() {
    GiaoDien::doiMau(10); // Mau xanh la
    cout << "\nNhan ENTER de tiep tuc...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    GiaoDien::datLaiMauMacDinh();
}

void GiaoDien::inDongKe(char kyTu, int soLuong) {
    for (int i = 0; i < soLuong; i++) {
        cout << kyTu;
    }
    cout << "\n";
}

void GiaoDien::inBanner() {
    GiaoDien::doiMau(10); // Mau xanh la
    inDongKe('=', 120);
    cout << u8"  ██████╗ ██╗  ██╗██████╗ ████████╗              ███╗   ███╗ █████╗ ███╗   ██╗ █████╗  ██████╗ ███████╗██████╗ \n";
    cout << u8"  ╚════██╗██║  ██║╚════██╗╚══██╔══╝              ████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔════╝ ██╔════╝██╔══██╗\n";
    cout << u8"   █████╔╝███████║ █████╔╝   ██║       █████╗    ██╔████╔██║███████║██╔██╗ ██║███████║██║  ███╗█████╗  ██████╔╝\n";
    cout << u8"  ██╔═══╝ ██╔══██║ ╚═══██╗   ██║       ╚════╝    ██║╚██╔╝██║██╔══██║██║╚██╗██║██╔══██║██║   ██║██╔══╝  ██╔══██╗\n";
    cout << u8"  ███████╗██║  ██║██████╔╝   ██║                 ██║ ╚═╝ ██║██║  ██║██║ ╚████║██║  ██║╚██████╔╝███████╗██║  ██║\n";
    cout << u8"  ╚══════╝╚═╝  ╚═╝╚═════╝    ╚═╝                 ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝\n";

    cout << "\n";
    cout << "                           HE THONG QUAN LY NHAN SU - NHOM 2H3T\n";
    cout << "                            DO AN LAP TRINH HUONG DOI TUONG\n";

    inDongKe('=', 120);
    GiaoDien::datLaiMauMacDinh();
}

void GiaoDien::inTieuDeTrang(string tieuDe) {
    xoaManHinh();
    inBanner();
    cout << "\n";
    GiaoDien::doiMau(11); //Mau Cyan
    inDongKe('-', 120);
    cout << "  " << tieuDe << "\n";
    inDongKe('-', 120);
    GiaoDien::datLaiMauMacDinh();
    cout << "\n";
}

void GiaoDien::thongBaoThanhCong(string noiDung) {
    doiMau(10); // Mau xanh la
    cout << "[THANH CONG] " << noiDung << "\n";
    datLaiMauMacDinh();
}

void GiaoDien::thongBaoLoi(string noiDung) {
    doiMau(12); // Mau do
    cout << "[LOI] " << noiDung << "\n";
    datLaiMauMacDinh();
}

void GiaoDien::thongBaoChuY(string noiDung) {
    doiMau(6); // Mau vang Dam
    cout << "[CHU Y] " << noiDung << "\n";
    datLaiMauMacDinh();
}
