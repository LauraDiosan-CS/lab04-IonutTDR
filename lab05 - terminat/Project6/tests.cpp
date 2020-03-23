#include <iostream>
using namespace std;
#include <cstring>
#include <assert.h>
#include "tests.h"
#include "GymExercise.h"
#include "Repo.h"
#include "Service.h"
#include "Operations.h"


void test_GymExercise()
{
    GymExercise g("Tractiuni", 10, 30, 20);
    char* verif = g.getName();
    assert(strcmp("Tractiuni", verif) == 0);
    assert(g.getReps() == 30);
    assert(g.getSeries() == 10);
    assert(g.getWeight() == 20);

}

void test_Repo()
{
    Repo r;
    GymExercise g1("Tractiuni", 10, 20, 80);
    GymExercise g2("Flotari", 20, 40, 60);
    GymExercise g3("Fandari", 40, 30, 70);
    r.addGymExercise(g1);
    r.addGymExercise(g2);
    r.addGymExercise(g3);

    int n = 0;
    n = r.getSize();
    assert(n == 3);

    r.deleteGymExercise(1);
    n = r.getSize();
    assert(n == 2);

    r.updateGymExercise(0, "Tractiuni", 10, 30, 80);
    GymExercise* gym = r.getAll();
    assert(gym[0].getReps() == 30);

    Repo r2;
    r2 = r;
    assert(r2.getSize() == 2);
}


void test_Service()
{
    Repo r;
    GymExercise g1("Tractiuni", 10, 20, 80);
    GymExercise g2("Flotari", 20, 40, 60);
    GymExercise g3("Fandari", 40, 30, 70);
    GymExercise g4("Abdomene", 10, 15, 50);
    Service s;
    s.addGym(g1);
    s.addGym(g2);
    s.addGym(g3);
    s.addGym(g4);
    
    int n = 0;
    n = s.getSize();
    assert(n == 4);

    s.deleteGym(3);
    n = s.getSize();
    assert(n == 3);

    s.updateGym(0, "Tractiuni", 10, 20, 60);
    GymExercise* gym = s.getAll();
    assert(gym[0].getWeight() == 60);

    Service s2;
    s2 = s;
    n = s2.getSize();
    assert(n == 3);

    //test pentru verificarea cerintei: noOfSeries * noOfReps * weightKg > X
    GymExercise newGyms[4];
    int newLen = 0;
    s.gymsByXservice(45000, newGyms, newLen);
    assert(newLen == 2);
    assert(newGyms[0] == g2 && newGyms[1] == g3);

    //test pentru verificarea cerintei: weightKg * noOfReps  < 5
    s.deleteGyms5service();
    GymExercise* gyms = s.getAll();
    n = s.getSize();
    assert(n == 3);

    GymExercise G1("Tractiuni", 10, 1, 4);
    GymExercise G2("Flotari", 20, 0, 60);
    GymExercise G3("Fandari", 40, 30, 70);
    GymExercise G4("Abdomene", 10, 15, 50);
    Service S;
    S.addGym(G1);
    S.addGym(G2);
    S.addGym(G3);
    S.addGym(G4);

    S.deleteGyms5service();

    n = S.getSize();
    assert(n == 2);
    GymExercise* Gyms = S.getAll();
    assert(Gyms[0] == G3 && Gyms[1] == G4);
}

void test_gymsByX()
{
    Repo r;
    GymExercise g1("Tractiuni", 10, 20, 80);
    GymExercise g2("Flotari", 20, 40, 60);
    GymExercise g3("Fandari", 40, 30, 70);
    GymExercise g4("Abdomene", 10, 15, 50);
    r.addGymExercise(g1);
    r.addGymExercise(g2);
    r.addGymExercise(g3);
    r.addGymExercise(g4);

    GymExercise newGyms[4];
    int newLen = 0;

    gymsByX(r, 45000, newGyms, newLen);

    assert(newLen == 2);
    assert(newGyms[0] == g2 && newGyms[1] == g3);
}
void test_deleteGyms5()
{
    Repo r;
    GymExercise g1("Tractiuni", 10, 1, 4);
    GymExercise g2("Flotari", 20, 0, 60);
    GymExercise g3("Fandari", 40, 30, 70);
    GymExercise g4("Abdomene", 10, 15, 50);
    r.addGymExercise(g1);
    r.addGymExercise(g2);
    r.addGymExercise(g3);
    r.addGymExercise(g4);

    deleteGyms5(r);

    int n = 0;
    GymExercise* gyms = r.getAll();
    n = r.getSize();
    assert(n == 2);
    assert(gyms[0] == g3 && gyms[1] == g4);


}