
#include "stdafx.h"
#include "Cloud.h"
#include <time.h> 

Sensor::Sensor() {
	value = 0;
	name = "empty";
	status = 0;
	id = "x1";

}

Adv_sensor::Adv_sensor() {
	param = "Temperature";
	param_value = 23;
}

int Cloud::id_to_int() {
	std::cout << "Type the ID of the sensor:" << std::endl;
	int id;
	std::string val;
	std::cin.clear();
	std::cin >> val;

	if (val[0] == 'd' || 'i') {
		std::string temp = val;

		for (int i = 0; i < sensor.size(); i++) {
			if (sensor[i].id == temp) {
				id = i;
			}

		}
	}

	if (val[0] == 't') {
		std::string temp = val;
		for (int i = 0; i < adv_sensor.size(); i++) {
			if (adv_sensor[i].id == temp) {
				id = i;
			}

		}
	}
	return id;
}


int Cloud::addSensor(int counter, int tmpCounter, int doorCounter, int irCounter) {

	int val;
	std::cout << "Vilken enhet vill ni l�gga till?" << std::endl;
	std::cout << "1) Tmp-sensor." << std::endl;
	std::cout << "2) Smart door." << std::endl;
	std::cout << "3) Movement detector" << std::endl;

	std::cin >> val;

	if (val == 1) {
		tmpCounter++;
		adv_sensor.resize(tmpCounter);

		//add_tmp();
		std::string tempd = "t";
		std::string tmpString = std::to_string(tmpCounter);

		tempd += tmpString;

		//	std::cout << tempd;
		std::cin.ignore();
		std::cout << "Tell some info about it(e.g tmp sensor downstairs)" << std::endl;
		std::string temp;
		std::cin >> temp;
		adv_sensor[tmpCounter - 1].name = temp;
		std::cout << tempd;
		adv_sensor[tmpCounter - 1].id = tempd;
		std::cout << adv_sensor[tmpCounter - 1].id;
		srand(time(NULL));
		std::cin.ignore();
		int random = rand() % 25 + 5;
		adv_sensor[tmpCounter - 1].param_value = random;
		int chooser;
		std::cout << "What does your sensor measure?" << std::endl;
		std::cout << "1)Temperature\n2)Humidity\n3)Pressure" << std::endl;
		std::cin >> chooser;
		if (chooser == 1) {
			adv_sensor[tmpCounter - 1].param = "Temperature";
		}
		if (chooser == 2) {
			adv_sensor[tmpCounter - 1].param = "Humidity";
		}
		if (chooser == 3) {
			adv_sensor[tmpCounter - 1].param = "Pressure";
		}


		//std::cout << "�r den p�?" << std::endl;
		adv_sensor[tmpCounter - 1].status = 1;
		return 1;
	}

	if (val == 2) {
		counter++;
		Sensor s1;
		sensor.push_back(s1);
		std::string doorString = "d";
		std::string counterString = std::to_string(doorCounter);

		//add_door();
		std::cin.ignore();
		std::cout << "Tell some info about it(e.g front door)" << std::endl;
		std::string temp;
		std::cin >> temp;

		doorString += counterString;
		sensor[counter - 1].name = temp;
		sensor[counter - 1].id = doorString;
		std::cin.ignore();
		//std::cout << "�r den p�?" << std::endl;
		sensor[counter - 1].status = 1;
		return 2;
	}
	if (val == 3) {
		counter++;
		sensor.resize(counter);

		std::cin.ignore();
		std::cout << "Tell some info about it(e.g IR sensor downstairs)" << std::endl;
		std::string temp;
		std::cin >> temp;
		sensor[counter - 1].name = temp;
		std::cin.ignore();
		//std::cout << "�r den p�?" << std::endl;
		sensor[counter - 1].status = 1;
		return 3;
	}

}

void Cloud::printUnits()
{
	std::cout << "ID:\tStatus:\t\tValue:\t\tInfo:" << std::endl;
	for (int i = 0; i < sensor.size(); i++) {

		std::cout << sensor[i].id << "\t";
		if (sensor[i].id[0] == 't' || sensor[i].id[0] == 'i') {
			//std::cout << sensor[i].status << "\t";
			if (sensor[i].status == 1) {
				std::cout << "ON" << "\t\t";
			}
			else {
				std::cout << "OFF" << "\t\t";
			}
		}
		if (sensor[i].id[0] == 'd') {
			if (sensor[i].status == 1) {
				std::cout << "Open" << "\t\t";
			}
			else {
				std::cout << "Closed" << "\t\t";
			}
		}

		std::cout << sensor[i].value << "\t\t";
		std::cout << sensor[i].name << "\t" << std::endl;

	}
	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\t\tADVANCED SENSORS:" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "ID:\tStatus:\t\tParameter:\tParamValue:\tInfo:\t" << std::endl;
	for (int i = 0; i < adv_sensor.size(); i++) {
		std::cout << adv_sensor[i].id << "\t";
		if (adv_sensor[i].status == 1) {
			std::cout << "ON" << "\t\t";
		}
		else {
			std::cout << "OFF" << "\t\t";
		}
		std::cout << adv_sensor[i].param << "\t\t";
		std::cout << adv_sensor[i].param_value << "\t";
		std::cout << adv_sensor[i].name << "\t" << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
}

void Cloud::prepare()
{
	sensor.resize(2);

	sensor[0].name = "MainDoor";
	sensor[1].name = "IR-sensor upstairs";
	sensor[0].value = 1;
	sensor[1].value = 0;
	sensor[0].status = 0;
	sensor[1].status = 0;
	sensor[0].id = "d1";
	sensor[1].id = "i1";

	adv_sensor.resize(1);
	adv_sensor[0].id = "t1";
	adv_sensor[0].status = 1;
	adv_sensor[0].param = "Temperature";
	adv_sensor[0].param_value = 23;
	adv_sensor[0].name = "Temperature in Cellar.";


}

void Cloud::menu()
{
	std::string val;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Welcome to your personal CloudHome Interface" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
	printUnits();
	std::cout << "1) Go to dashboard. " << std::endl;
	std::cout << "2) Add Unit/sensor" << std::endl;
	std::cout << "3) Remove sensor." << std::endl;
	std::cout << "OR Write ID to turn on/off. " << std::endl;
}
/*if (val[0] == 'd' || 'i' || 't') {
std::string temp = val;
for (int i = 0; i < sensor.size(); i++) {
if (sensor[i].id == temp) {
sensor.erase(sensor.begin() + i);
}
}
printUnits();
}*/

enum Status { OFF, ON };

CPanel::CPanel() { //Default constructor
	serial = 0001;
}


void CPanel::printCPanel() {
	std::cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\t\t\t\t   Control Panel Interface" << std::endl;
	std::cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl << std::endl;
	std::cout << "\tID" << "\t\t\tSTATUS" << "\t\tINFO" << "\t\tPARAMETER" << "\tVALUE" << "\t\tNAME" << std::endl;
	std::cout << "_______________________________________________________________________________________\n" << std::endl;
	for (int i = 0; i < sensor.size(); i++) { //Print normal sensors
		std::cout << "\t" << sensor[i].id << "\t\t" << "\t\t" << sensor[i].status << "\t\t"
			<< sensor[i].value << sensor[i].name << std::endl;
	}
	for (int i = 0; i < adv_sensor.size(); i++) { //Print advanced sensors
		std::cout << "\t" << adv_sensor[i].id << "\t\t" << adv_sensor[i].name << "\t\t" << adv_sensor[i].status << "\t\t"
			<< adv_sensor[i].value << adv_sensor[i].param << adv_sensor[i].param_value << std::endl;
	}

}





void CPanel::menuCPanel() {
	int i;
	int id;
	int choice;
	std::string sensor;


	std::cout << "\n\n\t\t|| Control Panel. Edit sensor and component paramerters. ||\n\n" << std::endl;
	std::cout << "\t\t(0) Choose sensor\n \t\t(1) Exit to Cloud menu\n" << std::endl;
	std::cin >> choice;
	if (choice == 0) {
		id = id_to_int();
		sensorParam(id);
	}

	//else if (choice != "0" || choice != "1") {
	//	std::cout << "\t\t---- == = ERROR == = ----Invalid option!!!Select 0 - 1 \n\n" << std::endl;
	//}


	// Cloud func
	return;
}

void CPanel::sensorParam(int x) {
	// Return fr�n int_to_vector()
	std::cout << "\t\tSelected sensor: " << adv_sensor[x].id << "\tInfo: \n" << adv_sensor[x].name << std::endl;

	std::cout << "\t\tParameter: " << adv_sensor[x].param << "\tValue: " << adv_sensor[x].param_value << std::endl;
	std::cout << "\t\tEnter new Value: " << std::endl;
	int new_value;
	std::cin >> new_value;
	adv_sensor[x].param_value = new_value;

}


void CPanel::Set_Status() {
	int input, input_sensor;
	std::cout << "choose sensor: " << std::endl;
	std::cin >> input_sensor;
	std::cout << "Sensor :  " << input_sensor << std::endl;

	std::cin.clear();
	std::cout << "Set status to ON: " << std::endl;
	std::cin >> input;
	sensor[input_sensor].status = input;


}







