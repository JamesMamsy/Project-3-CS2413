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
	DT& getInfo();
	void setNext(int n);
	void setDown(int d);
	void setInfo(DT& x);
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
	void findDisplayPath(DT& Key); //print all values of nodes encoutered searching for key
	int noFree(); //return num of free locations
	int size(); //returns num of elemnts stored
	int parentPost(DT& Key); //provides the location of the parents of key in the array
	GLRow<DT>& operator [] (int pos);
	int getFirstFree();
	int getFirstElement();
	int setFirstFree(int pos);
	int setFirstElement(int pos);
};


//GLRow Functions
template<class DT>
GLRow<DT>::GLRow() {
	_Next = -1;
	_Down = -1;
	_Info = NULL;
}

template<class DT>
GLRow<DT>::GLRow(GLRow<DT>& anotherOne) {
	_Info = anotherOne.getInfo();
	_Next = anotherOne.getNext();
	_Down = anotherOne.getDown();
}

template<class DT>
GLRow<DT>& operator=(GLRow<DT> anotherOne) {
	
}
template<class DT>
int GLRow<DT>::getNext() {
	return _Next;
}

template<class DT>
int GLRow<DT>::getDown() {
	return _Down;
}

template<class DT>
DT& GLRow<DT>::getInfo() {
	return _Info
}

template<class DT>
void GLRow<DT>::setNext(int n){
	_Next = n;
}

template<class DT>
void GLRow<DT>::setDown(int d) {
	_Down = d;
}

template<class DT>
void GLRow<DT>::setInfo(DT& x) {
	_Info = x;
}

template<class DT>
GLRow<DT>::~GLRow(){
	delete _Next;
	delete _Down;
	delete _Info;
}




//ArrayGLL Functions
template<class DT>
ArrayGLL<DT>::ArrayGLL() {
	myGLL = NULL;
	maxSize = 0;
	firstElement = -1;
	firstFree = -1;
}

template<class DT>
ArrayGLL<DT>::ArrayGLL(int size) {
	myGLL = NULL;
	maxSize = size;
	firstElemnt = -1;
	firstFree = -1;
}

template<class DT>
ArrayGLL<DT>::ArrayGLL(ArrayGLL<DT>& anotherOne) {
	myGll = anotherOne.getMyGLL();
	maxSize = anotherOne.getMaxSize();
	firstElement = anotherOne.getFirstElement();
	firstElement = anotherOne.getFirstFree();
}

template<class DT>
void ArrayGLL<DT>::display() {
	cout << "TODO: Not yet display implemented.";
}

template<class DT>
int ArrayGLL<DT>::find(DT& key) {
	return -1;
}

template<class DT>
void ArrayGLL<DT>::findDisplayPath(DT& key) {
	cout << "TODO; findDisplayPath not yet implemented"
}

template<class DT>
int ArrayGLL<DT>::noFree() {
	return maxSize - firstFree;
}

template<class DT>
int ArrayGLL<DT>::size() {
	return firstFree;
}

template<class DT>
int ArrayGLL<DT>::parentPost(DT& key) {
	return -1;
}

template<class DT>
int ArrayGLL<DT>::getFirstElement() {
	return firstElement;
}

template<class DT>
int ArrayGLL<DT>::getFirstFree() {
	return firstFree;
}


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

	const int& newData1 = 600;	
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


