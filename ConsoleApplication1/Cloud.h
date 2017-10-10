// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

//#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <vector>
#include <string>

class Cloud {

public:
	int addSensor(int, int, int, int);
	void printUnits();
	void prepare();
	void menu();
	int id_to_int();
	int removeSensor();
	//void menu(int);
	//void test();

};


class Sensor {

public:
	int tmpCounter = 1;
	int doorCounter = 1;
	int irCounter = 1;
	int counter = 3;
	std::string name;
	int value;
	int status;
	std::string id;
	Sensor();
	//void addSensor();
	//void test();

};

class Adv_sensor : public Sensor {

public:
	std::string param;
	int param_value;
	int reading;
	Adv_sensor();
};


class CPanel : public Cloud {
	int serial;
public:
	//Constructor
	CPanel();
	//Member functions
	void printCPanel();
	int menuCPanel();
	void sensorParam(int);
	void Set_Status();
	

};
enum Status { OFF, ON };

extern std::vector<Sensor> sensor;
extern std::vector<Adv_sensor> adv_sensor;



// TODO: reference additional headers your program requires here