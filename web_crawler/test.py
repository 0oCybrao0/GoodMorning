import requests
from bs4 import BeautifulSoup
from bs4.element import ResultSet, Tag
import json

response = requests.get("https://www.fcu.edu.tw/announcements/")
print(response.status_code)
print(response.text)

soup = BeautifulSoup(response.text, "html.parser")


news_list: ResultSet[Tag] = soup.find_all(class_="a-news-list__main")
print(news_list[0])

data = []

for news in news_list:
    category = news.find(class_="a-news-list__category").text
    date = news.find(class_="a-news-list__date").text.strip()
    unit = news.find(class_="a-news-list__unit").span.text
    title = news.find(class_="a-news-list__title").text
    url = news.find(class_="a-news-list__title").get("href")
    print(category, date, unit, title, url, sep=" | ")

    data.append({
        "date": date,
        "category": category,
        "unit": unit,
        "title": title,
        "url": url,
    })

with open("./result.json", "w+") as f:
    json.dump(data, f, ensure_ascii=False, indent=4)
