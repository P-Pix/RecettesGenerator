import os
import sys
import html
import requests

def createJSONContenu(url: str) -> str:
    print("Create JSON Contenu\n-----------------")
    url = (html.unescape(url))
    data = requests.get(url).text
    # garde que le contenu de <table>...</table>
    data = data.split("<table id=\"nutrition_data_table\" class=\"data_table\">")[1].split("</table>")[0]
    # divise le contenu par <tr>
    data = data.split("</tr>")
    label = ""
    value = ""
    json = "{"
    counter = 0
    for i in data:
        # class="nutriment_label"
        if "<td class=\"nutriment_label\">" in i:
            label = i.split("<td class=\"nutriment_label\">")[1].split("</td>")[0]
            # retire les \t et les \n
            label = label.replace("\t", "").replace("\n", "")
            #print(f"il y a un label : {label}")
        # class="nutriment_value " jusqu'à ">" </td>
        if "<td class=\"nutriment_value \"" in i:
            value = i.split("<td class=\"nutriment_value \"")[1].split(">")[1].split("</td>")[0].split("<")[0]
            value = value.replace("\t", "").replace("\n", "").replace(" ", "").replace(",", ".").replace("%", "").replace(u"\u00A0", "").replace("?", "0")
            # separe les lettres et les chiffres
            number = ""
            unit = ""
            for j in value:
                if j.isalpha():
                    unit += j
                else:
                    number += j
            #print(f"il y a une value : \'{number}\' avec une unité \'{unit}\'")
        if label != "" and value != "":
            #print (f"Label : {label}\nValue : {number}, {unit}\n")

            json += ("\"" + label + "\": { \"unity\": \"" + unit + "\",\n\"value\": " + number  + "}")
            if counter < len(data) - 2:
                json += ",\n"
            else:
                json += "\n}"
            label = ""
            value = ""
        counter += 1
    print(json)
    print("-----------------\nFin Create JSON Contenu\n")
    return json

if __name__ == "__main__":
    createJSONContenu()
else:
    print("readHTMLIndex imported")