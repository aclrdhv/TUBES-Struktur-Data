#ifndef FINAL_PROJECT_H_INCLUDED
#define FINAL_PROJECT_H_INCLUDED

#include <iostream>
#include <iomanip>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define first(L) ((L).first)
#define mhs(P) (P)->mhs
#define dsn(P) (P)->dsn
#define nil NULL

const int table_w = 12;

// list mahasiswa
typedef struct elm_mahasiswa *adr_mahasiswa;
struct infotype_mahasiswa
{
    string nim, nama, kelas;
};
struct elm_mahasiswa
{
    infotype_mahasiswa info;
    adr_mahasiswa next, prev;
};
struct list_mahasiswa
{
    adr_mahasiswa first;
};

// list dosen pembimbing
typedef struct elm_dosbing *adr_dosbing;
struct infotype_dosbing
{
    string nip, nama;
};
struct elm_dosbing
{
    infotype_dosbing info;
    adr_dosbing next, prev;
};
struct list_dosbing
{
    adr_dosbing first;
};

// list relasi
typedef struct elm_relasi *adr_relasi;
struct elm_relasi
{
    adr_mahasiswa mhs;
    adr_dosbing dsn;
    adr_relasi next;
};
struct list_relasi
{
    adr_relasi first;
};

/*
a. Menambahkan data mahasiswa.
b. Menambahkan data dosen pembimbing.
c. Mencari data mahasiswa tertentu.
d. Menambahkan relasi data dosen pembimbing dengan mahasiswa dan sebaliknya.
e. Mencari data mahasiswa yang dibimbing oleh dosen tertentu.
f. Menghapus dosen beserta relasinya.
g. Menghapus data dosen pembimbing yang membimbing mahasiswa tertentu.
h. Menampilkan seluruh data mahasiswa beserta semua data dosen pembimbing satu dan
duanya.
i. Menampilkan data dosen pembimbing dengan jumlah bimbingan terbanyak.
j. Menampilkan data mahasiswa yang hanya memiliki pembimbing tunggal.
k. Program utama dari aplikasi Final Project.
*/

list_mahasiswa create_list_mahasiswa();
list_dosbing create_list_dosbing();
list_relasi create_list_relasi();

void print_mahasiswa(list_mahasiswa LM);
void print_dosbing(list_dosbing LD);
void print_relasi(list_relasi LR);

adr_mahasiswa create_mahasiswa(infotype_mahasiswa x);
adr_dosbing create_dosbing(infotype_dosbing x);

void add_mahasiswa(list_mahasiswa &LM, adr_mahasiswa P);
void add_dosbing(list_dosbing &LD, adr_dosbing P);

adr_mahasiswa find_mahasiswa(list_mahasiswa LM, string nim);
adr_dosbing find_dosbing(list_dosbing LD, string nip);

int jumlah_pembimbing(list_relasi LR, adr_mahasiswa P);
int pembimbing_ke(list_relasi LR, adr_dosbing PD, adr_mahasiswa PM);
void add_relasi(list_mahasiswa &LM, list_dosbing &LD, list_relasi &LR, string nim, string nip);
list_mahasiswa find_mahasiswa_by_dosbing(list_relasi LR, string nip);

void delete_dosbing(list_dosbing &LD, list_relasi &LR, string nip);
void delete_dosbing_by_mahasiswa(list_mahasiswa &LM, list_dosbing &LD, list_relasi &LR, string nim);

void print_mahasiswa_dosbing(list_mahasiswa LM, list_dosbing LD, list_relasi LR);
int jumlah_dibimbing(list_relasi LR, adr_dosbing P);
void print_dosbing_max(list_dosbing LD, list_relasi LR);
void print_mahasiswa_tunggal(list_relasi LR);

#endif // FINAL_PROJECT_H_INCLUDED
