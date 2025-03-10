# Résumé rapide de Make 🛠️

Passons au level 2.
Ce Makefile va utilisé plus d'automatisation et de features lié a Make.

**Makefile :**

```make
CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -MMD -MP
CPPFLAGS    := -I./include
LDFLAGS     :=  
LDLIBS      :=  

NAME        := peerclass2

SRC_DIR     := ./src/
OBJ_DIR     := ./obj/
INC_DIR     := ./include/

SOURCES     := main.c test.c
SOURCES     := $(addprefix $(SRC_DIR),$(SOURCES))
OBJECTS     := $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEPS        := $(OBJECTS:.o=.d)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LDLIBS)

-include $(DEPS)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$^ | $< | $@"
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(DEPS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
```
---

## Structure du Makefile

### 1. **Variables Principales**

| Variable    | Description |
|-------------|-------------|
| `CC`        | Compilateur utilisé (`gcc`). |
| `CFLAGS`    | Options de compilation (`-Wall -Wextra -Werror -MMD -MP`). |
| `CPPFLAGS`  | Options pour inclure le répertoire `./include/`. |
| `LDFLAGS`   | Options du linker (vide par défaut). |
| `LDLIBS`    | Bibliothèques à lier (vide par défaut). |
| `NAME`      | Nom de l'exécutable généré (`peerclass2`). |
| `SRC_DIR`   | Répertoire contenant les fichiers sources (`./src/`). |
| `OBJ_DIR`   | Répertoire contenant les fichiers objets (`./obj/`). |
| `INC_DIR`   | Répertoire contenant les fichiers d'en-tête (`./include/`). |

### 2. **Gestion des fichiers sources et objets**

- `SOURCES` : Liste des fichiers sources (`main.c`, `test.c`), préfixés avec `$(SRC_DIR)`.
- `OBJECTS` : Liste des fichiers objets (`.o`), convertis depuis `SOURCES`.
- `DEPS` : Liste des fichiers de dépendances (`.d`) générés pour suivre les modifications des `.h`.

---

## Règles du Makefile

### 1. **Compilation principale (`all`)**
```make
all: $(NAME)
```
La cible `all` dépend de l'exécutable `$(NAME)`, qui est généré en compilant tous les fichiers objets.

### 2. **Compilation de l'exécutable**
```make
$(NAME): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LDLIBS)
	@echo "$@ has been created"
```
- Prend tous les fichiers objets (`$(OBJECTS)`).
- Génère l'exécutable (`peerclass2`).
- Utilise `$@` pour référencer le nom de la cible (`peerclass2`).

### 3. **Compilation des fichiers `.o`**
```make
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$^ | $< | $@"
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -MMD -MP -c $< -o $@
	@echo "$@ has been compiled\n"
```
- Compile chaque fichier `.c` en `.o` dans `$(OBJ_DIR)`.
- `mkdir -p $(dir $@)`: Assure que le répertoire `obj/` existe.
- `-MMD -MP` : Génère un fichier `.d` pour suivre les dépendances des fichiers `.h`.
- `@echo` affiche des messages pour un retour visuel sur la compilation.

### 4. **Inclusion des fichiers de dépendances**
```make
-include $(DEPS)
```
- Charge dynamiquement les fichiers `.d` générés lors de la compilation.
- Permet de recompiler uniquement les fichiers `.c` impactés par des modifications dans les `.h`.

---

## Flags
- `MMD -MP`:
  - MMD → Génère automatiquement les dépendances des fichiers .h (sauf les fichiers système).
  - MP → Empêche Make de planter si un .h est supprimé.

## Ressources
- [Automatic Variables](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html)
- [Implicit Rules](https://www.gnu.org/software/make/manual/html_node/Implicit-Rules.html)
- [Automatic Prerequisites](https://www.gnu.org/software/make/manual/html_node/Automatic-Prerequisites.html)
