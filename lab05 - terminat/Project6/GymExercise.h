#pragma once
#include <iostream>
using namespace std;
#include <ostream>
class GymExercise {
private:
    char* name;
    int noOfSeries, noOfReps, weightKg;
public:
    GymExercise();
    GymExercise(const char* name, int noOfSeries, int noOfReps, int weightKg);
    GymExercise(const GymExercise& g);
    char* getName();
    int getSeries();
    int getReps();
    int getWeight();
    void setName(char* newName);
    void setSeries(int newNr);
    void setReps(int newNr);
    void setWeight(int newNr);
    GymExercise& operator=(const GymExercise& g);
    bool operator==(const GymExercise& g);
    friend ostream& operator<<(ostream& os, const GymExercise& g);
    ~GymExercise();
};

