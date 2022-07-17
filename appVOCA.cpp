#include <iostream>
#include <iomanip>
#include <cstdlib> // To use rand()
#include <string>

using namespace std;

void Word::voca_Init()
{
    system("CLS");
    int count = 0;
    ID = count++;
    cout << "Tu vung thu " << ID + 1 << "la: " << endl;
    cout << "Nhap tu nghia tieng anh: " << endl;
    cin >> ENG;
    cout << "Nhap tu tieng viet: " << endl;
    cin >> VIET;
    cout << "Nhap loai tu theo so cho san: " << endl;
    cout << "(1): Danh tu" << setw(5) << "(2): Dong tu" << endl
         << "(3): Tinh tu" << setw(5) << "(4): Trang tu" << endl;
    cin >> TYPE;
};

void Word::voca_Show()
{
    cout << "Tu vung thu " << ID + 1 << "la: " << ENG << endl;
    cout << "Nghia tieng viet la: " << VIET << endl;
    switch (TYPE)
    {
    case 1:
    {
        cout << "Tu nay la Danh tu." << endl;
        break;
    }
    case 2:
    {
        cout << "Tu nay la Dong tu." << endl;
        break;
    }
    case 3:
    {
        cout << "Tu nay la Tinh tu." << endl;
        break;
    }
    case 4:
    {
        cout << "Tu nay la Trang tu." << endl;
        break;
    }
    default:
    {
        cout << "Nhap lai loai tu." << endl;
    }
    }
    cin >> TYPE;
}
system("pause");

void Main_Menu()
{
    char slct; // SELECT
    Word *obj1[100];

Menu:
{
    system("CLS");
    cout << "\t\t\t                         *" << endl;
    cout << "\t\t\t                    ***********" << endl;
    cout << "\t\t\t              ***********************" << endl;
    cout << "\t\t\t      ---------------------------------------" << endl;
    cout << "\t\t\t               APP STUDY VOCABULARY" << endl;
    cout << "\t\t\t      ---------------------------------------" << endl;
    cout << "\t\t\t       ****       ****        ****      ****" << endl;
    cout << "\t\t\t       ****       ****        ****      ****" << endl;
    cout << "\t\t\t       ****       ****        ****      ****" << endl;
    cout << "\t\t\t       ****       ****        ****      ****" << endl;
    cout << "\t\t\t       ****       ****        ****      ****" << endl;
    cout << "\t\t\t      ---------------------------------------" << endl;
    cout << "\t\t\t  -----------------------------------------------" << endl;
    cout << "\t\t\t\t\t  +++MAIN MENU+++" << endl;
    cout << "\t\t\t  -----------------------------------------------" << endl;
    cout << endl;
    cout << "\t\t\t 1.  CREATE VOCABULARY" << endl;
    cout << "\t\t\t 2.  CHECKING VOCABULARY" << endl;
    cout << "\t\t\t 3.  REVIEW VOCABULARY" << endl;
    cout << "\t\t\t 4.  SPELL CHECKING" << endl;
    cout << "\t\t\t 5.  LIST LEARNED VOCABULARY " << endl;
    cout << endl;
    cout << "\t\t\t SELECT OPTION (1-5): ";
    cin >> slct;

    switch (slct)
    {
    case '1':
        system("CLS");
        int n;
        cout << "\t\t\t\t  ---------------------------------------------------" << endl;
        cout << "\t\t\t\t\t\t     NUMBER OF VOCABULARY" << endl;
        cout << "\t\t\t\t  ---------------------------------------------------" << endl
             << endl;
        cout << endl;
        cout << "\t\t\t\t  Enter the Number of vocabulary you want to Create:  ";
        cin >> n;
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            string type;
            cout << endl;
            system("CLS");
            cout << "\t\t\t\t  ------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t      CREATE VOCABULARY" << endl;
            cout << "\t\t\t\t  ------------------------------------------------------" << endl
                 << endl;
            do
            {
                cout << endl;
                cout << "\t\t\t\t  Enter Vocabulary Meaning (VIET/ENG):  ";
                cin >> type;
                cout << endl;
                if (type == "ENG")
                {
                    obj1[i] = new Checking_voca;
                    obj1[i]->create_vocabulary(type);
                }
                else if (type == "VIET")
                {
                    obj1[i] = new Saving_voca;
                    obj1[i]->create_vocabulary(type);
                }
                else
                {
                    cout << endl;
                    cout << "\t\t\t\t  Invalid Vocabulary Meaning Type, Please try again......" << endl;
                }
            } while (type != "ENG" && type != "VIET");
        }
        goto Menu;
        break;

    case '2':
        system("CLS");
        if (Word::get_voca() == 0)
        {
            cout << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t   -------No Vocabulary Created Yet-------" << endl
                 << endl
                 << endl;
        }
        else
        {
            for (int i = 0; i < 1; i++)
            {
                int ID, type_word;
                cout << endl;
                cout << "\t\t\t\t------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t     TYPE WORD" << endl;
                cout << "\t\t\t\t------------------------------------------------------" << endl
                     << endl
                     << endl;
                cout << "\t\t\t\t Enter ID OF VOCABULARY:  ";
                cin >> ID;
                cout << endl;
                cout << "\t\t\t\t Enter Type Of Vocabulary:  ";
                cin >> type_word;
                cout << endl;
                for (int i = 0; i < n; i++)
                {
                    obj1[i]->Typing(type_word, ID);
                }
            }
            cout << endl
                 << "\t\t\t\t  Define Successfully......" << endl;
        }
        cout << endl;
        system("pause");
        goto Menu;
        break;

    case '3':
        system("CLS");
        if (Word::get_voca() == 0)
        {
            cout << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t   -------No Vocabulary Created Yet-------" << endl
                 << endl
                 << endl;
        }
        else
        {
            for (int k = 0; k < 1; k++)
            {
                int j, amnt;
                cout << endl;
                cout << "\t\t\t\t------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t     WITHDRAW AMOUNT" << endl;
                cout << "\t\t\t\t------------------------------------------------------" << endl
                     << endl
                     << endl;
                cout << "\t\t\t\t Enter Account Number to Withdraw Amount:  ";
                cin >> j;
                cout << endl;
                cout << "\t\t\t\t Enter Amount To Be Withdrawed:  ";
                cin >> amnt;
                cout << endl;
                for (int i = 0; i < n; i++)
                {
                    obj1[i]->withdraws(amnt, j);
                }
            }
        }
        cout << endl;
        system("pause");
        goto Menu;
        break;
