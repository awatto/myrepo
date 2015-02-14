#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "../include.h"


template<class T>
class LinkedList
{
private:	
    template<class N>
	class Node{
		Node<N>(N& data) :Next(nullptr){ Data = data; };
		~Node<N>() { delete Data; Next = nullptr; };
		
		N Data;
		Node* Next;		
	};
    
	
public:
    LinkedList<T>() : mHead(nullptr), mTail(nullptr), mSize(0){};
    ~LinkedList<T>()
    {	
		DeleteAll();
		delete mTail;
		mTail = nullptr;
		delete mHead;
		mHead = nullptr;
		mSize = 0;
	};
	
	size_t GetSize() { return mSize; }; 
	
	void AddTail(T& data)
	{
		Node<T>* newNode = new Node<T>(data);
		if(mHead && mTail)
		{
			mTail->Next = newNode;
			mTail = mTail->Next;
		}
		else
		{
			mHead = newNode;
			mTail = mHead;
		}
	};
	
	void AddHead(T& data)
	{
		Node<T>* newNode = new Node<T>(data);
		if(mHead && mTail)
		{
			newNode->Next = mHead;
			mHead = newNode;
		}
		else
		{
			mHead = newNode;
			mTail = mHead;
		}		
	};
	
	T* GetDataAt(size_t index)
	{
		Node<T>* node = GetNodeAt(index);
		if(node)
		{
			return &(node->Data);
		}
		else
		{
			return nullptr;
		}
	};
	
	bool RemoveNodeAt(size_t index)
	{
		Node<T>* node = GetNodeAt(index - 1); // get the node one ahead of the node to be deleted
		if(node == nullptr)
		{
			return false; // nothing to remove
		}
		if(node->Next == nullptr)
		{
			return false; //nothing to remove
		}
		Node<T>* nodeToDel = node->Next;
		node->Next = nodeToDel->Next;
		
		delete nodeToDel;
		return true;		
	};
	
	void DeleteAll()
	{
		Node<T>* cur = mHead;
		Node<T>* next = cur;
		while(cur)
		{
			next = cur->mNext;
			delete cur;
			cur = next;			
		}
		mTail = mHead;
		mSize = 0;		
	};
    
    
    
    
private:
	LinkedList<T>(LinkedList<T>&);
	LinkedList<T>& operator=(LinkedList<T>&);  
	
	// get a node by its index. Index is 0-based
	Node<T>* GetNodeAt(size_t index)
	{
		if(index > mSize)
			return nullptr;
			
		size_t cur = 0;
		Node<T>* retNode = mHead;
		while(cur < index)
		{
			retNode = retNode->Next;
			cur ++;
		}
		return retNode;		
	};
    
private:
    Node<T>*		mHead;
    Node<T>*		mTail;
    size_t			mSize;
};

#endif
