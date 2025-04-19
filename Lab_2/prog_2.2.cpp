// დაწერეთ პროგრამა, რომელიც მომხმამრებელს სთავაზობს ფაილური ოპერაციებისთვის
// მოხერხებულ ინტერფეისს.
#include <cstring>
#include <iostream>
#include <stdlib.h>
using namespace std;

void interface()
{
    cout << "\n1. ინფორმაცია დირექტორიის შიგთავზე\n";
    cout << "2. დირექტორიის შექმნა\n";
    cout << "3. არსებული დირექტორიის წაშლა\n";
    cout << "4. ფაილის შექმნა\n"; // ფაილის შექმნა წინასწარ განსაზღვრული დაშვების
                                  // უფლებებით
    cout << "5. ინფორმაცია ფაილზე\n";
    cout << "6. ფაილზე უფლებების შეცვლა (შესრულების უფლების დამატება)\n";
    cout << "7. პროგრამას საქმიანობის დასრულება\n";
    cout << "\nგააკეთე არჩევანი: ";
}

bool checkName(string name)
{
    // ფაილის სახელად მხოლოდ ქვედა რეგისტრის ასოების გამოყენება არის შესაძლებელი
    for (int i = 0; i < name.length(); i++) {
        if (name[i] < 'a' || 'z' < name[i])
            return false;
    }
    return true;
}

int main()
{
    string comm = "";
    int choice = 7;
    while (true) {
        interface();
        cin >> choice;
        switch (choice) {
        case 1: {
            comm = "ls -al";
            break;
        }
        case 2: {
            string dir;
            cout << "მხოლოდ ქვედა რეგისტრის ასოების გამოყენებაა ნებადართული\n";
            while (true) {
                cout << "აკრიფეთ დირექტორიის სახელი: ";
                cin >> dir;
                cout << checkName(dir) << "\n";
                if (!checkName(dir)) {
                    cout << "აკრეფილი მიმდევრობა არასწორია\nთავიდან სცადეთ\n";
                    cin.clear();
                    continue;
                }
                break;
            }
            comm = "mkdir " + dir;
            break;
        }
        case 3: {
            comm = "ls -a";
            system(comm.c_str());
            string dr;
            cout << "ჩამონათვალიდან აკრიფეთ წასაშლელი დირექტორიის სახელი: ";
            cin >> dr;
            comm = "rm -r " + dr;
            break;
        }
        case 4: {
            comm = "ls -a";
            system(comm.c_str());
            string file;
            cout << "აკრიფეთ შესაქმნელი ფაილის სახელი: ";
            cin >> file;
            comm = "touch " + file;
            break;
        }
        case 5: {
            comm = "\nls -a";
            system(comm.c_str());
            string file;
            cout << "\nჩამონათვალიდან აკრიფეთ სასურველი ფაილის სახელი!!!\n";
            cout << "ფაილის სახელი: ";
            cin >> file;
            comm = "ls -al " + file;
            break;
        }
        case 6: {
            comm = "\nls";
            system(comm.c_str());
            string file;
            cout << "\nჩამონათვალიდან აირჩიეთ ფაილის სახელი უფლებების შესაცვლელად!!!\n";
            cout << "ფაილის სახელი: ";
            cin >> file;
            comm = "chmod a+x " + file;
            break;
        }
        default: {
            exit(0);
        }
        }
        system(comm.c_str());
    }
}
