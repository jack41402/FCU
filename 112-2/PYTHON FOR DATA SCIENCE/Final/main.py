from msedge.selenium_tools import Edge, EdgeOptions
from selenium import webdriver
from bs4 import BeautifulSoup

# Set up Chrome options
options = EdgeOptions()
options.use_chromium = True
# options.add_argument("--headless")
options.add_argument("headless")

# Set up Edge driver
browser = Edge(executable_path='msedgedriver.exe')
browser.get('https://www.baidu.com')

# Open the webpage
url = "https://www.zillow.com/homes/for_rent/West-Lafayette,-IN_rb/"
browser.get(url)

# Wait for the page to load
browser.implicitly_wait(10)

# Extract data
content = browser.page_source

# Parse with BeautifulSoup
soup = BeautifulSoup(content, 'html.parser')

# Find elements
data = soup.find_all('div', class_='example-class')
for item in data:
    print(item.text)

# Close the driver
browser.quit()
