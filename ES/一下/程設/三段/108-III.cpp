class queue:public List
{
	public:
		void enqueue(const Node &value)
		{
			insertAtFront(value);
		}
		void dequeue(Node &value)
		{
			removeFromBack(value);
		}
};

class stack:public List
{
	public:
		void push(const Node &value)
		{
			insertAtFront(value);
		}
		void pop(Node &value)
		{
		removeFromFront(value);
	    }
};

class Queue
{
	public:
		void enqueue(const Node &value)
		{
			queueList.insertAtFront(value);
		}
		void dequeue(Node &value)
		{
			queueList.removeFromBack(value);
		}
	private:
	    List queueList;	
};

class Stack
{
	public:
		void push(const Node&value)
		{
			stackList.insertAtFront(value);
		}
		void pop(Node &value)
		{
			stackList.removeFromBack(value);
		}
	private:
		List stackList;
};
