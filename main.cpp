#include <iostream>
#include<string>
#define TotalRoom 100

using namespace std;


static int totalRoomNumber = 0;

class customer
{
protected:
	string customerName;
	string fatherName;
	string customerAddress;
	string mobileNumber;
public:
	customer()
	{
		customerName = "N/A";
		fatherName = "N/A";
		customerAddress = "N/A";
		mobileNumber = "N/A";
	}

	void setCustomerName(string name) {
		customerName = name;
	}
	string getcustomerName() {
		return customerName;
	}
	void setFatherName(string name) {
		fatherName = name;
	}
	string getfatherName() {
		return fatherName;
	}
	void setCustomerAddress(string address) {
		customerAddress = address;
	}
	string getsetCustomerAddress() {
		return customerAddress;
	}
	void setMobileNumber(string number) {
		mobileNumber = number;
	}
	string getMobileNumber() {
		return mobileNumber;
	}
	void inputCustomerInformation()
	{
		cout << "Enter Customer Name: ";
		fflush(stdin);
		getline(cin, customerName);
		cout << "Enter Customer's Father Name: ";
		fflush(stdin);
		getline(cin, fatherName);
		cout << "Enter Customer Address.[HOUSE/ROAD orHOUSE/VILLEGE]: ";
		fflush(stdin);
		getline(cin, customerAddress);
		cout << "Enter Customer Number : ";
		fflush(stdin);
		cin >> mobileNumber;
		fflush(stdin);
	}
	void showCustomerInformation()
	{
		cout << "Customer Name :" << customerName << endl
			<< "Customer's Father Name: " << fatherName << endl
			<< "Customer address :" << customerAddress << endl
			<< "Customer number :" << mobileNumber << endl;
	}
	~customer(){}

};

class room : public customer
{
private:
	int roomNumber;
	string roomtype;
	float roomtyperent;
	string bednumber;
	float bedtyperent;
	string ac;
	float actyperent;
	float totalroomPrice;
public:
	room()
	{
		customer();
		static int i = 1;
		roomNumber = i;
		i++;
		roomtype = "N/A";
		bednumber = "N/A";
		ac = "N/A";
		roomtyperent = 0.00;
		bedtyperent = 0.00;
		actyperent = 0.00;
		totalroomPrice = 0.00;
	}
	void setRoomNumber(int Rnumber) {
		roomNumber = Rnumber;
	}
	int getRoomNumber() {
		return roomNumber;
	}
	void setroomtype(string type) {
		roomtype = type;
	}
	string getroomtype() {
		return roomtype;
	}
	void setbadnumber(string BEDnumber) {
		bednumber = BEDnumber;
	}
	string getbadnumber() {
		return bednumber;
	}
	void setac(int c) {
		ac = c;
	}
	string getac() {
		return ac;
	}
	void inputroomInformation()
	{
		int a;
		cout << "What Kind of Room?" << endl;
		cout << "   1.Premium" << endl
			<< "   2.Regular" << endl << endl;
		cin >> a;
		fflush(stdin);
		switch (a)
		{
		case 1:
			roomtype = "Premium";
			roomtyperent = 10000.00;
			break;
		case 2:
			roomtype = "regular";
			roomtyperent = 7000.00;
			break;
		default:
			cout << "You entered Wrong option!!\a\a" << endl;
			break;
		}
	}
	void inputbednumberInformation()
	{
		int b;
		cout << "How Many bed ? " << endl;
		cout << "   1.Single Bed" << endl
			<< "   2.Dual Bed" << endl
			<< "   3.Triple Bed" << endl << endl << endl;
		cin >> b;
		fflush(stdin);
		switch (b)
		{
		case 1:
			bednumber = "Single Bed";
			bedtyperent = 5000.00;
			break;
		case 2:
			bednumber = "Dual Bed";
			bedtyperent = 1000.00;
			break;
		case 3:
			bednumber = "Triple Bed";
			bedtyperent = 1500.00;
			break;
		default:
			cout << "You entered Wrong option!!\a\a" << endl;
			break;
		}
	}
	void ACinformation()
	{
		int c;
		cout << "Do you Want?" << endl;
		cout << "  1.AC Room" << endl
			<< "  2.Non AC Room" << endl << endl;
		cin >> c;
		fflush(stdin);
		switch (c)
		{
		case 1:
			ac = "AC";
			actyperent = 2000.00;
			break;
		case 2:
			ac = "Non AC";
			actyperent = 1000.00;
			break;
		default:
			cout << "You entered Wrong option!!\a\a" << endl;
			break;
		}
	}
	void calculatetotalPrice(int daynumber)
	{
		totalroomPrice = (roomtyperent + bedtyperent + actyperent)*daynumber;
	}
	void roomReservation(int i)
	{
		setRoomNumber(i);
		inputCustomerInformation();
		inputroomInformation();
		inputbednumberInformation();
		ACinformation();
		int day;
		cout << "\nHow many day do you want to stay ? ";
		cin >> day;
		fflush(stdin);
		calculatetotalPrice(day);
		cout << "Total Price : " << totalroomPrice << " Taka " << endl;
	}
	void showroomReservation()
	{
		showCustomerInformation();
		cout << "Room Number : " << roomNumber << endl
			<< "Room Type   : " << roomtype << endl
			<< "Bed Type    : " << bednumber << " (" << ac << ") " << endl
			<< "Total Price : " << totalroomPrice << " Taka " << endl;
	}
	~room(){}
};
class hotel
{
private:
	room hotelroom[TotalRoom];
public:
	void bookingRoom()
	{
		int roomNumber; int c = 0;
		cout << "Which no. of Room Do you Want to Reserve[1-100] : ";
		cin >> roomNumber;
		fflush(stdin);
		for (int i = 0; i<totalRoomNumber; i++)
		{
			if (roomNumber == hotelroom[i].getRoomNumber())
			{
				cout << "This Room is reserved" << endl;
				c++;

			}
		}
		if (c == 0)
		{
			hotelroom[totalRoomNumber].roomReservation(roomNumber);
			++totalRoomNumber;
		}
	}
	void serachroom()
	{
		int roomNumber; int c = 0;
		cout << "Which no. of Room[1-100] : ";
		cin >> roomNumber;
		fflush(stdin);
		for (int i = 0; i<totalRoomNumber; i++)
		{
			if (roomNumber == hotelroom[i].getRoomNumber())
			{
				cout << "This Room is reserved" << endl;
				c++;
				break;

			}
		}
		if (c == 0)
		{
			cout << "This Room is empty for reservation" << endl;
		}
	}
	void searchCustomerbyName()
	{
		string customername; int c = 0;
		cout << "Customer Name : ";
		cin >> customername;
		fflush(stdin);
		for (int i = 0; i<totalRoomNumber; i++)
		{
			if (customername == hotelroom[i].getcustomerName())
			{
				cout << "Room Number :" << hotelroom[i].getRoomNumber() << endl;
				c++;
				break;
			}
		}
		if (c == 0)
		{
			cout << "There is no Customer with this Name" << endl;
		}
	}
	void serachCustomerbyMobileNumber()
	{
		string MobileNumber; int c = 0;
		cout << "Customer Mobile Number : ";
		cin >> MobileNumber;
		fflush(stdin);
		for (int i = 0; i<totalRoomNumber; i++)
		{
			if (MobileNumber == hotelroom[i].getMobileNumber())
			{
				cout << "Room Number:" << hotelroom[i].getRoomNumber() << endl;
				c++;
				break;
			}
		}
		if (c == 0)
		{
			cout << "There is no Customer with this Mobile Number" << endl;
		}
	}
	void showroomdetail()
	{
		int roomNumber; int c = 0;
		cout << "Which no. of Room[1-100] : ";
		cin >> roomNumber;
		for (int i = 0; i<totalRoomNumber; i++)
		{
			if (roomNumber == hotelroom[i].getRoomNumber())
			{
				hotelroom[i].showroomReservation();
				c++;
				break;
			}
		}
		if (c == 0)
		{
			cout << "This Room is not reserved" << endl;
		}
	}
	void searchEmptyroom()
	{
		cout << "These Rooms are Empty : ";
		for (int i = 1; i <= TotalRoom; i++)
		{
			for (int j = 0; j<totalRoomNumber; j++)
			{
				if (i != hotelroom[j].getRoomNumber())
				{
					cout << i << ", ";
				}
			}
		}
	}

	void Introductoin()
	{
		cout << "\t\t************************************************" << endl;
		cout << "\t\t* ---HOTEL----" << "                                 *" << endl;
		cout << "\t\t* ---ROOM BOOKING---" << "                           *" << endl;
		cout << "\t\t* ---SYSTEM--------" << "                            *" << endl;
		cout << "\t\t* MADY BY:MD.NURUL AHSAN,DUHITA MANSUR KHAN    *" << endl;
		cout << "\t\t* ID NUMBER:2014-2-60-006,2014-2-60-103" << "        *" << endl;
		cout << "\t\t* UNIVERSITY: EAST WEST UNIVERSITY" << "             *" << endl;
		cout << "\t\t* PRESS ENTER TO MAIN MENU" << "                     *" << endl;
		cout << "\t\t************************************************" << endl;
		cin.get();
	}
};

int main()
{

	hotel Westin;
	Westin.Introductoin();
	int decision;
	do
	{
		cout << "_____________________________________________________" << endl;
		cout << "                   Main Menu" << endl;
		cout << "_____________________________________________________" << endl
			<< "1.Booking room " << endl
			<< "2.Show Reserved room Details" << endl
			<< "3.Search a room availability for reservation" << endl
			<< "4.Search a Customer Room No by his Name" << endl
			<< "5.Search a Customer Room No by his mobile number" << endl
			<< "6.Search room detail by room number" << endl
			<< "7.Search Which room is empty" << endl
			<< "8.Exit" << endl
			<< "_____________________________________________________" << endl;

		cout << "Enter Your Choice : ";
		cin >> decision;
		switch (decision)
		{
		case 1:
		{
				  char choose;
				  do
				  {
					  Westin.bookingRoom();
					  cout << "\nDo you Want to reserve another Room?[y/n]";
					  cin >> choose;
				  }
				  while (choose == 'y');
				  break;
		}
		case 2:
		{
				  char choose;
				  do
				  {
					  Westin.showroomdetail();
					  cout << "\nDo you Want to see another Room detail?[y/n]";
					  cin >> choose;
				  }
				  while (choose == 'y');
				  break;
		}
		case 3:
		{
				  char choose;
				  do
				  {
					  Westin.serachroom();
					  cout << "\nDo you Want to search another room?[y/n]";
					  cin >> choose;
				  }
				  while (choose == 'y');
				  break;
		}
		case 4:
		{
				  char choose;
				  do
				  {
					  Westin.searchCustomerbyName();
					  cout << "\nDo you Want to search another customer?[y/n] ";
					  cin >> choose;
					  fflush(stdin);
				  }
				  while (choose == 'y');
				  break;
		}
		case 5:
		{
				  char choose;
				  do
				  {
					  Westin.serachCustomerbyMobileNumber();
					  cout << "\nDo you want to search another? [y/n] ";
					  cin >> choose;
					  fflush(stdin);
				  } 
				  while (choose == 'y');
				  break;
		}
		case 6:
		{
				  char choose;
				  do
				  {
					  Westin.showroomdetail();
					  cout << "\nDo you want to see another detail? [y/n] ";
					  cin >> choose;
					  fflush(stdin);
				  }
				  while (choose == 'y');
				  break;

		}
		case 7:
		{
				  Westin.searchEmptyroom();
				  break;
		}
		case 8:
		{
				  cout << endl << endl << "GOOD BYE" << endl << endl;
				  cout << "THANK YOU FOR USING OUR SYSTEM" << endl;
				  break;
		}
		default:
		{
				   cout << "You Entered a Wrong option !!\a\a" << endl;
				   break;
		}
		}

	}
	while (decision != 8);

	cout << endl << endl;
	getchar();
	getchar();
	return 0;
}

