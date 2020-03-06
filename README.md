# Fib-bugado
Concertar código da série de fibonacci bugado utilizando o gdb

usado para compilar: g++ -std=c++11 fib_series_bugged.cpp -o fib
usando o gdb: g++ -std=c++11 -g fib_series_bugged.cpp  -o fib

1° execução = Ao digitar o limite para a série Fibonnaci, independente da entrada, a saida são infinitos '0'.

====== 1ª ALTERAÇÃO=====

Nas linhas 43 e 44 os valores das variaveis eram 0, por isso ocorria um looping de 0 na saida do programa. Então, foi atribuido o valor 1 para a variável 'fib0'.

========================================================================

2° execução = a saída não obedece o limite da serie.

Por exemplo, ao colocar como limite o numero 12, como saída é impresso " 1 2 3 5 8 13", quando na verdade a sequencia deveria ir até o número 8, uma vez que  ele é o ultimo numero da sequencia menor ou igual ao 12;


Além disso, no gdb é apresentado o seguinte comentário: 'Program received signal SIGSEGV, Segmentation fault.
0x0000555555554a3f in printArray (_A=0x0, _sz=5) at fib_series_bugged.cpp:24
24	        cout << _A[ i ] << " "; 

Muito provavelmente, os valores do vetor _A não está sendo passados adequadamente.

======= 2ª ALTERAÇÃO =======

Na linha 42 faltando o &, pois os valores do vetor A dentro da função, não estavam refletindo nos valores de A[] fora da função. Por isso o erro de segmentation fault anteriormente.

Foi alterada a variavel count para que ela retornasse corretamente a serie até o seu menor numero antes ou igual ao limite.

=======================================================================

3º execução = 

