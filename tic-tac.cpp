#include "iostream"
#include "cstdlib"

bool board(int x, int y, char Player2Symbol, char Player1Symbol, bool Player1_turn, char brd[3][3]){
    if(Player1_turn){
        brd[x-1][y-1] = Player1Symbol;
    }
    else {
        brd[x-1][y-1] = Player2Symbol;
    };

    for (int i=0; i<2; i++){
        for (int a=0; a<3; a++){
            switch (brd[i][a]) {
                case '-':
                    if(a == 1){
                        std::cout << '|' << '_' << '|';
                    }
                    else {
                        std::cout << '_';
                    }
                    break;
                case 'x':
                    if(a == 1){
                        std::cout << '|' << 'x' << '|';
                    }
                    else {
                        std::cout << 'x';
                    }
                    break;
                case 'o':
                    if(a == 1){
                        std::cout << '|' << 'o' << '|';
                    }
                    else {
                        std::cout << 'o';
                    }
                    break;
            }
        };
        std::cout << "\n";
    };
    std::cout << " " << "|" << " " << "|";
    std::cout << "\n" << "|--------------------|" << "\n";

    if(Player1_turn){
        Player1_turn = false;
    }
    else {
        Player1_turn = true;
    };
    return Player1_turn;
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
    char brd[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    std::string PlayerName1;
    std::string PlayerName2;
    char Player1Symbol;
    char Player2Symbol;
    int x;
    int y;
    bool invalidSym = true;
    int go = 0;
    bool Player1_turn = false;

    std::cout << "Player1 enter your name: ";
    std::cin >> PlayerName1;
    std::cout << "Player2 enter your name: ";
    std::cin >> PlayerName2;

    std::cout << PlayerName1 << " choose [o/x] -> ";
    std::cin >> Player1Symbol;

    if(Player1Symbol == 'o' || Player1Symbol == 'x'){
    }
    else {
        while(invalidSym){
            std::cout << "Invalid symbol, try again\n";
            std::cout << "-> ";
            std::cin >> Player1Symbol;
            if(Player1Symbol == 'o' || Player1Symbol == 'x'){
                invalidSym = false;
            }
        }
    }

    switch (Player1Symbol) {
        case 'x':
            Player2Symbol = 'o';
            break;
        case 'o':
            Player2Symbol = 'x';
            break;
    };

    while(go < 10){
        if(!Player1_turn){
            std::cout << PlayerName1 << " enter coordinates\n";
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
        }
        else {
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
        };
        Player1_turn = board(x, y, Player2Symbol, Player1Symbol, Player1_turn, brd);
        go += 1;
    };


    return 0;
}
