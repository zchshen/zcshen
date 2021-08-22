# [priority_queue](http://www.cplusplus.com/reference/queue/priority_queue/)

># constructor
[constructor](http://www.cplusplus.com/reference/queue/priority_queue/priority_queue/)
```
// constructing priority queues
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

int main ()
{
  int myints[]= {10,60,50,20};

  std::priority_queue<int> first;
  std::priority_queue<int> second (myints,myints+4);
  std::priority_queue<int, std::vector<int>, std::greater<int> >
                            third (myints,myints+4);
  // using mycomparison:
  typedef std::priority_queue<int,std::vector<int>,mycomparison> mypq_type;

  mypq_type fourth;                       // less-than comparison
  mypq_type fifth (mycomparison(true));   // greater-than comparison

  return 0;
}

The example does not produce any output, but it constructs different priority_queue objects:
- First is empty.
- Second contains the four ints defined for myints, with 60 (the highest) at its top.
- Third has the same four ints, but because it uses greater instead of the default (which is less), it has 10 as its top element.
- Fourth and fifth are very similar to first: they are both empty, except that these use mycomparison for comparisons, which is a special stateful comparison function that behaves differently depending on a flag set on construction.
```

># destructor

># empty
[empty](http://www.cplusplus.com/reference/queue/priority_queue/empty/)
```
// priority_queue::empty
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue

int main ()
{
  std::priority_queue<int> mypq;
  int sum (0);

  for (int i=1;i<=10;i++) mypq.push(i);

  while (!mypq.empty())
  {
     sum += mypq.top();
     mypq.pop();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}

The example initializes the content of the priority queue to a sequence of numbers (form 1 to 10). It then pops the elements one by one until it is empty and calculates their sum.

Output:
total: 55
```

># size
[size](http://www.cplusplus.com/reference/queue/priority_queue/size/)
```
// priority_queue::size
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue

int main ()
{
  std::priority_queue<int> myints;
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

># top
[top](http://www.cplusplus.com/reference/queue/priority_queue/top/)
```
// priority_queue::top
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue

int main ()
{
  std::priority_queue<int> mypq;

  mypq.push(10);
  mypq.push(20);
  mypq.push(15);

  std::cout << "mypq.top() is now " << mypq.top() << '\n';

  return 0;
}

Output:
mypq.top() is now 20
```

># push
[push](http://www.cplusplus.com/reference/queue/priority_queue/push/)
[pop](http://www.cplusplus.com/reference/queue/priority_queue/pop/)
```
// priority_queue::push/pop
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue

int main ()
{
  std::priority_queue<int> mypq;

  mypq.push(30);
  mypq.push(100);
  mypq.push(25);
  mypq.push(40);

  std::cout << "Popping out elements...";
  while (!mypq.empty())
  {
     std::cout << ' ' << mypq.top();
     mypq.pop();
  }
  std::cout << '\n';

  return 0;
}

Output:
Popping out elements... 100 40 30 25
```

># emplace
[emplace](http://www.cplusplus.com/reference/queue/priority_queue/emplace/)
```
// priority_queue::emplace
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <string>         // std::string

int main ()
{
  std::priority_queue<std::string> mypq;

  mypq.emplace("orange");
  mypq.emplace("strawberry");
  mypq.emplace("apple");
  mypq.emplace("pear");

  std::cout << "mypq contains:";
  while (!mypq.empty())
  {
     std::cout << ' ' << mypq.top();
     mypq.pop();
  }
  std::cout << '\n';

  return 0;
}

Output:

mypq contains: strawberry pear orange apple
```

># swap
[swap](http://www.cplusplus.com/reference/queue/priority_queue/swap/)
```
// priority_queue::swap
#include <iostream>       // std::cout
#include <queue>          // std::priority_queue

int main ()
{
  std::priority_queue<int> foo,bar;
  foo.push (15); foo.push(30); foo.push(10);
  bar.push (101); bar.push(202);

  foo.swap(bar);

  std::cout << "size of foo: " << foo.size() << '\n';
  std::cout << "size of bar: " << bar.size() << '\n';

  return 0;
}

Output:

size of foo: 2
size of bar: 3
```