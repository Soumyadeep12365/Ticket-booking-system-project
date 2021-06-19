#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<process.h>
#include<dos.h>
void book();
void menu();
void display();
void cancel();
int seat[6][5];
int main()
{

	int i,j;
	for(i=0;i<6;i++)
	{
		for(j=0;j<5;j++)
		seat[i][j]=0;
	}

	menu();

}
void menu()
{
	system("cls");
	int choice,operation;
	do
    {
    	printf("\n\t\t\t\t\t****Welcome to Easy Bus****\n");
    	printf("\t\t\t\t\t...............................\n");
        printf("\n\t\t\ [1] Book Ticket\t [2] Cancel Booking\t [3] Seat Matrix\t [4] Exit\n");
        printf("\n Please Enter Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        	case 1:
        		book();
        	    break;
        	case 2:
        		cancel();
        		break;
			case 3:
				display();
				break;
			case 4:
				printf("\n Booking Software is Shutting Down....");
				break;

			default:
        		printf("\n\t\t\t\tInvalid Choice........Please Choose from the above options");
        }
        printf("\n Do you want to do any other operations....?\n Press 1 to continue....Press 2 to exit....");
		scanf("%d",&operation);
		if(operation==1)
		{
			menu();
		}
	}
	while(choice==5);
}
void book()
{
	int i,j,n,row,col,count=0;
	printf("\n\t\t\t\t\t\t****..Book here..****\n\n");
	display();
	printf("\n How many Seats do you want to book?\n");
	scanf("%d",&n);
	for(i=0;i<6;i++)
	{
		for(j=0;j<5;j++)
		{
			if(seat[i][j]==0)
			count++;
		}
	}
	if(n>count)
	{
		printf("\n Sorry only %d seats are available!!!",count);
		return;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			printf("\n Please enter the row no you want to book: ");
			scanf("%d",&row);
			printf("\n Please enter the column no you want to book: ");
			scanf("%d",&col);
			if(row<=6&&col<=5) //checking the row/col no entered is available or not
			{
			    if(seat[row-1][col-1]==0) //checking the seat is booked/empty
			    {
			    	//details();
				    printf("\n Booking Successful!!!!");
				    seat[row-1][col-1]=1;

			    }
			    else
			    {
			    	printf("\n Sorry....It's Already Booked!!!!");
				}
	        }
	        else
	        {
	        	printf("\n Please Enter Correct Input....");
			}
		}
	}
}
void cancel()
{
	int i,n,row,col;
	printf("\n\t\t\t\t\t\t****..Cancel here..****\n\n");
	display();
	printf("\n How many Seats do you want to cancel?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Please enter the row no you have booked: ");
		scanf("%d",&row);
		printf("\n Please enter the column no you have booked: ");
		scanf("%d",&col);
		if(row<=6&&col<=5) //checking the row/col no entered is available or not
		{
			if(seat[row-1][col-1]==1) //checking the seat is booked/empty
			{
				printf("\n Cancellation Successful!!!!");
				seat[row-1][col-1]=0;
			}
			else
			{
			    printf("\n Sorry....It's Not Booked!!!!");
			}
	    }
	    else
	    {
	        printf("\n Please Enter Correct Input....");
		}
	}
}

void display()
{
	//displaying seat arrangement
	int i,j;
	char ch;
	for(i=0;i<6;i++)
	{
		ch='A';
		for(j=0;j<5;j++)
		printf("%c%d=%d\t\t\t",ch++,i+1,seat[i][j]);
		printf("\n\n");
    }
}
