public class SetOfStacks<T>{
	int capacity = 5;
	int topSize = 0;
	Stack<Stack<T>> set = new Stack<Stack<T>>();
	SetOfStacks(){
		capacity = 5;
		set.push(new Stack<T>());
	}
	void push(T entered){
		if(topSize == capacity){
			set.push(new Stack<T>());
			set.peek().push(entered);
			topSize = 1;
		}
		else{
			set.peek().push(entered);
			topSize++;
		}
	}

	T peek(){
		return set.peek().peek();
	}

	T pop(){
		T tmp = set.peek().pop();
		topSize--;
		if(set.peek().isEmpty()){
			set.pop();
			topSize = capacity;
		}
		return tmp;
	}



}
