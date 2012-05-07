#ifndef OSHEADERS_H_
#define OSHEADERS_H_

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
//#include <sstream.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/time.h>

#define DEF_PORT 16688
#define DEF_IP "127.0.0.1"
#define MAXLEN 4096
#define DEF_STR "I_AM_DEFAULT"
#define SA struct sockaddr

#endif /*OSHEADERS_H_*/
