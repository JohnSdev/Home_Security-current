
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
	param = "Max temp alam";
	param_value = 23;
}

int Cloud::id_to_int() {
	std::cout << "\t\tType the ID of the sensor:" << std::endl;
	int id;
	std::string val;
	int going = 1;
	while (going) {
	std::cin.clear();
	std::cin >> val;
	
	
		if (val[0] == 'a') {
			std::string temp = val;
			for (int i = 0; i < adv_sensor.size(); i++) {
				if (adv_sensor[i].id == temp) {
					id = i;
					going = 0;
				}

			}
		}
		else {
			std::cout << "ERROR CHOOSE EXISTSING SENSOR!"<< std::endl;
		}
	}
	return id;
}

int Cloud::removeSensor() {
	
		std::string temp;
		std::string compid;
		/*int temp;
		std::string compid;
		std::cout << "Which component do you want to remove?" << std::endl;
		std::cout << "1. Advanced Sencor" << std::endl;
		std::cout << "2.Standard Sensors" << std::endl;
		std::cout << "3.Go back to Cloud" << std::endl;
		while (true) {
		std::cin.clear();
		std::cin >> temp;
		if (temp == 1)
		{
		std::cout << "You have the following sensors" << std::endl;
		if (adv_sensor.size() == 0)
		{
		std::cout << "You do not have anny advanced sensors" << std::endl;
		return 3;

		}
		else
		{

		for (int i = 0; i < adv_sensor.size(); i++) {
		std::cout << adv_sensor[i].id << std::endl;
		}
		}
		std::cout << "Witch id do you want to remove? Write 'exit' to return to Cloud." << std::endl;
		std::cin.clear();
		std::cin >> compid;
		if (compid == "exit") {
		return 3;
		}
		for (int i = 0; i < adv_sensor.size(); i++)
		if (adv_sensor[i].id == compid) {
		adv_sensor.erase(adv_sensor.begin() + i);
		std::cout << "Sensor:" << compid << " was succefully deleted" << std::endl;
		return 0;
		}


		std::cout << "component A" << compid << " was succefully deleted" << std::endl;

		}
		if (temp == 2)
		{
		std::cout << "You have the following standard sensors" << std::endl;
		if (sensor.size() == 0)
		{
		std::cout << "You do not have anny sensors" << std::endl;
		return 3;

		}
		else
		{

		for (int i = 0; i < sensor.size(); i++) {
		std::cout << sensor[i].id  << std::endl;
		}
		}
		std::cout << "Witch id do you want to remove?Write 'exit' to return to Cloud." << std::endl;
		std::cin.clear();
		std::cin >> compid;
		if (compid == "exit") {
		return 3;
		}
		for (int i = 0; i < sensor.size(); i++)
		if (sensor[i].id == compid) {
		sensor.erase(sensor.begin() + i);
		return 1;
		}
		}

		if (temp == 3) {
		return 3;
		}
		else
		{
		std::cout << "Print a valid input!" << std::endl;
		}
		}*/
	
		std::cout << "which component do you want to delete? or Print 'exit' to return to cloud" << std::endl<<std::endl;
		while (true) {

			for (int i = 0; i < adv_sensor.size(); i++) {
				std::cout << adv_sensor[i].id << std::endl;
			}
			for (int i = 0; i < sensor.size(); i++) {
				std::cout << sensor[i].id << std::endl;
			}
			std::cout << std::endl;
			std::cin.clear();
			std::cin >> temp;
			if (temp[0] == 'd' || 'i')
			{

				for (int i = 0; i < sensor.size(); i++)
					if (sensor[i].id == temp) {
						sensor.erase(sensor.begin() + i);
						return 1;

					}
				if (temp[0] == 'a')
				{

					for (int i = 0; i < adv_sensor.size(); i++)
						if (adv_sensor[i].id == temp) {
							adv_sensor.erase(adv_sensor.begin() + i);
							return 0;

						}
				}

				else
				{
					std::cout <<std::endl<< "Wrong input try again. print 'exit' if you want to return to cloud" << std::endl;
					
				}

			}
			else
			{
				std::cout << "Print a valid input!" << std::endl;
			}
		}
	}
	


	



int Cloud::addSensor(int counter, int tmpCounter, int doorCounter, int irCounter) {

	int val;
	std::cout << "Choose component type?" << std::endl;
	std::cout << "1) Advance-sensor." << std::endl;
	std::cout << "2) Smart door/window." << std::endl;
	std::cout << "3) Movement detector(IR)" << std::endl;

	std::cin >> val;

	if (val == 1) {
		tmpCounter++;
		adv_sensor.resize(tmpCounter);

		//add_tmp();
		std::string tempd = "a";
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
		adv_sensor[tmpCounter - 1].param_value = 35;
		adv_sensor[tmpCounter - 1].reading = random;

		int chooser;
		std::cout << "What does your sensor measure?" << std::endl;
		std::cout << "1)Temperature\n2)Humidity\n3)Shock" << std::endl;
		std::cin >> chooser;
		if (chooser == 1) {
			adv_sensor[tmpCounter - 1].param = "Temp alarm     ";
		}
		if (chooser == 2) {
			adv_sensor[tmpCounter - 1].param = "Humidity alarm ";
		}
		if (chooser == 3) {
			adv_sensor[tmpCounter - 1].param = "Vibration alarm";
		}


		//std::cout << "Är den på?" << std::endl;
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
		//std::cout << "Är den på?" << std::endl;
		sensor[counter - 1].status = 1;
		return 2;
	}/*
	if (val == 3) {
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
		return 3;
	}*/
	if (val == 3) {
		counter++;
		sensor.resize(counter);

		std::string irstring = "i"; //a
		std::string counterString = std::to_string(irCounter);//a

		std::cin.ignore();
		std::cout << "Tell some info about it(e.g IR sensor downstairs)" << std::endl;
		std::string temp;
		std::cin >> temp;
		irstring += counterString;//a
		sensor[counter - 1].name = temp;
		sensor[counter - 1].id = irstring; //a

		std::cin.ignore();
		//std::cout << "Är den på?" << std::endl;
		sensor[counter - 1].status = 1;
		return 3;
	}
}

void Cloud::printUnits()
{
	std::cout << "ID:\tStatus\t\tInfo:" << std::endl;
	for (int i = 0; i < sensor.size(); i++) {

		std::cout << sensor[i].id << "\t";
		if (sensor[i].id[0] == 'a' || sensor[i].id[0] == 'i') {
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

		//std::cout << sensor[i].value << "\t\t";
		std::cout << sensor[i].name << "\t" << std::endl;

	}
	std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "\t\tADVANCED SENSORS:" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << "ID:\tStatus:\t\tReading:\tParameter:\t\tParamValue:\tInfo:\t" << std::endl;
	for (int i = 0; i < adv_sensor.size(); i++) {
		std::cout << adv_sensor[i].id << "\t";
		if (adv_sensor[i].status == 1) {
			std::cout << "ON" << "\t\t";
		}
		else {
			std::cout << "OFF" << "\t\t";
		}
		std::cout << adv_sensor[i].reading << "\t\t";
		std::cout << adv_sensor[i].param << "\t\t";
		std::cout << adv_sensor[i].param_value << "\t\t";
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
	adv_sensor[0].id = "a1";
	adv_sensor[0].status = 1;
	adv_sensor[0].param = "Temp alarm     ";
	adv_sensor[0].reading = 23;
	adv_sensor[0].param_value = 35;
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
	std::cout << "OR Write ID to turn sensor on/off or close/open door. " << std::endl;
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
		
		std::cout << "\t\t\t   ____________________________________________" << std::endl;
		std::cout << "\t\t\t\t      Control Panel Interface" << std::endl;
		std::cout << "\t\t\t   ____________________________________________\n" << std::endl << std::endl;/*
		std::cout << "\t\tID:\tStatus:\t\tValue:\t\tInfo:" << std::endl;
		for (int i = 0; i < sensor.size(); i++) {

			std::cout << "\t\t" << sensor[i].id << "\t";
			if (sensor[i].id[0] == 'a' || sensor[i].id[0] == 'i') {
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

		}*/
		std::cout << "\t\t\t________________________________________________" << std::endl;
		std::cout << "\t\t\t\t\tADVANCED SENSORS:" << std::endl;
		std::cout << "\t\t\t________________________________________________\n" << std::endl;
		std::cout << "\t\tID:\tStatus:\t\tParameter:\tParamValue:\tInfo:\t" << std::endl;
		for (int i = 0; i < adv_sensor.size(); i++) {
			std::cout << "\t\t" << adv_sensor[i].id << "\t";
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
		std::cout << std::endl;
	
}

	/*
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
	*/







int CPanel::menuCPanel() {
	int i;
	int id;
	char choice;
	int loop = 1;
	while (loop == 1) {
		std::string sensor;


		std::cout << "\n\n\t\t|| Control Panel. Edit sensor and component paramerters. ||\n\n" << std::endl;
		std::cout << "\t\t(0) Choose sensor\n \t\t(1) Exit to Cloud menu\n" << std::endl;
		std::cin >> choice;
		if (choice == 48) {
			id = id_to_int();
			sensorParam(id);
			loop = 0;
		}
		else if (choice == 49) {
			loop = 0;
		}
		else if (choice != 48 || choice != 49) {
			std::cout << "\t\t---- == = ERROR == = ----Invalid option!!!Select 0 - 1 \n\n" << std::endl;
			loop = 1;
		}
		
	}


	// Cloud func
	return 0;
}

void CPanel::sensorParam(int x) {
	// Return från int_to_vector()
	std::cout << "\t\tSelected sensor: " << adv_sensor[x].id << "\tInfo: " << adv_sensor[x].name << "\n" << std::endl;

	std::cout << "\t\tParameter: " << adv_sensor[x].param << "\tValue: " << adv_sensor[x].param_value << std::endl;
	std::cout << "\t\tEnter new Value: " << std::endl;
	int new_value;
	std::cin >> new_value;
	adv_sensor[x].param_value = new_value;
	printCPanel();
	menuCPanel();
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







