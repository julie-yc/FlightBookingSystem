#pragma once
#include <string>

using namespace std;

namespace FlightBookingSystem {

	class Passenger {
	public:
		Passenger();
		Passenger(const string& firstName, const string& lastName, const string& passportNumber);

		const string& getFirstName() const;
		const string& getLastName() const;
		const string& getPassportNumber() const;

		void displayInfo() const;

	private:
		string mFirstName;
		string mLastName;
		string mPassportNumber;

	};
}