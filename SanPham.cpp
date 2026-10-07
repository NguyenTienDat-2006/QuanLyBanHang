#include "SanPham.h"

// ==================================================
// CLASS SAN PHAM
// ==================================================

SanPham::SanPham()
{
}


SanPham::SanPham(
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


string SanPham::getMaSP()
{
    return maSP;
}

string SanPham::getTenSP()
{
    return tenSP;
}

int SanPham::getSoLuong()
{
    return soLuong;
}

double SanPham::getDonGia()
{
    return donGia;
}


void SanPham::setTenSP(string ten)
{
    tenSP = ten;
}

void SanPham::setSoLuong(int sl)
{
    soLuong = sl;
}

void SanPham::setDonGia(double gia)
{
    donGia = gia;
}


void SanPham::giamSoLuong(int sl)
{
    soLuong -= sl;
}


void SanPham::tangSoLuong(int sl)
{
    soLuong += sl;
}


void SanPham::nhap(int stt)
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


void SanPham::xuat()
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