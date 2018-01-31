#include "List.h"
void main()
{
	List ds;
	ds.AddFist(1);
	ds.AddLast(3);
	ds.InsertPos(2, 2);
	ds.Display();
	cout << "\n";
	ds.DeletePos(2);
	ds.Display();
	cout << "\n";
	ds.DeleteFirst();
	ds.Display();
	cout << "\n";
	//ds.DeleteLast();
	ds.Display();
	cout << "\n";
	cout<<ds.IsEmpty();
	cout << "\n";
	ds.Display();
	cout << "\n";
	cout << "\n";
	ds.Clear();
	ds.AddFist(1);
	ds.Display();
}