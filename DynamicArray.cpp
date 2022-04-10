#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
template<class T>
class List
{
public:
    int GetIndex(unsigned int i) {
        return (i >= _Lengh) ?  0 : StartPoint[i];
    }
    void Read() {
        for (int i = 0; i < _Lengh; i++) {
            cout << StartPoint[i] << endl;
        }
    }
    int Lengh() {
        return _Lengh;
    }
    void Add(T value)
    {
        if (_Lengh > 0) {
             _Lengh++;
             NextValue(&value);
        }
        else {
            _Lengh++;
            FirstValue(&value);
        }
    }
private:
    int _Lengh = 0;
    T *StartPoint;

    void FirstValue(T * value) {
        StartPoint =(T*) malloc(sizeof(T) * _Lengh);
        *StartPoint = *value;
    }
    void NextValue(T * value) {
        T* NewStartPoint = (T*)malloc(sizeof(T) * _Lengh);
        if (NewStartPoint != NULL) {
            Transfer(NewStartPoint, value);
            StartPoint = NewStartPoint;
            NewStartPoint = NULL;
         }  
        else {
            _Lengh--;
        }
    }
    void  Transfer(T *NewStartPoint, T *value) {
       int i = 0;
       do
        {
            NewStartPoint[i] = StartPoint[i];
            i++;
        } while (i <= _Lengh - 2);
        NewStartPoint[_Lengh - 1] = *value;
        free(StartPoint);
    }

};

int main()
{
    List<int> array;
    array.Add(1);
    array.Add(2);
    array.Add(3);
    array.Add(4);
    array.Read();
}
