#include <iostream>
#include <iomanip>

using namespace std;

string itemName[10] = { "Milk", "Bread", "Chocolate", "Towel", "Toothpaste",
		"Soap", "Pen", "Biscuit", "Lamp", "Battery" };

string itemID[10] = { "0120001", "0120002", "0120003", "0120004", "0120005",
		"0120006", "0120007", "0120008", "0120009", "0120010" };

float itemPrice[10] = { 10.50, 5.50, 8.00, 12.10, 6.75, 5.20, 2.00, 4.45, 20.50,
		10.00 };

string floatToString(float number) {
	ostringstream stream;
	stream << std::fixed;
	stream << std::setprecision(2);
	stream << number;
	return stream.str();
}

void itemList() {
	cout << "|   ITEM   |  PRICE  |  BARCODE/ID  |" << endl;
	for (int i = 0; i < 10; i++) {
		string pound = "£";
		cout << setprecision(2) << fixed << setw(11) << itemName[i] << setw(10)
				<< (pound + floatToString(itemPrice[i])) << setw(15)
				<< itemID[i] << endl;
	};
}

float IDCheck() {
	int ID;
	bool validID = false;
	cout << "Barcode (Type 'F' to finish): ";
	string userInput;
	cin >> userInput;
	if (userInput == "F")
		return -1;
	for (int i = 0; i < 10; i++) {
		if (userInput == itemID[i]) {
			validID = true;
			ID = i;
		}

	}
	if (validID) {
		cout << "You have selected the item: " << itemName[ID]
				<< ", it costs: £" << itemPrice[ID] << endl;
		return itemPrice[ID];
	} else {
		cerr << "Invalid ItemID, please try again." << endl;
		return 0;
	}

}
int main() {

    bool nextCustomer = true;
    while(nextCustomer) {

        cout << "****************************************************" << endl;
        cout << "*   WELCOME TO HERTS SUPERMARKET CHECKOUT SYSTEM   *" << endl;
        cout << "* Scan the barcode or manually type the barcode ID *" << endl;
        cout << "****************************************************" << endl;
        itemList();

        float totalPrice = 0;

        float price = IDCheck();

        while(price != -1) {
            totalPrice += price;
            price = IDCheck();
        }

        cout << "Your total is £" << totalPrice << endl;

        float change = -totalPrice;

        while(change < 0) {
            float cash;
            cout << "Cash required (£" << -change << "): ";
            cin >> cash;

            change += cash;
        }

        cout << "Thank you for your purchase. Change: £" << change << endl;

        string newCustomer;
        while(true) {
            cout << "Next Customer (Y/N)? ";
            cin >> newCustomer;
            newCustomer = tolower(newCustomer.at(0));
            if(newCustomer.at(0) == 'y') {
                nextCustomer = true;
                cout << endl;
                break;
            } else if(newCustomer.at(0) == 'n') {
                nextCustomer = false;
                break;
            }
        }

    }
    return 0;
}
