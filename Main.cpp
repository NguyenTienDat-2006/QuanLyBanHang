#include <bits/stdc++.h>

#include "KiemTra.h"
#include "NguoiDung.h"
#include "SanPham.h"
#include "ChiTietGioHang.h"
#include "DonHang.h"
#include "QuanLySanPham.h"
#include "QuanLyNguoiDung.h"
#include "Menu.h"

using namespace std;


// ==================================================
// MAIN
// ==================================================

int main()
{
    // ==================================================
    // TAI KHOAN MAC DINH
    // ==================================================

    vector<NguoiDung> dsNguoiDung =
    {
        NguoiDung(
            "ND1",
            "admin100000",
            "admin",
            "Admin@123",
            "ADMIN",
            "Quan tri vien",
            "Giam doc",
            "0900000000",
            "Ha Noi"
        ),

        NguoiDung(
            "ND2",
            "staff100000",
            "staff",
            "Staff@123",
            "STAFF",
            "Nhan vien",
            "Nhan vien",
            "0911111111",
            "Ha Noi"
        )
    };


    // ==================================================
    // SAN PHAM MAU
    // ==================================================

    vector<SanPham> dsSanPham =
    {
        SanPham(
            "SP1",
            "SP001",
            "Laptop Dell",
            10,
            15000000
        ),

        SanPham(
            "SP2",
            "SP002",
            "Ban phim",
            20,
            500000
        ),

        SanPham(
            "SP3",
            "SP003",
            "Chuot",
            30,
            300000
        )
    };


    // ==================================================
    // DANH SACH DON HANG
    // ==================================================

    vector<DonHang> dsDonHang;


    // ==================================================
    // MENU CHINH
    // ==================================================

    int chon;


    do
    {
        cout << "\n";
        cout << "========================================\n";
        cout << "       HE THONG QUAN LY BAN HANG\n";
        cout << "========================================\n";

        cout << "1. Quan tri\n";
        cout << "2. Khach hang\n";
        cout << "0. Thoat\n";

        cout << "Chon: ";
        cin >> chon;


        // ==================================================
        // QUAN TRI
        // ==================================================

        if (chon == 1)
        {
            int loai;


            cout << "\n========== QUAN TRI ==========\n";

            cout << "1. Admin\n";
            cout << "2. Staff\n";
            cout << "0. Quay lai\n";

            cout << "Chon: ";
            cin >> loai;


            if (loai == 1 || loai == 2)
            {
                int vt = dangNhap(dsNguoiDung);


                if (vt == -1)
                {
                    cout << "\nSai tai khoan hoac mat khau!\n";
                }


                // ==================================================
                // ADMIN
                // ==================================================

                else if (
                    loai == 1 &&
                    dsNguoiDung[vt].getVaiTro() == "ADMIN"
                )
                {
                    cout << "\nDang nhap ADMIN thanh cong!\n";

                    menuAdmin(
                        dsNguoiDung,
                        dsSanPham,
                        dsDonHang,
                        vt
                    );
                }


                // ==================================================
                // STAFF
                // ==================================================

                else if (
                    loai == 2 &&
                    dsNguoiDung[vt].getVaiTro() == "STAFF"
                )
                {
                    menuStaff(dsSanPham);
                }


                else
                {
                    cout << "\nTai khoan khong dung vai tro!\n";
                }
            }
        }


        // ==================================================
        // KHACH HANG
        // ==================================================

        else if (chon == 2)
        {
            menuKhachHang(
                dsSanPham,
                dsNguoiDung,
                dsDonHang
            );
        }


        else if (chon != 0)
        {
            cout << "\nLua chon khong hop le!\n";
        }

    } while (chon != 0);


    cout << "\nCam on ban da su dung chuong trinh!\n";


    return 0;
}