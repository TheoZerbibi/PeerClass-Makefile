# Résumé rapide de Make 🛠️

**Make** est un outil d'automatisation utilisé principalement pour compiler des programmes.

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

Make détermine intelligemment quelles commandes doivent être exécutées, en fonction des fichiers modifiés.

**Exemple simplifié :**

```make
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS 	:= -I./

peerclass1: main.o test.o
	$(CC) -o peerclass1 main.o test.o $(CFLAGS)

main.o: main.c
	$(CC) $(CPPFLAGS) -c main.c $(CFLAGS)

util.o: test.c
	$(CC) $(CPPFLAGS) -c test.c $(CFLAGS)

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
# echo $(SIMPLE)  # Affiche "Hello World!!!"
CONDI ?= Hola
# echo $(CONDI)   # Affiche "Hola"
CONDI ?= Salut
# echo $(CONDI)   # Affiche toujours "Hola", car déjà défini.
```

## À quoi ça sert ?

- Automatiser la **compilation** de projets complexes.
- Accélérer les cycles de développement (**recompile uniquement ce qui a changé**).
- Gérer proprement les **dépendances** et tâches répétitives.


### Conclusion :
`make` est un standard pour simplifier et automatiser la gestion des compilations en développement logiciel.

### Ressources
- [Implicit Variables](https://www.gnu.org/software/make/manual/make.html#Implicit-Variables)
- [Phony Targets](https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html)
- [Special Targets](https://www.gnu.org/software/make/manual/html_node/Special-Targets.html)
- [Variable Assignment](https://www.gnu.org/software/make/manual/make.html#Flavors)
