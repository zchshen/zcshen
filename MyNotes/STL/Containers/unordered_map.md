# [unordered_map](http://www.cplusplus.com/reference/unordered_map/unordered_map/)

># constructor
[constructor](http://www.cplusplus.com/reference/unordered_map/unordered_map/unordered_map/)
```
// constructing unordered_maps
#include <iostream>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string,std::string> stringmap;

stringmap merge (stringmap a,stringmap b) {
  stringmap temp(a); temp.insert(b.begin(),b.end()); return temp;
}

int main ()
{
  stringmap first;                              // empty
  stringmap second ( {{"apple","red"},{"lemon","yellow"}} );       // init list
  stringmap third ( {{"orange","orange"},{"strawberry","red"}} );  // init list
  stringmap fourth (second);                    // copy
  stringmap fifth (merge(third,fourth));        // move
  stringmap sixth (fifth.begin(),fifth.end());  // range

  std::cout << "sixth contains:";
  for (auto& x: sixth) std::cout << " " << x.first << ":" << x.second;
  std::cout << std::endl;

  return 0;
}

Possible output:
sixth contains: apple:red lemon:yellow orange:orange strawberry:red
```

># destructor
[destructor](http://www.cplusplus.com/reference/unordered_map/unordered_map/~unordered_map/)

># operator=
[operartor=](http://www.cplusplus.com/reference/unordered_map/unordered_map/operator=/)
```
// assignment operator with unordered_map
#include <iostream>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string,std::string> stringmap;

stringmap merge (stringmap a,stringmap b) {
  stringmap temp(a); temp.insert(b.begin(),b.end()); return temp;
}

int main ()
{
  stringmap first, second, third;
  first = {{"AAPL","Apple"},{"MSFT","Microsoft"}};  // init list
  second = {{"GOOG","Google"},{"ORCL","Oracle"}};   // init list
  third = merge(first,second);                      // move
  first = third;                                    // copy

  std::cout << "first contains:";
  for (auto& elem: first) std::cout << " " << elem.first << ":" << elem.second;
  std::cout << std::endl;

  return 0;
}

Possible output:
first contains: MSFT:Microsoft AAPL:Apple GOOG:Google ORCL:Oracle
```

># iterators
[begin](http://www.cplusplus.com/reference/unordered_map/unordered_map/begin/)
[end](http://www.cplusplus.com/reference/unordered_map/unordered_map/end/)
```
// unordered_map::begin/end example
#include <iostream>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap;
  mymap = {{"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"}};

  std::cout << "mymap contains:";
  for ( auto it = mymap.begin(); it != mymap.end(); ++it )
    std::cout << " " << it->first << ":" << it->second;
  std::cout << std::endl;

  std::cout << "mymap's buckets contain:\n";
  for ( unsigned i = 0; i < mymap.bucket_count(); ++i) {
    std::cout << "bucket #" << i << " contains:";
    for ( auto local_it = mymap.begin(i); local_it!= mymap.end(i); ++local_it )
      std::cout << " " << local_it->first << ":" << local_it->second;
    std::cout << std::endl;
  }

  return 0;
}

Possible output:
mymap contains: France:Paris Australia:Canberra U.S.:Washington
mymap's buckets contain:
bucket #0 contains:
bucket #1 contains:
bucket #2 contains:
bucket #3 contains:
bucket #4 contains:
bucket #5 contains: France:Paris
bucket #6 contains:
bucket #7 contains: Australia:Canberra
bucket #8 contains: U.S.:Washington
bucket #9 contains:
bucket #10 contains:
```

># const iterators
[cbegin](http://www.cplusplus.com/reference/unordered_map/unordered_map/cbegin/)
[cend](http://www.cplusplus.com/reference/unordered_map/unordered_map/cend/)
```
// unordered_map::cbegin/cend example
#include <iostream>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap;
  mymap = {{"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"}};

  std::cout << "mymap contains:";
  for ( auto it = mymap.cbegin(); it != mymap.cend(); ++it )
    std::cout << " " << it->first << ":" << it->second;  // cannot modify *it
  std::cout << std::endl;

  std::cout << "mymap's buckets contain:\n";
  for ( unsigned i = 0; i < mymap.bucket_count(); ++i) {
    std::cout << "bucket #" << i << " contains:";
    for ( auto local_it = mymap.cbegin(i); local_it!= mymap.cend(i); ++local_it )
      std::cout << " " << local_it->first << ":" << local_it->second;
    std::cout << std::endl;
  }

  return 0;
}

Possible output:
mymap contains: France:Paris Australia:Canberra U.S.:Washington
mymap's buckets contain:
bucket #0 contains:
bucket #1 contains:
bucket #2 contains:
bucket #3 contains:
bucket #4 contains:
bucket #5 contains: France:Paris
bucket #6 contains:
bucket #7 contains: Australia:Canberra
bucket #8 contains: U.S.:Washington
bucket #9 contains:
bucket #10 contains:
```

># capacity
[size](http://www.cplusplus.com/reference/unordered_map/unordered_map/size/)
```
// unordered_map::size
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,double> mymap = {
       {"milk",2.30},
       {"potatoes",1.90},
       {"eggs",0.40}
  };

  std::cout << "mymap.size() is " << mymap.size() << std::endl;

  return 0;
}

Output:
mymap.size() is 3
```

[max_size](http://www.cplusplus.com/reference/unordered_map/unordered_map/max_size/)
```
// unordered_map limits
#include <iostream>
#include <unordered_map>

int main ()
{
  std::unordered_map<int,int> mymap;

  std::cout << "max_size = " << mymap.max_size() << std::endl;
  std::cout << "max_bucket_count = " << mymap.max_bucket_count() << std::endl;
  std::cout << "max_load_factor = " << mymap.max_load_factor() << std::endl;

  return 0;
}

Possible output:
max_size = 357913941
max_bucket_count = 357913941
max_load_factor = 1
```

[empty](http://www.cplusplus.com/reference/unordered_map/unordered_map/empty/)
```
// unordered_map::empty
#include <iostream>
#include <unordered_map>

int main ()
{
  std::unordered_map<int,int> first;
  std::unordered_map<int,int> second = {{1,10},{2,20},{3,30}};
  std::cout << "first " << (first.empty() ? "is empty" : "is not empty" ) << std::endl;
  std::cout << "second " << (second.empty() ? "is empty" : "is not empty" ) << std::endl;
  return 0;
}

Output:
first is empty
second is not empty
```

[reserve](http://www.cplusplus.com/reference/unordered_map/unordered_map/reserve/)
```
// unordered_map::reserve
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap;

  mymap.reserve(6);

  mymap["house"] = "maison";
  mymap["apple"] = "pomme";
  mymap["tree"] = "arbre";
  mymap["book"] = "livre";
  mymap["door"] = "porte";
  mymap["grapefruit"] = "pamplemousse";

  for (auto& x: mymap) {
    std::cout << x.first << ": " << x.second << std::endl;
  }

  return 0;
}

Possible output:
book: livre
house: maison
grapefruit: pamplemousse
tree: arbre
apple: pomme
door: porte
```

># element access
[at](http://www.cplusplus.com/reference/unordered_map/unordered_map/at/)
```
// unordered_map::at
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,int> mymap = {
                { "Mars", 3000},
                { "Saturn", 60000},
                { "Jupiter", 70000 } };

  mymap.at("Mars") = 3396;
  mymap.at("Saturn") += 272;
  mymap.at("Jupiter") = mymap.at("Saturn") + 9638;

  for (auto& x: mymap) {
    std::cout << x.first << ": " << x.second << std::endl;
  }

  return 0;
}

Possible output:
Saturn: 60272
Mars: 3396
Jupiter: 69910
```

[operator\[\]](http://www.cplusplus.com/reference/unordered_map/unordered_map/operator[]/)
```
// unordered_map::operator[]
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap;

  mymap["Bakery"]="Barbara";  // new element inserted
  mymap["Seafood"]="Lisa";    // new element inserted
  mymap["Produce"]="John";    // new element inserted

  std::string name = mymap["Bakery"];   // existing element accessed (read)
  mymap["Seafood"] = name;              // existing element accessed (written)

  mymap["Bakery"] = mymap["Produce"];   // existing elements accessed (read/written)

  name = mymap["Deli"];      // non-existing element: new element "Deli" inserted!

  mymap["Produce"] = mymap["Gifts"];    // new element "Gifts" inserted, "Produce" written

  for (auto& x: mymap) {
    std::cout << x.first << ": " << x.second << std::endl;
  }

  return 0;
}

Possible output:
Seafood: Barbara
Deli:
Bakery: John
Gifts:
Produce:
```

># modifiers
[emplace](http://www.cplusplus.com/reference/unordered_map/unordered_map/emplace/)
```
// unordered_map::emplace
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap;

  mymap.emplace ("NCC-1701", "J.T. Kirk");
  mymap.emplace ("NCC-1701-D", "J.L. Picard");
  mymap.emplace ("NCC-74656", "K. Janeway");

  std::cout << "mymap contains:" << std::endl;
  for (auto& x: mymap)
    std::cout << x.first << ": " << x.second << std::endl;

  std::cout << std::endl;
  return 0;
}

Possible output:
mymap contains:
NCC-1701: J.T. Kirk
NCC-1701-D: J.L. Picard
NCC-74656: K. Janeway
```

[emplace_hint](http://www.cplusplus.com/reference/unordered_map/unordered_map/emplace_hint/)
```

```

[insert](http://www.cplusplus.com/reference/unordered_map/unordered_map/insert/)
```
// unordered_map::insert
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,double>
              myrecipe,
              mypantry = {{"milk",2.0},{"flour",1.5}};

  std::pair<std::string,double> myshopping ("baking powder",0.3);

  myrecipe.insert (myshopping);                        // copy insertion
  myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0)); // move insertion
  myrecipe.insert (mypantry.begin(), mypantry.end());  // range insertion
  myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );    // initializer list insertion

  std::cout << "myrecipe contains:" << std::endl;
  for (auto& x: myrecipe)
    std::cout << x.first << ": " << x.second << std::endl;

  std::cout << std::endl;
  return 0;
}

Possible output:
myrecipe contains:
salt: 0.1
eggs: 6
sugar: 0.8
baking powder: 0.3
flour: 1.5
milk: 2
```

[erase](http://www.cplusplus.com/reference/unordered_map/unordered_map/erase/)
```
// unordered_map::erase
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap;

  // populating container:
  mymap["U.S."] = "Washington";
  mymap["U.K."] = "London";
  mymap["France"] = "Paris";
  mymap["Russia"] = "Moscow";
  mymap["China"] = "Beijing";
  mymap["Germany"] = "Berlin";
  mymap["Japan"] = "Tokyo";

  // erase examples:
  mymap.erase ( mymap.begin() );      // erasing by iterator
  mymap.erase ("France");             // erasing by key
  mymap.erase ( mymap.find("China"), mymap.end() ); // erasing by range

  // show content:
  for ( auto& x: mymap )
    std::cout << x.first << ": " << x.second << std::endl;

  return 0;
}

Possible output:
Russia: Moscow
Japan: Tokyo
U.K.: London
```

[clear](http://www.cplusplus.com/reference/unordered_map/unordered_map/clear/)
```
// clearing unordered_map
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap =
         { {"house","maison"}, {"car","voiture"}, {"grapefruit","pamplemousse"} };

  std::cout << "mymap contains:";
  for (auto& x: mymap) std::cout << " " << x.first << "=" << x.second;
  std::cout << std::endl;

  mymap.clear();
  mymap["hello"]="bonjour";
  mymap["sun"]="soleil";

  std::cout << "mymap contains:";
  for (auto& x: mymap) std::cout << " " << x.first << "=" << x.second;
  std::cout << std::endl;

  return 0;
}

Possible output:
mymap contains: house=maison grapefruit=pamplemousse car=voiture
mymap contains: sun=soleil hello=bonjour
```

[swap](http://www.cplusplus.com/reference/unordered_map/unordered_map/swap/)
```
// unordered_map::swap
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string>
     first = {{"Star Wars","G. Lucas"},{"Alien","R. Scott"},{"Terminator","J. Cameron"}},
     second  = {{"Inception","C. Nolan"},{"Donnie Darko","R. Kelly"}};

  first.swap(second);

  std::cout << "first: ";
  for (auto& x: first) std::cout << x.first << " (" << x.second << "), ";
  std::cout << std::endl;

  std::cout << "second: ";
  for (auto& x: second) std::cout << x.first << " (" << x.second << "), ";
  std::cout << std::endl;

  return 0;
}

Possible output:
first: Inception (C. Nolan), Donnie Darko (R. Kelly),
second: Alien (R. Scott), Terminator (J. Cameron), Star Wars (G. Lucas),
```

># operations
[count](http://www.cplusplus.com/reference/unordered_map/unordered_map/count/)
```
// unordered_map::count
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,double> mymap = {
     {"Burger",2.99},
     {"Fries",1.99},
     {"Soda",1.50} };

  for (auto& x: {"Burger","Pizza","Salad","Soda"}) {
    if (mymap.count(x)>0)
      std::cout << "mymap has " << x << std::endl;
    else
      std::cout << "mymap has no " << x << std::endl;
  }

  return 0;
}

Output:
mymap has Burger
mymap has no Pizza
mymap has no Salad
mymap has Soda
```

[find](http://www.cplusplus.com/reference/unordered_map/unordered_map/find/)
```
// unordered_map::find
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,double> mymap = {
     {"mom",5.4},
     {"dad",6.1},
     {"bro",5.9} };

  std::string input;
  std::cout << "who? ";
  getline (std::cin,input);

  std::unordered_map<std::string,double>::const_iterator got = mymap.find (input);

  if ( got == mymap.end() )
    std::cout << "not found";
  else
    std::cout << got->first << " is " << got->second;

  std::cout << std::endl;

  return 0;
}

Possible output:
who? dad
dad is 6.1
```

[equal_range](http://www.cplusplus.com/reference/unordered_map/unordered_map/equal_range/)
```
// nothing
```

># observers
[get_allocator](http://www.cplusplus.com/reference/unordered_map/unordered_map/get_allocator/)
```
// nothing
```

[key_eq](http://www.cplusplus.com/reference/unordered_map/unordered_map/key_eq/)
```
// unordered_map::key_eq
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap;

  bool case_insensitive = mymap.key_eq()("test","TEST");

  std::cout << "mymap.key_eq() is ";
  std::cout << ( case_insensitive ? "case insensitive" : "case sensitive" );
  std::cout << std::endl;

  return 0;
}

Output:
mymap.key_eq() is case sensitive
```

[hash_function](http://www.cplusplus.com/reference/unordered_map/unordered_map/hash_function/)
```
// unordered_map::hash_function
#include <iostream>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string,std::string> stringmap;

int main ()
{
  stringmap mymap;

  stringmap::hasher fn = mymap.hash_function();

  std::cout << "this: " << fn ("this") << std::endl;
  std::cout << "thin: " << fn ("thin") << std::endl;

  return 0;
}

Possible output:
this: 671344778
thin: 3223852919
```

># buckets
[bucket](http://www.cplusplus.com/reference/unordered_map/unordered_map/bucket/)
```
// unordered_map::bucket
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap = {
    {"us","United States"},
    {"uk","United Kingdom"},
    {"fr","France"},
    {"de","Germany"}
  };

  for (auto& x: mymap) {
    std::cout << "Element [" << x.first << ":" << x.second << "]";
    std::cout << " is in bucket #" << mymap.bucket (x.first) << std::endl;
  }

  return 0;
}

Possible output:
Element [us:United States] is in bucket #1
Element [de:Germany] is in bucket #2
Element [fr:France] is in bucket #2
Element [uk:United Kingdom] is in bucket #4
```

[bucket_count](http://www.cplusplus.com/reference/unordered_map/unordered_map/bucket_count/)
```
// unordered_map::bucket_count
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap = {
            {"house","maison"},
            {"apple","pomme"},
            {"tree","arbre"},
            {"book","livre"},
            {"door","porte"},
            {"grapefruit","pamplemousse"}
  };

  unsigned n = mymap.bucket_count();

  std::cout << "mymap has " << n << " buckets.\n";

  for (unsigned i=0; i<n; ++i) {
    std::cout << "bucket #" << i << " contains: ";
    for (auto it = mymap.begin(i); it!=mymap.end(i); ++it)
      std::cout << "[" << it->first << ":" << it->second << "] ";
    std::cout << "\n";
  }

  return 0;
}

Possible output:
mymap has 7 buckets.
bucket #0 contains: [book:livre] [house:maison] 
bucket #1 contains: 
bucket #2 contains: 
bucket #3 contains: [grapefruit:pamplemousse] [tree:arbre]
bucket #4 contains: 
bucket #5 contains: [apple:pomme]
bucket #6 contains: [door:porte]
```

[bucket_size](http://www.cplusplus.com/reference/unordered_map/unordered_map/bucket_size/)
```
// unordered_map::bucket_size
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap = {
    {"us","United States"},
    {"uk","United Kingdom"},
    {"fr","France"},
    {"de","Germany"}
  };

  unsigned nbuckets = mymap.bucket_count();

  std::cout << "mymap has " << nbuckets << " buckets:\n";

  for (unsigned i=0; i<nbuckets; ++i) {
    std::cout << "bucket #" << i << " has " << mymap.bucket_size(i) << " elements.\n";
  }

  return 0;
}

Possible output:
mymap has 5 buckets:
bucket #0 has 0 elements.
bucket #1 has 1 elements.
bucket #2 has 2 elements.
bucket #3 has 0 elements.
bucket #4 has 1 elements.
```

[max_bucket_count](http://www.cplusplus.com/reference/unordered_map/unordered_map/max_bucket_count/)
```
// unordered_map limits
#include <iostream>
#include <unordered_map>

int main ()
{
  std::unordered_map<int,int> mymap;

  std::cout << "max_size = " << mymap.max_size() << std::endl;
  std::cout << "max_bucket_count = " << mymap.max_bucket_count() << std::endl;
  std::cout << "max_load_factor = " << mymap.max_load_factor() << std::endl;

  return 0;
}

Possible output:
max_size = 357913941
max_bucket_count = 357913941
max_load_factor = 1
```

># hash policy
[rehash](http://www.cplusplus.com/reference/unordered_map/unordered_map/rehash/)
```
// unordered_map::rehash
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap;

  mymap.rehash(20);

  mymap["house"] = "maison";
  mymap["apple"] = "pomme";
  mymap["tree"] = "arbre";
  mymap["book"] = "livre";
  mymap["door"] = "porte";
  mymap["grapefruit"] = "pamplemousse";

  std::cout << "current bucket_count: " << mymap.bucket_count() << std::endl;

  return 0;
}

Possible output:
current bucket_count: 23
```

[load_factor](http://www.cplusplus.com/reference/unordered_map/unordered_map/load_factor/)
```
// unordered_map hash table stats
#include <iostream>
#include <unordered_map>

int main ()
{
  std::unordered_map<int,int> mymap;

  std::cout << "size = " << mymap.size() << std::endl;
  std::cout << "bucket_count = " << mymap.bucket_count() << std::endl;
  std::cout << "load_factor = " << mymap.load_factor() << std::endl;
  std::cout << "max_load_factor = " << mymap.max_load_factor() << std::endl;

  return 0;
}

Possible output:
size = 0
bucket_count = 11
load_factor = 0
max_load_factor = 1
```

[max_load_factor](http://www.cplusplus.com/reference/unordered_map/unordered_map/max_load_factor/)
```
// unordered_map::max_load_factor
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap = {
    {"Au","gold"},
    {"Ag","Silver"},
    {"Cu","Copper"},
    {"Pt","Platinum"}
  };

  std::cout << "current max_load_factor: " << mymap.max_load_factor() << std::endl;
  std::cout << "current size: " << mymap.size() << std::endl;
  std::cout << "current bucket_count: " << mymap.bucket_count() << std::endl;
  std::cout << "current load_factor: " << mymap.load_factor() << std::endl;

  float z = mymap.max_load_factor();
  mymap.max_load_factor ( z / 2.0 );
  std::cout << "[max_load_factor halved]" << std::endl;

  std::cout << "new max_load_factor: " << mymap.max_load_factor() << std::endl;
  std::cout << "new size: " << mymap.size() << std::endl;
  std::cout << "new bucket_count: " << mymap.bucket_count() << std::endl;
  std::cout << "new load_factor: " << mymap.load_factor() << std::endl;

  return 0;
}

Possible output:
current max_load_factor: 1
current size: 4
current bucket_count: 5
current load_factor: 0.8
[max_load_factor halved]
new max_load_factor: 0.5
new size: 4
new bucket_count: 11
new load_factor: 0.363636
```