#include<iostream>
#include<math.h>
using namespace std;

int winning(int status[])
{
    //CHECKING IF PLAYER HAS WON
    if((status[0]==1 && status[4]==1 && status[8]==1) || (status[0]==1 && status[3]==1 && status[6]==1) || (status[3]==1 && status[4]==1 && status[5]==1) || (status[6]==1 && status[7]==1 && status[8]==1) || (status[0]==1 && status[1]==1 && status[2]==1) || (status[1]==1 && status[4]==1 && status[7]==1) || (status[2]==1 && status[5]==1 && status[8]==1) || (status[2]==1 && status[4]==1 && status[6]==1))
        return 1;
    
    //CHECKING IF COMP HAS WON    
    else if((status[0]==2 && status[4]==2 && status[8]==2) || (status[0]==2 && status[3]==2 && status[6]==2) || (status[3]==2 && status[4]==2 && status[5]==2) || (status[6]==2 && status[7]==2 && status[8]==2) || (status[0]==2 && status[1]==2 && status[2]==2) || (status[1]==2 && status[4]==2 && status[7]==2) || (status[2]==2 && status[5]==2 && status[8]==2) || (status[2]==2 && status[4]==2 && status[6]==2))
        return 1; 
    
    else
        return 0;
}

void display(int board[])
{
    int x, y, z;
    for(x=0; x<3; x++)   
    {       
        cout<<board[x]<<"\t"; 
    }    
    cout<<endl;
    for(y=3; y<6; y++)   
    {       
        cout<<board[y]<<"\t"; 
    }    
    cout<<endl;
    for(z=6; z<9; z++)   
    {       
        cout<<board[z]<<"\t"; 
    }    
    cout<<endl<<endl;
}

int main()
{
    int user, s, r, k = 8, p;
    int status[9] = {0,0,0,0,0,0,0,0,0};                          //CURRENT STATUS OF GAME AT ANY GIVEN POINT (BASCALLY THE BOARD)
    int allMoves[8][9];                                           //MATRIX WITH ALL POSSIBLE MOVES FOR COMP FOR EVERY TURN
    
    cout<<"Make your first move (Integer between 0-8)"<<endl;
    display(status);
    while(k>0)
    {
        cin>>user;
        status[user] = 1;
        s = winning(status);                                      //CHECKING IF PLAYER HAS WON
        cout<<"Board after player's move:"<<endl;
        display(status);
        
        if(s == 1)
        {
            cout<<"Player has won!"<<endl;
            break;
        }
        
        else if(s == 0)
        {        
            p = 0;
            for(int a=0; a<k; a++)                                //POPULATING POSSIBLE MOVES MATRIX
            {
                if(status[p] == 0)
                {
                    for(int b=0; b<9; b++)
                    {
                        allMoves[a][b] = status[b];               //FILL CURRENT LINE WITH PLAYER'S MOVE
                    }    
                    allMoves[a][p] = 2;                           //REPLACE 1 POSITION IN ORDER WITH POSSIBLE COMP MOVE
                }
                
                else
                {
                    a--;
                }
                p++;
            }
            
            //cout<<"\nAll Possible Moves:"<<endl;                //PRINTING ALL POSSIBLE MOVES
            for(int d=0; d<8; d++)          
            {
                for(int f=0; f<9; f++)
                {
                    //cout<<allMoves[d][f]<<"\t";
                }
                //cout<<endl;
            }
            
            int l = 0, index, sum = 0;                            //HEURISTIC FUNCTION FOR SELECTING COMP MOVE
            for(int n=k; n>=0; n--)
            {
                sum += status[n] * pow(3,l);
                l++;
            }
        
            index = sum % k;
            //cout<<"Index of selected move: "<<index<<endl;
    
            for(int m=0; m<9; m++)                                //COMP PLAYING THEIR MOVE
            {
                status[m] = allMoves[index][m];
            }
            
            cout<<"Board after comp move: "<<endl;
            display(status);
            r = winning(status);
            if(r == 1)                                            //CHECKING IF COMP HAS WON
            {
                cout<<"Computer has won!!"<<endl;
                break;
            }    
            k = k - 2;
        }
    }   
}
