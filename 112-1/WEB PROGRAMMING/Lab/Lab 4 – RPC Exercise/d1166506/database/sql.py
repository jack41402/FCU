import MySQLdb
import yaml


class SQL:
    def __init__(self):
        self.database = None
        self.connection()

    def connection(self):
        try:
            with open("./database/config.yaml", 'r') as stream:
                config = yaml.load(stream, Loader=yaml.FullLoader)
        except FileNotFoundError:
            print("[ERROR] FILE config.yaml NOT FOUND.")
            return False
        except yaml.YAMLError:
            print("[ERROR] CONFIG FORMAT ERROR.")
            return False
        try:
            self.database = MySQLdb.connect(**config)
        except MySQLdb.Error as e:
            print(f'[ERROR] CANNOT CONNECT TO MySQL DATABASE {config["database"]}: {e}')
            return False

    def command(self, command: str, value: tuple):
        try:
            with self.database.cursor() as cursor:
                cursor.execute(command, value)
                self.database.commit()
                result = cursor.fetchall()
                return result
        except MySQLdb.Error as e:
            self.database.rollback()
            print(f'[ERROR] MySQL error in sql.command {command}: {e}')
        except Exception as e:
            print(f'[ERROR] Other exception in sql.command {command}: {e}')

    def insertInfo(self, table: str, info: dict):
        try:
            if table == "user_information":
                command = "INSERT INTO user_information(id, username, password) VALUES(%s, %s, %s)"
                self.command(command, (info["id"], info["username"], info["password"]))
                print("[INFO] Insert into user_information successfully.")
            elif table == "forum":
                command = "INSERT INTO forum(article_id, title, content, time, user_id) VALUES(%s, %s, %s, NOW(), %s)"
                self.command(command, (info["article_id"], info["title"], info["content"], info["user_id"]))
                print("[INFO] Insert into forum successfully.")
            else:
                return False
        except Exception as e:
            print(f'[ERROR] Other exception in sql.insertInfo: {e}')

    def findMaxId(self, table: str, column: str):
        try:
            command = "SELECT MAX(%s) FROM " + table
            print("Command in findMaxId: ", command)
            result = self.command(command, (column, ))
            print("result in maxId: %s" % result)
            result = result[0][0]
            print("result in maxId: %s" % result)
            if result is None:
                result = 1
            else:
                result += 1
            return result
        except Exception as e:
            print(f'[ERROR] Other exception in sql.findMax: {e}')

    def findInfo(self, table: str, key: str, value: str):
        try:
            command = '''SELECT * FROM %s WHERE %s="%s"'''
            command %= table, key, value
            result = self.command(command, ())
            return result
        except Exception as e:
            print(f'[ERROR] Other exception in sql.findInfo: {e}')

    def getTable(self, table: str):
        try:
            command = "SELECT * FROM " + table
            result = self.command(command, ())
            if result:
                print("result in getTable: ",  result)
            return result
        except Exception as e:
            print(f'[ERROR] Other exception in sql.getTable: {e}')
