#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element{
    char name[20];
    char sb[5];
    int atm;
    float atms;
};

void menu();
void add();
void view();
void exp();
void modify();
void displayTable();

int main()
{
    printf("\n\n\n\n\n\n\t\t\t\t\t<--:Modern Periodic Table:-->\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t\tProject Done By :- Akash Patil \n\t\t\t\t\t\t\t\t\tGR No :- 11910149\n\t\t\t\t\t\t\t\t\tYear-Division :- SY-C ");
    printf("\n\n\n\n\n\nPress any key to continue.");
    getch();
    menu();
    return 0;
}

void menu()
{
    system("cls");
    printf("\n\n\n");
    displayTable();
	printf("\n\n\t\t\t\t 1. Search.");
	printf("\n\t\t\t\t 2. Add new Element.");
	printf("\n\t\t\t\t 3. View.");
	printf("\n\t\t\t\t 4. Modify.");
	printf("\n\t\t\t\t 5. Save Element in file.");
	printf("\n\t\t\t\t 6. Exit.");
    printf("\n\n\t\t\t\t\nEnter your choice:\t");
	fflush(stdin);
	int choice = getch();
	switch(choice)
	{
		case '1':
			exp();
			break;

		case '2':
			add();
			break;

		case '3':
		    view();
		    break;

        case '4':
            modify();
            break;

        case '5':
            print();
            break;

        case '6':
			system("cls");
			printf("\n\n\n\n\t\t\t\tTHANK YOU\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			getch();
			exit(1);
			break;

		default:
			system("cls");
			printf("\n\n\t\t\t\tWrong choice, Try again");
	}
}

void add()
{

    char ch;
    struct element p ;
    FILE *fp;
    char another='y';
	system("cls");
	printf("---------> ADD ELEMENT <------------");
	printf("\n\nEnter the Information of Elements:");
    while (another == 'y')
    {
        printf("\n\nName: ");
        gets(p.name);
        p.name[0] = toupper(p.name[0]);
        fflush(stdin);
        printf("\nSymbol: ");
        gets(p.sb);
        p.sb[0] = toupper(p.sb[0]);
        fflush(stdin);
        printf("\nAtomic No: ");
        scanf("%d",&p.atm);
        fflush(stdin);
        printf("\nAtomic Wt: ");
        scanf("%f",&p.atms);
        fflush(stdin);

        fp = fopen("database.txt", "ab+");

        if(fp == NULL)
        {
            printf("Cannot open the record file. ");
            getch();
            exit(1);
        }
        fwrite(&p,sizeof(p),1,fp);
        fclose(fp);
        printf("\n\n\n\t\tEnter 'y' for next record(y/n):");
        another = getch();
    }
    fflush(stdin);
    menu();
}

void view()
{
    FILE *fp;
    struct element p ;
    system("cls");
    printf("<--:VIEW RECORD:-->\n\n");
    printf("Name         Symbol        Atomic No.      Atomic Weight\n");
    printf("------------------------------------------------------------\n");

    fp = fopen("database.txt", "rb+");

    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        printf("%-15s%-15s%-15d%-10f%\n",p.name,p.sb,p.atm,p.atms);
    }

    fclose(fp);
    printf("\n\n\nPress any key to continue.");
    getch();
    menu();
}

void print()                                //Function for printing information of fetched element
{
	FILE *fp, *fo; //fo -> new file so that it can be used to store
    struct element p;
    system("cls");
    fo = fopen("element_print.txt", "w+");
    fprintf(fo, "<--:ALL ELEMENTS:-->\n\n");
    fprintf(fo,"Name         Symbol        Atomic No.      Atomic Weight\n");
    fprintf(fo,"------------------------------------------------------------\n");
    fp = fopen("database.txt", "rb+");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        exit(1);
    }
    while (fread(&p, sizeof(p), 1, fp) == 1)
    {
        fprintf(fo,"%-15s%-15s%-15d%-10f%\n",p.name,p.sb,p.atm,p.atms);
    }
    fclose(fo);
    printf("\n\n\t\tData Saved in element_print.txt file successfully\n\n");
    fclose(fp);
    printf("\nPress any key to continue.");
    getch();
    menu();
}

void exp()                                      //Function to explore the periodic table (searching an element)
{
    FILE *fp;
    int AN, choice; //AN = Atomic Number
    struct element p;
    char EN[20],SY[5]; //EN = Element Name , SY = Symbol
    system("cls");
    printf("<--:SEARCH ELEMENT:-->\n\n");
    printf("Search through :\n");
    printf("1. Element Name\n");
    printf("2. Symbol \n");
    printf("3. Atomic Number \n");
    printf("4. Exit \n");
    printf("Enter Your choice : ");
    fflush(stdin);
    scanf("%d", &choice);
    fp = fopen("database.txt", "rb+");
    if (fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    switch (choice)
    {
    case 1:
    {
        printf("Enter Name of Element : ");
        fflush(stdin);
        gets(EN);
        EN[0] = toupper(EN[0]);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (strcmp(EN, p.name) == 0)
            {
                printf("\n\nName : %s\n", p.name);
                printf("Symbol : %s\n", p.sb);
                printf("Atomic Number : %d\n", p.atm);
                printf("Atomic Weight : %f\n", p.atms);
            }
        }
        break;
    }

    case 2:
    {
        printf("Enter Symbol of Element : ");
        fflush(stdin);
        gets(SY);
        SY[0] = toupper(SY[0]);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (strcmp(SY, p.sb) == 0)
            {
                printf("\n\nName : %s\n", p.name);
                printf("Symbol : %s\n", p.sb);
                printf("Atomic Number : %d\n", p.atm);
                printf("Atomic Weight : %f\n", p.atms);
            }
        }
        break;
    }

    case 3:
    {
        printf("\nEnter Atomic Number of Element : ");
        fflush(stdin);
        scanf("%d", &AN);
        while (fread(&p, sizeof(p), 1, fp) == 1)
        {
            if (AN == p.atm)
            {
                printf("\n\nName : %s\n", p.name);
                printf("Symbol : %s\n", p.sb);
                printf("Atomic Number : %d\n", p.atm);
                printf("Atomic Weight : %f\n", p.atms);
            }
        }
        break;
    }

    case 4:
        exit(1);
        break;

    default:
        printf("\n\nTry Again ");

    }
    fclose(fp);
    printf("\n\nPress any key to continue.");
    getch();
    menu();
}

void modify()
{
    char EN[20],SY[5];
    FILE *fp;
    int choice, AN;
    struct element p;
    system("cls");
    fp = fopen("database.txt", "rb+");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    printf("<--:MODIFY RECORD:-->\n\n");
    printf("Enter How would you like to search for modification :\n");
    printf("1. Element Name\n");
    printf("2. Symbol \n");
    printf("3. Atomic Number \n");
    printf("4. Exit \n");
    fflush(stdin);
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        printf("\n\nEnter Element Name to get to update Menu : ");
        fflush(stdin);
        gets(EN);
        EN[0] = toupper(EN[0]);
        printf("\nChoose what will you like to Modify :\n\n");
        printf("1. Element Name\n");
        printf("2. Symbol \n");
        printf("3. Atomic Number \n");
        printf("4. Atomic Mass \n");
        printf("\nEnter Your Choice : ");
        fflush(stdin);
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (strcmp(p.name,EN)==0)
                {
                    fflush(stdin);
                    printf("\nEnter Name which needs to be modified : ");
                    gets(p.name);
                    p.name[0] = toupper(p.name[0]);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;
                }
            }
            break;
        }
        case 2:
        {
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (strcmp(p.name,EN)==0)
                {
                    fflush(stdin);
                    printf("\nEnter Symbol to be modified  : ");
                    gets(p.sb);
                    p.sb[0] = toupper(p.sb[0]);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;
                }
            }
            break;
        }
        case 3:
        {
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (strcmp(p.name,EN)==0)
                {
                    printf("\nEnter Atomic Number to be modified : ");
                    scanf("%d", &p.atm);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;
                }
            }
            break;
        }

        case 4:
        {
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (strcmp(p.name,EN)==0)
                {
                    printf("\nEnter Atomic Mass to be modified : ");
                    scanf("%f", &p.atms);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;
                }
            }
            break;
        }

        case 5:
            exit(1);
            break;

        default:
            printf("Enter Correct Option ");
            break;
        }
        break;
    }
    case 2:
    {
        printf("\n\n\nEnter Element Symbol to get to update Menu : ");
        fflush(stdin);
        gets(SY);
        SY[0] = toupper(SY[0]);
        printf("\nChoose what will you like to Modify :\n\n");
        printf("1. Element Name\n");
        printf("2. Symbol \n");
        printf("3. Atomic Number \n");
        printf("4. Atomic Mass \n");
        printf("\nEnter Your Choice : ");
        fflush(stdin);
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (strcmp(p.sb,SY)==0)
                {
                    fflush(stdin);
                    printf("\nEnter Name which needs to be modified : ");
                    gets(p.name);
                    p.name[0] = toupper(p.name[0]);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;
                }
            }
            break;
        }
        case 2:
        {
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (strcmp(p.sb,SY)==0)
                {
                    fflush(stdin);
                    printf("\nEnter Symbol to be modified  : ");
                    gets(p.sb);
                    p.sb[0] = toupper(p.sb[0]);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;
                }
            }
            break;
        }
        case 3:
        {
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (strcmp(p.sb,SY)==0)
                {
                    printf("\nEnter Atomic Number to be modified : ");
                    scanf("%d", &p.atm);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;
                }
            }
            break;
        }

        case 4:
        {
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (strcmp(p.sb,SY)==0)
                {
                    printf("\nEnter Atomic Mass to be modified : ");
                    scanf("%f", &p.atms);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;
                }
            }
            break;
        }

        case 5:
            exit(1);
            break;

        default:
            printf("Enter Correct Option ");
            break;
        }
        break;
    }

    case 3:
    {
        printf("\n\n\nEnter Atomic Number of Element  to get to update Menu : ");
        fflush(stdin);
        scanf("%d",&AN);
        printf("\nChoose what will you like to Modify :\n\n");
        printf("1. Element Name\n");
        printf("2. Symbol \n");
        printf("3. Atomic Number \n");
        printf("4. Atomic Mass \n");
        printf("\nEnter Your Choice : ");
        fflush(stdin);
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (AN==p.atm)
                {
                    fflush(stdin);
                    printf("\nEnter Name which needs to be modified : ");
                    gets(p.name);
                    p.name[0] = toupper(p.name[0]);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;
                }
            }
            break;
        }
        case 2:
        {
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                    fflush(stdin);
                    printf("\nEnter Symbol to be modified  : ");
                    gets(p.sb);
                    p.sb[0] = toupper(p.sb[0]);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;

            }
            break;
        }
        case 3:
        {
            while (fread(&p, sizeof(p), 1, fp) == 1)
            {
                if (AN==p.atm)
                {
                    printf("\nEnter Atomic Number to be modified : ");
                    scanf("%d", &p.atm);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;
                }
            }
            break;
        }

        case 4:
        {
            while (AN==p.atm)
            {
                if (strcmp(p.sb,SY)==0)
                {
                    printf("\nEnter Atomic Mass to be modified : ");
                    scanf("%f", &p.atms);
                    fseek(fp, -sizeof(p), SEEK_CUR);
                    fwrite(&p, sizeof(p), 1, fp);
                    break;
                }
            }
            break;
        }

        case 5:
            exit(1);
            break;

        default:
            printf("Enter Correct Option ");
            break;
        }
        break;
    }

    case 4 :
        exit(1);
        break;

    default:
        printf("\nIncorrect Option try again ");
        break;

    }
    fclose(fp);
    printf("Press any key to continue.");
    getch();
    menu();
}

void displayTable()                 //Displaying the modern periodic table.
{
    printf("\n\t\t\t\tTHE MODERN PERIODIC TABLE\n");
    printf("\t\t\t\t-------------------------\n");
    printf("\tH                                                                   He\n\n");
    printf("\tLi  Be                                           B   C  N   O   F   Ne\n\n");
    printf("\tNa  Mg                                          Al  Si  P   S   Cl  Ar\n\n");
    printf("\tK   Ca  Sc  Ti  V   Cr  Mn  Fe  Co  Ni  Cu  Zn  Ga  Ge  As  Se  Br  Kr\n\n");
    printf("\tRb  Sr  Y   Zr  Nb  Mo  Tc  Ru  Rh  Pd  Ag  Cd  In  Sn  Sb  Te  I   Xe\n\n");
    printf("\tCs  Ba  La  Hf  Ta  W   Re  Os  Ir  Pt  Au  Hg  Tl  Pb  Bi  Po  At  Rn\n\n");
    printf("\tFr  Ra  Ac  Rf  Db  Sg  Bh  Hs  Mt  Ds  Uuu Uub -   Uuq  -  Uuh\n\n\n");
    printf("\n\t\t  Ce  Pr  Nd  Pm  Sm  Eu  Gd  Tb  Dy  Ho  Er Tm Yb Lu\n\n");
    printf("\t\t  Th  Pa  U   Np  Pu  Am  Cm  Bk  Cf  Es  Fm Md No Lr\n\n\n");
}

