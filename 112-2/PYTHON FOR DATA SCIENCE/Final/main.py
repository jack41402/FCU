from crawl import *
from Housing import Housing
import database


if __name__ == '__main__':
    RUN_CRAWLER = True

    if RUN_CRAWLER:
        data = crawl()
        for item in data:
            database.insert(Housing(item))
