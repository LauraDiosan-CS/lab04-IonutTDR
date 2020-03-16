#include "Repo.h"
#include "GymExercise.h"


Repo::Repo()
{
    this->n = 0;
}

Repo::~Repo()
{
    this->n = 0;
}

void Repo::addGymExercise(GymExercise g)
{
    this->gyms[this->n++] = g;
}

int Repo::getSize()
{
    return this->n;
}

GymExercise* Repo::getAll()
{
    return this->gyms;
}
