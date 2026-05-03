2H3T - HE THONG QUAN LY NHAN SU
===============================

I. CACH CHAY TREN CMD WINDOWS

1. Cai MinGW hoac MSYS2 de co trinh bien dich g++.
2. Mo CMD tai thu muc project.
3. Chay file:

   build.bat

Hoac bien dich thu cong:

   g++ -std=c++11 -Iinclude main.cpp src\*.cpp -o build\QuanLyNhanSu.exe
   build\QuanLyNhanSu.exe


II. CAU TRUC THU MUC

2H3T_QuanLyNhanSu_CoBan_OOP
|
|-- main.cpp
|-- build.bat
|-- README.txt
|
|-- include
|   |-- InputHelper.h
|   |-- GiaoDien.h
|   |-- NhanVien.h
|   |-- NhanVienVanPhong.h
|   |-- NhanVienSanXuat.h
|   |-- QuanLy.h
|   |-- DanhSachNhanVien.h
|   |-- Menu.h
|
|-- src
    |-- InputHelper.cpp
    |-- GiaoDien.cpp
    |-- NhanVien.cpp
    |-- NhanVienVanPhong.cpp
    |-- NhanVienSanXuat.cpp
    |-- QuanLy.cpp
    |-- DanhSachNhanVien.cpp
    |-- Menu.cpp


III. CAC DIEU KIEN DA BO SUNG THEO THANG DIEM

1. De tai thuc te:
   - Quan ly nhan su, tinh luong nhan vien.

2. Co ke thua:
   - NhanVienVanPhong ke thua NhanVien.
   - NhanVienSanXuat ke thua NhanVien.
   - QuanLy ke thua NhanVien.

3. Co da hinh:
   - Lop NhanVien co ham ao thuan tuy:
     + layLoaiNhanVien()
     + tinhLuong()
     + nhapThongTinRieng()
     + xuatThongTinRieng()
     + suaThongTinRieng()
   - DanhSachNhanVien luu vector<NhanVien*> va goi ham thong qua con tro lop cha.

4. Co getter/setter:
   - Lop NhanVien co getter/setter cho ma, ten, ngay sinh, dia chi.
   - Cac lop con co getter/setter cho tat ca thuoc tinh rieng.

5. Co ham khoi tao:
   - Constructor mac dinh.
   - Constructor co tham so.
   - Copy constructor.

6. Co ham qua tai nhap/xuat:
   - operator >> va operator << cho:
     + NhanVienVanPhong
     + NhanVienSanXuat
     + QuanLy

7. Console:
   - Chay duoc tren CMD bang build.bat.
   - Co giao dien console co banner nhom 2H3T.
   - Co mau console bang lenh system("color 0B") tren Windows.

8. Rang buoc nhap lieu:
   - Khong cho de trong chuoi.
   - Ho ten khong chua so.
   - Ngay sinh dung DD/MM/YYYY.
   - So ngay, gio tang ca, luong, he so phai trong khoang hop le.
   - Menu khong bi loi khi nhap chu.


IV. LUU Y

- Code duoc viet bang cac cau truc C++ co ban, de giai thich.
- Khong dung unique_ptr, lambda, template nang cao, map, unordered_map.
- Co su dung vector<NhanVien*> vi day la cach co ban de minh hoa da hinh.
- Destructor cua DanhSachNhanVien co delete de tranh ro ri bo nho.

//0  = Đen
//1  = Xanh dương đậm
//2  = Xanh lá đậm
//3  = Xanh biển đậm
//4  = Đỏ đậm
//5  = Tím
//6  = Vàng nâu
//7  = Trắng xám mặc định
//8  = Xám đậm
//9  = Xanh dương sáng
//10 = Xanh lá sáng
//11 = Cyan sáng
//12 = Đỏ sáng
//13 = Hồng tím sáng
//14 = Vàng sáng
//15 = Trắng sáng