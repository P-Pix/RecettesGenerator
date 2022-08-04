import os
import sys
import tkinter as Tk

def readIngredient(fileName: str) -> list:
    # Ouvre le fichier
    file = open(fileName)
    liste = []
    # Pour chaque ligne du fichier
    for ingredient in file:
        liste.append(ingredient.replace("\n", "").lower())
    liste.sort()
    return liste

def initList() -> list:
    ingredients = []
    for i in os.listdir("ingredients/"):
        ingredients.extend(readIngredient("ingredients/" + i))
    ingredients.sort()
    print(ingredients)
    return ingredients

def canvaAddIngredient() -> Tk.Canvas:
    ingredients = initList()
    CANVAS = Tk.Canvas(width=800, height=600, bg='white')
    CANVAS.create_text(400, 300, text='Hello World!', font=('Arial', 30))
    # ajouter une liste defilante de mots
    LISTE = Tk.Listbox(width=50, height=10)
    for i in ingredients:
        LISTE.insert(Tk.END, i)
    LISTE.pack()
    AJOUTER_INGREDIENT_LISTE = Tk.Button(text='Ajouter un ingredient', command=lambda: ajouter_ingredient(LISTE.get(), ingredients))
    AJOUTER_INGREDIENT_LISTE.pack()
    # ajouter un champ de texte
    ECRIRE_INGREDIENT = Tk.Entry(width=50)
    ECRIRE_INGREDIENT.pack()
    # ajouter un bouton
    AJOUTER_INGREDIENT_WRITE = Tk.Button(text='Envoyer Ingredient', command=lambda: ajouter_ingredient(ECRIRE_INGREDIENT.get(), ingredients))
    AJOUTER_INGREDIENT_WRITE.pack()
    return CANVAS

def main() -> None:
    # Liste des ingredients présent

    # Fenêtre de l'interface
    root = Tk.Tk()
    root.title("Recherche d'ingrédients")
    canva = canvaAddIngredient().pack()
    root.mainloop()
    

def ajouter_ingredient(name: str, ingredients: list) -> None:
    # la liste est trié pas ordre alphabétique
    if name == '':
        return
    name = name.lower()
    if name not in ingredients:
        ingredients.append(name)
        ingredients.sort()
    print(ingredients)

if __name__ == "__main__":
    main()
else:
    print("GUI.py is not a module")