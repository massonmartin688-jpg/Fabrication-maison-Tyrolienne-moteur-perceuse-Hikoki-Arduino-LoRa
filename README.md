# Voici comment j'ai réussi à prendre le contrôle électronique d'une perceuse HiKOKI pour la piloter à distance via le protocole LoRa.


L'objectif était de remplacer l'interaction physique avec la gâchette par une commande numérique sans fil, tout en conservant l'intelligence du variateur de vitesse d'origine de la machine. Plutôt que de modifier la puissance, j'ai choisi de "tromper" le cerveau de la perceuse.

Ce que j'ai mis en place :
1. Le décodage de la gâchette (Reverse Engineering)
En démontant la perceuse, j'ai identifié que la gâchette n'est rien d'autre qu'un potentiomètre linéaire. Elle envoie une valeur de résistance variable au contrôleur interne.
![Mon module LoRa](image/potentiomètre%20linéaire%20hikoki.png)

J'ai mesuré les valeurs de résistance aux bornes de la gâchette d'origine.

J'ai ensuite déconnecté cette gâchette pour la remplacer par mon propre circuit.

2. La substitution par un Potentiomètre Numérique
Pour simuler l'appui du doigt de manière électronique, j'utilise un Digital Potentiometer numérique .
![Mon module LoRa](image/potentiometre%20numérique.jpg)

Ce composant reçoit des ordres de mon microcontrôleur.

Il fait varier sa résistance interne exactement comme le ferait la gâchette mécanique.

Cela permet un contrôle ultra-précis de la vitesse (de 0 à 100%) sans risque de griller le moteur, car on utilise le circuit de commande prévu par HiKOKI.

3. Le pilotage Longue Portée (LoRa)
Pour commander le tout, j'ai choisi la technologie LoRa :

Portée : Je peux piloter la machine à travers plusieurs murs ou à très grande distance, là où le Bluetooth s'arrêterait.

Sécurité : Mon code surveille la connexion. Si je perds le signal radio, le potentiomètre numérique revient instantanément à zéro pour arrêter la perceuse par sécurité.


![Mon module LoRa](image/perceuse%20et%20arduino%202%20.png)
