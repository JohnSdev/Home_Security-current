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

		}

		else if (val[0] == 'd' || 'i' || 't') {
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
			//cloud.printUnits();

		}


		else {
			std::cout << "ERROR WRONG INPUT" << std::endl;
		}

	}
	return 0;
}