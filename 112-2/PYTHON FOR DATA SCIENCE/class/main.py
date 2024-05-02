import json

json_file_path = r"D:\GitHub\FCU\112-2\PYTHON FOR DATA SCIENCE\class\config.json"

try:
    with open(json_file_path, 'r', encoding='utf-8-sig') as j:
        contents = json.loads(j.read())
        print(contents)
except FileNotFoundError:
    print("The file was not found. Please check the file path.")
except json.JSONDecodeError as e:
    print("Failed to decode JSON from the file:", e)
except Exception as e:
    print("An error occurred:", e)
