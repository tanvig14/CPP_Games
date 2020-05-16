#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int goal[3][3] = {{1,2,3},{8,0,4},{7,6,5}};                          //GOAL STATE OF THE BOARD

void display(int board[12][3],int x,int y)
{
    for(int i = 0; i<x; i++)
    {
        for(int j = 0; j<y; j++)
        {
            cout<<board[i][j]<<"\t";
        }
        cout<<endl;
        if(i==2 || i==5 || i==8)
            cout<<endl;
    }
}

int merit(int moves[12][3])                                         //FUNCTION TO CALCULATE MERIT OF EACH POSSIBLE MOVE
{
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, min = 10, index;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(moves[i][j] != goal[i][j])
                c1++;
            if(moves[i+3][j] != goal[i][j])
                c2++;
            if(moves[i+6][j] != goal[i][j])
                c3++;
            if(moves[i+9][j] != goal[i][j])
                c4++;
        }
    }
    if((c1 == c2) && (c2 == c3) && (c3 == c4))
    {
        c1 = rand() % 10;
        c2 = rand() % 10;
        c3 = rand() % 10;
        c4 = rand() % 10;
    }    
    if(min>c1)
    {
        min = c1;
        index = 0;
    }
    if(min>c2)
    {
        min = c2;
        index = 3;
    }
    if(min>c3)
    {
        min = c3;
        index = 6;
    }
    if(min>c4)
    {
        min = c4;
        index = 9;
    }
    return index;
}

int * childs(int x,int y,int current[3][3],int allmoves[12][3])     //CALCULATING ALL POSSIBLE MOVES BASED ON POSITION
{
    int count = 0, N;
    static int curr[3][3]; 
    for(int a = 0; a<3; a++)
    {
        for(int b = 0; b<3; b++)
        {
            curr[a][b] = current[a][b]; 
        }
    }
    
    if(x == 0 && y == 0)                                            
    {
        int q = 0;
        for(int a = 0; a<6; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = curr[a-q][b]; 
            }
            if(a == 2 || a == 5)
                q = q + 3;
        }
        allmoves[0][0] = curr[0][1];
        allmoves[0][1] = 0;
        allmoves[3][0] = curr[1][0];
        allmoves[4][0] = 0;
        for(int a = 6; a<12; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = 0; 
            }
        }       
        //cout<<"All possible moves:"<<endl;
        //display(allmoves,6,3);
    }
    else if(x == 0 && y == 1)
    {
        int q = 0;
        for(int a = 0; a<9; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = curr[a-q][b]; 
            }
            if(a == 2 || a == 5)
                q = q + 3;
        }
        allmoves[0][1] = curr[0][0];
        allmoves[0][0] = 0;
        allmoves[3][1] = curr[0][2];
        allmoves[3][2] = 0;
        allmoves[6][1] = curr[1][1];
        allmoves[7][1] = 0;        
        for(int a = 9; a<12; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = 0; 
            }
        }
        //cout<<"All possible moves:"<<endl;
        //display(allmoves,9,3);
    }
    else if(x == 0 && y == 2)
    {
        int q = 0;
        for(int a = 0; a<6; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = curr[a-q][b]; 
            }
            if(a == 2 || a == 5)
                q = q + 3;
        }
        allmoves[0][2] = curr[0][1];
        allmoves[0][1] = 0;
        allmoves[3][2] = curr[1][2];
        allmoves[4][2] = 0;        
        for(int a = 6; a<12; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = 0; 
            }
        }   
        //cout<<"All possible moves:"<<endl;
        //display(allmoves,6,3);
    }
    else if(x == 1 && y == 0)
    {
        int q = 0;
        for(int a = 0; a<9; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = curr[a-q][b]; 
            }
            if(a == 2 || a == 5)
                q = q + 3;
        }
        allmoves[1][0] = curr[0][0];
        allmoves[0][0] = 0;
        allmoves[4][0] = curr[1][1];
        allmoves[4][1] = 0;
        allmoves[7][0] = curr[2][0];
        allmoves[8][0] = 0;        
        for(int a = 9; a<12; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = 0; 
            }
        }
        //cout<<"All possible moves:"<<endl;
        //display(allmoves,9,3);
    }
    else if(x == 1 && y == 1)
    {
        int q = 0;
        for(int a = 0; a<12; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = curr[a-q][b]; 
            }
            if(a == 2 || a == 5 || a == 8)
                q = q + 3;
        }
        allmoves[1][1] = curr[0][1];
        allmoves[0][1] = 0;
        allmoves[4][1] = curr[1][0];
        allmoves[4][0] = 0;
        allmoves[7][1] = curr[1][2];
        allmoves[7][2] = 0;
        allmoves[10][1] = curr[2][1];
        allmoves[11][1] = 0;        
        //cout<<"All possible moves:"<<endl;
        //display(allmoves,12,3);
    }
    else if(x == 1 && y == 2)
    {
        int q = 0;
        for(int a = 0; a<9; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = curr[a-q][b]; 
            }
            if(a == 2 || a == 5)
                q = q + 3;
        }
        allmoves[1][2] = curr[0][2];
        allmoves[0][2] = 0;
        allmoves[4][2] = curr[1][1];
        allmoves[4][1] = 0;
        allmoves[7][2] = curr[2][2];
        allmoves[8][2] = 0;        
        for(int a = 9; a<12; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = 0; 
            }
        }
        //cout<<"All possible moves:"<<endl;
        //display(allmoves,9,3);
    }
    else if(x == 2 && y == 0)
    {
        int q = 0;
        for(int a = 0; a<6; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = curr[a-q][b]; 
            }
            if(a == 2 || a == 5)
                q = q + 3;
        }
        allmoves[2][0] = curr[1][0];
        allmoves[1][0] = 0;
        allmoves[5][0] = curr[2][1];
        allmoves[5][1] = 0;
        for(int a = 6; a<12; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = 0; 
            }
        }       
        //cout<<"All possible moves:"<<endl;
        //display(allmoves,6,3);
    }
    else if(x == 2 && y == 1)
    {
        int q = 0;
        for(int a = 0; a<9; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = curr[a-q][b]; 
            }
            if(a == 2 || a == 5)
                q = q + 3;
        }
        allmoves[2][1] = curr[1][1];
        allmoves[1][1] = 0;
        allmoves[5][1] = curr[2][0];
        allmoves[5][0] = 0;
        allmoves[8][1] = curr[2][2];
        allmoves[8][2] = 0;        
        for(int a = 9; a<12; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = 0; 
            }
        }
        //cout<<"All possible moves:"<<endl;
        //display(allmoves,9,3);
    }    
    else if(x == 2 && y == 2)
    {
        int q = 0;
        for(int a = 0; a<6; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = curr[a-q][b]; 
            }
            if(a == 2 || a == 5)
                q = q + 3;
        }
        allmoves[2][2] = curr[1][2];
        allmoves[1][2] = 0;
        allmoves[5][2] = curr[2][1];
        allmoves[5][1] = 0;        
        for(int a = 6; a<12; a++)
        {
            for(int b = 0; b<3; b++)
            {
                allmoves[a][b] = 0; 
            }
        }   
        //cout<<"All possible moves:"<<endl;
        //display(allmoves,6,3);
    }
    
    N = merit(allmoves);
    //cout<<"Choose: "<<N<<endl;
    for(int a=0; a<3; a++)
    {
        for(int b=0; b<3; b++)
        {
            curr[a][b] = allmoves[a+N][b];
        }
    }
    //cout<<"All possible moves:"<<endl;
    //display(allmoves,12,3);
    return *curr;    
}

int main()
{
    int current[3][3];
    int moves[12][3];
    int xindex, yindex, *p;
    cout<<"Enter initial position"<<endl;                           //ENTER NUMBERS 0-9 AS YOUR DESIRED BOARD POSITION (Eg - 2 8 3 1 6 4 7 0 5)
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            cin>>current[i][j];
        }
    }
    cout<<endl;
    
    display(current,3,3);
    int l = 0;
    while(l<1000)                                                    //LIMIT SET TO 1000 MOVES TO AVOID CRASHING DUE TO INFINITE LOOPS WHICH COULD BE CAUSED SINCE THE ALGORITHM DOES NOT LOOK FURTHER THAN THE NEXT MOVE WHILE CALCULATING THE BEST MOVE
    {
        int count = 0;
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<3; j++)
            {
                if(current[i][j] != goal[i][j])
                    count++;
            }
        }
        if(count == 0)
        {
            cout<<"Goal State Reached!"<<endl;
            break;
        }
        
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<3; j++)
            {
                if(current[i][j] == 0)
                {
                    xindex = i;
                    yindex = j;
                    break;
                }
            }
        }
        p = childs(xindex, yindex, current,moves);
        int v = 0;
        for(int i = 0; i<3; i++)
        {
            for(int j = 0; j<3; j++)
            {
                current[i][j] = *(p+j+v);
            }
            v = v + 3;
        }
        display(current,3,3);
        l++;
    }   
}
