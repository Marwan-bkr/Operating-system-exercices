Après une une petite réécriture du code, dont l'ajout de 2 includes nécessaire aux fonctions utilisées, la correction de déclaration j'ai compris que ce code permettait de :
    1. Créer un tableau vide, puis de le remplir avec deux file descriptors grâce à la fonction pipe(p). Un tube est créé.
    2. Le bord lecture du tube a été fermé.
    3. J'écris dans le bord écrire du tube.
    4. L'OS envoi un signal SIGPIPE car un bord du tube est fermé.
    5. Le processus capte le signal et utilise le handler parametré par sigaction.
    6. Le message "Signal SIGPIPE recu" apparaît ainsi que l'erreur "Write: Broken pipe".