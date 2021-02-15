#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

int f=0,r=-1;
int fro=0,rea=-1;

int choice;

typedef struct PRQ
{
    char nm[20];
    int ele;
    int pr;
}PriorityQ;

typedef struct PRQ1
{
    char itm[20];
    int ele1;
    int pr1;
    int quant;
}PriorityQu;

PriorityQ PQ[SIZE];
PriorityQu PQu[SIZE];

//Function to insert
void PQinsert(int elem, int pre,char name[20])
{
    int i;
    if(r==SIZE-1)
    {
        printf("\nDone with all the Rooms!!");
    }
    else
    {
        i=r;
        r=r+1;
        while(PQ[i].pr > pre && i >= 0)
        {
            PQ[i+1]=PQ[i];
            i--;
        }
        PQ[i+1].ele=elem;
        PQ[i+1].pr=pre;
        strcpy(PQ[i+1].nm,name);
    }
}

void PQinsert_order(int elemn, int preo,char item[],int quan)
{
    int i;
    if(rea==SIZE-1)
    {
        printf("\nSent the orders!!\nNo order left!");
    }
    else
    {
        i=rea;
        rea=rea+1;
        while(PQu[i].pr1 > preo && i >= 0)
        {
            PQu[i+1]=PQu[i];
            i--;
        }
        PQu[i+1].ele1=elemn;
        PQu[i+1].pr1=preo;
        PQu[i+1].quant=quan;
        strcpy(PQu[i+1].itm,item);
    }
}

//To delete
PriorityQ PQdelete()
{
    PriorityQ p;
    if(f > r)
    {
        printf("\nNo Room Is Booked for the Sercvice yet!!");
        p.ele=-1;p.pr=-1;
        return(p);
    }
    else
    {
        p=PQ[f];
        f=f+1;
        return(p);
    }
}

PriorityQu PQdelete_order()
{
    PriorityQu p1;
    if(fro > rea)
    {
        printf("\nNo Order's there!!");
        p1.ele1=-1;p1.pr1=-1;
        return(p1);
    }
    else
    {
        p1=PQu[fro];
        fro=fro+1;
        return(p1);
    }
}

//Display the elements in queue
void display()
{
    int i;
    if(f>r)
    {
        printf("\nNo services remaining!");
    }
    else
    {
        printf("\nData: ");
        printf("[Name, Room_no, Priority]");
        printf("\nFront->");
        for(i=f;i<=r;i++)
            printf(" [%s,%d,%d] ",PQ[i].nm,PQ[i].ele,PQ[i].pr);
        printf("<-Rear");
    }
}

void display_order()
{
    int i;
    if(fro > rea)
    {
	printf("\nNo orders!!");
    }
    else
    {
	printf("\nData: ");
	printf("[Item, Quantity, Room_no, Priority]");
	printf("\nFront->");
	for(i=fro;i<=rea;i++)
	    printf(" [%s,%d,%d,%d] ",PQu[i].itm,PQu[i].quant,PQu[i].ele1,PQu[i].pr1);
	printf("<-Rear");
    }
}

void search(int room)
{
        PriorityQ p;
        int result,i;
        for ( i= 0; i < SIZE; i++)
        {
        if (PQ[i].ele == room)
        {
            result=1;
            break;
        }
        }
        if(result==1)
        {
            printf("\nThese are the details of %d room",room);
            printf("\nName: %s",PQ[i].nm);
            printf("\nRoom no: %d",PQ[i].ele);
            printf("\nPriority: %d",PQ[i].pr);
        }
        else
            printf("\n\tThere is no such room added");
}

void search_order(int orderno)
{
    PriorityQu p1;
    int result,i;
    for ( i= 0; i < SIZE; i++)
    {
	if (PQu[i].ele1 == orderno)
	{
	    result=1;
	   break;
	}
    }
    if(result==1)
    {
	printf("\n%d is present in the list!!",orderno);
	printf("\nThese are the Details of %d",orderno);
	printf("\nName: %s",PQu[i].itm);
	printf("\nQuantity: %d",PQu[i].quant);
	printf("\nRoom no: %d",PQu[i].ele1);
	printf("\nPriority: %d",PQu[i].pr1);
    }
    else
	printf("\n\tThere is no such order number %d ",orderno);
}

//Main() Function
void main()
{
    PriorityQ p;
    PriorityQu p1;
    int pass=1234;
    int input,x;
    int password;
    int total=0;

    while(1)
    {
	system("cls");
	printf("\n\n");
	printf("\n\t\t\t**************************************");
	printf("\n\t\t\t*Welcome to Hotel Management Service!*");
	printf("\n\t\t\t**************************************");
	printf("\n\t\t\t\tFor Hotel Staff");
	printf("\n\n\t\t\t\tPress any key to continue...");
	getch();
	printf("\n\n\t\t\tWelcome Admin!!");
	printf("\n\t\t\tPlease Enter the password: ");
	scanf("%d",&password);
	if(password==pass)
	{
            system("cls");
            printf("\n\tHello Admin!!");
            menu:
            while(1)
            {
                printf("\n\t----------------------------------------------------");
                printf("\n\t\t\t\tMenu");
                printf("\n\t1.Room Service\n\t2.Food Service\n\t3.Exit");
                printf("\n\t----------------------------------------------------");
                printf("\nYour Choice: ");
                scanf("%d",&input);
                switch(input)
                {
                    case 1:
                    //room_service();
                    while(1)
                    {
                        system("cls");
                        printf("\n\t\t\tRoom Cleaning Service in Hotel");
                        printf("\n\n1.Add Room\n2.Remove Room\n3.Show Pending Rooms\n4.Search room\n5.Exit");
                        printf("\nYour choice ");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                        case 1:
                            printf("\nEnter name: ");
                            scanf("%s",&p.nm);
                            printf("Enter room: ");
                            scanf("%d",&p.ele);
                            printf("Enter Priority:");
                            scanf("%d",&p.pr);
                            PQinsert(p.ele,p.pr,p.nm);
                            printf("\n\n\t\t\tPress Enter to Continue...");
                        break;
                        case 2:
                            p=PQdelete();
                            if( p.ele != -1)
                            {
                            printf("\nRoom %d is canceled",p.ele);
                            }
                            printf("\n\n\t\t\tPress Enter to Continue...");
                        break;
                        case 3:
                            display();
                            printf("\n\n\t\t\tPress Enter to Continue...");
                        break;
                        case 4:
                            printf("\nEnter the room no for Searching Details: ");
                            scanf("%d",&x);
                            search(x);
                            getch();
                            printf("\n\n\t\t\tPress Enter to Continue...");
                            break;
                        case 5:
                            system("cls");
                            goto menu;
                        default:
                            printf("Invalid Option");
                            printf("\n\n\t\t\tPress Enter to Continue...");
                        break;
                        }
                        getch();
                    }
                    break;
                    case 2:
                    //food_service();
                    while(1)
                    {
                        system("cls");
                        printf("\n\t\t\tFood Service");
                        printf("\n\n1.Add Order\n2.Send order \n3.Show Pending orders\n4.Search order\n5.Exit");
                        printf("\nYour choice ");
                        scanf("%d",&choice);
                        switch(choice)
                        {
                        case 1:
                            printf("Enter Item: ");
                            scanf("%s",&p1.itm);
                            printf("Enter Quantity: ");
                            scanf("%d",&p1.quant);
                            printf("Enter room: ");
                            scanf("%d",&p1.ele1);
                            printf("Enter Priority:");
                            scanf("%d",&p1.pr1);
                            PQinsert_order(p1.ele1,p1.pr1,p1.itm,p1.quant);
                            printf("\n\n\t\t\tPress Enter to Continue...");
                        break;
                        case 2:
                            p1=PQdelete_order();
                            if( p1.ele1 != -1)
                            {
                                printf("\nOrder sent to room no %d",p1.ele1);
                            }
                            printf("\n\n\t\t\tPress Enter to Continue...");
                        break;
                        case 3:
                            display_order();
                            printf("\n\n\t\t\tPress Enter to Continue...");
                        break;
                        case 4:
                             printf("\nEnter the room no to search order: ");
                             scanf("%d",&x);
                             search_order(x);
                             getch();
                             printf("\n\n\t\t\tPress Enter to Continue...");
                             break;
                        case 5:
                            system("cls");
                            goto menu;
                        break;
                        default:
                            printf("Invalid Option");
                            printf("\n\n\t\t\tPress Enter to Continue...");
                        break;
                        }
                        getch();
                    }
                    break;
                    case 3:
                        printf("\n\nThank you Admin!!");
                        getch();
                    exit(0);
                    default:
                        printf("\nInvalid Option");
                printf("\n\n\t\t\tPress Enter to Continue");
                        getch();
                        system("cls");
                        break;
                }

            }

        }
        if(password!=pass)
            printf("\n\t\t\tSorry!! Please Enter the Correct Password!");
            total++;
        if(total==3)
        {
            system("cls");
            printf("\n\t\t\tSorry!!");
            printf("\n\t\tYou have Entered wrong password more than 3 times!!!");
            getch();
            exit(0);
        }
        getch();
    }
}

//END
