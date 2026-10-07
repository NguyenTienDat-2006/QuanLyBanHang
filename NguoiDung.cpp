#include "NguoiDung.h"
#include "KiemTra.h"

// ==================================================
// CLASS NGUOI DUNG
// ==================================================

NguoiDung::NguoiDung()
{
}


NguoiDung::NguoiDung(
    string id,
    string ma,
    string tk,
    string mk,
    string vt,
    string ten,
    string cv,
    string phone,
    string dc
)
    : id(id),
      maND(ma),
      taiKhoan(tk),
      matKhau(mk),
      vaiTro(vt),
      hoTen(ten),
      chucVu(cv),
      sdt(phone),
      diaChi(dc)
{
}


// ==================================================
// GETTER
// ==================================================

string NguoiDung::getID()
{
    return id;
}

string NguoiDung::getMaND()
{
    return maND;
}

string NguoiDung::getTaiKhoan()
{
    return taiKhoan;
}

string NguoiDung::getMatKhau()
{
    return matKhau;
}

string NguoiDung::getVaiTro()
{
    return vaiTro;
}

string NguoiDung::getHoTen()
{
    return hoTen;
}

string NguoiDung::getChucVu()
{
    return chucVu;
}

string NguoiDung::getSDT()
{
    return sdt;
}

string NguoiDung::getDiaChi()
{
    return diaChi;
}


// ==================================================
// SETTER
// ==================================================

void NguoiDung::setMatKhau(string mk)
{
    matKhau = mk;
}

void NguoiDung::setHoTen(string ten)
{
    hoTen = ten;
}

void NguoiDung::setChucVu(string cv)
{
    chucVu = cv;
}

void NguoiDung::setSDT(string phone)
{
    sdt = phone;
}

void NguoiDung::setDiaChi(string dc)
{
    diaChi = dc;
}


// ==================================================
// NHAP NGUOI DUNG CHO ADMIN
// Chi ADMIN / STAFF
// ==================================================

void NguoiDung::nhapAdmin(
    int stt,
    vector<NguoiDung>& ds
)
{
    id = "ND" + to_string(stt);

    cout << "\nID tu dong: " << id << endl;


    // ==================================================
    // CHON VAI TRO
    // ==================================================

    int chonVaiTro;

    do
    {
        cout << "\n========== CHON VAI TRO ==========\n";
        cout << "1. ADMIN\n";
        cout << "2. STAFF\n";
        cout << "Chon: ";
        cin >> chonVaiTro;

        if (chonVaiTro != 1 && chonVaiTro != 2)
            cout << "Vai tro khong hop le!\n";

    } while (chonVaiTro != 1 && chonVaiTro != 2);


    if (chonVaiTro == 1)
        vaiTro = "ADMIN";
    else
        vaiTro = "STAFF";


    // ==================================================
    // SINH MA TU DONG
    // ==================================================

    string prefix;

    if (vaiTro == "ADMIN")
        prefix = "admin";
    else
        prefix = "staff";


    int soLonNhat = 99999;

    for (auto &nd : ds)
    {
        string ma = nd.getMaND();

        if (ma.find(prefix) == 0)
        {
            string phanSo = ma.substr(prefix.length());

            bool hopLe = true;

            if (phanSo.empty())
                hopLe = false;

            for (char c : phanSo)
            {
                if (!isdigit((unsigned char)c))
                {
                    hopLe = false;
                    break;
                }
            }

            if (hopLe)
            {
                int so = atoi(phanSo.c_str());

                if (so > soLonNhat)
                    soLonNhat = so;
            }
        }
    }

    soLonNhat++;

    stringstream ss;
    ss << soLonNhat;

    maND = prefix + ss.str();

    cout << "Ma nguoi dung tu dong: "
         << maND
         << endl;


    // ==================================================
    // TAI KHOAN
    // ==================================================

    do
    {
        cout << "\nTai khoan (toi da 12 ky tu): ";
        cin >> taiKhoan;

        if (!kiemTraTaiKhoan(taiKhoan))
        {
            cout << "\nTai khoan khong hop le!\n";
            cout << "- Toi da 12 ky tu\n";
            cout << "- Ky tu dau tien phai la chu cai\n";
            cout << "- Chi gom chu cai va chu so\n";
        }

        else if (trungTaiKhoan(ds, taiKhoan))
        {
            cout << "Tai khoan da ton tai!\n";
        }

    } while (
        !kiemTraTaiKhoan(taiKhoan) ||
        trungTaiKhoan(ds, taiKhoan)
    );


    // ==================================================
    // MAT KHAU
    // ==================================================

    do
    {
        cout << "\nMat khau:\n";
        cout << "- It nhat 8 ky tu\n";
        cout << "- Co chu hoa\n";
        cout << "- Co chu thuong\n";
        cout << "- Co ky tu dac biet\n";

        cout << "Nhap mat khau: ";

        matKhau = nhapMatKhau();

        if (!kiemTraMatKhau(matKhau))
        {
            cout << "\nMat khau khong hop le!\n";
        }

    } while (!kiemTraMatKhau(matKhau));


    // ==================================================
    // HO TEN
    // ==================================================

    cin.ignore();

    do
    {
        cout << "\nHo va ten: ";
        getline(cin, hoTen);

        if (!kiemTraHoTen(hoTen))
            cout << "Ho ten khong duoc de trong!\n";

    } while (!kiemTraHoTen(hoTen));


    // ==================================================
    // CHUC VU
    // ==================================================

    int chonChucVu;

    do
    {
        cout << "\n========== CHON CHUC VU ==========\n";
        cout << "1. Giam doc\n";
        cout << "2. Nhan vien\n";
        cout << "Chon: ";

        cin >> chonChucVu;

        if (chonChucVu != 1 && chonChucVu != 2)
            cout << "Chuc vu khong hop le!\n";

    } while (chonChucVu != 1 && chonChucVu != 2);


    if (chonChucVu == 1)
        chucVu = "Giam doc";
    else
        chucVu = "Nhan vien";


    // ==================================================
    // SDT
    // ==================================================

    do
    {
        cout << "So dien thoai (10 chu so): ";
        cin >> sdt;

        if (!kiemTraSDT(sdt))
            cout << "SDT khong hop le!\n";

    } while (!kiemTraSDT(sdt));


    // ==================================================
    // DIA CHI
    // ==================================================

    cin.ignore();

    cout << "Dia chi: ";
    getline(cin, diaChi);
}


// ==================================================
// NHAP KHACH HANG
// ==================================================

void NguoiDung::nhapKhachHang(
    int stt,
    vector<NguoiDung>& ds
)
{
    id = "ND" + to_string(stt);

    cout << "\nID tu dong: " << id << endl;


    // CUSTOMER tu dong
    vaiTro = "CUSTOMER";


    // Sinh ma customer
    string prefix = "customer";

    int soLonNhat = 99999;

    for (auto &nd : ds)
    {
        string ma = nd.getMaND();

        if (ma.find(prefix) == 0)
        {
            string phanSo = ma.substr(prefix.length());

            bool hopLe = true;

            if (phanSo.empty())
                hopLe = false;

            for (char c : phanSo)
            {
                if (!isdigit((unsigned char)c))
                {
                    hopLe = false;
                    break;
                }
            }

            if (hopLe)
            {
                int so = atoi(phanSo.c_str());

                if (so > soLonNhat)
                    soLonNhat = so;
            }
        }
    }

    soLonNhat++;

    stringstream ss;
    ss << soLonNhat;

    maND = prefix + ss.str();

    cout << "Ma nguoi dung tu dong: "
         << maND
         << endl;


    // ==================================================
    // TAI KHOAN
    // ==================================================

    do
    {
        cout << "\nTai khoan (toi da 12 ky tu): ";
        cin >> taiKhoan;

        if (!kiemTraTaiKhoan(taiKhoan))
        {
            cout << "\nTai khoan khong hop le!\n";
            cout << "- Toi da 12 ky tu\n";
            cout << "- Ky tu dau tien phai la chu cai\n";
            cout << "- Chi gom chu cai va chu so\n";
        }

        else if (trungTaiKhoan(ds, taiKhoan))
        {
            cout << "Tai khoan da ton tai!\n";
        }

    } while (
        !kiemTraTaiKhoan(taiKhoan) ||
        trungTaiKhoan(ds, taiKhoan)
    );


    // ==================================================
    // MAT KHAU
    // ==================================================

    do
    {
        cout << "\nMat khau:\n";
        cout << "- It nhat 8 ky tu\n";
        cout << "- Co chu hoa\n";
        cout << "- Co chu thuong\n";
        cout << "- Co ky tu dac biet\n";

        cout << "Nhap mat khau: ";

        matKhau = nhapMatKhau();

        if (!kiemTraMatKhau(matKhau))
            cout << "Mat khau khong hop le!\n";

    } while (!kiemTraMatKhau(matKhau));


    // ==================================================
    // HO TEN
    // ==================================================

    cin.ignore();

    do
    {
        cout << "Ho va ten: ";
        getline(cin, hoTen);

        if (!kiemTraHoTen(hoTen))
            cout << "Ho ten khong duoc de trong!\n";

    } while (!kiemTraHoTen(hoTen));


    // ==================================================
    // SDT
    // ==================================================

    do
    {
        cout << "So dien thoai (10 chu so): ";
        getline(cin, sdt);

        if (!kiemTraSDT(sdt))
            cout << "SDT phai gom dung 10 chu so!\n";

    } while (!kiemTraSDT(sdt));


    // ==================================================
    // DIA CHI
    // ==================================================

    cout << "Dia chi: ";
    getline(cin, diaChi);

    chucVu = "Khach hang";
}


// ==================================================
// XUAT
// ==================================================

void NguoiDung::xuat()
{
    cout << left
         << setw(8) << id
         << setw(15) << maND
         << setw(15) << taiKhoan
         << setw(12) << vaiTro
         << setw(25) << hoTen
         << setw(15) << chucVu
         << setw(13) << sdt
         << diaChi
         << endl;
}


// ==================================================
// KIEM TRA TAI KHOAN TRUNG
// ==================================================

bool NguoiDung::trungTaiKhoan(
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