#pragma once

#include <bits/stdc++.h>

using namespace std;

class ChiTietGioHang
{
private:
    string maSP;
    string tenSP;
    int soLuong;
    double donGia;

public:

    ChiTietGioHang();

    ChiTietGioHang(
        string ma,
        string ten,
        int sl,
        double gia
    );

    string getMaSP();
    string getTenSP();
    int getSoLuong();
    double getDonGia();

    void tangSoLuong(int sl);

    double thanhTien();
};