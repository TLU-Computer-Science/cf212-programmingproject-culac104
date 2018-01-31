#include "Linked_List.h"
void main()
{
	List ds;
	ds.AddFirst(1);
	ds.AddLast(8);
	ds.AddLast(7);
	ds.InsertPos(6,3);
	ds.AddLast(5);
	ds.AddLast(2);
	ds.AddLast(3);
	ds.AddLast(5);
	ds.Inra();
	cout << "\n";
	ds.QuickSort();
	ds.Inra();
}