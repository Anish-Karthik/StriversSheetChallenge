#include <bits/stdc++.h> 

class Queue {

public:

int *arr;

int size;

int frnt;

int rear;

    Queue() {

        arr=new int[10000];

        frnt=0;

        rear=0;

    }

 

    /*----------------- Public Functions of Queue -----------------*/

 

    bool isEmpty() {

        if(frnt == rear)

        {

            return true;

        }

        return false;

    }

 

    void enqueue(int data) {

        if(rear==size-1)

        {

            return;

        }

        else

        {

            arr[rear]=data;

            rear++;

        }

    }

 

    int dequeue() {

        int ans;

        if(isEmpty())

        {

            return -1;

        }

        else{

            ans=arr[frnt];

            frnt++;

            if(frnt == rear)

            {

                frnt=0;

                rear=0;

            }

        }

        return ans;

    }

 

    int front() {

        int ans;

        if(isEmpty())

        {

            return -1;

        }

        else{

             ans=arr[frnt];

        }

        return ans;

    }

};
