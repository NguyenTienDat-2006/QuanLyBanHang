#pragma once

#include <bits/stdc++.h>

#include "NguoiDung.h"
#include "SanPham.h"
#include "DonHang.h"

using namespace std;

void xemDonHang(
    vector<DonHang>& dsDonHang
);

void menuAdmin(
    vector<NguoiDung>& nd,
    vector<SanPham>& sp,
    vector<DonHang>& dsDonHang,
    int viTriAdmin
);

void menuStaff(
    vector<SanPham>& sp
);