//
//  main.cpp
//  Menu-Component-Composite
//
//  Created by MTX on 2022/4/2.
//

/*
 list 容器的成员函数
 push_front() 在它的头部添加一个元素
 push_back() 可以在 list 容器的末尾添加一个元素
 emplace_front() 和 emplace_back()
 
 insert() 在 list 容器内部添加元素
 
 // e.g.
 std::list<int> data(10, 55); // List of 10 elements with value 55
 data.insert(++begin(data), 66); // Insert 66 as the second element
 auto iter = begin(data);
 std::advance(iter, 9); // Increase iter by 9
 data.insert(iter, 3, 88);// Insert 3 copies of 88 starting at the 10th
 // 执行完上面的代码后，list 容器的内容如下：
 // 55 66 55 55 55 55 55 55 55 88 88 88 55 55
 // 将一段元素插入到data列表中
 std::vector<int> numbers(10, 5)/ // Vector of 10 elements with value 5
 data.insert(--(--end(data)), cbegin(numbers), cend(numbers));
 // 代码执行后，data 中的内容如下：
 // 55 66 55 55 55 55 55 55 55 88 88 88 5 5 5 5 5 5 5 5 5 5 55 55
 
 有三个函数可以在 list 容器中直接构造元素：
 emplace() 在迭代器指定的位置构造一个元素；
 emplace_front() 在 list 的第一个元素之前构造元素；
 emplace_back() 在 list 的尾部元素之后构造元素。
 
 // e.g.
 std::list<std::string> names {"Jane", "Jim", "Jules", "Janet"};
 names.emplace_back("Ann");
 std::string name ("Alan");
 names.emplace_back(std::move(name));
 names.emplace_front("Hugo");
 names.emplace(++begin(names), "Hannah");
 
 // std::move() 函数将 name 的右值引用传入 emplace_back() 函数。
 // 这个操作执行后，name 变为空，因为它的内容已经被移到 list 中。
 // 执行完这些语句后，names 中的内容如下：
 // "Hugo” "Hannah" "Jane" "Jim" "Jules" "Janet" "Ann" "Alan"
*/

/*
 std::move
 
 在C++11中，标准库在<utility>中提供了一个有用的函数std::move，std::move并不能移动任何东西
 它唯一的功能是将一个左值强制转化为右值引用，继而可以通过右值引用使用该值，以用于移动语义。
 从实现上讲，std::move基本等同于一个类型转换：static_cast<T&&>(lvalue);

 std::move函数可以以非常简单的方式将左值引用转换为右值引用。(左值 右值 引用 左值引用)概念

 C++ 标准库使用比如vector::push_back 等这类函数时,会对参数的对象进行复制,连数据也会复制.
 这就会造成对象内存的额外创建, 本来原意是想把参数push_back进去就行了,通过std::move，可以避免不必要的拷贝操作。
 
 std::move是将对象的状态或者所有权从一个对象转移到另一个对象，只是转移，没有内存的搬迁或者内存拷贝所以可以提高利用效率,改善性能.。
 对指针类型的标准库对象并不需要这么做.
 */

/*
// 递归函数
#include <iostream> // std::cout std::endl

// 求斐波那契数列的第n项。斐波那契数列定义：F(0)=0，F(1)=1, F(n)=F(n-1)+F(n-2)（n>=2，n∈N*），求第n项的值。
int fibonacci(int num)
{
    return num < 2 ? num : (fibonacci(num - 1) + fibonacci(num - 2));
}

int main(void)
{
    std::cout << fibonacci(6) << std::endl; //0、1、1、2、3、5、8...
    return 0;
}
*/

#include <list>
#include <iostream> // std::cout std::endl
#include <string>
using namespace std;

class MenuComponent {//构成层叠菜单的元素
protected: //Qustion 1
    string name;
public:
    void printMenu() { cout << name; }
    virtual void addMenuElement(MenuComponent *element) = 0;//Qustion 2
    virtual void removeMenuElement(MenuComponent *element) = 0;
    virtual list<MenuComponent *> * getElement() = 0;//Qustion 3
    string getMenuName() { return name; }
};

class MenuItem: public MenuComponent {
public:
    MenuItem(string name) { this->name = name; }
    void addMenuElement(MenuComponent *element) { return; }
    void removeMenuElement(MenuComponent *element) { return; }
    list<MenuComponent *> * getElement() { return NULL; }
};

class Menu: public MenuComponent {
private:
    //Use of class template 'list' requires template arguments
    list<MenuComponent *> elementList;//Qustion 4
public:
    Menu(string name) { this->name = name; }
    void addMenuElement(MenuComponent *element) { elementList.push_back(element); }
    void removeMenuElement(MenuComponent *element) { elementList.remove(element); }
    list<MenuComponent *> * getElement() { return &elementList; }
};

void printString(string& stringToPrint)
{
    cout << stringToPrint << endl;
}

void printMenu(MenuComponent& menuToPrint)
{
    menuToPrint.printMenu();
}

int main(int argc, const char * argv[]) {
    MenuComponent *mainMenu = new Menu("Insert");
    MenuComponent *subMenu = new Menu("Chart");
    MenuComponent *element = new MenuItem("On This Sheet");
    mainMenu->addMenuElement(subMenu);//Qustion 5
    subMenu->addMenuElement(element);

    //使用for循环来遍历一个list
    cout << "traversal method 1\n";
    list<MenuComponent *> * elementList = mainMenu->getElement();
    list<MenuComponent *>::iterator iter;
    list<string> nameList;
    for (iter = elementList->begin(); iter != elementList->end(); iter++)
    {
        //cout << *iter << endl;
        MenuComponent *comp = *iter;
        //Member reference type 'MenuComponent *' is a pointer; did you mean to use '->'?
        comp->printMenu();
        nameList.push_back(comp->getMenuName());
        cout << endl;
    }
    
    //使用STL的通用算法for_each来遍历list,自定义类不支持此遍历方式，建议转string或int等基础类型
    cout << "traversal method 2\n";
    for_each(nameList.begin(), nameList.end(), printString);
    return 0;
}
