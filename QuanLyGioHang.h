#pragma once

#include <bits/stdc++.h>

#include "SanPham.h"
#include "NguoiDung.h"
#include "ChiTietGioHang.h"
#include "DonHang.h"

using namespace std;

void themVaoGioHang(
    vector<SanPham>& dsSanPham,
    vector<ChiTietGioHang>& gioHang
);

void xemGioHang(
    vector<ChiTietGioHang>& gioHang
);

void datMua(
    vector<ChiTietGioHang>& gioHang,
    vector<SanPham>& dsSanPham,
    vector<DonHang>& dsDonHang,
    vector<NguoiDung>& dsNguoiDung,
    int viTriNguoiDung
);

void menuKhachHang(
    vector<SanPham>& dsSanPham,
    vector<NguoiDung>& dsNguoiDung,
    vector<DonHang>& dsDonHang
);