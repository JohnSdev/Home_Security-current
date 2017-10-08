#include "stdafx.h"
#include <iostream>
#include <sstream>

///////////////////////////

//CLOUD



Sensor::Sensor() {
	value = 0;
	name = "empty";
	status = 0;
	id = "t1";
	

}

adv_Sensor::adv_Sensor() {
	value = NULL;
	name = "Bathroom";
	status = 1;
	id = "t1";
	param = "Temperature";
	param_value = NULL;
}

int Cloud::id_to_int() {
	std::cout << "Type the ID of the sensor:" << std::endl;
	int id;
	std::string val;
	std::cin.clear();
	std::cin >> val;
	
	if (val[0] == 'd' || 'i' ) {
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


void Cloud::addSensor(int counter) {

	int val;
	std::cout << "Vilken enhet vill ni lägga till?" << std::endl;
	std::cout << "1) Tmp-sensor." << std::endl;
	std::cout << "2) Smart door." << std::endl;
	std::cout << "3) Movement detector" << std::endl;
	std::cin >> val;


	if (val == 1) {
		//add_tmp();
	//	adv_sensor.resize(counter);
		std::cin.ignore();
		std::cout << "Tell some info about it(e.g tmp sensor downstairs)" << std::endl;
		std::string temp;
		std::cin >> temp;
		adv_sensor[counter - 1].name = temp;
		std::cin.ignore();
		//std::cout << "Är den på?" << std::endl;
		adv_sensor[counter - 1].status = 1;
		//SENSORID = T+RÄKNARE!!!!
	}

	if (val == 2) {
		//add_door();
		counter++;
		sensor.resize(counter);
		std::cin.ignore();
		std::cout << "Tell some info about it(e.g front door)" << std::endl;
		std::string temp;
		std::cin >> temp;
		sensor[counter - 1].name = temp;
		std::cin.ignore();
		//std::cout << "Är den på?" << std::endl;
		sensor[counter - 1].status = 1;
	}
	if (val == 3) {
		//add_ir();
		counter++;
		sensor.resize(counter);
		std::cin.ignore();
		std::cout << "Tell some info about it(e.g IR sensor downstairs)" << std::endl;
		std::string temp;
		std::cin >> temp;
		sensor[counter - 1].name = temp;
		std::cin.ignore();
		//std::cout << "Är den på?" << std::endl;
		sensor[counter - 1].status = 1;
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
	std::cout << std::endl << std::endl << std::endl;
}

void Cloud::prepare()
{
	sensor.resize(2);
	//adv_sensor.resize(1);
	sensor[0].name = "MainDoor";
	sensor[1].name = "IR-sensor upstairs";
	//adv_sensor[0].name = "Temp in cellar";
	sensor[0].value = 1;
	sensor[1].value = 0;
	//adv_sensor[0].value = 10;
	sensor[0].status = 0;
	sensor[1].status = 0;
	//adv_sensor[0].status = 1;
	sensor[0].id = "d1";
	sensor[1].id = "i1";
	//adv_sensor[0].id = "t1";

}

void Cloud::menu(int counter)
{
	std::string val;

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "Welcome to your personal CloudHome Interface" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
	printUnits();
	std::cout << "1) Go to dashboard. " << std::endl;
	std::cout << "2) Add Unit/sensor" << std::endl;
	std::cout << "3) Write ID to turn on/off. " << std::endl;
	std::cin >> val;
	if (val == "1") {
		

	}
	if (val == "2") {
		addSensor(counter);
	}

	if (val[0] == 'd' || 'i' || 't') {
		std::string temp = val;

		for (int i = 0; i < sensor.size(); i++) {
			if (sensor[i].id == temp) {
				if (sensor[i].status == 1) {
					sensor[i].status = 0;
				}
				else {
					sensor[i].status = 1;
				}
			}

		}
		printUnits();


	}
	else {
		std::cout << "ERROR WRONG INPUT" << std::endl;

	}
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
///////////////////////////////////////////////////////////////



//////////////////////////CPANEL


enum Status { OFF, ON };

CPanel::CPanel() { //Default constructor
	serial = 0001;
}


void CPanel::printCPanel() {
	std::cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\t\t\t\t   Control Panel Interface" << std::endl;
	std::cout << "\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << std::endl << std::endl;
	std::cout << "\tID"  << "\t\t\tSTATUS" << "\t\tINFO" << "\t\tPARAMETER" << "\tVALUE" << "\t\tNAME" << std::endl;
	std::cout << "_______________________________________________________________________________________\n" << std::endl;
	for (int i = 0; i < sensor.size() ; i++) { //Print normal sensors
		std::cout << "\t" << sensor[i].id << "\t\t"  << "\t\t" << sensor[i].status << "\t\t"
		<< sensor[i].info << sensor[i].name <<std::endl;
	}
	for (int i = 0; i < adv_sensor.size(); i++) { //Print advanced sensors
		std::cout << "\t" << adv_sensor[i].id << "\t\t" << adv_sensor[i].name << "\t\t" << adv_sensor[i].status << "\t\t"
			<< adv_sensor[i].info << adv_sensor[i].param << adv_sensor[i].param_value << std::endl;
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
		return ;
}

void CPanel::sensorParam(int x) {
	// Return från int_to_vector()
	std::cout << "\t\tSelected sensor: " << adv_sensor[x].id << "\tInfo: \n" << adv_sensor[x].info << std::endl;

	std::cout << "\t\tParameter: " << adv_sensor[x].param << "\tValue: " << adv_sensor[x].param_value << std::endl;
	std::cout << "\t\tEnter new Value: " << std::endl;
	int new_value;
	std::cin >> new_value;
	adv_sensor[x].param_value = new_value;

 }


void CPanel::Set_Status(){
	int input, input_sensor;
	std::cout << "choose sensor: " << std::endl;
	std::cin >> input_sensor;
	std::cout << "Sensor :  " << input_sensor << std::endl;

	std::cin.clear();
	std::cout << "Set status to ON: " << std::endl;
	std::cin >> input;
	sensor[input_sensor].status = input;


}








