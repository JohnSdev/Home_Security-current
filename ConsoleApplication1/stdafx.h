// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <vector>

class Cloud {

public:
	void addSensor(int);
	void printUnits();
	void prepare();
	void menu(int);
	int id_to_int(); //////// NEW
	//void menu(int);
	//void test();

};



class Sensor {

public:

	std::string name;
	std::string info;  ////NEW
	int value;
	int status;
	std::string id;
	Sensor();
	//void addSensor();
	//void test();

};


class adv_Sensor : public Sensor {
public:
	adv_Sensor();
	std::string param;

	int param_value;
	//funk_new_sensor()
	//skapar en "underklass", ärver allt från översta
};

class CPanel : public Cloud {
	int serial;
public:
	//Constructor
	CPanel();
	//Member functions
	void printCPanel();
	void menuCPanel();
	void sensorParam(int);
	void Set_Status();

};

extern std::vector<Sensor> sensor;
extern std::vector<adv_Sensor> adv_sensor;



// TODO: reference additional headers your program requires here
