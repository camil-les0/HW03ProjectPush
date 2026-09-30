
#include <iostream>
#include<iomanip>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std ;

void EscribirCartones(int [][5][5], int);

void imprimirCartones(int [][5][5], int, string[]);

int sortearBola(bool[]);

void marcarNumero(int[][5][5], int, int);

bool verificarGanador(int[5][5]);

int main (){
	
string entrada;
int numGamers = 0;

do {
    cout << "Ingrese el numero de jugadores: ";
    cin >> entrada;

    bool esNum = true;

    for (int i = 0; i < entrada.length() && esNum; i++) {
        if (!isdigit(entrada[i])) {
            esNum = false;
        }
    }
    if (esNum) {
        numGamers = stoi(entrada);
    } else {
        numGamers = 0;
    }

    if (numGamers < 3) {
        cout << "Error: Entrada invalida o menor a 3.\n\n";
    }

} while (numGamers < 3);

	cin.ignore();
	string nombres[numGamers];

	for(int i = 0; i < numGamers; i++ ){
		
		cout << "Ingrese el nombre del Jugador " << i+1 << ": ";
		getline(cin, nombres[i]);
		cout << endl;
	}

	
    cout << "\n Listo Jugadores registrados: " << numGamers << endl;
    cin.get();
	
	cout<<"======================================================================="<<endl;
	cout<<"|                          BIENVENIDO A BINGO                         |"<<endl;
	cout<<"======================================================================="<<endl;
	cin.get();
	cout << "========================================================================"<<endl;
    cout << "|                          REGLAS DEL BINGO                            |"<<endl;
    cout << "========================================================================"<<endl;
    cout << "1. Se sortearan numeros aleatorios del 1 al 75."<<endl;
    cout << "2. Si el numero esta en tu carton, se marcara con un '*'."<<endl;
    cout << "3. El carton se actualizara despues de cada sorteo."<<endl;
    cout << "4. Para ganar debes completar una de estas combinaciones:"<<endl;
    cout << "   - Una fila completa."<<endl;
    cout << "   - Una columna completa."<<endl;
    cout << "   - Una diagonal completa."<<endl;
    cout << "5. El juego termina cuando alguien gana o se acaban los numeros."<< endl;
    
    cin.get();
	
	cout << "Iniciamos: \n";
	cin.get();
	
	int carton[numGamers][5][5];

    EscribirCartones(carton, numGamers);
	imprimirCartones(carton, numGamers, nombres);
	cin.get();
	
	int bola;

	bool ganador = false;
 	bool bolasUsadas[76] = {false};
	int bolasSacadas = 0;
	int numbolas;
	

while(!ganador && bolasSacadas < 75)
	{
	numbolas++;
    int bola = sortearBola(bolasUsadas);

    bolasSacadas++;

    cout << "\nBola sorteada: " << bola << endl;
	cin.get();
    marcarNumero(carton, numGamers, bola);
    imprimirCartones(carton, numGamers, nombres);
	cin.get();
    for(int i = 0; i < numGamers && !ganador; i++)
    {
        if(verificarGanador(carton[i]))
        {
            cout<< endl;
            cout << "\n !BINGO¡ Felicidades, has ganado " << nombres[i] << endl;
            ganador = true;
        }
    }
}

if(!ganador)
{	cout << endl;
    cout << "Se han sorteado las 75 bolas." << endl;
    cout << "Ningun jugador completo una fila, una columna o una diagonal." << endl;
    cout << "No hubo ganador." << endl;
}

cout <<"Bolas Sorteadas "<< numbolas<<endl; 
	return 0;
}
void EscribirCartones(int box[][5][5], int numG)
{
    for(int i = 0; i < numG; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int inicio = j * 15 + 1;

            for(int k = 0; k < 5; k++)
            {
                if(j == 2 && k == 2)
                {
                    box[i][k][j] = 0;
                }
                else
                {
                    bool repetido;

                    do
                    {
                        repetido = false;

                        box[i][k][j] = rand() % 15 + inicio;

                        for(int l = 0; l < k && !repetido; l++)
                        {
                            if(box[i][l][j] == box[i][k][j])
                            {
                                repetido = true;
                            }
                        }

                    }while(repetido);
                }
            }
        }
    }
}

void imprimirCartones(int box[][5][5], int numG, string nom[])
{
    //nombre
    for(int jugador=0; jugador<numG; jugador++)
    {
        string nombre = nom[jugador];

        if(nombre.length()>21)
            nombre = nombre.substr(0,18) + "...";

        cout << left << setw(25) << nombre;
    }

    cout << endl;

    //letra bingo
    for(int jugador=0; jugador<numG; jugador++)
    {
        cout << left << setw(25) << "B   I   N   G   O";
    }

    cout << endl;

    //inicio de tabla
    for(int jugador=0; jugador<numG; jugador++)
    {
        cout << "-------------------------";
    }

    cout << endl;

    //carton
    for(int fila=0; fila<5; fila++)
    {
        for(int jugador=0; jugador<numG; jugador++)
        {
            for(int col=0; col<5; col++)
            {
                if(box[jugador][fila][col]==0)
                    cout << setw(4) << "*";
                else
                    cout << setw(4) << box[jugador][fila][col];
            }

            cout << "    ";
        }

        cout << endl;
    }
}
int sortearBola(bool usadas[])
{
    int num;

    do
    {
        num = rand() % 75 + 1;
    }
    while(usadas[num] == true);

    usadas[num] = true;

    return num;
}
void marcarNumero(int box[][5][5], int numG, int numero)
{
    for(int jugador = 0; jugador < numG; jugador++)
    {
        for(int fila = 0; fila < 5; fila++)
        {
            for(int col = 0; col < 5; col++)
            {
                if(box[jugador][fila][col] == numero)
                {
                    box[jugador][fila][col] = 0;
                }
            }
        }
    }
}
bool verificarGanador(int carton[5][5])
{
    // filas
    for(int fila = 0; fila < 5; fila++)
    {
        bool completa = true;

        for(int col = 0; col < 5; col++)
        {
            if(carton[fila][col] != 0)
            {
                completa = false;
            }
        }

        if(completa)
        {
            return true;
        }
    }

    // columnas
    for(int col = 0; col < 5; col++)
    {
        bool completa = true;

        for(int fila = 0; fila < 5; fila++)
        {
            if(carton[fila][col] != 0)
            {
                completa = false;
            }
        }

        if(completa)
        {
            return true;
        }
    }

    // diagonal principal
    bool completa = true;

    for(int i = 0; i < 5; i++)
    {
        if(carton[i][i] != 0)
        {
            completa = false;
        }
    }

    if(completa)
    {
        return true;
    }

    // diagonal secundaria
    completa = true;

    for(int i = 0; i < 5; i++)
    {
        if(carton[i][4-i] != 0)
        {
            completa = false;
        }
    }

    if(completa)
    {
        return true;
    }

    return false;
}