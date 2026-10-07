#ifndef SANPHAM_H
#define SANPHAM_H

#include <bits/stdc++.h>

using namespace std;

// ==================================================
// CLASS SAN PHAM
// ==================================================

class SanPham
{
private:
    string id;
    string maSP;
    string tenSP;

    int soLuong;
    double donGia;

public:

    SanPham() {}


    SanPham(
        string id,
        string ma,
        string ten,
        int sl,
        double gia
    )
        : id(id),
          maSP(ma),
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


    void setTenSP(string ten)
    {
        tenSP = ten;
    }

    void setSoLuong(int sl)
    {
        soLuong = sl;
    }

    void setDonGia(double gia)
    {
        donGia = gia;
    }


    void giamSoLuong(int sl)
    {
        soLuong -= sl;
    }


    void tangSoLuong(int sl)
    {
        soLuong += sl;
    }


    void nhap(int stt)
    {
        id = "SP" + to_string(stt);

        cout << "Ma san pham: ";
        cin >> maSP;

        cin.ignore();

        do
        {
            cout << "Ten san pham: ";
            getline(cin, tenSP);

            if (tenSP.empty())
                cout << "Ten san pham khong duoc de trong!\n";

        } while (tenSP.empty());

        do
        {
            cout << "So luong: ";
            cin >> soLuong;

            if (cin.fail() || soLuong < 0)
            {
                cout << "So luong phai la so nguyen khong am!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }

        } while (cin.fail() || soLuong < 0);


        do
        {
            cout << "Don gia: ";
            cin >> donGia;

            if (cin.fail() || donGia < 0)
            {
                cout << "Don gia phai la so thuc khong am!\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }

        } while (cin.fail() || donGia < 0);
    }


    void xuat()
    {
        cout << left
             << setw(8) << id
             << setw(15) << maSP
             << setw(30) << tenSP
             << setw(12) << soLuong
             << fixed
             << setprecision(0)
             << donGia
             << endl;
    }
};

#endif