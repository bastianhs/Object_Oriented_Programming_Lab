#ifndef PRIO_QUEUE_HPP
#define PRIO_QUEUE_HPP

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class PriorityQueue
{
private:
    int size;
    std::vector<T> content;

public:
    /*
        Default constructor, size = 0
    */
    PriorityQueue()
    {
        size = 0;
    }

    /*
        Destructor
    */
    ~PriorityQueue() {}

    /*
        Menambahkan nilai T ke dalam content
    */
    void Enqueue(T value)
    {
        bool go = true;
        int i = GetSize() - 1;
        while (i > -1 && go)
        {
            if (content[i] >= value)
            {
                go = false;
            }
            else
            {
                if (i == GetSize() - 1)
                {
                    content.push_back(content[i]);
                }
                else
                {
                    content[i + 1] = content[i];
                }

                --i;
            }
        }

        if (i == GetSize() - 1)
        {
            content.push_back(value);
        }
        else
        {
            content[i + 1] = value;
        }

        ++size;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue dan menghapus nilai tersebut
        Dijamin PrioriryQueue tidak kosong
    */
    T Dequeue()
    {
        T front = content.front();
        content.erase(content.begin());
        --size;
        return front;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue
        Dijamin PriorityQueue tidak kosong
    */
    T Front()
    {
        return content.front();
    }

    /*
        Menambahkan elemen pada priority queue pq ke dalam content
    */
    void MergeQueue(PriorityQueue<T> pq)
    {
        for (typename vector<T>::iterator it = pq.content.begin(); it != pq.content.end(); ++it)
        {
            Enqueue(*it);
        }
    }

    /*
        Mengembalikan banyak data dari priority queue ini
    */
    int GetSize()
    {
        return size;
    }

    /*
        Operator overloading untuk mencetak isi priority queue
        Contoh: (3, 2, 1)
        Apabila kosong, tampilkan ()
    */
    friend ostream &operator<<(ostream &out, PriorityQueue<T> pq)
    {
        out << '(';

        for (typename vector<T>::iterator it = pq.content.begin(); it != pq.content.end(); ++it)
        {
            cout << *it;
            if (it != pq.content.end() - 1)
            {
                cout << ", ";
            }
        }

        out << ")\n";

        return out;
    }
};

#endif
