#pragma once
#include "GymExercise.h"

class Repo {
private:
    GymExercise gyms[20];
    int n;
public:
    Repo();
    void addGymExercise(GymExercise g);
    int getSize();
    GymExercise* getAll();
    ~Repo();
};
