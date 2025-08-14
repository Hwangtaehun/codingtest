#include <iostream>
#include <fstream>
#define SIZE 19

using namespace std;

class Omok{
private:
    int board[SIZE][SIZE];
    int result;
    int sx, sy;
    int ex, ey;
public:
    Omok();
    ~Omok();
    void process();
    int getBoard(int x, int y);
};

Omok::Omok()
{
    ifstream inf("input.txt");

    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            inf >> board[i][j];
        }
    }

    inf.close();
    result = 0;
}

Omok::~Omok(){
    ofstream ouf("output.txt");
    ouf << result << endl;
    if(result){
        ouf << sy + 1 <<  ' ' << sx+1  << endl;
    }
    ouf.close();
}

void Omok::process(){
    const int direction[4][2] = {{1,0}, {0, 1}, {1, 1}, {1, -1}};
    int x, y, dir;
    int currentColor;

    for(int dir = 0; dir < 4; dir++){
        for(int y = 0; y < 19; y++){
            for(int x = 0; x < 19; x++){
                if( (currentColor = getBoard(x, y) ) && getBoard(x, y) != getBoard(x - direction[dir][0], y - direction[dir][1])){
                    int count = 0;
                    int xh = x, yh = y;

                    while( getBoard(xh, yh) == currentColor ){
                        xh += direction[dir][0];
                        yh += direction[dir][1];
                        count++;
                    }

                    if(count == 5){
                        result = currentColor;
                        sx = x;
                        sy = y;
                        ex = xh;
                        ey = yh;
                        return;
                    }
                }
            }
        }
    }
}

int Omok::getBoard(int x, int y){
    if ( x < 0 )
        return 0;
    if ( y < 0 )
        return 0;
    if ( x >= 19)
        return 0;
    if ( y >= 19)
        return 0;

    return board[y][x];
}

int main()
{
    Omok o;
    o.process();
    return 0;
}
