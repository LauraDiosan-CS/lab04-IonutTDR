#include <iostream>
#include <cstring>
using namespace std;
#include "Service.h"
#include "GymExercise.h"
#include "Repo.h"
#include "Operations.h"
#include "UserInterface.h"

UserInterface::UserInterface(){}
UserInterface::~UserInterface(){}

//Menu
void printMenu()
{
	cout << "Menu: \n";
	cout << "1. Adauga exercitii: \n";
	cout << "2. Sterge exercitii \n";
	cout << "3. Actualizare \n";
	cout << "4. Afisare \n";
	cout << "5. Identificarea exercitiilor care  au noOfSeries * noOfReps * weightKg > X\n";
	cout << "6. Eliminarea exercitiilor care au weightKg * noOfReps  < 5\n";
	cout << "7. Undo\n";
	cout << "x. Iesire\n";
	cout << "\n";
}
//Adauga un exercitiu in lista
void UserInterface::add()
{
	cout << "Numele exercitiului: ";
	char* name = new char[20];
	cin >> name;

	cout << "Numarul de serii: ";
	int series = 0;
	cin >> series;

	cout << "Numarul de repetari: ";
	int reps = 0;
	cin >> reps;

	cout << "Greutate KG: ";
	int weight;
	cin >> weight;

	GymExercise g(name, series, reps, weight);
	
	this->s.addGym(g);
	cout << "\n";
}


//Sterge un element din lista
void UserInterface::remove()
{
	cout << "Se sterge exercitiul cu ID-ul (ID-ul este pozitia in lista, indexarea de la 0): \n";

	int id;
	cin >> id;

	this->s.deleteGym(id);
	cout << "Exercitiul cu ID-ul " << id << " a fost sters.\n";
	cout << "\n";
}

//Actualizeaza un exercetiu care se afla pe o anumita pozitie 
void UserInterface::update()
{
	cout << "Se va actualiza exercitiul care are ID-ul (ID-ul este pozitia in lista, indexarea de la 0): ";
	int index = 0;
	cin >> index;;

	cout << "Noul numele: ";
	char* name = new char[20];
	cin >> name;

	cout << "Noul numarul de serii: ";
	int series = 0;
	cin >> series;

	cout << "Noul numarul de repetari: ";
	int reps = 0;
	cin >> reps;

	cout << "Noua greutate KG: ";
	int weight;
	cin >> weight;

	this->s.updateGym(index, name, series, reps, weight);
	cout << "Exercitiu actualizat.\n";
	cout << "\n";
	
}

//Afiseaza toate exercitiile
void UserInterface::getAll()
{
	GymExercise* gyms = this->s.getAll();
	int n = this->s.getSize();
	for (int i = 0; i < n; i++)
		cout << i << ". " << gyms[i];
	cout << "\n";
}

/*
	Pentru undo memorez in copyService lista initiala inainte ca aceasta sa se modifice; in cazul in care este aplicat UNDO lista initiala va memora copyService
	UNDO se poate folosi doar o data !!!
*/
void UserInterface::run()
{
	int undo = 0;
	Service copyService;
	char op;
	int ok = 1;
	int X;
	while (ok == 1)
	{
		printMenu();
		cout << "Alege optiunea: ";
		cin >> op;
		cout << "\n";
		if (op == '1')
			copyService = this->s, undo = 1, this->add();

		if (op == '2')
			copyService = this->s, undo = 1, this->remove();
		
		if (op == '3')
			copyService = this->s, undo = 1, this->update();

		if (op == '4')
			this->getAll();

		if (op == '5')
		{
			GymExercise newGyms[101];
			int newLen = 0;
			int X = 0;
			cout << "X = ";
			cin >> X;
			this->s.gymsByXservice(X, newGyms, newLen);
			
			cout << "Exercitiile selectate: \n";
			for (int i = 0; i < newLen; i++)
				cout << newGyms[i];
			cout << "\n";
		}

		if (op == '6')
		{
			copyService = this->s;
			undo = 1;
			cout << "Se vor sterge exercitiile care au weightKg * noOfReps  < 5\n ";
			this->s.deleteGyms5service();
			cout << "S-au sters\n";
		}

		if (op == '7')
		{
			if (undo == 1)
			{
				undo = 0;
				this->s = copyService;
				cout << "S-a efectuat UNDO\n";
				cout << "\n";
			}
			else
				cout << "Ai aplicat deja UNDO\n";
		}

		if (op == 'x')
			break;
	}
}