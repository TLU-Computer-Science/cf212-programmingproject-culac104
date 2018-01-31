#include<iostream>
using namespace std;
int n;
struct Node{
	int data;
	Node *next;
};
class List
{
private:
	Node *head;
	Node *tail;
public:
	List()
	{
		head = tail = NULL;
	};
	Node *creatNode(int x)
	{
		Node *p = new Node;
		if (p == NULL)
			exit(1);
		p->next = NULL;
		p->data = x;
		return p;
	}
	bool isEmpty()
	{
		if (head == NULL) return true;
		return false;
	}
	void AddFirst(int x)
	{
		Node *p = creatNode(x);
		if (isEmpty())
			head = tail = p;
		else
		{
			p->next = head;
			head = p;
		}
	}
	void AddLast(int x)
	{
		Node *p = creatNode(x);
		if (isEmpty())
			AddFirst(x);
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	void InsertPos(int v, int Pos)
	{
		if (isEmpty() || Pos <= 1)
			AddFirst(v);
		else if (Pos >= n)
			AddLast(v);
		else
		{
			Node *p = new Node;
			Node *q = new Node;
			Node *temp = new Node;
			q = head;
			for (int i = 1; i<Pos; i++)
			{
				p = q;
				q = q->next;
			}
			temp->data = v;
			p->next = temp;
			temp->next = q;
		}
	}
	Node *Search(int k)
	{
		Node *p = head;
		while (p != NULL)
		{
			if (p->data == k)
				return p;
			else
				p = p->next;
		}
		return NULL;
	}
	void Inra()
	{
		Node *p = head;
		while (p != NULL){
			cout << " " << p->data;
			p = p->next;
		}
	}
	void DelFirst()
	{
		if (!isEmpty())
		{
			Node *p = head;
			head = head->next;
			delete p;
		}
	}
	void DelLast()
	{
		if (!isEmpty())
		{
			Node *p = head;
			Node *q = new Node;
			while (p->next != tail) p = p->next;
			q = p;
			p = p->next;
			tail = q;
			tail->next = NULL;
			delete p;
		}
	}
	void DelPos(int Pos)
	{
		if (Pos <= 1)
			DelFirst();
		else if (Pos >= n)
			DelLast();
		else
		{
			int dem = 0;
			if (!isEmpty())
			{
				Node *p = head;
				Node *q = new Node;
				while (p != NULL)
				{
					dem++;
					q = p;
					if (dem == Pos)
						break;
					else
						p = p->next;
				}
				Node *r = head;
				while (r->next != q)
					r = r->next;
				r->next = q->next;
				delete q;
			}
		}
	}
	void QuickSort()
	{
		List l1, l2;
		Node *tag, *p;
		if (head == tail)
			return;
		tag = head;
		head = head->next;
		tag->next = NULL;
		while (head != NULL)
		{
			p = head;
			head = head->next;
			p->next = NULL;
			if (p->data <= tag->data)
				l1.AddFirst(p->data);
			else
				l2.AddFirst(p->data);
		}
		l1.QuickSort();
		l2.QuickSort();
		if (l1.head != NULL)
		{
			head = l1.head;
			l1.tail->next = tag;
		}
		else head = tag;
		tag->next = l2.head;
		if (l2.head != NULL)
			tail = l2.tail;
		else
			tail = tag;
	}

};
