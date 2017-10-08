// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>



std::vector<Sensor> sensor;
std::vector<adv_Sensor> adv_sensor;

//Test

int tmpCounter = 1;
int doorCounter = 1;
int irCounter = 1;
int counter = 3;




int main()
{
	CPanel panel;

	Cloud cloud;
	std::string val;
	cloud.prepare();


	while (true) {


		cloud.menu(counter);
		panel.printCPanel();
		panel.menuCPanel();

	}
	return 0;
}