#include "Service.h"
#include "Repo.h"
#include "GymExercise.h"
#include "Operations.h"

Service::Service(){}//constructor implicit
Service::~Service(){}//destructor

/*Construcor prin copiere*/
Service::Service(const Service& s)
{
	this->r = s.r;
}


void Service::addGym(const GymExercise& g)
{
	this->r.addGymExercise(g);
}

void Service::deleteGym(int poz)
{
	this->r.deleteGymExercise(poz);
}

void Service::updateGym(int poz, const char* name, int series, int reps, int weight)
{
	this->r.updateGymExercise(poz, name, series, reps, weight);
}

int Service::getSize()
{
	return this->r.getSize();
}

Service& Service::operator=(const Service& s)
{
	this->r = s.r;
	return *this;
}

GymExercise* Service::getAll()
{
	return this->r.getAll();
}

void Service::gymsByXservice(int X, GymExercise gyms[], int& len)
{
	gymsByX(this->r, X, gyms, len);
}

void Service::deleteGyms5service()
{
	deleteGyms5(this->r);
}