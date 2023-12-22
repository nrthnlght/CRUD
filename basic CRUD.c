#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
main()
{

        int pilih1, pilih2, pilih3;
        FILE *pf;
        int data, i,harga ;
        char nama[40];
        char kar, again='y';

        do{

                printf("\n===========================================\n\t\tPT.NAFRI MAJU MUNDUR\n-------------------------------------------\n");
                printf("\n1. Menginput dengan Menghapus data sebelumnya\n");
                printf("\n2. Menambahkan Data tanpa Menghapus\n");
                printf("\n3. Melihat Data Keseluruhan\n");
                printf("\n-------------------------------------------\n");
                printf("pilihan Anda ?");
                scanf("%d",&pilih1);
                printf("\n===========================================\n");
                if(pilih1>3){
     system("cls");
                        printf("INPUT SALAH, COBA LAGI!!\n");}
                switch(pilih1)

        {
        case 1:
                {
                    system("cls");
                        if((pf=fopen("latihan.txt","w"))== NULL)
                        {
                                printf("file gagal diciptakan!\n");
                                exit(1);
                        }
                        printf("Masukkan banyaknya barang :");
                        scanf("%d",&data);
                        for(i=1;i<=data;i++)
                        {
                                printf("\nBarang ke %d : ",i);fflush(stdin);
                                gets(nama);
                                strcat(nama,"\n");
                                fputs(nama, pf);
                        }
                        printf("============================\n");
                        printf("Oke. Data sudah disimpan !!\n");
                        printf("============================\n");
                        fclose(pf);
                }
                printf("Kembali ke menu [y/t] ? ");
        again=getch();
        break;
        case 2:
                {system("cls");
                        if((pf=fopen("latihan.txt","a"))== NULL)
                        {
                                printf("file gagal diciptakan!\n");
                                exit(1);
                        }
                        printf("Masukkan banyaknya Barang :");
                        scanf("%d",&data);
                        for(i=1;i<=data;i++)
                        {
                                printf("\nBarang ke %d : ",i);fflush(stdin);
                                gets(nama);
                                strcat(nama,"\n");
                                fputs(nama, pf);
                        }
                        printf("============================\n");
                        printf("Oke. Data sudah disimpan !!\n");
                        printf("============================\n");
                        fclose(pf);
                }
                printf("Kembali ke menu [y/t] ? ");
        again=getch();
        break;

        case 3:
                {system("cls");
                        if ((pf=fopen("latihan.txt","r"))== NULL)
                        {
                                printf("file tak dapat dibuka !\r\n");
                                exit(1);
                        }
                        while((kar=fgetc(pf)) !=EOF)
                        putchar(kar);
                        printf("\n");
                        fclose(pf);
                }
        printf("Kembali ke menu [y/t] ? ");
        again=getch();
    break;
        }
  }while(again=='y');
}
