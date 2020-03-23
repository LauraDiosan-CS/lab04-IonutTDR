#include <iostream>
using namespace std;
#include "tests.h"
#include "GymExercise.h"
#include "Repo.h"
#include "UserInterface.h"
#include "Operations.h"
#include "Service.h"

int main()
{
    test_GymExercise();
    test_Repo();
    test_Service();
    test_deleteGyms5();
    test_gymsByX();

    UserInterface console;
    console.run();

    return 0;
}
