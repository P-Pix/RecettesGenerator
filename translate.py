#!/usr/bin/python

from googletrans import Translator as Ts
import os

def main():
    listeFile = os.listdir('./wordlists/nouns/')
    errorFile = open('errorsecondfood.txt', 'w')
    for file in listeFile:
        data = open('./wordlists/nouns/' + file, 'r')
        listemot = []
        print(file)
        for word in data:
            # traduit le mot en français depuis l'anglais
            try:
                translator = Ts()
                language = translator.detect(word)
                translation = translator.translate(word, src=language, dest='fr')
                listemot.append(translation.text)
            except:
                print(f'Erreur au mot = {word} dans le fichier {file}')
                errorFile.write(f'Erreur au mot = {word} dans le fichier {file}\n')
        data.close()
        # écrit le fichier en français
        data = open('./food-identicon/ingredients.txt', 'w')
        for word in listemot:
            data.write(word + '\n')
        data.close()

if __name__ == "__main__":
    main()