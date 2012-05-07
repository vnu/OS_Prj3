/********************************************************************************************************************************************
 *
 * NAME 				: 	VINU CHARANYA ATHANGUDI PURUSHOTHAMAN
 * PERSON # 		:	37648013
 * PROGRAM 1		:	bclient.c
 * HEADER FILE	:	osheaders.h
 *
 * DESCRIPTION	: This will send a string to the server, display the results
 * 							  The client will pass the string given to the server and then display the data that is returned from the server
 *  					      The client will exit after running once
 *
 *
 * EXECUTION		:	/bclient <IP> <PORT> <String>
 *
 * <IP> is the # of threads to run the producer function on.
 * <PORT> is the # of threads to run the consumer function on.
 * <String> is the string to be reversed by the server
 *
 *
 * DATE				:	5 Apr 2011
 *
 *********************************************************************************************************************************************/
#include "osheaders.h"


#define SIZE 1024
char buf[SIZE];

#define DPORT 9005

/*****************************************************************************************************************
 *
 * Function 	: 	Main
 *
  Parameters	:	<IP> <PORT> <String>
 *
 * <PORT> is the bserver port to connect to
 * <IP> is the bserver ip to connect to
 *  <String> is the string to be reversed by the server
 *
 * DESCRIPTION	: This will send a string to the server, display the results
 * 							  The client will pass the string given to the server and then display the data that is returned from the server
 *  					      The client will exit after running once
 *
 *
 *
 ******************************************************************************************************************/

int main(int argc,
         char *argv[])
{
  int sockfd;
  int nread;
  struct sockaddr_in serv_addr;
  struct hostent *host;
  uint16_t serv_port=DPORT;
  char *ip;

  if (argc != 4)
  {
    fprintf(stderr,"\nUsage: /.bclient <IP> <PORT> <STRING>\n\n");
    exit(1);
  }
  ip=argv[1];
  serv_port=atoi(argv[2]);

  /* create endpoint */
  if ((sockfd = socket(AF_INET,SOCK_STREAM, 0))< 0) {
    perror(NULL);
    exit(2);
  }

  /* connect to server */
  serv_addr.sin_family = AF_INET;
  host = gethostbyname(argv[1]);
  memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);
  serv_addr.sin_port =
            htons(serv_port);
  printf("\nSending Connection request to Bserver...\n");
  if (connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr))< 0) {
    perror(NULL);
    exit(3);
  }
  printf("\nSuccessfully Connected to Bserver..\n");

  /* transfer data */
  char *str;
  str=argv[3];
  printf("Request : %s\n\n",str);
  nread=write(sockfd,str,strlen(str)); //Send the string
  nread = read(sockfd, buf,SIZE); //Retrieves the string
  write(1, buf, nread);// Prints the output
  printf("\n\n");
  close(sockfd);
  exit(0);
}
