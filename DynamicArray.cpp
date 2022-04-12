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
        Readme();   
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
        else{
            _Lengh++;
            FirstValue(&value);
        }
         
    }
private:

    int _Lengh = 0;
    T **StartPoint;
    int CharPointCount=0;

    void Readme() {
        for (int i = 0; i < _Lengh; i++) {
            cout<< *StartPoint[i] << endl;
        }
    }
    void FirstValue(T * value) {
        T* NPoint = new T[3];
        NPoint = value;
       // StartPoint = new  T[1]; //(typeid(value))malloc(typeid(*value).name()+1);
        StartPoint = &NPoint;
        // cout<<typeid(NPoint).name()<<endl;
    }
    void NextValue(T * value,int Type=0) {
        T* NPoint = new T[1]; // (typeid(value))malloc(typeid(*value).name() + 1);
        *NPoint = *value;
        MemoryExpansion(NPoint);
    }
    
    void MemoryExpansion(T* NValue) {
    	
        T** NewStartPoint = StartPoint;
        StartPoint = new T*[_Lengh];
        
        for (int i = 0; i < _Lengh ; i++)
        {
            StartPoint[i] = NewStartPoint[i];
        }
        StartPoint[_Lengh-1] = NValue;

        //free(NewStartPoint);
     
    }
    
};
int main()
{
    List<char*> array;
    array.Add("10");
    array.Add("20");
    array.Add("30");
    array.Read(); 
}
