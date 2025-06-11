# Como usar

o código foi realizado no sistema operacional Debian

Primeiro é necessario preparar o terminal para compilar em C++

O g++ é o compillador C++.

    sudo apt update
    sudo apt install g++

Para verificar a versão do g++

    g++ --version

Pronto!! o ambiente esta preparado.
Agora vamos usar o editor de texto no terminal usando o nano.

    nano portscanner.cpp

Agora insira o código. Depois de salvar vamos compilar em C++ e gerar um executável

    g++ portscanner.cpp -o portscanner

e rodar o programa como:

    ./portscanner
    

