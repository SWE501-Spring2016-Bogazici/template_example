//============================================================================
// Name        : dlinked_list_template.cpp
// Author      : Gokce Yucel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template <typename D>
struct DNode {
	DNode<D> *prev;
	DNode<D> *next;
	D data;

public:
	DNode(D d) {
	    data = d;
	    next = NULL;
	    prev = NULL;
	}
};

template <typename D>
struct DList {
	DNode<D> *head;
	DNode<D> *tail;
	int count;

public:
	DList<D>() {
	    head=NULL;
	    tail=NULL;
	    count=0;
	}

	void AddFront(D x) {
		if (head == NULL) {
			head = tail = new DNode<D>(x);
		}
		else {
			DNode<D> *tmp = head;
			head = new DNode<D>(x);
			tmp->prev = head;
			head->next = tmp;
		}
		count++;
	}

    void AddBack(D x) {
        if (tail == NULL) {
            tail = head = new DNode<D>(x);
        }
        else {
            DNode<D> *tmp = tail;
            tail = new DNode<D>(x);
            tmp->next = tail;
			tail->prev = tmp;
        }
        count++;
    }

	bool PopFront(int& ret) {
		if (head == NULL) return false;
		DNode<D> *tmp = head;
		head = tmp->next;
		ret = tmp->data;
		delete tmp;
		count--;
		return true;
	}

	bool PopBack(int& ret) {
		if (tail == NULL) return false;
		DNode<D> *tmp = tail;
		tail = tmp->prev;
		ret = tmp->data;
		delete tmp;
		count--;
		return true;
	}

	DNode<D> *GetElementAtPos(unsigned int pos) {
		if (pos > count || head == NULL) return NULL;
		unsigned int idx;
		if (pos - count < pos) {
			idx = count;
			for (DNode<D> *p = tail; p->prev != NULL; p = p->prev){
				if (idx-- == pos) return p;
			}
		}
		else {
			idx = 0;
			for (DNode<D> *p = head; p->next != NULL; p = p->next){
				if (++idx == pos) return p;
			}
		}
		return NULL;
	}

	void Print() {
		for (DNode<D> *p = head; p != NULL; p = p->next) {
			cout << p->data << " ";
		}
		cout << endl;
	}
};

int main() {
	DList<string> dl;
	dl.AddFront("karpuz");
	dl.AddFront("armut");
	dl.AddBack("kiraz");
	dl.AddFront("portakal");
	dl.AddBack("erik");
	dl.Print();

//	int ret;
//	while(dl.PopBack(ret)) cout << ret << endl;

	DNode<string> *p = dl.GetElementAtPos(5);
	cout << p->data << endl;
}
