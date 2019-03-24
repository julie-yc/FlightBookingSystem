#pragma once
#include <vector>

#include "Flight.h"

using namespace std;

namespace FlightBookingSystem {
	
	class Database {
	public:
		void addFlight(const string& flightNumber, const string& departureAirport, const string& departureDate,
			const string& departureTime, const string& arrivalAirport, const string& arrivalDate, const string& arrivalTime,
			int seatsAvailable);

		bool isFlightScheduled(const string& flightNumber);
		Flight& getFlightInfo(const string& flightNumber);
		void displayAllFlights() const;

	private:
		std::vector<Flight> mFlights;

	};
}
