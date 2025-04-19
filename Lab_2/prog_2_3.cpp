#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

void interface()
{
    // გავაკეთოთ პროგრამის ინტერფეისი
        cout << "\n1. Information About Directory.\n";
        cout << "2. Create Directory.\n";
        cout << "3. Delete Current Directory.\n";
        cout << "4. Create File.\n";
        cout << "5. Information About File.\n";
        cout << "6. Change Rights On File (Add Rights).\n";
        cout << "7. Finish Program\n";
        cout << "\nPick an Option: ";

}

bool checkName(string name)
{
    // Only small letters are allowed to create file
    for (int i = 0; i < name.length(); i++)
    {
        if ( name[i] < 'a' || name[i] > 'z' )
        {
            return false;
        }
    }
    return true;
}


int main()
{

    string command = "";
    int choice = 7;

    while (true)
    {

        interface();
        cin >> choice;

            switch (choice)
            {

                case 1:
                {
                    command = "ls -al";
                    break;
                }

                case 2:
                {
                    string dir;
                    cout << "Only use small letters!\n";

                    while (true)
                    {
                        cout << "Enter directory's name: ";
                        cin >> dir;
                        cout << checkName(dir) << "\n";
                        if (!checkName(dir))
                        {
                                cout << "Letters are entered wrongly\nTry again!\n";
                                cin.clear();
                                continue;
                        }
                        break;
                    }
                    command = "mkdir " + dir;
                    break;
                }

                case 3:
                {
                    command = "ls -a";
                    system(command.c_str());
                    string dr;
                    cout << "Which directory do you want to delete ?\n";
                    cin >> dr;
                    command = "rm -r " + dr;
                    break;
                }

                case 4:
                {
                    command = "ls -a";
                    system(command.c_str());
                    string file;
                    cout << "Enter new file's name: ";
                    cin >> file;

                    command = "touch " + file;
                    break;
                }

                case 5:
                {
                    command = "ls -a";
                    system(command.c_str());
                    string file;
                    cout << "Which file's information do you want to see ?";
                    cin >> file;

                    command = "ls -al " + file;
                    break;
                }

                case 6:
                {
                    command = "ls -a";
                    system(command.c_str());
                    string file;
                    cout << "Which file's rights do you want to change ?";
                    cin >> file;

                    command = "chmod a+x " + file;
                    break;
                }

                case 7:
                {
                    cout << "Program Finished Successfully!\n";
                    exit(0);
                }

                default:
                {
                    cout << "Unknown Option Picked!\nTry again and pick option from following list!\n";
                    continue;
                }

            }

            system(command.c_str());    // Reads Command !!!

    }

}











