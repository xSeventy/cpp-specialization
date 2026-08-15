#include "test_runner.h"

using namespace std;

template<typename T>
class Table {
public:
    
    Table(const size_t& s, const size_t& r) : table(s, vector<T>(r)) {}
    
    void Resize(const size_t& s, const size_t& r) {
        table.resize(s);
        for(auto& a : table) {
            a.resize(r);
        }
    }
    
    vector<T>& operator[] (const size_t s) {
        return table[s];
    }
    
    const vector<T>& operator[] (const size_t s) const {
        return table[s];
    }
    
    pair<size_t, size_t> Size() const {
        return make_pair(table.size(), table[0].size());
    }
    
private:
    vector<vector<T>> table;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
  ASSERT_EQUAL(t[0][0], 42);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}
