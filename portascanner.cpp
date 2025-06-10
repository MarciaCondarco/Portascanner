#include <iostream> // Biblioteca para entrada e saída padrão (exemplo: cout,cin)
#include <cstring>  // Biblioteca para manipulação de string em C
#include <sys/socket.h> //Biblioteca para criação e uso de sockets
#include <netinet/in.h> //Biblioteca com definições para endereços de internet (IPV4)
#include <arpa/inet.h>  //Biblioteca para conversão de endereços (exemplo: inet_pton)
#include <unistd.h> //Biblioteca para funções POSIX (exemplo: close) 

using namespace std;

int main(){
    int startPort = 1;
    int endPort = 1024;
    string ip = "";

    cout<<"Digite o alvo: ";
    cin>>ip;

    cout<< "Escaneando IP " << ip << "de porta" << startPort << "ate " << endPort << "...\n";

    //loop que percorre as portas estabelecidas nas variaveis startPort e endPort
    for(int port=startPort; port<=endPort; ++port){
        int sockfd = socket(AF_INET, SOCK_STREAM, 0); //criando um socket do tipo TCP(SOCK_STREAM)

        if(sockfd<0)//verificação do socket se foi criado com sucesso
        {
            cerr << "Erro ao criar socket.\n"; //mensagem de erro
            continue; //pula para proxima porta
        }
        sockaddr_in addr; 
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);

        int result = connect(sockfd, (sockaddr*)&addr, sizeof(addr));

        if(result==0){
            cout<<"porta: "<<port<<" [ABERTA]\n";
        }
        close(sockfd);
    }
        cout<< "scan finalizado,\n";
        return 0;
}