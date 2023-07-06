#include <iostream>

using namespace std;
template <typename T>
class ArrayList {
private:
    int len;
    T** arr;
    int msize;
    const int INIT_SIZE = 100;

    /**
    Truncates the array, effectively removing the element at the
    given index.
    */
    void truncate(int from) {
        if (from == len - 1) {
            len--;
            return;
        }

        for ( ; from < len - 1; from++)
            arr[from] = arr[from + 1];
        len--;
    }

    /**
    Initializing code for the various constructors.
    */
    void init(int init_size) {
        arr = new T*[init_size];
        len = 0;
        msize = init_size;
    }

public:

    /**
    Constructor for this ArrayList, which uses the INITAL_SIZE
    constant to specify a starting size.
    */
    ArrayList() {
        init(INIT_SIZE);
    }

    /**
    Constructor for this ArrayList, that lets the user specify a
    starting size.
    */
    ArrayList(int init_size) {
        init(init_size);
    }

    /**
    De-constructor for this ArrayList.
    */
    ~ArrayList() {
        delete(arr);
    }

    /**
    Adds the given data to this list.
    */
    void add(T& data) {
        if (len == msize) {
            T** to = new T*[len * 2];
            for (int i = 0; i < len; i++)
                to[i] = arr[i];
            delete(arr);
            arr = to;
        }

        T* ptr = &data;
        arr[len++] = ptr;
    }

    /**
    Takes the given data away from this list, effectively
    removing it.
    */
    void take(T& data) {
        for (int i = 0; i < len; i++) {
            if (&data == arr[i]) {
                truncate(i);
                break;
            }
        }
    }

    /**
    Takes the data at the given index away from this list,
    effectively removing it.
    */
    void take(int index) {
        if (index >= 0 && index < len)
            truncate(index);
    }

    /**
    Prints the contents of this list.
    */
    void print() {
        cout << "[";
        for (int i = 0; i < len; i++) {
            if (i != len - 1)
                cout << &*arr[i] << ", ";
            else
                cout << &*arr[i];
        }
        cout << "]" << endl;
    }

};

class Car {
public:
    int model;
};

int main() {
    Car cars[5];
    ArrayList<Car> list;

    for (int i = 0; i < 5; i++)
        list.add(cars[i]);
    list.print();
    list.take(4);
    list.print();
    return 0;
}
