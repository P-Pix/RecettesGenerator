#!/usr/bin/python

from googletrans import Translator as Ts
import os
import sys

def translate(word: str) -> str:
    word = word.replace('\n', '')
    try:
        translator = Ts()
        language = translator.detect(word)
        print(f"\'{word}\' = \'{language.lang}\'")
        translation = translator.translate(word, src=language.lang, dest="fr")
        print(f"\'{word}\' = \'{translation.text}\'")
        return translation.text
    except:
        errorFile = open('ErrorTranslate.txt', 'a')
        print(f'Erreur au mot = \'{word}\'')
        errorFile.write(f'{word}\n')
        errorFile.close()
        exception = sys.exc_info()
        print(exception)
        return word

def printArgument() -> None:
    print('Usage:')
    print("\t-w word: the word to translate")
    print("\t-f file: the file to translate")
    print("\t-d directory: the directory with file to translate")
        
def argument() -> None:
    if sys.argv[1] == '-w':
        for i in range(2, len(sys.argv)):
            print(f'{sys.argv[i]} = {translate(sys.argv[i])}')
    elif sys.argv[1] == '-f':
        for i in range(2, len(sys.argv)):
            data = open(sys.argv[i], 'r')
            translateFile = open(sys.argv[i] + '_fr', 'w')
            for word in data:
                translateFile.write(translate(word) + '\n')
            data.close()
            translateFile.close()
    elif sys.argv[1] == '-d':
        for i in range(2, len(sys.argv)):
            files = os.listdir(sys.argv[i])
            for file in files:
                data = open(sys.argv[i] + file, 'r')
                translateFile = open(sys.argv[i] + file + '_fr', 'w')
                for word in data:
                    translateFile.write(translate(word.er) + '\n')
                data.close()
                translateFile.close()
    else:
        print('Wrong arguments')
        printArgument()
        sys.exit(1)

if __name__ == "__main__":
    if len(sys.argv) == 1:
        printArgument()
        sys.exit(1)
    else:
        argument()
        sys.exit(0)