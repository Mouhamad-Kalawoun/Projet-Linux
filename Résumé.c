Bonjour,



Dans ce document je vais parler de ce que j'ai fait � la fois chez le client et le serveur d'une fa�on g�n�rale sans entrer dans les d�tails.



Une fois tu d�marres le serveur, il va vous donner son adresse IP, puis il va demander le numero du port, doit �tre plus grand ou �gal � 1024.



Ensuite on va d�marrer les clients, tu dois entrer l'adresse IP du serveur puis le numero du port, si les informations entr�es sont fausses, un 

message va demontrer les erreurs.



Plusieurs clients peuvent communiquer avec le serveur en m�me temps.



Le serveur renvoie au client le message qui � d�j� re�u sans le changer.


Pour fermer l'�change entre le client et le serveur, il est suffisant d'envoyer un mesage "fin" du client au serveur.


J'ai ajout� des commentaires pour rendre le code plus simple.


Merci de votre attention.



Mouhamad Nour aldin kalawoun




