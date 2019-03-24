#include "pch.h"
#include <iostream>

#include "Flight.h"

using namespace std;

namespace FlightBookingSystem {
	Flight::Flight(const string& flightNumber, const string& departureAirport,const string& departureDate,
		const string& departureTime, const string& arrivalAirport, const string& arrivalDate,
		const string& arrivalTime, int seatsAvailable):
		mFlightNumber(flightNumber),
		mDepartureAirport(departureAirport),
		mDepartureDate(departureDate),
		mDepartureTime(departureTime),
		mArrivalAirport(arrivalAirport),
		mArrivalDate(arrivalDate),
		mArrivalTime(arrivalTime),
		mSeatsAvailable(seatsAvailable)
	{
	}

	const string& Flight::getFlightNumber() const {
		return mFlightNumber;
	}

	const int Flight::getSeatsAvailable() const {
		return mSeatsAvailable;
	}

	void Flight::reserveSeat(int seatNumber, const string& firstName, const string& lastName, const string& passportNumber) {
		if (seatNumber <= 0 || seatNumber > mSeatsAvailable ||
			mReservedSeats.find(seatNumber) != mReservedSeats.end()) {
			throw logic_error("This seat is unavailable.");
		}

		Passenger passenger(firstName, lastName, passportNumber);
		mReservedSeats[seatNumber] = passenger;
	}

	void Flight::displayFlightInfo() const {
		cout << "Departure Airport: " << mDepartureAirport << endl;
		cout << "Departure Date: " << mDepartureDate << endl;
		cout << "Departure Time: " << mDepartureTime << endl;
		cout << "Arrival Airport: " << mArrivalAirport << endl;
		cout << "Arrival Date: " << mArrivalDate << endl;
		cout << "Arrival Time: " << mArrivalTime << endl;
		cout << "Seats: 1~" << mSeatsAvailable << endl;

		cout << "Passengers: " << endl;
		for (auto it = mReservedSeats.begin(); it != mReservedSeats.end(); it++)
		{
			cout << "Reserver seat number: " << it->first << endl;
			it->second.displayInfo();
		}

		cout << endl;
	}

	void Flight::displayTicketInfo(const string passportNumber) const {
		for (auto it = mReservedSeats.begin(); it != mReservedSeats.end(); it++)
		{
			if (it->second.getPassportNumber() == passportNumber) {
				it->second.displayInfo();
				cout << "Flight" << mFlightNumber << endl;
				cout << "Departure Airport: " << mDepartureAirport << endl;
				cout << "Departure Date: " << mDepartureDate << endl;
				cout << "Departure Time: " << mDepartureTime << endl;
				cout << "Arrival Airport: " << mArrivalAirport << endl;
				cout << "Arrival Date: " << mArrivalDate << endl;
				cout << "Arrival Time: " << mArrivalTime << endl;
				cout << endl;
				return;
			}
		}

		throw logic_error("Booking not found.");
	}
}
