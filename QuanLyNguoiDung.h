#pragma once

#include <bits/stdc++.h>
#include "NguoiDung.h"

using namespace std;

bool trungTaiKhoan(
    vector<NguoiDung>& ds,
    string taiKhoan
);

void xemNguoiDung(vector<NguoiDung>& ds);

void themNguoiDungAdmin(
    vector<NguoiDung>& ds
);

void dangKyCustomer(
    vector<NguoiDung>& ds
);

int dangNhap(
    vector<NguoiDung>& ds
);

void xoaNguoiDung(
    vector<NguoiDung>& ds,
    int viTriAdmin
);

void suaNguoiDung(
    vector<NguoiDung>& ds,
    int viTriAdmin
);