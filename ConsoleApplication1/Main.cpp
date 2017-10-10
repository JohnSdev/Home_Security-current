// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Cloud.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

std::vector<Sensor> sensor;
std::vector<Adv_sensor> adv_sensor;
int counter = 2;
int tmpCounter = 1;
int doorCounter = 2;
int irCounter = 2;

int main()
{
	CPanel panel;
	Cloud cloud;
	std::string val;
	cloud.prepare();


	while (true) {
		cloud.menu();
		std::cin >> val;
		if (val == "1") {
			panel.printCPanel();
			panel.menuCPanel();
			//cloud.printCunits();
		}
		else if (val == "2") {
			int countercount = cloud.addSensor(counter, tmpCounter, doorCounter, irCounter);

			if (countercount == 1) {
				tmpCounter++;
			}
			if (countercount == 2) {
				doorCounter++;
				counter++;

			}
			if (countercount == 3) {
				irCounter++;
				counter++;
			}

		}
		else if (val == "3") {
			int whichSensor = cloud.removeSensor();
			
			if (whichSensor == 0) {
				tmpCounter--;
			}
			if (whichSensor == 1) {
				counter--;
			}
			if (whichSensor == 2) {

			}

		}
		else if (val[0] == 'a') {
			std::cout << "TEST";
			std::string temp = val;
			for (int i = 0; i < adv_sensor.size(); i++) {
				if (adv_sensor[i].id == temp) {
					if (adv_sensor[i].status == ON) {
						adv_sensor[i].status = OFF;
					//	std::cout << "TEST";
					}
					else {
					//	std::cout << "TEST";
						adv_sensor[i].status = ON;
					}
				}
			}

		} //
		else if (val[0] == 'd' || 'i' ) {
			std::string temp = val;

			for (int i = 0; i < sensor.size(); i++) {
				if (sensor[i].id == temp) {
					if (sensor[i].status == ON) {
						sensor[i].status = OFF;
					}
					else {
						sensor[i].status = ON;
					}
				}

			}
			//cloud.printUnits();

		} 

		else {
			std::cout << "ERROR WRONG INPUT" << std::endl;
		}

	}
	return 0;
}