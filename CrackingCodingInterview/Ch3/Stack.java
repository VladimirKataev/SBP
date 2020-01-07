public class Stack<T>{
	class Node<T>{
		Node<T> nxt;
		T dat;
	}

	private Node<T> top;
	Stack(){
		top = null;
	}
	void push(T in){
		Node<T> tmp = new Node<T>();
		tmp.dat = in;
		tmp.nxt = top;
		top = tmp;
	}
	T peek(){
		return top.dat;
	}
	T pop(){
		Node<T> tmp = top;
		top = top.nxt;
		return tmp.dat;
	}
<<<<<<< HEAD
	boolean isEmpty(){ return top == null;}
=======
>>>>>>> 57462fbb641ad39c43ef7074f75faef70973ed25
}
