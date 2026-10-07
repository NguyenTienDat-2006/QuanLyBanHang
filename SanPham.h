#pragma once

#include <bits/stdc++.h>

using namespace std;

class SanPham
{
private:
    string id;
    string maSP;
    string tenSP;

    int soLuong;
    double donGia;

public:

    SanPham();

    SanPham(
        string id,
        string ma,
        string ten,
        int sl,
        double gia
    );

    string getMaSP();
    string getTenSP();
    int getSoLuong();
    double getDonGia();

    void setTenSP(string ten);
    void setSoLuong(int sl);
    void setDonGia(double gia);

    void giamSoLuong(int sl);
    void tangSoLuong(int sl);

    void nhap(int stt);
    void xuat();
};