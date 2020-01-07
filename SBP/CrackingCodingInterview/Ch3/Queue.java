public class Queue<T>{
	class Node<T>{
		Node<T> next;
		T dat;
	}
	Node<T> head;
	Node<T> tail;
	Queue(){
		head = null;
		tail = null;
	}

	T peek(){
		if(head == null){return null;}
		return head.dat;
	}
	void push(Node<T> in){
		tail.next = in;
		tail = in;
	}
	boolean isEmpty(){
		if(head == null){return true;}
		return false;
	}
	T pop(){
		T tmp = head.dat;
		head = head.next;
		return tmp;
	}


}
