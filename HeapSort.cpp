#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "string"

class BinaryHeap 
{
public:
    std::vector <int> heap;
    int l(int parent);
    int r(int parent);
    int Parent(int child);
    void HeapifyUp(int index);
    void HeapifyDown(int index);
    void SortUp(int n);
    void SortDown(int n);
    std::string direction = "max";

    BinaryHeap() {}
    void Insert(int element);
    void DeleteMin();
    int ExtractMin();
    void PrintHeap();
    int GetSize();
};
int main() 
{
    BinaryHeap heap;
    std::string command;
    while (std::cin.good())
    {
        std::cin >> command;
        if (command == "+")
        {
            int number;
            std::cin >> number;
            heap.Insert(number);
        }
        else if (command == "p")
        {
            heap.PrintHeap();
        }
        else if (command == "-")
        {
            std::cout << heap.ExtractMin() << " ";
            heap.DeleteMin();
        }
        else if (command == "s")
        {
            heap.direction = "min";
        }
    }
}
int BinaryHeap::GetSize() 
{
    return heap.size();
}
void BinaryHeap::Insert(int newElement) 
{
    heap.push_back(newElement);
    if (direction == "max")
    {
        HeapifyDown(heap.size() - 1);
        SortUp(heap.size() - 1);
    }
    else
    {
        HeapifyDown(heap.size());
        SortDown (heap.size());
    }
}
void BinaryHeap::DeleteMin() 
{
    if (heap.size() == 0) 
    {
        return;
    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    HeapifyDown(0);
}
int BinaryHeap::ExtractMin() 
{
    if (heap.size() == 0) 
    {
        return -1;
    }
    else
        return heap.front();
}
void BinaryHeap::PrintHeap() 
{
    std::vector <int>::iterator pos = heap.begin();
    while (pos != heap.end()) 
    {
        std::cout << *pos << " ";
        pos++;
    }
    std::cout << std::endl;
}
int BinaryHeap::l(int parent)
{
    int l = 2 * parent + 1;
    if (l < heap.size())
        return l;
    else
        return -1;
}
int BinaryHeap::r(int parent)
{
    int r = 2 * parent + 2;
    if (r < heap.size())
        return r;
    else
        return -1;
}
int BinaryHeap::Parent(int child) 
{
    int p = (child - 1) / 2;
    if (child == 0)
        return -1;
    else
        return p;
}
void BinaryHeap::HeapifyUp(int number) 
{
    int largest = number;
    int l = 2 * number + 1;
    int r = 2 * number + 2;

    if (l < heap.size() && heap[l] > heap[largest])//
        largest = l;

    if (r < heap.size() && heap[r] > heap[largest])//
        largest = r;

    if (largest != number) {
        std::swap(heap[number], heap[largest]);

        HeapifyUp(largest);
    }
}
void BinaryHeap::HeapifyDown(int number)
{
    int largest = number;
    int l = 2 * number + 1;
    int r = 2 * number + 2;

    if (l < heap.size() && heap[l] < heap[largest])//
        largest = l;

    if (r < heap.size() && heap[r] < heap[largest])//
        largest = r;

    if (largest != number) {
        std::swap(heap[number], heap[largest]);

        HeapifyUp(largest);
    }
}

void BinaryHeap::SortUp(int n)  //Rosn¹ce
{
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapifyUp(i);

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(heap[i], heap[0]);

        HeapifyUp(0);
    }
}

void BinaryHeap::SortDown(int n)  //Rosn¹ce
{
    for (int i = n / 2 - 1; i >= 0; i--)
        HeapifyDown(i);

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(heap[0], heap[i]);

        HeapifyDown(0);
    }
}