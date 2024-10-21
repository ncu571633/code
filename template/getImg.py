import os
import requests
from tqdm import tqdm

name = "xxx-xxx"
link = "http://www.xxx.com/xxx/"
count = 0

for i in tqdm(range(1, 67), desc="Outer loop"):
    for j in range(1, 13):
        path = f"{link}/{name}/{i}/{name}-{j}.jpg"
        response = requests.get(path)
        if response.status_code == 200:
            with open(f"{name}-{count}.jpg", "wb") as file:
                file.write(response.content)
        print(f"count {count}")
        count += 1
