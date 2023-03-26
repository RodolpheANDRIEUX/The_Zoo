# 🐯 The Zoo (🇬🇧)

![Zoo Entrance](https://cdn-icons-png.flaticon.com/512/2093/2093797.png)

Welcome to __*The Zoo*__! In this game, everything takes place in the terminal. Your goal is to develop and manage your own zoo by taking care of animals, managing habitats, and attracting visitors.

## 🚀 Getting Started

You start the game with the following animals:

- 🐯 A pair of *tigers*
- 🦅 A pair of __eagles__
- 🐓 A _rooster_
- 🐔 10 *hens*

Additionally, one month of food is provided to get you started. 🍖

## 📖 Main Menu

The main menu allows you to choose from the following actions:

1. 🕰️ **Pass time**: You can choose to pass a day, a month, a year (risky), or a chosen duration in days.
2. 💳 **Buy/Sell**: At any time, you can visit Amazon Zoo to buy food, animals, and habitats to accommodate them.
3. 👁️‍🗨️ **View the Zoo**: Regularly monitor the health and hunger of your animals by checking the contents of the habitats.

> 💡 *Tip: Don't try to put a recently purchased chicken in a tiger enclosure... (at your own risk)*

## 🎯 Objective

The goal of the game is to expand your zoo by taking advantage of breeding, buying new species, and earning money from visitors attracted to the zoo's animals. The more animals you have, the more money you'll earn, but beware of overpopulation in habitats ⚠️, diseases ☣️, fires 🔥, and more. You'll need to feed and protect your animals to prevent your zoo from going bankrupt. Good luck!

## 📊 Technical Details (spoiler)

[Here is a copy of the Excel instruction sheet](https://docs.google.com/spreadsheets/d/1MjxqtMzeRHTIvxKP_Xu-opLi2-lufaPF5iwtXDAlAe8/edit?usp=sharing) in which the parameters present in our code have been colored green.

>#### Testing the game
>A good way to optimally test the game is to start by visiting the Zoo (2), buying additional animals (1), and then passing one day (3). You should then have received all the annual grants for protected species. This will allow you to buy all the necessary food to be able to pass a year. The goal is then to repeat this operation in the hope of reaching the animals' sexual maturity. (To avoid having many notifications due to chickens, you can test animal sales (4) by selling all the hens!).

#### Technical Specificities

- Time is not a scenario over 10 years; the player can play themselves over 10 years and more if they wish.
- The player can buy any item (food, animals, habitat) with a single method.
- All inputs have error handling;
- It is nearly impossible to put an animal in the wrong type of habitat. Indeed, putting a chicken in a tiger habitat is possible, but it will be eaten. This will give the tiger the weight of the chicken in meat. If there are no tigers, the lucky chicken will escape the zoo. You will then receive a fine for endangering visitor safety.
- In the list of habitats, if an animal is hungry or sick, an icon (/!\\) will be displayed next to the concerned line
- Each probability calculation is performed every day thanks to a Utils::tirage() method that draws the event each day based on its monthly probability passed as an argument.

## Created by:

- [ANDRIEUX Rodolphe](https://github.com/RodolpheANDRIEUX)
- [LASSERRE Anaël]()

---
# 🐯 Le Zoo (🇫🇷)

![Zoo Entrance](https://cdn-icons-png.flaticon.com/512/2093/2093797.png)

Bienvenue dans __*Le Zoo*__! Dans ce jeu, tout se passe dans le terminal. Votre objectif est de développer et gérer votre propre zoo en prenant soin des animaux, en gérant les habitats et en attirant des visiteurs.

## 🚀 Démarrage

Vous commencez la partie avec les animaux suivants :

- 🐯 Un couple de *tigres*
- 🦅 Un couple d'__aigles__
- 🐓 Un _coq_
- 🐔 10 *poules*

De plus, un mois de nourriture vous est fourni pour bien démarrer. 🍖

## 📖 Menu principal

Le menu principal vous permet de choisir parmi les actions suivantes :

1. 🕰️ **Passer le temps** : Vous pouvez choisir de passer un jour, un mois, un an (risqué) ou une durée choisie en jour.
2. 💳 **Achat/Vente** : Vous pouvez à tout moment aller dans Amazon Zoo pour acheter de la nourriture, des animaux et des habitats pour les accueillir.
3. 👁️‍🗨️ **Voir le Zoo** : Vous pouvez régulièrement surveiller l'état de santé et de faim de vos animaux en consultant le contenu des habitats.

> 💡 *Astuce : Ne tentez pas de mettre un poulet récemment acheté dans un enclos pour tigre... (a vos risques et perils)*

## 🎯 Objectif

Le but du jeu est de développer votre zoo en profitant des reproductions, en achetant de nouvelles espèces et en gagnant de l'argent grâce aux visiteurs attirés par les animaux du zoo. Plus vous avez d'animaux, plus vous gagnerez d'argent, mais attention à la surpopulation dans les habitats ⚠️, aux maladies ☣️, aux incendies 🔥, etc. Vous devrez nourrir et protéger vos animaux pour que le zoo ne fasse pas faillite. Bonne chance !

## 📊 Details technique (spoil)

[Voici une copie de l'excel de la consigne](https://docs.google.com/spreadsheets/d/1MjxqtMzeRHTIvxKP_Xu-opLi2-lufaPF5iwtXDAlAe8/edit?usp=sharing) dans lequel a été colorié en vert les parametres presents dans notre code.

>#### Tester le jeu
>Une bonne manniere de tester obtimalement le jeu est de commencer par visiter le Zoo (2), acheter des animaux suplementaires (1), puis de passer un jour (3). Vous devriez avoir alors touché toutes les subventions annuelles pour especes protegées. Cela vous permettra d'acheter ensuite toute la nourriture necessaire pour pouvoir passer un an. Le but est alors de répéter cette operation pour esperer faire atteindre leur maturitée sexuelle aux animaux. (Pour eviter d'avoir beaucoup de notifications dues aux poules, vous pouvez tester la vente d'animaux (4) en vendant toutes les poules!).

#### Spécificités techniques

- Le temps n'est pas un scenario sur 10 ans, le joueur a la possibilité de jouer lui meme sur 10 ans et plus s'il le souhaite.
- Le joueur peut acheter n'importe quelle item (nourriture, animaux, habitat) avec une methode unique.
- Toutes les inputs ont une gestion d'erreur;
- Il est impossible (ou presque) des mettre un animal dans un habitat du mauvais type. En effet mettre un poulet dans un habitat de tigre est possible mais il se fera manger. Cela donnera le poids du poulet en viande au tigre. S'il n'y a pas de tigre le poulet chanceux s'échappera du zoo. Vous recevrez alors une amende pour atteinte à la securitée des visiteurs.
- Dans la liste des habitats, si un animal a faim ou est malade un icon (/!\\) s'affichera à coté de la ligne concernée
- Chaque calcul de probabilité s'effectue tout les jours grace à une methode Utils::tirage() qui tire chaque jour l'evenement en fonction de sa probabilité mensuelle passée en argument.

## Créé par :

- [ANDRIEUX Rodolphe](https://github.com/RodolpheANDRIEUX)
- [LASSERRE Anaël]()
