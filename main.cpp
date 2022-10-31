#include "search.cpp"
char global_username[50];
void calling_func();
void main_admin();
void employee_main();
void admin_will_decide();
void deciding_func();
void details_seperation();
void sign_up()
{
	char u_pass[20];
	int i;
	int flag=0;
	struct login l;
	struct login c;
	FILE *ln;
	FILE *lo;
	lo = fopen("login.bin","ab+");
	
	printf("\n\n\t\t\t\t\t\tSIGN UP");
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tCreate Username  :");
	gets(l.name);
	
	fflush(stdin);

	printf("\n\t\t\t\t\t\tCreate Password  :");
	for( i=0 ; ; )
	{
		u_pass[i] = getch();
		if((u_pass[i]>='a'&&u_pass[i]<='z')||(u_pass[i]>='A'&&u_pass[i]<='Z')||(u_pass[i]>='!'&&u_pass[i]<='@'))
		{
			l.passwor[i] = u_pass[i];
			++i;
			u_pass[i]='*';
			printf("%c",u_pass[i]);
		}
		if(u_pass[i] == '\b' && i>=1)
		{
		    printf("\b \b");
		    --i;
		}
		if(u_pass[i] == '\r')
		{
			l.passwor[i] = '\0';
			break;
		}
	}
    fwrite(&l, sizeof(login),1,lo);
	fclose(lo);
	//calling_func();
    admin_will_decide();
   }
void sign_up_employee()
{
	char u_pass[20];
	int i;
	int flag=0;
	struct login l;
	struct login c;
	FILE *ln;
	FILE *lo;
	lo = fopen("login_employee.bin","ab+");
	
	printf("\n\n\t\t\t\t\t\tEmployee Enrollment");
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tCreate Username(Employee id)  :");
	gets(l.name);
	
	fflush(stdin);

	printf("\n\t\t\t\t\t\tCreate Password  :");
	for( i=0 ; ; )
	{
		u_pass[i] = getch();
		if((u_pass[i]>='a'&&u_pass[i]<='z')||(u_pass[i]>='A'&&u_pass[i]<='Z')||(u_pass[i]>='!'&&u_pass[i]<='@'))
		{
			l.passwor[i] = u_pass[i];
			++i;
			u_pass[i]='*';
			printf("%c",u_pass[i]);
		}
		if(u_pass[i] == '\b' && i>=1)
		{
		    printf("\b \b");
		    --i;
		}
		if(u_pass[i] == '\r')
		{
			l.passwor[i] = '\0';
			break;
		}
	}
    fwrite(&l, sizeof(login),1,lo);
	fclose(lo);
	//calling_func();
    admin_will_decide();
   }
void sign_in()
{
	int l_times = 0;
	while(l_times<3)
	{
		int i,flag=0;
		char u_pass[20],pass[20], username[50];
	
		struct login l;
		FILE *lo;
		
		fflush(stdin);
		printf("\n\n\t\t\t\t\t\tUsername  :");
		gets(username);
		
		fflush(stdin);
		printf("\n\t\t\t\t\t\tPassword  :");
		
		for( i=0 ; ; )
		{
			u_pass[i] = getch();
			if((u_pass[i]>='a'&&u_pass[i]<='z')||(u_pass[i]>='A'&&u_pass[i]<='Z')||(u_pass[i]>='!'&&u_pass[i]<='@'))
			{
				pass[i] = u_pass[i];
				++i;
				u_pass[i]='*';
				printf("%c",u_pass[i]);
			}
			if(u_pass[i] == '\b' && i>=1)
			{
			    printf("\b \b");
			    --i;
			}
			if(u_pass[i] == '\r')
			{
				pass[i] = '\0';
				break;
			}
		}
		lo = fopen("login.bin","rb");
	
		while(fread(&l,sizeof(login),1,lo))
		{
			if(strcmp(username,l.name)==0 && strcmp(pass,l.passwor)==0)
			{
				flag = 1;
				printf("\n\n\n\t\t\t\t\t\tLog in Successful...!");
				//main_admin();
                admin_will_decide();
			}
		}
		if(flag == 0)
		{
			l_times++;
			printf("\n\n\t\t\t\t\t\tInvalid Username/Password...");
		}
   }
   printf("\n\n\t\t\t\t\t\tToo many login attempts...!\n\n\t\t\t\t\t\tTry again later...\n\n\t\t\t\t\t\tThank you...!\n\n\n");
}
void sign_in_employee()
{
    cout<<"Employee login"<<endl;
    cout<<"If you are already enrolled try to log in!!!"<<endl;
    cout<<"Else contact Admin for the enrollment!!!"<<endl;
	int l_times = 0;
	while(l_times<3)
	{
		int i,flag=0;
		char u_pass[20],pass[20], username[50];
	
		struct login l;
		FILE *lo;
		
		fflush(stdin);
		printf("\n\n\t\t\t\t\t\tEmployee id  :");
		gets(username);
		
		fflush(stdin);
		printf("\n\t\t\t\t\t\tPassword  :");
		
		for( i=0 ; ; )
		{
			u_pass[i] = getch();
			if((u_pass[i]>='a'&&u_pass[i]<='z')||(u_pass[i]>='A'&&u_pass[i]<='Z')||(u_pass[i]>='!'&&u_pass[i]<='@'))
			{
				pass[i] = u_pass[i];
				++i;
				u_pass[i]='*';
				printf("%c",u_pass[i]);
			}
			if(u_pass[i] == '\b' && i>=1)
			{
			    printf("\b \b");
			    --i;
			}
			if(u_pass[i] == '\r')
			{
				pass[i] = '\0';
				break;
			}
		}
		lo = fopen("login_employee.bin","rb");
	
		while(fread(&l,sizeof(login),1,lo))
		{
			if(strcmp(username,l.name)==0 && strcmp(pass,l.passwor)==0)
			{
				flag = 1;
				printf("\n\n\n\t\t\t\t\t\tLog in Successful...!");
                strcpy(global_username,username);
				employee_main();
			}
		}
		if(flag == 0)
		{
			l_times++;
			printf("\n\n\t\t\t\t\t\tInvalid Username/Password...");
		}
   }
   printf("\n\n\t\t\t\t\t\tToo many login attempts...!\n\n\t\t\t\t\t\tTry again later...\n\n\t\t\t\t\t\tThank you...!\n\n\n");
}
void admin_will_decide()
{
    int choice=0;
    while(true)
    {
    cout<<"Press 1-To deal with Employee database"<<endl;
    cout<<"Press 2-Employee enrollment"<<endl;
    cout<<"Press 3-To back"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
            {
                main_admin();
                break;
            }
        case 2:
            {
                sign_up_employee();
                break;
            }
        case 3:
            {
                deciding_func();
                break;
            }
    }
    }
}
void front_output()
{
        cout<<"Welcome to  YSR Group of Companies"<<endl;
        cout<<"Press 1-Admin"<<endl;
        cout<<"Press 2-Employee"<<endl;
        cout<<"Press 3-Exit"<<endl;
        cout<<"Enter your choice:"<<endl;
}
void loadingBar()
{
    char a = 177, b = 219;
    printf("\n\n\t\t\t\t\t\t\t\tLoading...\n\n");
    printf("\t\t\t\t\t");
        
    printf("\r");
    printf("\t\t\t\t\t\t\t\t");
    for (int i = 0; i < 15; i++) 
	{
        printf("%c", b);
        Sleep(100);
    }
    cout<<endl;
}
void main_admin()
{
    struct heap_salary s1;
    tree t;
    t.read_file_main();
    t.create_heap();
    int choice=0;
    while(true)
    {
        t.output();
        cin>>choice;
        switch(choice)
        {
            case 1:
                {                    
                t.create();
                n=0;
                t.create_heap();
                break;
                }
            case 2:
                t.insert1();
                n=0;
                t.create_heap();
                break;
            case 3:
                 t.display();
                 break;
            case 4:
                t.displayheap();
                break;
            case 5:
                t.search1();
                break;
            case 6:
                t.modify();
                n=0;
                t.create_heap();
                break;
            case 7:
                t.delete1();
                break;
            case 8:
                t.redo();
                break;
            case 9:
                {
                    t.calc_hash_size();
                    break;
                }
            case 10:
                t.write_file_main();
                admin_will_decide();
                break;
            default:
                cout<<"It is an invalid choice"<<endl;
        }
    }
}
void employee_main()
{
    struct heap_salary s1;
    tree t;
    t.read_file_main();
    int choice=0;
    while(true)
    {
    cout<<"\nPress 1-To view details"<<endl;
    cout<<"Press 2-To back"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
            //t.search1();
            details_seperation();
            break;
        }
        case 2:
        {
            calling_func();
            break;
        }
        default:
            cout<<"Invalid choice"<<endl;
    }
    }
}
void deciding_func()
{
    int choice=0;
    while(true)
    {
        cout<<"Press 1-To Register"<<endl;
        cout<<"Press 2-To Login"<<endl;
        cout<<"Press 3-To back"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                sign_up();
                break;
            }
            case 2:
            {
                sign_in();
                break;
            }
            case 3:
            {
                calling_func();
                break;
            }
        }
    }
}
void calling_func()
{
    int choice=0;
    while(true)
    {
        front_output();
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                loadingBar();
                //main_admin();
                deciding_func();
            break;
            }
            case 2:
            {
                loadingBar();
                //employee_main();
                sign_in_employee();
            break;
            }            
            case 3:
            {
                exit(0);
                break;
            }
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}
void details_seperation()
{
    tree t;
    t.read_file_main();
    struct employee e1;
    strcpy(e1.emp_id,global_username);
    struct node* temp=t.search(e1);
        if(temp!=NULL)
            {
                //cout<<"The element exists"<<endl;
                cout<<"Employee Id:"<<temp->e.emp_id<<endl;
                cout<<"Employee Name:"<<temp->e.emp_name<<endl;
                cout<<"Employee Department:"<<temp->e.department<<endl;
                cout<<"Employee Salary:"<<temp->e.salary<<endl;
                cout<<"Employee Date of Birth:"<<temp->e.dob.date<<"\\"<<temp->e.dob.month<<"\\"<<temp->e.dob.year<<endl;
                cout<<"Employee Adhaar Number:"<<temp->e.adhaar<<endl;
                cout<<"Employee Address"<<temp->e.address<<endl;
                temp->e.p.pay_display();
            }
            else
            {
                cout<<"The element doesn't exist"<<endl;
            }
}
int main()
{
    calling_func();
    return 0;
}