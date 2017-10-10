#ifndef SEQUENCE_H_INCLUDED
#define SEQUENCE_H_INCLUDED

template<typename T>
class Sequence {
public:
virtual int GetLength()=0;
virtual T GetFirst()=0;
virtual T GetLast()=0;
virtual T Get(int index)=0;
virtual void Remove(T elem)=0;
virtual void Append(T elem)=0;
virtual void Prepend(T elem)=0;
virtual void InsertAt(int pos,T elem)=0;
virtual Sequence<T> *GetSubsequence(int i, int j)=0;
virtual void print()=0;
};
#endif