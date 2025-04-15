#include <iostream>
#include <string>

using namespace std;

class InternalClass {
public:
    string fetch() {
        return "get user info";
    }
};

class ExternalClass {
public:
    string search() {
        return "get user info";
    }
};

class Adapter {
private:
    ExternalClass* external;

public:
    Adapter(ExternalClass* external) : external(external) {} // 생성자

    string fetch() {
        return external->search();
    }
};

int main() {
    ExternalClass external;
    Adapter adapter(&external);

    cout << adapter.fetch() << endl;

    return 0;
}
