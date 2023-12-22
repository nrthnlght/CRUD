#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

//var. semesta
FILE *file;
int j;
j = 0;
struct orders order;
float subtotal, total, ppn, total_bayar, kembalian;
int bayar;

void gotoxy(int x, int y)
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


struct items
{
    char ni[50];
    int pilih;
    int harga;
    int qty;
    float total;
};

struct orders
{
    char nama[50];
    char tanggal[50];
    int numOfItem;
    float subtotal, ppn, bayar, total_bayar, kembalian;
    struct items itm[50]; //ambil dari struct items dengan var. itm
};
struct orders ord[50];

void tanggal()
{
    int jam, menit, detik, hari, bulan, tahun;

    // tipe aritmatika dari waktu
    time_t sekarang;

    time(&sekarang);
    printf("%s", ctime(&sekarang));

    struct tm *local = localtime(&sekarang);

    jam = local->tm_hour;
    menit = local->tm_min;
    detik = local->tm_sec;

    hari = local->tm_mday;
    bulan = local->tm_mon + 1;
    tahun = local->tm_year + 1900;
}

void billHeader(char nama[50], char tanggal[30])
{
    printf("\n");
    printf ("=================== FUKUSHI ==================\n");
    printf ("================= RESTAURANT =================\n");
    printf ("----------------------------------------------\n");
    printf ("\nInvoice to : %s", strupr (nama));
    printf ("\n");
}

void billBody(char *ni[50], int qty, float harga)
{
    printf("%s\t", ni);
    printf("%d\t", qty);
    printf("%d\t\t\n", qty * harga);
}

void billFooter(float total, float ppn, float subtotal, float bayar, float kembalian)
{
    printf ("\n----------------------------------------------\n");
    printf ("\ntotal\t\t\t\tRp %.2f,-", total);
    printf ("\nppn\t\t\t\tRp %.2f,-", ppn);
    printf ("\nsubtotal\t\t\tRp %.2f,-", subtotal);
    printf ("\nbayar\t\t\t\tRp %.2f,-", bayar);
    printf ("\nkembali\t\t\t\tRp %.2f,-", kembalian);

    printf ("\n\naddress : jln. Buntu\n");
    printf ("Telp.: minta langsung");
}

void password()
{
    char username[100];
    char password[100];

    PASS:
        gotoxy (40, 13);
        printf ("masukkan username :");
        scanf ("%s", username);
        gotoxy (40, 14);
        printf ("masukkan password :");
        fflush (stdin);

        char ch;
        int i = 0;
        while ((ch = (char)_getch()) != '\r')
        {
            password[i] = ch;
            printf("*");
            i++;
        }
        printf ("\n");

        if ((strcmp(username, "FAZA") == 0) && (strcmp(password, "salsa") == 0))
        {
            gotoxy (38, 16);
            printf ("selamat anda berhasil masuk\n");
        }
        else
        {
            gotoxy (30, 16);
            printf ("Password dan username salah... silahkan ulang lagi\n");
            system ("pause");
            system ("cls");
            goto PASS;
        }
}

void inputMakanan()
{
    int i = 1, jml;
    float ttl, total;
    char saveBill = 'y';

    ord[j].subtotal = 0;

    system("cls");
    printf("Masukkan nama customer : ");
    scanf("%s",&ord[j].nama);
    printf("masukkan jumlah yang akan dipesan : ");
    scanf("%d", &jml);

    printf("========================================================================================\n");
    printf("|                            MENU FUKUSHI RESTAURANT                                   |\n");
    printf("========================================================================================\n");
    printf("|\t MAKANAN            |    harga   |\t MINUMAN                  |    harga   |\n");
    printf("========================================================================================\n");
    printf("|\t 1. Sashimi         | Rp 58500,- |\t 8. Matcha                | Rp 17000,- |\n");
    printf("|\t 2. Aburi           | Rp 79000,- |\t 9. Sakura Tea            | Rp 15500,- |\n");
    printf("|\t 3. Ramen           | Rp 75000,- |\t 10. Kombucha             | Rp 24000,- |\n");
    printf("|\t 4. Udon            | Rp 60500,- |\t 11. Ofukucha             | Rp 19000,- |\n");
    printf("|\t 5. Gyoza           | Rp 41000,- |\t 12. Melon Soda           | Rp 14500,- |\n");
    printf("|\t 6. Yakiniku        | Rp 53000,- |\t 13. Milk Tea             | Rp 14500,- |\n");
    printf("|\t 7. Okonomiyaki     | Rp 67500,- |\t 14. Air Putih            | Rp 6000,-  |\n");
    printf("========================================================================================\n");

    ord[j].numOfItem = jml;
    for (i = 0; i < jml; i++)
    {

    pilih:
        printf("\n\nMasukkan menu ke %d yang ingin anda pesan : ", i + 1);
        scanf("%d", &ord[j].itm[i].pilih);
        fflush(stdin);

        if (ord[j].itm[i].pilih == 1)
        {
            ord[j].itm[i].harga = 58500;
            //copy string ".." ke char ni, maka char ni akan berisi printf dari ".."
            strcpy(ord[j].itm[i].ni, "Sashimi");
            printf("Sashimi");
        }
        else if (ord[j].itm[i].pilih == 2)
        {
            ord[j].itm[i].harga = 79000;
            strcpy(ord[j].itm[i].ni, "Aburi");
            printf("Aburi");
        }
        else if (ord[j].itm[i].pilih == 3)
        {
            ord[j].itm[i].harga = 75000;
            strcpy(ord[j].itm[i].ni, "Ramen");
            printf("Ramen");
        }
        else if (ord[j].itm[i].pilih == 4)
        {
            ord[j].itm[i].harga = 60500;
            strcpy(ord[j].itm[i].ni, "Udon");
            printf("Udon");
        }
        else if (ord[j].itm[i].pilih == 5)
        {
            ord[j].itm[i].harga = 41000;
            strcpy(ord[j].itm[i].ni, "Gyoza");
            printf("Gyoza");
        }
        else if (ord[j].itm[i].pilih == 6)
        {
            ord[j].itm[i].harga = 53000;
            strcpy(ord[j].itm[i].ni, "Yakiniku");
            printf("Yakiniku");
        }
        else if (ord[j].itm[i].pilih == 7)
        {
            ord[j].itm[i].harga = 67500;
            strcpy(ord[j].itm[i].ni, "Okonomiyaki");
            printf("Okonomiyaki");
        }
        else if (ord[j].itm[i].pilih == 8)
        {
            ord[j].itm[i].harga = 17000;
            strcpy(ord[j].itm[i].ni, "Matcha");
            printf("Matcha");
        }
        else if (ord[j].itm[i].pilih == 9)
        {
            ord[j].itm[i].harga = 15500;
            strcpy(ord[j].itm[i].ni, "Sakura Tea");
            printf("Sakura Tea");
        }
        else if (ord[j].itm[i].pilih == 10)
        {
            ord[j].itm[i].harga = 24000;
            strcpy(ord[j].itm[i].ni, "Kombucha");
            printf("Kombucha");
        }
        else if (ord[j].itm[i].pilih == 11)
        {
            ord[j].itm[i].harga = 19000;
            strcpy(ord[j].itm[i].ni, "Ofukucha");
            printf("Ofukucha");
        }
        else if (ord[j].itm[i].pilih == 12)
        {
            ord[j].itm[i].harga = 14000;
            strcpy(ord[j].itm[i].ni, "Melon Soda");
            printf("Melon Soda");
        }
        else if (ord[j].itm[i].pilih == 13)
        {
            ord[j].itm[i].harga = 14500;
            strcpy(ord[j].itm[i].ni, "Milk Tea");
            printf("Milk Tea");
        }
        else if (ord[j].itm[i].pilih == 14)
        {
            ord[j].itm[i].harga = 6000;
            strcpy(ord[j].itm[i].ni, "Air Putih");
            printf("Air Putih");
        }
        else
        {
            printf("pilihan menu yang anda pilih tidak tersedia");
            goto pilih;
        }
    //quantity
        printf("\nmasukkan jumlah/quantity : ");
        scanf("%d", &ord[j].itm[i].qty);
        fflush(stdin);

    //total harga setelah dikali qty
        ord[j].itm[i].total = ord[j].itm[i].qty * ord[j].itm[i].harga;
        printf("total = %.2f ", ord[j].itm[i].total);

        ord[j].subtotal += ord[j].itm[i].total;
    }

    printf("\nsub total = Rp %.2f,-", ord[j].subtotal);

    //ppn
    ord[j].ppn = 0.1 * ord[j].subtotal;
    printf("\n\nppn = Rp %.2f,-", ord[j].ppn);

    //total bayar
    ord[j].total_bayar = ord[j].subtotal + ord[j].ppn;
    printf("\nSubtotal setelah ppn = Rp %.2f,-", ord[j].total_bayar);

    //pembayaran
    bayar:
    printf("\n\nMasukkan nominal uang yang anda bayarkan : ");
    scanf("%f", &ord[j].bayar);

    //kembalian
    ord[j].kembalian = ord[j].bayar - ord[j].total_bayar;
    printf("Uang bayar = Rp %.2f,-\n", ord[j].bayar);
        if (ord[j].bayar > ord[j].total_bayar)
        {
            printf("Uang kembalian = Rp %.2f,-\n", ord[j].kembalian);
        }
        else if (ord[j].bayar == ord[j].total_bayar)
        {
            printf("Rp,-");
        }
        else
        {
            printf("Uang kurang Rp %.2f,-", ord[j].total_bayar - ord[j].bayar);
            goto bayar;
        }

    //untuk menyimpan data yang akan diambil/ditampilkan
    if (saveBill == 'y' || saveBill == 'Y')
    {
        file = fopen("RestaurantBill.dat", "a+"); //selain file dapat ditulis file juga dapat dibaca
        fwrite(&ord[j], sizeof(struct orders), 1, file); //Operator sizeof memberikan jumlah penyimpanan, dalam byte, yang diperlukan untuk menyimpan objek dari jenis operand

        if (fwrite != 0)
            printf("\nBerhasil disimpan\n");
        else
            printf("\npenyimpanan bermasalah");
        fclose(file);
    }
    j++;
}

void kesanPesan()
{
    system("cls");
    gotoxy(35, 7);
    printf("==========================================\n");
    gotoxy(35, 8);
    printf("                   KESAN              \n");
    gotoxy(35, 9);
    printf("==========================================\n");
    gotoxy(53, 11);
    printf("TER WOW.\n\n");
    gotoxy(35, 13);
    printf("==========================================\n");
    gotoxy(35, 14);
    printf("                   PESAN              \n");
    gotoxy(35, 15);
    printf("==========================================\n");
    gotoxy(35, 16);
    printf("kak tolong kalo ada tts ga usah lagi \n\t\t\t\t kasih pilihan mau live coding apa di rumah.\n\t\t\t\tlangsung di rumah aja T_T.. pokoknya thank uuuu\n\n");
}

int main()
{
    //variabel menu
    int menu, i;
    int read = 0;
    char nama[50];

    //change bg color
    system("COLOR F4");

    //program animasi
    int a, invoiceFound = 0;
    double b;
    char salam[] = "\t\t\t\t\t WELCOME TO JAPANESE RESTAURANT   ";
    int k, l;

    printf("\n\n\n");
    for (a = 0; salam[a] != NULL; a++)
    {
        printf("%c", salam[a]);
        for (b = 0; b <= 9999999; b++)
        {
        }
    }
    fflush(stdin);
    //memanggil function password
    password();

    //program menu
    do
    {
    menu:
        system("cls");
        printf("|=======================================================|\n");
        printf("|                       WELCOME TO                      |\n");
        printf("|                  JAPANESE RESTAURANT                  |\n");
        printf("|=======================================================|\n");
        printf("|       1. Input Customer                               |\n");
        printf("|       2. Tampilan                                     |\n");
        printf("|       3. Cetak Bill                                   |\n");
        printf("|       4. Kesan Pesan                                  |\n");
        printf("|       5. Exit                                         |\n");
        printf("|=======================================================|\n\n");

        printf("Find your menu : ");
        scanf("%d", &menu);

        fgetc(stdin); //agar scanf jalan

        switch (menu)
        {
        case 1:
            inputMakanan();
            break;
        case 2:
            system("cls");
            file = fopen("RestaurantBill.dat", "r"); //"r" Membuka file sesuai namafilenya untuk dibaca, jika file tidak ada maka akan bernilai NULL.

            for (k = 0; k < j; k++)
            {
                float total = 0;
                printf("Data order : %s\n\n", strupr(ord[k].nama));

                for (l = 0; l < ord[k].numOfItem; l++)
                {
                    printf("order \t\t: %s\n", ord[k].itm[l].ni);
                    printf("jumlah order \t: %d\n", ord[k].itm[l].qty);
                    printf("harga \t\t: Rp %d,-\n", ord[k].itm[l].qty * ord[k].itm[l].harga);
                }

                    printf("\ntotal \t\t: Rp%.2f,-\n", ord[k].subtotal);
                    printf("ppn \t\t: Rp%.2f,-\n", ord[k].ppn);
                    printf("sub total \t: Rp%.2f,-\n", ord[k].total_bayar);
                    printf("bayar \t\t: Rp%.2f,-\n", ord[k].bayar);
                    printf("kembalian \t: Rp%.2f,-\n", ord[k].kembalian);
                    printf("\n\n");
            }
            fclose(file);

            break;
        case 3:  //cetak bill
            system("cls");
            printf("\nMasukkan nama pelanggan : ");
            scanf("%s", &nama);

            printf ("\n");

        //loading program
            printf("\tGenerating your BILL....");
            for(i=1;i<=6;i++)
            {
               printf("\b\b\b\b");
               if(i==1||i==3||i==5)
               printf("    ");
               if(i==2||i==4||i==6)
               {
                printf(".");
                Sleep(300);
                printf(".");
                Sleep(300);
                printf(".");
                Sleep(300);
                printf(".");
               }
               Sleep(300);
            }
        // open file
            printf ("\n\n");
            file = fopen("RestaurantBill.dat", "r");
            printf("\n************* Invoices of %s *************\n", strupr(nama));

            for (k = 0; k < j; k++)
            {
                if (strcmp(ord[k].nama, nama) ==  0)
                {
                    float total = 0;
                    billHeader(ord[k].nama, ord[k].tanggal);
                    tanggal();
                        printf("----------------------------------------------\n");
                        printf("Items\t\t");
                        printf("Qty\t\t");
                        printf("Total\t\t");
                        printf("\n----------------------------------------------\n\n");

                    for (l = 0; l < ord[k].numOfItem; l++)
                    {
                        printf("%s\t\t", ord[k].itm[l].ni);
                        printf("%d\t\t", ord[k].itm[l].qty);
                        printf("%d\t\t\n", ord[k].itm[l].qty * ord[k].itm[l].harga);
                    }
                    billFooter(ord[k].subtotal, ord[k].ppn, ord[k].total_bayar, ord[k].bayar, ord[k].kembalian);
                    printf("\n\n");
                    invoiceFound = 1;
                }
            }
            if (!invoiceFound)
            {
                printf("Sorry the invoice for %s doesn't exits", nama);
            }
            fclose(file);

            break;
        case 4:
            kesanPesan();
            break;
        case 5:
            system("cls");
            gotoxy(42, 3);
            printf("\t\tTerima Kasih!\n");
            gotoxy(42, 4);
            printf("Nama  : AYU FAZA ISLAMI_672022033\n");
            gotoxy(42, 5);
            printf("Nama  : SALSABILA YUNITA SARI_672022217\n");
            exit(0);
            break;
        default:
            printf("Menu tidak ada silahkan coba lagi!\n");
        }
    } while (menu = !5);
    system("pause");
    system("cls");
    goto menu;
}
