#include <sys/socket.h>
#include <sys/types.h> 


/*

|-------------------------|
|                         |
|  THIS IS MADE FOR UNIX  |
|                         |
|-------------------------|
*/

int main(int argc, char argv[]){
    nt ss = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(80);

    server_sockaddr.sin_addr.s_addr = htonl(argv[1]);
    if(bind(ss, (struct sockaddr* ) &server_sockaddr, sizeof(server_sockaddr))==-1) {
        perror("bind");
        exit(1);
    }
    if(listen(ss, QUEUE) == -1) {
        perror("listen");
        exit(1);
    }

    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);

    conn = accept(ss, (struct sockaddr*)&client_addr, &length);
    if( conn < 0 ) {
        perror("connect");
        exit(1);
    }

    char buffer[1024];

    char reqStrs[] = "GET / HTTP/1.1 \r\n";
    while(1) {
    	for(auto reqStr : reqStrs){
        	send(conn, reqStr, sizeof(reqStr) , 0);
		Sleep(1000);
    	}
    }
    close(conn);
    close(ss);
    return 0;
}
