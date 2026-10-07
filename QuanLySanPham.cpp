#include "QuanLySanPham.h"

// ==================================================
// QUAN LY SAN PHAM
// ==================================================

void xemSanPham(vector<SanPham>& ds)
{
    if (ds.empty())
    {
        cout << "\nDanh sach san pham rong!\n";
        return;
    }

    cout << "\n========== DANH SACH SAN PHAM ==========\n";

    cout << left
         << setw(8) << "ID"
         << setw(15) << "Ma SP"
         << setw(30) << "Ten SP"
         << setw(12) << "So luong"
         << "Don gia"
         << endl;

    cout << string(80, '-') << endl;

    for (auto &sp : ds)
        sp.xuat();
}


// ==================================================
// THEM SAN PHAM
// ==================================================

void themSanPham(vector<SanPham>& ds)
{
    SanPham sp;

    sp.nhap(ds.size() + 1);

    ds.push_back(sp);

    cout << "\nThem san pham thanh cong!\n";
}


// ==================================================
// XOA SAN PHAM
// ==================================================

void xoaSanPham(vector<SanPham>& ds)
{
    string ma;

    cout << "Nhap ma san pham can xoa: ";
    cin >> ma;

    for (int i = 0; i < (int)ds.size(); i++)
    {
        if (ds[i].getMaSP() == ma)
        {
            char xacNhan;

            cout << "Ban co chac chan muon xoa? (Y/N): ";
            cin >> xacNhan;

            if (xacNhan == 'Y' || xacNhan == 'y')
            {
                ds.erase(ds.begin() + i);

                cout << "Xoa san pham thanh cong!\n";
            }
            else
            {
                cout << "Da huy xoa.\n";
            }

            return;
        }
    }

    cout << "Khong tim thay san pham!\n";
}


// ==================================================
// SUA SAN PHAM
// ==================================================

void suaSanPham(vector<SanPham>& ds)
{
    if (ds.empty())
    {
        cout << "\nDanh sach san pham rong!\n";
        return;
    }

    xemSanPham(ds);

    string ma;

    cout << "\nNhap ma san pham can sua: ";
    cin >> ma;

    int viTri = -1;

    for (int i = 0; i < (int)ds.size(); i++)
    {
        if (ds[i].getMaSP() == ma)
        {
            viTri = i;
            break;
        }
    }

    if (viTri == -1)
    {
        cout << "Khong tim thay san pham!\n";
        return;
    }

    cin.ignore();

    string tenMoi;
    int soLuongMoi;
    double donGiaMoi;

    do
    {
        cout << "Ten san pham moi: ";
        getline(cin, tenMoi);

        if (tenMoi.empty())
            cout << "Ten san pham khong duoc de trong!\n";

    } while (tenMoi.empty());

    do
    {
        cout << "So luong moi: ";
        cin >> soLuongMoi;

        if (cin.fail() || soLuongMoi < 0)
        {
            cout << "So luong phai la so nguyen khong am!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (cin.fail() || soLuongMoi < 0);

    do
    {
        cout << "Don gia moi: ";
        cin >> donGiaMoi;

        if (cin.fail() || donGiaMoi < 0)
        {
            cout << "Don gia phai la so thuc khong am!\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (cin.fail() || donGiaMoi < 0);

    char xacNhan;

    cout << "\nBan co chac chan muon sua san pham nay? (Y/N): ";
    cin >> xacNhan;

    if (xacNhan == 'Y' || xacNhan == 'y')
    {
        ds[viTri].setTenSP(tenMoi);
        ds[viTri].setSoLuong(soLuongMoi);
        ds[viTri].setDonGia(donGiaMoi);

        cout << "\nSua san pham thanh cong!\n";
    }
    else
    {
        cout << "\nDa huy thao tac sua.\n";
    }
}


// ==================================================
// MENU SAN PHAM
// ==================================================

void menuSanPham(vector<SanPham>& ds)
{
    int chon;

    do
    {
        cout << "\n========== QUAN LY SAN PHAM ==========\n";
        cout << "1. Them san pham\n";
        cout << "2. Xem san pham\n";
        cout << "3. Sua san pham\n";
        cout << "4. Xoa san pham\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";

        cin >> chon;

        if (chon == 1)
            themSanPham(ds);

        else if (chon == 2)
            xemSanPham(ds);

        else if (chon == 3)
            suaSanPham(ds);

        else if (chon == 4)
            xoaSanPham(ds);

        else if (chon != 0)
            cout << "Lua chon khong hop le!\n";

    } while (chon != 0);
}