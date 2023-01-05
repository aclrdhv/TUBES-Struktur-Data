#include "final_project.h"

char menu()
{
    cout << "=============== MENU UTAMA ===============" << endl;
    cout << "a. Menambahkan data mahasiswa." << endl;
    cout << "b. Menambahkan data dosen pembimbing." << endl;
    cout << "c. Mencari data mahasiswa tertentu." << endl;
    cout << "d. Menambahkan relasi data dosen pembimbing dengan mahasiswa dan sebaliknya." << endl;
    cout << "e. Mencari data mahasiswa yang dibimbing oleh dosen tertentu." << endl;
    cout << "f. Menghapus dosen beserta relasinya." << endl;
    cout << "g. Menghapus data dosen pembimbing yang membimbing mahasiswa tertentu." << endl;
    cout << "h. Menampilkan seluruh data mahasiswa beserta semua data dosen pembimbing satu dan duanya." << endl;
    cout << "i. Menampilkan data dosen pembimbing dengan jumlah bimbingan terbanyak." << endl;
    cout << "j. Menampilkan data mahasiswa yang hanya memiliki pembimbing tunggal." << endl;
    cout << "k. Menampilkan semua data mahasiswa dan semua data dosen pembimbing" << endl;
    cout << "z. EXIT" << endl;
    cout << "==========================================" << endl;
    cout << "Pilihan: ";
    char pilihan;
    cin >> pilihan;
    cout << endl;
    return pilihan;
}

int main()
{
    list_mahasiswa LM = create_list_mahasiswa();
    list_dosbing LD = create_list_dosbing();
    list_relasi LR = create_list_relasi();

    adr_mahasiswa PM;
    adr_dosbing PD;

    // // Mahasiswa
    PM = create_mahasiswa(infotype_mahasiswa{"123", "Luthfi", "IF4511"});
    add_mahasiswa(LM, PM);
    PM = create_mahasiswa(infotype_mahasiswa{"234", "Marcell", "IF4511"});
    add_mahasiswa(LM, PM);
    PM = create_mahasiswa(infotype_mahasiswa{"345", "Khusyasy", "IF4511"});
    add_mahasiswa(LM, PM);
    PM = create_mahasiswa(infotype_mahasiswa{"456", "Muhammad", "IF4511"});
    add_mahasiswa(LM, PM);
    PM = create_mahasiswa(infotype_mahasiswa{"567", "Budi", "IF4511"});
    add_mahasiswa(LM, PM);
    PM = create_mahasiswa(infotype_mahasiswa{"678", "Agus", "IF4511"});
    add_mahasiswa(LM, PM);
    print_mahasiswa(LM);

    // // Dosen
    PD = create_dosbing(infotype_dosbing{"321", "Angga"});
    add_dosbing(LD, PD);
    PD = create_dosbing(infotype_dosbing{"432", "Budiono"});
    add_dosbing(LD, PD);
    PD = create_dosbing(infotype_dosbing{"543", "Cahya"});
    add_dosbing(LD, PD);
    print_dosbing(LD);

    // buat relasi
    add_relasi(LM, LD, LR, "123", "321");
    add_relasi(LM, LD, LR, "234", "321");
    add_relasi(LM, LD, LR, "345", "321");
    add_relasi(LM, LD, LR, "456", "432");
    add_relasi(LM, LD, LR, "567", "432");

    add_relasi(LM, LD, LR, "123", "543");
    add_relasi(LM, LD, LR, "234", "543");
    add_relasi(LM, LD, LR, "345", "543");
    add_relasi(LM, LD, LR, "456", "543");
    add_relasi(LM, LD, LR, "567", "543");

    add_relasi(LM, LD, LR, "678", "543");
    print_mahasiswa_dosbing(LM, LD, LR);

    print_dosbing_max(LD, LR);
    print_mahasiswa_tunggal(LR);

    // hapus dosen
    cout << "Menghapus dosen dengan NIP 432" << endl;
    delete_dosbing(LD, LR, "432");
    print_mahasiswa_dosbing(LM, LD, LR);

    print_dosbing(LD);

    cout << "Menghapus dosen yang membimbing mahasiswa dengan NIM 456" << endl;
    delete_dosbing_by_mahasiswa(LM, LD, LR, "456");
    print_mahasiswa_dosbing(LM, LD, LR);

    // menu
    infotype_mahasiswa XM;
    infotype_dosbing XD;
    list_mahasiswa LM2;
    string nim, nip;
    char pilihan = menu();
    char lanjut = 'y';
    int jumlah;
    while (pilihan != 'z' && lanjut != 'n')
    {
        if (pilihan == 'a')
        {
            cout << "Jumlah mahasiswa yang ingin dimasukkan: ";
            cin >> jumlah;
            for (int i = 1; i <= jumlah; i++)
            {
                cout << "Masukkan data mahasiswa ke-" << i << endl;
                cout << "NIM: ";
                cin >> XM.nim;
                cout << "Nama: ";
                cin >> XM.nama;
                cout << "Kelas: ";
                cin >> XM.kelas;
                PM = create_mahasiswa(XM);
                add_mahasiswa(LM, PM);
            }
            print_mahasiswa(LM);
        }
        else if (pilihan == 'b')
        {
            cout << "Jumlah dosen yang ingin dimasukkan: ";
            cin >> jumlah;
            for (int i = 1; i <= jumlah; i++)
            {
                cout << "Masukkan data dosen ke-" << i << endl;
                cout << "NIP: ";
                cin >> XD.nip;
                cout << "Nama: ";
                cin >> XD.nama;
                PD = create_dosbing(XD);
                add_dosbing(LD, PD);
            }
            print_dosbing(LD);
        }
        else if (pilihan == 'c')
        {
            cout << "Masukkan mahasiswa yang ingin dicari" << endl;
            cout << "NIM: ";
            cin >> nim;
            PM = find_mahasiswa(LM, nim);
            cout << "NIM: " << info(PM).nim << " ";
            cout << "Nama: " << info(PM).nama << " ";
            cout << "Kelas: " << info(PM).kelas << endl;
            cout << endl;
        }
        else if (pilihan == 'd')
        {
            cout << "Masukkan mahasiswa dan dosen yang ingin dibuat relasi" << endl;
            cout << "NIM: ";
            cin >> nim;
            cout << "NIP: ";
            cin >> nip;
            add_relasi(LM, LD, LR, nim, nip);
            print_mahasiswa_dosbing(LM, LD, LR);
        }
        else if (pilihan == 'e')
        {
            cout << "Masukkan dosen yang ingin ditampilkan mahasiswa bimbingan-nya" << endl;
            cout << "NIP: ";
            cin >> nip;
            LM2 = find_mahasiswa_by_dosbing(LR, nip);
            print_mahasiswa(LM2);
        }
        else if (pilihan == 'f')
        {
            cout << "Masukkan dosen yang ingin dihapus" << endl;
            cout << "NIP: ";
            cin >> nip;
            delete_dosbing(LD, LR, nip);
            print_mahasiswa_dosbing(LM, LD, LR);
        }
        else if (pilihan == 'g')
        {
            cout << "Masukkan mahasiswa yang dosen pembimbing-nya ingin dihapus" << endl;
            cout << "NIM: ";
            cin >> nim;
            delete_dosbing_by_mahasiswa(LM, LD, LR, nim);
            print_mahasiswa_dosbing(LM, LD, LR);
        }
        else if (pilihan == 'h')
        {
            print_mahasiswa_dosbing(LM, LD, LR);
        }
        else if (pilihan == 'i')
        {
            print_dosbing_max(LD, LR);
        }
        else if (pilihan == 'j')
        {
            print_mahasiswa_tunggal(LR);
        }
        else if (pilihan == 'k')
        {
            print_mahasiswa(LM);
            print_dosbing(LD);
        }
        else
        {
            cout << "Pilihan tidak ada" << endl;
        }
        cout << "Kembali ke menu? (y/n): ";
        cin >> lanjut;
        if (lanjut != 'n')
        {
            pilihan = menu();
        }
    }
    cout << "Program Selesai" << endl;
    cout << "Terimakasih" << endl;
    return 0;
}
