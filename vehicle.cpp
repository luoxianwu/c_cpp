
/*
Provide a way to represent vehicles:

    • Each vehicle should have a vehicle identification number (VIN), manufacturer (such as BMW, Ford, etc.), model, year, and color. 
      Other than the manufacturer, these can be simple primitive types (e.g., int, string, enum). 
      We are not designing an actual vehicle inventory system!
    • A vehicle should contain manufacturer information for the vehicle, consisting of a manufacturer name and a country.
    • A vehicle should be able to return a string representation of itself that consists of the color, year, manufacturer name, model, and VIN.
        ◦ If the vehicle is a BMW, then the string must end with “© BMW AG, Munich, Germany”.
        ◦ If the vehicle is a Tesla, then the string must end with “(Batteries Included!)”.

Create a repository with the following functionality:

    • A way to add a vehicle to, and remove a vehicle from, the inventory.
    • A way to fetch a list of vehicles that match a specified year.
    • A way to fetch a list of vehicles that of a given manufacturer.

When executed, the application should populate the inventory with a some example vehicles, and then print to the console:

    • A list of all the vehicles in the inventory.
    • A list of vehicles from a specific year or manufacturer.
*/
#include <iostream>
#include <list>
using namespace std;

enum class VehicleColor{ Red, Green, Blue};

class Vehicle {
    public:
    string m_VIN;
    string m_manufacturer;
    string m_model;
    unsigned int  m_year;
    string m_name;
    VehicleColor m_color;
    string m_note;
    public:
    Vehicle( string VIN, string manufacturer, string model, unsigned int  year, string name, VehicleColor color )
    :m_VIN(VIN), m_manufacturer(manufacturer), m_model(model), m_year(year), m_name(name), m_color(color) {
        if( m_manufacturer == "BMW" )
            //m_note = “BMW AG, Munich, Germany”;
            m_note = "© BMW AG, Munich, Germany";   
        else if(m_manufacturer == "Tesla" )
            //m_note = “\(Batteries Included!\)”;
            m_note = "(Batteries Included!)";
    }
    
    void show_info(){
        cout << "-------------------" << endl;
        cout << "Vehicle VIN: " << m_VIN << endl;
        cout << "Manufacturer: " << m_manufacturer << endl;
        cout << "Model: " << m_model << endl;
        cout << "Year: " << m_year << endl;
        cout << "Name: " << m_name << endl;
        //cout << "Color: " << m_color << endl;
        cout << "Color: ";
        switch( m_color )
        {
            case VehicleColor::Red:
            cout << "Red" << endl;
            break;
            case VehicleColor::Green:
            cout << "Green" << endl;
            break;
            case VehicleColor::Blue:
            cout << "Blue" << endl;
            break;
        }
        cout << m_note << endl;
        cout << "-------------------" << endl;
    }
};

class VehicleRepo{
    list<Vehicle> Vehicles;
    list<Vehicle> VehiclesBy;
    public:
    int addVehicle( Vehicle );
    list<Vehicle>* fetchVehile( string manufacturer );
    list<Vehicle>* fetchVehile( unsigned int year );
    void showRepo(void);

};

int VehicleRepo::addVehicle(Vehicle v){
    Vehicles.push_back(v);
    return 0;
}
list<Vehicle>* VehicleRepo::fetchVehile( string manufacturer ){
    VehiclesBy.clear();
    list<Vehicle>::iterator it;
    for( it = Vehicles.begin(); it != Vehicles.end(); it++ )
        if( it->m_manufacturer == manufacturer ){
            VehiclesBy.push_back(*it);
            it = Vehicles.erase(it); // !!! erase return next valid iterator
        }
    return &VehiclesBy;           
}

list<Vehicle>* VehicleRepo::fetchVehile( unsigned int year ){
    VehiclesBy.clear();
    list<Vehicle>::iterator it;
    for( it = Vehicles.begin(); it != Vehicles.end(); it++ )
        if( it->m_year == year ){
            VehiclesBy.push_back(*it);
            it = Vehicles.erase(it); // !!! erase return next valid iterator
        }
    return &VehiclesBy;    
}

void VehicleRepo::showRepo( void ){
    for( auto it = Vehicles.begin(); it != Vehicles.end(); ++it )
        it->show_info();
    return;
}


int main() {

    Vehicle v[] = {
        Vehicle("12345678VIN", "Ford", "750", 1990, "highlander", VehicleColor::Red ),
        Vehicle("12345678VIN", "Hydai","750", 1991, "highlander", VehicleColor::Red ),
        Vehicle("12345678VIN", "Ford", "750", 1992, "highlander", VehicleColor::Green ),
        Vehicle("12345678VIN", "BMW", "750",  1992, "highlander", VehicleColor::Green ),
        Vehicle("12345678VIN", "Tesla", "15", 1991, "highlander", VehicleColor::Green )

    };
    #define countof(v) (sizeof(v)/sizeof(Vehicle))


    VehicleRepo repository;

    for( int i = 0; i < countof(v); i++ )
        repository.addVehicle(v[i]);

    cout << "==== vehicles repository: ==== \n";
    repository.showRepo();

    cout << "==== fetch Ford vehicles: ==== \n";
    list<Vehicle> *t = repository.fetchVehile("Ford");

    for( auto v : *t)
        v.show_info();


    cout << "==== fetch 1991 year vehicles: ==== \n";
    t = repository.fetchVehile( 1991 );

    for( auto v : *t)
        v.show_info();

    cout << "==== vehicles repository: ==== \n";
    repository.showRepo();

    return 0;
}

