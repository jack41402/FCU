from bs4 import BeautifulSoup
from urllib.request import urlopen
import requests

url = 'https://www.ptt.cc/bbs/movie/M.1671967711.A.3D7.html'

response = requests.get(url).text
html = BeautifulSoup(response, "html.parser")
main_content = html.find("div", id='main-content')

# 這個會是全部的東西，包含推文
# print(main_content.text)

# extract可以扣掉不要的東西

# 扣掉 作者 標題 時間 (需要可以另外存)
meta = main_content.find_all("div", class_="article-metaline")
for m in meta:
    m.extract()

# 扣掉看板名稱
right_meta = main_content.find_all("div", class_="article-metaline-right")
for m in right_meta:
    m.extract()

# 扣掉推文(需要的話另外處理)
# push = main_content.find_all("div", class_="push")
# for single_push in push:
#     single_push.extract()

print(main_content.text)
