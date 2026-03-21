#include <bits/stdc++.h>
using namespace std;

class Engine
{
	public:
		virtual void start() = 0;
		virtual void stop() = 0;
		~Engine() {}
};

class PetrolEngine : public Engine
{
	public:
		void start() override {
			cout << "Petrol Engine Started\n";
		}
		void stop() override {
			cout << "Petrol Engine Stopped\n";
		}
};

class DieselEngine : public Engine
{
	public:
		void start() override {
			cout << "Diesel Engine Started\n";
		}
		void stop() override {
			cout << "Diesel Engine Stopped\n";
		}
};

class CNGEngine : public Engine
{
	public:
		void start() override {
			cout << "CNG Engine Started\n";
		}
		void stop() override {
			cout << "CNG Engine Stopped\n";
		}
};

class Vehicle
{
	protected:
		Engine* engine;
	public:
		Vehicle(Engine* eng) {
			engine = eng;
		}
		virtual void start() = 0;
		virtual void stop() = 0;
		virtual ~Vehicle() {
			delete engine;
		}
};

class SUV : public Vehicle
{
	public:
		SUV(Engine* eng) : Vehicle(eng) {}
		void start() override {
			engine->start();
			cout << "SUV Started\n";
		}
		void stop() override {
			engine->stop();
			cout << "SUV Stopped\n";
		}
};

class Sedan : public Vehicle
{
	public:
		Sedan(Engine* eng) : Vehicle(eng) {}
		void start() override {
			engine->start();
			cout << "Sedan Started\n";
		}
		void stop() override {
			engine->stop();
			cout << "Sedan Stopped\n";
		}
};

class Bolero : public Vehicle
{
	public:
		Bolero(Engine* eng) : Vehicle(eng) {}
		void start() override {
			engine->start();
			cout << "Bolero Started\n";
		}
		void stop() override {
			engine->stop();
			cout << "Bolero Stopped\n";
		}
};


class VehicleFactory 
{
	public:
		static Vehicle* createVehicle(const string& type, const string& engineType) {
			Engine* engine = nullptr;
			if (engineType == "Petrol") {
				engine = new PetrolEngine();
			} else if (engineType == "Diesel") {
				engine = new DieselEngine();
			} else if (engineType == "CNG") {
				engine = new CNGEngine();
			} else {
				throw invalid_argument("Invalid engine type");
			}

			if (type == "SUV") {
				return new SUV(engine);
			} else if (type == "Sedan") {
				return new Sedan(engine);
			} else if (type == "Bolero") {
				return new Bolero(engine);
			} else {
				delete engine; // Clean up the engine if vehicle type is invalid
				throw invalid_argument("Invalid vehicle type");
			}
		}
};

class VehicleController 
{
	public:
		static void startVehicle(Vehicle* vehicle) {
			vehicle->start();
		}
		static void stopVehicle(Vehicle* vehicle) {
			vehicle->stop();
		}
};

int main() {
	try {
		Vehicle* mySUV = VehicleFactory::createVehicle("SUV", "Petrol");
		VehicleController::startVehicle(mySUV);
		VehicleController::stopVehicle(mySUV);
		delete mySUV;
		
		cout << "-----------------------------\n";

		Vehicle* mySedan = VehicleFactory::createVehicle("Sedan", "Diesel");
		VehicleController::startVehicle(mySedan);
		VehicleController::stopVehicle(mySedan);
		delete mySedan;
		
		cout << "-----------------------------\n";

		Vehicle* myBolero = VehicleFactory::createVehicle("Bolero", "CNG");
		VehicleController::startVehicle(myBolero);
		VehicleController::stopVehicle(myBolero);
		delete myBolero;
		
	} catch (const invalid_argument& e) {
		cerr << "Error: " << e.what() << endl;
	}
	return 0;
}