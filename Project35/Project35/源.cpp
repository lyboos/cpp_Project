#define  _CRT_SECURE_NO_WARNINGS 
#pragma once
#include<iostream>
#include<cstddef>
#include <string>
#include <vector>
#include<cctype>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <iterator>
#include <cmath>
using namespace std;
long long hash1(int key) {
   long long res = llabs(3 * pow(key, 3) + 5 * pow(key, 2) + 7 * key + 11);
   return res;
}
struct Node {
	int key;
	string val;
	Node* next;
//    int key=-99;
//    string value;
//    node* next;
//    int num;
};

int curNum = 0;
void reHash(vector<Node*>& nodes) {
		int newLen = nodes.size() * 2 + 1;
		vector<Node*> res(newLen, nullptr);
		vector<Node*> store;
		for (Node* n : nodes) {
			if (n != nullptr) {
				Node* copy1 = n;
				while (copy1 != nullptr) {
					Node* tmpNode = new Node();
					tmpNode->val = copy1->val;
					tmpNode->key = copy1->key;
					store.push_back(tmpNode);
					copy1 = copy1->next;
				}
			}
		}
		for (Node* node : store) {
			long long hash = hash1(node->key);
			int pos = hash % newLen;
			if (res[pos] == nullptr)
				res[pos] = node;
			else {
				Node* tmp = res[pos];
				if (tmp->key > node->key) {
					res[pos] = node;
					node->next = tmp;
				}
				else {
					while (tmp->next != nullptr) {
						if (tmp->next->key > node->key) {
							node->next = tmp->next;
							tmp->next = node;
							break;
						}
						tmp = tmp->next;
					}
					if (tmp->next == nullptr)
						tmp->next = node;
				}
			}
		}
		nodes = res;
		for (int i = 0; i < newLen; i++) {
			if (nodes[i] != nullptr) {
				Node* tNode = nodes[i];
				int curLen = 0;
				while (tNode != nullptr) {
					curLen++;
					tNode = tNode->next;
				}
				if (curLen > 4) {
					reHash(nodes);
					return;
				}
			}
		}
		return;
	}
	void addKey(vector<Node*>& nodes, Node* node) {
		long long hash = hash1(node->key);
		int length = nodes.size();
		int pos = hash % length;
		if (nodes[pos] == nullptr) {
			nodes[pos] = node;
			if (curNum > nodes.size()) {
				reHash(nodes);
				return;
			}
		}
		else {
			Node* tmp = nodes[pos];
			if (tmp->key > node->key) {
				nodes[pos] = node;
				node->next = tmp;
			}
			else {
				while (tmp->next != nullptr) {
					if (tmp->next->key > node->key) {
						node->next = tmp->next;
						tmp->next = node;
						break;
					}
					tmp = tmp->next;
				}
				if (tmp->next == nullptr)
					tmp->next = node;
			}
			if (curNum > nodes.size()) {
				reHash(nodes);
				return;
			}
			//局部量扩容
			int curLen = 0;
			tmp = nodes[pos];
			while (tmp != nullptr) {
				curLen++;
				tmp = tmp->next;
			}
			if (curLen > 4)
				reHash(nodes);
		}
		return;
	}
	void hashTable(vector<Node*>& nodes, int n) {
		//    hashmap map;
		//    int l; cin >> l; cin.get();
		//    int size = 0;
		//    int n; cin >> n; cin.get();
		//    string order[100];
		//    for (int i = 0; i < n; i++)
		//    {
		//        getline(cin, order[i]);
		//    }
		//    int key, pos; string value; node* node1, * node2;
		//    node empty = { -99,"lyboos",nullptr,-99 };
		//    for (int i = 0; i < 1000; i++)
		//    {
		//        map.entry[i] = empty;
		//    }
		for (int i = 1; i <= n; i++) {
			string order;
			cin >> order;
			if (order.at(0) == 'a') {
				curNum++;
				Node* node = new Node();
				cin >> node->key >> node->val;
				addKey(nodes, node);
			}
			else if (order.at(0) == 's') {
				//            case 2:
					//                key = key1(order[i]);
					//                pos = hash1(key);
					//                node1 = (node*)malloc(sizeof(node));
					//                map.entry[pos] = *node1;
					//                break;
				int pos;
				cin >> pos;
				if (nodes[pos] == nullptr) {
					cout << "null" << endl;
				}
				else {
					Node* node = nodes[pos];
					while (node->next != nullptr) {
						cout << node->key << ":" << node->val << "->";
						node = node->next;
					}
					cout << node->key << ":" << node->val << endl;
				}
			}
			else if (order.at(0) == 'd') {
				//            case 3:
				//                pos = key1(order[i]);
				//                node1 = &map.entry[pos];
				//                if (map.entry[pos].key == -99) {
				//                    cout << "null" << endl;
				//                }					              else {
					//                    do
					//                    {
					//                        cout << node1->key << ":" << node1->value;
					//                        if (node1->next != nullptr)
					//                        {
					//                            cout << "->";
					//                            node1 = node1->next;
					//                        }
					//                    } while (node1->next!=nullptr);
					//                }
					//                break;
					//            default:break;
					//        }
					//    }
				int key;
				cin >> key;
				curNum--;
				long long hash = hash1(key);
				int len = nodes.size();
				int pos = hash % len;
				Node* node = nodes[pos];
				if (node->key == key) {
					nodes[pos] = node->next;
				}
				else {
					while (node->next != nullptr) {
						if (node->next->key == key) {
							node->next = node->next->next;
							break;
						}
						node = node->next;
					}
				}
			}
		}
	}
int main() {
	int n;
	cin >> n;
	vector<Node*> nodes(n, nullptr);
	int m;
	cin >> m;
	hashTable(nodes, m);
}

//
//struct hashmap {
//    node entry[1000];
//    int size;
//};
//

//
//
//int whichorder(string str) {
//    if (str.at(0) == 'a') return 1;
//    if (str.at(0) == 'd') return 2;
//    if (str.at(0) == 's') return 3;
//    return -1;
//}
//int key1(string str) {
//    string s = " ";
//    vector<string> result = split(str,s);
//    return atoi(result[1].c_str());
//}
//
//string value1(string str) {
//    string s = " ";
//    vector<string> result = split(str, s);
//    return result[2];
//}
//

//int main() {

//    return 0;
//}


//#ifndef _HASHMAP_H_
//#define _HASHMAP_H_
//
//template<class Key, class Value>
//class HashNode
//{
//public:
//    Key    _key;
//    Value  _value;
//    HashNode *next;
//
//    HashNode(Key key, Value value)
//    {
//        _key = key;
//        _value = value;
//        next = NULL;
//    }
//    ~HashNode()
//    {
//
//    }
//    HashNode& operator=(const HashNode& node)
//    {
//        _key  = node._key;
//        _value = node._value;
//        next = node.next;
//        return *this;
//    }
//};
//
//template <class Key, class Value, class HashFunc, class EqualKey>
//class HashMap
//{
//public:
//    HashMap(int size);
//    ~HashMap();
//    bool insert(const Key& key, const Value& value);
//    bool del(const Key& key);
//    HashNode<Key, Value>& find(const Key& key);
//    HashNode<Key, Value>& operator [](const Key& key);
//    HashNode<Key, Value>** table;
//    HashFunc hash;
//    EqualKey equal;
//    Value ValueNULL;
//    HashNode<Key, Value>& nodeNULL;
//
//private:
//    unsigned int _size;
//};
//
//
//template <class Key, class Value, class HashFunc, class EqualKey>
//HashMap<Key, Value, HashFunc, EqualKey>::HashMap(int size) : _size(size),hash(),equal()
//{
//    table = new HashNode<Key, Value>*[_size];
//    for (unsigned i = 0; i < _size; i++)
//        table[i] = NULL;
//}
//
//
//
//template <class Key, class Value, class HashFunc, class EqualKey>
//HashMap<Key, Value, HashFunc, EqualKey>::~HashMap()
//{
//    for (unsigned i = 0; i < _size; i++)
//    {
//        HashNode<Key, Value> *currentNode = table[i];
//        while (currentNode)
//        {
//            HashNode<Key, Value> *temp = currentNode;
//            currentNode = currentNode->next;
//            delete temp;
//        }
//    }
//    delete table;
//}
//
//
//template <class Key, class Value, class HashFunc, class EqualKey>
//bool HashMap<Key, Value, HashFunc, EqualKey>::insert(const Key& key, const Value& value)
//{
//    int index = hash(key)%_size;
//    HashNode<Key, Value> * node = new HashNode<Key, Value>(key,value);
//    node->next = table[index];
//    table[index] = node;
//    return true;
//}
//
//
//template <class Key, class Value, class HashFunc, class EqualKey>
//bool HashMap<Key, Value, HashFunc, EqualKey>::del(const Key& key)
//{
//    unsigned index = hash(key) % _size;
//    HashNode<Key, Value> * node = table[index];
//    HashNode<Key, Value> * prev = NULL;
//    while (node)
//    {
//        if (node->_key == key)
//        {
//            if (prev == NULL)
//            {
//                table[index] = node->next;
//            }
//            else
//            {
//                prev->next = node->next;
//            }
//            delete node;
//            return true;
//        }
//        prev = node;
//        node = node->next;
//    }
//    return false;
//}
//
//template <class Key, class Value, class HashFunc, class EqualKey>
//HashNode<Key,Value>& HashMap<Key, Value, HashFunc, EqualKey>::find(const Key& key)
//{
//    unsigned  index = hash(key) % _size;
//    if (table[index] == NULL) {
//        cout << "null" << endl;
//        HashNode<int, string>& temp = new HashNode<int, string>(-1, NULL);
//        return nodeNULL;
//    }
//    else
//    {
//        HashNode<Key, Value> * node = table[index];
//        while (node)
//        {
//            if (node->_key == key)
//                return *node;
//            node = node->next;
//        }
//    }
//}
//
//
//template <class Key, class Value, class HashFunc, class EqualKey>
//HashNode<Key,Value>& HashMap<Key, Value, HashFunc, EqualKey>::operator [](const Key& key)
//{
//    return find(key);
//}
//
//
//#endif
//
//class HashFunc
//{
//public:
//    int operator()(const int& key)
//    {
//        int hash = 0;
//        hash = abs(3*key*key*key+5*key*key+7*key+11);
//        return hash;
//    }
//};
//
//class EqualKey
//{
//public:
//    bool operator()(const string& A, const string& B)
//    {
//        if (A.compare(B) == 0)
//            return true;
//        else
//            return false;
//    }
//};
//
//int main() {
//    int l; cin >> l; cin.get();
//    HashMap<int, string, HashFunc, EqualKey> hashmap(100);
//
//    hashmap.insert(10, "cpp");
//    hashmap.insert(5, "cat");
//    hashmap.insert(3, "dog");
//   // hashmap.insert("welcome", "haha");
//    HashNode<int,string> node1 = hashmap.find(5);
//    HashNode<int, string> node2 = hashmap.find(5);
//    HashNode<int, string> node3 = hashmap.find(5);
//
//    cout << "after insert:" << endl;
//    //cout << hashmap.find(10) << endl;
//    //cout << hashmap.find(5) << endl;
//   // cout << hashmap["why"].c_str() << endl;
//   // cout << hashmap["hello"].c_str() << endl;
//
//    //if (hashmap.del(10))
//    //    cout << "remove is ok" << endl;    //remove is ok
//   // cout << hashmap.find(10).c_str() << endl; //not exist print NULL
//
//   // hashmap["why"] = "love";
//   // cout << hashmap["why"].c_str() << endl;
//    return 0;
//}
//void print(vector<string> arr) {
//    int length = arr.size();
//    for (int i = 0; i < length; i++)
//    {
//        cout << arr[i] << endl;
//    }
//}
//void asDefault(vector<string> arr) {
//    int length = arr.size();
//    string temp;
//    for (int i = 0; i < length; i++)
//    {
//        for (int j = 0; j +1< length-i; j++)
//        {
//            if (arr[j] > arr[j + 1]) {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//    print(arr);
//}
//
//bool cmp_num(string a, string b) {
//    int anum = atoi(a.c_str());
//    int bnum = atoi(b.c_str());
//    if (anum > bnum)
//        return true;
//    return false;
//}
//void asNumval(vector<string> arr) {
//    int length = arr.size();
//    string temp;
//    for (int i = 0; i < length; i++)
//    {
//        for (int j = 0; j + 1 < length - i; j++)
//        {
//            if (cmp_num(arr[j] , arr[j + 1])) {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//    print(arr);
//}
//bool cmp_alpha(string a, string b) {
//    int length = a.size() > b.size() ? b.size() : a.size();
//    for (int i = 0,j=0; i < a.size()&&j<b.size();)
//    {
//        char an = a.at(i), bn = b.at(j);
//        if (isalpha(an) && isalpha(bn)) {
//            if ((((an - bn) == 32)|| (an - bn) == -32)) {
//                if (an - bn > 0) return true;
//                else if (an - bn < 0) return false;
//                i++, j++;
//                continue;
//            }
//            if ((an <= 90 && bn <= 90) || (an >= 97 && bn >= 97))
//            {
//                if (an - bn > 0) return true;
//                else if (an - bn < 0) return false;
//            }
//            else if (an >= 97 && bn <= 90) {
//                an -= 32;
//                if (an - bn > 0) return true;
//                else if (an - bn < 0) return false;
//            }
//            else if (bn >= 97 && an <= 90) {
//                bn -= 32;
//                if (an - bn > 0) return true;
//                else if (an - bn < 0) return false;
//            }
//            i++, j++;
//        }
//        else {
//            if (an - bn > 0) return true;
//            else if(an - bn < 0) return false;
//            i++, j++;
//        }
//    }
//}
//void asAlpha(vector<string> arr) {
//    int length = arr.size();
//    string temp;
//    for (int i = 0; i < length; i++)
//    {
//        for (int j = 0; j + 1 < length - i; j++)
//        {
//            if (cmp_alpha(arr[j], arr[j + 1])) {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//    print(arr);
//}
//
//bool isSuit(char an) {
//    if (isalnum(an)) return true;
//    if (isspace(an)) return true;
//    if (isalpha(an)) return true;
//    return false;
//}
//bool cmp_alphaAndNum(string a, string b) {
//    int length = a.size() > b.size() ? b.size() : a.size();
//    for (int i = 0,j=0; i < a.size()&&j<b.size();)
//    {
//        char an = a.at(i), bn = b.at(j);
//        if (isSuit(an) && isSuit(bn)) {
//            if (an - bn > 0) return true;
//            else if (an - bn < 0) return false;
//            i++; j++;
//        }
//        else if (isSuit(an)) {
//            j++;
//        }
//        else if (isSuit(bn)) {
//            i++;
//        }
//        else {
//            i++, j++;
//        }
//    }
//    if (a.size() > length)
//        return true;
//    else return false;
//}
//void onlyNumandAlpha(vector<string> arr) {
//    int length = arr.size();
//    string temp;
//    for (int i = 0; i < length; i++)
//    {
//        for (int j = 0; j + 1 < length - i; j++)
//        {
//            if (cmp_alphaAndNum(arr[j], arr[j + 1])) {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//    print(arr);
//}
//void asReverse(vector<string> arr) {
//    int length = arr.size();
//    string temp;
//    for (int i = 0; i < length; i++)
//    {
//        for (int j = 0; j + 1 < length - i; j++)
//        {
//            if (arr[j] < arr[j + 1]) {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//    print(arr);
//}
//
//int main() {
//    vector<string> arr;
//    size_t n;
//    cin >> n; cin.get();
//    //std::cin >> std::ws;
//    string s;
//    for (int i = 0; i < n; i++)
//    {
//        getline(cin,s);
//        arr.push_back(s);
//    }
//    int c;
//    cin >> c; cin.get();
//    //std::cin >> std::ws;
//    string order[100];
//    for (int i = 0; i < c; i++)
//    {
//        getline(cin, order[i]);
//    }
//    for (int i = 0; i < c; i++)
//    {
//        switch (order[i][0]) {
//        case '-':
//            asDefault(arr);
//            break;
//        case 'n':
//            asNumval(arr);
//            break;
//        case 'i':
//            asAlpha(arr);
//            break;
//        case 'd':
//            onlyNumandAlpha(arr);
//            break;
//        case 'r':
//            asReverse(arr);
//            break;
//        default:break;
//        }
//    }
//    return 0;
//}


//int whichorder(char order[100]) {
//    if (order[0] == 'p') {
//        if (order[1] == 'u') {
//            if (order[4] == 'F') {
//                return 1;
//            }
//            else if (order[4] == 'B') {
//                return 2;
//            }
//        }
//        if (order[1] == 'o') {
//            if (order[3] == 'F') {
//                return 3;
//            }
//            else if (order[3] == 'B') {
//                return 4;
//            }
//        }
//    }
//    else if (order[0] == 'g') {
//        if (order[1] == 'e')
//            if (order[3] == 'S')
//                return 5;
//    }
//    return -1;
//}
//
//struct Node {
//    Node* next;//后一个节点
//    Node* prev;//前一个节点
//    int val;//该节点存放的数字
//};
////双端队列
//struct Deque {
//    int size;//有效节点数
//    Node* front;//虚拟头节点，不作为有效节点
//    Node* rear;//虚拟尾节点，不作为有效节点
//};
//void push_front(Deque* self, int value) {
//    Node* head = self->front->next;
//    Node* back = self->rear->prev;
//    if (self->front->next==self->rear) {
//        Node* node1 = (Node*)malloc(sizeof(Node));
//        *node1 = { self->rear,self->front,value };
//        self->front->next = node1;
//        self->rear->prev=node1;
//    }
//    else {
//        Node* node1 = (Node*)malloc(sizeof(Node));
//        *node1 = { head,self->front,value };
//        self->front->next = node1;
//        head->prev = node1;
//    }
//    self->size++;
//}
//void push_back(Deque* self, int value) {
//    Node* head = self->front->next;
//    Node* back = self->rear->prev;
//    if (self->front->next == self->rear) {
//        Node* node1 = (Node*)malloc(sizeof(Node));
//        *node1 = { self->rear,self->front,value };
//        self->front->next = node1;
//        self->rear->prev = node1;
//    }
//    else {
//        Node* node1 = (Node*)malloc(sizeof(Node));
//        *node1 = { self->rear,back,value };
//        self->rear->prev = node1;
//        back->next = node1;
//    }
//    self->size++;
//}
//void pop_front(Deque* self) {
//    Node* head = self->front->next;
//    Node* back = self->rear->prev;
//    if (self->front->next == self->rear) {
//        cout << -1 << endl;
//    }
//    else {
//        cout << head->val << endl;
//        (self->front)->next = head->next;
//        (head->next)->prev = self->front;
//        self->size--;
//    }
//}
//void pop_back(Deque* self) {
//    Node* head = self->front->next;
//    Node* back = self->rear->prev;
//    if (self->front->next == self->rear) {
//        cout << -1 << endl;
//    }
//    else {
//        cout << back->val << endl;
//        self->rear->prev = back->prev;
//        back->prev->next = self->rear;
//        self->size--;
//    }
//}
//void getsize(Deque* self) {
//    cout << self->size << endl;
//}
//void substing(char* pSrc, char* pDes, int StartPos, int len)
//{
//    if (StartPos > strlen(pSrc))
//        return;
//    len = (strlen(pSrc) - StartPos) > len ? len : (strlen(pSrc) - StartPos);
//    strncpy(pDes, pSrc + StartPos, len);
//    pDes[len] = '\0';
//}
//int main() {
//    int n;
//    Node front = { nullptr,nullptr,-1};
//    Node rear = { nullptr,nullptr,-2};
//    rear.prev = &front;
//    front.next = &rear;
//    Deque deque1 = {0,&front,&rear};
//    Deque* deque = &deque1;
//    cin >> n; cin.get();
//    string s[100];
//    for (int i = 0; i < n; i++)
//    {
//        getline(cin, s[i]);
//    }
//    int val; char* pointer;
//    for(int i=0;i<n;i++)
//    {
//        char* order = (char *)s[i].c_str();
//        switch (whichorder(order))
//        {
//        case 1:
//            val = atoi(s[i].substr(9).c_str());
//            push_front(deque, val);
//            break;
//        case 2:
//            val = atoi(s[i].substr(8).c_str());
//            push_back(deque, val);
//            break;
//        case 3:
//            pop_front(deque);
//            break;
//        case 4:
//            pop_back(deque);
//            break;
//        case 5:
//            getsize(deque);
//            break;
//        default:
//            break;
//        }
//    }
//    return 0;
//}
//int main() {
//    int src[101][101] = { 0 };
//    int n; 
//    char ch;
//    cin >> n; 
//    std::size_t n_rows1, n_cols1;
//    std::cin >> n_rows1 >> n_cols1;
//    for (int i = 0; i < n_rows1; i++) {
//        std::copy_n(std::istream_iterator<int>(std::cin), n_cols1, src[i]);
//    }
//    //cin.get(ch); cin.get(ch);
//    //for (int i = 0; i < n_rows1; i++) {
//    //    int index = 0;
//    //    while (cin.get(ch) && ch != '\r') {
//    //        src[i][index] = (int)(ch-'1'); // 空白符也一起读进来
//    //        index++;
//    //    }
//    //    cin.get();
//    //}
//    for (int y = 1; y < n; y++)
//    {
//        int mat[101][101] = { 0 };
//        int res[101][101] = { 0 };
//        std::size_t n_rows, n_cols;
//        std::cin >> n_rows >> n_cols; cin.get(ch); cin.get(ch);
//        //for (int i = 0; i < n_rows1; i++) {
//        //    int index = 0;
//        //    while (cin.get(ch) && ch != '\r') {
//        //        src[i][index] = (int)(ch - '1'); // 空白符也一起读进来
//        //        index++;
//        //    }
//        //    cin.get(ch);
//        //}
//        for (int f = 0; f < n_rows; f++) {
//            std::copy_n(std::istream_iterator<int>(std::cin), n_cols, mat[f]);
//        }
//
//        for (int i = 0; i < n_rows1; i++)
//        {
//            for (int j = 0; j < n_rows; j++)
//            {
//                for (int k = 0; k < n_cols; k++)
//                {
//                    res[i][k] += (src[i][j]*mat[j][k]);
//                }
//            }
//        }
//        for (int  f= 0;  f< 10; f++) {
//            for (int j = 0; j < 10; j++)
//            {
//                src[f][j] = res[f][j];
//            }
//        }
//        n_rows1 = n_rows1; n_cols1=n_cols;
//    }
//    for (int f = 0; f < n_rows1; f++)
//    {
//        for (int j = 0; j < n_cols1; j++)
//            cout << src[f][j] << " ";
//        cout << endl;
//    }
//    return 0;
//}




//typedef struct A {
//    int a;
//    A* next;
//}A;
//vector<int> dfs(A* head) {
//    A* pre = nullptr;
//    A* cur = head;
//    A* temp = cur;
//    while (cur) {
//        temp = cur->next; //需要现保存一下，不然断开了就找不到了
//        cur->next = pre;
//        pre = cur; // pre 和 cur分别向右边平移
//        cur = temp;
//    }
//    vector<int> ret;
//    while (pre) {
//        ret.push_back(pre->a);
//        pre = pre->next;
//    }
//    return ret;
//}
//
//void add(A** head, int a) {
//    A* tem = (A*)malloc(sizeof(A));
//    tem->a = a; tem->next = nullptr;
//    (*head)->next = tem;
//    (*head)= (*head)->next;
//}
//int main() {
//    A* head=(A*)malloc(sizeof(A));
//    A* temp = head;
//    int ch; int count = 0;
//    while (scanf("%d",&ch))
//    {
//         count++;
//         add(&temp, ch);
//    }
//    vector<int> ret=dfs(head->next);
//    for (int i = 0; i <count; i++)
//    {
//        cout << ret[i] << ' ';
//    }
//    return 0;
//}
//int main() {
//    char bfcode[10000] = { 0 }, paper[1000] = { 0 };
//    int pointer = 0;
//    int stack[1000], stp = 0;
//    
//    cin.getline(bfcode, 10000);
//    for (int i = 0; bfcode[i] != '\0'; i++)
//    {
//        switch (bfcode[i]) {
//        case '+':
//            paper[pointer]++;
//            break;
//        case '-':
//            paper[pointer]--;
//            break;
//        case '>':
//            pointer++;
//            break;
//        case '<':
//            pointer ? pointer-- : pointer;
//            break;
//        case ',':
//            scanf("%c", &paper[pointer]);
//            break;
//        case '.':
//            printf("%c", paper[pointer]);
//            break;
//        case '[':
//            if (paper[pointer] == 0) {
//                int number = 0;
//                while (!(bfcode[i] == ']' && number == 1)) {
//                    if (bfcode[i] == '[') number++;
//                    else if (bfcode[i] == ']') number--;
//                    i++;
//                }
//            }
//            break;
//        case ']':
//            if (paper[pointer] != 0) {
//                int number = 0;
//                while (!(bfcode[i] == '[' && number == 1)) {
//                    if (bfcode[i] == ']') number++;
//                    else if (bfcode[i] == '[') number--;
//                    i--;
//                }
//            }
//            break;
//        default:break;
//        }
//    }
//    return 0;
//}

//int main() {
//    char res[20][120] = { 0 };
//    int n;
//    char str[60];
//    cin >> str >> n;
//    int row = 0,column=0;
//    for (int i = 0; i < strlen(str); i++)
//    {
//        int index = i % (2 * n - 2);
//        bool flag = true;
//        if (index < n) flag = false;
//        index = index < n ? index : 2 * n - 2 - index;
//        char temp[] = {str[i],' ','\0'};
//        strcat(res[index], temp);
//        if(flag)
//        for (int i = 0; i < n; i++)
//        {
//            if (i != index) {
//                strcat(res[i], "  ");
//            }
//        }
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cout << res[i] << endl;
//    }
//    return 0;
//}
//int capacity = 0;
//int num = 0;
//void add(int** arr, char* order) {
//    int* arry = *arr;
//    if (*arr == NULL) {
//        arry =(int *)malloc(sizeof(int) * 10);
//        capacity = 10;
//        *arr = arry;
//    }
//    else if(capacity==num){
//        int n= capacity + (capacity >> 1);
//        int* temp = NULL;
//        temp=*arr;
//        arry = (int*)malloc(sizeof(int)*n);
//        for (int i = 0; i < n; i++)
//        {
//            *(arry + i) = *(temp+i);
//        }
//        capacity = capacity + (capacity >> 1);
//        *arr = arry;
//    }
//    order += 4;
//    int n = atoi(order);
//    *(arry + num) = n;
//    num++;
//    *arr = arry;
//}
//
//void remove(int** arr, char order[51]) {
//    int* arry = *arr;
//    order += 6;
//    int n = atoi(order);
//    int i = 0;
//    for (i = 0; i < num; i++)
//    {
//        if (*(arry + i) == n) {
//            break;
//        }
//    }
//    int* temp= (int*)malloc(sizeof(int) * capacity);
//    if (i < num) {
//        int j = 0;
//        for (j = 0; j < i; j++)
//        {
//            *(temp + j) = *(arry + j);
//        }
//        for (int k = i+1; k < num; k++)
//        {
//            *(temp + j + k - i-1) = *(arry+k);
//        }
//        num--;
//    }
//}
//
//void get(int** arr, char order[51]) {
//    order += 4;
//    int n = atoi(order);
//    if (n >= capacity || n >= num || n <0)
//    {
//        cout << -1 << endl;
//        return;
//    }
//    int* arry = *arr;
//    cout << *(arry + n) << endl;
//}
//
//
//void getsize(int** arr) {
//    if (*arr == NULL) {
//        cout << 0 << endl;
//    }
//    else {
//        cout << num << endl;
//    }
//}
//
//void getcapa(int** arr) {
//    if (*arr == NULL) {
//        cout << 0 << endl;
//    }
//    else {
//        cout << capacity << endl;
//    }
//}
//
//
//int main() {
//    char order[20][51] = { 0 };
//    int n;
//    int* arr= NULL;
//    scanf("%d", &n);
//    cin.get();
//    for (int i = 0; i < n; i++)
//    {
//        cin.getline(order[i], 51);
//    }
//    for (int i = 0; i < n; i++)
//    {
//        switch (order[i][0])
//        {
//        case 'a':
//            add(&arr, order[i]);
//            break;
//        case 'r':
//            remove(&arr, order[i]);
//            break;
//        case 'g':
//            if (order[i][3] == ' ') get(&arr, order[i]);
//            else if (order[i][3] == 'S') getsize(&arr);
//            else if (order[i][3] == 'C') getcapa(&arr);
//        default:
//            break;
//        }
//    }
//    return 0;
//}

//int main() {
//    int n = 0, m = 0;
//    cin >> n >> m;
//    int arr[50][50] = { 0 };
//    int arr2[50][50] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++) {
//            scanf("%d",&arr[i][j]);
//        }
//    }
//    for (int k = 0; k < (m/90); k++)
//    {
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++)
//            {
//                arr2[j][n - i-1] = arr[i][j];
//            }
//        }
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++)
//            {
//                arr[i][j] = arr2[i][j];
//            }
//        }
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//            cout << arr2[i][j]<<' ';
//        cout << '\n';
//    }
//    return 0;
//}
//int main() {
//    int n = 0, m = 0;
//    cin >> n >> m;
//    int arr[50][50] = { 0 };
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++) {
//            cin >> arr[i][j];
//        }
//    }
//
//    int left = 0, right = m - 1, top = 0, bottom = n - 1;
//    while (true)
//    {
//        if (left > right) break;
//        for (int i = left; i <= right; i++)
//        {
//          
//            cout << arr[top][i] << ' ';
//        }
//        top++;
//
//
//        if (top > bottom) break;
//        for (int i = top; i <= bottom ; i++)
//        {
//            cout << arr[i][right] << ' ';
//        }
//        right--;
//
//
//        if (left > right) break;
//        for (int i = right; i >= left; i--)
//        {
//            cout << arr[bottom][i] << ' ';
//        }
//        bottom--;
//
//
//        if (top > bottom) break;
//        for (int i = bottom; i >= top; i--)
//        {
//            cout << arr[i][left] << ' ';
//        }
//        left++;
//    }
//
//
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++) {
//            if(j!=m-1)
//            cout << arr[i][j]<<' ';
//            else cout << arr[i][j] << '\n';
//        }
//    }
//    return 0;
//}
//int main() {
//    string pszSource;
//    char temp;
//    while (cin.get(temp)) {
//        pszSource = pszSource + temp;
//    }
//    string output;
//    int nByteSrc = pszSource.size();
//    const char* enkey = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
//    std::string pszEncode(nByteSrc * 4 / 3 + 4, '\0');
//    int nLoop = nByteSrc % 3 == 0 ? nByteSrc : nByteSrc - 3;
//    int n = 0;
//    int i = 0;
//    for ( i = 0; i < nLoop; i += 3)
//    {
//           pszEncode[n] = enkey[pszSource[i] >> 2];
//               pszEncode[n + 1] = enkey[((pszSource[i] & 3) << 4) | ((pszSource[i + 1] & 0xF0) >> 4)];
//                pszEncode[n + 2] = enkey[((pszSource[i + 1] & 0x0f) << 2) | ((pszSource[i + 2] & 0xc0) >> 6)];
//                 pszEncode[n + 3] = enkey[pszSource[i + 2] & 0x3F];
//              n += 4;
//    }
//   
//    switch (nByteSrc % 3)
//    {
//            case 0:
//                     pszEncode[n] = '\0';
//                     break;
//            
//             case 1:
//                     pszEncode[n] = enkey[pszSource[i] >> 2];
//                     pszEncode[n + 1] = enkey[((pszSource[i] & 3) << 4) | ((0 & 0xf0) >> 4)];
//                     pszEncode[n + 2] = '=';
//                   pszEncode[n + 3] = '=';
//                    pszEncode[n + 4] = '\0';
//                     break;
//            
//             case 2:
//                     pszEncode[n] = enkey[pszSource[i] >> 2];
//                     pszEncode[n + 1] = enkey[((pszSource[i] & 3) << 4) | ((pszSource[i + 1] & 0xf0) >> 4)];
//                   pszEncode[n + 2] = enkey[((pszSource[i + 1] & 0xf) << 2) | ((0 & 0xc0) >> 6)];
//                     pszEncode[n + 3] = '=';
//                     pszEncode[n + 4] = '\0';
//                     break;
//                 }
//    
//       cout<<pszEncode;
//   
//    return 0;
//}
//    string output;
    /*string input;
    char temp;
    int num = 0, line = 0;
    while (cin.get(temp)) {
        input = input + temp;
    }
    int flag = 0;
    for (int i = 0; i < input.size(); i++)
    {
        switch (input.at(i))
        {
        case ' ':
            if (flag == 1) num++;
            flag = 0;
            break;
        case '\n':
            if (flag == 1) num++;
            flag = 0;
            line++;
            break;
        default:
            flag = 1;
            break;
        }
    }
    if (input.size() == 0) num = 0, line = 0;
    cout << input.size() << ' ' << num << ' ' << line;*/
    
/*int n;
    cin >> n;
    cin >> ws;
    string* dict=new string[5000];
    char* tmp = new char[100];
    int f = 0, m = 0;
    for (int i = 0; i < n; i++)
    {
        cin.getline(tmp, 100);
        int num = atoi(tmp);
        char* gender1 = strstr(tmp," ");
        char gender = *(gender1 + 1);
        if (gender == 'f') {
            f += num;
        }
        else if (gender == 'm') {
            m += num;
        }
    }
    cout << "f: " << f << endl;
    cout << "m: " << m << endl;*/
    /*int num = 0;
    int line = 0;
    int words = 0;
    string* dict[5000];
    int i = 0;
    while (cin.get()!='\n') {
        dict[i] = new string();
        getline(cin, *dict[i]);
        cout << *dict[i];
        i++;
    }*/
    /*int n = 0, count = 0;
    int tmp;
    int arr[10000];
    while (cin >> tmp) {
        arr[count] = tmp;
        n = arr[count] ^ n;
        count++;
    }
    cout << n;*/
    //cin >> n;
    //for (int i = 0; i < n; i++) {
    //    cin >> arr[i];
    //}
    //long long sum=1;
    //for (int i = 0; i < n; i++)
    //{
    //    sum *= arr[i];
    //    //int64_t tmp = (int64_t)sum * (int64_t)arr[i];
    //    //if ((int32_t)((int32_t)tmp) != tmp)
    //        // overflow occurred
    //    if(sum > numeric_limits<int>::max()||sum< numeric_limits<int>::min())
    //    //if(arr[i]!=0&&sum==0)
    //    {
    //        cout << -1;
    //        break;
    //    }
    //    else {
    //        cout << sum;
    //    }
    //    if (i != n - 1) cout << ' ';
    //}
        /*string numstr; long num;
        stringstream aa;
        cin >> numstr;
        aa << numstr;
        aa >> num;
        if (num >= 0) {

            num = rev(num);
            cout << num << endl;
        }
        else
        {
            num = -num;
            num = rev(num);
            if(num==0)  cout << -1<< endl;
            else cout << '-'<<num << endl;
        }*/
 /*       return 0;
}*/


//int rev(long m)
//{
//    if (m > numeric_limits<int>::max())
//        return -1;
//    long t = 0;
//    while (m > 0)
//    {
//        t = t * 10 + m % 10;
//        m = m / 10;
//    }
//    return t;
//}