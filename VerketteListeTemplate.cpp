#include <iostream>
#include "my_templlist.h"
using namespace std;

int main()
{
	TListenKnoten<int>* anker1 = nullptr;
	int laenge = 3;
	for (int i = 0; i < laenge; i++)
	{
		vorne_anfuegen<int>(anker1, i*i);
	}
	liste_ausgeben(anker1);
	liste_aufaddieren<int>(anker1);
	cout << endl;

	TListenKnoten<double> *anker2 = nullptr;
	for (double i = 0; i < laenge; i++)
	{
		hinten_anfuegen<double>(anker2, i*i);
	}
	liste_ausgeben<double>(anker2);
	liste_aufaddieren<double>(anker2);
	cout << endl;
	system("PAUSE");
	return 0;
}

