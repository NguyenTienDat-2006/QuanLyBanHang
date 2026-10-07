#ifndef MENU_H
#define MENU_H

#include <bits/stdc++.h>

#include "KiemTra.h"
#include "NguoiDung.h"
#include "SanPham.h"
#include "ChiTietGioHang.h"
#include "DonHang.h"
#include "QuanLySanPham.h"
#include "QuanLyNguoiDung.h"

using namespace std;


// ==================================================
// THEM SAN PHAM VAO GIO HANG
// ==================================================

void themVaoGioHang(
    vector<SanPham>& dsSanPham,
    vector<ChiTietGioHang>& gioHang
)
{
    if (dsSanPham.empty())
    {
        cout << "\nDanh sach san pham rong!\n";
        return;
    }

    xemSanPham(dsSanPham);

    string ma;
    int soLuong;

    cout << "\nNhap ma san pham muon mua: ";
    cin >> ma;

    int viTri = -1;

    for (int i = 0; i < (int)dsSanPham.size(); i++)
    {
        if (dsSanPham[i].getMaSP() == ma)
        {
            viTri = i;
            break;
        }
    }

    if (viTri == -1)
    {
        cout << "\nKhong tim thay san pham!\n";
        return;
    }

    cout << "Nhap so luong muon mua: ";
    cin >> soLuong;

    if (soLuong <= 0)
    {
        cout << "\nSo luong khong hop le!\n";
        return;
    }

    // So luong dang co trong gio hang
    int dangCo = 0;

    for (auto &ct : gioHang)
    {
        if (ct.getMaSP() == ma)
        {
            dangCo = ct.getSoLuong();
            break;
        }
    }

    if (dangCo + soLuong > dsSanPham[viTri].getSoLuong())
    {
        cout << "\nKhong du so luong trong kho!\n";
        cout << "So luong hien co: "
             << dsSanPham[viTri].getSoLuong()
             << endl;

        return;
    }

    // Neu san pham da co trong gio hang
    for (auto &ct : gioHang)
    {
        if (ct.getMaSP() == ma)
        {
            ct.tangSoLuong(soLuong);

            cout << "\nDa them them san pham vao gio hang!\n";
            return;
        }
    }

    ChiTietGioHang ct(
        dsSanPham[viTri].getMaSP(),
        dsSanPham[viTri].getTenSP(),
        soLuong,
        dsSanPham[viTri].getDonGia()
    );

    gioHang.push_back(ct);

    cout << "\nThem san pham vao gio hang thanh cong!\n";
}


// ==================================================
// XEM GIO HANG
// ==================================================

void xemGioHang(
    vector<ChiTietGioHang>& gioHang
)
{
    if (gioHang.empty())
    {
        cout << "\nGio hang dang rong!\n";
        return;
    }

    double tongTien = 0;

    cout << "\n========== GIO HANG ==========\n";

    cout << left
         << setw(15) << "Ma SP"
         << setw(30) << "Ten SP"
         << setw(12) << "So luong"
         << setw(15) << "Don gia"
         << "Thanh tien"
         << endl;

    cout << string(90, '-') << endl;

    for (auto &ct : gioHang)
    {
        cout << left
             << setw(15) << ct.getMaSP()
             << setw(30) << ct.getTenSP()
             << setw(12) << ct.getSoLuong()
             << setw(15)
             << fixed
             << setprecision(0)
             << ct.getDonGia()
             << ct.thanhTien()
             << endl;

        tongTien += ct.thanhTien();
    }

    cout << string(90, '-') << endl;

    cout << "Tong tien: "
         << fixed
         << setprecision(0)
         << tongTien
         << " VND"
         << endl;
}


// ==================================================
// DAT MUA
// ==================================================

void datMua(
    vector<ChiTietGioHang>& gioHang,
    vector<SanPham>& dsSanPham,
    vector<DonHang>& dsDonHang,
    vector<NguoiDung>& dsNguoiDung,
    int viTriNguoiDung
)
{
    if (gioHang.empty())
    {
        cout << "\nGio hang dang rong!\n";
        cout << "Vui long them san pham vao gio hang truoc.\n";
        return;
    }

    string hoTen;
    string sdt;
    string diaChi;


    // ==================================================
    // KHACH DA DANG NHAP
    // ==================================================

    if (viTriNguoiDung != -1)
    {
        hoTen = dsNguoiDung[viTriNguoiDung].getHoTen();
        sdt = dsNguoiDung[viTriNguoiDung].getSDT();
        diaChi = dsNguoiDung[viTriNguoiDung].getDiaChi();

        cout << "\n========== THONG TIN DAT HANG ==========\n";

        cout << "Ho ten: " << hoTen << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Dia chi: " << diaChi << endl;
    }


    // ==================================================
    // KHACH CHUA DANG NHAP
    // ==================================================

    else
    {
        cin.ignore();

        cout << "\n========== THONG TIN DAT HANG ==========\n";

        do
        {
            cout << "Ho ten: ";
            getline(cin, hoTen);

            if (!kiemTraHoTen(hoTen))
                cout << "Ho ten khong duoc de trong!\n";

        } while (!kiemTraHoTen(hoTen));


        do
        {
            cout << "So dien thoai: ";
            getline(cin, sdt);

            if (!kiemTraSDT(sdt))
                cout << "SDT phai gom dung 10 chu so!\n";

        } while (!kiemTraSDT(sdt));


        cout << "Dia chi: ";
        getline(cin, diaChi);
    }


    // ==================================================
    // KIEM TRA TON KHO
    // ==================================================

    for (auto &ct : gioHang)
    {
        bool timThay = false;

        for (auto &sp : dsSanPham)
        {
            if (sp.getMaSP() == ct.getMaSP())
            {
                timThay = true;

                if (ct.getSoLuong() > sp.getSoLuong())
                {
                    cout << "\nSan pham "
                         << ct.getMaSP()
                         << " khong du so luong trong kho!\n";

                    return;
                }

                break;
            }
        }

        if (!timThay)
        {
            cout << "\nSan pham "
                 << ct.getMaSP()
                 << " khong con ton tai!\n";

            return;
        }
    }


    // ==================================================
    // MA DON HANG
    // ==================================================

    string maDH =
        "DH" + to_string(dsDonHang.size() + 1);


    // ==================================================
    // TAO DON HANG
    // ==================================================

    DonHang dh(
        maDH,
        hoTen,
        sdt,
        diaChi,
        gioHang
    );


    dsDonHang.push_back(dh);


    // ==================================================
    // TRU SO LUONG KHO
    // ==================================================

    for (auto &ct : gioHang)
    {
        for (auto &sp : dsSanPham)
        {
            if (sp.getMaSP() == ct.getMaSP())
            {
                sp.giamSoLuong(ct.getSoLuong());
                break;
            }
        }
    }


    // ==================================================
    // THONG BAO
    // ==================================================

    cout << "\n========================================\n";
    cout << "          DAT HANG THANH CONG!\n";
    cout << "========================================\n";

    dsDonHang.back().xuat();


    gioHang.clear();
}


// ==================================================
// MENU KHACH HANG
// ==================================================

void menuKhachHang(
    vector<SanPham>& dsSanPham,
    vector<NguoiDung>& dsNguoiDung,
    vector<DonHang>& dsDonHang
)
{
    int chon;

    int viTriNguoiDung = -1;

    vector<ChiTietGioHang> gioHang;


    do
    {
        cout << "\n";
        cout << "========================================\n";
        cout << "              KHACH HANG\n";
        cout << "========================================\n";


        if (viTriNguoiDung != -1)
        {
            cout << "Tai khoan: "
                 << dsNguoiDung[viTriNguoiDung].getTaiKhoan()
                 << endl;

            cout << "Trang thai: DA DANG NHAP\n";
        }
        else
        {
            cout << "Trang thai: CHUA DANG NHAP\n";
        }


        cout << "\n";
        cout << "1. Xem danh sach san pham\n";
        cout << "2. Chon mua san pham\n";
        cout << "3. Xem gio hang\n";
        cout << "4. Dat mua\n";
        cout << "5. Dang ky tai khoan\n";
        cout << "6. Dang nhap\n";
        cout << "0. Quay lai\n";

        cout << "\nChon: ";
        cin >> chon;


        if (chon == 1)
        {
            xemSanPham(dsSanPham);
        }


        else if (chon == 2)
        {
            themVaoGioHang(
                dsSanPham,
                gioHang
            );
        }


        else if (chon == 3)
        {
            xemGioHang(gioHang);
        }


        else if (chon == 4)
        {
            datMua(
                gioHang,
                dsSanPham,
                dsDonHang,
                dsNguoiDung,
                viTriNguoiDung
            );
        }


        else if (chon == 5)
        {
            cout << "\n========== DANG KY CUSTOMER ==========\n";

            dangKyCustomer(dsNguoiDung);
        }


        else if (chon == 6)
        {
            int vt = dangNhap(dsNguoiDung);

            if (vt == -1)
            {
                cout << "\nSai tai khoan hoac mat khau!\n";
            }
            else if (
                dsNguoiDung[vt].getVaiTro() == "CUSTOMER"
            )
            {
                viTriNguoiDung = vt;

                cout << "\nDang nhap khach hang thanh cong!\n";
            }
            else
            {
                cout << "\nTai khoan nay khong phai CUSTOMER!\n";
            }
        }


        else if (chon != 0)
        {
            cout << "\nLua chon khong hop le!\n";
        }

    } while (chon != 0);
}


// ==================================================
// XEM DON HANG
// ==================================================

void xemDonHang(
    vector<DonHang>& dsDonHang
)
{
    if (dsDonHang.empty())
    {
        cout << "\nChua co don hang nao!\n";
        return;
    }


    cout << "\n========== DANH SACH DON HANG ==========\n";


    for (auto &dh : dsDonHang)
    {
        dh.xuat();

        cout << endl;
    }
}


// ==================================================
// MENU ADMIN
// ==================================================

void menuAdmin(
    vector<NguoiDung>& nd,
    vector<SanPham>& sp,
    vector<DonHang>& dsDonHang,
    int viTriAdmin
)
{
    int chon;


    do
    {
        cout << "\n";
        cout << "========================================\n";
        cout << "              MENU ADMIN\n";
        cout << "========================================\n";

        cout << "1. Them nguoi dung ADMIN / STAFF\n";
        cout << "2. Xem danh sach nguoi dung\n";
        cout << "3. Xoa nguoi dung\n";
        cout << "4. Sua nguoi dung\n";
        cout << "5. Xem danh sach don hang\n";
        cout << "6. Xem danh sach san pham\n";
        cout << "7. Quan ly san pham\n";
        cout << "0. Dang xuat\n";

        cout << "Chon: ";
        cin >> chon;


        // ==================================================
        // THEM ADMIN / STAFF
        // ==================================================

        if (chon == 1)
        {
            themNguoiDungAdmin(nd);
        }


        // ==================================================
        // XEM NGUOI DUNG
        // ==================================================

        else if (chon == 2)
        {
            xemNguoiDung(nd);
        }


        // ==================================================
        // XOA NGUOI DUNG
        // ==================================================

        else if (chon == 3)
        {
            xoaNguoiDung(
                nd,
                viTriAdmin
            );
        }


        // ==================================================
        // SUA NGUOI DUNG
        // ==================================================

        else if (chon == 4)
        {
            suaNguoiDung(
                nd,
                viTriAdmin
            );
        }


        // ==================================================
        // XEM DON HANG
        // ==================================================

        else if (chon == 5)
        {
            xemDonHang(dsDonHang);
        }


        // ==================================================
        // XEM SAN PHAM
        // ==================================================

        else if (chon == 6)
        {
            xemSanPham(sp);
        }


        // ==================================================
        // QUAN LY SAN PHAM
        // ==================================================

        else if (chon == 7)
        {
            menuSanPham(sp);
        }


        else if (chon != 0)
        {
            cout << "\nLua chon khong hop le!\n";
        }

    } while (chon != 0);
}


// ==================================================
// MENU STAFF
// ==================================================

void menuStaff(
    vector<SanPham>& sp
)
{
    cout << "\nDang nhap quyen STAFF thanh cong!\n";

    menuSanPham(sp);
}

#endif