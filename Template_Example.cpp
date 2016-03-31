// Example program
#include <iostream>
#include <string>

using namespace std;

template <typename K = int>
struct Node {
	K data;
	Node *next;
	Node *prev;

	Node(K d = 0) {
		data = d;
		next = NULL;
		prev = NULL;
	}
};

class List {
	Node <int> *head;
	Node <int> *tail;
	unsigned int count;
public:
	List() {
		head = NULL;
		tail = NULL;
		count = 0;
	}

	void AddFront(int x) {
		if (head == NULL) {
			head = tail = new Node<int>(x);
		}
		else {
			Node<int>* tmp = head;
			head = new Node<int>(x);
			tmp->prev = head;
			head->next = tmp;
		}
		count++;
	}

	void AddBack(int x) {
		if (tail == NULL) {
			tail = head = new Node<int>(x);
		}
		else {
			Node<int>* tmp = tail;
			tail = new Node<int>(x);
			tmp->next = tail;
			tail->prev = tmp;
		}
		count++;
	}

	bool PopFront(int& ret) {
		if (head == NULL) return false;
		Node<int>* tmp = head;
		head = tmp->next;
		head->prev = NULL;
		ret = tmp->data;
		delete tmp;
		count--;
		return true;
	}

	bool PopBack(int& ret) {
		if (tail == NULL) return false;
		Node<int>* tmp = tail;
		tail = tmp->prev;
		tail->next = NULL;
		ret = tmp->data;
		delete tmp;
		count--;
		return true;
	}


	Node<int>* GetElementAtStartPos(unsigned int n) {    //Baþtan n. deðer
		if (n>count)return NULL;
		Node<int>* a = head;
		for (int i = 1; i<n; i++) {
			a = a->next;
		}
		return a;
	}

	Node<int>* GetElementAtFinishPos(unsigned int n) {   //Sondan n. deðer
		if (n>count)return NULL;
		Node<int>* a = tail;
		for (int i = 1; i<n; i++) {
			a = a->prev;
		}
		return a;
	}



	void Print() {
		cout << "List with " << count << " Elements:" << endl;
		for (Node<int>* p = head; p != NULL; p = p->next) {
			cout << p->data << " ";
		}
		cout << endl;
	}
};
int main()
{
	List L;

	L.AddFront(5);
	L.AddFront(8);
	L.AddBack(7);
	L.AddBack(9);

	L.Print();
	Node<int>* b = L.GetElementAtFinishPos(2);
	if (b != NULL)
		cout << b->data << endl;
	else cout << "Not Found" << endl;

	system("pause");
	return 0;
}
