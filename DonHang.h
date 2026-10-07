#pragma once

#include <bits/stdc++.h>
#include "ChiTietGioHang.h"

using namespace std;

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

    DonHang();

    DonHang(
        string ma,
        string ten,
        string phone,
        string dc,
        vector<ChiTietGioHang> gioHang
    );

    void xuat();
};