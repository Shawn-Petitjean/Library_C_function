# Libft — Bibliothèque de fonctions utilitaires en C

`libft` est une bibliothèque statique en langage C (`libft.a`) qui réimplémente un ensemble de fonctions de la bibliothèque standard C ainsi que plusieurs fonctions utilitaires supplémentaires pour la manipulation de chaînes de caractères, la gestion de la mémoire, les entrées/sorties sur descripteurs de fichiers et les listes chaînées.

---

## Prérequis

- Un compilateur C (`cc`, `gcc` ou `clang`)
- `make`
- `ar` (pour la création de l'archive statique)

---

## Compilation

Utilisez le `Makefile` fourni à la racine du projet :

```bash
# Compiler la bibliothèque (génère libft.a)
make

# Supprimer les fichiers objets (.o)
make clean

# Supprimer les fichiers objets et libft.a
make fclean

# Recompiler entièrement le projet
make re
```

La compilation utilise les flags `-Wall -Wextra -Werror`.

---

## Utilisation

Pour utiliser la bibliothèque dans un projet C :

1. Incluez l'en-tête `libft.h` dans vos fichiers sources :
   ```c
   #include "libft.h"
   ```
2. Compilez votre programme en liant `libft.a` :
   ```bash
   cc -Wall -Wextra -Werror votre_programme.c libft.a -o votre_programme
   ```

### Exemple

```c
#include "libft.h"

int main(void)
{
    char *msg = ft_strjoin("Bonjour, ", "monde !");
    if (msg)
    {
        ft_putendl_fd(msg, 1);
        free(msg);
    }
    return (0);
}
```

---

## Fonctions disponibles

### Vérification et conversion de caractères

| Fonction | Description |
| --- | --- |
| `ft_isalpha` | Vérifie si le caractère est alphabétique. |
| `ft_isdigit` | Vérifie si le caractère est un chiffre décimal (`0`–`9`). |
| `ft_isalnum` | Vérifie si le caractère est alphanumérique. |
| `ft_isascii` | Vérifie si le caractère appartient à la table ASCII (`0`–`127`). |
| `ft_isprint` | Vérifie si le caractère est affichable. |
| `ft_toupper` | Convertit une lettre minuscule en majuscule. |
| `ft_tolower` | Convertit une lettre majuscule en minuscule. |

### Manipulation de la mémoire

| Fonction | Description |
| --- | --- |
| `ft_memset` | Remplit une zone mémoire avec un octet donné. |
| `ft_bzero` | Met à zéro les `n` premiers octets d'une zone mémoire. |
| `ft_memcpy` | Copie `n` octets d'une zone mémoire vers une autre (sans chevauchement). |
| `ft_memmove` | Copie `n` octets d'une zone mémoire vers une autre en gérant les chevauchements. |
| `ft_memchr` | Recherche la première occurrence d'un octet dans une zone mémoire. |
| `ft_memcmp` | Compare deux zones mémoire octet par octet. |
| `ft_calloc` | Alloue de la mémoire pour un tableau et l'initialise à zéro. |

### Manipulation de chaînes de caractères

| Fonction | Description |
| --- | --- |
| `ft_strlen` | Calcule la longueur d'une chaîne de caractères. |
| `ft_strlcpy` | Copie une chaîne en limitant la taille du tampon de destination. |
| `ft_strlcat` | Concatène deux chaînes en limitant la taille totale du tampon. |
| `ft_strchr` | Recherche la première occurrence d'un caractère dans une chaîne. |
| `ft_strrchr` | Recherche la dernière occurrence d'un caractère dans une chaîne. |
| `ft_strncmp` | Compare au plus `n` caractères de deux chaînes. |
| `ft_strnstr` | Recherche une sous-chaîne dans une chaîne sur au plus `len` caractères. |
| `ft_strdup` | Duplique une chaîne de caractères dans une nouvelle zone allouée. |
| `ft_substr` | Extrait une sous-chaîne à partir d'un index et d'une longueur donnés. |
| `ft_strjoin` | Alloue et retourne la concaténation de deux chaînes. |
| `ft_strtrim` | Supprime les caractères spécifiés au début et à la fin d'une chaîne. |
| `ft_split` | Découpe une chaîne en un tableau de chaînes selon un délimiteur. |
| `ft_strmapi` | Applique une fonction à chaque caractère et retourne une nouvelle chaîne. |
| `ft_striteri` | Applique une fonction à chaque caractère d'une chaîne en place. |

### Conversions

| Fonction | Description |
| --- | --- |
| `ft_atoi` | Convertit une chaîne de caractères en entier (`int`). |
| `ft_itoa` | Convertit un entier (`int`) en chaîne de caractères allouée dynamiquement. |

### Entrées / Sorties (descripteurs de fichiers)

| Fonction | Description |
| --- | --- |
| `ft_putchar_fd` | Écrit un caractère sur le descripteur de fichier spécifié. |
| `ft_putstr_fd` | Écrit une chaîne de caractères sur le descripteur de fichier spécifié. |
| `ft_putendl_fd` | Écrit une chaîne suivie d'un retour à la ligne sur le descripteur de fichier spécifié. |
| `ft_putnbr_fd` | Écrit un entier sur le descripteur de fichier spécifié. |

### Listes chaînées (`t_list`)

La structure `t_list` est définie dans `libft.h` :

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Fonction | Description |
| --- | --- |
| `ft_lstnew` | Alloue et initialise un nouvel élément de liste chaînée. |
| `ft_lstadd_front` | Ajoute un élément au début d'une liste chaînée. |

---

## Tests

Un fichier `main.c` est inclus dans le dépôt pour tester les différentes fonctions de la bibliothèque.
