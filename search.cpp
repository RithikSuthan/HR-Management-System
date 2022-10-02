#include "source.cpp"
struct node * tree::search(struct employee e1)
{
    struct node *temp=root;
    while(temp!=NULL)
    {
        if(strcmp(temp->e.emp_id,e1.emp_id)>0)
        {
            //cout<<"left"<<endl;
            if(temp->left==NULL)
            {
                break;
            }
            else
            {
                temp=temp->left;
            }
        }
        else if(strcmp(temp->e.emp_id,e1.emp_id)==0)
        {
            //cout<<"Element found"<<endl;
            return temp;
            break;
        }
        else if(strcmp(temp->e.emp_id,e1.emp_id)<0)
        {
            //cout<<"right"<<endl;
            if(temp->right==NULL)
            {
                break;
            }
            else
            {
                temp=temp->right;
            }            
        }
    }
    return NULL;
}
void tree::swapValues(struct node *u,struct  node *v)
{
    struct employee temp;
    temp=u->e;
    u->e=v->e;
    v->e=temp;
}
hash1 tree::search1_recursive(struct node *root)
{
    hash1 h2;
    if (root == NULL)
        return h2;
    search1_recursive(root->left);
    h2.hash_insert1(root->e);
    search1_recursive(root->right);
    return h2;
}
void tree::search1()
{
    struct employee e;
    cout<<"Enter the employee roll number"<<endl;
    cin>>e.emp_id;
    hash1 h;
    db=(hash1 *)malloc(max_size * sizeof(hash1));
    h.init();
    h=search1_recursive(root);
    h.display(e);
    if (hash_search_flag!=0)
        {
            cout<<"\nElement found"<<endl;
            hash_search_flag=0;
        }
        else
        {
            cout<<"\ntElement doesn't exist"<<endl;
        }
    h.delete1();
    hash_size=0;
}
void tree::modify_display()
{
        cout<<"Press 0-No changes required"<<endl;
        cout<<"Press 1-To change the employee Id"<<endl;
        cout<<"Press 2-To change the employee name"<<endl;
        cout<<"Press 3-To change the employee department"<<endl;
        cout<<"Press 4-To change the employee salary"<<endl;
        cout<<"Press 5-To change the employee date of birth"<<endl;
        cout<<"Press 6-To change the employee phone number"<<endl;
        cout<<"Press 7-To change the employee Adhaar number"<<endl;
        cout<<"Press 8-To change the employee address"<<endl;
	    cout<<"Press 9-To change H.R. ALLOWANCE"<<endl;
        cout<<"Press 10-To change CONVEYANCE ALLOWANCE"<<endl;
        cout<<"Press 11-To change SPECIAL ALLOWANCES"<<endl;
	    cout<<"Press 12-To change AMT. OF INCREMENT"<<endl;
	    cout<<"Press 13-To change MEDICAL INSURANCE"<<endl;
        cout<<"Press 14-To change the whole record"<<endl;
        cout<<"Enter your choice"<<endl;
}
void tree::modify()
{
    struct employee e;
    cout<<"Enter the employee roll number"<<endl;
    cin>>e.emp_id;
    struct node* temp=search(e);
    if(temp!=NULL)
    {
        cout<<"The element exists"<<endl;
        cout<<"Employee Id:"<<temp->e.emp_id<<endl;
        cout<<"Employee Name:"<<temp->e.emp_name<<endl;
        cout<<"Employee Department:"<<temp->e.department<<endl;
        cout<<"Employee Salary:"<<temp->e.salary<<endl;
        cout<<"Employee Date of Birth:"<<temp->e.dob.date<<"\\"<<temp->e.dob.month<<"\\"<<temp->e.dob.year<<endl;
        cout<<"Employee Phone Number:"<<temp->e.phone<<endl;
        cout<<"Employee Adhaar Number:"<<temp->e.adhaar<<endl;
        cout<<"Employee Address"<<temp->e.address<<endl;  
        temp->e.p.pay_display();   
        int choice=0;
        modify_display();
        cin>>choice;
         fflush(stdin);     
        switch (choice)
        {
            case 0:
                return;
                break;
            case 1:
                {
                cout<<"Enter the employee id"<<endl;
                cin.getline(temp->e.emp_id,10);
                fflush(stdin);                    
                break;
                }
            case 2:
            {
            cout<<"Enter the employee name"<<endl;
            cin.getline(temp->e.emp_name,30);
            fflush(stdin);  
            break;              
            }    
            case 3:
             {      
                 cout<<"Enter the department name"<<endl;
                    cin.getline(temp->e.department,30);
                    fflush(stdin);   
                    break;
            }
            case 4:
            {
                    cout<<"Enter the salary of the employee"<<endl;
                    cin>>temp->e.salary;
                    temp->e.p.basic=temp->e.salary;
                    temp->e.p.GrossSalary();
                    temp->e.p.TaxCalc();
                    temp->e.p.prof_tax();
                    temp->e.p.EpfCalc();
                    temp->e.p.TakeHomeSalary();
                    fflush(stdin);
                    break;
            }
            case 5:
            {
                    cout<<"Employee date of birth"<<endl;
                    cout<<"Enter the date"<<endl;
                    cin>>temp->e.dob.date;
                    fflush(stdin);
                    cout<<"Enter the month"<<endl;
                    cin>>temp->e.dob.month;
                    fflush(stdin);
                    cout<<"Enter the year"<<endl;
                    cin>>temp->e.dob.year;
                    fflush(stdin);
                break;
            }
            case 6:
            {
                fflush(stdin);
                cout<<"Enter the employee phone number:"<<endl;
                cin.getline(temp->e.phone,11);
                fflush(stdin);
                break;
            } 
            case 7:
            {
                    fflush(stdin);
                    cout<<"Enter the Adhaar number"<<endl;
                    cin>>temp->e.adhaar;
                    fflush(stdin);        
                    break;        
            }           
            case 8:
            {
                cout<<"Enter the employee address:"<<endl;
                cin.getline(temp->e.address,40);
                break;
            }
            case 9:
            {
	            cout<<"\n\nENTER H.R. ALLOWANCE      : ";
                cin>>temp->e.p.hr_all;
                    temp->e.p.GrossSalary();
                    temp->e.p.TaxCalc();
                    temp->e.p.prof_tax();
                    temp->e.p.EpfCalc();
                    temp->e.p.TakeHomeSalary();
                break;
            }
            case 10:
            {
                cout<<"\n\nENTER CONVEYANCE ALLOWANCE: ";
                cin>>temp->e.p.con_all;
                    temp->e.p.GrossSalary();
                    temp->e.p.TaxCalc();
                    temp->e.p.prof_tax();
                    temp->e.p.EpfCalc();
                    temp->e.p.TakeHomeSalary();
                break;
            }
            case 11:
            {
                cout<<"\n\nENTER SPECIAL ALLOWANCES  : ";
	            cin>>temp->e.p.other_all;
                    temp->e.p.GrossSalary();
                    temp->e.p.TaxCalc();
                    temp->e.p.prof_tax();
                    temp->e.p.EpfCalc();
                    temp->e.p.TakeHomeSalary();
                break;
            }
            case 12:
            {
	            cout<<"\n\nENTER AMT. OF INCREMENT   : ";
	            cin>>temp->e.p.increment;
                    temp->e.p.GrossSalary();
                    temp->e.p.TaxCalc();
                    temp->e.p.prof_tax();
                    temp->e.p.EpfCalc();
                    temp->e.p.TakeHomeSalary();
                break;
            }
            case 13:
            {
	            cout<<"\n\nENTER MEDICAL INSURANCE   : ";
	            cin>>temp->e.p.medi_insur;
                    temp->e.p.GrossSalary();
                    temp->e.p.TaxCalc();
                    temp->e.p.prof_tax();
                    temp->e.p.EpfCalc();
                    temp->e.p.TakeHomeSalary();
                break;
            }
            case 14:
            {
            cout<<"Enter the employee id"<<endl;
            cin.getline(temp->e.emp_id,10);
            fflush(stdin);
            cout<<"Enter the employee name"<<endl;
            cin.getline(temp->e.emp_name,30);
            fflush(stdin);
            cout<<"Enter the department name"<<endl;
            cin.getline(temp->e.department,30);
            fflush(stdin);
            cout<<"Enter the salary of the employee"<<endl;
            cin>>temp->e.salary;
            temp->e.p.basic=temp->e.salary;
            fflush(stdin);
            cout<<"Employee date of birth"<<endl;
            cout<<"Enter the date"<<endl;
            cin>>temp->e.dob.date;
            fflush(stdin);
            cout<<"Enter the month"<<endl;
            cin>>temp->e.dob.month;
            fflush(stdin);
            cout<<"Enter the year"<<endl;
            cin>>temp->e.dob.year;
            fflush(stdin);
            cout<<"Enter the emplyee phone number"<<endl;
            cin.getline(temp->e.phone,11);
            fflush(stdin);
            temp->e.p.basic=e.salary;
            cout<<"Enter the employee Adhaar number"<<endl;
            cin>>temp->e.adhaar;
            fflush(stdin);
            cout<<"Enter the employee address:"<<endl;
            cin.getline(temp->e.address,40);
	        cout<<"\n\nENTER H.R. ALLOWANCE      : ";
            cin>>temp->e.p.hr_all;
            cout<<"\n\nENTER CONVEYANCE ALLOWANCE: ";
            cin>>temp->e.p.con_all;
            cout<<"\n\nENTER SPECIAL ALLOWANCES  : ";
	        cin>>temp->e.p.other_all;
	        cout<<"\n\nENTER AMT. OF INCREMENT   : ";
	        cin>>temp->e.p.increment;
	        cout<<"\n\nENTER MEDICAL INSURANCE   : ";
	        cin>>temp->e.p.medi_insur;         
            temp->e.p.GrossSalary();
            temp->e.p.TaxCalc();
            temp->e.p.prof_tax();
            temp->e.p.EpfCalc();
            temp->e.p.TakeHomeSalary();           
            }            
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    }
    else
    {
        cout<<"The elemnt doesn't exist"<<endl;
    }   
    cout<<"The record is been successfully verified"<<endl; 
}
struct node *node::sibling()
{
    if(parent==NULL)
    {
        return NULL;
    }
    if(isOnLeft())
    {
        return parent->right;
    }
    else
    {
        return parent->left;
    }
}
bool node::hasRedChild()
{
	return (left != NULL && left->colour ==red)||(right != NULL && right->colour == red);
}
void tree::fixDoubleBlack(struct node *x) 
{
	if (x == root)
	return;
	struct node *sibling = x->sibling(),*parent = x->parent;
	if (sibling == NULL) 
    {
	    fixDoubleBlack(parent);
	} 
    else
    {
        if (sibling->colour == red)
        {
            parent->colour = red;
            sibling->colour =black;
            if (sibling->isOnLeft()) 
            {
                rotate_right(parent);
            } 
            else 
            {
                rotate_left(parent);
            }
            fixDoubleBlack(x);
        } 
        else 
        {
            if (sibling->hasRedChild())
            {
                if (sibling->left != NULL and sibling->left->colour ==red) 
                {
                    if (sibling->isOnLeft()) 
                    {
                        sibling->left->colour = sibling->colour;
                        sibling->colour = parent->colour;
                        rotate_right(parent);
                    } 
                    else 
                    {
                        sibling->left->colour = parent->colour;
                        rotate_right(sibling);
                        rotate_left(parent);
                    }
                } 
                else 
                {
                    if (sibling->isOnLeft()) 
                    {
                        sibling->right->colour = parent->colour;
                        rotate_left(sibling);
                        rotate_right(parent);
                    } 
                    else 
                    {
                        sibling->right->colour = sibling->colour;
                        sibling->colour = parent->colour;
                        rotate_left(parent);
                    }
		        }
		parent->colour = black;
		} 
        else 
        {
            sibling->colour =red;
            if (parent->colour ==black)
                fixDoubleBlack(parent);
            else
                parent->colour=black;
            }
    	}
	}
}
struct node *tree::succesor(struct node *x)
{
    struct node *ptr=x;
    struct node *temp;
    while(ptr!=NULL)
    {
        temp=ptr;
        ptr=ptr->left;
    }
    return temp;
}
struct  node * tree::replacing_node(struct node *ptr)
{
    if(ptr->left!=NULL && ptr->right!=NULL)//internal
    {
        return succesor(ptr->right);
    }
    if (ptr->left==NULL && ptr->right==NULL)//leaf
    {
        return NULL;
    }
    if((ptr->left!=NULL))//leaf like
    {
        return ptr->left;
    }
    else
    {
        return ptr->right;
    }
    //return NULL;
}
void tree::delete_val_node(struct node *ptr)
{
    struct node *u=replacing_node(ptr);
    bool dbblack=((u==NULL || u->colour==black) && (ptr->colour==black));
    struct node *parent=ptr->parent;
    if (u == NULL) 
    {
        if (ptr == root)
        {
            cout<<"The element is root"<<endl;
            root = NULL;
        }
        else 
        {
            if (dbblack) 
            {
                fixDoubleBlack(ptr);
            } 
            else 
            {
                if (ptr->sibling() != NULL)
                    ptr->sibling()->colour = red;
            }
            if (ptr->isOnLeft()) 
            {
            parent->left = NULL;
            } 
            else 
            {
            parent->right = NULL;
            }
	}
	delete ptr;
	return;
	}
	if (ptr->left == NULL || ptr->right == NULL) 
    {
	if(ptr == root) 
    {
		ptr->e= u->e;
		ptr->left = ptr->right = NULL;
		delete u;
	} 
    else
    {
		if(ptr->isOnLeft()) 
        {
		    parent->left = u;
		} 
        else 
        {
		    parent->right = u;
		}
		delete ptr;
		u->parent = parent;
		if (dbblack)
        {
		fixDoubleBlack(u);
		} else 
        {
		u->colour=black;
		}
	}
	return;
	}
	swapValues(u,ptr);
	delete_val_node(u);
}
struct employee point[25];
int Top=-1;

void tree::push(struct employee pt)
{
    if(Top==24)
    {
        printf("Overflow\n");
    }
    else
    {
        Top++;
        point[Top]=pt;
        cout<<pt.emp_id<<endl;
    }
    return;
}
struct employee tree::pop()
{
    //cout<<point[Top].address<<endl;
    return point[Top--];
}
void tree::redo()
{
    if(Top==-1)
	{
		printf("Underflow\n");
	}
	else
    {
	struct employee temp=pop();
    struct node *dummy=new node(temp);
	root=insert1_tree(root,dummy);
    insertheap(temp,n);
    n=n+1;
    cout<<"Redo successfully"<<endl;
    }
}
void tree::delete_val(struct employee e)
{
    struct node *ptr=search(e);
    if(ptr==NULL)
    {
        cout<<"No such element exists in the tree"<<endl;
        return;
    }
    if(strcmp(e.emp_id,ptr->e.emp_id)!=0)
    {
       // cout<<"No such element exists in the tree"<<endl;
        return;
    }
    else
    {
        push(ptr->e);
        delete_val_node(ptr);
        cout<<"Element is been deleted"<<endl;
    }
}
void tree::delete1()
{
    struct employee e;
    fflush(stdin);
    cout<<"Enter the employee id"<<endl;
    cin.getline(e.emp_id,10);
    fflush(stdin);    
    if(root==NULL)
    {
        cout<<"The tree is empty"<<endl;
        return;
    }
    else
    {
        delete_val(e);
        del_heap(e);
    }
}
void tree::del_heap(struct employee e)
    {
        int left, right, i,par;
        struct employee temp;
        for (i = 0; i < n; i++)
        {
            if (strcmp(e.emp_id,sal[i].e.emp_id)==0){
                e = sal[i].e;
                break;
            }
        }
        if (strcmp(e.emp_id,sal[i].e.emp_id)!=0)
        {
            printf("%s not found in heap\n",e.emp_id);
            return;
        }
        sal[i] = sal[n - 1];
        n = n - 1;
        par = (i - 1) / 2;
        if (strcmp(sal[i].e.emp_id,sal[par].e.emp_id)>0)
        {
            insertheap(sal[i].e, i);
            return;
        }
        left = 2 * i + 1;
        right = 2 * i + 2;
        while (right < n)
        {
            if (strcmp(sal[i].e.emp_id,sal[left].e.emp_id)>=0 && strcmp(sal[i].e.emp_id,sal[right].e.emp_id)>=0)
                return;
            if ((sal[right].e.emp_id,sal[left].e.emp_id)<=0)
            {
                temp = sal[i].e;
                sal[i].e = sal[left].e;
                sal[left].e = temp;
                i = left;
            }
            else
            {
                temp = sal[i].e;
                sal[i].e = sal[right].e;
                sal[right].e = temp;
                i = right;
            }
            left = 2 * i + 1;
            right = 2 * i + 2;
        }
        if (left == n - 1 && strcmp(sal[i].e.emp_id,sal[left].e.emp_id)<0)
        {
            temp = sal[i].e;
            sal[i].e = sal[left].e;
            sal[left].e = temp;
        }
    }