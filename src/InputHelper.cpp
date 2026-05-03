#include "../include/InputHelper.h"
#include <iostream>
#include <limits>
#include <cctype>
#include <cstdlib>
using namespace std;

void InputHelper::xoaBoDem() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string InputHelper::nhapChuoiKhongRong(string thongBao) {
    string giaTri;

    while (true) {
        cout << thongBao;
        getline(cin >> ws, giaTri);

        if (giaTri.empty()) {
            cout << "Loi: Khong duoc de trong. Vui long nhap lai.\n";
        } else {
            return giaTri;
        }
    }
}

bool InputHelper::hoTenHopLe(string hoTen) {
    if (hoTen.empty()) {
        return false;
    }

    for (int i = 0; i < (int)hoTen.length(); i++) {
        if (isdigit((unsigned char)hoTen[i])) {
            return false;
        }
    }

    return true;
}

string InputHelper::nhapHoTen(string thongBao) {
    string hoTen;

    while (true) {
        hoTen = nhapChuoiKhongRong(thongBao);

        if (hoTenHopLe(hoTen)) {
            return hoTen;
        }

        cout << "Loi: Ho ten khong duoc chua chu so.\n";
    }
}

bool InputHelper::ngaySinhHopLe(string ngaySinh) {
    if (ngaySinh.length() != 10) {
        return false;
    }

    if (ngaySinh[2] != '/' || ngaySinh[5] != '/') {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            continue;
        }

        if (!isdigit((unsigned char)ngaySinh[i])) {
            return false;
        }
    }

    int ngay = atoi(ngaySinh.substr(0, 2).c_str());
    int thang = atoi(ngaySinh.substr(3, 2).c_str());
    int nam = atoi(ngaySinh.substr(6, 4).c_str());

    if (nam < 1900 || nam > 2026) {
        return false;
    }

    if (thang < 1 || thang > 12) {
        return false;
    }

    int soNgayTrongThang[13] = {
        0, 31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    bool namNhuan = false;

    if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)) {
        namNhuan = true;
    }

    if (namNhuan) {
        soNgayTrongThang[2] = 29;
    }

    if (ngay < 1 || ngay > soNgayTrongThang[thang]) {
        return false;
    }

    return true;
}

string InputHelper::nhapNgaySinh(string thongBao) {
    string ngaySinh;

    while (true) {
        ngaySinh = nhapChuoiKhongRong(thongBao);

        if (ngaySinhHopLe(ngaySinh)) {
            return ngaySinh;
        }

        cout << "Loi: Ngay sinh phai dung dinh dang DD/MM/YYYY va phai hop le.\n";
    }
}

int InputHelper::nhapSoNguyen(string thongBao, int nhoNhat, int lonNhat) {
    int giaTri;

    while (true) {
        cout << thongBao;
        cin >> giaTri;

        if (cin.fail()) {
            xoaBoDem();
            cout << "Loi: Vui long nhap so nguyen.\n";
            continue;
        }

        if (giaTri < nhoNhat || giaTri > lonNhat) {
            xoaBoDem();
            cout << "Loi: Gia tri phai nam trong khoang ["
                 << nhoNhat << ", " << lonNhat << "].\n";
            continue;
        }

        xoaBoDem();
        return giaTri;
    }
}

double InputHelper::nhapSoThuc(string thongBao, double nhoNhat, double lonNhat) {
    double giaTri;

    while (true) {
        cout << thongBao;
        cin >> giaTri;

        if (cin.fail()) {
            xoaBoDem();
            cout << "Loi: Vui long nhap so.\n";
            continue;
        }

        if (giaTri < nhoNhat || giaTri > lonNhat) {
            xoaBoDem();
            cout << "Loi: Gia tri phai nam trong khoang ["
                 << nhoNhat << ", " << lonNhat << "].\n";
            continue;
        }

        xoaBoDem();
        return giaTri;
    }
}

char InputHelper::nhapYesNo(string thongBao) {
    char luaChon;

    while (true) {
        cout << thongBao;
        cin >> luaChon;
        xoaBoDem();

        luaChon = (char)tolower((unsigned char)luaChon);

        if (luaChon == 'y' || luaChon == 'n') {
            return luaChon;
        }

        cout << "Loi: Chi duoc nhap Y/y hoac N/n.\n";
    }
}
