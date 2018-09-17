#include <sys/socket.h>

if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
{
    perror(“cannot create socket”); 
    return 0; 
}

struct sockaddr_in address;
const int PORT = 8080; //Where the clients can reach at
/* htonl converts a long integer (e.g. address) to a network representation */ 
/* htons converts a short integer (e.g. port) to a network representation */ 
memset((char *)&address, 0, sizeof(address)); 
address.sin_family = AF_INET; 
address.sin_addr.s_addr = htonl(INADDR_ANY); 
address.sin_port = htons(PORT); 
if (bind(server_fd,(struct sockaddr *)&address,sizeof(address)) < 0) 
{ 
    perror(“bind failed”); 
    return 0; 
}