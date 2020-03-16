#include <cstring>
#include <assert.h>
#include "tests.h"
#include "GymExercise.h"
#include "Repo.h"

void test_GymExercise()
{
    char* name = new char[10];
    strcpy(name, "Ionut");
    GymExercise g(name, 10, 30, 20);
    char* verif = g.getName();
    assert(verif[0] == name[0]);
    assert(g.getReps() == 30);
    assert(g.getSeries() == 10);
    assert(g.getWeight() == 20);

}

void test_Repo()
{
    Repo r;
    assert(r.getSize() == 0);
    char* name = new char[10];
    strcpy(name,"Ionut");
    GymExercise g(name, 10, 30, 20);
    r.addGymExercise(g);
    assert(r.getSize() == 1);
    GymExercise* gyms = r.getAll();
    char* verif = gyms[0].getName();
    assert(verif[0] == name[0]);
    assert (gyms[0].getReps() == 30);
    assert (gyms[0].getSeries() == 10);

}


