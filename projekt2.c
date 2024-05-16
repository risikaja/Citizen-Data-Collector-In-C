#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PERSONA 100
#define FILE_NAME "projekt2.txt"

struct personi
{
    char emri[100];
    char mbiemri[100];
    char adresa[1000];
    int nr_telefonit;
    char email[100];
};

struct personi p[MAX_PERSONA];
int n = 0;

void menu();
void regjistro();
void modifiko();
void kerkoEmrin();
void kerkoMbiemri();
void kerkonr();
void fshi();
void afishoTeDhenat();
void rradhitSipasEmrit();
void rradhitSipasMbiemrit();
void lexoTeDhenat();
void shkruajTeDhenat();

int main()
{
    FILE *fp;
    fp = fopen(FILE_NAME, "r");
    if (fp != NULL)
    {
        lexoTeDhenat(fp);
        fclose(fp);
    }

    int zgjedhja;

    while (1)
    {
        menu();
        printf("\nZgjidhni nje opsion: ");
        scanf("%d", &zgjedhja);

        switch (zgjedhja)
        {
            case 0:
                regjistro();
                break;
            case 1:
                modifiko();
                break;
            case 2:
                fshi();
                break;
            case 3:
                kerkoEmrin();
                break;
            case 4:
                kerkoMbiemri();
                break;
            case 5:
                kerkonr();
                break;
            case 6:
                afishoTeDhenat();
                break;
            case 7:
                rradhitSipasEmrit();
                break;
            case 8:
                rradhitSipasMbiemrit();
                break;
            case 9:
                printf("\nDilni nga programi.\n");
                // Write the data back to the file before exiting
                fp = fopen(FILE_NAME, "w");
                if (fp != NULL)
                {
                    shkruajTeDhenat(fp);
                    fclose(fp);
                }
                return 0;
            default:
                printf("\nOpcioni i zgjedhur nuk ekziston.\n");
                break;
        }
    }

    return 0;
}

void menu()
{
    printf("0. Regjistro nje qytetar te ri.\n");
    printf("1. Modifiko te dhenat e nje qytetari.\n");
    printf("2. Fshi te dhenat e nje qytetari.\n");
    printf("3. Kerko sipas emrit.\n");
    printf("4. Kerko sipas mbiemrit.\n");
    printf("5. Kerko sipas numrit te telefonit.\n");
    printf("6. Afisho te dhenat e ruajtura me pare.\n");
    printf("7. Rradhit sipas emrit.\n");
    printf("8. Rradhit sipas mbiemrit.\n");
    printf("9. Dil nga programi.\n");
}

void regjistro()
{
    if (n < MAX_PERSONA)
    {
        struct personi qytetari;

        printf("\nEmri: ");
        scanf("%s", qytetari.emri);

        printf("Mbiemri: ");
        scanf("%s", qytetari.mbiemri);

        printf("Adresa: ");
        getchar(); // Clear the input buffer
        fgets(qytetari.adresa, sizeof(qytetari.adresa), stdin);

        printf("Numri i telefonit: ");
        scanf("%d", &qytetari.nr_telefonit);

        printf("Email: ");
        scanf("%s", qytetari.email);

        p[n] = qytetari;
        n++;

        printf("\nTe dhenat u regjistruan me sukses.\n");
    }
    else
    {
        printf("\nNumri maksimal i qytetareve te regjistruar eshte arritur.\n");
    }
}

void modifiko()
{
    char emri[100], mbiemri[100];
    int i, gjetur = 0;

    printf("\nEmri: ");
    scanf("%s", emri);

    printf("Mbiemri: ");
    scanf("%s", mbiemri);

    for (i = 0; i < n; i++)
    {
        if (strcmp(p[i].emri, emri) == 0 && strcmp(p[i].mbiemri, mbiemri) == 0)
        {
            struct personi qytetari;

            printf("\nEmri i ri: ");
            scanf("%s", qytetari.emri);

            printf("Mbiemri i ri: ");
            scanf("%s", qytetari.mbiemri);

            printf("Adresa e re: ");
            getchar(); // Clear the input buffer
            fgets(qytetari.adresa, sizeof(qytetari.adresa), stdin);

            printf("Numri i ri i telefonit: ");
            scanf("%d", &qytetari.nr_telefonit);

            printf("Email-i ri: ");
            scanf("%s", qytetari.email);

            p[i] = qytetari;
            gjetur = 1;
            break;
        }
    }

    if (gjetur == 1)
    {
        printf("\nTe dhenat u modifikuan me sukses.\n");
    }
    else
    {
        printf("\nQytetari nuk u gjet.\n");
    }
}

void fshi()
{
    char emri[100], mbiemri[100];
    int i, gjetur = 0;

    printf("\nEmri: ");
    scanf("%s", emri);

    printf("Mbiemri: ");
    scanf("%s", mbiemri);

    for (i = 0; i < n; i++)
    {
        if (strcmp(p[i].emri, emri) == 0 && strcmp(p[i].mbiemri, mbiemri) == 0)
        {
            int j;
            for (j = i; j < n - 1; j++)
            {
                p[j] = p[j + 1];
            }
            n--;
            gjetur = 1;
            break;
        }
    }

    if (gjetur == 1)
    {
        printf("\nTe dhenat u fshine me sukses.\n");
    }
    else
    {
        printf("\nQytetari nuk u gjet.\n");
    }
}

void kerkoEmrin()
{
    char emri[100];
    int i, gjetur = 0;

    printf("\nEmri: ");
    scanf("%s", emri);

    for (i = 0; i < n; i++)
    {
        if (strcmp(p[i].emri, emri) == 0)
        {
            printf("\nEmri: %s\n", p[i].emri);
            printf("Mbiemri: %s\n", p[i].mbiemri);
            printf("Adresa: %s\n", p[i].adresa);
            printf("Numri i telefonit: %d\n", p[i].nr_telefonit);
            printf("Email: %s\n", p[i].email);
            gjetur = 1;
        }
    }

    if (gjetur == 0)
    {
        printf("\nQytetari nuk u gjet.\n");
    }
}

void kerkoMbiemri()
{
    char mbiemri[100];
    int i, gjetur = 0;

    printf("\nMbiemri: ");
    scanf("%s", mbiemri);

    for (i = 0; i < n; i++)
    {
        if (strcmp(p[i].mbiemri, mbiemri) == 0)
        {
            printf("\nEmri: %s\n", p[i].emri);
            printf("Mbiemri: %s\n", p[i].mbiemri);
            printf("Adresa: %s\n", p[i].adresa);
            printf("Numri i telefonit: %d\n", p[i].nr_telefonit);
            printf("Email: %s\n", p[i].email);
            gjetur = 1;
        }
    }

    if (gjetur == 0)
    {
        printf("\nQytetari nuk u gjet.\n");
    }
}

void kerkonr()
{
    int nr_telefonit;
    int i, gjetur = 0;

    printf("\nNumri i telefonit: ");
    scanf("%d", &nr_telefonit);

    for (i = 0; i < n; i++)
    {
        if (p[i].nr_telefonit == nr_telefonit)
        {
            printf("\nEmri: %s\n", p[i].emri);
            printf("Mbiemri: %s\n", p[i].mbiemri);
            printf("Adresa: %s\n", p[i].adresa);
            printf("Numri i telefonit: %d\n", p[i].nr_telefonit);
            printf("Email: %s\n", p[i].email);
            gjetur = 1;
        }
    }

    if (gjetur == 0)
    {
        printf("\nQytetari nuk u gjet.\n");
    }
}

void afishoTeDhenat()
{
    int i;

    if (n == 0)
    {
        printf("\nNuk ka te dhena per te shfaqur.\n");
        return;
    }

    printf("\nTe dhenat e qytetareve:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nQytetari %d:\n", i + 1);
        printf("Emri: %s\n", p[i].emri);
        printf("Mbiemri: %s\n", p[i].mbiemri);
        printf("Adresa: %s\n", p[i].adresa);
        printf("Numri i telefonit: %d\n", p[i].nr_telefonit);
        printf("Email: %s\n", p[i].email);
    }
}

void rradhitSipasEmrit()
{
    int i, j;
    struct personi temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(p[j].emri, p[j + 1].emri) > 0)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nTe dhenat u rradhitin sipas emrit me sukses.\n");
}

void rradhitSipasMbiemrit()
{
    int i, j;
    struct personi temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (strcmp(p[j].mbiemri, p[j + 1].mbiemri) > 0)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    printf("\nTe dhenat u rradhitin sipas mbiemrit me sukses.\n");
}

void lexoTeDhenat(FILE *fp)
{
    int i;
    fscanf(fp, "%d\n", &n);

    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%s\n", p[i].emri);
        fscanf(fp, "%s\n", p[i].mbiemri);
        fgets(p[i].adresa, sizeof(p[i].adresa), fp);
        fscanf(fp, "%d\n", &p[i].nr_telefonit);
        fscanf(fp, "%s\n", p[i].email);
    }
}

void shkruajTeDhenat(FILE *fp)
{
    int i;
    fprintf(fp, "%d\n", n);

    for (i = 0; i < n; i++)
    {
        fprintf(fp, "%s\n", p[i].emri);
        fprintf(fp, "%s\n", p[i].mbiemri);
        fprintf(fp, "%s\n", p[i].adresa);
        fprintf(fp, "%d\n", p[i].nr_telefonit);
        fprintf(fp, "%s\n", p[i].email);
    }
}
