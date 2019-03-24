#pragma once
#include "pch.h"
#include <vector>
#include <iostream>
#include <stdexcept>

#include "Database.h"

using namespace std;

namespace FlightBookingSystem {

	void Database::addFlight(const string& flightNumber, const string& departureAirport,
		const string& departureDate, const string& departureTime, const string& arrivalAirport, 
		const string& arrivalDate, const string& arrivalTime, int seatsAvailable) {

		Flight flight(flightNumber, departureAirport, departureDate, departureTime,
			arrivalAirport, arrivalDate, arrivalTime, seatsAvailable);
		mFlights.push_back(flight);
	}

	bool Database::isFlightScheduled(const string& flightNumber) {
		for (auto& flight : mFlights) {
			if (flight.getFlightNumber() == flightNumber) {
				return true;
			}
		}

		return false;
	}

	Flight& Database::getFlightInfo(const string& flightNumber) {
		for (auto& flight : mFlights) {
			if (flight.getFlightNumber() == flightNumber) {
				return flight;
			}
		}

		throw logic_error("No flight found.");
	}

	void Database::displayAllFlights() const {
		for (const auto& flight : mFlights) {
			flight.displayFlightInfo();
		}
	}
}