#include <iostream>

using namespace std;

class Item {
public:
    Item *source;

    Item(Item *src) {
        source = src;
        cout << "Item() is called!" << endl;
    }

    virtual int out() { return 0; }
};

class Counter : public Item {
    int value;
public:
    int out() {
        return value++; // 这里返回的到底是value？还是 value+1 ?
    }

    Counter(int v) : Item(0) { value = v; }
};

class Filter : public Item {
    int factor; // 素数因子
public:
    int out() {
        while (1) {
            int n = source->out(); // 实际上形成了递归调用，递归检查当前 n 是否能被所有的比n小的素数整除
            if (n % factor) return n; // 返回不能整除当前素数的n
        }
    }

    Filter(Item *src, int f) : Item(src) { factor = f; }
};

class Sieve : public Item {
public:
    int out() {
        // 形成了一个 Filter 链表，每调用一次 Filter，就能找到一个素数，并且将以该素数为因子的Filter添加到链表中
        int n = source->out();
        source = new Filter(source, n);
        return n;
    }

    Sieve(Item *src) : Item(src) {
        cout << "Sieve() is called!" << endl;
    }
};

int main() {
    Counter c(2);
    Sieve s(&c);
    int next, n;
    n = 50;
    // cin >> n;
    while (1) {
        next = s.out();
        if (next > n) break;
        cout << next << " ";
    }
    cout << endl;
    return 0;
}
