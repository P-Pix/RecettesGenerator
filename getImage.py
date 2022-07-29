import google_images_download as gid
import os
import sys

def main():
    files = os.listdir('./wordlists/nouns/')
    print(files)
    for file in files:
        data = open('./wordlists/nouns/' + file, 'r')
        print(file)
        for word in data:
            # télécharge l'image
            response = gid.googleimagesdownload()
            arguments = {"keywords": word, "limit": 1, "print_urls": True}
            paths = response.download(arguments)
            print(paths)

if __name__ == "__main__":
    main()