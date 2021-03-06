#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include <windows.h>

using namespace std;

void  window01();
void cregister();
void login();
void Aboutus();
void menu();

namespace inputData
{
     int inputnum01;
    int inputnum02;
    string inputnum03;
    float inputnum04;
    string username1;
    string userpassword1;
}

class Node {
public:
	int batchnumber;
	string productname;
	string pqty;
	int productprice;
	Node* next;
};

Node* head = new Node();

bool check(int x)
{

	if (head == NULL)
		return false;

	Node* t = new Node;
	t = head;


	while (t != NULL) {
		if (t->batchnumber == x)
			return true;
		t = t->next;
	}

	return false;
}

// insert the record
void Insert_Record(int batchnumber, string productname,
				string pqty, int productprice)
{
	if (check(batchnumber)) {
		cout << "\n\n\t\t\t\t\tStudent with this "
			<< "record Already Exists\n";
		return;
	}

	Node* t = new Node();
	t->batchnumber = batchnumber;
	t->productname = productname;
	t->pqty = pqty;
	t->productprice = productprice;
	t->next = NULL;


	if (head == NULL
		|| (head->batchnumber >= t->batchnumber)) {
		t->next = head;
		head = t;
	}

	else {
		Node* c = head;
		while (c->next != NULL
			&& c->next->batchnumber < t->batchnumber) {
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
	}
        //** product details add file
	     ofstream productDetails;
         productDetails.open("productDetails.txt", ios::app);
         productDetails<<batchnumber<<" "<<productname<<" "<<pqty<<" "<<productprice<<endl;
         productDetails.close();

	cout << "\n\n\t\t\t\t\tRecord Inserted Successfully || ";

    system("pause");
}


void Search_Record(int batchnumber)
{

	if (!head) {
		cout << "\n\n\t\t\t\t\tNo such Record Available\n";
		return;
	}


	else {
		Node* p = head;
		while (p) {
			if (p->batchnumber == batchnumber) {
				cout << "\n\n\t\t\t\t\tProduct Batch Number : \t"
					<< p->batchnumber << endl;
				cout << "\n\n\t\t\t\t\tProduct Name :\t\t"
					<< p->productname << endl;
				cout << "\n\n\t\t\t\t\tProduct Quntity :\t"
					<< p->pqty << endl;
				cout << "\n\n\t\t\t\t\tPrice of a Product :\t"
					<< p->productprice << endl;
					cout<<"\n\n\t\t\t\t\t..........";
                system("pause");
				return;

			}
			p = p->next;
		}

		if (p == NULL)
			cout << "\n\n\t\t\t\t\tNo such Record Available ";
			system("pause");
	}
}

int Delete_Record(int batchnumber)
{
	Node* t = head;
	Node* p = NULL;


	if (t != NULL
		&& t->batchnumber == batchnumber) {
		head = t->next;
		delete t;

		cout << "\n\n\t\t\t\t\tRecord Deleted Successfully";
		system("pause");
		return 0;
	}


	while (t != NULL && t->batchnumber != batchnumber) {
		p = t;
		t = t->next;
	}
	if (t == NULL) {
		cout << "\n\n\t\t\t\t\tRecord does not Exist\n";
		return -1;
		p->next = t->next;

		delete t;
		cout << "\n\n\t\t\t\t\tRecord Deleted Successfully";
		system("pause");

		return 0;
	}
}


void Show_Record()
{
	Node* p = head;
	if (p == NULL) {
		cout << "\n\n\t\t\t\t\tNo Record Available :: ";
		system("pause");
	}
	else {
        system("cls");
        cout<<"\n\n\t\t\t\t\t NILWALA Coparation Inventory Management System  \n"<<endl;
        cout<<"\n\n All products --------------- \n"<<endl;
		cout << "Pnumber\tPname\tPqty"
			<< "\tPrice\n";


		while (p != NULL) {
			cout << p->batchnumber << " \t"
				<< p->productname << "\t"
				<< p->pqty << "\t"
				<< p->productprice << endl;
			p = p->next;
         }
          cout<<"\n\n\n Exit -> ";
         system("pause");
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// use linked list
void menu(){


    head = NULL;
	string Pname, Pqty;
	int PBnumber, Pprice;

	while (true) {
    system("cls");
    cout<<"\n\n\t\t\t\t\t NILWALA Coparation Inventory Management System  \n"<<endl;
    cout<<"\n\t\t\t\t\t> Add a new Product Record : 01\n";
    cout<<"\n\t\t\t\t\t> delete a Product record :02\n";
    cout<<"\n\t\t\t\t\t> Search a Products : 03\n";
    cout<<"\n\t\t\t\t\t>View all Products : 04\n";

     cout<<" \n\n\t\t\t\t\t Enter your choice : ";




		int Choice;
		cin >> Choice;
		if (Choice == 1) {
            system("cls");
             cout<<"\n\n\t\t\t\t\t NILWALA Coparation Inventory Management System  \n"<<endl;
			cout << "\n\n\n\t\t\t\t\t>Enter Name of Product name : ";
			cin >> Pname;
			cout << "\n\t\t\t\t\t>Enter Batch Number of Product : ";
			cin >> PBnumber;
			cout << "\n\t\t\t\t\t>Enter Product quantity : ";
			cin >> Pqty;
			cout << "\n\t\t\t\t\t>Enter Price of product : ";
			cin >> Pprice;
			Insert_Record(PBnumber, Pname, Pqty, Pprice);
            system("cls");
		}
		else if (Choice == 2) {
		      system("cls");
		       cout<<"\n\n\t\t\t\t\t NILWALA Coparation Inventory Management System  \n"<<endl;
			cout << "\n\n\n\t\t\t\t\t> Enter Batch Number of a Product "
					"record is to be deleted : ";
			cin >> PBnumber;
			Delete_Record(PBnumber);
		}
		else if (Choice == 3) {

             system("cls");
		       cout<<"\n\n\t\t\t\t\t NILWALA Coparation Inventory Management System  \n"<<endl;
			cout << "\n\n\n\t\t\t\t\t>Enter Batch Number of a Product "
					"record you want to Search : ";
			cin >> PBnumber;
			Search_Record(PBnumber);
		}
		else if (Choice == 4) {
			Show_Record();
		}
		else if (Choice == 5) {
			exit(0);
		}
		else {
			cout << "\n\n\n\t\t\t\t\tInvalid Choice "
				<< "\n\n\n\t\t\t\t\tTry Again\n";
		}
	}



}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Admin
{
private:
    string Username;
    string Userpassword;
    string NICnumber;
    int telephoneNum;
    string Homeaddress;
    string age;
public:

     void openAccount(string Username,string Userpassword)
     {
         this->Username=Username;
         this->Userpassword=Userpassword;

         ofstream registerDataFile;
         registerDataFile.open("registerDataFile.txt", ios::app);
         registerDataFile<<Username<<" "<<Userpassword<<endl;
         registerDataFile.close();

         using namespace inputData;
         cout<<"\n\n\n\t\t\t\t\t> Go to next add other biodata ->  press 01: ";
         cout<<"\n\n\n\t\t\t\t\t> Back to menu->  press 02: ";
          cout<<"\n\n\n\t\t\t\t\t> Enter your choice : ";
          cin>>inputnum01;

         switch(inputnum01)        {
         case 1:
              getuserData();
            break;
            case 2:
             window01();
            break;
            default:
                cout<<"\n\n\n\t\t\t\t\t> Invalid Enter ! ";
        }
     }

        void getuserData()
      {
        system("cls");
        cout << "\n\t\t\t\t\tContinue........Add user infomation ++\n";
        cout << "\n\t\t\t\t\t>Enter Username(enter register username !) : ";
        cin>>Username;
        cout << "\n\t\t\t\t\t>Enter address : ";
        cin>>Homeaddress;
        cout << "\n\t\t\t\t\t>Enter NIC number : ";
        cin>>NICnumber;
        cout << "\n\t\t\t\t\t>Enter telephone number : ";
        cin>>telephoneNum;
        cout << "\n\t\t\t\t\t>Enter age  : ";
        cin>>age;

        ofstream userData;
        userData.open("userData.txt",ios::app);
        userData<<Username<<" "<<Homeaddress<<" "<<NICnumber<<" "<<telephoneNum<<" "<<age<<endl;
        userData.close();

        using namespace inputData;
        cout << "\n\t\t\t\t\tGo to Login()- press any key : ";
        system("pause");
        login();

      }

     void loginAccount(string Username,string Userpassword)
     {
         this->Username=Username;
         this->Userpassword=Userpassword;

        string UserAndPassword=Username+" "+Userpassword;
        string line;

        ifstream registerDataFile;
        registerDataFile.open("registerDataFile.txt");

           bool found = false;

if(registerDataFile.is_open()) {

    while(getline(registerDataFile,line) && !found) {

        if (line.compare(UserAndPassword) == 0) {

            found = true;

        }
    }
    registerDataFile.close();

    if(found) {

        cout << "\n\n\n\t\t\t\t\t Login Sucsessfully "<<endl;
        system("cls");
        UserAccount();
    }

    else {
              system("Color 0A");
            using namespace inputData;
          cout << "\n\n\n\t\t\t\t\tUsername or password incorrect!"<<endl;
          cout << "\n\n\t\t\t\t\t Try to Login again ! press -- [01] || Back to menu :  press--[02] : ";
          cin>>inputnum01;
          if(1==inputnum01)
          {
              login();
          }else if(2==inputnum01)
          {
              system("pause");
              window01();
          }
         }
}

}

     void UserAccount()
     {
        cout << "\n\t\t\t\t\t[Admin Account name] : "<<Username<<endl;

     }
};



void cregister()
{
    system("Color 0A");
    using namespace inputData;
    cout<<"\n\n\n\t\t\t\t\t> Enter Admin Username : ";
    cin>>username1;
    cout<<"\n\t\t\t\t\t>Enter Admin Password : ";
    cin>>userpassword1;

    Admin *obj=new Admin();
    obj->openAccount(username1,userpassword1);
    delete obj;
}
void login()
{
    system("Color 0A");
    using namespace inputData;
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t> Login now -->>>> : ";
    cout<<"\n\n\n\t\t\t\t\t>If you want to leave press [1] || Enter Admin Username : ";
    cin>>username1;

     if("1" == username1){

         window01();

    }else{

      cout<<"\n\t\t\t\t\t>Enter Admin Password : ";
      cin>>userpassword1;

    }

    Admin obj;
    obj.loginAccount(username1,userpassword1);
    menu();
}


void Aboutus()
{
     system("Color 0A");
    cout<<"\n\n\t\t\t\t\t -------------About us----------------------- "<<endl;
    cout<<"\n\n\n\t\t\t\t\t>NILWALA Coparation (pvt) Ltd";
    cout<<"\n\t\t\t\t\t Matara,sri lanka";
    cout<<"\n\n\t\t\t\t\t>General Line : +94 (0) 115577111";
    cout<<"\n\t\t\t\t\t>Hotline : +94 (0) 115777888";
    cout<<"\n\t\t\t\t\t> Email : EMS@NilwalaCorp.lk";
    cout<<"\n\t\t\t\t\t>Fax : +94 (0) 11 2430393\n";
    cout<<"\n\t\t\t\t\t> Developed by NIBM HDSE-212-F 05-Team Members\n";
    cout<<"\n\t\t\t\t\t>Mahdse212f-020 \n";
    cout<<"\n\t\t\t\t\t>Mahdse212f-019 \n";
    cout<<"\n\t\t\t\t\t>Mahdse212f-024 \n";
    cout<<"\n\t\t\t\t\t>Mahdse212f-013 \n";
    cout<<"\n\t\t\t\t\t> Copyright ?? NILWALA Coparation (pvt) Ltd. All rights reserved.\n";
    cout<<"\n\t\t\t\t\t----------- Exit :  ";
    system("pause");
    window01();

}


void window01()// frist window application
 {


    using namespace inputData;
    system("cls");
     system("Color E4");
    cout<<"\n\n\t\t\t\t\t NILWALA Inventory Management System "<<endl;
    cout<<"\n\n\t\t\t\t\tTips ! :: If you do not have an account, first create an account and load it.";
    cout<<"\n\n\n\t\t\t\t\t>Log in : 01\n";
    cout<<"\n\t\t\t\t\t>Register: 02\n";
    cout<<"\n\t\t\t\t\t>About us : 03 \n";
    cout<<"\n\t\t\t\t\t> Exits : 04 \n\n\n";

    cout<<" \n\t\t\t\t\t Enter number : ";
    cin>>inputnum01;
    system("cls");

    switch(inputnum01)
    {
    case 1:
       login();
        break;
    case 2:
         cregister();
        break;
    case 3:
        Aboutus();
        break;
    case 4:
        return;
        break;
    default:
            cout<<" \n\n\t\t\t\t\t Enter number is wrong ! ";

    }

}
int main()
{
    window01();

    return 0;
}

