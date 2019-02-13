#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

void str_test() {
    string s1 = "hello hello hello hello hello hello 1234 7876";

    //从0位置开始查找第一个hello出现的首位位置
    size_t index1 = s1.find("hello", 0);
    cout << index1 << endl;

    //查找第一个hello出现时的首位位置
    size_t index2 = s1.find_first_of("hello");
    cout << index2 << endl;

    //查找最后一个hello出现时的末尾位置
    size_t index3 = s1.find_last_of("hello");
    cout << index3 << endl;

    //求hello出现的次数，以及对应的下标
    int count = 0;
    size_t offindex = s1.find("hello", 0);
    while (offindex != string::npos) {  //如果 offindex != -1
        //找到了
        cout << "索引:" << offindex << endl;
        count++;
        offindex++;
        offindex = s1.find("hello", offindex);
    }

    //把hello替换成welcome
    size_t offindex1 = s1.find("hello", 0);
    while (offindex1 != string::npos) {

        //从offindex1的位置开始删除5个位置，并插入新的字符串welcome
        s1.replace(offindex1, strlen("hello"), "welcome");

        //从后面的位置开始
        offindex1 += strlen("welcome");

        //继续查找
        offindex1 = s1.find("hello", offindex1);
    }
    cout << "替换后的字符串：" << s1 << endl;
    string str("hi sysu");
    for (auto it = str.begin(); it != str.end(); it++)
    {
        cout << *it << endl;
    }
}

template <typename T>
void showvector(vector<T> v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ", ";
    }
    cout << endl;
}
void vector_test() {
    vector<string> v6 = { "hi","my","name","is","lee" };
    v6.resize(3);  //重新调整vector容量大小
    showvector(v6);

    vector<int> v5 = { 1,2,3,4,5 }; //列表初始化,注意使用的是花括号
    cout << v5.front() << endl; //访问第一个元素
    cout << v5.back() << endl; //访问最后一个元素

    showvector(v5);
    v5.pop_back(); //删除最后一个元素
    showvector(v5);
    v5.push_back(6); //加入一个元素并把它放在最后
    showvector(v5);
    v5.insert(v5.begin()+1,9); //在第二个位置插入新元素
    showvector(v5);
    v5.erase(v5.begin() + 3);  //删除第四个元素
    showvector(v5);
    v5.insert(v5.begin() + 1, 7,8); //连续插入7个8
    showvector(v5);
    v5.clear(); //清除所有内容
    showvector(v5);

}

template <typename T>
void showset(set<T> v) {
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
}

void set_test() {
    set<int> s1{9,8,1,2,3,4,5,5,5,6,7,7 }; //自动排序，从小到大,剔除相同项
    showset(s1);
    set<string> s2{ "hello","sysy","school","hello" }; //字典序排序
    showset(s2);
    s1.insert(9); //有这个值了，do nothing
    showset(s1);
    cout << s1.count(777) << endl;
    s2.insert("aaa"); //没有这个字符串，添加并且排序
    showset(s2);
}


void showmap(map<string, int> v)
{
    for (map<string, int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << it->first << "  " << it->second << endl;  //注意用法，不是用*it来访问了。first表示的是key，second存的是value
    }
    cout << endl;
}

void map_test()
{
    map<string, int> m1; //<>里的第一个参数表示key的类型,第二个参数表示value的类型
    m1["Kobe"] = 100;
    m1["James"] = 99;
    m1["Curry"] = 98;

    string s("Jordan");
    m1[s] = 90;

    cout << m1["Kobe"] << endl;
    cout << m1["Jordan"] << endl;
    cout << m1["Durant"] << endl; //不存在这个key，就显示0

    m1.erase("Curry");//通过关键字来删除
    showmap(m1);
    m1.insert(pair<string, int>("Harris", 89)); //也可以通过insert函数来实现增加元素
    showmap(m1);
    cout << "Jordan: " << m1.at("Jordan") << endl;
    m1.clear(); //清空全部
}

int main() {

//    str_test();

//    vector_test();

//    set_test();

    map_test();
    return 0;
}




