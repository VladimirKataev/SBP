#include<iostream>

template<class A> //-------move to a node.cpp and make node.h
class node{
	public:
		node<A>* nxt;
		A dat;
};

template<class A>
void printList(node<A>* head){
	std::cout << head->dat << ' ';
	for(node<A>* i = head; i->nxt != NULL; i = i->nxt)
		std::cout << i->nxt->dat << ' ';
	std::cout << '\n';
}


template<class A>
void removeDups(node<A>* head){//O(n^2) efficiency. could be lower with a hash map, but done with no tmp buffer
	node<A>* last;
	for(node<A>* i = head; i->nxt != NULL; i++){
		if(i->nxt->dat == head->dat){
			if(i->nxt->nxt == NULL)
				i->nxt = NULL;
			else
				i->nxt = i->nxt->nxt;
		}
	}
	if(head->nxt != NULL)
		removeDups(head->nxt);

}

template<class A>
node<A>* kthFromLast(node<A>* head, int k){
	int l = 1; // To account for OBO that comes from last not being checked
	for(node<A>* i = head; i->nxt != NULL; i = i->nxt)
		l++;
//	std::cout << "length of " << l << '\n';
	node<A>* toRet = head;
	for(int i = 0; i < (l-k)-1; i++)
		toRet = toRet->nxt;
	return toRet;
}


template<class A>
void deleteMidNode(node<A>* head, node<A>* toDel){ //Irony is, used in removeDups
	node<A>* tmp = head->nxt;
	while(tmp->nxt != NULL){
		if(tmp->nxt == toDel){
			tmp->nxt = tmp->nxt->nxt;
			return;
		}
		tmp = tmp->nxt;
	}
}

template<class A, class B>
void addNode(node<A> head, node<B> add){
	if(head->nxt == NULL)
		head->nxt = add;
	else
		addNode(head->nxt, add);

}

template<class A>
node<A>* intersect(node<A>* a, node<A>* b){
//	if(a == b)	return a;
//	if(a->nxt = b)	return b;
//	if(b->nxt = a)	return a;

	for(node<A>* i = a; i->nxt != NULL; i = i->nxt)
		for(node<A>* j = b; j->nxt != NULL; j = j->nxt)
			if(i->nxt == j->nxt)
				return i->nxt;
	return NULL;

}

template<class A>
node<A>* loopDetect(node<A>* a){
	if(a->nxt == NULL) return NULL;

	for(node<A>* i = a; i->nxt != NULL; i = i->nxt){
		for(node<A>* j = a; j != i; j = j->nxt){
			if(j == i->nxt)
				return j;

		}
	}
	return NULL;

}

template<class A>
node<A>* partition(node<A>* in, A val){ //Allocates memory
	node<A>* readIn = in;
	node<A>* smallPartition = NULL;
	node<A>* smallPartitionEnd = NULL;
	node<A>* largePartition = NULL;
	node<A>* largePartitionEnd = NULL;
	node<A>* toInsert;
	for(node<A>* i = in; i->nxt != NULL; i = i->nxt){
		readIn = i;
                toInsert = new node<A>;
                toInsert->dat = readIn->dat;
                toInsert->nxt = NULL;
		if(toInsert->dat < val){
			if(smallPartition == NULL){
				smallPartition = toInsert;
				smallPartitionEnd = toInsert;
			}
			else{
				smallPartitionEnd->nxt = toInsert;
				smallPartitionEnd = smallPartitionEnd->nxt;
			}
		}
		else{
                        if(largePartition == NULL){
                                largePartition = toInsert;
                                largePartitionEnd = toInsert;
                        }
                        else{
                                largePartitionEnd->nxt = toInsert;
                                largePartitionEnd = smallPartitionEnd->nxt;
                        }
		}
	}

	toInsert = new node<A>;
	toInsert->nxt = NULL;
	toInsert->dat = readIn->nxt->dat;

	if(toInsert->dat > val){
		toInsert->nxt = largePartition;
		largePartition = toInsert;
	}
	else{
		toInsert->nxt = smallPartition;
		smallPartition = toInsert;
	}
	smallPartitionEnd->nxt = largePartition;
	return smallPartition;

}


template<class A>
void deleteLinkedList(node<A>* head){
	if(head->nxt != NULL)
		deleteLinkedList(head->nxt);
	delete head;
}

template<class A>
node<A>* reverseList(node<A>* rest){
	bool done = false;
	node<A>* mk;
	node<A>* prev = NULL;
	node<A>* parse = rest;
	while(!done){
		mk = new node<A>;
		mk->dat = parse->dat;
		mk->nxt = prev;
		prev = mk;
		if(parse->nxt == NULL)
			done = true;
		else
			parse = parse->nxt;
	}

	return mk;
}


template<class A>
bool palindrome(node<A>* in)
{
	node<A>* reverseStack = reverseList(in);
	node<A>* parse = reverseStack;
	for(node<A>* i = in; i->nxt != NULL; i = i->nxt){
		if(parse->dat != i->dat)
			return false;
		if(parse->nxt == NULL)
			return false;
		parse = parse->nxt;
	}
	deleteLinkedList(reverseStack);

	return true;
}


node<int>* sumLists(node<int>* l, node<int>* r){
	node<int>* start = NULL;
	node<int>* end = NULL;
	node<int>* lParse = l;
	node<int>* rParse = r;
	node<int>* toAdd;
	int dig = 0, rem = 0, one = 0, two = 0;
	bool doneOne = false, doneTwo = false;
	while(!doneOne && !doneTwo){
		if(!doneOne && lParse->nxt != NULL){
			one = lParse->dat;
			lParse = lParse->nxt;
		}
		else if(!doneOne && lParse->nxt == NULL){
			one = lParse->dat;
			doneOne = true;
		}
		else{
			one = 0;
		}

                if(!doneTwo && rParse->nxt != NULL){
                        two = rParse->dat;
                        rParse = rParse->nxt;
                }
                else if(!doneTwo && rParse->nxt == NULL){
                        two = rParse->dat;
                        doneTwo = true;
                }
                else{
                        two = 0;
                }
		dig = one + two + rem;
		if(dig > 9){
			rem = (dig - (dig%10))/10;
			dig %= 10;
		}
		toAdd = new node<int>;
		toAdd->dat = dig;
		toAdd->nxt = NULL;

		if(start == NULL){
			start = toAdd;
			end = toAdd;
		}
		else{
			end->nxt = toAdd;
			end = end->nxt;
		}
	}
	return start;
}

int main(int argc, char** argv){


	node<int> a;
	node<int> b;
	node<int> c;
	node<int> d;
	node<int> e;
	node<int> f;


	a.dat = 1;
	b.dat = 2;
	c.dat = 3;
	d.dat = 4;
	e.dat = 5;
	f.dat = 6;

	a.nxt = &b;
	b.nxt = &c;
	c.nxt = &d;
	d.nxt = &e;
	e.nxt = &f;
	f.nxt = &e;




/*--------List intersect test data
	a.dat = 1;
	b.dat = 9;
	c.dat = 6;
	d.dat = 4;
	e.dat = 5;
	f.dat = 100;


	a.nxt = &c;
	b.nxt = &d;
	c.nxt = &e;

	d.nxt = &e;
	e.nxt = &f;
	f.nxt = NULL;
*/


/*--------Sum Lists test data
	a.nxt = &b;
	b.nxt = &c;
	c.nxt = NULL;
	d.nxt = &e;
	e.nxt = &f;
	f.nxt = NULL;

	a.dat = 7;
	b.dat = 1;
	c.dat = 6;
	d.dat = 5;
	e.dat = 9;
	f.dat = 2;
*/


/*------Generic Test Data
        a.nxt = &b;
        b.nxt = &c;
        c.nxt = &d;
        d.nxt = &e;
        e.nxt = &f;
        f.nxt = NULL;

        a.dat = 1;
        b.dat = 2;
        c.dat = 3;
        d.dat = 3;
        e.dat = 2;
        f.dat = 1;
*/


//	std::cout << "Linked list of:\n";
//	printList(&a);

	node<int>* res = loopDetect(&a);


	std::cout << "Loops at node with value:\t";

	if(res == NULL) std::cout << "NULL";
	else std::cout << res->dat;


/*
	std::cout << '\n';
	printList(&b);



	node<int>* res = intersect(&a, &b);

	if(res == NULL)
		std::cout << "\nNo Intersect";
	else
		std::cout << "\nIntersect at node " << res->dat;
*/


//	std::cout << "\nAfter removal of dups: ";	removeDups(&a);

//	std::cout << "Kth from last:\t" << kthFromLast(&a, 1)->dat;


//	std::cout << "After Removal: "; deleteMidNode(&a, &c);


//	std::cout << "After Partition(3): "; res =  partition(&a, 3);

//	std::cout << "Reversed List: ";

//	node<int>* res = reverseList(&a);

//	res = sumLists(&a, &d);

//	std::cout << "Is it Palidrome: " << palindrome(&a);






//	printList(res);

//	deleteLinkedList(res);

	std::cout << '\n';




	return 0;
}
