/**
 * Altere e complete o programa de maneira que ele seja capaz de
 * calcular a serie de Fibonacci ate 10^19 ou 10000000000000000000.
 */

#include <iostream>

using namespace::std;


//-------------------------------------------------------------------------------
//! Imprime um vetor de inteiros longos sem sinal.
/*! Esta funcao imprime na saida padrao um vetor de inteiros cujo tamanho eh
 *  passado como argumento.
 *  @param _A O vetor a ser impresso na saida padrao.
 *  @param _sz O tamanho do vetor passado como argumento.
 */
void
printArray( long long _A[ ], int _sz )
{
    // Imprimir o vetor.
    cout << ">>> [ ";
    for ( int i(0) ; i <= _sz ; ++i )
        cout << _A[ i ] << " ";
    cout << "]\n";
}

//-------------------------------------------------------------------------------
//! Gera a sequencia de Fibonacci em um vetor ate um limite informado.
/*! Esta funcao gera em um vetor alocado dinamicamente a serie de Fibonacci ate
 *  antes de atingir um limite inteiro passado por parametro.
 *  Por exemplo, se limite = 15, o vetor gerado deve ser [ 1 1 2 3 5 8 13 ],
 *  visto que o ultimo elemento da serie e 13 < limite (=15).
 *
 *  @param _limit O limite inteiro que determina o fim da serie.
 *  @param _A Pointeiro que deverah conter o vetor com a serie.
 *  @return Number of elements in the Fibonacci series (size of _A)
 */
int
fib( int _limit, long long  *&_A ) // Faltando o &, pois os valores do vetor A dentro da função, não estavam refletindo nos valores de A[] fora da função.
{
    int count = 0;
    int fib0 = 1;
    int fib1 = 0;
    int fib2 = 0;
    int i = 0;

    _A = new long long[count];

    while ( fib2 < _limit )
    {
        fib2 = fib0 + fib1;
    
            _A[count] = fib2;
            //para testes
            cout << _A[count] << " " << endl;

        //cout << fib2 << " "; // imprimir na tela apenas para depurar
        //_A[count] = fib2;
        count++; // usado para determinar o comprimento da serie.
        fib0 = fib1;
        fib1 = fib2;
        
    }
    cout << endl; // descarregar a lista.

    // TODO: Aqui devemos criar e preencher o vetor com a serie
    /*_A = new int[count];
    for (i = 0 ; i < count ; i++ ){
        _A[i] = i;
        //para testes
        cout << _A[i] << " " << endl;
    }*/

    return count-2;
}

int main () {
    int L; // Valor limite da serie, cujo valor maximo deve ser inferior.
    long long *A = nullptr; // Ponteiro para o vetor a ser criado dinamicamente.

    cout << ">>> Indique o limite para a serie de Fibonacci (n > 0): ";
    cin >> L; // Ler valor do terminal.

    if ( L >= 0 ) {
        auto sz = fib( L, A ); // Gerar a Fibonacci em vetor.
        cout << ">>> The Fibonacci series up to " << L << "is: \n";
        cout << "size: " << sz << endl;
        printArray( A, sz ); // Imprimir vetor na saida padrao.
    }
    else cout << ">>> Sorry, only positive integers accepted. Aborting...\n";
}
