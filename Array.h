#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

template<typename T> class Array : public Sequence<T>
{
private:
    T *arr;
    int num;
public:
Array(){
    arr=new T;
    num=0;
};


void Append(T elem){
        my_realloc(arr,num,num+1);
            *(arr+num)=elem;
            num++;};

void print(){
    int i;
        for(i=0;i<num;++i)
        cout << *(arr+i) << "\n";};

int GetLength(){return num;};

T GetFirst(){return *arr;};

T GetLast(){return*(arr+num-1);};

T Get(int index){return *(arr+index);};

int getIsEmpty(){return num;}

Array<T> *GetSubsequence(int i, int j){
    if((i>j) or (j<0) or (j>num-1)){
		cout << "INDEX ERROR\n";
		return 0;}
    int k;
    Array<T> *b;
    b=new Array<T>;
        for(k=i;k<j+1;++k)
			b->Append(*(arr+k));
    return b;
};

void Remove(T elem){int i,j=0;
for(i=0;i<num;++i)
    if(*(arr+i)==elem){
        for(j=i;j<num-1;++j)*(arr+j)=*(arr+j+1);
            my_realloc(arr,num,num-1);
            --num;}
};

void Prepend(T elem){
    int i;
    my_realloc(arr,num,num+1);
        for(i=num+1;i>0;--i)
        *(arr+i)=*(arr+i-1);
    *(arr)=elem;
num++;};

void InsertAt(int pos,T elem){
    if(pos>num-1){
		cout << "INDEX ERROR\n";
		return ;
	}
    int i;
    if (pos==0) Prepend(elem);
if (pos==num) Append(elem);
if ((pos!=0) and (pos!=num) and (num>pos)){
    my_realloc(arr,num,num+1);
        for(i=num;i>pos-1;--i)
        *(arr+i)=*(arr+i-1);
 *(arr+pos)=elem;
num++;}
};
};
#endif
