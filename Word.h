#include<iostream>
#include<iomanip>
#include<cstdlib> // To use rand()
#include<string>

using namespace std;

class Word {
protected:
	int ID;
	string ENG;
	int TYPE;
	string VIET;
	static int voca;
public:
	Word(int ID , string ENG, int TYPE, string VIET) {
		this->ID = ID;
        this->ENG = ENG;
        this->VIET = VIET;
        this->TYPE = TYPE;
        voca++;
	}
    void create_vocabulary();
    void review_vocabulary(string, int);
    void show_viet(string);
    void show_type(int);
    static int getT_voca();
    string get_viet();
    int get_type();
};
void Main_Menu();