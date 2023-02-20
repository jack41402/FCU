from bs4 import BeautifulSoup
from urllib.request import urlopen
import requests

# mac的話好像要加入下面兩行
# import ssl
# ssl._create_default_https_context = ssl._create_unverifield_content

url = 'https://www.ptt.cc/bbs/movie/index.html'
# url = 'https://www.ptt.cc/bbs/Gossiping/index.html'

response = requests.get(url).text

# 要爬八卦版的話要加入一些東西|
# 有些網頁會要檢查header中的user-agent，但是大部分都是檢查有填就好
# headers = {"user-agent": "Mozilla/5.0"}
# jar = requests.cookies.RequestsCookieJar()
# jar.set("over18", "1", domain="www.ptt.cc")
# response = requests.get(url, headers=headers, cookies=jar).text

# print(response)

html = BeautifulSoup(response)
# print(html)
for article_entry in html.find_all("div", class_='r-ent'):
    print(article_entry.find("div", class_='title').text)
    # 提供另外一種寫法 select
    print(article_entry.select('.date')[0].text)
    print(article_entry.find("div", class_="title").find("a").get("href"))

