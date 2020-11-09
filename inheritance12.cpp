/* Sample Input/Output :

Enter a number: 4
2 3 1 4
You entered: 
1 2 3 4 
Again?(y/n): y
Enter a number: 4
4 4 1 2
You entered: 
1 2 4 4 
Again?(y/n): n

*/


#include <bits/stdc++.h>
using namespace std;

struct QueueNode
{
  int data;
  QueueNode *link;
};
typedef QueueNode *QueueNodePtr;

class Queue
{
  public:
    Queue(); //Initializes the object to an empty queue.
    Queue(const Queue &aQueue);

    void add(int item); //Postcondition: item has been added to the back of the queue.
    int remove();//Precondition: The queue is not empty.
    //Returns the item at the front of the queue and
    //removes that item from the queue.
    bool empty() const; //Returns true if the queue is empty. Returns false otherwise.
  
    QueueNodePtr front; //Points to the head of a linked list.
    //Items are removed at the head
    QueueNodePtr back; //Points to the node at the other end of the
    //linked list. Items are added at this end.
};

Queue::Queue() : front(NULL), back(NULL)
{
    //Intentionally empty.
}

//Uses cstddef:
bool Queue::empty() const
{
  return (back == NULL); //front == NULL would also work
}

//Uses cstddef:
void Queue::add(int item)
{
  if (empty())
  {
    front = new QueueNode;
    front->data = item;
    front->link = NULL;
    back = front;
  }
  else
  {
    QueueNodePtr temp_ptr;
    temp_ptr = new QueueNode;
    temp_ptr->data = item;
    temp_ptr->link = NULL;
    back->link = temp_ptr;
    back = temp_ptr;
  }
}
int Queue::remove()
{
  if (empty())
  {
    cout << "Error: Removing an item from an empty queue.\n";
    exit(1);
  }  
  int result = front->data;
  
  QueueNodePtr discard;
  discard = front;
  front = front->link;

  if (front == NULL) //if you removed the last node
  back = NULL;
    
  delete discard;
    
  return result;
}

//Uses cstdlib and iostream:
class PriorityQueue: public Queue
{
  public:
    int remove();
   
};

int PriorityQueue::remove()
{
  int min = INT_MAX;
  QueueNodePtr minp;
  QueueNodePtr p;
  QueueNodePtr prev;
  QueueNodePtr minprev = NULL;
  prev = NULL;
  minp = front;
  p = front;

  if (empty())
  {
    cout << "Error: Removing an item from an empty queue.\n";
    return 0;
    exit(1);
  }
  else if (p->link == NULL)
  {
    min = front->data;
    minp = front;
    delete (minp);
    front=NULL;
    back=NULL;
    return min;
  }

  else
  {
    while (p != NULL)
    {
      if (p->data < min)
      {
        min = p->data;
        minp = p;
        minprev = prev;
      }
      prev = p;
      p = p->link;    
    }
    if (min == front->data)
    {
      minp = front;
      min = front->data;
      front = front->link;
      free(minp);
      return min;
    }  
    minprev->link = minp->link;
    delete (minp);
    return (min);
  }
}

int main()
{
  PriorityQueue q;
  int n, arr[n];
  char ans;

  do
  {
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
      q.add(arr[i]);
    }

    cout << "You entered: \n";
    while (!q.empty())
    {
      cout << q.remove() << " ";
    }
    cout << "\n";
    cout << "Again?(y/n): ";
    cin >> ans;
    cin.ignore(10000, '\n');
  } while (ans != 'n' && ans != 'N');
  
  return 0;
}