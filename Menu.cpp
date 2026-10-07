#include "Menu.h"

#include "QuanLyNguoiDung.h"
#include "QuanLySanPham.h"

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