from google_images_download import google_images_download as gid
import os
import sys

def main():
    files = os.listdir('./wordlists/nouns/')
    errorfile = open('errorimage.txt', 'w')
    print(files)
    for file in files:
        data = open('./wordlists/nouns/' + file, 'r')
        print(file)
        for word in data:
            print(word)
            # télécharge l'image
            try:
                response = gid.googleimagesdownload()
                # retirer a word '\n'
                word = word.replace('\n', '')
                arguments = {"keywords": word, "limit": 1, "print_urls": True}
                paths = response.download(arguments)
                print(paths)
                print(f'path = {paths[0][word][0]}')
                # copie l'image dans le dossier de destination
                os.system(f'cp {paths[0][word][0]} ./images/{word}.jpg')
                # supprime l'image téléchargée
                os.system(f'rm {paths[0][word][0]}')
            except:
                print(f'Erreur au mot = {word} dans le fichier {file}')
                errorfile.write(f'Erreur au mot = {word} dans le fichier {file}\n')

        data.close()
    os.system('rm -rf ./downloads')

if __name__ == "__main__":
    main()