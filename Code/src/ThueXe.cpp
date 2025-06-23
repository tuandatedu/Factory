#include "ThueXe.h"
#include <iostream>
using namespace std;

vector<Xe*> Xe::danhSachXeMau;

Xe::Xe() {
    bienSo = "";
    soChoNgoi = 0;
}

Xe::Xe(const Xe& xe) {
    bienSo = xe.bienSo;
    soChoNgoi = xe.soChoNgoi;
}

// Static methods
void Xe::themXeMau(Xe* xe) {
    if (xe == nullptr) return;
    for (auto x : danhSachXeMau) {
        if (x->getLoaiXe() == xe->getLoaiXe()) return;
    }
    danhSachXeMau.push_back(xe);
}

Xe* Xe::taoXe(string loaiXe) {
    for (auto x : danhSachXeMau) {
        if (x->getLoaiXe() == loaiXe) {
            return x->Clone();
        }
    }
    cout << "Khong tim thay loai xe: " << loaiXe << endl;
    return nullptr;
}

void Xe::xoaXeMau() {
    for (auto x : danhSachXeMau) {
        delete x;
    }
    danhSachXeMau.clear();
}

void Xe::nhapXe() {
    cout << "Nhap bien so: ";
    getline(cin, bienSo);

    cout << "Nhap so cho ngoi: ";
    cin >> soChoNgoi;
}

void Xe::xuatXe() {
    cout << "Bien so: " << bienSo << endl;
    cout << "So cho ngoi: " << soChoNgoi << endl;
    cout << "Loai xe: " << getLoaiXe() << endl;
}

void Xe::setBienSo(string bienSo) {
    this->bienSo = bienSo;
}

void Xe::setSoChoNgoi(int soChoNgoi) {
    this->soChoNgoi = soChoNgoi;
}

string Xe::getBienSo() const {
    return bienSo;
}

int Xe::getSoChoNgoi() const {
    return soChoNgoi;
}

ThueXe::ThueXe() {
    xe = nullptr;
    ngayThue.d = 0;
    ngayThue.m = 0;
    ngayThue.y = 0;
    gioBatDau.h = 0;
    gioBatDau.m = 0;
    gioKetThuc.h = 0;
    gioKetThuc.m = 0;
    thanhPhoDangO = "";
}

ThueXe::ThueXe(Xe* xe, Ngay ngay, Gio batDau, Gio ketThuc, string thanhPho) {
    this->xe = xe;
    this->ngayThue = ngay;
    this->gioBatDau = batDau;
    this->gioKetThuc = ketThuc;
    this->thanhPhoDangO = thanhPho;
}

ThueXe::~ThueXe() {
    delete xe;
}

void ThueXe::nhapThongTinThue() {
    string loai;
    cout << "Nhap loai xe (Xe may/Xe dap/O to tu lai): ";
    getline(cin, loai);
    xe = XeFactory::createXe(loai);

    if (xe == nullptr) return;

    xe->nhapXe();

    cout << "Nhap ngay thue (dd mm yyyy): ";
    cin >> ngayThue.d;
    cin >> ngayThue.m;
    cin >> ngayThue.y;

    cout << "Nhap gio bat dau (hh mm): ";
    cin >> gioBatDau.h;
    cin >> gioBatDau.m;

    cout << "Nhap gio ket thuc (hh mm): ";
    cin >> gioKetThuc.h;
    cin >> gioKetThuc.m;

    cout << "Nhap thanh pho dang o: ";
    getline(cin, thanhPhoDangO);
}

void ThueXe::xuatThongTinThue() const {
    if (xe) xe->xuatXe();

    cout << "Ngay thue: " << ngayThue.d << "/" << ngayThue.m << "/" << ngayThue.y << endl;
    cout << "Gio bat dau: " << gioBatDau.h << ":" << gioBatDau.m << endl;
    cout << "Gio ket thuc: " << gioKetThuc.h << ":" << gioKetThuc.m << endl;
    cout << "Thanh pho dang o: " << thanhPhoDangO << endl;
}

Xe* XeFactory::createXe(const string& loaiXe) {
    return Xe::taoXe(loaiXe);
}
