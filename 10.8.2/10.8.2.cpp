#include <iostream>
#include <fstream>
using namespace std;

class Collection
{

    private:
        int max_size;
        int current_index;
        char* arr;

    public:

        Collection(int);
        Collection(const Collection&);
        ~Collection();

        void add(char);
        void del(int);

        void output();

        bool operator%(char);


};

Collection::Collection(int max_size)
{
    this->max_size = max_size;
    this->arr = new char[max_size];
    this->current_index = 0;
}

Collection::Collection(const Collection& c)
{
    this->max_size = c.max_size;
    this->arr = new char[max_size];
    this->current_index = c.current_index;

    for (int i = 0; i < max_size; i++)
        arr[i] = c.arr[i];
}

Collection::~Collection()
{
    delete [] arr;
}

void Collection::add(char element)
{

    if (current_index == max_size || current_index < 0)
        return;

    arr[current_index++] = element;

}

void Collection::del(int index)
{

    if (index < 0 || index > current_index)
        return;

    for (int i = index; i < current_index - 1; i++)
        arr[i] = arr[i + 1];

    current_index--;

}

void Collection::output()
{
    for (int i = 0; i < current_index; i++)
        cout << arr[i] << " ";

}

bool Collection::operator%(char element)
{

    for (int i = 0; i < current_index; i++)
        if (arr[i] == element)
            return true;

    return false;

}

void read_collection(ifstream& input, Collection& c)
{
    while (true)
    {
        if (input.eof())
            break;

        char element;
        input >> element;

        if (input.eof())
            break;

        c.add(element);
    }
}

int main()
{

    ifstream input("test.txt");

    Collection collection(20);
    read_collection(input, collection);

    collection.output();

    collection.add('k'); 
    collection.del(5); 

    cout << "\n\nCollection after adding (k) and removing element with index 5 (f):\n";

    collection.output();

    cout << "\n\nTesting whether (k) is in the collection: " << ((collection % 'k')?"k is in the collection":"k is not in the collection");
    cout << "\nTesting whether (f) is in the collection: " << ((collection % 'f')?"f is in the collection":"f is not in the collection");

    cin.get();

    return 0;
}
