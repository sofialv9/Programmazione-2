#include <iostream>
using namespace std;

int main()
{
    // il cast è sempre possibile tra tipi di base (sempre safe)

    // static_cast
    double d = 10.5;
    int i = static_cast<int>(d);

    // dynamic_cast - controlla che il cast sia andato a buon fine (se non è così il puntatore risultante è uguale a nullptr)
    SquadraClub* club = dynamic_cast<SquadraClub*>(sq[i]);
}