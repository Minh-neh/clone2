#include <iostream>
#include <iomanip>
#include <cstdlib> // To use rand()
#include <cstring>
#include <cstring>
#include "Word.h"

using namespace std;

int Word:: getT_voca() {  //const not used here because static data member
	return voca;
}

string Word:: get_viet()
{
    return VIET;
}

int Word:: get_type()
{
    return TYPE;
}

int Word::voca = 0; //initializing the static int 

void Word::create_vocabulary()
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
}

int GetRandom(int min,int max){
    return min + (int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}

void Word::review_vocabulary(string VIET, int TYPE)
{
    int n;
    string re_viet;
    int re_type;
    cout << "\t\t\t\t  Enter the Number of vocabulary you want to Review:  ";
    cin >> n;
    cout << "Tu vung ID la " << GetRandom(1,n) << " mang nghia tieng anh" <<  ENG << "co nghia tieng viet la gi: " << endl;
    cin >> re_viet;
    cout << "Thuoc loai tu gi: " << endl;
    cout << "(1): Danh tu" << setw(5) << "(2): Dong tu" << endl
         << "(3): Tinh tu" << setw(5) << "(4): Trang tu" << endl;
    cin >> re_type;
    if(VIET == re_viet && TYPE == re_type)
    {
        cout << "CHINH XAC";
    }
    else if (VIET == re_viet)
    {
        cout << "SAI ROI" << endl;
        show_type(TYPE);
    }
    else if (TYPE == re_type)
    {
        cout << "SAI ROI" << endl;
        show_viet(VIET);
    }
    else 
    {
        cout << "SAI ROI, HOC LAI NHE" << endl;
    } 
}

void Word::show_viet(string VIET)
{
    cout << "Tu nay co nghia tieng viet la: " << VIET << endl;
}

void Word::show_type(int TYPE)
{

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
    default:{
        cout << "";
            }
    }
}


void Main_Menu()
{
    char slct; // SELECT
    Word *obj1[100];

    Menu:{
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
    cout << "\t\t\t 2.  REVIEW VOCABULARY" << endl;
    cout << "\t\t\t 3.  CHECKING LEARNED VOCABULARY" << endl;
    cout << "\t\t\t 4.  LET'S RELAXING" << endl;
    cout << endl;
    cout << "\t\t\t SELECT OPTION (1-4): ";
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
            cout << endl;
            system("CLS");
            cout << "\t\t\t\t  ------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t      CREATE VOCABULARY" << endl;
            cout << "\t\t\t\t  ------------------------------------------------------" << endl
                 << endl;
            cout << endl;
            obj1[i]->create_vocabulary();
        }
        goto Menu;
        break;

    case '2':
        system("CLS");
        if (Word::getT_voca() == 0)
        {
            cout << endl
                 << endl
                 << endl;
            cout << "\t\t\t\t   -------No Vocabulary Created Yet-------" << endl
                 << endl
                 << endl;
        goto Menu;
        break;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << endl;
                cout << "\t\t\t\t------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t     REVIEW VOCABULARY" << endl;
                cout << "\t\t\t\t------------------------------------------------------" << endl;
                obj1[i]->review_vocabulary(obj1[i]->get_viet(), obj1[i]->get_type());
        system("pause");
        goto Menu;
        break;
            }
        }
    }
    }
}
    