#include <string>
#include "myArray.hpp"

void printIntArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01()
{
    MyArray<int> array1(10);
    for (int i = 0; i < 10; i++)
    {
        array1.Push_back(i);
    }
    cout << "array1打印输出：" << endl;
    printIntArray(array1);
    cout << "array1的Size：" << array1.getSize() << endl;
    cout << "array1的Capacity：" << array1.getCapacity() << endl;

    cout << "--------------------------" << endl;

    MyArray<int> array2(array1);
    array2.Pop_back();
    cout << "array2打印输出：" << endl;
    printIntArray(array2);
    cout << "array2的Size：" << array2.getSize() << endl;
    cout << "array2的Capacity：" << array2.getCapacity() << endl;
}

// 测试自定义数据类型
class Person
{
public:
    Person() {}
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

public:
    string m_Name;
    int m_Age;
};

void printPersonArray(MyArray<Person> &personArr)
{
    for (int i = 0; i < personArr.getSize(); i++)
    {
        cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
    }
}

void test02()
{
    // 创建数组
    MyArray<Person> pArray(10);
    Person p1("孙悟空", 30);
    Person p2("韩信", 20);
    Person p3("妲己", 18);
    Person p4("王昭君", 15);
    Person p5("赵云", 24);

    // 插入数据
    pArray.Push_back(p1);
    pArray.Push_back(p2);
    pArray.Push_back(p3);
    pArray.Push_back(p4);
    pArray.Push_back(p5);

    printPersonArray(pArray);

    cout << "pArray的Size：" << pArray.getSize() << endl;
    cout << "pArray的Capacity：" << pArray.getCapacity() << endl;
}

int main()
{

    test01();

    test02();

    return 0;
}