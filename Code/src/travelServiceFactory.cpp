#include "travelServiceFactory.h"

// Tour Factory implementation
TourFactory::TourFactory(const string& tourType) 
    : tourType(tourType) {}

TourFactory::TourFactory(const TourFactory& other)
    : tourType(other.tourType) {}

TravelService* TourFactory::createService() const {
    if (tourType == "DaLat") {
        return new DaLat();
    } else if (tourType == "SapaHaGiang") {
        return new SapaHaGiang();
    } else if (tourType == "HaLongTuanChau") {
        return new HaLongTuanChau();
    } else if (tourType == "DaNang") {
        return new DaNang();
    } else if (tourType == "PhuQuoc") {
        return new PhuQuoc();
    } else {
        return nullptr;
    }
}

// Ticket Factory implementation
TicketFactory::TicketFactory(const string& ticketType)
    : ticketType(ticketType) {}

TicketFactory::TicketFactory(const TicketFactory& other) 
    : ticketType(other.ticketType) {}

TravelService* TicketFactory::createService() const {
    if (ticketType == "FlightTicketService") {
        return new FlightTicketService();
    } else if (ticketType == "BusTicketService") {
        return new BusTicketService();
    } else if (ticketType == "TrainTicketService") {
        return new TrainTicketService();
    } else {
        return nullptr;
    }
}