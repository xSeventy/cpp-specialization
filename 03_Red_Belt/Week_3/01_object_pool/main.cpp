#include "test_runner.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <stdexcept>
#include <set>
#include <deque>

using namespace std;

template <class T>
class ObjectPool {
public:
    T* Allocate() {
        if(released.size() > 0) {
            T* obj = released.front();
            allotted.insert(obj);
            released.pop_front();
            return obj;
        } else {
            T* obj = new T;
            allotted.insert(obj);
            return obj;
        }
    }
    
    T* TryAllocate() {
        if(released.size() > 0) {
            T* obj = released.front();
            allotted.insert(obj);
            released.pop_front();
            return obj;
        } else {
            return nullptr;
        }
    }
    
    void Deallocate(T* object) {
        if(!allotted.count(object)) {
            throw invalid_argument("error");
        } else {
            released.push_back(object);
            allotted.erase(object);
        }
        
    }
    
    ~ObjectPool() {
        for(auto a : released) {
            delete a;
        }
        for(auto a : allotted) {
            delete a;
        }
    }
    
private:
    // Добавьте сюда поля
    deque<T*> released;
    set<T*> allotted;
};

void TestObjectPool() {
    ObjectPool<string> pool;
    
    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();
    
    *p1 = "first";
    *p2 = "second";
    *p3 = "third";
    
    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");
    
    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");
    
    pool.Deallocate(p1);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}
