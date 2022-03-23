#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

void introduction();
void main_function();
void user_information();
void add_property();
void search_property();
void edit_property();
void delete_property();
void report_property();
void sold_property();

struct seller
{
    string name;
    int phone;
    string adress;
};
struct property
{
    string name;
    string type;
    string adress;
    string price;
};
int main()
{
    main_function();
    return 0;
}

void introduction()
{
    system("cls");
    system("color 3f");
    cout << endl;
    cout << endl;
     cout<<"\n#########################################################\n"
        <<"#                                                       #\n"
        <<"#             Property Sale  Management  System           #\n"
        <<"#                                                       #\n"
        <<"#########################################################\n";
    cout << endl
         << endl;
}
void main_function()
{
    introduction();
    // a is for first  manu option list
    int a;
    cout << " Property Seller Process then Press 2: " << endl;
    cout << "If you want to Exit Process then  press 3: " << endl;
    do
    {
        cin >> a;

        switch (a)
        {

        case 2:
        {
            // b is for second manu option list
            int b;
            user_information();
            cout << "Do you Want to: " << endl;
            cout << "1: Add Property " << endl;
            cout << "2: Search Property " << endl;
            cout << "3:Edit Property " << endl;
            cout << "4: Delete Property " << endl;
            cout << "5: Report of  Property " << endl;
            cout << "6: Exit " << endl;
            cout << "Please Enter from the above options" << endl;
            do
            {
                cin >> b;
                switch (b)
                {
                case 1:
                    add_property();
                    break;
                case 2:
                    search_property();
                    break;
                case 3:
                    edit_property();
                    break;
                case 4:
                    delete_property();
                    break;
                case 5:
                    int v;
                    cout << "(1) Avalible Property" << endl;
                    cout << "(2) Sold Property" << endl;
                    cin >> v;
                    if (v == 1)
                    {
                        report_property();
                    }
                    if (v == 2)
                    {
                        sold_property();
                    }

                    break;
                case 6:
                    exit(0);
                    break;
                default:
                    cout << "Enter a valid option";
                    break;
                }
            } while (b <= 1 || b >= 4);
        }
        break;
        case 3:
            exit(0);
        default:
            cout << "Enter a valid option";
        }
    } while (a != 1 || a != 2);
}
void user_information()
{
    seller s1;
    cout << "Please Enter Your Name " << endl;
    cin >> s1.name;
    cout << "Please Enter Your Phone No. " << endl;
    cin >> s1.phone;
    cout << "Please Enter Your Adress " << endl;
    cin >> s1.adress;
    cout << "Enter your Property Detail;";
    system("cls");
}
//-------------------------------------------------------------------------------------------------
//------------------------------SEARCH FUNCTION----------------------------------------------------
//-------------------------------------------------------------------------------------------------
void add_property()
{
    introduction();
     int op;
again:
    cout << "Add a new Property";
    property p1;
    ofstream myfile("property.txt", ios::app);

    cout << "Enter the Name of Property" << endl;
    cin >> p1.name;
    cout << "Enter the adress of Property" << endl;
    cin >> p1.adress;
    cout << "Enter the Type of Property" << endl;
    cin >> p1.type;
    cout << "Enter the Price of Property" << endl;
    cin >> p1.price;
    myfile << p1.name << "   " << p1.adress << "   " << p1.type << "   " << p1.price << endl;

    myfile.close();
    cout << endl;

    cout << "Perss 1 to Add new Property:" << endl;
    cout << "Press 2 to return main manu:" << endl;
    cout << "Press 0 to exit :" << endl;
    cin >> op;
    if (op == 1)
    {
        cout << "The Property information was not duplicate and the new Property information is successfully added in the system!" << endl;
        goto again;
    }
    if (op == 2)
    {
        main_function();
    }
    if (op == 0)
    {
        exit(0);
    }
}
//-------------------------------------------------------------------------------------------------
//------------------------------SEARCH FUNCTION----------------------------------------------------
//-------------------------------------------------------------------------------------------------

void search_property()
{
loop:
    int ch;
    string name;
    string adress;
    property pro;
    cout << "(1). Search Property by Name" << endl
         << "(2). Search Property by Adress" << endl;
    cin >> ch;
    if (ch == 1)
    {
        cout << "Enter Property Name : ";
        cin >> name;
    }
    if (ch == 2)
    {
        cout << "Enter Property Adress : ";
        cin >> adress;
    }
    ifstream myfile("property.txt");
    while (myfile >> pro.name >> pro.adress >> pro.type >> pro.price)
    {
        if (name.compare(pro.name) == 0)
        {
            cout << pro.name << "   " << pro.adress << "   " << pro.type << "   " << pro.price;
        }
        else if (adress.compare(pro.adress) == 0)
        {
            cout << pro.name << "   " << pro.adress << "   " << pro.type << "   " << pro.price;
        }
    }
    cout << endl
         << endl
         << "Press 1 to go back to main menu OR Press 2  to search again "
         << endl
         << "Press 0 to exit"
         << endl;
    cin >> ch;
    if (ch == 1)
        main_function();
    if (ch == 2)
        goto loop;
    if (ch == 0)
        exit(0);
}
//-------------------------------------------------------------------------------------------------
//------------------------------DELETE FUNCTION----------------------------------------------------
//-------------------------------------------------------------------------------------------------
void delete_property()
{
loop:
    string op;
    property pro;
    cout << "Enter the Name of property you want to delete \n";
    cin >> op;
    ifstream myfile("property.txt");
    ofstream newfile("new.txt");
    myfile >> pro.name >> pro.adress >> pro.type >> pro.price;
    while (!myfile.eof())
    {
        if (pro.name != op)
        {
            newfile << pro.name << "    " << pro.adress << "   " << pro.type << "   " << pro.price << endl;
        }
        else
        {
            cout << "Record Deleted \n";
        }
        myfile >> pro.name >> pro.adress >> pro.type >> pro.price;
    }
    myfile.close();
    newfile.close();
    if (remove("property.txt") != 0)
    {
        cout << "NOT IN THE LIST" << endl;
    }
    else
    {
        cout << "ok";
    }
    if (rename("new.txt", "property.txt") != 0)
    {
        cout << "NOT IN THE LIST" << endl;
    }
    else
    {
        cout << "ok" << endl;
    }
    char x;
    cout << "press Y to delete more property" << endl;
    cout << "press R to return to main manu" << endl;
    cout << "press E Exit" << endl;
    cin >> x;
    if (x == 'y' || x == 'Y')
    {
        goto loop;
    }
    if (x == 'r' || x == 'R')
    {
        main_function();
    }
    if (x == 'e' || x == 'E')
    {
        exit(0);
    }
}
//-------------------------------------------------------------------------------------------------
//------------------------------EDIT FUNCTION----------------------------------------------------
//-------------------------------------------------------------------------------------------------
void edit_property()
{
loop:
    string name;
    string adress;
    string type;
    string price;
    string op;
    property pro;
    cout << "Enter the Name of property you want to edit \n";
    cin >> op;
    ifstream myfile("property.txt");
    ofstream newfile("new.txt");
    myfile >> pro.name >> pro.adress >> pro.type >> pro.price;
    while (!myfile.eof())
    {
        if (pro.name != op)
        {
            newfile << pro.name << "    " << pro.adress << "   " << pro.type << "   " << pro.price << endl;
        }
        else
        {
            cout << "Enter New  Property Name ";
            cin >> name;
            cout << "Enter New  Property Adress ";
            cin >> adress;
            cout << "Enter New  Property type ";
            cin >> type;
            cout << "Enter New  Property price ";
            cin >> price;
            newfile << name << "    " << adress << "   " << type << "   " << price << endl;
        }
        myfile >> pro.name >> pro.adress >> pro.type >> pro.price;
    }
    myfile.close();
    newfile.close();
    if (remove("property.txt") != 0)
    {
        cout << "NOT IN THE LIST" << endl;
    }
    else
    {
        cout << "ok";
    }
    if (rename("new.txt", "property.txt") != 0)
    {
        cout << "NOT IN THE LIST" << endl;
    }
    else
    {
        cout << "ok" << endl;
    }
    char x;
    cout << "press Y to edit another property" << endl;
    cout << "press R to return to main manu" << endl;
    cout << "press E Exit" << endl;
    cin >> x;
    if (x == 'y' || x == 'Y')
    {
        goto loop;
    }
    if (x == 'r' || x == 'R')
    {
        main_function();
    }
    if (x == 'e' || x == 'E')
    {
        exit(0);
    }
}
void report_property()
{
    property pro;

    ifstream myfile("property.txt");
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "-------------------------AVALIBLE PROPERTIES-------------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "PROPERTY"
         << "   "
         << "PROPERTY"
         << "     "
         << "PROPERTY"
         << "    "
         << "PROPERTY" << endl;
    cout << "NAME"
         << "       "
         << "ADRESS"
         << "       "
         << "TYPE"
         << "       "
         << "PRICE" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    cout << endl;
    while (myfile >> pro.name >> pro.adress >> pro.type >> pro.price)
    {
        cout << pro.name << "     " << pro.adress << "     " << pro.type << "      " << pro.price << endl;
    }
}




void sold_property()
{
    property pro;

    ifstream myfile("sold.txt");
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "-------------------------AVALIBLE PROPERTIES-------------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "PROPERTY"
         << "   "
         << "PROPERTY"
         << "     "
         << "PROPERTY"
         << "    "
         << "PROPERTY" << endl;
    cout << "NAME"
         << "       "
         << "ADRESS"
         << "       "
         << "TYPE"
         << "       "
         << "PRICE" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    cout << endl;
    while (myfile >> pro.name >> pro.adress >> pro.type >> pro.price)
    {
        cout << pro.name << "     " << pro.adress << "     " << pro.type << "      " << pro.price << endl;
    }
}
