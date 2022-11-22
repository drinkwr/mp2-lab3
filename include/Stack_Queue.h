//lab3
#include <iostream>
using namespace std;
const double COEFFICIENT = 1.5;
const int MAX_SIZE = 2000;
template <class T>
class Vector
{
protected:
    T* data;
    size_t capacity; //выделенная память
    size_t size; //занятая память
    
public:
    Vector()
    {
        data = nullptr;
        capacity=0;
        size=0;
    }
    
    ~Vector()
    {
        if(data != nullptr)
        {
            delete[] data;
        }
        data=nullptr;
        size=0;
        capacity=0;
    }
    
    size_t GetSize()
    {
        return size;
    }
    
    size_t GetCapacity()
    {
        return capacity;
    }
    
    Vector (int n)
    {
        if ((n<0)||(n>MAX_SIZE)) throw "Incorrect size";
        else {
            capacity=size_t(COEFFICIENT*n)+1;
            data = new T[capacity];
            size=n;
            for (size_t i=0;i<capacity; i++)
                data[i]=0;
        }
    }
    
    Vector (const Vector& v)
    {
        capacity=v.capacity;
        size=v.size;
        data = new T[capacity];
        for (size_t i=0; i<size; i++)
            data[i]=v.data[i];
        for (size_t i=size; i<capacity; i++)
            data[i]=0;
    }
    
    Vector& operator=(Vector& v)
    {
        if(&v == this)
            return *this;
        capacity=v.capacity;
        size=v.size;
        if(data != nullptr)
            delete [] data;
        data = new T[capacity];
        for (size_t i=0; i<size; i++)
            data[i]=v.data[i];
        for (size_t i=size; i<capacity; i++)
            data[i]=0;
        return *this;
    }
    
    void push_back (T elem)
    {
        if (size==MAX_SIZE)
            throw "Can not push back";
        if ((size+1)>capacity)
        {
            capacity=size_t(COEFFICIENT*capacity)+1;
            resize(capacity);
        }
        size++;
        data[size-1]=elem;
    }
    
    void pop_back()
    {
        if (size==0)
            throw "Can not to pop";
        else
        {
            data[size-1]=0;
            size--;
        }
    }
    
    void push_front (T elem)
    {
        this->insert(elem,0);
    }
    
    void pop_front ()
    {
        for (size_t i=0; i<size; i++)
            data[i]=data[i+1];
        data[size-1]=0;
        size--;
    }
    
    void resize (size_t s)
    {
        T* temp=new T[s];
        for (size_t i=0; i<size; i++)
            temp[i]=data[i];
        delete[] data;
        data=temp;
        capacity=s;
    }
    
    T& operator[] (size_t index)
    {
        if ((index<0)||(index>=size))
            throw "Incorrect index";
        else
            return data[index];
    }
    
    T operator[] (size_t index) const
    {
        if ((index<0)||(index>=size))
            throw "Incorrect index";
        else
            return data[index];
    }
    
    void insert (T elem, int index)
    {
        if ((size+1)>capacity)
        {
            capacity=size_t(COEFFICIENT*capacity)+1;
            resize(capacity);
            for (size_t i=size; i>=index; i--)
                data[i]=data[i-1];
            data[index-1]=elem;
            size++;
        }
        
        else
        {
            for (size_t i=size; i>=index; i--)
                data[i]=data[i-1];
            data[index-1]=elem;
            size++;
        }
    }
    
    void erase (int index)
    {
        for (size_t i=index-1; i<size-1; i++)
            data[i]=data[i+1];
        data[size-1]=0;
        size--;
    }
    
    bool operator==(const Vector &v) const
    {
        bool flag=true;
        if (size!=v.size)
            flag=false;
        else
            for (int i=0; i<size; i++)
                if (data[i]!=v.data[i])
                {
                    flag=false;
                    break;
                }
        return flag;
    }
    
    bool operator!=(const Vector &v) const
    {
        return !(*this==v);
    }
};



template <class T>
class Stack: public Vector <T> {
private:
    void push_front();
    void pop_front();
    void insert(T elem, int index);
    void erase (int index);
    
public:
    Stack(): Vector<T> () {}
    Stack(int n): Vector<T> (n) {}
    Stack(const Stack& s): Vector<T> (s) {}
    ~Stack() {}
    
    T top()
    {
        if (Vector<T>::size == 0) throw "Can not take the top of stack";
        else return Vector<T>::data[Vector<T>::size -1 ];
    }
    
    void push(T elem)
    {
        Vector<T>::push_back(elem);
    }
    
    void pop()
    {
        Vector<T>::pop_back();
    }
    
    bool empty()
    {
        if (Vector<T>::size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool full()
    {
        if(Vector<T>::size == Vector<T>::capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};



template <class T>
class Queue: public Vector <T> {
private:
    T *start;
    T *end;
    void insert(T elem, int index);
    void erase(int index);
    void pop_back();
    void pop_front();
    void push_back(T elem);
    void push_front(T elem);
    
public:
    Queue(): Vector<T>()
    {
        start=nullptr;
        end=nullptr;
    }
    Queue(int n): Vector<T>(n)
    {
        start=Vector<T>::data;
        end=Vector<T>::data+Vector<T>::size-1;
    }
    Queue(const Queue& q): Vector<T>(q)
    {
        start=q.start;
        end=q.end;
        
    }
    ~Queue() {};
    
    T front()
    {
        if (Vector<T>::size==0)
            throw "Can not take the first element of queue";
        else
            return *start;
    }
    
    T back()
    {
        if (Vector<T>::size==0)
            throw "Can not take the last element of queue";
        else
            return *end;
    }
    
    void push(T elem)
    {
        if (this->full()==true)
            resize(size_t(COEFFICIENT*Vector<T>::capacity)+1);
        if (end==Vector<T>::data+Vector<T>::capacity-1)
            end=Vector<T>::data;
        else
            end++;
        *end=elem;
        Vector<T>::size++;
    }
    
    void pop()
    {
        if (this->empty()==true)
            throw "Can not pop";
        if (start==Vector<T>::data+Vector<T>::capacity-1)
            start=Vector<T>::data;
        else
            start++;
        Vector<T>::size--;
    }
    
    void resize (size_t s)
    {
        T* temp = new T[s];
        int k=0;
        for (size_t i = (start-Vector<T>::data) / sizeof(T); i < Vector<T>::capacity; i++)
        {
            temp[k]=Vector<T>::data[i];
            k++;
        }
        for (size_t i = 0; i < (start-Vector<T>::data) / sizeof(T); i++)
        {
            temp[k]=Vector<T>::data[i];
            k++;
        }
        delete[] Vector<T>::data;
        Vector<T>::data = temp;
        Vector<T>::capacity = s;
        start = Vector<T>::data;
        end = Vector<T>::data+Vector<T>::size-1;
    }
    
    bool empty()
    {
        if (Vector<T>::size==0)
            return true;
        else
            return false;
    }
    
    bool full()
    {
        if (((start==Vector<T>::data) && (Vector<T>::size==Vector<T>::capacity)) || (start==end+1))
            return true;
        else
            return false;
    }
    
    bool operator == (const Queue& q) const
    {
        bool flag=true;
        if ((Vector<T>::size!=q.size) || (start!=q.start) || (end!=q.end))
            flag=false;
        else
            for (size_t i=0; i<Vector<T>::size; i++)
                if (Vector<T>::data[i]!=q.data[i])
                {
                    flag=false;
                    break;
                }
        return flag;
    }
    
    bool operator!=(const Queue &q) const
    {
        return !(*this==q);
    }
};


/*int main()
 {
 Stack<int> S;
 S.push(10);
 S.push(6);
 S.push(9);
 S.push(17);
 while(!S.empty())
 {
 cout << S.top() <<"\n";
 S.pop();
 }
 Queue<int> Q;
 Q.push(10);
 Q.push(6);
 Q.push(9);
 Q.push(17);
 while(!Q.empty())
 {
 cout << Q.front() <<"\n";
 Q.pop();
 }
 }
 */

