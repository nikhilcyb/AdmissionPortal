#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
//#include <Dos.h>
//#include<windows.h>

using namespace std;

int randomFlag = 0;
template <class T> // Template
T getDetail()
{
    T input;
    cin >> input;
    return input;
}

void heading()
{
    cout << "\n-------------------------------------------------------";
    cout << "------------------------------------------------------";
    cout << "\n\t\t\t\tM Y _ S T U D E N T   A D M I S S I O N   P O R T A L\n";
    cout << "-------------------------------------------------------";
    cout << "------------------------------------------------------\n";
}

class Biodata
{
protected:
    string name, address, email, DOB, Nationality, Dstate;
    long long int phone_no;
    char gender;
    int ID, branch, HSC_year, SSC_year;
    float e_mark, HSC_per, SSC_per;

    void getData(); // Function Overriding
    void showData();
    void header();
};

class Student : public Biodata // Inheretance
{
public:
    friend void menu(); // Friend Function

    Student() // Constructor
    {
        name = "";
        DOB = "";
        address = "";
        Dstate = "";
        email = "";
        Nationality = "";
        e_mark = 0;
        HSC_per = 0;
        SSC_per = 0;
    }
    ~Student() // Distructor
    {
        system("cls");
        cout << "Exiting";
    }
    void getData(); // Function Overriding
    void showData();
    void header();
    void listView();
    void preView();
    void addData();
    void displayData();
    void searchData();
    void deleteData();
    void modifyData();
    void sortData();
    void finalData();
    int getID() { return ID; }
    string get_name() { return name; }
    float get_e_mark() { return e_mark; }
} s;

void welcome()
{
    system("cls");
    heading();
    cout << "\n\n\n\t\t\t\t";
    cout << "Prepared By    :";
    cout << "   Nrupraj and Mohit";
    cout << "\n\n\n\n\t\t\t\t\t       OOP Project";
    cout << "\n\t\t\t\t\tStudent Admission Portal\n\n";
    cout << "\t\t\t\t    Press Enter to continue......";
    getchar();
    //  int process=0;
    //  cout<<"\n\n\t\t\t\t\tLoading";
    //
    //  for(process=0;process<10;process++)
    //  {
    //    Sleep(150);
    //    cout<<".";
    //  }
}

void login(char username[10]) // Function Overloading
{
    string pass = "";
    char ch;

    cout << "\n\t\t\t\tPlease Enter system Password : ";
    ch = getch();
    while (ch != 13)
    {
        pass.push_back(ch);
        cout << '*';
        ch = getch();
    }
    if (pass == "pass")
    {
        cout << "\n\n\t\t\t\tAccess Granted! \t";
        getch();
    }
    else
    {
        cout << "\n\n\t\t\t\tAccess Aborted...\n\t\t\t\tPlease Try Again\n\n\t\t";
        system("PAUSE");
        login(username);
        system("cls");
    }
}
void login() // Function Overloading
{
    cout << "\n\n\tStudent entry... Access Granted! \n\n";
    int input;
    system("cls");
    heading();
    cout << "\n\n\n\t\t\t\t 1. New Student Entry\n\n";
    cout << "\t\t\t\t 2. Display Record\n\n";
    cout << "\t\t\t\t 3. Delete Record\n\n";
    cout << "\t\t\t\t 4. Modify Record\n\n";
    cout << "\t\t\t\t 0. Exit\n\n\n\n\n";
    cout << "-------------------------------------------------------";
    cout << "------------------------------------------------------\n";
    cout << "\t\t\t   > Choose options:[1/2/3/4/0]: ";
    fflush(stdin);
    cin >> input;
    switch (input)
    {
    case 1:
        randomFlag = 0;
        s.addData();
        break;
    case 2:
        s.searchData();
        break;
    case 3:
        s.deleteData();
        break;
    case 4:
        s.modifyData();
        break;
    case 0:
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        fflush(stdin);
        cout << "\n\n\t\t\tT H A N K I N G   Y O U . . .\n\n\n  ";
        exit(0);
    default:
        fflush(stdin);
        cout << "\n\n\n\t\t\t\t      Invalid input!\n\n\t\t\t\t";
        cout << "Press Enter to choose again...";
        getchar();
    }

    login();
}

void Student::getData()
{
    system("cls");
    heading();
    cout << "\n\t\tstep 1. Student Biodata\n\n";
    if (randomFlag == 0)
        ID = rand();
    int xp = -1;
    try
    {
        cout << "\t\t\tEnter Gender (M/F)      : ";
        cin >> gender;
        cout << "\t\t\tEnter Full Name         : ";
        cin.ignore();
        getline(cin, name);
        cout << "\t\t\tEnter Full Address      : ";
        getline(cin, address);
        cout << "\t\t\tEnter Country           : ";
        getline(cin, Nationality);
        cout << "\t\t\tEnter state on Domicile : ";
        getline(cin, Dstate);
        cout << "\t\t\tBranch available        :\n\t\t\t  >1. Computer Science and Engg.\n";
        cout << "\t\t\t  >2. Information Technology\n\t\t\t  >3. Artificial Intelligence\n";
        cout << "\t\t\tEnter Choice            : ";
        cin >> branch;
        cout << "\t\t\tEnter your Phone no     : ";
        cin >> phone_no;
        cout << "\t\t\tEnter your Email_ID     : ";
        cin >> email;

        cout << "\n\n\t\t\t\tStep 1 Completed.....  ";
        getch();
        system("cls");
        heading();

        cout << "\n\n\t\tStep 2. Academic information\n\n";
        cout << "\n\t\t\tEnter SSC percentage      : ";
        SSC_per = getDetail<float>();
        cout << "\n\t\t\tEnter SSC Passing Year    : ";
        SSC_year = getDetail<int>();
        cout << "\n\t\t\tEnter HSC percentage      : ";
        HSC_per = getDetail<float>();
        cout << "\n\t\t\tEnter HSC Passing Year    : ";
        HSC_year = getDetail<int>();
        cout << "\n\t\t\tEnter Entrance Test Score : ";
        e_mark = getDetail<float>();
    }
    catch (int x) // exceptional handling
    {
        cout << "\n\n\tSomething went wrong\n\n";
    }

    cout << "\n\n\t\t\t\t Registration Completed.....  ";
    cout << "\n\n\t\t\t\t Please Note your registration ID : " << ID;
    cout << "\n\n\t\t\tPress Enter Key for menu...";

    getch();
    system("cls");
    string loop;
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\n\t\t\tWant to see preview of Entered information ?? (Y/N) :";
    cin >> loop;
    if (loop == "Y" || loop == "y")
    {
        system("cls");
        heading();
        preView();
    }
    else
    {
        cout << "\t\t\tPress Enter Key for menu...";
        getch();
    }
}

void Student::preView()
{
    cout << "\n\t\t..........................Student Biodata..........................\n\n";
    cout << "\n\t\t\t Admission No.     : " << ID;
    cout << "\n\t\t\t Gender (M/F)      : " << gender;
    cout << "\n\t\t\t Full Name         : " << name;
    cout << "\n\t\t\t Full Address      : " << address;
    cout << "\n\t\t\t Country           : " << Nationality;
    cout << "\n\t\t\t state on Domicile : " << Dstate;
    if (branch == 1)
        cout << "\n\t\t\t Branch selected   : Computer Science and Engg.";
    if (branch == 2)
        cout << "\n\t\t\t Branch selected   : Information Technology";
    if (branch == 3)
        cout << "\n\t\t\t Branch selected   : Artificial Intelligence";
    cout << "\n\t\t\t Phone no          : " << phone_no;
    cout << "\n\t\t\t Email_ID          : " << email;

    cout << "\n\n\t\t........................Academic information........................\n\n";
    cout << "\n\t\t\t SSC percentage      : " << SSC_per;
    cout << "\n\t\t\t SSC Passing Year    : " << SSC_year;
    cout << "\n\t\t\t HSC percentage      : " << HSC_per;
    cout << "\n\t\t\t HSC Passing Year    : " << HSC_year;
    cout << "\n\t\t\t Entrance Test Score : " << e_mark;
    cout << "\n\n-------------------------------------------------------";
    cout << "------------------------------------------------------\n";
    cout << "\t\t\tPress Enter Key for menu...";
    getch();
}

void Student::addData()
{
    ofstream fout;
    fout.open("Students.dat", ios::binary | ios::out | ios::app);

    s.getData();
    getch();
    fout.write((char *)&s, sizeof(s));
    fout.close();
    cout << "\n\nData Successfully Saved to File....\n";
}

void Student::displayData()
{
    ifstream fin;
    fin.open("Students.dat", ios::in | ios::binary);
    while (fin.read((char *)&s, sizeof(s)))
    {
        s.showData();
    }
    fin.close();
    cout << "\n\nData Reading from File Successfully Done....\n";
}

void Student::showData()
{
    system("cls");
    heading();
    ifstream fin("Students.dat");
    int rec = 0;
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (rec < 1)
            s.header();
        s.listView();
        rec++;
    }
    fin.close();
    cout << "\n\n\n";
    cout << "-------------------------------------------------------";
    cout << "------------------------------------------------------\n";
    cout << "\t\tTotal " << rec << " Records in file...\n";
    cout << "\n\t\tPress any key for menu...";
    getch();
}
void Student::header()
{
    cout.setf(ios::left);
    cout << "\n\n\t" << setw(10) << "I.D." << setw(20) << "Student Name" << setw(20) << "Department"
         << setw(15) << "SSC Score" << setw(15) << "HSC Score" << setw(15) << "Entrance Test Score" << endl;
    cout << "-------------------------------------------------------";
    cout << "------------------------------------------------------\n";
}
void Student::listView()
{
    string Branch;
    if (branch == 1)
        Branch = "CSE";
    if (branch == 2)
        Branch = "IT";
    if (branch == 3)
        Branch = "AI";
    cout.setf(ios::left);
    cout << "\t" << setw(10) << ID << setw(20) << name << setw(20) << Branch
         << setw(15) << SSC_per << setw(15) << HSC_per << setw(15) << e_mark << endl;
}

void Student::searchData()
{
    system("cls");
    heading();
    int n, flag = 0, ch2;
    string n1;
    ifstream fin;
    fin.open("Students.dat", ios::in | ios::binary);
    cout << "\n\n\t\t\tSearch a Student Data ";
    cout << "\n\t\t------------------------------------------";
    cout << "\n\n\t\t\t  >1. by ID\n\n\t\t\t  >2. by Name\n\n\t\t\t  >3. go back.";
    cout << "\n\t\t------------------------------------------";
    cout << "\n\n\t\t\t  Enter choice		 : ";
    cin >> ch2;
    if (ch2 == 1)
    {
        cout << "\t\t\tEnter Admission Number (ID) you want to search : ";
        cin >> n;
    }
    else if (ch2 == 2)
    {
        cout << "\t\tEnter Full name of Student you want to search  :";
        cin.ignore();
        getline(cin, n1);
    }
    else if (ch2 == 3)
        return;
    // else ;
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (ch2 == 1)
        {
            if (n == s.getID())
            {
                cout << "\n\n\t\t\tThe Details of Admission No.(ID) " << n << " found.\n";
                cout << "\t\t\tPress any key to see...";
                getch();
                system("cls");
                heading();
                s.preView();
                flag++;
            }
        }
        else if (ch2 == 2)
        {
            string n2 = s.get_name();

            if (n1 == n2)
            {
                cout << "\n\n\t\t\tThe Details of " << n1 << " found.\n";
                cout << "\t\t\tPress any key to see...";
                getch();
                system("cls");
                heading();
                s.preView();
                flag++;
            }
        }
    }
    if (flag == 0)
    {
        cout << "\n\n\t\tData not found....\n";
        cout << "\t\t\tPress any key to continue...";
        getch();
    }
    fin.close();
    searchData();
}

void Student::deleteData()
{
    system("cls");
    heading();
    int n, flag = 0;
    ifstream fin;
    ofstream fout, tout;
    fin.open("Students.dat", ios::in | ios::binary);
    fout.open("TempStud.dat", ios::out | ios::app | ios::binary);

    cout << "\n\n\t\t\tEnter Admission Number(ID) you want to Delete : ";
    cin >> n;

    while (fin.read((char *)&s, sizeof(s)))
    {
        if (n == s.getID())
        {
            cout << "\n\n\t\t\t";
            cout << "\n\t\t\tFile - Admission No. " << n << " has been Removed:\n";

            flag++;
        }
        else
        {
            fout.write((char *)&s, sizeof(s));
        }
    }
    fout.close();
    fin.close();
    if (flag == 0)
        cout << "\n\n\t\t\tThe Admission No. " << n << " not found....\n";
    cout << "\t\t\tPress any key to continue...";
    getch();
    remove("Students.dat");
    rename("tempStud.dat", "Students.dat");
}

void Student::modifyData()
{
    randomFlag = 1;
    system("cls");
    heading();
    int n, flag = 0, pos;
    fstream fio;

    fio.open("Students.dat", ios::in | ios::out | ios::binary);

    cout << "\n\t\t\t\tEnter Admission Number you want to Modify : ";
    cin >> n;

    while (fio.read((char *)&s, sizeof(s)))
    {
        pos = fio.tellg();
        if (n == s.getID())
        {
            cout << "\n\t\t\tThe Following Admission No.(ID) " << n << " will be modified with new data:\n";
            s.preView();
            cout << "\n\nNow Enter the New Details....\n";
            s.getData();
            fio.seekg(pos - sizeof(s));
            fio.write((char *)&s, sizeof(s));
            flag++;
        }
    }
    fio.close();
    if (flag == 0)
    {
        cout << "\n\n\t\t\t\tThe Admission No. " << n << " not found....\n";
        cout << "\t\t\tPress any key to continue...";
        getch();
    }
}

void Student::sortData()
{ /*

ifstream fin;
ofstream fout, tout;
fin.open("Students.dat", ios::in | ios::binary);
fout.open("TempStud.dat", ios::out | ios::app | ios::binary);

while (fin.read((char *)&s, sizeof(s)))
{
if (n == s.get_e_mark())
{
cout << "\n\n\t\t\t";
cout << "\n\t\t\tFile - Admission No. " << n << " has been Removed:\n";

flag++;
}
else
{
fout.write((char *)&s, sizeof(s));
}
}
fout.close();
fin.close();
if (flag == 0)
cout << "\n\n\t\t\tThe Admission No. " << n << " not found....\n";
cout << "\t\t\tPress any key to continue...";
getch();
remove("Students.dat");
rename("tempStud.dat", "Students.dat");

*/
}

void Student::finalData()
{
    system("cls");
    heading();
    ifstream fin("Students.dat");
    float cut_score;
    cout << "\n\t\t\t\tEnter cut off score : ";
    cin >> cut_score;
    cout << "\n-------------------------------------------------------";
    cout << "------------------------------------------------------\n";
    int rec = 0, head = 0;
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (head < 1)
            s.header();
        if (cut_score <= s.get_e_mark())
        {
            s.listView();
            rec++;
        }
        head++;
    }
    fin.close();
    cout << "\n\n\n";
    cout << "-------------------------------------------------------";
    cout << "------------------------------------------------------\n";
    cout << "\t\tTotal " << rec << " Records Selected from " << head << " file...\n";
    cout << "\n\t\tPress any key for menu...";
    getch();
}

void menu()
{
    int input;
    system("cls");
    heading();
    cout << "\n\n\n\t\t\t\t 1. New Student Entry\n\n";
    cout << "\t\t\t\t 2. Display Student List\n\n";
    cout << "\t\t\t\t 3. Search a Student File\n\n";
    cout << "\t\t\t\t 4. Delete a Student Record\n\n";
    cout << "\t\t\t\t 5. Modify a Student Record\n\n";
    cout << "\t\t\t\t 6. Sort the List of Students\n\n";
    cout << "\t\t\t\t 7. Final List\n\n";
    cout << "\t\t\t\t 0. Exit\n\n\n\n\n";
    cout << "-------------------------------------------------------";
    cout << "------------------------------------------------------\n";
    cout << "\t\t\t   > Choose options:[1/2/3/4/5/6/7/0]: ";
    fflush(stdin);
    cin >> input;
    switch (input)
    {
    case 1:
        randomFlag = 0;
        s.addData();
        break;
    case 2:
        s.showData();
        break;
    case 3:
        s.searchData();
        break;
    case 4:
        s.deleteData();
        break;
    case 5:
        s.modifyData();
        break;
    case 6:
        s.sortData();
        break;
    case 7:
        s.finalData();
        break;
    case 0:
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        fflush(stdin);
        cout << "\n\n\t\t\tT H A N K I N G   Y O U . . .\n\n\n  ";
        exit(0);
    default:
        fflush(stdin);
        cout << "\n\n\n\t\t\t\t      Invalid input!\n\n\t\t\t\t";
        cout << "Press Enter to choose again...";
        getchar();
    }

    menu();
}

int main()
{
    srand(time(0));
    welcome();
    char username[10];
    system("cls");
    heading();
    cout << "\n\n\t\t\t\tlOGIN as   1.ADMIN   2. STUDENT";
again:
    cout << "\n\t\t\t\tPlease enter choice: ";
    int user_type;
    cin >> user_type;
    if (user_type == 1)
    {
        cout << "\n\t\t\t\tEnter username\t\t     : ";
        cin >> username;
        login(username);
        menu();
    }
    else if (user_type == 2)
    {
        login();
    }
    else
    {
        cout << "\n\n\t\t\t\t      Invalid input!\n\n\t\t\t\t";
        cout << "Press Enter to choose again...";
        goto again;
    }

    return 0;
}
