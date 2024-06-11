from selenium import webdriver
from selenium.webdriver.edge.options import Options
from selenium.common.exceptions import TimeoutException, WebDriverException
from bs4 import BeautifulSoup
import time


def crawl():
    # Set up Edge driver options
    options = Options()
    # options.add_argument("headless")

    # Initialize the Edge driver
    try:
        driver = webdriver.Edge(options=options)
    except WebDriverException as e:
        print(f"Error initializing Edge driver: {e}")
    else:
        url = "https://offcampushousing.purdue.edu/housing/"
        data = []  # Initialize as an empty list to store all items
        for i in range(1, 6):
            try:
                # Open the webpage
                driver.get(url + f"page-{i}")
                print(f"Page {i} loaded successfully.")
            except TimeoutException:
                print("The request timed out. The page took too long to load.")
            except WebDriverException as e:
                print(f"WebDriver error occurred: {e}")
            except Exception as e:
                print(f"An error occurred: {e}")
            else:
                # Wait for the page to load
                driver.implicitly_wait(5)
                # Extract data
                content = driver.page_source
                # Parse with BeautifulSoup
                soup = BeautifulSoup(content, "html.parser")
                # Find elements
                data.extend(soup.find_all("li", class_="list-result-item"))

        # Close the driver
        driver.quit()

        return data
