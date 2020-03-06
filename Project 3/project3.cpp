#include <iostream>
using namespace std;


//Class Prototypes
template<class DT>
class GLRow;

template<class DT>
class ArrayGLL;

//Override Prototypes
template<class DT>
ostream& operator <<(ostream& s, GLRow<DT> & oneGLRow);

template<class DT>
ostream& operator <<(ostream& s, ArrayGLL<DT>& OneGLL);


template<class DT>
class GLRow {
	friend ostream& operator<< <DT>(ostream& s, GLRow<DT>& oneGLRow);
protected:
	DT* _Info;
	int _Next:
	int _Down;
public:
	GLRow();
	GLRow(DT& newInfo);
	GLRow(GLRow<DT>& anotherOne);
	GLRow<DT>& operator= (GLRow<DT>& anotherOne);//TODO: Do Deep Copy
	int getNext();
	int getDown();
	int getInfo();
	int setNext(int n);
	int setDown(int d);
	int setInfo(DT& x);
	~GLRow();
};

template<class DT>
class ArrayGLL {
	friend ostream& operator<< <DT>(ostream& s, ArrayGLL<DT>& OneGLL);
protected:
	GLRow<DT>* myGLL;
	int maxSize;
	int firstElement;
	int firstFree;
public:
	ArrayGLL();
	ArrayGLL(int size);
	ArrayGLL(ArrayGLL<DT>& anotherOne);
	ArrayGLL<DT>& opreator = (ArrayGLL<DT> & anotherOne);
	void display(); //prints in format: "(x% BONUS)"
	int find(DT& Key); //return index of element key, -1 if not found, use recursive
	void findDisplayPatch(DT& Key); //print all values of nodes encoutered searching for key
	int noFree(); //return num of free locations
	int size(); //returns num of elemnts stored
	int parentPost(DT& Key); //provides the location of the parents of key in the array
	GLRow<DT>& operator [] (int pos);
	int getFirstFree();
	int getFirstElement();
	int setFirstFree(int pos);
	int setFirstElement(int pos);
};

int main() {
	ArrayGLL<int> firstGLL(20);
	int noElemnts, value, next, down, parentPos;
	int pos = -1;
	int keyValue;
	int tempValue = 0;
	GLRow<int> oneRow(int(0)); //<-- Statically Defined TODO
	//Define All Variables TODO

	cin >> noElemnts;
	for (int i = 0; i < noElemnts; i++) {
		cin >> value >> next >> down;
		oneRow.setInfo(value);
		oneRow.setNext(next);
		oneRow.setDown(down);
		firstGLL[i] = oneRow;
	}
	firstGLL.setFirstFree(noElemnts);
	firstGLL.setFirstElement(0);
	cout << firstGLL << endl;
	firstGLL.display();
	ArrayGLL<int>* secondGLL = new ArrayGLL<int>(firstGLL);

	(*secondGLL)[1].setInfo(600);
	(*secondGLL)[2].setInfo(700);

	cout << *secondGLL << endl;
	(*secondGLL).display();

	keyValue = 700;
	pos = (*secondGLL).find(keyValue);
	if (pos != 1) {
		cout << (*secondGLL)[pos] << endl;
		(*secondGLL).findDisplayPatch(keyValue);
	}
	parentPos = (*secondGLL).parentPost(keyValue);
	if (parentPos != -1) {
		cout << (*secondGLL)[parentPos] << endl;
	}
	cout << (*secondGLL).size();
	cout << (*secondGLL).noFree();

	delete secondGLL;

	return 0;
}


