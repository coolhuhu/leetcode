// 第296场周赛第4题
// 6093. 设计一个文本编辑器
// 提示1：在某些数据结构的中间进行更改通常比更改同一数据结构的前/后更难。
// 提示2：你能把你的数据结构（带光标的文本）分成两部分，这样每一部分只在它的末端发生变化吗？
// 提示3：你能想到一个支持高效移除/添加到前/后的数据结构吗？
// 提示4：尝试通过分别维护前缀和后缀来解决两个双端队列的问题。

#include<list>
#include<string>
using namespace std;

class TextEditor {
    list<char> lt;
    list<char>::iterator cur = lt.begin();

public:
    TextEditor() {

    }
    
    void addText(string text) {
        for (auto c : text) {
            lt.insert(cur, c);
        }
    }
    
    int deleteText(int k) {
        
    }
    
    string cursorLeft(int k) {

    }
    
    string cursorRight(int k) {

    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */