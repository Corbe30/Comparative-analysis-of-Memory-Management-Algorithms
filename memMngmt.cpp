#include<bits/stdc++.h>

using namespace std;

int processNumber;
int processSize;
int memory[100];
bool frearr[100];
int divs=8;

void printTable(int pos)
{
    cout<<"+----------------------------------------------------------+\n";
    cout<<"|\tNo.\tMemory \t\t Status \t Process   |\n";
    cout<<"+----------------------------------------------------------+\n";
    int j = 1, ok = 0;
        for (int i = 0; i < divs; i++) {
            if(i == pos) {
                cout<<"|\t"<<(i + 1)<<" \t "<<processSize<<"  \t\t "<<" NF \t\t "<<"Process "<<(processNumber + 1) <<" |";
                if(memory[i] - processSize != 0) {
                    cout<<"\n|\t" << (i + 2) << " \t " << (memory[i] - processSize) << "  \t\t " << " F \t\t\t   |";
                    ok = 1;
                }
            }
            else {
                if(frearr[i])
                cout<<"|\t" << (i + 1 + ok) << " \t " <<  memory[i] << "  \t\t  " << "F \t\t\t   |" ;
                else
                {
                    cout<<"|\t" << (i + 1 + ok) << " \t " <<  memory[i] << "  \t\t  " << "NF \t\t " << "Process " << j++ << " |" ;
                }
            }
            cout<<endl;
        }
        cout<<"+----------------------------------------------------------+\n";
}

void firstFit() {
    int ans = -1;
    for(int i = 0; i < divs; i++) {
        if(frearr[i] && processSize <= memory[i]) {
            ans = i;
            break;
        }
    }
    printTable(ans);
}

void bestFit() {
    int ans = -1, curr = 1000000;
    for(int i = 0; i < divs; i++) {
        if(frearr[i] && processSize <= memory[i]) {
            if(memory[i] - processSize < curr) {
                curr = memory[i] - processSize;
                ans = i;
            }
        }
    }
    printTable(ans);
}

void worstFit() {
    int ans = -1, curr = 0;
    for(int i = 0; i < divs; i++) {
        if(frearr[i] && processSize <= memory[i]) {
            if(memory[i] - processSize > curr) {
                curr = memory[i] - processSize;
                ans = i;
            }
        }
    }
    printTable(ans);
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
            int fitType ;
            cin>>fitType;

            // auto start = high_resolution_clock::now();
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
            // auto stop = high_resolution_clock::now();

            // auto duration = duration_cast<microseconds>(stop - start);
            // cout << "\n Duration of execution: " << duration.count() << '\n';
        }
}

void processInput()
{
    cout<<"\n\tCurrent Scenario of the Memory Allocation \n";
    printTable(-1);
    cout<<"\nEnter the no. of the processes you need to add: ";
    cout<<"\nEnter the size of the process that needs to be added (in KB): ";
    cin>>processSize;
    choice();
}

void memoryinput(){
    divs=0;
    processNumber=0;
    cout<<"\nEnter the number of Memory Blocks: ";
    
    cin>>divs;
    for(int i=0;i<divs;i++){
        cout<<"\nEnter the Memory Block on Position "<<(i + 1)<<": ";
        cin>>memory[i];
        cout<<"Not free [0] / free [1]: ";
        int x;
        cin>>x;
        frearr[i]=(x==1)?true:false;
        if(!frearr[i])
        {
            processNumber++;
        }
    }
    processInput();
}

int main()
{
    //pre defined arrays in case user does not enter 
    int d_memory[10] = {100, 300, 40, 50, 150, 240, 200, 400};
    int d_frearr[10] = { false, true, false, true, false, true, false, true };
    for(int i=0;i<10;i++)
    {
        memory[i]=d_memory[i];
        frearr[i]=d_frearr[i];
    }
    processNumber = 4;
    int divs = 8;
    //Welcome Message
    int inputornot;
    cout<<"\tWelcome to The Memory Allocation Simulator"<<endl;
    cout<<"\nDo you want to input memory data? \nEnter [0] No or [1] Yes: "<<endl;
    cin>>inputornot;
    if(inputornot==1)
    {
        memoryinput();
    }
    else
    {
        cout<<memory[0]<<memory[1]<<memory[2]<<endl;

        processInput();
    }
    return 0;
}