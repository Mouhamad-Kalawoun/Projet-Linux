
//   C'est la partie du serveur

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main()
{ int st;
  int portserveur;
  socklen_t lgclient;
  int ns,soc;	
  int pid;
  struct sockaddr_in serveur,client;
  char * mes;
  mes = (char *)malloc(256);

  printf("\nProgramme Serveur TCP, ce code est prepare par Mouhamad Nour Aldine Kalawoun\n");
  printf("L'adresse du serveur est: 127.0.0.1 \nVeuillez entrer le numero de port du serveur (doit etre >= 1024): ");
  scanf("%d",&portserveur);
  printf("\nAppel fonction socket\n");
  soc = socket (AF_INET,SOCK_STREAM,IPPROTO_TCP); // creation du socket
  if (soc==-1) {
    printf("Retour socket invalide\n");
    return (-1);
  }
  // indication au systeme de l'adrersse et numero de port du serveur
  serveur.sin_family = AF_INET;
  serveur.sin_port = htons(portserveur);// host to network short
  serveur.sin_addr.s_addr = inet_addr("127.0.0.1");
  st = bind(soc,(const struct sockaddr *)&serveur,sizeof(serveur));
  if (st!=0) {
     printf("Retour bind invalide, st=%d\n\n",st);
     exit(-1);
   }
  printf("Attente des demandes de connexion sur le port %d\n\n",portserveur);   
  st = listen(soc,10);
  if (st!=0) {
     printf("Retour listen invalide");
     return (-1);
   }
  

for(;;){
  lgclient = sizeof(client);
  ns  = accept(soc,(struct sockaddr *)&client,&lgclient);
  pid=fork();

if(pid==0){
	
  printf("Retour accept : %d\n",ns);

  if (ns==-1) {
     printf("Retour accept invalide \n");
     return -1;
   }

  printf("Connexion acceptee, client %s\n",inet_ntoa(client.sin_addr));
  // la connexion est etablie

  mes = "Bienvenu au serveur de CNAM, ce code est prepare par Mouhamad Nour Aldine Kalawoun";

  st = send(ns,mes,strlen(mes),0);

  if (st==-1) {
     printf("Erreur lors de l'emission du message d'accueuil ");
     return -1;
   }
   char rep[128];
   do {
      printf("Attente message du client\n");
      st = recv(ns,&rep[0],256,0);
      if (st > 0) {
        rep[st] = 0;
        printf("Nombre de caracteres recus %d \n",st);
        printf("Message a recu: %s \n",rep);
        st = send(ns,rep,strlen(rep),0);   // emission du message au client
      }

      else {
	printf("Retour recv \n");
        st = sleep(3);
	
      }

  } while (strcmp("fin",rep)!=0);
	
  close(ns);

		} // fin fils
	} // fin for(;;)

  close(soc);

} // fin main
