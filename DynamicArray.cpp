#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
template<class T>
class List
{
public:
    int GetIndex(unsigned int i) {
        return (i >= _Lengh) ? 0 : *StartPoint[i];
    }
    void Read() {
        for (int i = 0; i < _Lengh; i++) {
             cout<< *StartPoint[i] << endl;
        }
    }
    int Lengh() {
        return _Lengh;
    }
    void Add(T value)
    {
        MemoryPointCreate(&value);
    }
    int * GetAll() {
        int GetAllList[_Lengh];
        for (int i = 0; i < _Lengh;i++) {
            GetAllList[i] = *StartPoint[i];
        }
        return GetAllList;
    }
private:
    int _Lengh = 0;
    T** StartPoint;
    T *_FirstValue = new T[1];

    void MemoryPointCreate(T* value, int Type = 0) {
        T* NPoint = new T[1]; // (typeid(value))malloc(typeid(*value).name() + 1);
        *NPoint = *value;
        MemoryExpansion(NPoint);
    }
    void MemoryExpansion(T* NValue) {
        if (_Lengh > 0) {
            _Lengh++;
            T** NewStartPoint = StartPoint;
            StartPoint = new T * [_Lengh];
            for (int i = 0; i < _Lengh-1; i++)
            {
                StartPoint[i] = NewStartPoint[i];
            }
            StartPoint[_Lengh - 1] = NValue;
            free(NewStartPoint);
        }
        else {
            _Lengh++;
            StartPoint = new T * [_Lengh];
            StartPoint[0] = NValue;
        }
    }
};
int main()
{
    List<int> array;
    array.Add(10);
    array.Add(20);
    array.Add(30);
    //array.Read();
    for (int i = 0; i < array.Lengh(); i++)
    {
        cout << array.GetIndex(i)<<endl;

    }
}
