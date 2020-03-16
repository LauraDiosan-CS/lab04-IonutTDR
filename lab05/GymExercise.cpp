#include <cstring>
#include "GymExercise.h"

GymExercise::GymExercise()
{
	this->name = NULL;
	this->noOfSeries = 0;
	this->noOfReps = 0;
	this->weightKg = 0;
}

GymExercise::GymExercise(char* name2, int noOfSeries, int noOfReps, int weightKg)
{
	this->name = new char[strlen(name2) + 1];
	strcpy(this->name, name2);
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
	strcpy(this->name, g.name);
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
