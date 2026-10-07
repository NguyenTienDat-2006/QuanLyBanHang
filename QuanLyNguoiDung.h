#ifndef QUANLYNGUOIDUNG_H
#define QUANLYNGUOIDUNG_H

#include <bits/stdc++.h>
#include "NguoiDung.h"

using namespace std;


// ==================================================
// KIEM TRA TAI KHOAN TRUNG
// ==================================================

bool trungTaiKhoan(
    vector<NguoiDung>& ds,
    string taiKhoan
)
{
    for (auto &nd : ds)
    {
        if (nd.getTaiKhoan() == taiKhoan)
            return true;
    }

    return false;
}


// ==================================================
// XEM NGUOI DUNG
// ==================================================

void xemNguoiDung(vector<NguoiDung>& ds)
{
    if (ds.empty())
    {
        cout << "\nDanh sach nguoi dung rong!\n";
        return;
    }

    cout << "\n========== DANH SACH NGUOI DUNG ==========\n";

    cout << left
         << setw(8) << "ID"
         << setw(15) << "Ma ND"
         << setw(15) << "Tai khoan"
         << setw(12) << "Vai tro"
         << setw(25) << "Ho ten"
         << setw(15) << "Chuc vu"
         << setw(13) << "SDT"
         << "Dia chi"
         << endl;

    cout << string(120, '-') << endl;

    for (auto &nd : ds)
        nd.xuat();
}


// ==================================================
// THEM ADMIN / STAFF
// ==================================================

void themNguoiDungAdmin(
    vector<NguoiDung>& ds
)
{
    NguoiDung nd;

    nd.nhapAdmin(
        ds.size() + 1,
        ds
    );

    ds.push_back(nd);

    cout << "\nThem nguoi dung thanh cong!\n";
}


// ==================================================
// DANG KY CUSTOMER
// ==================================================

void dangKyCustomer(
    vector<NguoiDung>& ds
)
{
    NguoiDung nd;

    nd.nhapKhachHang(
        ds.size() + 1,
        ds
    );

    ds.push_back(nd);

    cout << "\nDang ky tai khoan CUSTOMER thanh cong!\n";
}


// ==================================================
// DANG NHAP
// ==================================================

int dangNhap(
    vector<NguoiDung>& ds
)
{
    string tk;
    string mk;

    cout << "\n========== DANG NHAP ==========\n";

    cout << "Tai khoan: ";
    cin >> tk;

    cout << "Mat khau: ";
    mk = nhapMatKhau();

    for (int i = 0; i < (int)ds.size(); i++)
    {
        if (
            ds[i].getTaiKhoan() == tk &&
            ds[i].getMatKhau() == mk
        )
        {
            return i;
        }
    }

    return -1;
}


// ==================================================
// XOA NGUOI DUNG
// ==================================================

void xoaNguoiDung(
    vector<NguoiDung>& ds,
    int viTriAdmin
)
{
    if (ds.empty())
    {
        cout << "\nDanh sach rong!\n";
        return;
    }


    xemNguoiDung(ds);


    string tk;

    cout << "\nNhap tai khoan can xoa: ";
    cin >> tk;


    int viTri = -1;

    for (int i = 0; i < (int)ds.size(); i++)
    {
        if (ds[i].getTaiKhoan() == tk)
        {
            viTri = i;
            break;
        }
    }


    if (viTri == -1)
    {
        cout << "Khong tim thay nguoi dung!\n";
        return;
    }


    // Khong cho admin xoa chinh minh
    if (viTri == viTriAdmin)
    {
        cout << "\nKhong the xoa tai khoan ADMIN dang dang nhap!\n";
        return;
    }


    // Xac nhan
    char xacNhan;

    cout << "\nBan co chac chan muon xoa tai khoan nay? (Y/N): ";
    cin >> xacNhan;


    if (xacNhan == 'Y' || xacNhan == 'y')
    {
        ds.erase(ds.begin() + viTri);

        cout << "\nXoa nguoi dung thanh cong!\n";
    }
    else
    {
        cout << "\nDa huy thao tac xoa.\n";
    }
}


// ==================================================
// SUA NGUOI DUNG
// ==================================================

void suaNguoiDung(
    vector<NguoiDung>& ds,
    int viTriAdmin
)
{
    if (ds.empty())
    {
        cout << "\nDanh sach nguoi dung rong!\n";
        return;
    }


    xemNguoiDung(ds);


    string tk;

    cout << "\nNhap tai khoan can sua: ";
    cin >> tk;


    int viTri = -1;

    for (int i = 0; i < (int)ds.size(); i++)
    {
        if (ds[i].getTaiKhoan() == tk)
        {
            viTri = i;
            break;
        }
    }


    if (viTri == -1)
    {
        cout << "Khong tim thay nguoi dung!\n";
        return;
    }


    cout << "\n========== THONG TIN NGUOI DUNG ==========\n";
    cout << "Tai khoan: "
         << ds[viTri].getTaiKhoan()
         << endl;

    cout << "Vai tro: "
         << ds[viTri].getVaiTro()
         << endl;


    // ==================================================
    // SUA HO TEN
    // ==================================================

    cin.ignore();

    string tenMoi;

    do
    {
        cout << "\nHo ten moi: ";
        getline(cin, tenMoi);

        if (!kiemTraHoTen(tenMoi))
            cout << "Ho ten khong duoc de trong!\n";

    } while (!kiemTraHoTen(tenMoi));


    // ==================================================
    // SUA MAT KHAU
    // ==================================================

    string mkMoi;

    do
    {
        cout << "\nMat khau moi: ";

        mkMoi = nhapMatKhau();

        if (!kiemTraMatKhau(mkMoi))
            cout << "Mat khau khong hop le!\n";

    } while (!kiemTraMatKhau(mkMoi));


    // ==================================================
    // SUA CHUC VU
    // ==================================================

    int chonCV;

    do
    {
        cout << "\n========== CHON CHUC VU ==========\n";
        cout << "1. Giam doc\n";
        cout << "2. Nhan vien\n";
        cout << "Chon: ";

        cin >> chonCV;

    } while (chonCV != 1 && chonCV != 2);


    string cvMoi;

    if (chonCV == 1)
        cvMoi = "Giam doc";
    else
        cvMoi = "Nhan vien";


    // ==================================================
    // SUA SDT
    // ==================================================

    string sdtMoi;

    do
    {
        cout << "SDT moi: ";
        cin >> sdtMoi;

        if (!kiemTraSDT(sdtMoi))
            cout << "SDT phai gom dung 10 chu so!\n";

    } while (!kiemTraSDT(sdtMoi));


    // ==================================================
    // SUA DIA CHI
    // ==================================================

    cin.ignore();

    string diaChiMoi;

    cout << "Dia chi moi: ";
    getline(cin, diaChiMoi);


    // ==================================================
    // XAC NHAN
    // ==================================================

    char xacNhan;

    cout << "\nBan co chac chan muon luu thay doi? (Y/N): ";
    cin >> xacNhan;


    if (xacNhan == 'Y' || xacNhan == 'y')
    {
        ds[viTri].setHoTen(tenMoi);
        ds[viTri].setMatKhau(mkMoi);
        ds[viTri].setChucVu(cvMoi);
        ds[viTri].setSDT(sdtMoi);
        ds[viTri].setDiaChi(diaChiMoi);

        cout << "\nSua thong tin thanh cong!\n";
    }
    else
    {
        cout << "\nDa huy thao tac sua.\n";
    }
}

#endif