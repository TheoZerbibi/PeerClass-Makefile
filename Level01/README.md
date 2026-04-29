# Résumé rapide de Make 🛠️

**Make** est un outil d'automatisation utilisé principalement pour compiler des programmes. Pour bien comprendre son utilité, il faut d'abord comprendre ce qui se passe quand on transforme un code source en programme.

## ⚙️ C'est quoi la compilation ?

La compilation est le processus de traduction d'un code écrit par un humain (le `.c`) en un langage compréhensible par la machine. Pour une commande simple comme `gcc main.c -o main.out`, quatre étapes invisibles se déroulent :



1.  **Préprocesseur (`.c` -> `.i`)** : Nettoie le code (enlève les commentaires) et gère les directives commençant par `#` (inclut les headers avec `#include`, remplace les macros).
2.  **Compilateur (`.i` -> `.s`)** : Traduit le code C en **Assembleur**, un langage de bas niveau propre à l'architecture du processeur.
3.  **Assembleur (`.s` -> `.o`)** : Transforme l'assembleur en **code objet** (code machine binaire). C'est ici que naissent les fichiers `.o`.
4.  **Éditeur de liens / Linker (`.o` -> exécutable)** : Rassemble tous les fichiers objets et les bibliothèques pour créer le programme final (`.out` ou exécutable).

### Pourquoi les fichiers `.o` et `.s` ?
* **`.s` (Assembleur)** : Il sert d'étape intermédiaire pour que le code soit optimisé pour un processeur spécifique.
* **`.o` (Objet)** : C'est la pièce de puzzle finale. **C'est ici que `make` prend tout son sens.** Si vous avez 100 fichiers, mais que vous n'en modifiez qu'un seul, `make` ne recréera que le `.o` de ce fichier et relancera l'édition de liens, au lieu de tout recompiler depuis le début.

---

## Fonctionnement de Make

Il lit un fichier nommé `Makefile` qui contient des instructions définissant :

- Les **règles** pour construire un programme (compilation, linkage…).
- Les **dépendances** entre les fichiers sources (`.c`, `.h`) et les fichiers générés (`.o`, exécutables).
- Les **recettes** (commandes) pour construire les fichiers cibles.

Ce qui nous donne:
```make
target: dependencies
	recipe (shell commands)

rule:
    recipe  (shell commands)
```

Make détermine intelligemment quelles commandes doivent être exécutées, en fonction des fichiers modifiés (en comparant les dates de modification des `.c` et des `.o`).

**Exemple simplifié :**

```make
CC          := gcc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -I./

peerclass1: main.o test.o
	$(CC) -o peerclass1 main.o test.o $(CFLAGS)

main.o: main.c
	$(CC) $(CPPFLAGS) -c main.c -o main.o $(CFLAGS)

test.o: test.c
	$(CC) $(CPPFLAGS) -c test.c -o test.o $(CFLAGS)

fclean:
	rm -f *.o peerclass1
```

## Assignements de variables
- `=` : Assignation simple. La valeur est évaluée au moment de l'utilisation.
- `:=` : Assignation immédiate. La valeur est évaluée au moment de l'assignation.
- `?=` : Assignation conditionnelle. Assigne une valeur uniquement si la variable n'est pas déjà définie.
- `+=` : Ajoute une valeur à la variable existante.

Exemple :
```make
BASE = Hello
SIMPLE := $(BASE) World!
LAZY = $(BASE) World!
# echo $(SIMPLE)  # Affiche "Hello World!"
# echo $(LAZY)    # Affiche "Hello World!"
BASE = Bonjour
# echo $(SIMPLE)  # Affiche toujours "Hello World!"
# echo $(LAZY)    # Affiche "Bonjour World!"
SIMPLE += "!!!"
# echo $(SIMPLE)  # Affiche "Hello World!!!!"
CONDI ?= Hola
# echo $(CONDI)   # Affiche "Hola"
CONDI ?= Salut
# echo $(CONDI)   # Affiche toujours "Hola", car déjà défini.
```

## À quoi ça sert ?

- Automatiser la **compilation** de projets complexes.
- Accélérer les cycles de développement (**recompile uniquement ce qui a changé** grâce aux fichiers `.o`).
- Gérer proprement les **dépendances** et tâches répétitives.


### Conclusion :
`make` est un standard pour simplifier et automatiser la gestion des compilations en développement logiciel.

### Ressources
- [Implicit Variables](https://www.gnu.org/software/make/manual/make.html#Implicit-Variables)
- [Phony Targets](https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html)
- [Special Targets](https://www.gnu.org/software/make/manual/html_node/Special-Targets.html)
- [Variable Assignment](https://www.gnu.org/software/make/manual/make.html#Flavors)
