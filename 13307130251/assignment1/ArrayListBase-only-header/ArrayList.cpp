
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList : public List<T> {

    public:
        ArrayList();
        ArrayList(const T &m);
        ~ArrayList();
        int size() const;
        bool isEmpty() const;
        T get(int index)const;
        void add(T element);
        T remove(int index);
        int getcapacity(){return Capacity;}
    private:
        static const int defaultsize=10;
        int Arraysize;
        int Capacity;
        T *element;
        void resize();
};
template<typename T>
ArrayList<T>::ArrayList(){
    Arraysize=0;
    Capacity=defaultsize;
    element=new T[defaultsize];
}
template<typename T>
ArrayList<T>::ArrayList(const T &m){
    Arraysize=1;
    Capacity=defaultsize;
    element=new T[defaultsize];
    element[0]=m;
}
template<typename T>
ArrayList<T>::~ArrayList(){}
template<typename T>
int ArrayList<T>::size()const
{
    return Arraysize;
}
template<typename T>
bool ArrayList<T>::isEmpty()const
{
    return Arraysize==0;
}
template<typename T>
T ArrayList<T>::get(int index)const
{
    return element[index];
}
template<typename T>
void ArrayList<T>::resize()
{
    if(Arraysize*1.0/Capacity<0.2&&Arraysize>5)
    {
        T *New=new T[2*Arraysize];
        Capacity=2*Arraysize;
        T *ne=New;
        T *oe=element;
        int num=Arraysize;
        while(num--){
            *(ne++)=*(oe++);
        }
        delete []element;
        element=New;
    }
    else if (Arraysize==Capacity){
        T *New=new T[2*Arraysize];
        Capacity=2*Arraysize;
        T *ne=New;
        T *oe=element;
        int num=Arraysize;
        while(num--){
            *(ne++)=*(oe++);
        }
        delete []element;
        element=New;
    }
}
template <typename T>
void ArrayList<T>::add(T element)
{
    this->element[Arraysize++]=element;
    if(Arraysize==Capacity){
        resize();
    }
}
template<typename T>
T ArrayList<T>::remove(int index){
    T r=element[index];
    for(int i=index;i<Arraysize-1;i++)
        element[i]=element[i+1];
    Arraysize--;
    resize();
    return r;
}
/*
int main()
{
    cout << "delete_after_insert_entrys start" << endl;

    ArrayList<int> list;
    for (int i = 0; i< 1000; ++i) {
        list.add(i);
    }
    
    assert(list.size() == 1000);
    for (int i = 0; i< 1000; ++i) {
        assert(list.get(i) == i);
    }

    for (int i = 0; i<100; ++i) {
        list.remove(0);
    }
    
    assert(list.size() == 900);

    for (int i = 100; i<1000; ++i) {
        assert(list.get(i-100) == i);
    }

    for (int i = 100; i<1000; ++i) {
        cout<<list.size()<<" "<<list.getcapacity()<<endl;
        list.remove(0);
    }
    
    assert(list.isEmpty());
        
    cout << "delete_after_insert_entrys end" << endl;
}*/