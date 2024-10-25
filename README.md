# CDataframe 🖥️
[Lien vers le dépôt GitHub](https://github.com/EFREI-BDX/projet-langage-c-justine-garnung-yelena-sainte-rose.git) 

## Projet C: CDataframe
Un data frame est une structure bidimensionnelle. Cela signifie que les données sont alignées de façon tabulaire en colonnes et en lignes.

## Membres du projet
> Justine GARNUNG    [![linkedin](https://github.com/justinegrng/Projet-Transverse/assets/89320065/eba91f42-9ed4-4ef3-8502-ca4925d64d8f)](https://www.linkedin.com/in/justine-garnung-674571232/)  
> Yéléna SAINTE-ROSE BRUNY    [![linkedin](https://github.com/justinegrng/Projet-Transverse/assets/89320065/eba91f42-9ed4-4ef3-8502-ca4925d64d8f)](https://www.linkedin.com/in/yelesr/)  

## Files organization
> [!TIP]
> Il suffit de cliquer ci-dessous sur "📁 Projet CDataframe" afin de visualiser l'arborescence de notre projet.
<details>
<summary> 📁 Projet CDataframe </summary>
  
- `main.c`
- `menu.c`
- `menu.h`
- `column.c`
- `column.h`
- `cdataframe.c`
- `cdataframe.h`
</details>

## Explication générale

Etant donné que notre projet consiste à travailler et à manipuler des dataframes, similaires à ceux utilisés en analyse de données. 
Et sachant qu'un dataframe est une structure de données bidimensionnelle, où chaque colonne peut contenir des données de différents types (par exemple : entier, chaîne, flottant). 
Nous avons décidés en premier lieu d'utiliser un tableau de colonnes pour stocker les données et non une liste doublement chaînée de colonnes.

Dans ce projet, il y a une structure CDataframe qui contient un tableau dynamique de pointeurs vers des Column. 
Chaque Column contient un tableau dynamique de données que ce soit des entiers, des chaînes de caractères ou des flottants.
Mais aussi d'autres données comme le nom de la colonne et le type de données.

Ce code fournit également un ensemble de fonctions pour manipuler les dataframes et les colonnes. 
Ces fonctions permettent de créer et de supprimer des dataframes, des colonnes et des lignes, d'ajouter et de supprimer des données. 
De plus, elles permettent de renommer des colonnes, de rechercher des valeurs, d'accéder et de modifier des cellules, d'imprimer les noms des colonnes,
et de compter les lignes, les colonnes et les cellules qui répondent à certaines conditions.

Dans le cadre de ce projet, un menu a été mis en place pour permettre à l'utilisateur de tester les différentes fonctionnalités de la bibliothèque.

## Fonctions
✔ La fonction a été développée et elle fonctionne avec tout type de dataframe.  
❌La fonction a été développée mais elle ne fonctionne pas avec le dataframe.

### Fonctions menu.c
- `print_menu` → *Affiche le menu interactif* ✔
- `interactive_menu` → *Permet à l'utilisateur de choisir une option du menu interactif* ✔
- `menu_choice_1` → *Permet à l'utilisateur de choisir entre un dataframe vide, un dataframe avec des valeurs en dur ou de saisir les valeurs* ✔
### Fonctions column.c
- `create_column` → *Crée une colonne, initialise son nom, son type et sa taille* ✔
- `insert_value` → *Insère une valeur dans une colonne, en allouant de la mémoire supplémentaire si nécessaire* ✔
- `print_col` → *Affiche les valeurs d'une colonne* ✔
- `delete_column` → *Supprime une colonne et libère la mémoire associée* ✔
- `count_value` → *Compte le nombre de fois qu'une valeur est présente dans une colonne* ✔
- `get_value` → *Retourne la valeur à l'index donné dans une colonne* ✔
- `count_greater_than` → *Compte le nombre de valeurs supérieures à une valeur donnée dans une colonne* ✔
- `count_less_than` → *Compte le nombre de valeurs inférieures à une valeur donnée dans une colonne* ✔
- `update_value` → *Met à jour la valeur à l'index donné dans une colonne* ✔
### Fonctions cdataframe.c
- `create_cdataframe` → *Crée un dataframe, initialise ses colonnes et sa taille* ✔
- `add_column` → *Ajoute une colonne à un dataframe* ✔
- `delete_column_at_index` → *Supprime une colonne d'un dataframe à un index donné* ✔
- `rename_column` → *Renomme une colonne d'un dataframe à un index donné* ✔
- `find_value` → *Trouve une valeur dans un dataframe* ❌
- `get_cell_value` → *Retourne la valeur d'une cellule dans un dataframe* ❌
- `set_cell_value` → *Modifie la valeur d'une cellule dans un dataframe* ❌
- `print_column_names` → *Affiche les noms des colonnes d'un dataframe* ✔
- `count_rows` → *Compte le nombre de lignes dans un dataframe* ✔
- `count_columns` → *Compte le nombre de colonnes dans un dataframe* ✔
- `count_cells_equal` → *Compte le nombre de cellules égales à une valeur dans un dataframe* ✔
- `count_cells_greater` → *Compte le nombre de cellules supérieures à une valeur dans un dataframe* ❌
- `count_cells_less` → *Compte le nombre de cellules inférieures à une valeur dans un dataframe* ❌
- `print_dataframe` → *Affiche un dataframe* ✔
- `fill_dataframe_user` → *Crée un dataframe avec des valeurs de l'utilisateur* ✔
- `print_dataframe_limited_rows` → *Affiche un dataframe avec un nombre limité de lignes* ❌
- `print_dataframe_limited_columns` → *Affiche un dataframe avec un nombre limité de colonnes* ✔
- `add_row` → *Ajoute une ligne à un dataframe* ❌
- `delete_row` → *Supprime une ligne d'un dataframe* ❌
- `delete_row_print` → *Affiche un dataframe après avoir supprimé une ligne* ❌
- `delete_value_at_index` → *Supprime une valeur à un index donné dans une colonne* ❌
