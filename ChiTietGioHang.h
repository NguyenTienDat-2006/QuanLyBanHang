#ifndef CHITIETGIOHANG_H
#define CHITIETGIOHANG_H

#include <bits/stdc++.h>

using namespace std;

// ==================================================
// CLASS CHI TIET GIO HANG
// ==================================================

class ChiTietGioHang
{
private:
    string maSP;
    string tenSP;
    int soLuong;
    double donGia;

public:

    ChiTietGioHang() {}


    ChiTietGioHang(
        string ma,
        string ten,
        int sl,
        double gia
    )
        : maSP(ma),
          tenSP(ten),
          soLuong(sl),
          donGia(gia)
    {
    }


    string getMaSP()
    {
        return maSP;
    }

    string getTenSP()
    {
        return tenSP;
    }

    int getSoLuong()
    {
        return soLuong;
    }

    double getDonGia()
    {
        return donGia;
    }


    void tangSoLuong(int sl)
    {
        soLuong += sl;
    }


    double thanhTien()
    {
        return soLuong * donGia;
    }
};

#endif