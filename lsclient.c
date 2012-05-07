/********************************************************************************************************************************************
 *
 * NAME 				: 	VINU CHARANYA ATHANGUDI PURUSHOTHAMAN
 * PERSON # 		:	37648013
 * PROGRAM 2		:	lsclient.c
 * HEADER FILE	:	osheaders.h
 *
 * DESCRIPTION	: This will send a string to the server, display the results
 * 							  The client will pass the string given to the server and then display the data that is returned from the server
 *  					      The client will exit after running once
 *
 *
 * EXECUTION		:	/lsclient <IP> <PORT> <PARAM>
 *
 * <IP> is the IP to connect to
 * <PORT> is the Port to connect to
 * <PARAM> is the list of parameters to be sent to the server
 *
 *
 * DATE				:	5 Apr 2011
 *
 *********************************************************************************************************************************************/
#include "osheaders.h"


#define SIZE 1024
#define BIG 10000
char buf[SIZE];

#define PORT 9005

/*****************************************************************************************************************
 *
 * Function 	: 	Main
 *
  Parameters	:	<IP> <PORT> <PARAM>
 *
 * <PORT> is the bserver port to connect to
 * <IP> is the bserver ip to connect to
 *  <PARAM> is the string to be reversed by the server
 *
 * DESCRIPTION	: This will send a string of ls parameters to the server, display the results
 * 							  The client will pass the parameters from command prompt to the server and then display the data that is returned from the server
 *  					      The client will exit after running once
 *
 *
 *
 ******************************************************************************************************************/
int main(int argc,
         char *argv[])
{
	int i;
  int sockfd;
  int nread;
  struct sockaddr_in serv_addr;
  struct hostent *host;
  uint16_t serv_port =PORT;
  char *ip;

  if (argc < 3)
  {
    fprintf(stderr,"\nUsage: /.lsclient <IP> <PORT> <PARAM 1> <PARAM 2> ..<PARAM N>\n\n");
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
  printf("\nSending Connection request to LSserver...\n");
  if (connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr))< 0) {
    perror(NULL);
    exit(3);
  }
  printf("\nSuccessfully Connected to LSserver..\n");

  /* transfer data */
  char *str,*cmd,*sp;
  cmd = (char *)malloc(sizeof(char)*100);
  str =(char *)malloc(sizeof(char)*100);
  sp=(char *)malloc(sizeof(char)*5);
  memset(cmd,'\0',100);
  memset(str,'\0',100);
  memset(sp,'\0',5);
  strcpy(sp," ");

  // Function that concatenates the input and sends it to the server and displays the output

  strcat(cmd,"ls ");
  for(i=3;i<argc;i++)
  {
	  str=argv[i];
	  strcat(cmd,sp);
	  strcat(cmd,str);
  }
  //write(1,cmd,10);


 nread=write(sockfd,cmd,strlen(cmd));

		  while(nread>0)
		  {
			  strcpy(buf,"\0");
			  nread= read(sockfd, buf,BIG);
			  write(1, buf, strlen(buf));
		  }
printf("\n\n");
  close(sockfd);
  free(sp);
  exit(0);
}
