// FlightBookingSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Database.h"

using namespace std;
using namespace FlightBookingSystem;

int displayMenu();
void flightDetailQuery(Database& db);
void getTicketInfo(Database& db);
void addBooking(Database& db);
void addFlight(Database& db);

int main() {
	Database flightDB;

	while (true) {
		try
		{
			int selection = displayMenu();
			switch (selection) {
			case 1:
				flightDB.displayAllFlights();
				break;
			case 2:
				flightDetailQuery(flightDB);
				break;
			case 3:
				getTicketInfo(flightDB);
				break;
			case 4:
				addBooking(flightDB);
				break;
			case 5:
				addFlight(flightDB);
				break;
			case 6:
				cout << "Exiting the system" << endl;
				break;
			default:
				cerr << "Unknown command. Try again." << endl;
				return 1;
			}
		}
		catch (logic_error error)
		{
			cerr << error.what() << endl;
		}
	}

	return 0;
}

int displayMenu() {
	int selection;

	cout << endl;
	cout << "FlightBookingSystem" << endl;
	cout << "------------------------------" << endl;
	cout << "1) All flights schedule" << endl;
	cout << "2) Flight detail query" << endl;
	cout << "3) Your ticket info" << endl;
	cout << "4) Reserve a seat" << endl;
	cout << "5) Add new flight" << endl;
	cout << "6) Exit" << endl;
	cout << "------------------------------" << endl;

	cin >> selection;
	return selection;
}

void flightDetailQuery(Database& db) {
	string flightNumber;

	cout << "Flight number: " << endl;
	cin >> flightNumber;

	Flight& flight = db.getFlightInfo(flightNumber);
	flight.displayFlightInfo();
}

void getTicketInfo(Database& db) {
	string flightNumber;
	string passportNumber;

	cout << "Flight Number: " << endl;
	cin >> flightNumber;

	Flight& flight = db.getFlightInfo(flightNumber);

	cout << "Passport Number: " << endl;
	cin >> passportNumber;

	flight.displayTicketInfo(passportNumber);
}

void addBooking(Database& db) {
	string flightNumber;
	string firstName;
	string lastName;
	string passportNumber;
	int seatNumber;

	cout << "Flight Number: " << endl;
	cin >> flightNumber;

	Flight& flight = db.getFlightInfo(flightNumber);

	cout << "First name: " << endl;
	cin >> firstName;
	cout << "Last name: " << endl;
	cin >> lastName;
	cout << "Passport Number: " << endl;
	cin >> passportNumber;
	cout << "Select your seat from 1~" << flight.getSeatsAvailable() << " for your flight" << endl;
	cin >> seatNumber;

	flight.reserveSeat(seatNumber, firstName, lastName, passportNumber);

	cout << "Your have successfully reserved seat " << seatNumber << endl;
}

void addFlight(Database& db) {
	string flightNumber;
	string departureAirport;
	string departureDate;
	string departureTime;
	string arrivalAirport;
	string arrivalDate;
	string arrivalTime;
	int seatsAvailable;

	cout << "Flight Number: " << endl;
	cin >> flightNumber;

	if (db.isFlightScheduled(flightNumber) == true)
	{
		throw logic_error("Flight already scheduled.");
	}

	cout << "Departure Airport: " << endl;
	cin >> departureAirport;
	cout << "Departure Date: " << endl;
	cin >> departureDate;
	cout << "Departure Time: " << endl;
	cin >> departureTime;
	cout << "Arrival Airport: " << endl;
	cin >> arrivalAirport;
	cout << "Arrival Date: " << endl;
	cin >> arrivalDate;
	cout << "Arrival Time: " << endl;
	cin >> arrivalTime;
	cout << "Number of Seats: " << endl;
	cin >> seatsAvailable;

	db.addFlight(flightNumber, departureAirport, departureDate, departureTime,
		arrivalAirport, arrivalDate, arrivalTime, seatsAvailable);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
