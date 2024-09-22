// project final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<fstream>
using namespace std;

//Location Function
void location(char* city, char* state, char* country, char* address)
{
	fstream FoodappLocation;
	FoodappLocation.open("FoodappLocation.txt", ios::out);
	do {
		bool hasNumber = false;
		cout << "Enter your Delivery Address:" << endl;
		cin.getline(address, 50);

		cout << "Enter your City:" << endl;
		cin.getline(city, 20);
		cout << "Enter your State/Province:" << endl;
		cin.getline(state, 20);
		cout << "Enter your Country:" << endl;
		cin.getline(country, 20);
		for (int i = 0; city[i] != '\0'; i++) {
			if (city[i] >= '0' && city[i] <= '9') {
				hasNumber = true;
				break;
			}
		}
		for (int i = 0; state[i] != '\0'; i++) {
			if (state[i] >= '0' && state[i] <= '9') {
				hasNumber = true;
				break;
			}
		}
		for (int i = 0; country[i] != '\0'; i++) {
			if (country[i] >= '0' && country[i] <= '9') {
				hasNumber = true;
				break;
			}
		}

		if (hasNumber) {
			cout << "Invalid input. Please do not enter numbers in city, state, or country." << endl;
		}
		else {
			cout << "Address and Location Added successfully" << endl;
			FoodappLocation << address << endl;
			FoodappLocation << city << endl;
			FoodappLocation << state << endl;
			FoodappLocation << country << endl;
			break;
		}
	} while (true);
	FoodappLocation.close();
}

//LOGIN function (menu driven)
int login(char* username, char* password, char* name, int& c1)
{
	fstream Foodapp;
	Foodapp.open("FoodappLogin.txt", ios::out);
	char email[50];
	char op;
	cout << endl;
	// just main screen
	cout << "\t\t\t\t    * Want to Order best food in town? *\n \t\t\t\t\t  >>> Signup or Login HERE <<<" << endl;
	cout << endl;

	cout << "\t\t\t\t     |           Login / Sign up         |" << endl;

	cout << endl;
	// ends here

	// login system here
	//while (true)
	//{


	cout << "Please select an option : " << endl;
	cout << "--> Login (Type 'L')" << endl;
	cout << "--> Register (Type 'R')" << endl;
	cout << "--> Exit (Type 'E') " << endl;

	cout << endl;
	cout << "Select option:" << endl;
	cin >> op;
	if (op == 'e' || op == 'E')
	{
		cout << "Thank you for using MunchBuddy." << endl;
	}
	if (op == 'e' || op == 'E')
	{
		c1 = 1;
		return c1;
	}
	//case 1
	switch (op) {
	case 'l':
	case 'L': {
		cout << "\t\t\t\t\t ***  Login to your account ***" << endl;
		cout << "Please Enter Your Name:" << endl;
		cin.ignore(); // used cin.ignore here because it was not taking input from the user in the name variable
		cin.getline(name, 30);
		cout << "Enter your username:" << endl;
		//cin.ignore();
		cin.getline(username, 20);

		cout << "Enter your password:" << endl;
		//cin.ignore();
		cin.getline(password, 15);


		if (name != 0 && username != 0 && password != 0)
		{
			cout << "Login Successfull" << endl;
			Foodapp << name << endl;
			//Foodapp << email << endl;
			Foodapp << password << endl;
			Foodapp << username << endl;

		}
		else if ((name == 0 && username == 0 && password == 0))
		{
			cout << "Invalid name or username or password" << endl;

		}
		break;
	}

			//case 2
	case 'R':
	case'r': {
		char confirmpass[15];
		cout << "\t\t\t\t\t *** Register your account ***" << endl;
		cout << "Please Enter Your Name: " << endl;
		cin.ignore();
		cin.getline(name, 20);
		cout << "Enter your email:" << endl;
		cin.getline(email, 30);
		//cin.ignore();
		cout << "Enter your username:" << endl;
		cin.getline(username, 25);
		//cin.ignore();
	again:
		cout << "Enter your password (Use a Strong PASSWORD) :" << endl;
		cin.getline(password, 15);
		//cin.ignore();
		cout << "Renter your password:" << endl;
		cin.getline(confirmpass, 15);
		for (int i = 0; i < confirmpass[i] != '\0'; i++)
		{
			if (password[i] == confirmpass[i])
			{
				//cout << "Password Matched!!!";
			}
			else if (password[i] != confirmpass[i])
			{
				cout << "Password didn't match !!! " << endl;
				goto again;
			}
		}
		//cin.ignore();
		if (email != 0 && username != 0 && password != 0)
		{
			cout << "Account registered successfully" << endl;
			Foodapp << name << endl;
			Foodapp << email << endl;
			Foodapp << password << endl;
			Foodapp << username << endl;

		}
		else if ((email == 0 && username == 0 && password == 0))
		{
			cout << "Invalid email or username or password" << endl;

		}


		break;
	}
		   //exit case
	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}
	/*if (op == 'E' || op == 'e') {
		break;
	}*/
	//}
	Foodapp.close();
	//function ended

}

//payment function
void payment(int x, char* cardn, char cvv[], char* phone, char* name)
{
	cout << endl;
	cout << "1) Cash on Delivery" << endl;
	cout << "2) Credit/Debit Card" << endl;
	cout << "Please Select your payment method:";
	cin >> x;
	switch (x)
	{
	case 1:
		cout << "You Selected Cash on Delivery" << endl;
		break;
	case 2:
		cout << "You Selected Payment via Credit / debit card" << endl;
		cout << "Enter your name:" << endl;
		cin.ignore();
		cin.getline(name, 20);
		cout << "Enter your 15 digit card number:" << endl;
		cin.getline(cardn, 20);
		cout << "Enter CVV of your card:" << endl;
		cin.getline(cvv, 10);
		break;

	default:
		cout << "Invalid option. Try again:" << endl;
	}
}
//cart function
void addtocart(char* option, fstream& foodappdata)
{
	char i[100];
	fstream Foodappdata;
	Foodappdata.open("FoodappOrderData.txt", ios::in);
	cout << endl;
p:
	cout << endl;
	cout << "Do you want to confirm your order?" << endl;
	cin >> option;
	if (*option == 'y' || *option == 'Y')
	{
		cout << "Your Order items and bill is : " << endl;
		while (!Foodappdata.eof())
		{
			//Foodappdata >> i;
			Foodappdata.getline(i, 100);

			cout << i << endl;
		}
		cout << "Your Order has been Confirmed and will be deliverd in ~40 minutes" << endl;
		//cout << "Thank You for placing order at Munch buddy";

	}
	else if (*option == 'n' || *option == 'N')
	{
		cout << endl;
		cout << "Your order is not confirmed" << endl;
		cout << "Do you want to view your cart? " << endl;
		cin >> *option;
		if (*option == 'y' || *option == 'Y')
		{

			cout << "Your cart items are: " << endl;
			while (!Foodappdata.eof())
			{
				//Foodappdata >> i;
				Foodappdata.getline(i, 100);
				cout << i << endl;
			}
			goto p;
		}
	}

}
// view cart
void viewcart(char* option, fstream& foodappdata)
{
	char i[100];
	fstream Foodappdata;
	Foodappdata.open("FoodappOrderData.txt", ios::in);
	cout << endl;
	cout << "Your Itmes are added to your cart" << endl;

	cout << "Do yo want to view your cart? " << endl;
	cin >> *option;
	if (*option == 'y' || *option == 'Y')
	{

		cout << "Your cart items are: " << endl;
		while (!Foodappdata.eof())
		{
			//Foodappdata >> i;
			Foodappdata.getline(i, 100);
			cout << i << endl;
		}
	}
}


int main()
{																					//variable declaration
	int n = 50;
	int y = 12;
	char* password = new char[n];
	char* username = new char[n];
	char* city = new char[n];
	char* state = new char[n];
	char* country = new char[n];
	char* address = new char[n];
	char email[50];
	char* name = new char[n];
	char* option = new char[n];
	char* phone = new char[y];
	char* cardn = new char[n];
	char cvv[3];
	int x = 0;
	fstream Foodappmenu;
	fstream Foodappdata;
	Foodappmenu.open("Foodappmenu.txt", ios::out);
	Foodappdata.open("FoodappOrderData.txt", ios::out);

	char pizza1[] = "Chicken Fajita", pizza2[] = "Chicken Bar BQ", pizza3[] = "Peri Peri", pizza4[] = "Creamy Max", roll1[] = "Chicken Chatni Roll", roll2[] = "Chicken Mayo Roll", roll3[] = "Veg Roll With Fries", bur1[] = "Zinger Burger", bur2[] = "Chicken Burger", bur3[] = "Beef Burger";
	char sand1[] = "Club Sandwich", sand2[] = "Chicken Crispy Sandwich", sand3[] = "Extream Veg Sandwich";
	char bir1[] = "Chicken Biryani", bir2[] = "Prawn Biryani", bir3[] = "Beef Biryani";
	char d1[] = "Cold Drink", d2[] = "Tea", d3[] = "Coffee", d4[] = "Juice";
	char gotostart;
	int* choice = new int;
	int pchoice = 0, pchoice1 = 0, quantity = 0;




	// main menu design
	for (int i = 1; i < 35; i++)
	{
		cout << " ";

	}
	for (int j = 1; j < 45; j++)
	{
		cout << "*";

	}
	cout << endl;
	for (int k = 1; k < 40; k++)
	{
		cout << " ";
	}

	cout << "\t      Welcome to MunchBuddy " << endl;
	for (int i = 1; i < 35; i++)
	{
		cout << " ";

	}
	for (int j = 1; j < 45; j++)
	{
		cout << "*";

	}
	cout << endl;




	cout << endl;
	//design end

	int c1 = 0;

	c1 = login(username, password, name, c1);                         // Login function called

	cout << endl;
	cout << endl;
	if (c1 != 1)
	{


		location(city, state, country, address);                                               // Location function called
		cout << endl;
		cout << endl;

		cout << "Hello " << name << "\n\nWhat would you like to order?\n\n";

	beginning:

		cout << "\t\t\t\t\t\t--------Menu--------\n\n";

		cout << "--> 1) Pizzas\n";
		cout << "--> 2) Burgers\n";
		cout << "--> 3) Sandwich\n";
		cout << "--> 4) Rolls\n";
		cout << "--> 5) Biryani\n";
		cout << "--> 6) Drinks\n\n";
		cout << "\n Please Enter your Choice: ";

		cin >> *choice;
		// if else for pizza
		if (*choice == 1)
		{
			cout << "\n1) " << pizza1 << "\n";
			cout << "2) " << pizza2 << "\n";
			cout << "3) " << pizza3 << "\n";
			cout << "4) " << pizza4 << "\n";
			cout << "\nPlease Enter which Flavour would you like to have?:";
			cin >> pchoice;
			if (pchoice >= 1 && pchoice <= 5)
			{
				cout << "\n1) Small Rs.750\n" << "2) Regular Rs.950\n" << "3) Large Rs.1280\n";
				cout << "\nChoose Size Please:";
				cin >> pchoice1;
				if (pchoice1 >= 1 && pchoice1 <= 3)
					cout << "\nPlease Enter Quantity: ";
				cin >> quantity;
				switch (pchoice1)
				{
				case 1:
					*choice = 750 * quantity;
					break;

				case 2:
					*choice = 950 * quantity;
					break;

				case 3:
					*choice = 1280 * quantity;
					break;
				}
				//billing details using 'pchoice' variable
				switch (pchoice)
				{
				case 1:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << pizza1;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << pizza1 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 2:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << "  " << pizza2;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << pizza2 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 3:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << pizza3;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << pizza3 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 4:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << pizza4;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << pizza4 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;

				}
				cout << "Would you like to order anything else? Y / N:";
				cin >> gotostart;
				if (gotostart == 'Y' || gotostart == 'y')
				{
					goto beginning;

				}
				else if (gotostart == 'N' || gotostart == 'n')
				{
					cout << endl;
					cout << "Thank You for using MunchBuddy";
					goto end;
				}



			}

		}

		//burger
		else if (*choice == 2)
		{
			cout << "\n1 " << bur1 << " Rs.280" << "\n";
			cout << "2 " << bur2 << " Rs.350" << "\n";
			cout << "3 " << bur3 << " Rs.460" << "\n";
			//cout << "4 " << pizza4 << "\n";
			cout << "\nPlease Enter which Burger you would like to have?: ";
			cin >> pchoice1;
			if (pchoice1 >= 1 && pchoice1 <= 3)
			{
				cout << "\nPlease Enter Quantity: ";
				cin >> quantity;
				switch (pchoice1)
				{
				case 1:
					*choice = 280 * quantity;
					break;

				case 2:
					*choice = 350 * quantity;
					break;

				case 3:
					*choice = 460 * quantity;
					break;

				}
				/*	//option to get fries and drinks with order
					cout << "would you like to buy some fries and drinks? "<<endl;
					cout << " Y/N "<<endl;
					cout << "enter option: ";
					char a;
					cin >> a;
					if (a == 'Y')
					{
						cout << "type 1 for fries  ";
						cout << "type 2 for drinks ";
						int b;
						cout << "enter option: ";
						cin >> b;
						if (b == 1)
						{
							cout << "how much fries you want to order: "<<endl;
							int c;
							cout << "enter price: ";
							cin >> c;
							cout << "<-----thank you for your order---->" << endl;
						}
						else if (b == 2)
						{

							cout << "which drink you want to order: " << endl;
							cout << "type 1 for Cocacola" << endl;
							cout << "type 2 for Sprite" << endl;
							cout << "type 3 for Fanta" << endl;
							int d;
							cout << "enter option:  ";
							cin >> d;
							cout << "how many drinks you would like to order:  ";
							int z;
							cin >> z;
							cout << endl<< "<-----thank you for your order---->" << endl;
						}
						else
							cout << "-------ivalid number----- " << endl;
					}*/

				switch (pchoice1)
				{
				case 1:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << bur1;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << bur1 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 2:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << "  " << bur2;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << bur2 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 3:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << bur3;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << bur3 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;


				}
				cout << "\nWould you like to order anything else? Y / N:";
				cin >> gotostart;
				if (gotostart == 'Y' || gotostart == 'y')
				{
					goto beginning;

				}
				else if (gotostart == 'N' || gotostart == 'n')
				{
					cout << endl;
					cout << "Thank You for using MunchBuddy";
					goto end;
				}

			}
		}

		//sandwich
		else if (*choice == 3)
		{
			cout << "\n1  " << sand1 << " Rs.340" << "\n";
			cout << "2  " << sand2 << " Rs.250" << "\n";
			cout << "3  " << sand3 << " Rs.150" << "\n";

			cout << "\nPlease Enter which Sandwich you would like to have?:";
			cin >> pchoice1;
			if (pchoice1 >= 1 && pchoice1 <= 3)
			{
				cout << "\nPlease Enter Quantity: ";
				cin >> quantity;
				switch (pchoice1)
				{
				case 1:
					*choice = 340 * quantity;
					break;

				case 2:
					*choice = 250 * quantity;
					break;

				case 3:
					*choice = 150 * quantity;
					break;

				}
				//option to get fries and drinks with order
			/*	cout << "would you like to buy some fries and drinks? " << endl;
				cout << " Y/N " << endl;
				cout << "enter option: ";
				char h;
				cin >> h;
				if (h == 'Y')
				{
					cout << "type 1 for fries  ";
					cout << "type 2 for drinks ";
					int i;
					cout << "enter option: ";
					cin >> i;
					if (i == 1)
					{
						cout << "how much fries you want to order: " << endl;
						int c;
						cout << "enter price: ";
						cin >> c;
						cout << "<-----thank you for your order---->" << endl;
					}
					else if (i == 2)
					{

						cout << "which drink you want to order: " << endl;
						cout << "type 1 for cocacola" << endl;
						cout << "type 2 for sprite" << endl;
						cout << "type 3 for fanta" << endl;
						int j;
						cout << "enter option:  ";
						cin >> j;
						cout << "how many drinks you would like to order:  ";
						int k;
						cin >> k;
						cout << endl << "<-----thank you for your order---->" << endl;
					}
					else
						cout << "-------ivalid number----- " << endl;
				}
				else
					cout << "thank you for your order " << endl;
			}*/
				switch (pchoice1)
				{
				case 1:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << sand1;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << sand1 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 2:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << "  " << sand2;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << sand2 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 3:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << sand3;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << sand3 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;


				}
				cout << "Would you like to order anything else? Y / N:";
				cin >> gotostart;
				if (gotostart == 'Y' || gotostart == 'y')
				{
					goto beginning;

				}
				else if (gotostart == 'N' || gotostart == 'n')
				{
					cout << endl;
					cout << "Thank You for using MunchBuddy";
					goto end;
				}
			}
		}

		//roll
		else if (*choice == 4)
		{
			cout << "\n1 " << roll1 << " Rs.150" << "\n";
			cout << "2 " << roll2 << " Rs.100" << "\n";
			cout << "3 " << roll3 << " Rs.120" << "\n";

			cout << "\nPlease Enter which you would like to have?: ";
			cin >> pchoice1;
			if (pchoice1 >= 1 && pchoice1 <= 3)
			{
				cout << "\nHow Much Rolls Do you want: ";
				cin >> quantity;
				switch (pchoice1)
				{
				case 1:
					*choice = 150 * quantity;
					break;

				case 2:
					*choice = 100 * quantity;
					break;

				case 3:
					*choice = 120 * quantity;
					break;

				}

				switch (pchoice1)
				{
				case 1:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << roll1;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << roll1 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 2:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << "  " << roll2;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << roll2 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 3:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << roll3;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << roll3 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				}
				cout << "Would you like to order anything else? Y / N:";
				cin >> gotostart;
				if (gotostart == 'Y' || gotostart == 'y')
				{
					goto beginning;

				}
				else if (gotostart == 'N' || gotostart == 'n')
				{
					cout << endl;
					cout << "Thank You for using MunchBuddy";
					goto end;
				}

			}
		}
		//biryani

		else if (*choice == 5)
		{
			cout << "\n1 " << bir1 << " Rs.180" << "\n";
			cout << "2 " << bir2 << " Rs.320" << "\n";
			cout << "3 " << bir3 << " Rs.240" << "\n";

			cout << "\nPlease Enter which Biryani you would like to have?:";
			cin >> pchoice1;
			if (pchoice1 >= 1 && pchoice1 <= 3)
			{
				cout << "\nPlease Enter Quantity: ";
				cin >> quantity;
				switch (pchoice1)
				{
				case 1:
					*choice = 180 * quantity;
					break;

				case 2:
					*choice = 320 * quantity;
					break;

				case 3:
					*choice = 240 * quantity;
					break;

				}

				//receipt
				switch (pchoice1)
				{
				case 1:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << " " << quantity << " " << bir1;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << bir1 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 2:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << "  " << bir2;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << bir2 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 3:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << bir3;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << bir3 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;

				}
				cout << "Would you like to order anything else? Y / N:";
				cin >> gotostart;
				if (gotostart == 'Y' || gotostart == 'y')
				{
					goto beginning;

				}
				else if (gotostart == 'N' || gotostart == 'n')
				{
					cout << endl;
					cout << "Thank You for using MunchBuddy";
					goto end;
				}
			}
		}

		//drinks
		else if (*choice == 6)
		{
			cout << "\n1 " << d1 << " Rs.100" << "\n";
			cout << "2 " << d2 << " Rs.150" << "\n";
			cout << "3 " << d3 << " Rs.250" << "\n";
			cout << "4 " << d4 << " Rs.120" << "\n";

			cout << "\nPlease Enter which Drink you would like to have?:";
			cin >> pchoice1;
			if (pchoice1 >= 1 && pchoice1 <= 4)
			{
				cout << "\nPlease Enter Quantity: ";
				cin >> quantity;
				switch (pchoice1)
				{
				case 1:
					*choice = 100 * quantity;
					break;

				case 2:
					*choice = 150 * quantity;
					break;

				case 3:
					*choice = 250 * quantity;
					break;
				case 4:
					*choice = 120 * quantity;
					break;

				}
				//receipt
				switch (pchoice1)
				{
				case 1:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << " " << quantity << " " << d1;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << d1 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 2:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << "  " << d2;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << d2 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 3:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << d3;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << d3 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;
				case 4:
					cout << "\t\t\t\t\t\t--------Your Order--------\n\n";
					cout << "" << quantity << " " << d4;
					cout << "\n--> Your Total Bill is: Rs " << *choice << "/-" << endl;
					Foodappdata << quantity << " " << d4 << " " << *choice << endl;
					payment(x, cardn, cvv, phone, name);
					cout << endl;
					viewcart(option, Foodappdata);
					cout << endl;
					addtocart(option, Foodappdata);
					cout << endl;
					break;

				}
				cout << "Would you like to order anything else? Y / N:";
				cin >> gotostart;
				if (gotostart == 'Y' || gotostart == 'y')
				{
					goto beginning;

				}
				else if (gotostart == 'N' || gotostart == 'n')
				{
					cout << endl;
					cout << "Thank You for using MunchBuddy";
					goto end;
				}
			}
		}
		else if (*choice != 1 || *choice != 2 || *choice != 3 || *choice != 4 || *choice != 5 || *choice != 6);
		{
			cout << "We apologize for inconvenience but please select from the available 6 items only: " << endl;
			goto beginning;
		}
		Foodappmenu << pizza1 << endl << pizza2 << endl << pizza3 << endl << pizza4 << endl << roll1 << endl << roll2 << endl
			<< roll3 << endl << bur1 << endl << bur2 << endl << bur3 << endl << sand1 << endl << sand2 << endl << sand3 << endl
			<< bir1 << endl << bir2 << endl << bir3 << endl
			<< d1 << endl << d2 << endl << d3 << endl << d4;
		//end:
		//cout << "Thank You for using MunchBuddy";


		Foodappmenu.close();
		Foodappdata.close();

		//Allocated memory deleted
		delete choice;
		delete[] username;
		delete[] password;
		delete[] name;
		delete[] city;
		delete[] country;
		delete[] address;
		delete[] state;
		delete[] option;
		delete[] cardn;
		delete[] phone;

		// To remove any dangling pointers
		password = NULL;
		username = NULL;
		name = NULL;
		choice = NULL;
		country = NULL;
		state = NULL;
		address = NULL;
		city = NULL;
		option = NULL;
	}
end:
	return 0;
}

