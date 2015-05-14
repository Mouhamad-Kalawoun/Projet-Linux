Bonjour,



Dans ce document je vais parler de ce que j'ai fait à la fois chez le client et le serveur d'une façon générale sans entrer dans les détails.



Une fois tu démarres le serveur, il va vous donner son adresse IP, puis il va demander le numero du port, doit être plus grand ou égal à 1024.



Ensuite on va démarrer les clients, tu dois entrer l'adresse IP du serveur puis le numero du port, si les informations entrées sont fausses, un 

message va demontrer les erreurs.



Plusieurs clients peuvent communiquer avec le serveur en même temps.



Le serveur renvoie au client le message qui à déjà reçu sans le changer.


Pour fermer l'échange entre le client et le serveur, il est suffisant d'envoyer un mesage "fin" du client au serveur.


J'ai ajouté des commentaires pour rendre le code plus simple.


Merci de votre attention.



Mouhamad Nour aldin kalawoun




