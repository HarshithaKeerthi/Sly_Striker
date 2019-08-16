

#include<fstream>
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
 
class product
{
	public:
	int p[100];
	char product_number[11];
	char product_name[50];
	char product_price[50],product_quantity[50],tax,product_discount[50];
}; 
 
int p[1000],c=0;
fstream fp;
product produc;

void update()
{
	for(int i=0;i<1000;i++)
	p[i]=0;
	if(c==0)
	{
		char b[100];
		fp.open("database.txt",ios::in|ios::out);
		while(!fp.eof())
		{
			fp.getline(b,100,'$');
			if(fp.eof())
			break;
			if(b[0]!='*')
			{
				sscanf(b,"%[^|]|%[^|]|%[^|]|%[^|]$",produc.product_number,produc.product_name,produc.product_price,produc.product_discount);
				p[atoi(produc.product_number)]=1;
		 	}
			
			
		}
		fp.close();	
		c++;
	}
}
 
void save_product()
{	
	char b[100];
	int i;

	cout<<"\nEnter product_number : ";
	cin>>produc.product_number;
	if(p[atoi(produc.product_number)]==1)
	{
				cout<<"duplicate product no!!!";
				return;
	}
	p[atoi(produc.product_number)]=1;
	cout<<"\n product_name : ";
			cin>>produc.product_name;
			cout<<"\n product_price : ";
			cin>>produc.product_price;
			cout<<"\n product_discount : ";
			cin>>produc.product_discount;
	
	fp.open("database.txt",ios::app);
	sprintf(b,"%s|%s|%s|%s$",produc.product_number,produc.product_name,produc.product_price,produc.product_discount);
	fp<<b;
	fp.close();
	cout<<endl<<endl<<"\tThe Product Has Been Sucessfully Created..."<<endl;

}
 
void show_all_product()
{	
	char b[100];
	system("cls");
	
		cout<<endl<<endl<<"\t\tPRODUCTS\n\n";
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\tP.NO.\t\tNAME\t\t\tPRICE\t\tDISCOUNT\n";
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	fp.open("database.txt",ios::in);
	while(!fp.eof())
	{
		fp.getline(b,100,'$');
		if(fp.eof())
		break;
		if(b[0]!='*')
		{
			sscanf(b,"%[^|]|%[^|]|%[^|]|%[^|]$",produc.product_number,produc.product_name,produc.product_price,produc.product_discount);
			if(strlen(produc.product_name)>7)
				cout<<"\t"<<produc.product_number<<"\t\t"<<produc.product_name<<"\t\t"<<produc.product_price<<"\t\t"<<produc.product_discount<<endl;	
			else
			
			cout<<"\t"<<produc.product_number<<"\t\t"<<produc.product_name<<"\t\t\t"<<produc.product_price<<"\t\t"<<produc.product_discount<<endl;	
		}
		
	}
	fp.close();
	getch();
	
}
 
void display_record()
{
	char b[100],product_number[11];
	int flag=0;
	fp.open("database.txt",ios::in);
	cout<<"\nEnter product_number to be searched: ";
	cin>>product_number;
	while(1)
	{
		fp.getline(b,100,'$');
		if(fp.eof())
			break;
		if(b[0]!='*')
		{
			sscanf(b,"%[^|]|%[^|]|%[^|]|%[^|]$",produc.product_number,produc.product_name,produc.product_price,produc.product_discount);
			if(strcmp(produc.product_number,product_number)==0)
			{
				flag=1;
				system("cls");
				cout<<endl<<endl<<"\t\tPRODUCTS\n\n";
					cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
					cout<<"\tP.NO.\t\tNAME\t\t\tPRICE\t\tDISCOUNT\n";
					cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
					if(strlen(produc.product_name)>7)
						cout<<"\t"<<produc.product_number<<"\t\t"<<produc.product_name<<"\t\t"<<produc.product_price<<"\t\t"<<produc.product_discount<<endl;	
					else
						cout<<"\t"<<produc.product_number<<"\t\t"<<produc.product_name<<"\t\t\t"<<produc.product_price<<"\t\t"<<produc.product_discount<<endl;	
			}
		}
		
	}
	if(flag==0)
		cout<<"\n product not found";
	fp.close();
	getch();
}




void edit_product()
{	
	char b[100],product_number[11];
	int flag=0;
	fstream file1;
	file1.open("temp.txt",ios::app);
	fp.open("database.txt",ios::in|ios::out);
	system("cls");
	cout<<endl<<endl<<"\tPlease Enter The Product Number : ";
	cin>>product_number;
	while(1)
	{
		fp.getline(b,100,'$');
		
		if(fp.eof())
		break;
		
		
			sscanf(b,"%[^|]|%[^|]|%[^|]|%[^|]$",produc.product_number,produc.product_name,produc.product_price,produc.product_discount);
	
			if(strcmp(produc.product_number,product_number)==0)
			{
				cout<<"\nKey found\n: ";
				p[atoi(product_number)]=0;
				cout<<"\nEnter product_number:"; cin>>produc.product_number;
				if(p[atoi(produc.product_number)]==1)
				{
					cout<<"duplicate product no!!!";
					file1.close();
					fp.close();
					return;
				}
				p[atoi(product_number)]=0;
				p[atoi(produc.product_number)]=1;
				cout<<"\nENter product_name: "; cin>>produc.product_name;
				cout<<"\nENter product_price: "; cin>>produc.product_price;
				cout<<"\nEnter product_discount: "; cin>>produc.product_discount;
				sprintf(b,"%s|%s|%s|%s$",produc.product_number,produc.product_name,produc.product_price,produc.product_discount);
				file1<<b;
				flag=1;
			}
			else
			{
				strcat(b,"$");
				file1<<b;
			}
		
		
	
	}
	file1.close();
	fp.close();
	remove("database.txt");
	rename("temp.txt","database.txt");
	if(!flag)
		printf("record not found");
		
}



 
 
void delete_product()
{	
	char b[100],c[100],product_number[11];
	int flag=0,x,count1=0,i;
	fp.open("database.txt",ios::in);
	system("cls");
	cout<<endl<<endl<<"\tPlease Enter The Product Number : ";
	cin>>product_number;
	while(1)
	{
		fp.getline(b,100,'$');
		count1++;
		if(fp.eof())
		break;
		sscanf(b,"%[^|]|%[^|]|%[^|]|%[^|]$",produc.product_number,produc.product_name,produc.product_price,produc.product_discount);

		if(strcmp(produc.product_number,product_number)==0)
		{
			cout<<"\nproduct deleted\n: ";
			p[atoi(produc.product_number)]=0;
			produc.product_number[0]='*';
			
			sprintf(c,"%s|%s|%s|%s$",produc.product_number,produc.product_name,produc.product_price,produc.product_discount);
			flag=1;
			x=count1;
		}
	}
	fp.close();
	if(!flag)
		printf("record not found");
	else
	{
		fp.open("database.txt",ios::in|ios::out);
		for(i=0;i<x-1;i++)
			fp.getline(b,100,'$');
			
		fp<<c;
		fp.close();
	}
}



void reclaim_space()
{	
	char b[100],c[100],product_number[11];
	int flag=0;
	fstream file1;
	file1.open("temp.txt",ios::app);
	fp.open("database.txt",ios::in|ios::out);
	system("cls");
	while(1)
	{
		fp.getline(b,100,'$');
		if(fp.eof())
		break;
		if(b[0]!='*')
		{
			strcat(b,"$");
			file1<<b;
		}
	
	}
	file1.close();
	fp.close();
	remove("database.txt");
	rename("temp.txt","database.txt");
	cout<<"successfully reclaimed space";
	getch();
}



void product_menu()
{
	char b[100];
	system("cls");
	fp.open("database.txt",ios::in);
 
	cout<<endl<<endl<<"\t\tProduct MENU\n\n";
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\tP.NO.\t\tNAME\t\t\tPRICE\t\tDISCOUNT\n";
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	
	while(!fp.eof())
	{
		fp.getline(b,100,'$');
		if(fp.eof())
 		break;
		if(b[0]!='*')
		{
			sscanf(b,"%[^|]|%[^|]|%[^|]|%[^|]$",produc.product_number,produc.product_name,produc.product_price,produc.product_discount);
			if(strlen(produc.product_name)>7)
				cout<<"\t"<<produc.product_number<<"\t\t"<<produc.product_name<<"\t\t"<<produc.product_price<<"\t\t"<<produc.product_discount<<endl;	
			else
				cout<<"\t"<<produc.product_number<<"\t\t"<<produc.product_name<<"\t\t\t"<<produc.product_price<<"\t\t"<<produc.product_discount<<endl;	
		}
		
	}
	fp.close();
	getch();
}
 
 void place_order()
{
	int order_arr[50],quan[50],c=0,temp;
	float amt,damt,total=0;
	char b[100];
	char ch='Y';
	
	product_menu();
	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout<<"\n PLACE YOUR ORDER";
	cout<<"\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	do{
		cout<<"\n\nEnter The Product # : ";
		cin>>order_arr[c];
		cout<<"\nQuantity: ";
		cin>>quan[c];
		c++;
		cout<<"\nDo You Want To Order Another Product ? (y/n)";
		cin>>ch;
		}while(ch=='y' ||ch=='Y');
	cout<<"\n\nThank You...";
	getchar();
	system("cls");
	
	cout<<"\n\n**************************************INVOICE****************************************\n";
	cout<<"\nPr No.\tPr Name\t\t\tQuantity \tPrice \tAmount \tAmount after discount\n";
	for(int x=0;x<=c;x++)
	{
		fp.open("database.txt",ios::in);
		while(!fp.eof())
		{	
			fp.getline(b,100,'$');
			
			if(b[0]!='*')
			{
				sscanf(b,"%[^|]|%[^|]|%[^|]|%[^|]$",produc.product_number,produc.product_name,produc.product_price,produc.product_discount);

				if(atoi(produc.product_number)==order_arr[x])
				{
					float price;
					price=atof(produc.product_price);
					float discount;
					discount=atof(produc.product_discount);
					amt=price*quan[x];
					damt=amt-(amt*discount/100);
					if(temp!=atoi(produc.product_number))
					{
							if(strlen(produc.product_name)>7)
								cout<<"\n"<<order_arr[x]<<"\t"<<produc.product_name<<"\t\t"<<quan[x]<<"\t\t"<<produc.product_price<<"\t"<<amt<<"\t\t"<<damt;
							else
								cout<<"\n"<<order_arr[x]<<"\t"<<produc.product_name<<"\t\t\t"<<quan[x]<<"\t\t"<<produc.product_price<<"\t"<<amt<<"\t\t"<<damt;

					}
					total+=damt;
				}
				temp=atoi(produc.product_number);
			}
			
		}
		fp.close();
	}
	cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
	getchar();
}

void intro() 
{
	
	update();
	cout<<"hi:";
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<setw(70)<< "SUPER MARKET\n\n\n\n";
	cout<<setw(68)<<"BILLING SYSTEM\n";
    cout<<"\n\n\n\n\n\n\n";
    cout << "  MADE BY : HARSHITHA M & NAMARATHA K               ";
    getch();

} 
 
void admin_menu()
{
	system("cls");
	int option;
	cout<<"\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\n\t\t\t\t\t\tPress 1 to CREATE PRODUCT\n";
	cout<<"\n\t\t\t\t\t\tPress 2 to DISPLAY ALL PRODUCTS\n";
	cout<<"\n\t\t\t\t\t\tPress 3 to QUERY\n";
	cout<<"\n\t\t\t\t\t\tPress 4 to MODIFY PRODUCT\n";
	cout<<"\n\t\t\t\t\t\tPress 5 to DELETE PRODUCT\n";
	cout<<"\n\t\t\t\t\t\tPress 6 to RECLAIM SPACE\n";
	cout<<"\n\t\t\t\t\t\tPress 7 to GO BACK TO MAIN MENU\n";
	cout<<"\n\t\t\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
 
	cout<<"\n\n\t\t\t\t\t\tOption: ";
	cin>>option;
	switch(option)
	{
		case 1: system("cls");
				save_product();
				break;
				
		case 2: show_all_product();
				break;
				
		case 3:
				int num;
				system("cls");
				display_record();
				break;
				
		case 4: edit_product();
		break;
		
		case 5: delete_product();
		        break;
		        
		case 6: reclaim_space();
		        break;
				
		case 7: system("cls");
				break;
		
		default:admin_menu();
	}
}
 
int main(int argc, char *argv[])
{
	system("cls");
	intro();
	system("color 0F");
	char pass[20];
	for(;;)
	{
		system("cls");
		cout<<"*****************************************@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*********************************************\n\n"<<endl;
		cout<<"***************************************     SUPER MARKET BILLING SYSTEM     *******************************************\n\n"<<endl;
		cout<<"*****************************************@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*********************************************\n\n"<<endl;
		cout<<"\t\t\t@@@@@@@@@@@@@@@@             LOGIN             @@@@@@@@@@@@@@@@"<<endl;
		cout<<"\n\n\n\n";
		cout<<setw(65)<<"Enter the password : ";
		cin>>pass;
		if(strcmp(pass,"12345")==0){
			
			system("cls");
			cout<<"*****************************************@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*********************************************\n\n"<<endl;
			cout<<"***************************************    SUPER MARKET BILLING SYSTEM     *******************************************\n\n"<<endl;
			cout<<"*****************************************@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*********************************************\n\n"<<endl;
			cout<<"\t\t\t@@@@@@@@@@@@@@@@             WELCOME             @@@@@@@@@@@@@@@@\n"<<endl;
			int option;
			
			for(;;)
			{
		 
				cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
				cout<<"\n\t1. CUSTOMER BILL GENERATION\n";
				cout<<"\n\t2. PRODUCT INFORMATION\n";
				cout<<"\n\t3. EXIT\n";
				cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
				
				cout<<"\n\tOption: ";
				cin>>option;
				
				switch(option)
				{
					case 1: system("cls");
							place_order();
							getchar();
							break;
							
					case 2: admin_menu();
							break;
							
					case 3: 
							cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
							cout<<"\n\t Thank You. Good Bye !\n";
							cout<<"\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
							exit(0);
					
					default :cout<<"Invalid Input...\n";
				}
		 
			}
	}
	else
	{
		char ch[20];
		cout<<"\n";
		cout<<"  Password Incorrect !\n";
		cout<<"  Please try again ! Enter any character key to retry.\n\n  ";
		cin>>ch;
		if(ch)
			system("cls");
	}

	}
	return 0;
}

