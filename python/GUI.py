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

def help() -> None:
    print("Aide")

def ajoutPhoto() -> None:
    print("Ajout d'une photo")

def menu(root: Tk.Tk) -> None:
    menu = Tk.Menu(root)
    root.config(menu=menu)
    filemenu = Tk.Menu(menu)
    menu.add_cascade(label="File", menu=filemenu)
    filemenu.add_command(label="Open Picture", command=lambda: ajoutPhoto())
    filemenu.add_separator()
    filemenu.add_command(label="Exit", command=root.quit)
    helpmenu = Tk.Menu(menu)
    menu.add_cascade(label="Help", menu=helpmenu)
    helpmenu.add_command(label="About...", command=lambda: help())
    return menu

def addListeIngredient() -> Tk.Listbox:
    ingredients = initList()
    LISTE = Tk.Listbox(width=50, height=10)
    for i in ingredients:
        LISTE.insert(Tk.END, i)
    LISTE.pack()
    return LISTE

def addCanvasRecette(filename: str) -> Tk.Canvas:
    CANVAS = Tk.Canvas(width=500, height=500)
    file = open(filename)
    CANVAS.create_text(250, 250, text=file.read())
    file.close()
    CANVAS.pack()
    return CANVAS

def addButtonAddIngredient(LISTE: Tk.Listbox, ingredients: list) -> Tk.Button:
    AJOUTER_INGREDIENT_LISTE = Tk.Button(text='Ajouter un ingredient', command=lambda: ajouter_ingredient(LISTE.get(), ingredients))
    AJOUTER_INGREDIENT_LISTE.pack()
    return AJOUTER_INGREDIENT_LISTE

def addButtonAddIngredient(ENTRY: Tk.Entry, ingredients: list) -> Tk.Button:
    AJOUTER_INGREDIENT_LISTE = Tk.Button(text='Ajouter un ingredient', command=lambda: ajouter_ingredient(ENTRY.get(), ingredients))
    AJOUTER_INGREDIENT_LISTE.pack()
    return AJOUTER_INGREDIENT_LISTE

def addEntryCase() -> Tk.Entry:
    ENTRY = Tk.Entry(width=50)
    ENTRY.pack()
    return ENTRY

def main() -> None:
    # Fenêtre de l'interface
    ingredients = []

    root = Tk.Tk()
    root.title("Recherche d'ingrédients")
    menu(root)
    INGREDIENT = addListeIngredient()
    AJOUTER_INGREDIENT_LISTE = addButtonAddIngredient(INGREDIENT, ingredients)
    ENTRY = addEntryCase()
    AJOUTER_INGREDIENT_ENTRY = addButtonAddIngredient(ENTRY, ingredients)
    RECETTE = addCanvasRecette("recettes/hamburger.csv")
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