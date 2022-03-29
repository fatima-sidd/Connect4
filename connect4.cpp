#include<iostream>
#include<string>

using namespace std;


struct connect4{

    connect40(string Names[]){
        re_init(Names);
    }

    connect4(){
        string N[2] = {"P1", "P2"};
        re_init(N);
    }

    void re_init(string Names[]){
        for(int i = 0; i< 7; i++){
            ColumnMoves[i] = 6;
            for(int j = 0; j< 6; j++)
                Data[j][i] = 32; // 32 is code of space character
        }
        Result = 0;
        GameOver = 0;
        PlayerNames[0] = Names[0];
        PlayerNames[1] = Names[1];
        PlayerChar[0] = 'o';
        PlayerChar[1] = 'x';
        PlayerWinningChar[0] = 'O';
        PlayerWinningChar[1] = 'X';
    }

    int MakeMove(int Column){

    WhosTurn();

    int r,c;
    Column--;
    r=ColumnMoves[Column]-1;
    c=Column;
    Data[r][c]=PlayerChar[TurningPlayer];
    CheckIfGameOver(r,c);

    ColumnMoves[Column]--;

    int ret=0;
    if (ColumnMoves[Column]<=0)
    {
         ret=1;
    }

    else if (GameOver==true)
    {
        ret=2;
        if (TurningPlayer==0 && match==true)
            Result=1;

        if (TurningPlayer==1 && match==true)
            Result=-1;

        else Result==0;

        cout<<endl<<endl<<endl<<endl<<"Result = "<<Result;

    }

    else
    {
        if(TurningPlayer==0)
        {
            TurningPlayer++;
        }
        else
            TurningPlayer--;
    }

    return ret;

}

    void ShowGame(){

    cout<<endl<<"  1    2    3    4    5    6    7"<<endl;;
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            cout<<" "<<"|"<<Data[i][j]<<"|"<<" ";
        }
        cout<<endl<<" --------------------------------- "<<endl;
    }
}

    bool isGameOver(){

        return GameOver;
    }

    int WhosTurn(){

    if (TurningPlayer%2==0)
    {
        TurningPlayer=0;
    }
    else
        TurningPlayer=1;

    return TurningPlayer;
    }

    string getPlayerName(int id){
        if(id< 0 || id > 1 )
            return "";
        return PlayerNames[id];
    }

private:
    bool CheckIfGameOver(int r, int c){

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++){

            if( Data[r][c]==Data[r+1][c]&&Data[r][c]==Data[r+2][c]&&Data[r][c]==Data[r+3][c])
            {
                match=true;
                for(int i=0;i<4;i++)
                {
                    for (int k=0; k<=3; k++)
                    {
                        Data[r+k][c]=PlayerWinningChar[TurningPlayer];
                    }
                }
            }

            if(Data[r][c]==Data[r][c+1]&&Data[r][c]==Data[r][c+2]&&Data[r][c]==Data[r][c+3])
            {
                match=true;
                for(int i=0;i<4;i++)
                {
                    for (int k=0; k<=3; k++)
                    {
                        Data[r][c+k]=PlayerWinningChar[TurningPlayer];
                    }
                }
            }

            if(Data[r][c]==Data[r][c-1]&&Data[r][c]==Data[r][c-2]&&Data[r][c]==Data[r][c-3])
            {
                match=true;
                for(int i=0;i<4;i++)
                {
                    for (int k=0; k<=3; k++)
                    {
                        Data[r][c-k]=PlayerWinningChar[TurningPlayer];
                    }
                }

            }

            if(Data[r][c]==Data[r][c-1]&&Data[r][c]==Data[r][c+1]&&Data[r][c]==Data[r][c+2])
            {
                match=true;
                for(int i=0;i<4;i++)
                {
                    for (int k=-1; k<=2; k++)
                    {
                        Data[r][c+k]=PlayerWinningChar[TurningPlayer];
                    }
                }
            }

            if(Data[r][c]==Data[r][c-2]&&Data[r][c]==Data[r][c-1]&&Data[r][c]==Data[r][c+1])
            {
                match=true;
                for(int i=0;i<4;i++)
                {
                    for (int k=-2; k<=1; k++)
                    {
                        Data[r][c+k]=PlayerWinningChar[TurningPlayer];
                    }
                }
            }

            if(Data[r][c]==Data[r-1][c+1]&&Data[r][c]==Data[r-2][c+2]&&Data[r][c]==Data[r-3][c+3])
            {
                match=true;
                for(int i=0;i<4;i++)
                {
                    for (int k=0; k<=3; k++)
                    {
                        Data[r-k][c+k]=PlayerWinningChar[TurningPlayer];
                    }
                }
            }

            if(Data[r][c]==Data[r+1][c-1]&&Data[r][c]==Data[r+2][c-2]&&Data[r][c]==Data[r+3][c-3])
            {
                match=true;
                for(int i=0;i<4;i++)
                {
                    for (int k=0; k<=3; k++)
                    {
                        Data[r+k][c-k]=PlayerWinningChar[TurningPlayer];
                    }
                }
            }

            if(Data[r][c]==Data[r-1][c-1]&&Data[r][c]==Data[r-2][c-2]&&Data[r][c]==Data[r-3][c-3])
            {
                match=true;
                for(int i=0;i<4;i++)
                {
                    for (int k=0; k<=3; k++)
                    {
                        Data[r-k][c-k]=PlayerWinningChar[TurningPlayer];
                    }
                }
            }

            if(Data[r][c]==Data[r+1][c+1]&&Data[r][c]==Data[r+2][c+2]&&Data[r][c]==Data[r+3][c+3])
            {
                match=true;
                for(int i=0;i<4;i++)
                {
                   for (int k=0; k<=3; k++)
                    {
                        Data[r+k][c+k]=PlayerWinningChar[TurningPlayer];
                    }
                }
            }
        }
        if(match==true)
        {
            GameOver=true;
            return 1;
        }
    }
}

    string PlayerNames[2]; // To Hold Name of Players Who are playing
    int TurningPlayer; // To save the players ID who is making a move; 0: First Player, 1: Second Player
    char PlayerChar[2]; // Characters to be shown for move
    char PlayerWinningChar[2]; // Character to be shown if player wins.
    int  ColumnMoves[7]; // An array to keep record of first empty cell in a column
    char Data[6][7]; // Array to hold game data.
    bool GameOver; // If true it means the game is over.
    int Result;// Variable to hold result of game {0: Drawn, -1: First Player Lost, 1: First Player Won}
    bool match=false;
};


int main(){
    cout<<"Are you ready?"<<endl<<endl
        <<"Enter 1 to begin the game, \nEnter 0 to terminate"<<endl;
    int opt;
    cin>>opt;


    while (opt==1)
    {
        string N[2] ;

        connect4 C4;
        C4.ShowGame();

        cout<<"Enter name of first player : ";
        cin>>N[0];
        C4.connect40(N);

        cout<<"Enter name of second player : ";
        cin>>N[1];
        C4.connect40(N);

        cout<<endl<<endl<<endl<<"Beginning the game! "<<endl<<endl;

        do
        {
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"Player:  "<<C4.getPlayerName(C4.WhosTurn())<<"\nPlease enter a column number (1-7) to make your turn"<<endl;
            int col_no;

            cout<<"Column number:  ";
            cin>>col_no;

            while (col_no<1 || col_no>7)
            {
                cout<<endl<<"ERROR"<<endl
                    <<"Enter correct Column number between 1 and 7"<<endl
                    <<"Column number:  ";
                cin>>col_no;
            }

            C4.MakeMove(col_no);
            C4.isGameOver();
            C4.ShowGame();
        }
        while(C4.isGameOver() != true);

        cout<<C4.getPlayerName(C4.WhosTurn())<<"  WON THE GAME! "<<endl<<endl<<endl;

        cout<<"Enter 1 to replay, \nEnter 0 to terminate."<<endl;
        cin>>opt;

    }

    return 0;
}
