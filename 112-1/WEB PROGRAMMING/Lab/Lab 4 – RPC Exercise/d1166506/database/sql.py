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
                maxId = self.findMaxId()
                if not maxId:
                    maxId = 0
                print("maxId: %s" % maxId)
                self.command(command, (maxId + 1, info["username"], info["password"]))
            else:
                return False
        except Exception as e:
            print(f'[ERROR] Other exception in sql.insertInfo: {e}')

    def findMaxId(self):
        try:
            command = "SELECT MAX(id) FROM user_information"
            result = self.command(command, ())
            print(result)
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