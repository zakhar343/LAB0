#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template<typename T>
class List : public Sequence<T>
{
private:
    struct node<T> *ptr;
    int num;
public:

List(){ptr=NULL;num=0;};

~List(){delete ptr;}

int GetLength(){return num;};

T GetFirst(){return ptr->cell;};

T GetLast(){
	struct node<T> *temp=ptr;
	int i;
	for(i=1;i<num;i++)
		temp=temp->next;
	return temp->cell;
}

T Get(int pos){
	struct node<T> *temp=ptr;
	int i;
	if((pos>=0) and (pos<num)){
	for(i=0;i<pos;i++)
		temp=temp->next;
	return temp->cell;}
	else{ cout << "ERROR\n";return 0;
        }
}

int getIsEmpty(){return num;}

void Prepend(T elem){
	struct node<T> *temp=ptr;
	ptr=new node <T>;
    ptr->cell=elem;
    ptr->next=NULL;
    if(num!=0)
		ptr->next=temp;
    ++num;}

void print(){
    struct node<T> *temp=ptr;
    while (temp!=NULL){
        cout << (temp->cell) << "\n";
        temp=temp->next;
    };
        }

void Append(T elem){
    struct node<T> *temp=ptr;
    struct node<T> *temp1;
    if(num==0)
		Prepend(elem);
	else{
        while (temp->next!=NULL)
            temp=temp->next;
        temp1=new node <T>;
        temp->next=temp1;
        temp1->cell=elem;
        temp1->next=NULL;
        num++;
        }
};

Sequence<T> *GetSubsequence(int i, int j){
    if((i>j) or (j<0) or (j>num-1)){
		cout << "INDEX ERROR\n";
		return 0;}
    int k=0;
    List <T> *b;
    b=new List<T>;
    struct node<T> *temp=ptr;
    while(k!=i){++k;temp=temp->next;}
        for(i=0;i<j-k+1;++i){
                b->Append(temp->cell);
                temp=temp->next;}
        b->print();
        return b;
};

void InsertAt(int pos,T elem){
    if(pos>num-1){
		cout << "INDEX ERROR\n";
		return ;
	}
    int i;
    struct node<T> *temp=ptr;
    struct node<T> *temp1;
    struct node<T> *temp2;
    if (pos!=0){
            for(i=1;i<pos-1;++i)
				temp=temp->next;
		temp1=temp->next;
		temp2=new node <T>;
		temp->next=temp2;
		temp2->cell=elem;
		temp2->next=temp1;
		++num;
		}
    if (pos==0)
		Prepend(elem);
    if (pos==num-1)
		Append(elem);
};

void Remove(T elem){
    int i;
	struct node<T> *temp=ptr;
	struct node<T> *temp1;
	for(i=1;i<num;++i){
        if((i==1) and (temp->cell==elem))
			ptr=temp->next;
        if(temp->next->cell==elem){
            temp1=temp->next;
            temp->next=temp->next->next;
            delete temp1;
        }
        temp=temp->next;
    };
    --num;
}
};
#endif