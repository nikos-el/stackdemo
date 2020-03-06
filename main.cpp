#include <iostream>

using namespace std;

template <typename T>
class stack{
  public:
    stack (int size): top(-1), arr(new T [size]) {}
    stack (const stack &s): top(s.top), arr(new T [sizeof(s.arr)/sizeof(T)]){
      for (int i=0; i<=top; i++) arr[i]=s.arr[i];
    }
    ~stack (){
      top=-1;
      delete [] arr;
    }
    const stack & operator = (const stack &s){
      for (int i=0; i<=s.top; i++) arr[i]=s.arr[i];
      top=s.top;
      return s;
    }

    bool empty(){
      return top==-1;
    }
    void push (const T &x){
      arr[++top]=x;
    }
    T pop(){
      T x=arr[top];
      top--;
      return x;
    }
    int size(){
      return top+1;
    }

    friend ostream & operator << (ostream &out, const stack &s){
      out<<"[";
      for (int i=0; i<s.top; i++) out<<s.arr[i]<<", ";
      if (s.top>=0) out<<s.arr[s.top];
      out<<"]";
      return out;
    }

  private:
    int top;
    T *arr;
};

#ifndef CONTEST
int main(){
  stack<int> s(10);
  cout<<"s is empty: "<<s<<endl;
  s.push(42);
  cout<<"s has one element: "<<s<<endl;
  s.push(17);
  s.push(34);
  cout<<"s has more elements: "<<s<<endl;
  cout<<"How many? "<<s.size()<<endl;
  stack<int> t(5);
  t.push(7);
  cout<<"t: "<<t<<endl;
  t=s;
  cout<<"popping from s: "<<s.pop()<<endl;
  s.push(8);
  stack<int> a(s);
  t.push(99);
  a.push(77);
  cout<<"s: "<<s<<endl;
  cout<<"t: "<<t<<endl;
  cout<<"a: "<<a<<endl;
  stack<double> c(4);
  c.push(3.14);
  c.push(1.414);
  cout<<"c contains doubles "<<c<<endl;
  stack<char> k(4);
  k.push('$');
  cout<<"k contains a character "<<k<<endl;
}
#endif
