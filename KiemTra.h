#ifndef KIEMTRA_H
#define KIEMTRA_H

#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

// ==================================================
// CAC HAM KIEM TRA
// ==================================================

bool kiemTraTaiKhoan(string taiKhoan)
{
    if (taiKhoan.empty() || taiKhoan.length() > 12)
        return false;

    // Ky tu dau tien phai la chu cai
    if (!isalpha((unsigned char)taiKhoan[0]))
        return false;

    // Chi gom chu cai va chu so
    for (char c : taiKhoan)
    {
        if (!isalnum((unsigned char)c))
            return false;
    }

    return true;
}


// ==================================================
// KIEM TRA MAT KHAU
// - It nhat 8 ky tu
// - Co chu hoa
// - Co chu thuong
// - Co ky tu dac biet
// ==================================================

bool kiemTraMatKhau(string matKhau)
{
    bool chuHoa = false;
    bool chuThuong = false;
    bool kyTuDacBiet = false;

    if (matKhau.length() < 8)
        return false;

    if (matKhau.find(' ') != string::npos)
        return false;

    for (char c : matKhau)
    {
        if (isupper((unsigned char)c))
            chuHoa = true;

        else if (islower((unsigned char)c))
            chuThuong = true;

        else if (ispunct((unsigned char)c))
            kyTuDacBiet = true;
    }

    return chuHoa && chuThuong && kyTuDacBiet;
}


// ==================================================
// KIEM TRA HO TEN
// Khong duoc de trong
// ==================================================

bool kiemTraHoTen(string hoTen)
{
    if (hoTen.empty())
        return false;

    // Kiem tra toan bo chuoi co ky tu thuc hay khong
    bool coKyTu = false;

    for (char c : hoTen)
    {
        if (!isspace((unsigned char)c))
        {
            coKyTu = true;
            break;
        }
    }

    return coKyTu;
}


// ==================================================
// KIEM TRA SO DIEN THOAI
// Phai gom dung 10 chu so
// ==================================================

bool kiemTraSDT(string sdt)
{
    if (sdt.length() != 10)
        return false;

    for (char c : sdt)
    {
        if (!isdigit((unsigned char)c))
            return false;
    }

    return true;
}


// ==================================================
// HAM NHAP MAT KHAU
// ==================================================

string nhapMatKhau()
{
    string matKhau;
    char c;

    while (true)
    {
        c = _getch();

        // Enter
        if (c == 13)
            break;

        // Backspace
        if (c == 8)
        {
            if (!matKhau.empty())
            {
                matKhau.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            matKhau += c;
            cout << "*";
        }
    }

    cout << endl;

    return matKhau;
}

#endif