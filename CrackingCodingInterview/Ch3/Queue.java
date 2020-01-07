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
<<<<<<< HEAD
	void push(T in){
		Node<T> inj = new Node<T>();
		inj.dat = in;

		if(head == null){
			head = inj;
		}
		if(tail == null){
			tail = inj;
		}
		else{
			tail.next = inj;
			tail = inj;
		}
=======
	void push(Node<T> in){
		tail.next = in;
		tail = in;
>>>>>>> 57462fbb641ad39c43ef7074f75faef70973ed25
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
