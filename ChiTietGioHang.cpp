#include "ChiTietGioHang.h"

// ==================================================
// CLASS CHI TIET GIO HANG
// ==================================================

ChiTietGioHang::ChiTietGioHang()
{
}


ChiTietGioHang::ChiTietGioHang(
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


string ChiTietGioHang::getMaSP()
{
    return maSP;
}

string ChiTietGioHang::getTenSP()
{
    return tenSP;
}

int ChiTietGioHang::getSoLuong()
{
    return soLuong;
}

double ChiTietGioHang::getDonGia()
{
    return donGia;
}


void ChiTietGioHang::tangSoLuong(int sl)
{
    soLuong += sl;
}


double ChiTietGioHang::thanhTien()
{
    return soLuong * donGia;
}