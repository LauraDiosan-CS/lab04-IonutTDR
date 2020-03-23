#include "Operations.h"
#include "GymExercise.h"
#include "Repo.h"


/*
	Desc: adauga intr-o lista noua exercitiile care au produsul nr. de serii, nr. de repetari si greutate mai mare decat un nr X dat
	In: rep - repository , clasa Repo; newGyms - o lista de exercitii, clasa GymExercise, newLen - int 
*/
void  gymsByX(Repo& rep, int X, GymExercise newGyms[], int& newLen)
{
	GymExercise* gyms = rep.getAll();
	int  n = rep.getSize();

	int i = 0;

	for (i = 0; i < n; i++)
	{
		int p = gyms[i].getReps() * gyms[i].getSeries() * gyms[i].getWeight();
		if (p > X)
			newGyms[newLen++] = gyms[i];
	}
}

/*
	Desc: elimina din lista exercitiile care au (nr de repetari * greutatea) < 5
	In: rep - repository, clasa Repo
*/

void deleteGyms5(Repo& rep)
{
	GymExercise* gyms = rep.getAll();
	int  n = rep.getSize();

	int k = 0;
	while (k < n)
	{
		if (gyms[k].getWeight() * gyms[k].getReps() < 5)
		{
			rep.deleteGymExercise(k);
			n = rep.getSize();
			k = 0;
		}
		else
			k++;
	}
}