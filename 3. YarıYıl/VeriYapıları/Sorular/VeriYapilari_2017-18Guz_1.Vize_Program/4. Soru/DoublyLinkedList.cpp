#include <string>
#include <iostream>
using namespace std;

struct DoublyNode
{
	string elem;											// element name
	int score;												// element score;
	DoublyNode* next;										// next item in the list
	DoublyNode* prev;										// previous item in the list
};

struct DoublyLinkedList
{
	DoublyNode* header;										// pointer to the header of list
	DoublyNode* trailer;									// pointer to the trailer of list

	DoublyLinkedList();										// empty list constructor
	~DoublyLinkedList();									// destructor

	bool empty() const;										// is list empty?
	const string& front() const;							// get front element
	const string& back() const;								// get back element
	void addFront(const string& e, const int& i);			// add to front of list
	void addBack(const string& e, const int& i);			// add to back of list
	void removeFront();										// remove front item list
	void removeBack();										// remove from back
	void printH2T();
	void printT2H();

	void add(DoublyNode* v, const string& e, const int& i);	// insert new node before v
	void remove(DoublyNode* v);								// remove node v

	void insertOrdered(const string& e, const int& i);
	void removeOrdered(const string& e, const int& i);

	DoublyLinkedList* mergeLists(DoublyLinkedList* list2);

	void print(DoublyNode* first, DoublyNode* last);
};

DoublyLinkedList::DoublyLinkedList()				// constructor
{
	header			= new DoublyNode;				// create sentinels
	trailer			= new DoublyNode;
	header->next	= trailer;						// have them point to each other
	trailer->prev	= header;
}

DoublyLinkedList::~DoublyLinkedList()				// destructor
{
	while (!empty()) removeFront();					// remove all but sentinels
	delete header;									// remove the sentinels
	delete trailer;
}

bool DoublyLinkedList::empty() const				// is list empty?
{
	return (header->next == trailer);
}

const string& DoublyLinkedList::front() const		// get front element
{
	return header->next->elem;
}

const string& DoublyLinkedList::back() const		// get back element
{
	return trailer->prev->elem;
}

void DoublyLinkedList::addFront(const string& e, const int& i)		// add to front of list
{
	add(header->next, e, i);
}

void DoublyLinkedList::addBack(const string& e, const int& i)		// add to back of list
{
	add(trailer, e, i);
}

void DoublyLinkedList::add(DoublyNode* v, const string& e, const int& i)	// insert new node before v
{
	DoublyNode* u	= new DoublyNode;				// create a new node for e
	u->elem			= e;
	u->score		= i;

	u->next			= v;							// link u in between v
	u->prev			= v->prev;						// ... and v->prev
	v->prev->next	= u;							// correct code should be
	v->prev			= u;							// like this
	
	//v->prev->next	= v->prev	= u;				// WRONG CODE ! (Page : 127)
}

void DoublyLinkedList::removeFront()				// remove from font
{
	// Liste boş mu?
	if (empty())
	{
		cout << "List is empty !" << endl;
		return;
	}

	remove(header->next);
}

void DoublyLinkedList::removeBack()					// remove from back
{
	// Liste boş mu?
	if (empty())
	{
		cout << "List is empty !" << endl;
		return;
	}

	remove(trailer->prev);
}

void DoublyLinkedList::remove(DoublyNode* v)
{													// remove node v
	DoublyNode* u	= v->prev;						// predecessor
	DoublyNode* w	= v->next;						// successor
	u->next			= w;							// unlink v from list
	w->prev			= u;
	delete v;
}

void DoublyLinkedList::insertOrdered(const string& e, const int& i)
{
	DoublyNode* newNode		= new DoublyNode;
	newNode->elem			= e;
	newNode->score			= i;

	DoublyNode* current	= header->next;

	while (current != trailer)
	{
		if(newNode->score >= current->score)
			 current = current->next;
		else
			break;
	}

	// newNode'u current'tan önce ekle (add() ile aynı)
	newNode->next			= current;
	newNode->prev			= current->prev;
	current->prev->next		= newNode;
	current->prev			= newNode;
}

void DoublyLinkedList::removeOrdered(const string& e, const int& i)
{
	// Liste boş mu?
	if (empty())
	{
		cout << "List is empty !" << endl;
		return;
	}

	DoublyNode* current	= header->next;

	while (current != trailer)
	{
		if ((e.compare(current->elem) == 0) && (current->score == i))
		{
			current->prev->next	= current->next;
			current->next->prev	= current->prev;
			delete current;
			return;
		}

		current	= current->next;
	}

	cout << "\n" << e << " is not found" << endl;
}

DoublyLinkedList* DoublyLinkedList::mergeLists(DoublyLinkedList* list2)
{
	DoublyLinkedList* mergedList = new DoublyLinkedList();

	DoublyNode* plist1 = this->header->next; 
	DoublyNode* plist2 = list2->header->next;

	while ( (plist1 != this->trailer) || (plist2 != list2->trailer) )
	{
		if(plist1 == this->trailer)
		{
			while (plist2 != list2->trailer)
			{
				mergedList->addBack(plist2->elem, plist2->score);
				plist2 = plist2->next;
			}

			return mergedList;
		}

		if(plist2 == list2->trailer)
		{
			while (plist1 != this->trailer)
			{
				mergedList->addBack(plist1->elem, plist1->score);
				plist1 = plist1->next;
			}

			return mergedList;
		}

		if(plist1->score <= plist2->score )
		{
			mergedList->addBack(plist1->elem, plist1->score);
			plist1 = plist1->next;			
		}
		else
		{
			mergedList->addBack(plist2->elem, plist2->score);
			plist2 = plist2->next;
		}	
	}
}

void DoublyLinkedList::printH2T()
{
	if (empty())
	{
		cout << "List is empty !" << endl;
		return;
	}

	DoublyNode* first = header;
	while (!(first->next == trailer))
	{
		cout << first->next->elem << "\t" << first->next->score << endl;
		first = first->next;
	}
}

void DoublyLinkedList::printT2H()
{
	if (empty())
	{
		cout << "List is empty !" << endl;
		return;
	}

	DoublyNode* last = trailer;
	while (!(last->prev == header))
	{
		cout << last->prev->elem << "\t" << last->prev->score << endl;
		last = last->prev;
	}
}

// 2017-2018 Güz 4. Soru
void DoublyLinkedList::print(DoublyNode* first, DoublyNode* last)
{
	if ((first->elem.compare(last->elem) == 0)
		&& (first->score == last->score))
		cout << first->elem << endl;
	else
		print(first->next, last->prev);
}

int main()
{
	DoublyLinkedList list;

	list.insertOrdered("Paul", 720);
	list.insertOrdered("Rose", 590);
	list.insertOrdered("Anna", 660);
	list.insertOrdered("Mike", 1105);
	list.insertOrdered("Rob", 750);
	list.insertOrdered("Jack", 510);
	list.insertOrdered("Jill", 740);

	list.print(
		list.header->next,
		list.trailer->prev);

	::getchar();
}