#include <iostream>

#define NO_GOOD_MOVE  0
#define MAX_MOVE 3
#define N_COINS 23
#define HUMAN 1
#define COMPUTER 0

using namespace std;

bool isBadPosition(int nCoins);   
 
int findGoodMove(int nCoins) {   // 4
    for (int n = 1; n <= MAX_MOVE; n++)
        if (isBadPosition(nCoins - n))
            return n;
    return NO_GOOD_MOVE;
}

bool isBadPosition(int nCoins) {
    if (nCoins == 1)
        return true;
    return
        findGoodMove(nCoins) == NO_GOOD_MOVE;
}

void variant_one() {
    int human_pile = 0;
    int nCoins = N_COINS, n;
    int whoseTurn = HUMAN;
    cout << "Welcome to Nim. We start with " << nCoins << endl;
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";
    while (nCoins > 1) {
        cout << "\nWe have " << nCoins << ".\n";
        cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        switch (whoseTurn) {
        case HUMAN:
            n = nCoins + 10;
            while (n < 1 || n > 3 || n > nCoins) {
                cout << "Pls pick 1 to 3 coins and <= remaining coins: ";
                cin >> n;
                
            }
            
            break;
        case COMPUTER:
            n = findGoodMove(nCoins);
            if (!n)
                n = 1;
            cout << "Computer takes " << n << " coins.\n";
        }
        nCoins -= n;
        whoseTurn = (whoseTurn + 1) % 2;
        
    }
    human_pile += n;
    if (human_pile % 2 != 0)
    {
        cout << "Human Wins \n";
    }
    else
    {
        cout << "Computer wins\n";
    }
}
void variant_two()
{
    int pile1 = 7, pile2 = 7, pile3 = 9, n;
    int whoseTurn = HUMAN;
    //cout << "Welcome to Nim. We start with " << nCoins << endl;
    cout << "Each one picks 1 to " << MAX_MOVE << " coins.\n";

    while (pile1 > 1 || pile2 > 1 || pile3 > 1) {
        cout << "\nWe have " << pile1 << " " << pile2 << " " << pile3 << ".\n";
        cout << (whoseTurn ? "Human" : "Computer") << " plays: ";
        switch (whoseTurn) {
        case HUMAN:
            n = pile1 + 10;
            while (n < 1 || n > 3 || (n > pile1 + pile2 + pile3)) {
                cout << "Pls pick 1 to 3 coins and <= remaining coins: ";
                cin >> n;
            }
            break;
        case COMPUTER:
            n = findGoodMove(pile1 + pile2 + pile3);
            if (!n)
                n = 1;
            cout << "Computer takes " << n << " coins.\n";
        }
        if (pile1 >= n)
        {
            pile1 -= n;
        }
        else if (pile2 >= n)
        {
            pile2 -= n;
        }
        else if (pile3 >= n)
        {
            pile3 -= n;
        }

        whoseTurn = (whoseTurn + 1) % 2;
    }
     if (pile3 == 1)
        {
            cout << "\n\nWinner is : " << (whoseTurn ? "Computer \n" : "Human \n");
        }

}
    

int main() {
   
    int validation;
    cout << "For variante One press(1) || For variante two press(2)\n";
    cin >> validation;
    if (validation == 1)
    {
        variant_one();
    }
    else if (validation == 2)
    {
        variant_two();
    }
    
    return 0;
}


