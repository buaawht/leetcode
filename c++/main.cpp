#include <iostream>
#include <vector>

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
}

int main() {
    str_test();
    return 0;
}




