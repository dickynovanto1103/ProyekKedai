#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Pembelian{
    char namaBarang[100];
    int hargaSatuan;
    int banyakOrder;
};


void tulisanthai()
    {
        printf (" _____   _   _   _____   _         ___   _   _   _____\n"
                "|_   _| | |_| | |     | | |  ___  |  _| | |_| | |     |\n"
                "  | |   |  _  | |  _  | | | |___| | |_  |  _  | |  _  |\n"
                "  |_|   |_| |_| |_| |_| |_|       |___| |_| |_| |_| |_|\n");
                printf ("\n");
    }

void tulisannasgor()
    {
        printf (" _   _   _____   ____   ____   _____   ____      ____   ___   _    _   ____   _____   _   _\n"
                "| \\ | | |     | |  __| |  __  |  _  | |    |    |    | |  _| | \\  / | |    | |     | | |_| |\n"
                "|  \\| | |  _  |  _\\ \\  |    | | |_| | |   <     |   <  |  _| ||\\\\//|| |  __| |  _  | |  _  |\n"
                "|_|\\__| |_| |_| |____| |____| |_____| |_|\\_\\    |_|\\_\\ |___| ||    || |_|    |_| |_| |_| |_|\n");
                printf ("\n");
    }

void tulisanjian()
    {
        printf ("     _   _   _____   _   _         ___   _   _   _   ____\n"
                " _  | | | | |     | | \\ | |  ___  |   | | | | \\ | | |  __ \n"
                "| |_| | | | |  _  | |  \\| | |___| |  <  | | |  \\| | |    |\n"
                "|_____| |_| |_| |_| |_|\\ _|       |___| |_| |_|\\ _| |____|\n");
                printf ("\n");
    }

int isStringMatched(char input[], char kata[]){
    int panjangInput = strlen(input);
    int panjangKata = strlen(kata);

    int i,j;
    for(i=0;i<=panjangKata-panjangInput;i++){
        j=0;
        while(j<panjangInput && kata[i+j]==input[j]){
            j++;
        }
        if(j==panjangInput){return 1;}
    }
    return 0;
}


int main()
{
    int input,input_order,cntStand=0,cntThai=0,cntNasrem=0,cntJian=0,orderchoice;
    int harganasrem[100],hargateh[100],hargajian[100];
    int i,k;
    char orderapa[10][100],teh[100][100],nasrem[100][100],jian[100][100];

    int listHargaSemuaBarang[100];
    char listNamaSemuaBarang[100][100];

    struct Pembelian history[100];
    int idxHistory = 0;


    int indeksBarangTotal = 0;

    //stand
    FILE *fileStand;
    fileStand = fopen("orderapa.txt","r");
    while(!feof(fileStand))
    {
        fgets(orderapa[cntStand], sizeof orderapa[cntStand], fileStand);
        cntStand++;
    }
    cntStand--;
    fclose(fileStand);

    //thai tea
    FILE *fileThai;
    fileThai = fopen("thaicha.txt","r");
    while(!feof(fileThai))
    {
        fscanf(fileThai,"%[^#]#%d\n",&teh[cntThai],&hargateh[cntThai]);
        //menambahkan ke array semua barang
        strcpy(listNamaSemuaBarang[indeksBarangTotal], teh[cntThai]);
        listHargaSemuaBarang[indeksBarangTotal] = hargateh[cntThai];
        indeksBarangTotal++;
        cntThai++;
    }
    fclose(fileThai);

    //nasi goreng rempah
    FILE *fileNasrem;
    fileNasrem = fopen ("nasremdata.txt","r");
    while(!feof(fileNasrem))
    {
        fscanf(fileNasrem,"%[^#]#%d\n",&nasrem[cntNasrem],&harganasrem[cntNasrem]);
        //menambahkan ke array semua barang
        strcpy(listNamaSemuaBarang[indeksBarangTotal], nasrem[cntNasrem]);
        listHargaSemuaBarang[indeksBarangTotal] = harganasrem[cntNasrem];
        indeksBarangTotal++;
        cntNasrem++;
    }
    fclose(fileNasrem);

    //jianbing
    FILE *fileJian;
    fileJian = fopen ("jianbing.txt","r");
    while(!feof(fileJian))
    {

        fscanf(fileJian,"%[^#]#%d\n",&jian[cntJian],&hargajian[cntJian]);
        //menambahkan ke array semua barang
        strcpy(listNamaSemuaBarang[indeksBarangTotal], jian[cntJian]);
        listHargaSemuaBarang[indeksBarangTotal] = hargajian[cntJian];
        indeksBarangTotal++;
        cntJian++;
    }
    fclose(fileJian);



    do{
    do
    {
        printf ("Hello, what do you want to do?\n"
                "1. Order\n"
                "2. View order\n"
                "3. Exit\n");

        printf("Your choice : ");
        scanf("%d",&input);
        printf ("\n");

    }while (input<1||input>3);

        switch(input)
        {
        case 1 :
            printf ("1. Choose stand\n"
                    "2. Search a menu\n"
                    "3. Sort\n"
                    "4. Go back\n");
            printf ("Your choice : ");
            scanf ("%d",&input_order);

            switch (input_order)
            {
            case 1 :
                printf ("What do you want to order?\n");
                for (i=0;i<cntStand;i++)
                {
                    printf("%d. %s",i+1,orderapa[i]);
                }
                printf ("Your choice : ");
                scanf ("%d",&orderchoice);
                printf("\n");

                if (orderchoice==1) //thaicha
                {
                    tulisanthai();
                    for(k=0;k<cntThai;k++)
                    {
                        printf ("%s \t: %d",teh[k],hargateh[k]);
                        printf("\n");
                    }

                    printf ("Please write your order(number): ");
                    int orderThai,orderThaiJumlah;
                    scanf ("%d",&orderThai);
                    printf("How many?\n");
                    scanf ("%d",&orderThaiJumlah);
                    printf("order jumlah: %d\n",orderThaiJumlah);

                    printf("makanan: %s\n",teh[orderThai]);
                    strcpy(history[idxHistory].namaBarang,teh[orderThai]);
                    printf("namaBarang: %s\n",history[idxHistory].namaBarang);
                    //printf("halo2");
                    history[idxHistory].hargaSatuan = hargateh[orderThai];
                    //printf("halo3");
                    history[idxHistory].banyakOrder = orderThaiJumlah;
                    //printf("halo");
                    idxHistory++;


                    printf("Do you want to order again in this stand?\n");

                }else if (orderchoice==2) //nasi goreng mafia
                {
                    tulisannasgor();
                    for(k=0;k<cntNasrem;k++)
                    {
                        printf ("%s \t: %d",nasrem[k],harganasrem[k]);
                        printf("\n");
                    }
                    int orderNasrem,orderNasremJumlah;
                    printf ("Please write your order(number): ");
                    scanf ("%d",&orderNasrem);
                    printf("How many?\n");
                    scanf ("%d",&orderNasremJumlah);

                    strcpy(history[idxHistory].namaBarang,nasrem[orderNasrem]);
                    history[idxHistory].hargaSatuan = harganasrem[orderNasrem];
                    history[idxHistory].banyakOrder = orderNasremJumlah;
                    idxHistory++;

                    printf("Do you want to order again in this stand?\n");

                }else if (orderchoice==3) //jianbing heroes
                {
                    tulisanjian();
                    for(k=0;k<cntJian;k++)
                    {
                        printf ("%s \t: %d",jian[k],hargajian[k]);
                        printf("\n");
                    }

                    int orderJian,orderJianJumlah;

                    printf ("Please write your order(number): ");
                    scanf ("%d",&orderJian);
                    printf("How many?\n");
                    scanf ("%d",&orderJianJumlah);


                    strcpy(history[idxHistory].namaBarang,jian[orderJian]);
                    history[idxHistory].hargaSatuan = hargajian[orderJian];
                    history[idxHistory].banyakOrder = orderJianJumlah;
                    idxHistory++;

                    printf("Do you want to order again in this stand?\n");

                }
                int j;
                printf("list History\n");
                for(j=0;j<idxHistory;j++){
                    printf("%s %d %d\n",history[j].namaBarang,history[j].hargaSatuan,history[j].banyakOrder);
                }
                break;

            case 2 :
            {
                char inputMakanan[100];
                scanf("\n%[^\n]s",inputMakanan);
                printf("input makanan: %s\n",inputMakanan);

                char listBarangDitemukan[100][100];
                int listHargaDitemukan[100];
                int cntDitemukan = 0;

                //cari makanan dari sini yang sesuai disini
                for(i=0;i<indeksBarangTotal;i++){
                    char barang[100];
                    int harga;

                    strcpy(barang,listNamaSemuaBarang[i]);
                    harga = listHargaSemuaBarang[i];

                    //cek apakah string inputMakanan ada di ada di string barang
                    if(isStringMatched(inputMakanan,barang)){
                        strcpy(listBarangDitemukan[cntDitemukan], barang);
                        listHargaDitemukan[cntDitemukan] = harga;
                        cntDitemukan++;
                    }

                }

                if(cntDitemukan==0){printf("Tidak ditemukan menu yang diinginkan\n");}
                else{
                    for(i=0;i<cntDitemukan;i++){
                        printf("%d: %s %d\n",i+1, listBarangDitemukan[i], listHargaDitemukan[i]);
                    }
                    printf("\nWhat do you want to order?\n");
                    int pilihan;
                    scanf("%d",&pilihan);
                    printf("\nHow many?\n");
                    int banyakPesanan;
                    scanf("%d",&banyakPesanan);
                    printf("\n\nBerhasil membeli makanan!!\n");
                    strcpy(history[idxHistory].namaBarang,listBarangDitemukan[pilihan]);
                    history[idxHistory].hargaSatuan = listHargaDitemukan[pilihan];
                    history[idxHistory].banyakOrder = banyakPesanan;
                    idxHistory++;

                    printf("list History\n");
                    for(j=0;j<idxHistory;j++){
                        printf("%s %d %d\n",history[j].namaBarang,history[j].hargaSatuan,history[j].banyakOrder);
                    }
                }


            }
                break;
            case 3 :
                break;
            case 4 :
                printf ("\n");
                break;
            }
            break;

        case 2 :
            printf ("1. Want to pay?:\n");
            printf ("2. Back to main menu?"); //y or n
            int pilihan;
            scanf("%d",&pilihan);
            if(pilihan==1){
                printf("What do you want to pay?\n");
                //menampilkan list hutang
            }else{
                printf("\n");
                break;
            }
            break;
        }
    }while (input!=3);

    printf ("Thankyou for coming.\n");
    return 0;
}
