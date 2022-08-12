import os
import sys
import requests
import html

from readHTMLTableau import *

def createJSONFile():
    CHARACTERE_SPECIAL_HTML = ["&nbsp;"]
    # on recupere le fichier html index.html
    for i in range(1, 9318):
        url = html.unescape(sys.argv[1] + str(i))
        print(f"url : {url}")
        data = requests.get(url).text
        data = data.split("<ul class=\"products\">")[1].split("</ul>")[0]
        # on sépare chaque <li> dans une liste
        data = data.split("<li>")
        # pour chque element on cherche <div class="list_product_name">
        for i in data:
            if "<a href=" in i:
                # on recupere le nom du produit
                # <a href="/produit/3274080005003/eaux-de-sources-cristaline" title="Eaux de sources - Cristaline -&nbsp;1,5 l">
                name = i.split("<a href=\"")[1].split("\" title=\"")[1].split("\">")[0]
                name = name.replace("\t", "").replace("\n", "").replace(",", ".").replace("%", "").replace(u"\u00A0", "").replace("?", "0").replace("&nbsp;", " ").replace("/", "-")
                link = i.split("<a href=\"")[1].split("\" title=\"")[0]
                # on remplace les caracteres speciaux "&...;" par des espaces
                for j in CHARACTERE_SPECIAL_HTML:
                    name = name.replace(j, "")
                # creer un fichier json ingredients/test/<name>.json
                print(f"Name = {name}")
                with open("ingredients/test/" + name + ".json", 'w') as f:
                    print(f"Link = {sys.argv[1] + link}")
                    text = createJSONContenu(sys.argv[1] + link)
                    f.write(text)
                print (name)
                print ("\n")
            else:
                print("pas de produit")
                pass
if __name__ == "__main__":
    createJSONFile()
else:
    print("readHTMLIndex imported")