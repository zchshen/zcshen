# Google C++编程命名约定 

1. 总体规则：不要随意缩写；
2. 宏、枚举等使用全部大写+下划线；
3. 变量（含类、结构体成员变量）、文件、命名空间、存取函数等使用全部小写+下划线，类成员变量以下划线结尾，全局变量以g_开头；
4. 参考现有或相近命名约定……   
命名约定最重要的一致性规则是命名管理，命名风格直接可以直接确定命名实体是：类型、变量、函数、常量、宏等等，无需查找实体声明，我们大脑中的模式匹配引擎依赖于这些命名规则。命名规则具有一定随意性，但相比按个人喜好命名，一致性更重要，所以不管你怎么想，规则总归是规则。  

> 通用命名规则（General Naming Rules）  

函数命名、变量命名、文件命名应具有描述性，不要过度缩写，类型和变量应该是名词，函数名可以用“命令性”动词。
如何命名：
尽可能给出描述性名称，不要节约空间，让别人很快理解你的代码更重要，好的命名选择：  

    int num_errors;                  // Good.    
    int num_completed_connections;   // Good.
 
丑陋的命名使用模糊的缩写或随意的字符：  

    int n;                           // Bad - meaningless.  
    int nerr;                        // Bad - ambiguous abbreviation.  
    int n_comp_conns;                // Bad - ambiguous abbreviation.
 
类型和变量名一般为名词：如FileOpener、num_errors。  

函数名通常是指令性的，如OpenFile()、set_num_errors()，访问函数需要描述的更细致，要与其访问的变量相吻合。  

缩写：
除非放到项目外也非常明了，否则不要使用缩写，例如：  

    // Good
    // These show proper names with no abbreviations.
    int num_dns_connections;  // Most people know what "DNS" stands for.
    int price_count_reader;   // OK, price count. Makes sense.
 
    // Bad!
    // Abbreviations can be confusing or ambiguous outside a small group.
    int wgc_connections;  // Only your group knows what this stands for.
    int pc_reader;        // Lots of things can be abbreviated "pc".
 
不要用省略字母的缩写：  

    int error_count;  // Good.
    int error_cnt;    // Bad.
 
> 文件命名（File Names）  

文件名要全部小写，可以包含下划线（_）或短线（-），按项目约定来。   
可接受的文件命名：

    my_useful_class.cc  
    my-useful-class.cc  
    myusefulclass.cc  

C++文件以.cc结尾，头文件以.h结尾。  
不要使用已经存在于/usr/include下的文件名（译者注，对UNIX、Linux等系统而言），如db.h。  
通常，尽量让文件名更加明确，http_server_logs.h就比logs.h要好，定义类时文件名一般成对出现，如foo_bar.h和foo_bar.cc，对应类FooBar。  
内联函数必须放在.h文件中，如果内联函数比较短，就直接放在.h中。如果代码比较长，可以放到以-inl.h结尾的文件中。对于包含大量内联代码的类，可以有三个文件：  

    url_table.h      // The class declaration.
    url_table.cc     // The class definition.
    url_table-inl.h  // Inline functions that include lots of code.
 
参考第一篇-inl.h文件一节。

> 类型命名（Type Names）  

类型命名每个单词以大写字母开头，不包含下划线：MyExcitingClass、MyExcitingEnum。  
所有类型命名——类、结构体、类型定义（typedef）、枚举——使用相同约定，例如：
 
    // classes and structs
    class UrlTable { ... 
    class UrlTableTester { ... 
    struct UrlTableProperties { ...

    // typedefs
    typedef hash_map<UrlTableProperties *, string> PropertiesMap;

    // enums
    enum UrlTableErrors { ...
 
> 变量命名（Variable Names）  

变量名一律小写，单词间以下划线相连，类的成员变量以下划线结尾，如my_exciting_local_variable、my_exciting_member_variable_。
普通变量命名：  

    举例：
    string table_name;  // OK - uses underscore.
    string tablename;   // OK - all lowercase.
    string tableName;   // Bad - mixed case.
 
 
类数据成员：  
结构体的数据成员可以和普通变量一样，不用像类那样接下划线：   

    struct UrlTableProperties {
        string name;
        int num_entries;
    }
 
结构体与类的讨论参考第三篇结构体vs.类一节。
全局变量：  
对全局变量没有特别要求，少用就好，可以以g_或其他易与局部变量区分的标志为前缀。  

> 常量命名（Constant Names）  

在名称前加k：kDaysInAWeek。  
所有编译时常量（无论是局部的、全局的还是类中的）和其他变量保持些许区别，k后接大写字母开头的单词：  

    const int kDaysInAWeek = 7;
 
> 函数命名（Function Names）  

普通函数（regular functions，译者注，这里与访问函数等特殊函数相对）大小写混合，存取函数（accessors and mutators）则要求与变量名匹配：

    MyExcitingFunction()、MyExcitingMethod()、my_exciting_member_variable()、set_my_exciting_member_variable()。

普通函数：  
函数名以大写字母开头，每个单词首字母大写，没有下划线：  

    AddTableEntry()
    DeleteUrl()
 
存取函数：   
存取函数要与存取的变量名匹配，这儿摘录一个拥有实例变量num_entries_的类： 

    class MyClass {
    public:
    ...
    int num_entries() const { return num_entries_; }
    void set_num_entries(int num_entries) { num_entries_ = num_entries; }

    private:
    int num_entries_;
    };
 
其他短小的内联函数名也可以使用小写字母，例如，在循环中调用这样的函数甚至都不需要缓存其值，小写命名就可以接受。  
译者注：从这一点上可以看出，小写的函数名意味着可以直接内联使用。  

> 命名空间（Namespace Names）  

命名空间的名称是全小写的，其命名基于项目名称和目录结构：google_awesome_project。
关于命名空间的讨论和如何命名，参考第二篇命名空间。  

> 枚举命名（Enumerator Names）  

枚举值应全部大写，单词间以下划线相连：MY_EXCITING_ENUM_VALUE。
枚举名称属于类型，因此大小写混合：UrlTableErrors。  

    enum UrlTableErrors {
    OK = 0,
    ERROR_OUT_OF_MEMORY,
    ERROR_MALFORMED_INPUT,
    };
 
> 宏命名（Macro Names）  

你并不打算使用宏，对吧？如果使用，像这样：  MY_MACRO_THAT_SCARES_SMALL_CHILDREN。  
参考第四篇预处理宏，通常是不使用宏的，如果绝对要用，其命名像枚举命名一样全部大写、使用下划线：
 
    #define ROUND(x) ...
    #define PI_ROUNDED 3.0
    MY_EXCITING_ENUM_VALUE
 
> 命名规则例外（Exceptions to Naming Rules）  

当命名与现有C/C++实体相似的对象时，可参考现有命名约定：   

    bigopen() 
    函数名，参考open() 
    uint 
    typedef类型定义 
    bigpos 
    struct或class，参考pos 
    sparse_hash_map 
    STL相似实体；参考STL命名约定 
    LONGLONG_MAX 
    常量，类似INT_MAX
______________________________________
译者：命名约定就相对轻松许多，在遵从代码一致性、可读性的前提下，略显随意：  
1. 总体规则：不要随意缩写，如果说ChangeLocalValue写作ChgLocVal还有情可原的话，把ModifyPlayerName写作MdfPlyNm就太过分了，除函数名可适当为动词外，其他命名尽量使用清晰易懂的名词；
2. 宏、枚举等使用全部大写+下划线；
3. 变量（含类、结构体成员变量）、文件、命名空间、存取函数等使用全部小写+下划线，类成员变量以下划线结尾，全局变量以g_开头；
4. 普通函数、类型（含类与结构体、枚举类型）、常量等使用大小写混合，不含下划线；
5. 参考现有或相近命名约定。