#pragma once
#include "Service.h"
class UserInterface {
private:
	Service s;
public:
	UserInterface();
	void add();
	void remove();
	void update();
	void getAll();
	void run();
	~UserInterface();
};
void printMenu();