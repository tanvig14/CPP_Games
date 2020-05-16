#include<simplecpp>
#include<stdlib.h>

class dot                                                                 
{
private:
    int x,y;

public:
    void CIRCLE(int a,int b,char w)                                       //Make a dot for one array element
    {
        x=a;
        y=b;
        Circle c(x,y,3);

        if(w=='b')
        {
            c.setColor(COLOR("black"));
            c.setFill(1);
            c.imprint();
        }
        else if (w=='r')
        {
            c.setColor(COLOR("red"));
            c.setFill(1);
            c.imprint();
        }
    }
    void make_circle(int a,int b)                                         //Store x and y coordinates and call dot making function with coordinates x and y
    {
        x=a*60;
        y=b*60;
        CIRCLE(x,y,'b');
    }

    void CHANGE_COLOR_CIRCLE()                                            //change dot color after click on it
    {
        CIRCLE(x,y,'r');
    }
    void make_circle1()
    {
        CIRCLE(x,y,'b');
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};
dot dots[10][10];                                                         //Info for all dots
char name1[3],name2[3];
int noTwoLine[100][100];
int countPlayer1=0,countPlayer2=0;
int globalX,globalY,countLine=0;
int whichMode;

void makedots(int i,int j);
void makeboard();
int SEARCH_DOT(int a);
int checkLineNear(int a,int b,int c,int d);                               //Check to make line for nearby dots only

void startMakingLine(int a);
void makeLine(int a,int b,int c);
void makeSquare(int a,int b,int c);
void Result();
void askPlayer();
void HumVsComp();
void compTurn();
void initialisenoTwoline()
{
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
            noTwoLine[i][j]=0;
}
main_program
{
    initialisenoTwoline();
    initCanvas("Dots and Lines",1368,768);
    askPlayer();
    int a=0;
    while(true)
    {
        startMakingLine(a);
        if(a==0)a=1;
        else a=0;
    }
}
void askPlayer()
{
    int x;
asAgain:
    cout<<"CHOOSE YOUR GAMESTYLE"<<endl<<"1>HUMAN vs COMP"<<endl<<"2>HUMAN vs HUMAN"<<endl;
    cin>>x;
    if(x==1)HumVsComp();
    else if(x==2)makeboard();
    else
    {
        cout<<"INVALID INPUT";
        goto asAgain;
    }
}
void HumVsComp()
{
    cout<<"enter player 1 initial  ";
    cin>>name1;
    name2[0]='C';
    name2[1]='O';
    whichMode=1;
start:
    cout<<"enter the dots in x axis(2-10)";
    cin>>globalX;
    if(globalX>11||globalX<3)goto start;
    cout<<"enter the dots in y axis(2-10)";
    cin>>globalY;
    if(globalY>11||globalY<3)
    {
        cout<<"INVALID INPUT";
        goto start;
    }
    makedots(globalX,globalY);
}

void makedots(int i,int j)
{
    for(int o=1; o<=i; o++)
        for(int p=1; p<=j; p++)
        {
            dots[o-1][p-1].make_circle(o,p);
        }
}

void Result()
{
    if(countPlayer1>countPlayer2)
    {
        Text t2(870,450,name1);
        t2.imprint();
        Text t1(900,450,"WON");
        t1.imprint();
    }
    if(countPlayer1<countPlayer2)
    {
        Text t2(870,450,name2);
        t2.imprint();
        Text t1(900,450,"WON");
        t1.imprint();
    }
    if(countPlayer1==countPlayer2)
    {
        Text t1(900,450,"TIE");
        t1.imprint();
    }
}

void makeboard()
{
    cout<<"enter player 1 initial  ";
    cin>>name1;
    cout<<"enter player 2 initial  ";
    cin>>name2;
    whichMode=2;
start:
    cout<<"enter the dots in x axis(2-10)";
    cin>>globalX;
    if(globalX>11||globalX<3)goto start;
    cout<<"enter the dots in y axis(2-10)";
    cin>>globalY;
    if(globalY>11||globalY<3)
    {
        cout<<"invalid output";
        goto start;
    }
    makedots(globalX,globalY);
}

int checkLineNear(int a,int b,int c,int d)
{
    if((abs(a-c)<=1&&b==d)||(a==c&&abs(b-d)<=1))return 1;
    else return 0;
}

int SEARCH_DOT(int a)
{
    int r,e,w,q;
    q=a/65536;
    w=a%65536;
    if(q%60<=10)
        e=q/60;
    else if(q%60>=50)
        e=(q/60)+1;
    else
    {
        Text t1(900,500,"Wrong dot");
        wait(1);
        return 65336;
    }
    if(w%60<=10)
        r=w/60;
    else if(w%60>=50)
        r=(w/60)+1;
    else
    {
        Text t1(900,500,"Wrong dot");
        wait(1);
        return 65336;
    }

    dots[e-1][r-1].CHANGE_COLOR_CIRCLE();
    return (e-1)*10+(r-1);
}

void startMakingLine(int a)
{
    if(whichMode==2)
    {
        if(a==0)
        {
            Text t1(900,100,name1);
            wait(1);
        }

        if(a==1)
        {
            Text t1(900,100,name2);
            wait(1);

        }
samePoint:
        Text text1(900,600,"choose first point");
        int click,click1;
        click=getClick();
        int x=SEARCH_DOT(click);
        if(x==65336)
            goto samePoint;

        Text text2(900,600,"choose second point");
        click1=getClick();
        int y=SEARCH_DOT(click1);
        if(y==65336)
        {
            dots[x/10][x%10].make_circle1();
            goto samePoint;
        }
        if(x==y)
        {
            Text text3(900,500,"You clicked the same point");
            wait(.7);
            dots[x/10][x%10].make_circle1();
            goto samePoint;
        }
        makeLine(x,y,a);                                                  //check if the second click is adjacent to first click
                                                                          //if yes, proceed with line drawing provided a line doesnt exist already
    }
    if(whichMode==1)
    {
        if(a==0)
        {
            Text t1(900,100,name1);
            wait(1);
samePoint1:
            Text text1(900,600,"choose first point");
            int click,click1;
            click=getClick();
            int x=SEARCH_DOT(click);
            if(x==65336)
                goto samePoint1;

            Text text2(900,600,"choose second point");
            click1=getClick();
            int y=SEARCH_DOT(click1);

            if(y==65336)
            {
                dots[x/10][x%10].make_circle1();
                goto samePoint1;
            }
            if(x==y)
            {
                Text text3(900,500,"You clicked the same point");
                wait(.7);
                dots[x/10][x%10].make_circle1();
                goto samePoint1;
            }
        makeLine(x,y,a);                                                //check if the second click is adjacent to first click
                                                                        //if yes, proceed with line drawing provided a line doesnt exist already
        }
        if(a==1)
        {
            Text t1(900,100,name2);
            wait(1);
            compTurn();
        }
    }
}


void makeLine(int a,int b,int c)//make line for the clicked coordinates
{
    int x1,x2,y1,y2;
    x1=a/10;
    x2=b/10;
    y1=a%10;
    y2=b%10;
    int checkit=checkLineNear(x1,y1,x2,y2);

    if(noTwoLine[x1*10+y1][x2*10+y2]==1)
    {
        Text t1(900,600,"line already  exist");
        wait(.7);
        startMakingLine(c);
    }

    else if(checkit==1&&noTwoLine[x1*10+y1][x2*10+y2]!=1)
    {
        countLine++;
        int p1=dots[x1][y1].getX();
        int p2=dots[x1][y1].getY();
        int p3=dots[x2][y2].getX();
        int p4=dots[x2][y2].getY();
        Line l(p1,p2,p3,p4);
        noTwoLine[x2*10+y2][x1*10+y1]=1;
        noTwoLine[x1*10+y1][x2*10+y2]=1;
        if(c==0)
            l.setColor(COLOR("blue"));
        else
            l.setColor(COLOR("green"));
        l.imprint();
        makeSquare(x1*10+y1,x2*10+y2,c);
    }

    else
    {
        Text t1(900,700,"Wrong dots Joined");
        wait(.7);
        dots[x1][y1].make_circle1();
        dots[x2][y2].make_circle1();
        startMakingLine(c);
    }
}

void makeSquare(int a,int b,int c)
{
    char q[3];
    int no_of_line=((globalX-1)*globalY)+(globalX*(globalY-1));
    int x1,x2,y1,y2,flag=0;
    x1=a/10;
    y1=a%10;
    x2=b/10;
    y2=b%10;
    if(c==0)
    {
        for(int i=0; i<3; i++)
            q[i]=name1[i];
    }
    if(c==1)
    {
        for(int i=0; i<3; i++)
            q[i]=name2[i];
    }
    if(c==0)
    {
        if(x1==x2&&noTwoLine[x1*10+y1][x2*10+y2]==1&&noTwoLine[(x1-1)*10+y1][x1*10+y1]==1&&noTwoLine[(x1-1)*10+y1][(x2-1)*10+y2]==1&&noTwoLine[(x2-1)*10+y2][x2*10+y2]==1)
        {
            if(y1<y2)
            {
                Text t1((x1+1)*60-30,(y1+1)*60+30,q);
                t1.setColor(COLOR("blue"));
                t1.imprint();
                countPlayer1++;
                flag=1;
            }
            else
            {
                Text t1((x1+1)*60-30,(y1+1)*60-30,q);
                t1.setColor(COLOR("blue"));
                t1.imprint();
                countPlayer1++;
                flag=1;
            }
        }
        if(x1==x2&&noTwoLine[x1*10+y1][x2*10+y2]==1&&noTwoLine[(x1+1)*10+y1][x1*10+y1]==1&&noTwoLine[(x1+1)*10+y1][(x2+1)*10+y2]==1&&noTwoLine[(x2+1)*10+y2][x2*10+y2]==1)
        {
            if(y1<y2)
            {
                Text t1((x1+1)*60+30,(y1+1)*60+30,q);
                t1.setColor(COLOR("blue"));
                t1.imprint();
                countPlayer1++;
                flag=1;
            }
            else
            {
                Text t1((x1+1)*60+30,(y1+1)*60-30,q);
                t1.setColor(COLOR("blue"));
                t1.imprint();
                countPlayer1++;
                flag=1;
            }
        }
        if(y1==y2&&noTwoLine[x1*10+y1][x2*10+y2]==1&&noTwoLine[x1*10+(y1-1)][x1*10+y1]==1&&noTwoLine[x1*10+(y1-1)][x2*10+(y2-1)]==1&&noTwoLine[x2*10+(y2-1)][x2*10+y2]==1)
        {
            if(x1<x2)
            {
                Text t1((x1+1)*60+30,(y1+1)*60-30,q);
                t1.setColor(COLOR("blue"));
                t1.imprint();
                countPlayer1++;
                flag=1;
            }
            else
            {
                Text t1((x1+1)*60-30,(y1+1)*60-30,q);
                t1.setColor(COLOR("blue"));
                t1.imprint();
                countPlayer1++;
                flag=1;
            }
        }
        if(y1==y2&&noTwoLine[x1*10+y1][x2*10+y2]==1&&noTwoLine[x1*10+(y1+1)][x1*10+y1]==1&&noTwoLine[x1*10+(y1+1)][x2*10+(y2+1)]==1&&noTwoLine[x2*10+(y2+1)][x2*10+y2]==1)
        {
            if(x1<x2)
            {
                Text t1((x1+1)*60+30,(y1+1)*60+30,q);
                t1.setColor(COLOR("blue"));
                t1.imprint();
                countPlayer1++;
                flag=1;
            }
            else
            {
                Text t1((x1+1)*60-30,(y1+1)*60+30,q);
                t1.setColor(COLOR("blue"));
                t1.imprint();
                countPlayer1++;
                flag=1;
            }
        }
        Text Score2(860,150,q);
        Score2.imprint();
        Text Score(900,150,"SCORE");
        Score.imprint();
        Text Score1(950,150,countPlayer1);
        Score1.imprint();
        if(countLine==no_of_line)
        {
            Result();
            wait(8);
            exit(1);
        }
        if(flag==1)startMakingLine(c);
    }
    if(c==1)
    {
        if(x1==x2&&noTwoLine[x1*10+y1][x2*10+y2]==1&&noTwoLine[(x1-1)*10+y1][x1*10+y1]==1&&noTwoLine[(x1-1)*10+y1][(x2-1)*10+y2]==1&&noTwoLine[(x2-1)*10+y2][x2*10+y2]==1)
        {
            if(y1<y2)
            {
                Text t1((x1+1)*60-30,(y1+1)*60+30,q);
                t1.setColor(COLOR("green"));
                t1.imprint();
                countPlayer2++;
                flag=1;
            }
            else
            {
                Text t1((x1+1)*60-30,(y1+1)*60-30,q);
                t1.setColor(COLOR("green"));
                t1.imprint();
                countPlayer2++;
                flag=1;
            }
        }
        if(x1==x2&&noTwoLine[x1*10+y1][x2*10+y2]==1&&noTwoLine[(x1+1)*10+y1][x1*10+y1]==1&&noTwoLine[(x1+1)*10+y1][(x2+1)*10+y2]==1&&noTwoLine[(x2+1)*10+y2][x2*10+y2]==1)
        {
            if(y1<y2)
            {
                Text t1((x1+1)*60+30,(y1+1)*60+30,q);
                t1.setColor(COLOR("green"));
                t1.imprint();
                countPlayer2++;
                flag=1;
            }
            else
            {
                Text t1((x1+1)*60+30,(y1+1)*60-30,q);
                t1.setColor(COLOR("green"));
                t1.imprint();
                countPlayer2++;
                flag=1;
            }
        }
        if(y1==y2&&noTwoLine[x1*10+y1][x2*10+y2]==1&&noTwoLine[x1*10+(y1-1)][x1*10+y1]==1&&noTwoLine[x1*10+(y1-1)][x2*10+(y2-1)]==1&&noTwoLine[x2*10+(y2-1)][x2*10+y2]==1)
        {
            if(x1<x2)
            {
                Text t1((x1+1)*60+30,(y1+1)*60-30,q);
                t1.setColor(COLOR("green"));
                t1.imprint();
                countPlayer2++;
                flag=1;
            }
            else
            {
                Text t1((x1+1)*60-30,(y1+1)*60-30,q);
                t1.setColor(COLOR("green"));
                t1.imprint();
                countPlayer2++;
                flag=1;
            }
        }
        if(y1==y2&&noTwoLine[x1*10+y1][x2*10+y2]==1&&noTwoLine[x1*10+(y1+1)][x1*10+y1]==1&&noTwoLine[x1*10+(y1+1)][x2*10+(y2+1)]==1&&noTwoLine[x2*10+(y2+1)][x2*10+y2]==1)
        {
            if(x1<x2)
            {
                Text t1((x1+1)*60+30,(y1+1)*60+30,q);
                t1.setColor(COLOR("green"));
                t1.imprint();
                countPlayer2++;
                flag=1;
            }
            else
            {
                Text t1((x1+1)*60-30,(y1+1)*60+30,q);
                t1.setColor(COLOR("green"));
                t1.imprint();
                countPlayer2++;
                flag=1;
            }
        }
        Text Score2(860,170,q);
        Score2.imprint();
        Text Score(900,170,"SCORE");
        Score.imprint();
        Text Score1(950,170,countPlayer2);
        Score1.imprint();
        if(countLine==no_of_line)
        {
            Result();
            wait(8);
            exit(1);
        }
        if(flag==1)startMakingLine(c);
    }
}
void compTurn()
{
    int flag=0;
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
        {
            if(noTwoLine[(i+1)*10+j][(i+1)*10+(j+1)]!=1&&noTwoLine[i*10+j][i*10+(j+1)]==1&&noTwoLine[i*10+j][(i+1)*10+j]==1&&noTwoLine[i*10+(j+1)][(i+1)*10+(j+1)]==1)
            {
                makeLine((i+1)*10+j,(i+1)*10+(j+1),1);
                flag=1;
            }
            if(noTwoLine[i*10+j][i*10+(j+1)]!=1&&noTwoLine[(i+1)*10+j][(i+1)*10+(j+1)]==1&&noTwoLine[i*10+j][(i+1)*10+j]==1&&noTwoLine[i*10+(j+1)][(i+1)*10+(j+1)]==1)
            {
                if(flag!=0)break;

                makeLine(i*10+j,i*10+(j+1),1);
                flag=1;

            }
            if(noTwoLine[i*10+j][(i+1)*10+j]!=1&&noTwoLine[(i+1)*10+j][(i+1)*10+(j+1)]==1&&noTwoLine[i*10+j][i*10+(j+1)]==1&&noTwoLine[i*10+(j+1)][(i+1)*10+(j+1)]==1)

            {
                if(flag!=0)break;
                makeLine(i*10+j,(i+1)*10+j,1);
                flag=1;
            }
            if(noTwoLine[i*10+(j+1)][(i+1)*10+(j+1)]!=1&&noTwoLine[(i+1)*10+j][(i+1)*10+(j+1)]==1&&noTwoLine[i*10+j][i*10+(j+1)]==1&&noTwoLine[i*10+j][(i+1)*10+j]==1)
            {
                if(flag!=0)break;
                makeLine(i*10+(j+1),(i+1)*10+(j+1),1);
                flag=1;
            }
        }
    if(flag==0)
    {
imback:
        int r1,r2,x;

        r1=rand()%globalX;
        r2=rand()%globalY;
        if(r1==0&&r2==0)
        {
            x=rand()%2;
            switch(x)
            {
            case 0:
                if(noTwoLine[r1*10+r2][(r1+1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1+1)*10+r2,1);//right line
                flag=1;
                break;
            case 1:
                if(noTwoLine[r1*10+r2][r1*10+(r2+1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2+1),1);//down line
                flag=1;
                break;

            }
        }
        else if(r1==(globalX-1)&&r2==(globalY-1))
        {
            x=rand()%2;
            switch(x)
            {
            case 0:
                if(noTwoLine[r1*10+r2][r1*10+(r2-1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2-1),1);//top line
                flag=1;
                break;
            case 1:
                if(noTwoLine[r1*10+r2][(r1-1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1-1)*10+r2,1);//left line
                flag=1;
                break;
            }
        }
        else if(r1==0&&r2==(globalY-1))
        {
            x=rand()%2;
            switch(x)
            {
            case 0:
                if(noTwoLine[r1*10+r2][(r1+1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1+1)*10+r2,1);//right line
                flag=1;
                break;
            case 1:
                if(noTwoLine[r1*10+r2][r1*10+(r2-1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2-1),1);//top line
                flag=1;
                break;

            }
        }
        else if(r1==(globalX-1)&&r2==0)
        {
            x=rand()%2;
            switch(x)
            {
            case 0:
                if(noTwoLine[r1*10+r2][(r1-1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1-1)*10+r2,1);//left line
                flag=1;
                break;

            case 1:
                if(noTwoLine[r1*10+r2][r1*10+(r2+1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2+1),1);//down line
                flag=1;
                break;

            }
        }

        else if(r1==0)
        {
            x=rand()%3;
            switch(x)
            {
            case 0:
                if(noTwoLine[r1*10+r2][r1*10+(r2+1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2+1),1);
                flag=1;
                break;
            case 1:
                if(noTwoLine[r1*10+r2][(r1+1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1+1)*10+r2,1);
                flag=1;
                break;
            case 2:
                if(noTwoLine[r1*10+r2][r1*10+(r2-1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2-1),1);
                flag=1;
                break;
            }
        }
        else if(r2==0)
        {
            x=rand()%3;
            switch(x)
            {
            case 0:
                if(noTwoLine[r1*10+r2][r1*10+(r2+1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2+1),1);
                flag=1;
                break;
            case 1:
                if(noTwoLine[r1*10+r2][(r1+1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1+1)*10+r2,1);
                flag=1;
                break;
            case 2:
                if(noTwoLine[r1*10+r2][(r1-1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1-1)*10+r2,1);
                flag=1;
                break;
            }
        }
        else if(r1==(globalX-1))
        {
            x=rand()%3;
            switch(x)
            {
            case 0:
                if(noTwoLine[r1*10+r2][r1*10+(r2+1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2+1),1);
                break;
            case 1:
                if(noTwoLine[r1*10+r2][r1*10+(r2-1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2-1),1);
                break;
            case 2:
                if(noTwoLine[r1*10+r2][(r1-1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1-1)*10+r2,1);
                break;

            }
        }
        else if (r2==(globalY-1))
        {
            x=rand()%3;
            switch(x)
            {
            case 0:
                if(noTwoLine[r1*10+r2][(r1+1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1+1)*10+r2,1);
                break;
            case 1:
                if(noTwoLine[r1*10+r2][r1*10+(r2-1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2-1),1);
                break;
            case 2:
                if(noTwoLine[r1*10+r2][(r1-1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1-1)*10+r2,1);
                break;
            }
        }

        else
        {
            x=rand()%4;
            switch(x)
            {
            case 0:
                if(noTwoLine[r1*10+r2][(r1+1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1+1)*10+r2,1);
                break;
            case 1:
                if(noTwoLine[r1*10+r2][r1*10+(r2-1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2-1),1);
                break;
            case 2:
                if(noTwoLine[r1*10+r2][(r1-1)*10+r2]==1)goto imback;
                makeLine(r1*10+r2,(r1-1)*10+r2,1);
                break;
            case 3:
                if(noTwoLine[r1*10+r2][r1*10+(r2+1)]==1)goto imback;
                makeLine(r1*10+r2,r1*10+(r2+1),1);
                break;
            }
        }
    }
}
