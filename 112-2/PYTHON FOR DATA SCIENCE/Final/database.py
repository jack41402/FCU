import yaml
from tinydb import TinyDB, Query, Storage
from Housing import Housing


class YAMLStorage(Storage):
    def __init__(self, filename):
        self.filename = filename

    def read(self):
        with open(self.filename) as handle:
            try:
                data = yaml.safe_load(handle.read())
                return data
            except yaml.YAMLError:
                return None

    def write(self, data):
        with open(self.filename, 'w+') as handle:
            yaml.dump(data, handle)

    def close(self):
        pass


def insert(house: Housing):
    try:
        database = TinyDB('database.yaml', storage=YAMLStorage)
        query = Query()
        result = database.search(query.property_name == str(house.property_name))

        if not result:
            database.insert(house.__dict__)
            print(f"Inserted: {house.__dict__}")
        else:
            print(f"Duplicate found, skipping insertion: {house.property_name}")
    except Exception as e:
        print(e)


if __name__ == '__main__':
    database = TinyDB('database.yaml', storage=YAMLStorage)
    query = Query()
    for item in database.all():
        print(item)
