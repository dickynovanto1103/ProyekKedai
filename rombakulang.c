#include <stdio.h>

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


int main()
{
    int input,cntStand=0,cntThai=0,cntNasrem=0,cntJian=0,orderchoice;
    int harganasrem[100],hargateh[100],hargajian[100];
    int i,k;
    char orderapa[10][100],teh[100][100],nasrem[100][100],jian[100][100];


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
        cntThai++;
    }
    fclose(fileThai);

    //nasi goreng rempah
    FILE *fileNasrem;
    fileNasrem = fopen ("nasremdata.txt","r");
    while(!feof(fileNasrem))
    {
        fscanf(fileNasrem,"%[^#]#%d\n",&nasrem[cntNasrem],&harganasrem[cntNasrem]);
        cntNasrem++;
    }
    fclose(fileNasrem);

    //jianbing
    FILE *fileJian;
    fileJian = fopen ("jianbing.txt","r");
    while(!feof(fileJian))
    {
        fscanf(fileJian,"%[^#]#%d\n",&jian[cntJian],&hargajian[cntJian]);
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
                printf("How many?\n");
                printf("Do you want to order again in this stand?\n");

            }else if (orderchoice==2) //nasi goreng mafia
            {
                tulisannasgor();
                for(k=0;k<cntNasrem;k++)
                {
                    printf ("%s \t: %d",nasrem[k],harganasrem[k]);
                    printf("\n");
                }

                printf ("Please write your order(number): ");
                printf ("Do you want to add topping?\n");
                printf("How many?\n");
                printf("Do you want to order again in this stand?\n");

            }else if (orderchoice==3) //jianbing heroes
            {
                tulisanjian();
                for(k=0;k<cntJian;k++)
                {
                    printf ("%s \t: %d",jian[k],hargajian[k]);
                    printf("\n");
                }

                printf ("Please write your order(number): ");
                printf("How many?\n");
                printf("Do you want to order again in this stand?\n");
            }
            break;

            case 2 :
                printf ("Your order :\n");
                printf ("Do you want to pay?"); //y or n

        }
    }while (input!=3);

    printf ("Thankyou for coming.");
    system("cls");
    return 0;
}