#pragma once
class GymExercise {
private:
    char* name;
    int noOfSeries, noOfReps, weightKg;
public:
    GymExercise();
    GymExercise(char* name, int noOfSeries, int noOfReps, int weightKg);
    GymExercise(const GymExercise& g);
    char* getName();
    int getSeries();
    int getReps();
    int getWeight();
    ~GymExercise();
};

