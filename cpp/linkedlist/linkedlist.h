#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

template<class T>
class LinkedList
{
private:	
    template<class N>
	class Node{
		Node<N>(N& data) :mNext(nullptr){ mData = data; };
		~Node<N>() { delete mData; mNext = nullptr; };
		
		N mData;
		Node* mNext;		
	};
    
	
public:
    LinkedList<T>();
    ~LinkedList<T>();
  




};

#endif
