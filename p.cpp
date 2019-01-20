

#include<iostream>
#include<cstdio>
using namespace std;
 
struct mouse
{
	int score, power, id;
 
	mouse() {}
	mouse(int s, int p, int i) :score(s), power(p), id(i) {}
 
	bool operator>(const mouse &obj)const
	{
		if (score != obj.score) return score > obj.score;
		else return id < obj.id;
	}
};
 
template <class Type>
class priorityQueue
{
private:
	int currentSize;
	Type *array;
	int maxSize;
 
	void doubleSpace();
	void buildHeap();
	void percolateDown(int hole);
 
public:
	priorityQueue(int capacity = 200000)
	{
		array = new Type[capacity];
		maxSize = capacity;
		currentSize = 0;
	}
	priorityQueue(const Type data[], int size);
	~priorityQueue() { delete[]array; }
 
	bool isEmpty() const { return currentSize == 0; }
	void enQueue(const Type&x);
	Type deQueue();
	Type getHead() const { return array[1]; }
};
 
template <class Type>
void priorityQueue<Type>::enQueue(const Type&x)
{
	if (currentSize == maxSize - 1) doubleSpace();
 
	// 向上过滤
	int hole = ++currentSize;
	for (; hole > 1 && x > array[hole / 2]; hole /= 2)
		array[hole] = array[hole / 2];
	array[hole] = x;
}
 
template <class Type>
Type priorityQueue<Type>::deQueue()
{
	Type maxItem;
	maxItem = array[1];
	array[1] = array[currentSize--];
	percolateDown(1);
	return maxItem;
}
 
template <class Type>
void priorityQueue<Type>::percolateDown(int hole)
{
	int child;
	Type tmp = array[hole];
 
	for (; hole * 2 <= currentSize; hole = child)
	{
		child = hole * 2;
		if (child != currentSize&&array[child + 1] > array[child])
			child++;
		if (array[child] > tmp) array[hole] = array[child];
		else break;
	}
	array[hole] = tmp;
}
 
template<class Type>
void priorityQueue<Type>::buildHeap()
{
	for (int i = currentSize / 2; i > 0; i--)
		percolateDown(i);
}
 
template<class Type>
priorityQueue<Type>::priorityQueue(const Type data[], int size)
	:maxSize(size + 10), currentSize(size)
{
	array = new Type[maxSize];
	for (int i = 0; i < size; i++) array[i + 1] = data[i];
	buildHeap();
}
 
template<class Type>
void priorityQueue<Type>::doubleSpace()
{
	Type*tmp = array;
 
	maxSize *= 2;
	array = new Type[maxSize];
 
	for (int i = 0; i <= currentSize; ++i) array[i] = tmp[i];
	delete[]tmp;
}
 
int N, R, P[200000], S[200000];
mouse mice[200000];
 
void update(int id)
{
	// 不需要调整
	if (id == 0 || mice[id - 1]>mice[id]) return;
 
	mouse tmp = mice[id];
	while (id >0 && tmp > mice[id - 1])
	{
		mice[id] = mice[id - 1];
		--id;
	}
	mice[id] = tmp;
}
 
 
void compete(int id1, int id2)
{
	if (mice[id1].power > mice[id2].power)
	{
		mice[id1].score += 2;
		update(id1);
	}
	else if (mice[id1].power < mice[id2].power)
	{
		mice[id2].score += 2;
		update(id2);
	}
	else
	{
		mice[id1].score += 1;
		update(id1);
		mice[id2].score += 1;
		update(id2);
	}
}
 
int main()
{
	priorityQueue<mouse> pq;
	mouse m1, m2, tmp;
	scanf("%d %d", &N, &R);
	int num_of_mice = 2 * N;
	for (int i = 0; i < num_of_mice; ++i)
		scanf("%d", &P[i]);
	for (int i = 0; i < num_of_mice; ++i) {
		scanf("%d", &S[i]);
		pq.enQueue(mouse(P[i], S[i], i + 1));
	}
	for (int i = 0; i < num_of_mice; ++i)
		mice[i] = pq.deQueue();
 
	while (R--)
		for (int i = 0; i < N; ++i)
			compete(i * 2, i * 2 + 1);
 
	for (int i = 0; i < num_of_mice; ++i)
		printf("%d ", mice[i].id);
 
	return 0;
}

