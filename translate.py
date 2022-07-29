import googletrans as gt
import os
import sys

def main():
    listeFile = os.listdir('./wordlists/nouns/')
    for file in listeFile:
        data = open('./wordlists/nouns/' + file, 'r')
        for word in data:
            # traduit le mot en français depuis l'anglais
            translator = gt.Translator()
            translation = translator.translate(word, src='en', dest='fr')
            print(word + " = ")

if __name__ == "__main__":
    main()