#include "load.h"
#include "Apriori.h"



int main()
{
	int person_types[32];
	populate_zeros(person_types, 32);

	readPeople(person_types);

	print_array(person_types, 32);

	for (int i = 0; i < CONDITIONS; i++)
	{
		dropped_conditions[i] = false;
		failed_conditions[i] = 0;
	}
	
	condition_names[0] = "survived";
	condition_names[1] = "died";
	condition_names[2] = "female";
	condition_names[3] = "male";
	condition_names[4] = "child";
	condition_names[5] = "adult";
	condition_names[6] = "crew";
	condition_names[7] = "third";
	condition_names[8] = "second";
	condition_names[9] = "first";

	cin.ignore();
	cin.get();

	Apriori(person_types);

	cin.ignore();
	cin.get();
	return 0;
}