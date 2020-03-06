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

No GDB, foi utilizado o comando 'p sz' para conferir o valor do tamanho da serie e resolver o bug. 

======= 2ª ALTERAÇÃO =======

Na linha 42 faltando o &, pois os valores do vetor A dentro da função, não estavam refletindo nos valores de A[] fora da função. Por isso o erro de segmentation fault anteriormente.

Foi alterada a variavel count para que ela retornasse corretamente a serie até o seu menor numero antes ou igual ao limite. 

Troca dos tipos de variáveis da serie para long long, pois quando se utilizava numeros grandes eles não eram mostrados pois o tipo anterior era int e não suportava.

Criação do vetor alocado dinamicamente.

=======================================================================

3º execução = no GDB, ao executar o programa, é possivel notar que os primeiros valores da série estão corretos, porém quando os numeros ficam muito grandes ocorre um problema e é mostrado o seguinte erro: 

Program received signal SIGSEGV, Segmentation fault.
0x0000555555554c2f in fib (_limit=2147483647, 
    _A=@0x7fffffffde60: 0x555555769690) at fib_series_bugged.cpp:54
warning: Source file is more recent than executable.
54	            _A[count] = fib2;

=========3ª ALTERACAO=========
Após muito pesquisar, encontrei que o tipo de variável unsigned long suportava os números gigantes da série de fibonacci até 10^19. Após fazer essa troca, a saída do programa foi exatamente como o arquivo de saída esperado.

====================================================

4ª Execução = código rodando perfeitamente.


