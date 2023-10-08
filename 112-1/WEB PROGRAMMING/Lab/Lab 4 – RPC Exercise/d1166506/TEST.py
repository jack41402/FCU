from database import sql

user = sql.SQL()
try:
    username = "jack3"
    password = "pass"
    # user.insertInfo("user_information", {"username": username, "password": password})
    result = user.findInfo("user_information", "username", "jack3")
    if len(result) == 0:
        print(f"Find result: {result}")
    else:
        print("Password: %s" % result[0][2])
except Exception as e:
    print(f'[ERROR] TEST: {e}')