# Asistensi P4

Program ini memiliki struct Barang beranggota char nama[50], int harga, int stock dan struct Member beranggota char nama[50], int poin serta fungsi-fungsi yang berinteraksi dengan struct tersebut. 

#Tugas
1. Untuk tugas satu, harga dapat diupdate menggunakan fungsi ini:
```c
void updateHarga(Barang *b, int hargaBaru)
{
    b->harga = hargaBaru;
}
```

2. Untuk tugas dua, nama barang dapat diupdate menggunakan fungsi ini:
```c
void updateNama(Barang *b, char namaBaru[])
{
    strcpy(b->nama, namaBaru);
}
```

3. Untuk tugas tiga, kita bisa tambah blok kode ini setelah total awalnya ditentukan
```c
if(m != NULL && m->poin >= 1000) 
        {
            total *= 0.9; //diskon sepuluh persen
            m->poin -= 1000;
        }
```

4. Untuk tantangan tambahan, digunakan infinite loop yang membungkus alur logika. data member dan stock barang dideklarasikan sebelum program infinite loop berjalan. program menerima input pilihan menu pengguna. terdapat 6 menu, lihat barang, beli barang, cek member, keluar, update harga, dan update nama. beli barang, update harga, dan update nama menerima input pengguna dan memeriksa jika valid. berikut blok kodenya:
```c
int main() 
{
    // 1. Setup Database
    Barang dbBarang[5] = { {"Sabun", 5000, 10}, {"Sampo", 15000, 5}, {"Roti", 12000, 8}, {"Susu", 25000, 15}, {"Kopi", 22000, 20} };
    Member dbMember[2] = { {"Anisa", 500}, {"Budi", 100} };

    while(1)
    {
        int indexBarang, indexMember, qty, hargaBaru, pilihan;
        char namaBaru[50];
        printf("\n[1] Lihat Barang | [2] Beli Barang | [3] Cek Member | [4] Keluar | [5] Update Harga Barang | [6] Update Nama Barang");
        printf("\nSilahkan masukan pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1:
                cekBarang(dbBarang, 5);
                break;

            case 2:
                cekBarang(dbBarang, 5);
                printf("Pilih nomor barang: ");
                scanf("%d", &indexBarang);

                cekMember(dbMember, 2);
                printf("Pilih nomor member (0 jika bukan member): ");
                scanf("%d", &indexMember);

                printf("Masukkan jumlah pembelian: ");
                scanf("%d", &qty);

                if (indexBarang < 1 || indexBarang > 5 || qty <= 0)
                {
                    printf("Pilihan barang atau jumlah tidak valid.\n");
                    break;
                }

                if (indexMember == 0)
                    beliBarang(&dbBarang[indexBarang - 1], NULL, qty);
                else if (indexMember >= 1 && indexMember <= 2)
                    beliBarang(&dbBarang[indexBarang - 1],
                            &dbMember[indexMember - 1], qty);
                else
                    printf("Nomor member tidak valid.\n");

                break;

            case 3:
                cekMember(dbMember, 2);
                break;

            case 4:
                printf("Jaa ne\n");
                return 0;

            case 5:
                cekBarang(dbBarang, 5);
                printf("Pilih nomor barang yang ingin diubah harganya: ");
                scanf("%d", &indexBarang);

                if (indexBarang < 1 || indexBarang > 5)
                {
                    printf("Nomor barang tidak valid.\n");
                    break;
                }

                printf("Masukkan harga baru: ");
                scanf("%d", &hargaBaru);

                if (hargaBaru < 0)
                {
                    printf("Harga tidak boleh negatif.\n");
                    break;
                }

                updateHarga(&dbBarang[indexBarang - 1], hargaBaru);
                printf("Harga barang berhasil diperbarui.\n");
                printf("Harga baru: Rp%d\n", dbBarang[indexBarang - 1].harga);
                break;

            case 6:
                cekBarang(dbBarang, 5);
                printf("Pilih nomor barang yang ingin diubah namanya: ");
                scanf("%d", &indexBarang);

                if (indexBarang < 1 || indexBarang > 5)
                {
                    printf("Nomor barang tidak valid.\n");
                    break;
                }

                printf("Masukkan nama baru: ");
                scanf(" %49[^\n]", namaBaru);

                updateNama(&dbBarang[indexBarang - 1], namaBaru);
                printf("Nama barang berhasil diperbarui.\n");
                printf("Nama baru: %s\n", dbBarang[indexBarang - 1].nama);
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    return 0;
}
```

Berikut contoh output
<img width="1172" height="820" alt="image" src="https://github.com/user-attachments/assets/7a7f1579-c68d-4ceb-8004-59c4fbdb9b09" />
<img width="1127" height="817" alt="image" src="https://github.com/user-attachments/assets/00e3cb1a-e832-489b-873b-34f1e4d463b3" />

