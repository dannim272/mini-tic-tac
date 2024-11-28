#include "iostream"
#include "cstdlib"

void board(int x, int y, char Player2Symbol){
    char brd[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    brd[x][y] = Player2Symbol;

    for (int i=0; i<3; i++){
        for (int a=0; a<3; a++){
            switch (brd[i][a]) {
                case '-':
                    std::cout << '_'; 
                    break;
                case 'x':
                    std::cout << 'x';
                    break;
                case 'o':
                    std::cout << 'o';
                    break;
            }
        }
        std::cout << "\n";
    };
}

bool verify(int x, int y){
    if(x > 0 && x < 4 && y > 0 && y < 4){
        return true;
    }
    else {
        return false;
    }
}

int main(){
    std::string PlayerName1;
    std::string PlayerName2;
    char Player1Symbol;
    char Player2Symbol;
    int x;
    int y;

    std::cout << "Player1 enter your name: ";
    std::cin >> PlayerName1;
    std::cout << "Player2 enter your name: ";
    std::cin >> PlayerName2;

    std::cout << PlayerName1 << " choose [o/x] -> ";
    std::cin >> Player1Symbol;

    std::cout << PlayerName2 << " enter coordinates\n";
    std::cout << "-> ";
    std::cin >> x;
    std::cout << "-> ";
    std::cin >> y;

    while (!verify(x, y)){
        std::cout << "Invalid coordinates, enter again\n";
        std::cout << "-> ";
        std::cin >> x;
        std::cout << "-> ";
        std::cin >> y;
    };

    board(x,y,Player2Symbol);

    return 0;
}
