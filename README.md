*Ce projet a été créé dans le cadre du cursus 42 par lscheirm.*

## Description

Implémentation partielle de la fonction `printf` en C, avec apprentissage des variables variadiques (`va_list`, `va_arg`, `va_start`, `va_end`).

## Instructions

Compiler et installer le projet :

```bash
make        # compile la bibliothèque → libft.a
make clean  # supprime les fichiers objets (.o)
make fclean # supprime les fichiers objets + libft.a
make re     # recompile tout from scratch
```

Utiliser la bibliothèque dans un projet :

```bash
cc votre_fichier.c -L. -lftprintf -o votre_programme
```


## Choix techniques

J'ai utilisé des fonctions de ma libft en les personnalisants pour faire ce que le `printf` devait faire, et le `putnbr_base` pris dans un projet précédent aussi. J'ai modifié toutes ces fonctions en passant l'adresse d'une variable à toutes ces fonctions qui écrivaient ce qui était demandé, pour compter le nombre de caractères écrits et renvoyer le nombre de caractères écrits à la fin. Une simple boucle parcourt ma variable et dès qu'elle rencontre un pourcentage, elle regarde quelle lettre arrive après. Ensuite elle appelle la bonne fonction en envoyant l'adresse de la variable variadique, pour conserver l'endroit où nous sommes dans les arguments. Et puis elle appelle la fonction en envoyant la bonne donnée. Puis cela s'écrit. Sauf pour le `%%` qui écrit directement le pourcentage.

## Ressources

- [Explication des variables variadiques les 12 premières minutes](https://www.youtube.com/watch?v=o6l8lFd0uJY&t=1051s)
- [Claude AI](https://claude.ai/)

L'IA a été utilisée pour comprendre le fonctionnement de `printf` et ses différents paramètres, notamment le comportement attendu lors de l'envoi d'un pointeur `NULL` au format `%s`. Elle a également permis d'approfondir la compréhension des variables variadiques. De plus, l'IA a été utilisée aussi pour corriger le `README.md`, la grammaire et l'orthographe. Elle m'a permis aussi d'améliorer mon fichier de test pour vérifier si j'avais testé tous les cas possibles.
