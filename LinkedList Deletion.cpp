#include<iostream>

using namespace std;

template <class T> class LinkedList{
private:
	struct Node{
		T data;
		Node* next;
		
		Node(T val, Node* Link = 0): data(val), next(Link){}
		
	};
	
	Node* head;
	public:
		LinkedList(): head(0){}
		
		bool empty() const {
		return head == 0;
		}
		
		void addFirst(const T& val);
		void addLast(const T& val);
		void display();
		void del(const T& val);
		T delFirst();
		
};

template<class T> void LinkedList<T> :: addFirst(const T& val){
	Node* n = new Node(val);
	n->next = head;
	head = n;
}

template<class T> void LinkedList<T> :: addLast(const T& val){
	if (head == 0){
		return addFirst(val);
	}
	Node* p = head;
	while(p->next != 0) p = p->next;
	Node* n = new Node(val);
	p->next = n;
}

template <class T> void LinkedList<T> :: display(){
	cout << "[ ";
	for(Node* i = head;i != 0;i = i->next){
		cout << i->data << " -> ";
	}
	cout << " ]";
} 

class ListEmptyException{ };

template <class T> T LinkedList<T>::delFirst(){
	if (head == 0){
		throw ListEmptyException();
	}
	Node * n = head;
	T val = n->data;
	head = head->next;
	delete n;
	return val;
	
}

template <class T> void LinkedList<T>::del(const T& val){
	if (head == 0){
		throw ListEmptyException();
	}
	if(head->data == val){
		delFirst();
	}
	Node *p, *n = head;
	while (n != 0 && n->data != val){
		p = n;
		n = n->next;
	}
	if (n == 0) return;
	p->next = n->next;
	delete n;
	
}

int main(){
	LinkedList<int> List;
	List.addFirst(16);
	List.addFirst(15);
	List.addFirst(14);
	List.addLast(17);
	List.addLast(18);
	List.addLast(19);
	
	List.display();
	
	try{
		int value = List.delFirst();
	}
	catch (ListEmptyException& e){
		cout << "List EMPTY!"; // handel the exception
		
	}
	List.display();
	return 0;
}
