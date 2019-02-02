#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
	int book_id;
	char book_name[1000];
	char book_author[1000];
};

struct member
{	int member_id;
	char member_name[100];
	char department[50];
	long phone_number;
};

	void add_book();
	void search_book();
	void show();
	void authorname_search();
	void issue_book();
	void return_book();
	void add_member();
	void return_book();
	void students_list();
	void exit_prog();
	
	FILE *library_record;
	FILE *member_record;
	FILE *fp1;
	FILE *fp2;
	FILE *fp3;
	
int main()	
{
	int ch=0;
	system("cls");
	printf("\n\n\n\t\t\tLIBRARY MANAGEMENT SYSTEM\n");
	printf("\n\n\n\t\t\tUNDER DEVELOPMENT\n");
	printf("\n\n\n\t\t\tDEVELOPER: ABHINAV KARN\n");
	printf("\n\n\n\n\t\t\TPress any key to continue. . .");
	
	do
	{	
		system("cls");
		printf("\n\n\n\t\t\t========     MAIN MENU    =========");
		printf("\n\t\t\t 1. Add New Book");
		printf("\n\t\t\t 2. Book Search");
		printf("\n\t\t\t 3. Author Search");
		printf("\n\t\t\t 4. Add Member");
		printf("\n\t\t\t 5. Member List");
		printf("\n\t\t\t 6. Issue Book");
		printf("\n\t\t\t 7. Show Library Books");
		printf("\n\t\t\t 8. Return Book");
		printf("\n\t\t\t 9. Exit");
		printf("\n\n\t\t\t\tEnter Choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: 	add_book();
						break;
			case 2:		search_book();
			printf("here");
			getch();
						break;
			case 3:		authorname_search();
						break;
			case 4:		add_member();
						break;
			case 5:		students_list();
						break;
			case 6:		issue_book();
						break;
			case 7:		show();
						break;
			case 8:		return_book();
						break;
			case 9:		exit_prog();
						break;
			default:	printf("\n\n\n\t\t\tWrong Choice Try Again. . .");
						getch();
		}
	}while(1);
}

void add_book()
{
	system("cls");
	struct book b;
	library_record=fopen("library_record","ab");
	if(library_record==NULL)
	{
		printf("\n\t\t\t\tThe file is empty. . .");
	}
	printf("\n\t\tEnter BOOK ID: ");
	scanf("%d",&b.book_id);
	printf("\n\t\tEnter the NAME OF THE BOOK: ");
	fflush(stdin);
	gets(b.book_name);
	printf("\n\t\tEnter the AUTHOR OF THE BOOK: ");
	gets(b.book_author);
	fwrite(&b,sizeof(b),1,library_record);
	printf("\n\t\tBOOK ADDED SUCCESSFULLY.....");
	fclose(library_record);
	getch();
}

void search_book()
{
	system("cls");
	struct book b;
	char s[100];
	library_record=fopen("library_record","rb");
	if(library_record==NULL)
	{
		printf("\n\t\t\t\tThe file is empty. . .");
		getch();
	}
	printf("\n\t\tEnter the BOOK NAME TO BE SEARCHED:");
	fflush(stdin);
	gets(s);
	while(fread(&b,sizeof(b),1,library_record))
	{	printf("fghfj");
		if(s==b.book_name)
		{
			printf("\n\t\tCongrats BOOK Found...\n");
			printf("\n\t\tBOOK ID:%6d \n\t\tBOOK NAME:%20s \n\t\tBOOK AUTHOR:B%20s",b.book_id,b.book_name,b.book_author);
			fclose(library_record);
			return;
		}
		printf("\n\t\tSorry Record Not Found!");
		return;	
	}
	getch();
}

void authorname_search()
{
	system("cls");
	struct book b;
	char s[100];
	library_record=fopen("library_record","rb");
	if(library_record==NULL)
	{
		printf("\n\t\t\t\tThe file is empty. . .");
	}
	printf("\n\t\tEnter the BOOK AUTHOR TO BE SEARCHED:");
	gets(s);
	while(fread(&b,sizeof(b),1,library_record))
	{
		if(s==b.book_author)
		{
			printf("\n\t\tCongrats BOOKS Found...\n");
			printf("\n\t\tBOOK ID:%6d \n\t\tBOOK NAME:%20s \n\t\tBOOK AUTHOR:B%20s \n",b.book_id,b.book_name,b.book_author);
			fclose(library_record);
		}
	}
	printf("\n\t\tSorry Record Not Found!");
	getch();
	return;
}

void add_member()
 {
 	system("cls");  
    struct member m;
    int no,i;
    member_record=fopen("member_record","ab");
    if(member_record==NULL)
    {
      printf("\n unable to open file");
      return;
     }
     printf("\n**enter the no of student data you want to enter:");
     scanf("%d",&no);
     for(i=0;i<no;i++)
      {
      	printf("\nenter %d student id:",i+1);
      	scanf("\n%6d",&m.member_id);
      	printf("enter %d student name:",i+1);
      	scanf("\n%20s",m.member_name);
      	fflush(stdin);
      	printf("enter %d student department:",i+1);
      	scanf("%20s",m.department);
	  	printf("\n");
	  	printf("\n\t\tEnter the student Phone Number :");
	  	scanf("%ld",m.phone_number);
	  	fwrite(&m,sizeof(m),1,member_record);
      }
     fclose(member_record);
     if(no<2)
     printf("\n\t\tStudent Record is added");
     else
     printf("\n\t\tStudents Record are added");
     getch();
 }

void issue_book()
{
	system("cls");
	struct book b;
	int b_no,flag=0;
	fp1=fopen("books","rb");
	fp2=fopen("issue","ab");
	fp3=fopen("temp","ab");
	if(fp1==NULL)
	{
		printf("\n\n\t\tFILE IS EMPTY");
		return;
	}
	printf("\n\nBook number to be Issued :");
	scanf("%d",&b_no);
	while(fread(&b,sizeof(b),1,fp1))
	{
		if(b_no!=b.book_id)
			fwrite(&b,sizeof(b),1,fp3);
		else
		{
			fwrite(&b,sizeof(b),1,fp2);
			flag=1;
		}
	}
	if(flag==0);
	{
		printf("\n\nBook not Found...\n");
		return;
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	remove("books");
	rename("temp","books");
	getch();

}

void return_book()
{
	
}

void students_list()
{
    struct member m;
    member_record=fopen("std","rb");
    if(member_record==NULL)
     {
      printf("sorry file not found");
      return;
     }
     while(fread(&m,sizeof(m),1,member_record));
     printf("\n\t\tSTUDENT NAME:%6d\n\t\tSTUDENT NAME:%20s\n\t\tSTUDENT DEPARTMENT%20s\n\t\tSTUDENT PHONE NUMBER:%20ld\n",m.member_id,m.member_name,m.department,m.phone_number);
     fclose(member_record);
     getch();
}

void show()
{
	struct book b;
	library_record=fopen("books","rb");	
	if(library_record==NULL)
	{
		printf("\n\nFILE NOT FOUND\n");
		return;
	}
	while(fread(&b,sizeof(b),1, library_record))
	{
		printf("\n\t\tBOOK ID:%6d \n\t\tBOOK NAME:%20s \n\t\tBOOK AUTHOR:B%20s \n",b.book_id,b.book_name,b.book_author);
	}
	fclose(library_record);
	getch();
}

void login()
{
	char p[15],u[15]={0};
    int n=1, i=0;
    getch();
    system("cls");
    while(n<4) {
    	printf("\nUSER ID: ");
      	scanf("%s",u);
      	printf("PASS: ");
    	while(u[i-1]!=13) {
   	 		
				u[i++]=getch();
				printf("*");
			
		}

    	if(strcmp(u,"admin")==0&strcmp(p,"abc123")==0) 
		{
         	printf("\n\t\tYou have logged in successfully.");
			break;
      	}
    	else
      	{
         	printf("\nWrong PASSWORD and/or USER ID. Now you have % d more chance/s.\n",3-n);
         	getch();
         	printf("\nPress any key to continue again...");
         	system("cls");
      	}
      	n++;
    }
   if(n==4)
    {
      printf("\nYou can't log in.");
      getch();
      exit(0);
	}
}


void exit_prog()
{

	printf("\n\t\t\t\tThnx Come Back Again. . .");
	getch();
	exit(0);

}
