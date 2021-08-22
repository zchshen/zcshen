# [stack(LIFO)](http://www.cplusplus.com/reference/stack/stack/)

># constructor
[constructor](http://www.cplusplus.com/reference/stack/stack/)
```
// constructing stacks
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque

int main ()
{
  std::deque<int> mydeque (3,100);          // deque with 3 elements
  std::vector<int> myvector (2,200);        // vector with 2 elements

  std::stack<int> first;                    // empty stack
  std::stack<int> second (mydeque);         // stack initialized to copy of deque

  std::stack<int,std::vector<int> > third;  // empty stack using vector
  std::stack<int,std::vector<int> > fourth (myvector);

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

># destructor

># empty
[empty](http://www.cplusplus.com/reference/stack/stack/empty/)
```
// stack::empty
#include <iostream>       // std::cout
#include <stack>          // std::stack

int main ()
{
  std::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}

The example initializes the content of the stack to a sequence of numbers (form 1 to 10). It then pops the elements one by one until it is empty and calculates their sum.

Output:
total: 55
```

># size
[size](http://www.cplusplus.com/reference/stack/stack/size/)
```
// stack::size
#include <iostream>       // std::cout
#include <stack>          // std::stack

int main ()
{
  std::stack<int> myints;
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
[top](http://www.cplusplus.com/reference/stack/stack/top/)
```
// stack::top
#include <iostream>       // std::cout
#include <stack>          // std::stack

int main ()
{
  std::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';

  return 0;
}

Output:
mystack.top() is now 15
```

># push
[push](http://www.cplusplus.com/reference/stack/stack/push/)  
[pop](http://www.cplusplus.com/reference/stack/stack/pop/)

```
// stack::push/pop
#include <iostream>       // std::cout
#include <stack>          // std::stack

int main ()
{
  std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

  return 0;
}

Output:
Popping out elements... 4 3 2 1 0
```

># emplace
[emplace](http://www.cplusplus.com/reference/stack/stack/emplace/)
```
// stack::emplace
#include <iostream>       // std::cin, std::cout
#include <stack>          // std::stack
#include <string>         // std::string, std::getline(string)

int main ()
{
  std::stack<std::string> mystack;

  mystack.emplace ("First sentence");
  mystack.emplace ("Second sentence");

  std::cout << "mystack contains:\n";
  while (!mystack.empty())
  {
    std::cout << mystack.top() << '\n';
    mystack.pop();
  }

  return 0;
}

Output:

mystack contains:
Second sentence
First sentence
```

># swap
[swap](http://www.cplusplus.com/reference/stack/stack/swap/)
```
// stack::swap
#include <iostream>       // std::cout
#include <stack>          // std::stack

int main ()
{
  std::stack<int> foo,bar;
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