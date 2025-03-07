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

## À quoi ça sert ?

- Automatiser la **compilation** de projets complexes.
- Accélérer les cycles de développement (**recompile uniquement ce qui a changé**).
- Gérer proprement les **dépendances** et tâches répétitives.

### Conclusion :
`make` est un standard pour simplifier et automatiser la gestion des compilations en développement logiciel.

### Ressources
- [Automatic Variables](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)
- [Prerequisite Types](https://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html)
- [Implicit Rules](https://www.gnu.org/software/make/manual/html_node/Implicit-Rules.html)
- [Automatic Prerequisites](https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html)
