#pragma once
#include "GymExercise.h"
#include <iostream>
#include <ostream>
using namespace std;
class Repo {
private:
    GymExercise gyms[20];
    int n;
public:
    Repo();
    Repo(const Repo& r);
    void addGymExercise(const GymExercise& g);
    int getSize();
    int findGymExercise(GymExercise g);
    void deleteGymExercise(int poz);
    void updateGymExercise(int poz, const char* name, int series, int reps, int weight);
    Repo& operator=(const Repo& r);
    GymExercise* getAll();
    ~Repo();
};
