#include "pch.h"
#include <iostream>

#include "Passenger.h"

using namespace std;

namespace FlightBookingSystem {

	Passenger::Passenger()
	{
	}

	Passenger::Passenger(const string& firstName, const string& lastName,
		const string& passportNumber) :
		mFirstName(firstName),
		mLastName(lastName),
		mPassportNumber(passportNumber)
	{
	}

	const string& Passenger::getFirstName() const {
		return mFirstName;
	}

	const string& Passenger::getLastName() const {
		return mLastName;
	}

	const string& Passenger::getPassportNumber() const {
		return mPassportNumber;
	}

	void Passenger::displayInfo() const {
		cout << "First Name: " << mFirstName << endl;
		cout << "Last Name: " << mLastName << endl;
		cout << "Passport Number: " << mPassportNumber << endl;
		cout << endl;
	}
}