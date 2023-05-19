#include <iostream>

#ifndef LINKEDLIST_P
#define LINKEDLIST_P

namespace CSCIBetz
{

	class FullList{};
    class EmptyList{};


	template <typename tDATA>
	class linkedList_p
	{
	public:
		linkedList_p() { dummyHead = new Node; dummyHead -> nextNode = dummyHead -> prevNode = dummyHead; }
		~linkedList_p();

		void AddNode(tDATA &);
		tDATA & RemoveNode(tDATA &);
        bool IsEmpty() { return (dummyHead->nextNode == dummyHead); }

	private:
		struct Node
		{
			tDATA *data;
			Node *prevNode;
			Node *nextNode;
		}

		Node *dummyHead;		
	};
}

#endif

using namespace CSCIBetz;

template<typename tDATA>
linkedList_p<tDATA>::~linkedList_p()
{
	delete [] data; 
}

template<typename tDATA>
linkedList_p<tDATA>::AddNode(tDATA &dataRef)
{
	Node *newNode = new Node;
	newNode -> data -> dataRef; 
	newNode -> nextNode = dummyHead -> next;
	nextNode -> prevNode = dummyHead;

	dummyHead -> nextNode = newNode;
	newNode -> nextNode -> prevNode = newNode;
}

template<typename tDATA>
tDATA & linkedList_p<tDATA>::RemoveNode(tDATA &dataRef)
{
	Node *victim = dummyHead -> nextNode;
	while(victim -> data != dataRef || victim -> nextNode != dummyHead) 
	{
		victim = victim -> nextNode;
	}

	if(victim -> data)
	{
		victim -> nextNode -> prevNode = victim -> prevNode;
		victim -> prevNode -> nextNode = victim -> nextNode;
		return victim -> data;
	}
	else
	{
		printf("No data found\n");
		return null;
	}

}
