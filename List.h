#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class List
{
private:
	node *head, *tail;
public:
	List()
	{
		head = NULL;
		tail = NULL;
	}
public:
	void AddLast(int);
	void AddFist(int);
	void InsertPos(int, int);
	void DeleteFirst();
	void DeleteLast();
	void DeletePos(int);
	void Display();
	bool IsEmpty();
	void Clear();
};
void List::AddLast(int v)
{
	node *temp = new node;
	temp->data = v;
	temp->next = NULL;
	if (tail == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}
void List::AddFist(int v)
{
	node *temp = new node;
	temp->data = v;
	temp->next = head;
	head = temp;
	if (tail == NULL)
	{
		tail = head;
	}
}
void List::Display()
{
	node *temp = new node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << "; ";
		temp = temp->next;
	}
}
void List::InsertPos(int pos, int v)
{
	node *truoc = new node;
	node *hienhanh = new node;
	node *temp = new node;
	hienhanh = head;
	for (int i = 1; i<pos; i++)
	{
		truoc = hienhanh;
		hienhanh = hienhanh->next;
	}
	temp->data = v;
	truoc->next = temp;
	temp->next = hienhanh;
}
void List::DeleteFirst()
{
	node *temp = new node;
	temp = head;
	head = head->next;
	delete temp;
}
void List::DeleteLast()
{
	node *hienhanh = new node;
	node *truoc = new node;
	hienhanh = head;
	while (hienhanh->next != NULL)
	{
		truoc = hienhanh;
		hienhanh = hienhanh->next;
	}
	tail = truoc;
	truoc->next = NULL;
	delete hienhanh;

}
void List::DeletePos(int pos)
{

	node *hienhanh = new node;
	node *truoc = new node;
	hienhanh = head;
	for (int i = 1; i < pos; i++)
	{
		truoc = hienhanh;
		hienhanh = hienhanh->next;
	}
	truoc->next = hienhanh->next;
}
bool List::IsEmpty()
{
	return head == NULL;
}
void List::Clear()
{
	node *temp, *temp2;
	if (head == NULL)
	{
		return;
	}
	temp = head;
	while (temp) 
	{
		temp2 = temp->next;
		delete temp;
		if (temp2 != head)
		{
			head = NULL;
			return;
		}
		temp = temp2;
	}
}