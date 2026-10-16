#include <stdio.h>
#include <string.h>

typedef struct { char nama[50]; int harga; int stock; } Barang;
typedef struct { char nama[50]; int poin; } Member;

void cekBarang(Barang db[], int ukuran) 
{
    printf("\n--- Katalog Barang ---\n");
    for(int i=0; i<ukuran; i++) 
    {
        printf("%d. %s - Rp%d (Stok: %d)\n", i+1, db[i].nama, db[i].harga, db[i].stock);
    }
}
void cekMember(Member db[], int ukuran) 
{
    printf("\n--- Data Member ---\n");
    for(int i=0; i<ukuran; i++) 
    {
        printf("%d. %s - Poin: %d\n", i+1, db[i].nama, db[i].poin);
    }
}

void beliBarang(Barang *b, Member *m, int qty) 
{
    if (b->stock >= qty) 
    {
        b->stock -= qty;
        int total = b->harga * qty;

        //tugas praktikum 3
        if(m != NULL && m->poin >= 1000) 
        {
            total *= 0.9; //diskon sepuluh persen
            m->poin -= 1000;
        }

        printf("\n[TRANSAKSI] %d %s Terjual. Total: Rp%d\n", qty, b->nama, total);

        if (total >= 20000 && m != NULL) 
        {
            m->poin += 100;
            printf("  -> Member %s mendapat +100 Poin!\n", m->nama);
        }
    } 
    else 
    {
        printf("\n[GAGAL] Stok %s (Tersisa: %d) tidak cukup untuk dibeli sebanyak %d!\n", b->nama, b->stock, qty);
    }
}

//tugas praktikum 1
void updateHarga(Barang *b, int hargaBaru)
{
    b->harga = hargaBaru;
}

//tugas praktikum 2
void updateNama(Barang *b, char namaBaru[])
{
    strcpy(b->nama, namaBaru);
}

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
