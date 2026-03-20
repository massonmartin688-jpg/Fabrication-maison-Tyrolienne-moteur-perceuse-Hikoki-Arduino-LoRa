# Voici comment j'ai réussi à prendre le contrôle électronique d'une perceuse HiKOKI pour la piloter à distance via le protocole LoRa.
# J'ai détourné cette perceuse pour en faire le système de propulsion d'une tyrolienne électrique que j'ai conçue intégralement.


L'objectif était de remplacer l'interaction physique avec la gâchette par une commande numérique sans fil, tout en conservant l'intelligence du variateur de vitesse d'origine de la machine. Plutôt que de modifier la puissance, j'ai choisi de "tromper" le cerveau de la perceuse.

Ce que j'ai mis en place :
1. Le décodage de la gâchette (Reverse Engineering)
En démontant la perceuse, j'ai identifié que la gâchette n'est rien d'autre qu'un potentiomètre linéaire. Elle envoie une valeur de résistance variable au contrôleur interne.
![Mon module LoRa](image/potentiomètre%20linéaire%20hikoki.png)
![Mon module LoRa](image/gachette%20perceuse.JPEG)
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

![Mon module LoRa](image/module%20lora1.png)

Portée : Je peux piloter la machine à travers plusieurs murs ou à très grande distance, là où le Bluetooth s'arrêterait.

Sécurité : Mon code surveille la connexion. Si je perds le signal radio, le potentiomètre numérique revient instantanément à zéro pour arrêter la perceuse par sécurité.

Évolution du projet : La Tyrolienne Électrique
Définition de l'objectif Une fois le système de motorisation opérationnel, l'objectif a évolué vers la création d'une tyrolienne électrique autonome. Le défi consistait à concevoir un support mobile capable de supporter son propre poids tout en intégrant une propulsion mécanique efficace.

Modélisation 3D (Fusion 360) Pour garantir la précision de l'assemblage, j'ai modélisé l'intégralité de la structure sur Fusion 360. Cette étape a permis de simuler l'encombrement des composants et de prévoir les points de fixation nécessaires au mécanisme de traction.
![Mon module LoRa](image/modélisation%20du%20mécanisme.png)
![Mon module LoRa](image/modélisation%20du%20mécanisme%202.png)
Construction et défi technique Partant de zéro, j'ai assemblé la structure pour y incorporer une perceuse comme moteur. La difficulté majeure a été de concevoir un système de transmission capable de tracter une charge lourde sans que le câble ne glisse sur la poulie motrice, ce qui a nécessité une attention particulière sur l'adhérence et la tension du fil.

Voici une illustration de la partie mécanique que j'ai construite de A à Z : 
![Mon module LoRa](image/tyrolienne%20mécanisme.png)

Voici une photo prise pendant que le système était opérationnel : la tyrolienne était alors capable d'effectuer des marches avant et arrière, tout en faisant varier sa vitesse par l'intermédiaire de la perceuse.
![Mon module LoRa](image/projet%20final.png)


Voici une illustration des premiers tests de commande marche avant / marche arrière de la perceuse, réalisés grâce à des relais :
![Mon module LoRa](image/perceuse%20et%20arduino%202%20.png)
