#include <iostream>
using namespace std;
#include <cstring>
#include <ostream>
#include "GymExercise.h"

GymExercise::GymExercise()
{
	this->name = NULL;
	this->noOfSeries = 0;
	this->noOfReps = 0;
	this->weightKg = 0;
}

GymExercise::GymExercise(const char* name2, int noOfSeries, int noOfReps, int weightKg)
{
	this->name = new char[strlen(name2) + 1];
	strcpy_s(this->name, strlen(name2)+1, name2);
	this->noOfSeries = noOfSeries;
	this->noOfReps = noOfReps;
	this->weightKg = weightKg;
}

GymExercise::~GymExercise()
{
	if (this->name) {
		delete[] this->name;
		this->name = NULL;
	}
}

GymExercise::GymExercise(const GymExercise& g)
{
	this->name = new char[strlen(g.name) + 1];
	strcpy_s(this->name, strlen(g.name) + 1, g.name);
	this->noOfSeries = g.noOfSeries;
	this->noOfReps = g.noOfReps;
	this->weightKg = g.weightKg;
}


char* GymExercise::getName()
{
	return this->name;
}

int GymExercise::getReps()
{
	return this->noOfReps;
}

int GymExercise::getSeries()
{
	return this->noOfSeries;
}

int GymExercise::getWeight()
{
	return this->weightKg;
}

void GymExercise::setName(char* newName)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(newName) + 1];
	strcpy_s(this->name, strlen(newName) + 1, newName);
}

void GymExercise::setSeries(int newNr)
{
	this->noOfSeries = newNr;
}

void GymExercise::setReps(int newNr)
{
	this->noOfReps = newNr;
}

void GymExercise::setWeight(int newNr)
{
	this->weightKg = newNr;
}

GymExercise& GymExercise::operator=(const GymExercise& g)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(g.name) + 1];
	strcpy_s(this->name, strlen(g.name) + 1, g.name);
	this->noOfSeries = g.noOfSeries;
	this->noOfReps = g.noOfReps;
	this->weightKg = g.weightKg;
	return *this;
}

bool GymExercise:: operator==(const GymExercise& g) 
{
	return strcmp(this->name, g.name) == 0 && this->noOfSeries == g.noOfSeries && this->noOfReps == g.noOfReps && this->weightKg == g.weightKg;
}

ostream& operator<<(ostream& os, const GymExercise& g)
{
	os << g.name << " " << g.noOfSeries << " " << g.noOfReps << " " << g.weightKg << endl;
	return os;
}