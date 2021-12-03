#include<bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long int processNumber;
long long int processSize;
long long int memory[100000000];
bool frearr[100000000];
long int divs=8;

void firstFit() {
    long long int ans = -1;
    for(long long int i = 0; i < divs; i++) {
        if(frearr[i] && processSize <= memory[i]) {
            ans = i;
            break;
        }
    }
    cout << "process set at " << ans << "\n";
    // printTable(ans);
}

void bestFit() {
    long long int ans = -1, curr = 1000000;
    for(long long int i = 0; i < divs; i++) {
        if(frearr[i] && processSize <= memory[i]) {
            if(memory[i] - processSize < curr) {
                curr = memory[i] - processSize;
                ans = i;
            }
        }
    }
    cout << "process set at " << ans << "\n";
    // printTable(ans);
}

void worstFit() {
    long long int ans = -1, curr = 0;
    for(long long int i = 0; i < divs; i++) {
        if(frearr[i] && processSize <= memory[i]) {
            if(memory[i] - processSize > curr) {
                curr = memory[i] - processSize;
                ans = i;
            }
        }
    }
    cout << "process set at " << ans << "\n";
    // printTable(ans);
}

void choice(){
    bool running = true;
        while(running) {
            cout<<"\nEnter the Algorithm for Memory Allocation: \n";
            cout<<"[1] First Fit\n";
            cout<<"[2] Best Fit\n";
            cout<<"[3] Worst Fit\n";
            cout<<"[4] Exit\n";
            
            cout<<"Enter a number (1-4): ";
            int fitType;
            cin>>fitType;

            auto start = high_resolution_clock::now();
            switch(fitType) {
                case 1:
                    cout<<"\n\t\tAfter First Fit \n";
                    firstFit();
                    break;
                case 2:
                    cout<<"\n\t\tAfter Best Fit  \n";
                    bestFit();
                    break;
                case 3:
                    cout<<"\n\t\tAfter Worst Fit \n";
                    worstFit();
                    break;
                case 4: 
                    running = false;
                    break;
                default:
                    cout<<"\nPlease enter a number between 1 and 4.\n";
            }
            auto stop = high_resolution_clock::now();

            
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "\n Duration of execution: " << duration.count() << "ms \n";
        }
}

void processInput()
{
    processSize = 9;
    choice();
}

void memoryinput(){
    divs=0;
    processNumber=0;
    cout<<"\nEnter the number of Memory Blocks: ";
    
    cin>>divs;

    memory[0] = 10;
    frearr[0] = true;
    frearr[divs-1] = true;
    memory[divs-1] = 9;

    for(long long int i=1;i<divs-1;i++){
        memory[i] = 1;

        frearr[i] = false;
        if(!frearr[i])
        {
            processNumber++;
        }
    }
    processInput();
}

int main()
{
    processNumber = 4;
    int divs = 8;

    memoryinput();    
    
    return 0;
}