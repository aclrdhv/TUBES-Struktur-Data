#include "final_project.h"

list_mahasiswa create_list_mahasiswa()
{
    list_mahasiswa LM;
    first(LM) = nil;
    return LM;
}

list_dosbing create_list_dosbing()
{
    list_dosbing LD;
    first(LD) = nil;
    return LD;
}

list_relasi create_list_relasi()
{
    list_relasi LR;
    first(LR) = nil;
    return LR;
}

void print_mahasiswa(list_mahasiswa LM)
{
    adr_mahasiswa Q = first(LM);
    cout << "=============== Mahasiswa ===============" << endl;
    if (Q == nil)
    {
        cout << "List Mahasiswa kosong" << endl;
    }
    else
    {
        cout << left << setw(table_w) << "NIM";
        cout << left << setw(table_w) << "Nama";
        cout << left << setw(table_w) << "Kelas" << endl;
        while (Q != nil)
        {
            cout << left << setw(table_w) << info(Q).nim;
            cout << left << setw(table_w) << info(Q).nama;
            cout << left << setw(table_w) << info(Q).kelas << endl;
            Q = next(Q);
        }
    }
    cout << "========================================" << endl
         << endl;
}

void print_dosbing(list_dosbing LD)
{
    adr_dosbing Q = first(LD);
    cout << "========== Dosen Pembimbing ==========" << endl;
    if (Q == nil)
    {
        cout << "List Dosen Pembimbing kosong" << endl;
    }
    else
    {
        cout << left << setw(table_w) << "NIP";
        cout << left << setw(table_w) << "Nama" << endl;
        while (Q != nil)
        {
            cout << left << setw(table_w) << info(Q).nip;
            cout << left << setw(table_w) << info(Q).nama << endl;
            Q = next(Q);
        }
    }
    cout << "====================================" << endl
         << endl;
}
void print_relasi(list_relasi LR)
{
    adr_relasi Q = first(LR);
    cout << "============== Relasi ==============" << endl;
    if (Q == nil)
    {
        cout << "List Relasi kosong" << endl;
    }
    else
    {
        cout << left << setw(table_w) << "NIM";
        cout << left << setw(table_w) << "Nama";
        cout << left << setw(table_w) << "Kelas";
        cout << left << setw(table_w) << "NIP";
        cout << left << setw(table_w) << "Nama" << endl;
        while (Q != nil)
        {
            cout << left << setw(table_w) << info(mhs(Q)).nim;
            cout << left << setw(table_w) << info(mhs(Q)).nama;
            cout << left << setw(table_w) << info(mhs(Q)).kelas;
            cout << left << setw(table_w) << info(dsn(Q)).nip;
            cout << left << setw(table_w) << info(dsn(Q)).nama << endl;
            Q = next(Q);
        }
    }
    cout << "====================================" << endl
         << endl;
}

adr_mahasiswa create_mahasiswa(infotype_mahasiswa x)
{
    adr_mahasiswa P = new elm_mahasiswa;
    info(P) = x;
    next(P) = nil;
    prev(P) = nil;
    return P;
}

adr_dosbing create_dosbing(infotype_dosbing x)
{
    adr_dosbing P = new elm_dosbing;
    info(P) = x;
    next(P) = nil;
    prev(P) = nil;
    return P;
}

void add_mahasiswa(list_mahasiswa &LM, adr_mahasiswa P)
{
    adr_mahasiswa Q = first(LM);
    if (Q == nil)
    {
        first(LM) = P;
    }
    else
    {
        while (next(Q) != nil)
        {
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
}

void add_dosbing(list_dosbing &LD, adr_dosbing P)
{
    adr_dosbing Q = first(LD);
    if (Q == nil)
    {
        first(LD) = P;
    }
    else
    {
        while (next(Q) != nil)
        {
            Q = next(Q);
        }
        next(Q) = P;
        prev(P) = Q;
    }
}

adr_mahasiswa find_mahasiswa(list_mahasiswa LM, string nim)
{
    adr_mahasiswa Q = first(LM);
    while (Q != nil)
    {
        if (info(Q).nim == nim)
        {
            return Q;
        }
        Q = next(Q);
    }
    return nil;
}

adr_dosbing find_dosbing(list_dosbing LD, string nip)
{
    adr_dosbing Q = first(LD);
    while (Q != nil)
    {
        if (info(Q).nip == nip)
        {
            return Q;
        }
        Q = next(Q);
    }
    return nil;
}

int jumlah_pembimbing(list_relasi LR, adr_mahasiswa P)
{
    int jumlah = 0;
    adr_relasi Q = first(LR);
    while (Q != nil)
    {
        if (mhs(Q) == P)
        {
            jumlah++;
        }
        Q = next(Q);
    }
    return jumlah;
}

int pembimbing_ke(list_relasi LR, adr_dosbing PD, adr_mahasiswa PM)
{
    int jumlah = 0;
    adr_relasi Q = first(LR);
    while (Q != nil)
    {
        if (mhs(Q) == PM)
        {
            jumlah++;
            if (dsn(Q) == PD)
            {
                return jumlah;
            }
        }
        Q = next(Q);
    }
    return 0;
}

void add_relasi(list_mahasiswa &LM, list_dosbing &LD, list_relasi &LR, string nim, string nip)
{
    adr_mahasiswa PM = find_mahasiswa(LM, nim);
    adr_dosbing PD = find_dosbing(LD, nip);
    if (PM != nil && PD != nil)
    {
        // setiap mahasiswa maksimal 2 dosen pembimbing
        int jumlah = jumlah_pembimbing(LR, PM);
        if (jumlah >= 2)
        {
            cout << "Mahasiswa sudah memiliki 2 dosen pembimbing" << endl;
            return;
        }
        // setiap dosen maksimal 3 bimbingan kesatu dan 5 bimbingan kedua
        int ke1 = 0;
        int ke2 = 0;
        adr_relasi Q = first(LR);
        while (Q != nil)
        {
            if (dsn(Q) == PD)
            {
                int ke = pembimbing_ke(LR, PD, mhs(Q));
                if (ke == 1)
                {
                    ke1++;
                }
                else if (ke == 2)
                {
                    ke2++;
                }
            }
            Q = next(Q);
        }
        if (jumlah == 0 && ke1 >= 3)
        {
            cout << "Dosen sudah memiliki 3 bimbingan kesatu" << endl;
            return;
        }
        if (jumlah == 1 && ke2 >= 5)
        {
            cout << "Dosen sudah memiliki 5 bimbingan kedua" << endl;
            return;
        }
        // insert last relasi
        adr_relasi P = new elm_relasi;
        mhs(P) = PM;
        dsn(P) = PD;
        if (first(LR) == nil)
        {
            first(LR) = P;
            next(P) = nil;
        }
        else
        {
            adr_relasi Q = first(LR);
            while (next(Q) != nil)
            {
                Q = next(Q);
            }
            next(Q) = P;
            next(P) = nil;
        }
    }
    else
    {
        cout << "Dosen atau Mahasiswa tidak ditemukan" << endl;
    }
}

list_mahasiswa find_mahasiswa_by_dosbing(list_relasi LR, string nip)
{
    list_mahasiswa LM = create_list_mahasiswa();
    adr_relasi Q = first(LR);
    while (Q != nil)
    {
        if (info(dsn(Q)).nip == nip)
        {
            add_mahasiswa(LM, create_mahasiswa(info(mhs(Q))));
        }
        Q = next(Q);
    }
    return LM;
}

void delete_dosbing(list_dosbing &LD, list_relasi &LR, string nip)
{
    adr_dosbing PD = find_dosbing(LD, nip);
    if (PD != nil && first(LR) != nil)
    {
        adr_relasi Q, prec;
        Q = first(LR);
        prec = nil;
        while (Q != nil)
        {
            if (dsn(Q) == PD)
            {
                // delete relasi
                if (first(LR) == Q)
                {
                    // delete first
                    first(LR) = next(Q);
                    next(Q) = nil;
                    Q = first(LR);
                }
                else if (next(Q) == nil)
                {
                    // delete last
                    next(prec) = next(Q);
                    next(Q) = nil;
                    Q = nil;
                }
                else
                {
                    // delete after
                    next(prec) = next(Q);
                    next(Q) = nil;
                    Q = next(prec);
                }
            }
            else
            {
                prec = Q;
                Q = next(Q);
            }
        }
        // delete dosbing
        if (first(LD) == PD)
        {
            // delete first
            first(LD) = next(PD);
            next(PD) = nil;
            prev(PD) = nil;
        }
        else if (next(PD) == nil)
        {
            // delete last
            next(prev(PD)) = nil;
            next(PD) = nil;
            prev(PD) = nil;
        }
        else
        {
            // delete after
            next(prev(PD)) = next(PD);
            prev(next(PD)) = prev(PD);
            next(PD) = nil;
            prev(PD) = nil;
        }
    }
    else
    {
        cout << "Dosen tidak ditemukan" << endl;
    }
}

void delete_dosbing_by_mahasiswa(list_mahasiswa &LM, list_dosbing &LD, list_relasi &LR, string nim)
{
    adr_mahasiswa PM = find_mahasiswa(LM, nim);
    if (PM != nil && first(LR) != nil)
    {
        adr_relasi Q, prec;
        Q = first(LR);
        prec = nil;
        while (Q != nil)
        {
            prec = Q;
            Q = next(Q);
            if (mhs(prec) == PM)
            {
                delete_dosbing(LD, LR, info(dsn(prec)).nip);
                Q = first(LR);
            }
        }
    }
    else
    {
        cout << "Mahasiswa tidak ditemukan" << endl;
    }
}

void print_mahasiswa_dosbing(list_mahasiswa LM, list_dosbing LD, list_relasi LR)
{
    adr_mahasiswa PM = first(LM);
    cout << "==== Mahasiswa & Dosen Pembimbing ====" << endl;
    while (PM != nil)
    {
        cout << info(PM).nama << " ";
        cout << "(" << info(PM).nim << ") ";
        cout << "Dibimbing oleh:" << endl;
        adr_relasi Q = first(LR);
        int ke = 0;
        while (Q != nil)
        {
            if (mhs(Q) == PM)
            {
                ke++;
                cout << ke << ". ";
                cout << info(dsn(Q)).nama << " ";
                cout << "(" << info(dsn(Q)).nip << ")" << endl;
            }
            Q = next(Q);
        }
        if (ke == 0)
        {
            cout << "Tidak ada" << endl;
        }
        cout << endl;
        PM = next(PM);
    }
    cout << "======================================" << endl
         << endl;
}

int jumlah_dibimbing(list_relasi LR, adr_dosbing P)
{
    int jumlah = 0;
    adr_relasi Q = first(LR);
    while (Q != nil)
    {
        if (dsn(Q) == P)
        {
            jumlah++;
        }
        Q = next(Q);
    }
    return jumlah;
}

void print_dosbing_max(list_dosbing LD, list_relasi LR)
{
    adr_dosbing PD, MD;
    PD = first(LD);
    MD = nil;
    int max = 0;
    while (PD != nil)
    {
        int jumlah = jumlah_dibimbing(LR, PD);
        if (jumlah > max)
        {
            max = jumlah;
            MD = PD;
        }
        PD = next(PD);
    }
    cout << "===== Dosen Bimbingan Terbanyak =====" << endl;
    if (MD == nil)
    {
        cout << "Dosen tidak ditemukan" << endl;
    }
    else
    {
        cout << info(MD).nama << " ";
        cout << "(" << info(MD).nip << ")" << endl;
        cout << "Jumlah Mahasiswa Bimbingan: " << max << endl;
    }
    cout << "====================================" << endl
         << endl;
}

void print_mahasiswa_tunggal(list_relasi LR)
{
    adr_relasi Q = first(LR);
    int jumlah = 0;
    cout << "=== Mahasiswa Pembimbing Tunggal ===" << endl;
    while (Q != nil)
    {
        if (jumlah_pembimbing(LR, mhs(Q)) == 1)
        {
            cout << info(mhs(Q)).nama << " ";
            cout << "(" << info(mhs(Q)).nim << ")" << endl;
            jumlah++;
        }
        Q = next(Q);
    }
    if (jumlah == 0)
    {
        cout << "Tidak ada" << endl;
    }
    cout << "====================================" << endl
         << endl;
}
