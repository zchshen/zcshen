# [queue(FIFO)](http://www.cplusplus.com/reference/queue/queue/)

># constructor
[constructor](http://www.cplusplus.com/reference/queue/queue/queue/)
```
// constructing queues
#include <iostream>       // std::cout
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue

int main ()
{
  std::deque<int> mydeck (3,100);        // deque with 3 elements
  std::list<int> mylist (2,200);         // list with 2 elements

  std::queue<int> first;                 // empty queue
  std::queue<int> second (mydeck);       // queue initialized to copy of deque

  std::queue<int,std::list<int> > third; // empty queue with list as underlying container
  std::queue<int,std::list<int> > fourth (mylist);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}

Output:
size of first: 0
size of second: 3
size of third: 0
size of fourth: 2
```

># empty
[empty](http://www.cplusplus.com/reference/queue/queue/empty/)
```
// queue::empty
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> myqueue;
  int sum (0);

  for (int i=1;i<=10;i++) myqueue.push(i);

  while (!myqueue.empty())
  {
     sum += myqueue.front();
     myqueue.pop();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}

The example initializes the content of the queue to a sequence of numbers (form 1 to 10). It then pops the elements one by one until it is empty and calculates their sum.

Output:
total: 55
```

># size
[size](http://www.cplusplus.com/reference/queue/queue/size/)
```
// queue::size
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

  return 0;
}

Output:
0. size: 0
1. size: 5
2. size: 4
```

># front
[front](http://www.cplusplus.com/reference/queue/queue/front/)
```
// queue::front
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> myqueue;

  myqueue.push(77);
  myqueue.push(16);

  myqueue.front() -= myqueue.back();    // 77-16=61

  std::cout << "myqueue.front() is now " << myqueue.front() << '\n';

  return 0;
}

Output:
myqueue.front() is now 61
```

># back
[back](http://www.cplusplus.com/reference/queue/queue/back/)
```
// queue::back
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> myqueue;

  myqueue.push(12);
  myqueue.push(75);   // this is now the back

  myqueue.back() -= myqueue.front();

  std::cout << "myqueue.back() is now " << myqueue.back() << '\n';

  return 0;
}

Output:
myqueue.back() is now 63
```

># push
[push](http://www.cplusplus.com/reference/queue/queue/push/)  
[pop](http://www.cplusplus.com/reference/queue/queue/pop/)
```
// queue::push/pop
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> myqueue;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    std::cin >> myint;
    myqueue.push (myint);
  } while (myint);

  std::cout << "myqueue contains: ";
  while (!myqueue.empty())
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';

  return 0;
}

The example uses push to add a new elements to the queue, which are then popped out in the same order.
```

># emplace
[emplace](http://www.cplusplus.com/reference/queue/queue/emplace/)
```
// queue::emplace
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue
#include <string>         // std::string, std::getline(string)

int main ()
{
  std::queue<std::string> myqueue;

  myqueue.emplace ("First sentence");
  myqueue.emplace ("Second sentence");

  std::cout << "myqueue contains:\n";
  while (!myqueue.empty())
  {
    std::cout << myqueue.front() << '\n';
    myqueue.pop();
  }

  return 0;
}

Output:

myqueue contains:
First sentence
Second sentence
```

># swap
[swap](http://www.cplusplus.com/reference/queue/queue/swap/)
```
// queue::swap
#include <iostream>       // std::cout
#include <queue>          // std::queue

int main ()
{
  std::queue<int> foo,bar;
  foo.push (10); foo.push(20); foo.push(30);
  bar.push (111); bar.push(222);

  foo.swap(bar);

  std::cout << "size of foo: " << foo.size() << '\n';
  std::cout << "size of bar: " << bar.size() << '\n';

  return 0;
}

Output:

size of foo: 2
size of bar: 3
```