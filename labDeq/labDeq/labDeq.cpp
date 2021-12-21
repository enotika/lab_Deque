#include<iostream>
#include<cstring>
#include<string>
#include "Dequeue.h"
using namespace std;

int main() {


	Dequeue < const char* > q;
	int type;
	do {
		system("cls");
		cout << "enter type of request\n";
		cout << "1: push back element\n";
		cout << "2: push front element\n";
		cout << "3: getsize\n";
		cout << "4: cout from begin to end\n";
		cout << "5: cout from end to begin\n";
		cout << "6: erase back element\n";
		cout << "7: erase front element\n";
		cout << "0:end work\n";
		cin >> type;
		char *a = new char[70];
		switch (type) {
		case 1:
			cin >> a;
			q.pushBack(a);
			system("pause");
			break;
		case 2:
			cin >> a;
			q.pushFront(a);
			system("pause");
			break;
		case 3:
			cout << q.getSize() << endl;
			system("pause");
			break;
		case 4:
			q.outFromBegin(cout);
			system("pause");
			break;
		case 5:
			q.outFromEnd(cout);
			system("pause");
			break;
		case 6:
			q.popBack();
			system("pause");
			break;
		case 7:
			q.popFront();
			system("pause");
			break;
		default:
			if (type != 0) {
				cout << "Wrong number\n";
				system("pause");
			}
			break;
		}
	} while (type != 0);
	Dequeue < const char *> deq2;
	deq2 = q;
	deq2.outFromBegin(cout);


}