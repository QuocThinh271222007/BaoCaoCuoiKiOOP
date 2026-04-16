#include <bits/stdc++.h>
using namespace std;

const float DON_GIA_TANG_CA = 50000.0f;

// ========================= LOP NHAN VIEN =========================
class NhanVien {
private:
    string MaNV;
    string HoTen;
    string NgaySinh;
    string DiaChi;

public:
    NhanVien() : MaNV(""), HoTen(""), NgaySinh(""), DiaChi("") {}

    NhanVien(string ma, string ht, string ns, string dc)
        : MaNV(ma), HoTen(ht), NgaySinh(ns), DiaChi(dc) {}

    NhanVien(const NhanVien& other)
        : MaNV(other.MaNV), HoTen(other.HoTen),
          NgaySinh(other.NgaySinh), DiaChi(other.DiaChi) {}

    virtual ~NhanVien() {}

    string getMaNV() const { return MaNV; }
    void setMaNV(string ma) { MaNV = ma; }

    string getHoTen() const { return HoTen; }
    void setHoTen(string ht) { HoTen = ht; }

    string getNgaySinh() const { return NgaySinh; }
    void setNgaySinh(string ns) { NgaySinh = ns; }

    string getDiaChi() const { return DiaChi; }
    void setDiaChi(string dc) { DiaChi = dc; }

    virtual void Nhap() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Nhap ma nhan vien: ";
        getline(cin, MaNV);

        cout << "Nhap ho ten: ";
        getline(cin, HoTen);

        cout << "Nhap ngay sinh: ";
        getline(cin, NgaySinh);

        cout << "Nhap dia chi: ";
        getline(cin, DiaChi);
    }

    virtual void Xuat() const {
        cout << "Ma NV      : " << MaNV << '\n';
        cout << "Ho ten     : " << HoTen << '\n';
        cout << "Ngay sinh  : " << NgaySinh << '\n';
        cout << "Dia chi    : " << DiaChi << '\n';
    }

    virtual float TinhLuong() const = 0;

    virtual void HienThiThongTin() const {
        Xuat();
        cout << "Luong       : " << fixed << setprecision(2) << TinhLuong() << '\n';
    }
};

// ========================= NHAN VIEN VAN PHONG =========================
class NhanVienVanPhong : public NhanVien {
private:
    int SoNgayLamViec;
    float DonGiaNgay;
    int GioTangCa;

public:
    NhanVienVanPhong()
        : NhanVien(), SoNgayLamViec(0), DonGiaNgay(0), GioTangCa(0) {}

    NhanVienVanPhong(string ma, string ht, string ns, string dc,
                     int soNgay, float donGia, int gioTangCa)
        : NhanVien(ma, ht, ns, dc),
          SoNgayLamViec(soNgay), DonGiaNgay(donGia), GioTangCa(gioTangCa) {}

    NhanVienVanPhong(const NhanVienVanPhong& other)
        : NhanVien(other),
          SoNgayLamViec(other.SoNgayLamViec),
          DonGiaNgay(other.DonGiaNgay),
          GioTangCa(other.GioTangCa) {}

    ~NhanVienVanPhong() override {}

    int getSoNgayLamViec() const { return SoNgayLamViec; }
    void setSoNgayLamViec(int x) { SoNgayLamViec = x; }

    float getDonGiaNgay() const { return DonGiaNgay; }
    void setDonGiaNgay(float x) { DonGiaNgay = x; }

    int getGioTangCa() const { return GioTangCa; }
    void setGioTangCa(int x) { GioTangCa = x; }

    void Nhap() override {
        NhanVien::Nhap();

        cout << "Nhap so ngay lam viec: ";
        cin >> SoNgayLamViec;

        cout << "Nhap don gia ngay: ";
        cin >> DonGiaNgay;

        cout << "Nhap gio tang ca: ";
        cin >> GioTangCa;
    }

    void Xuat() const override {
        NhanVien::Xuat();
        cout << "So ngay lam viec: " << SoNgayLamViec << '\n';
        cout << "Don gia ngay    : " << DonGiaNgay << '\n';
        cout << "Gio tang ca     : " << GioTangCa << '\n';
    }

    float TinhLuong() const override {
        return SoNgayLamViec * DonGiaNgay + GioTangCa * DON_GIA_TANG_CA;
    }

    void HienThiThongTin() const override {
        cout << "\n===== NHAN VIEN VAN PHONG =====\n";
        Xuat();
        cout << "Luong          : " << fixed << setprecision(2) << TinhLuong() << '\n';
    }
};

// ========================= NHAN VIEN SAN XUAT =========================
class NhanVienSanXuat : public NhanVien {
private:
    int SoSanPham;
    float DonGiaSanPham;
    float Thuong;

public:
    NhanVienSanXuat()
        : NhanVien(), SoSanPham(0), DonGiaSanPham(0), Thuong(0) {}

    NhanVienSanXuat(string ma, string ht, string ns, string dc,
                    int soSP, float donGiaSP, float thuong)
        : NhanVien(ma, ht, ns, dc),
          SoSanPham(soSP), DonGiaSanPham(donGiaSP), Thuong(thuong) {}

    NhanVienSanXuat(const NhanVienSanXuat& other)
        : NhanVien(other),
          SoSanPham(other.SoSanPham),
          DonGiaSanPham(other.DonGiaSanPham),
          Thuong(other.Thuong) {}

    ~NhanVienSanXuat() override {}

    int getSoSanPham() const { return SoSanPham; }
    void setSoSanPham(int x) { SoSanPham = x; }

    float getDonGiaSanPham() const { return DonGiaSanPham; }
    void setDonGiaSanPham(float x) { DonGiaSanPham = x; }

    float getThuong() const { return Thuong; }
    void setThuong(float x) { Thuong = x; }

    void Nhap() override {
        NhanVien::Nhap();

        cout << "Nhap so san pham: ";
        cin >> SoSanPham;

        cout << "Nhap don gia san pham: ";
        cin >> DonGiaSanPham;

        cout << "Nhap thuong: ";
        cin >> Thuong;
    }

    void Xuat() const override {
        NhanVien::Xuat();
        cout << "So san pham     : " << SoSanPham << '\n';
        cout << "Don gia san pham: " << DonGiaSanPham << '\n';
        cout << "Thuong          : " << Thuong << '\n';
    }

    float TinhLuong() const override {
        return SoSanPham * DonGiaSanPham + Thuong;
    }

    void HienThiThongTin() const override {
        cout << "\n===== NHAN VIEN SAN XUAT =====\n";
        Xuat();
        cout << "Luong          : " << fixed << setprecision(2) << TinhLuong() << '\n';
    }
};

// ========================= QUAN LY =========================
class QuanLy : public NhanVien {
private:
    float LuongTrachNhiem;

public:
    QuanLy() : NhanVien(), LuongTrachNhiem(0) {}

    QuanLy(string ma, string ht, string ns, string dc, float luongTN)
        : NhanVien(ma, ht, ns, dc), LuongTrachNhiem(luongTN) {}

    QuanLy(const QuanLy& other)
        : NhanVien(other), LuongTrachNhiem(other.LuongTrachNhiem) {}

    ~QuanLy() override {}

    float getLuongTrachNhiem() const { return LuongTrachNhiem; }
    void setLuongTrachNhiem(float x) { LuongTrachNhiem = x; }

    void Nhap() override {
        NhanVien::Nhap();

        cout << "Nhap luong trach nhiem: ";
        cin >> LuongTrachNhiem;
    }

    void Xuat() const override {
        NhanVien::Xuat();
        cout << "Luong trach nhiem: " << LuongTrachNhiem << '\n';
    }

    float TinhLuong() const override {
        return LuongTrachNhiem;
    }

    void HienThiThongTin() const override {
        cout << "\n===== QUAN LY =====\n";
        Xuat();
        cout << "Luong           : " << fixed << setprecision(2) << TinhLuong() << '\n';
    }
};

// ========================= DANH SACH NHAN VIEN =========================
class DanhSachNhanVien {
private:
    vector<NhanVien*> thanhvien;

public:
    ~DanhSachNhanVien() {
        for (size_t i = 0; i < thanhvien.size(); ++i) {
            delete thanhvien[i];
        }
    }

    void ThemNhanVien(NhanVien* nv) {
        thanhvien.push_back(nv);
    }

    void XuatDanhSach() const {
        if (thanhvien.empty()) {
            cout << "\nDanh sach nhan vien rong.\n";
            return;
        }

        cout << "\n========== DANH SACH NHAN VIEN ==========\n";
        for (size_t i = 0; i < thanhvien.size(); ++i) {
            cout << "\nNhan vien thu " << i + 1 << ":\n";
            thanhvien[i]->HienThiThongTin();
        }
    }

    float TinhTongLuong() const {
        float tong = 0;
        for (size_t i = 0; i < thanhvien.size(); ++i) {
            tong += thanhvien[i]->TinhLuong();
        }
        return tong;
    }
};

// ========================= MAIN =========================
int main() {
    DanhSachNhanVien ds;
    int chon;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Them nhan vien van phong\n";
        cout << "2. Them nhan vien san xuat\n";
        cout << "3. Them quan ly\n";
        cout << "4. Xuat danh sach\n";
        cout << "5. Tinh tong luong\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> chon;

        switch (chon) {
            case 1: {
                NhanVien* nv = new NhanVienVanPhong();
                nv->Nhap();
                ds.ThemNhanVien(nv);
                cout << "Them nhan vien van phong thanh cong.\n";
                break;
            }
            case 2: {
                NhanVien* nv = new NhanVienSanXuat();
                nv->Nhap();
                ds.ThemNhanVien(nv);
                cout << "Them nhan vien san xuat thanh cong.\n";
                break;
            }
            case 3: {
                NhanVien* nv = new QuanLy();
                nv->Nhap();
                ds.ThemNhanVien(nv);
                cout << "Them quan ly thanh cong.\n";
                break;
            }
            case 4:
                ds.XuatDanhSach();
                break;
            case 5:
                cout << "\nTong luong: " << fixed << setprecision(2)
                     << ds.TinhTongLuong() << '\n';
                break;
            case 0:
                cout << "Ket thuc chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (chon != 0);

    return 0;
}
