/* დაწერეთ კონსოლური აპლიკაცია, რომელიც მომხმარებელს შესთავაზებს მარტივ და გასაგებ
 * ინტერფეისს. პროგრამის მეშვეობით უნდა იყოს შესაძლებელი რამდენიმე მოქმედების
 * გაკეთება. კერძოდ, დირექტორიასთან მუშაობა (შიგთავსის დათვალიერება / შექმნა /
 * წაშლა / სახელის გადარქმევა). მომხმარებელმა უნდა შეძლოს შესაბამისი დირექტორიის
 * სახელის კლავიატურიდან შეტანა. */

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

int main(){

	string dirOldName, dirNewName, command;
	int numb;

	while (true) {
		// გავაკეთოთ პროგრამის ინტერფეისი
		cout << "\nგააკეთეთ შესაბამისი არჩევანი: \n";
		cout << "   1. დირექტორიის დათვალიერება \n";
		cout << "   2. დირექტორიის შექმნა \n";
		cout << "   3. დირექტორიის სახელის გადარქმევა \n";
		cout << "   4. დირექტორიის წაშლა \n";
		cout << "   5. პროგრამიდან გამოსვლა \n";

		cout <<"\nთქვენი არჩევანი: ";
		cin >> numb;

		switch(numb){
			case 1: {
				cout << "\nშემოიტანეთ დირექტორიის სახელი: ";
				cin >> dirOldName;
				command = "ls -al " + dirOldName;
				break;
			}
			case 2: {
				cout << "\nშემოიტანეთ დირექტორიის სახელი: ";
				cin >> dirOldName;
				command = "mkdir " + dirOldName;
				break;
			}
			case 3: {
				cout << "\nშემოიტანეთ დირექტორიის სახელი: ";
				cin >> dirOldName;
				cout << "\nშემოიტანეთ დირექტორიის ახალი სახელი: ";
				cin >> dirNewName;
				command = "mv " + dirOldName + " " + dirNewName;
				break;
			}
			case 4: {
				cout << "\nშემოიტანეთ დირექტორიის სახელი: ";
				cin >> dirOldName;
				command = "rm -r " + dirOldName;
				break;
			}
			case 5: {
				cout << "\nპროგრამიდან წარმატებული გამოსვლა.\n\n";
				exit(0);

			}
			default: {
				cout << "\nასეთი მოქმედება არაა განსაზღვრული. თავიდან სცადეთ.\n\n";
				continue;
			}
		}
		system(command.c_str());
	}
}
