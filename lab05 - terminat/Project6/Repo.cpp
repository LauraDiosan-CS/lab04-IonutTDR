#include "Repo.h"
#include "GymExercise.h"


Repo::Repo()
{
    this->n = 0;
}

Repo::Repo(const Repo& r)
{
    this->n = 0;
    for (int i = 0; i < r.n; i++)
        this->gyms[this->n++] = r.gyms[i];
}

Repo::~Repo()
{
    this->n = 0;
}

void Repo::addGymExercise(const GymExercise& g)
{
    this->gyms[this->n++] = g;
}

int Repo::findGymExercise(GymExercise g)
{
    for (int i = 0; i < this->n; i++)
        if (this->gyms[i] == g)
            return i;
    return -1;
}

void Repo::deleteGymExercise(int poz)
{
    int i = 0;
    for (i = poz + 1; i < this->n; i++)
        this->gyms[i - 1] = this->gyms[i];
    this->n--;

}

void Repo::updateGymExercise(int poz, const char* name, int series, int reps, int weight)
{   
    GymExercise h(name, series, reps, weight);
    this->gyms[poz] = h;
}


int Repo::getSize()
{
    return this->n;
}

GymExercise* Repo::getAll()
{
    return this->gyms;
}

Repo& Repo::operator=(const Repo& r)
{
    if (this == &r)
        return *this;
    this->n = 0;
    for (int i = 0; i < r.n; i++)
        this->gyms[this->n++] = r.gyms[i];
    return *this;
}