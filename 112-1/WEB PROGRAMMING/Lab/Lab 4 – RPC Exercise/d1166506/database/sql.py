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
            elif table == "forum":
                command = "INSERT INTO forum(id, title, content, date, user_id) VALUES(%s, %s, %s, %s, %s)"
                self.command(command, (info["id"], info["title"], info["content"]))
            else:
                return False
        except Exception as e:
            print(f'[ERROR] Other exception in sql.insertInfo: {e}')

    def findMaxId(self, table: str):
        try:
            command = "SELECT MAX(id) FROM %s"
            result = self.command(command, (table, ))
            print("result: %s" % result)
            if not result:
                result = 1
            else:
                result += 1
            print("maxId: %s" % result)
            return result[0][0]
        except Exception as e:
            print(f'[ERROR] Other exception in sql.findMax: {e}')

    def findInfo(self, table: str, key: str, value: str):
        try:
            command = '''SELECT * FROM %s WHERE %s="%s"'''
            command %= table, key, value
            print(command)
            result = self.command(command, ())
            print(result)
            return result
        except Exception as e:
            print(f'[ERROR] Other exception in sql.findInfo: {e}')

    def getTable(self, table: str):
        try:
            command = "SELECT * FROM %s"
            result = self.command(command, (table, ))
            print(result)
            return result
        except Exception as e:
            print(f'[ERROR] Other exception in sql.getTable: {e}')
