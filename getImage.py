#!/usr/bin/python

'''
    Download the image of the word and save it in the folder
    ./images/
    Usage:
        python getImage.py
        arguments:
            -w word: the word to download the image
            -f file: the file to get all words
            -d directory: the directory with file to get all words
'''

from google_images_download import google_images_download as gid
import os
import sys

def downloadImage(word: str, directory: str) -> None:
    try: ## try to download the image
        response = gid.googleimagesdownload()
        arguments = {"keywords": word, "limit": 1, "output_directory": directory, "print_urls": True}
        response.download(arguments)
    except: ## if the image is not found, print the error
        print(f'Erreur au mot = {word}')
        errorFile = open('ErrorImage.txt', 'w')
        errorFile.write(f'{word}\n')

def argument() -> None:
    if sys.argv[1] == '-f': ## -f : download all images from a file with a list of terms, one research per line
        for i in range(2, len(sys.argv)):
            data = open(sys.argv[i], 'r')
            for word in data:
                downloadImage(word, './images/')
            data.close()

    elif sys.argv[1] == '-w': ## -w : download all images from a list of terms
        for i in range(2, len(sys.argv)): 
            downloadImage(sys.argv[i], './images')

    elif sys.argv[1] == '-d': ## -d : download all images from a directory with a list of file with a list of terms, one research per line
        for i in range(2, len(sys.argv)):
            files = os.listdir(sys.argv[i])
            for file in files:
                data = open(sys.argv[i] + file, 'r')
                for word in data:
                    downloadImage(word, './images/')
                data.close()
    else:
        print('Wrong arguments')
        sys.exit(1)

if __name__ == "__main__":
    if len(sys.argv) == 1:
        print('Usage:')
        print('    -w word: the word to download the image')
        print('    -f file: the file to get all words')
        print('    -d directory: the directory with file to get all words')
        sys.exit(1)
    argument()
    sys.exit(0)
else:
    print('This is a module, not a script')
    sys.exit(1)