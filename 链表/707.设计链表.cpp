/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
    //定义链表结构体
    struct LinkNode {
        int val;
        LinkNode* next;
        //使用构造函数来初始化结构体
        //将传入的参数val赋值给结构体中的val，为next赋值为空(nullptr)
        LinkNode(int val):val(val),next(nullptr){}
    };
    MyLinkedList() {
        _dummyHead = new LinkNode(0);//虚拟头结点，_是一种命名约定，这里是明确私有变量
        _size = 0;//将链表的大小初始化为0，表示当前没有节点
    }
    
    int get(int index) {
        //判断index是否合法
        if(index > (_size-1) || index < 0){
            return -1;
        }
        LinkNode* cur = _dummyHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkNode* newNode = new LinkNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkNode* newNode = new LinkNode(val);
        LinkNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        //判断index是否合法
        if(index > _size) return;
        //将小于0的插入点设置为0
        if(index < 0) index = 0;
        LinkNode* newNode = new LinkNode(val);
        LinkNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        //判断index是否合法
        if(index >= _size || index < 0){
            return;
        }
        LinkNode* cur = _dummyHead;
        while(index--) {
            cur = cur->next;
        }
        LinkNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        temp = nullptr;
        _size--;
    }
    void printLinkList() {
        LinkNode* cur = _dummyHead;
        while (cur->next != nullptr){
            cout<<cur->next->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
private:
    int _size;
    LinkNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

