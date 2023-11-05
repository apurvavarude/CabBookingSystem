 #include<iostream>
#include<string.h>
#include<cstdlib>
#include<conio.h>
using namespace std;

class node		
{
	public:
	
		string acc_name;
	    long long int acc_mob;
		int top;
		int acc_pin;
    	string a[100];
		char b[100];
		int bill[100];
		int np[100];
		int d[100];
		int m[100];
		int y[100];
		string time[100];
		node *link;
	
};
node *head=NULL,*temp,*New,*last,*prevv,*next,*loop;
//class cab;
class basic
{
	int a;
   public :
   	string adminname="admin";
		string password="0000";
		
     void menu();
	 void create();
	 void findlast();
	 void getdata();	
     void login();
     void book();
	friend void details();
  void admin();
 inline void showdata()       //using showdata to show data
    {
	cout<<"\nAccount holder name : "<<temp->acc_name<<endl;
	cout<<"\nAccount Mobile Number     : "<<temp->acc_mob<<endl;
	cout<<"\nSecurity pin        : "<<temp->acc_pin;
	cout<<"\nSource       : "<<temp->a;
	cout<<"\nDestination        : Islampur";
	cout<<"\nSecurity pin        : "<<temp->d<<"-"<<temp->m<<"-"<<temp->y<<"\n Time : "<<temp->time;
	
	cout<<"\nNumber of Persons        : "<<temp->np;
	cout<<"\nTotal BIll       : "<<temp->bill;
     
    }
	
};

class cab :public basic
{
	public:
   
};

void basic :: menu()
{
    cout<<"\n\n\t\t\t\t..........WELCOME TO SAVARI CABS.............";
	cout<<"\n\n1.Create Account:";
	cout<<"\n\n2.Book Cab :";
	cout<<"\n\n3.Get  Booked Cab Details:";
	cout<<"\n\n4.Admin Login :";
	cout<<"\n\n5.Exit";
}
void basic::create()
{
	int no;
	string name;
	long long int mob;
	int pin;
	cout<<"\nEnter  Name: ";
	cin.ignore();
	getline(cin,name);
	cout<<"\nEnter 10 digit Mobile number : ";
	cin>>mob;
	cout<<"\nEnter your four digit security pin: ";
	cin>>pin;
	New= new node;
	New->acc_name=name;
	New->acc_mob=mob;
	New->acc_pin=pin;
	New->top=0;

	New->link=NULL;
}
void basic::findlast()		//find last function to find last node
{
	last=head;
	while(last->link!=NULL)
	{
		last=last->link;
	}
}
void basic::getdata()
{
	create();
	if(head==NULL)
	{
		head=New;
		cout<<"\n\nAccount has been successfully created!";
	}					//using singly linked list insert at end logic 
	else
	{
		int c1=0;
		temp=head;
		while(temp!=NULL)
		{
			if(New->acc_pin>=1000 && New->acc_pin<=9999)
				c1=0;
			else
				c1=4;
				
			temp=temp->link;
		}
		if(c1==0)
		{
			findlast();
			last->link=New;
			cout<<"\n\nAccount has been successfully created!";
		}
		else if(c1==4)
		{
			cout<<"\n\nInvalid pin format!"<<endl;
			cout<<"Please enter four digit pin!"<<endl;
		}
	}
}

void basic ::book()
{
	int source;
	int dd,mm,yy;
	string time1;
	if(head==NULL)
	{
		cout<<"\n\nAccount's record is empty!";
	}
	else
	{
		int z,p,count=0;
		cout<<"\nEnter your security pin: ";
		cin>>p;
		temp=head;
		while(temp!=NULL)
		{
				if(p==temp->acc_pin)
				{
					++temp->top;
					cout << "Enter Source Address Choices - : " << endl;
                    cout << "1.Sangli\n2.Vita\n3.Karad\n " << endl;
                    cin >> source;
                                                   
                  //  system("cls");
                    cout << "Kindly ender the date to book a cab" << endl;
                    cin >> dd>>mm>>yy;
                    temp->d[temp->top]=dd;
                    temp->m[temp->top]=mm;
                    temp->y[temp->top]=yy;
                    cout << "Please enter suitable time" << endl;
                	cin.ignore();
                 	getline(cin,time1);
                    temp->time[temp->top]=time1;
                    cout << " Enter No. of Persons - " << endl;
                    cin >> p;
                    temp->np[temp->top]=p;
             if(source==1){
			 
                    temp->a[temp->top]="Sangli";
		
			 if (p == 1)
                temp->bill[temp->top]=80;
            else if (p == 2)
                temp->bill[temp->top]=160;
            else if (p == 3)
                temp->bill[temp->top]=240;
            else if (p == 4)
                temp->bill[temp->top]=320;
            else
                cout << " Enter valid no of person " << endl;
            }
            else if(source==2){
			
                    temp->a[temp->top]="Vita";
                    if (p == 1)
                temp->bill[temp->top]=70;
            else if (p == 2)
                temp->bill[temp->top]=140;
            else if (p == 3)
                temp->bill[temp->top]=210;
            else if (p == 4)
                temp->bill[temp->top]=280;
            else
                cout << " Enter valid no of person " << endl;
            }
                else if(source==3){
				
                    temp->a[temp->top]="Karad";
                       if (p == 1)
                temp->bill[temp->top]=45;
            else if (p == 2)
                temp->bill[temp->top]=90;
            else if (p == 3)
                temp->bill[temp->top]=135;
            else if (p == 4)
                temp->bill[temp->top]=180;
            else
                cout << " Enter valid no of person " << endl;  
			}
                
               	cout<<"cab Booked Successfully \n Details as : \n";   
			   	cout<<"\nSource             : "<<temp->a[temp->top];
            	cout<<"\nDestination        : RIT college";
            	cout<<"\nDate & Time        : "<<dd<<"-"<<mm<<"-"<<yy<<"  ontime  "<<time1;
				cout<<"\nNumber of Persons  : "<<p;
        		cout<<"\nTotal BIll         : "<<temp->bill[temp->top]; 
        		                
				}
		   
		   temp=temp->link;
	    }
	}
	  
  }

void  details()
{	int count=0;
    	if(head==NULL)
	{
		cout<<"\n\nAccount's record is empty!";
	}
	else
	{
		int a,i,j=1,count=0;
		int n;
		cout<<"\nEnter four digit security pin: ";
		cin>>n;
		temp=head;
		while(temp!=NULL)
		{
				if(n==0000)
				{
				//	cout<<"\n\nMobile No. : "<<temp->acc_mob<<endl;
					cout<<"\n\nBooked cab Are :\n"<<endl;
					cout<<"\n\nno.\t Name \tMobile No. \tSource\tDestination\tDate\t       Time   Persons   Bill \n"<<endl;
					for(i=temp->top;i>=0;i--)
					{
					
							cout<<j<<".\t"<<temp->acc_name<<"\t"<<temp->acc_mob<<"\t"<<temp->a[i]<<"\tRIT college\t"<<temp->d[i]<<"-"<<temp->m[i]<<"-"
							<<temp->y[i]<<"\t"<<temp->time[i]<<"\t   "<<temp->np[i]
							<<"\t "<<temp->bill[i]<<endl;
						     j++;
					}
					count++;
			     }
				else
				{
					count=2;	
				}  
		temp=temp->link;		
		}
		if(count==0)
		{
			cout<<"\n\n Account not found!"<<endl;
		}
		else if(count==2)
		{
			cout<<"\n\nInvalid security pin!"<<endl;
    }
		}  	
}
//void cab::del_cab()
//{
//	if(head==NULL)
//	{
//		cout<<"\n\nAccount's record is empty!";
//	}
//	else
//	{
//		int a,h,count=0;
//		cout<<"\n\nEnter account number you want to Delete: ";
//		cin>>a;
//		cout<<"\nEnter four digit security pin: ";
//		cin>>h;
//		loop=head;
//		while(loop!=NULL)
//		{
//			if(loop->acc_pin==h)
//			{
//				
//				if(a== head->acc_no)
//				{
//					temp=head;
//					head=head->link;
//					cout<<"\n\nAccount has been successfully Deleted!";
//					count++;
//					delete temp;
//				}
//				else
//				{
//					prevv=head;
//					temp=head->link;
//					while(temp!=NULL)
//					{
//						if(a==temp->acc_no)
//						{
//							prevv->link=temp->link;
//							count++;
//							cout<<"\n\nAccount has been successfully Deleted!";
//							delete temp;
//							break;
//						}
//						prevv=temp;
//						temp=temp->link;
//					}
//					if(count==0)
//					{
//						cout<<"\n\nBank Account not found!"<<endl;
//					}
//				}
//			}
//			else
//			{
//				cout<<"\n\nInvalid Security pin!"<<endl;
//			}
//			loop=loop->link;
//		}
//		
//	}
//}

void basic::admin()
{
   

	string n,p;
	x:
	cout<<"\nEnter Name:";
	cin.ignore();
	getline(cin,n);
	if(n==adminname)
	{
		cout<<"\nEnter 4 digit Security Pin :";
		cin>>p;
		if(p==password)
		{
			cout<<"Login Successfully\n Details as : ";
			details();
		}
	 else
	 {
	 	cout<<"\nIncorrect Pin";
	 }
	}
	else
	{
		cout<<"\nIncorrect Name ";
	
	}

}
int main()
{
	cab p;
	int x;
	l:
	    system("cls");
		p.menu();
		cout<<"\n\nEnter Your Choice : ";
		cin>>x;
        switch(x)
		{
		   case 1: 
		        system("cls");
				p.getdata();
				 break;	
		   case 2:
		   	    system("cls");
		        p.book(); 
				break;
		   case 3: 
		         system("cls");
		         details(); break;
	   case 4: 
		            system("cls");
	                 p.admin(); 
				      break;
		   case 5: cout<<"\n\nThankyou !";
			         exit(0);
		default:cout<<"\n\n\nEnter valid choice!"<<endl;	
	}
	getch();
		goto l;
		
}
 
