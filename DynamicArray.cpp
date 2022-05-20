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
	int Remove(unsigned int index){
		try{
			_Length--;
            T** NewStartPoint = StartPoint;
            StartPoint = new T * [_Length];
            for (int i = 0,j=0; i < _Length+1; i++)
            {
            	if(index!=i){
            		StartPoint[j] = NewStartPoint[i];
            		j++;
				}
				
            }
            delete(NewStartPoint);
            return 1;
		}
		catch (int myNum) {
			return 0;
		}
	}
    int GetIndex(unsigned int i) {
        return (i >= _Length) ? 0 : *StartPoint[i];
    }
    void Read() {
        for (int i = 0; i < _Length; i++) {
             cout<< *StartPoint[i] << endl;
        }
    }
    int Length() {
        return _Length;
    }
    void Add(T value)
    {
        MemoryPointCreate(&value);
    }
    int * GetAll() {
        int GetAllList[_Length];
        for (int i = 0; i < _Length;i++) {
            GetAllList[i] = *StartPoint[i];
        }
        return GetAllList;
    }
private:
    int _Length = 0;
    T** StartPoint;

    void MemoryPointCreate(T* value) {
        T* NPoint = new T[1]; // (typeid(value))malloc(typeid(*value).name() + 1);
        *NPoint = *value;
        MemoryExpansion(NPoint);
    }
    void MemoryExpansion(T* NValue) {
        if (_Length > 0) {
            _Length++;
            T** NewStartPoint = StartPoint;
            StartPoint = new T * [_Length];
            for (int i = 0; i < _Length-1; i++)
            {
                StartPoint[i] = NewStartPoint[i];
            }
            StartPoint[_Length - 1] = NValue;
            delete(NewStartPoint);
        }
        else {
            _Length++;
            StartPoint = new T * [_Length];
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
      array.Add(40);
        array.Add(50);
          array.Add(60);
            array.Add(70);
              array.Add(80);
              
    array.Remove(1);
    for (int i = 0; i < array.Length(); i++)
    {
        cout << array.GetIndex(i)<<endl;

    }
}
