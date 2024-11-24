#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
using namespace std;

int main() {
    // 示例1：字符串转换
    string text = "hello world";
    boost::to_upper(text);
    cout << "turn da: " << text << endl;  // 输出: HELLO WORLD

    // 示例2：字符串修剪
    string text2 = "   hello   ";
    boost::trim(text2);
    cout << "turn xiao: [" << text2 << "]" << endl;  // 输出: [hello]

    return 0;
}