/********************************************************************************************************************************************
 *
 * NAME 				: 	VINU CHARANYA ATHANGUDI PURUSHOTHAMAN
 * PERSON # 		:	37648013
 * PROGRAM 3		:	drandom.c
 * HEADER FILE	:	osheaders.h
 *
 * DESCRIPTION	:   This will generate random ascii data of 128 bytes to be sent as request to dserver.
 * 								The N Value has the number of iterations the program should run before exiting
 * 								The seed value is inputted to generate random number
 *
 *
 * EXECUTION		:	/drandom <IP> <PORT> <N> <SEED>
 *
 * <IP> is the IP Address to connect to
 * <PORT> is the Port number to connect to
 * <N> Number of iterations to be done
 * <SEED> This is the seed given to random client. Use bigger value
 *
 *
 * DATE				:	15 Apr 2011
 *
 *********************************************************************************************************************************************/
#include "osheaders.h"


#define SIZE 1024
#define BS 128
char buf[SIZE];

#define TIME_PORT 9005

int main(int argc,
         char *argv[])
{
  int sockfd;
  int nread;
  struct sockaddr_in serv_addr;
  struct hostent *host;
  uint16_t serv_port;
  char *ip;


  if (argc != 5)
  {
    fprintf(stderr,"\nUsage: /.drandom <IP> <PORT> <N> <SEED>\n\n");
    exit(1);
  }
  ip=argv[1];
  serv_port=atoi(argv[2]);

  /* create endpoint */
  if ((sockfd = socket(AF_INET,SOCK_STREAM, 0))< 0) {
    perror(NULL);
    exit(2);
  }

  char *cmd,*tmp,*tp,ch,*result,chr;
  int i,j,tt,p_number,N,seed,trk,sec;
  char read_or_write[]={'r','w'};

   p_number= atoi(argv[2]);
   N=atoi(argv[3]);
   seed=atoi(argv[4]);

  /* connect to server */
  serv_addr.sin_family = AF_INET;
  host = gethostbyname(argv[1]);
  memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);
  serv_addr.sin_port =
            htons(serv_port);
  if (connect(sockfd,(struct sockaddr *) &serv_addr, sizeof(serv_addr))< 0) {
    perror(NULL);
    exit(3);
  }

  /* transfer data */


  	 /*
  	  * Generating the command from the random client and sending it to the server for executing and prints request and response as w or r
  	  */

    srand(seed);
    cmd = (char *)malloc(200*sizeof(char));
    write(sockfd,"i",1);
    result = (char *)malloc(200*sizeof(char));
    	//strcpy(result,"\0");
    	nread = read(sockfd,result,150);
    	result[nread]='\0';

  sscanf(result,"%d %d",&trk,&sec);

  	 while(N>0)
  	 {

  		 switch(rand()%2)
  		 {
  		 case 0:	//This case is executed if the generated command is Write
  			 	 	 	 sprintf(cmd,"%c %d %d",'w',rand()%trk+1,rand()%sec+1);
  			 	 	 	 tp =(char *)malloc(BS*sizeof(char));
  			 		 	 for(i=0;i<BS;i++) //random character generated to write to the file. The generated value will be 128
  			 		 	 {
  			 		 		tt = rand()%57;
  			 		 		tt= tt+65;
  			 		 		ch= (char)tt;
  			 		 		tp[i]=ch;
  			 		 	 }
  			 		 	 	 tp[i]='\0';
  			 		 		tmp =(char *)malloc((BS+3)*sizeof(char));
  			 		 		sprintf(tmp," %ld %s",strlen(tp),tp);
  			 		 		strcat(cmd,tmp);
  			 		 		free(tp);
  			 		 		free(tmp);
  			 		 		printf("Request:%s\n","W");

  			 		 		 write(sockfd,cmd,strlen(cmd));
  			 		 		strcpy(cmd,"\0");
  			 		 		break;
  		 case 1: 		sprintf(cmd,"%c %d %d",'r',rand()%trk+1,rand()%sec+1); //This case is executed if the generated command is read
  		 	 	 	 	 	 printf("Request:%s\n","R");
  		 	 	 	 	 	 write(sockfd,cmd,strlen(cmd));
  		 	 	 	 	 	 strcpy(cmd,"\0");
  			 	 	 break;
  		 default:
  			 	 	 printf("Default\n");

  		 }
  /*		 if(chr=='w')

  		 		 {
  			 	 	 tp =(char *)malloc(BS*sizeof(char));
  		 			 for(i=0;i<=rand()%BS;i++)
  		 			 {
  		 				tt = rand()%26;
  		 				tt= tt+65;
  		 				ch= (char)tt;
  		 				 tp[i]=ch;
  		 			 }
  		 			 tp[i]='\0';

  		 			tmp =(char *)malloc((BS+3)*sizeof(char));

  		 			 sprintf(tmp," %d %s",strlen(tp),tp);
  		 			 strcat(cmd,tmp);

  		 			 free(tp);
  		 			 free(tmp);

  		 		 }


  		 printf("command:%s\n",cmd);
  	 write(sockfd,cmd,strlen(cmd));
  */
  	result = (char *)malloc(200*sizeof(char));
  	nread = read(sockfd,result,150);
  	result[nread]='\0';
  	printf("Response:%s\n",result);
  	free(result);
  	N--;
  	 }
    close(sockfd);
    exit(0);
  }
