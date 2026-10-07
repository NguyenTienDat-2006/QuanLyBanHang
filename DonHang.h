#ifndef DONHANG_H
#define DONHANG_H

#include <bits/stdc++.h>
#include "ChiTietGioHang.h"

using namespace std;

// ==================================================
// CLASS DON HANG
// ==================================================

class DonHang
{
private:
    string maDH;
    string hoTen;
    string sdt;
    string diaChi;

    vector<ChiTietGioHang> chiTiet;

    double tongTien;

public:

    DonHang() {}


    DonHang(
        string ma,
        string ten,
        string phone,
        string dc,
        vector<ChiTietGioHang> gioHang
    )
        : maDH(ma),
          hoTen(ten),
          sdt(phone),
          diaChi(dc),
          chiTiet(gioHang)
    {
        tongTien = 0;

        for (auto &ct : chiTiet)
            tongTien += ct.thanhTien();
    }


    void xuat()
    {
        cout << "\n========================================\n";
        cout << "Ma don hang: " << maDH << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Dia chi: " << diaChi << endl;

        cout << "\n----------- CHI TIET DON HANG -----------\n";

        cout << left
             << setw(15) << "Ma SP"
             << setw(30) << "Ten SP"
             << setw(12) << "So luong"
             << setw(15) << "Don gia"
             << "Thanh tien"
             << endl;

        cout << string(90, '-') << endl;

        for (auto &ct : chiTiet)
        {
            cout << left
                 << setw(15) << ct.getMaSP()
                 << setw(30) << ct.getTenSP()
                 << setw(12) << ct.getSoLuong()
                 << setw(15)
                 << fixed
                 << setprecision(0)
                 << ct.getDonGia()
                 << ct.thanhTien()
                 << endl;
        }

        cout << string(90, '-') << endl;

        cout << "Tong tien: "
             << fixed
             << setprecision(0)
             << tongTien
             << " VND"
             << endl;
    }
};

#endif