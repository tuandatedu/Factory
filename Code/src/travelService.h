#ifndef F6B5D65E_852A_4768_845D_BB9968DC2DCA
#define F6B5D65E_852A_4768_845D_BB9968DC2DCA
#include "main.h"

class TravelService {
public:
    virtual string getInfo() const = 0;
    virtual bool book(int groupSize) = 0;
    virtual ~TravelService() {}
};

class Itinerary {
public:
    string day;
    vector<string> activities;
};

class IncludedService {
public:
    string name;
    string description;
};

class DaLat : public TravelService {
private:
    string tourName;
    string tourCode;
    string departureDate;
    string transportation;
    string hotel;
    double tourPrice;
    vector<Itinerary> itinerary;
    vector<IncludedService> includedServices;
    string contact;

    int maxGroup;
    int booked;
public:
    DaLat();
    ~DaLat();
    DaLat(const DaLat& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class SapaHaGiang : public TravelService {
private:
    string tourName;
    string tourCode;
    string departurePoint;
    double tourPrice;
    vector<Itinerary> itinerary;
    vector<IncludedService> includedServices;
    string contact;

    int maxGroup;
    int booked;
public:
    SapaHaGiang();
    ~SapaHaGiang();
    SapaHaGiang(const SapaHaGiang& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class HaLongTuanChau : public TravelService {
private:
    string tourName;
    string tourCode;
    string departurePoint;
    string accommodation;
    double tourPrice;
    vector<Itinerary> itinerary;
    vector<IncludedService> includedServices;
    string contact;
    
    int maxGroup;
    int booked;
public:
    HaLongTuanChau();
    ~HaLongTuanChau();
    HaLongTuanChau(const HaLongTuanChau& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class DaNang : public TravelService {
private:
    string tourName;
    string tourCode;
    string departurePoint;
    string hotel;
    double tourPrice;
    vector<Itinerary> itinerary;
    vector<IncludedService> includedServices;
    string contact;

    int maxGroup;
    int booked;
public:
    DaNang();
    ~DaNang();
    DaNang(const DaNang& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class PhuQuoc : public TravelService {
private:
    string tourName;
    string tourCode;
    string departurePoint;
    string hotel;
    double tourPrice;
    vector<Itinerary> itinerary;
    vector<IncludedService> includedServices;
    string contact;

    int maxGroup;
    int booked;
public:
    PhuQuoc();
    ~PhuQuoc();
    PhuQuoc(const PhuQuoc& other);
    string getInfo() const override;
    bool book(int groupSize) override;
};

class FlightTicketService : public TravelService {
public:
    FlightTicketService();
    string getInfo() const override;
};

class BusTicketService : public TravelService {
public:
    BusTicketService();
    string getInfo() const override;
};

class TrainTicketService : public TravelService {
public:
    TrainTicketService();
    string getInfo() const override;
};

#endif /* F6B5D65E_852A_4768_845D_BB9968DC2DCA */
