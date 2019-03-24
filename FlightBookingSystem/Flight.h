#pragma once
#include <map>
#include <string>

#include "Passenger.h"

using namespace std;

namespace FlightBookingSystem {

	class Flight {
	public:
		Flight(const string& flightNumber, const string& departureAirport, const string& departureDate,
			const string& departureTime, const string& arrivalAirport, const string& arrivalDate,
			const string& arrivalTime, int seatsAvailable);

		const string& getFlightNumber() const;
		const int getSeatsAvailable() const;

		void reserveSeat(int seatNumber, const string& firstName, const string& lastName, const string& passportNumber);

		void displayFlightInfo() const;

		void displayTicketInfo(const string passportNumber) const;

	private:
		string mFlightNumber;
		string mDepartureAirport;
		string mDepartureDate;
		string mDepartureTime;
		string mArrivalAirport;
		string mArrivalDate;
		string mArrivalTime;
		int mSeatsAvailable;
		std::map<int, Passenger> mReservedSeats;
	};
}