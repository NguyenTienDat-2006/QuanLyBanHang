#pragma once

#include <bits/stdc++.h>

using namespace std;

class NguoiDung
{
private:
    string id;
    string maND;
    string taiKhoan;
    string matKhau;
    string vaiTro;
    string hoTen;
    string chucVu;
    string sdt;
    string diaChi;

public:

    NguoiDung();

    NguoiDung(
        string id,
        string ma,
        string tk,
        string mk,
        string vt,
        string ten,
        string cv,
        string phone,
        string dc
    );

    // ==================================================
    // GETTER
    // ==================================================

    string getID();
    string getMaND();
    string getTaiKhoan();
    string getMatKhau();
    string getVaiTro();
    string getHoTen();
    string getChucVu();
    string getSDT();
    string getDiaChi();


    // ==================================================
    // SETTER
    // ==================================================

    void setMatKhau(string mk);
    void setHoTen(string ten);
    void setChucVu(string cv);
    void setSDT(string phone);
    void setDiaChi(string dc);


    // ==================================================
    // NHAP NGUOI DUNG CHO ADMIN
    // Chi ADMIN / STAFF
    // ==================================================

    void nhapAdmin(
        int stt,
        vector<NguoiDung>& ds
    );


    // ==================================================
    // NHAP KHACH HANG
    // ==================================================

    void nhapKhachHang(
        int stt,
        vector<NguoiDung>& ds
    );


    // ==================================================
    // XUAT
    // ==================================================

    void xuat();


    // ==================================================
    // KIEM TRA TAI KHOAN TRUNG
    // ==================================================

    static bool trungTaiKhoan(
        vector<NguoiDung>& ds,
        string taiKhoan
    );
};