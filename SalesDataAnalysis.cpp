// Sales Data Analysis System: Manages admin and salesperson data including login, records, and sales tracking.

#include <iostream>
#include <string>
using namespace std;
struct UserInfo{
    int id;
    string firstname;
    string lastname;
    string password;
};
struct Admin{
    UserInfo userinfo;
};

struct SalesPerson {
    UserInfo userinfo;
    double salesByQtr[4];
    double totalSale;
};
void displaySingleSalesPerson(const SalesPerson& salesperson);
void salesPersonMenu(SalesPerson& salesperson);
void addSalesPerson(SalesPerson salesman[], int& noOfSalesPeople);
int displayMainMenu();
void displayAdminMenu();
void changePassword(UserInfo& adminInfo,int &noOfAdmin);
void displayRecord(const SalesPerson salesman[], int noOfSalesPeople);
void initializeSalespeople(SalesPerson salesman[]);

int main(){
    cout<<"Welcome to Sales Management System!"<<endl;
    Admin adminInfo;
    adminInfo.userinfo.password="admin";
    SalesPerson salesman[5];
    int noOfSalesPeople=0;
    int noOfAdmin=0;
    initializeSalespeople(salesman); 
    while (true)
    {
        int userchoice = displayMainMenu();
        if (userchoice==1)
        {
            string pass;
            cout<<endl<<"Enter Password: ";
                cin>>pass;
            if(pass==adminInfo.userinfo.password){
                if (noOfAdmin==0){changePassword(adminInfo.userinfo,noOfAdmin);}
                    while (true)
                    {
                        int ans;
                         displayAdminMenu();
                         cin>>ans;
                         if (ans==1)
                         {
                            displayRecord(salesman,noOfSalesPeople);
                         }
                         else if (ans==2)
                         {
                            int id;
                            bool ans=false;
                            cout<<endl<<"Enter ID: ";
                            cin>>id;
                            for (int i = 0; i < noOfSalesPeople; i++)
                            {
                                if (id==salesman[i].userinfo.id)
                                {
                                    displaySingleSalesPerson(salesman[i]);
                                    ans=true;
                                    break;
                                }
                            }
                            if (ans==false)
                            {
                                cout<<endl<<"ID not found !"<<endl;
                            } 
                         }
                         else if (ans==3)
                         {
                            addSalesPerson(salesman,noOfSalesPeople);
                         }
                         else if (ans==4)
                         {
                            break;
                         }
                    }
            }  
            else{
                    cout<<endl<<"Invalid Password !"<<endl;
                }
        }
        else if (userchoice==2)
        {
            if (noOfSalesPeople==0)
            {
                cout<<endl<<"No Sale's person register yet !"<<endl;
            }
            else{
                bool ans=false;
                 int id;
                 string pass;
                 cout<<endl<<"Enter ID: ";
                 cin>>id;
                 cout<<endl<<"Enter Password: ";
                 cin>>pass;
                 for (int i = 0; i < noOfSalesPeople; i++)
                 {
                    if (id==salesman[i].userinfo.id)
                    {
                        id=i;
                        ans=true;
                        break;
                    } 
                 }
                 if (ans==true)
                 {
                    if (pass=="saleperson123"&&salesman[id].userinfo.password==pass)
                    {
                        cout<<endl<<"Enter New Password: ";
                        cin>>pass;
                        salesman[id].userinfo.password=pass;
                        cout<<endl<<"Successfully Login !"<<endl;
                        salesPersonMenu(salesman[id]);
                    }
                    else if (pass==salesman[id].userinfo.password)
                    {
                        cout<<endl<<"Successfully Login !"<<endl;
                        salesPersonMenu(salesman[id]);
                    }
                    else{
                        cout<<endl<<"Invalid Password !";
                    }
                 }
                 else{
                    cout<<endl<<"Invalid ID"<<endl;
                 }
            }
        }
        else if (userchoice==0)
        {
            break;
        }
        else{
            cout<<endl<<"Invalid Inpuut !"<<endl;
        } 
    }
}
int displayMainMenu() {
    cout << "Main Menu:" << endl;
    cout << "Press 1 for Admin Menu" << endl;
    cout << "Press 2 for Salesperson Menu" << endl;
    cout << "Press 0 to exit" << endl;

    int choice;
    cout << "Your choice: ";
    cin >> choice;

    return choice;
}

void changePassword(UserInfo& adminInfo,int &noOfAdmin) {
    cout <<endl<< "Enter new password: ";
    cin >> adminInfo.password;
    cout<<endl<<"Enter ID: ";
    cin>>adminInfo.id;
    cout<<endl<<"Enter First Name: ";
    cin>>adminInfo.firstname;
    cout<<endl<<"Enter Last Name: ";
    cin>>adminInfo.lastname;
    noOfAdmin=noOfAdmin+1;
    cout<<endl<<"Admin Successfully Registered !"<<endl;
}

void displayRecord(const SalesPerson salesman[],int noOfSalesPeople) {
    cout << "Annual Sales Report:" << endl;
    cout << "ID      | First Name |   Last Name |  Password |Total Sale|   Sales by Quarter" << endl;

    for (int i = 0; i < 5; i++) {
        cout << salesman[i].userinfo.id << "    |   "
             << salesman[i].userinfo.firstname << "    |   "
             << salesman[i].userinfo.lastname << "    |   "
             << salesman[i].userinfo.password << "    |   "
             << salesman[i].totalSale << "      |  ";

        for (int j = 0; j < 4; j++) {
            cout << salesman[i].salesByQtr[j];
            if (j < 3) {
                cout << " ";
            }
        }

        cout << endl;
    }
    if (noOfSalesPeople>0)
	{
		double maximumSales=0;
		int id=0;
		double quarterSale=0;
		double quarterSale2=0;
		int qtNum=0;
		for (int i = 0; i < noOfSalesPeople; i++)
		{
			if (salesman[i].totalSale>maximumSales)
			{
				maximumSales=salesman[i].totalSale;
				id=i;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int k = 0; k < noOfSalesPeople; k++)
			{
				quarterSale=quarterSale+salesman[k].salesByQtr[i];
			}
			if (quarterSale>quarterSale2)
			{
				quarterSale2=quarterSale;
				qtNum=i+1;
			}
			quarterSale=0;
		}
		cout<<endl<<endl<<"Max Sale by SalesPerson: ID = "<<salesman[id].userinfo.id<<", Amount = $"<<maximumSales;
		cout<<endl<<"Max Sale by Quarter: Quarter = "<<qtNum<<", Amount = $"<<quarterSale2<<endl;	
	}
}

void displayAdminMenu() {
    cout << "\nAdmin Menu:" << endl;
    cout << "1. Display Complete Sales Record" << endl;
    cout << "2. Display Single SalesPerson Record" << endl;
    cout << "3. Add/Enroll SalesPerson" << endl;
    cout << "4. Logout" << endl;
}

void initializeSalespeople(SalesPerson salesman[]) {
    salesman[0].userinfo = {0, " ", " ", "saleperson123"};
    salesman[1].userinfo = {0, " ", " ", "saleperson123"};
    salesman[2].userinfo = {0, " ", " ", "saleperson123"};
    salesman[3].userinfo = {0, " ", " ", "saleperson123"};
    salesman[4].userinfo = {0, " ", " ", "saleperson123"};

    // Initialize sales data (you can set your values)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            salesman[i].salesByQtr[j] = 0.0;
        }
        salesman[i].totalSale = 0.0;
    }
}
// Define the displaySingleSalesPerson function
void displaySingleSalesPerson(const SalesPerson& salesperson) {
    cout << "Single Salesperson Record:" << endl;
    cout << "ID: " << salesperson.userinfo.id << endl;
    cout << "First Name: " << salesperson.userinfo.firstname << endl;
    cout << "Last Name: " << salesperson.userinfo.lastname << endl;
    cout << "Password: " << salesperson.userinfo.password << endl;
    cout << "Total Sale: " << salesperson.totalSale << endl;
    cout << "Sales by Quarter: ";
    for (int i = 0; i < 4; i++) {
        cout << salesperson.salesByQtr[i];
        if (i < 3) {
            cout << " ";
        }
    }
    cout << endl;
}
void addSalesPerson(SalesPerson salesman[], int& noOfSalesPeople) {
    if (noOfSalesPeople==5)
    {
        cout<<endl<<"Can not add more sales person !"<<endl;
        return;
    }
    SalesPerson newSalesperson;
    cout << "Enter Salesperson Details:" << endl;
    cout << "ID: ";
    cin >> newSalesperson.userinfo.id;
    cout << "First Name: ";
    cin >> newSalesperson.userinfo.firstname;
    cout << "Last Name: ";
    cin >> newSalesperson.userinfo.lastname;
    newSalesperson.userinfo.password=salesman[noOfSalesPeople].userinfo.password;
    newSalesperson.totalSale = 0.0; 
    for (int i = 0; i < 4; i++) {
        newSalesperson.salesByQtr[i] = 0.0; 
    } salesman[noOfSalesPeople] = newSalesperson;
    noOfSalesPeople++;
    cout << "Salesperson added successfully!" << endl;
}
void salesPersonMenu(SalesPerson& salesperson){
    int choice;
    while (true)
    {
        cout<<endl<<"Name: "<<salesperson.userinfo.firstname<<" "<<salesperson.userinfo.lastname<<endl;
					cout<<"ID: "<<salesperson.userinfo.id<<endl<<endl;
					cout<<endl<<"Press 1 for Update by Quarter"<<endl;
					cout<<"Press 2 for View Record's"<<endl;
					cout<<"Press 0 for Logout"<<endl;
					cout<<"Enter Choice: ";
					cin>>choice;
					if (choice==1)
					{double total=0;
					   for (int k = 0; k < 4; k++)
					   {cout<<endl<<"Enter Quarter "<<k+1<<": ";
						cin>>salesperson.salesByQtr[k];
						total=total+salesperson.salesByQtr[k];}
					   salesperson.totalSale=total;}
					else if (choice==2)
					{
						displaySingleSalesPerson(salesperson);
    }
    else if (choice==0)
    {
        break;
    }
    else{
        cout<<endl<<"Invalid Input !"<<endl;
    } 
}
}