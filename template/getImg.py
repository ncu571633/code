import os
import requests
from tqdm import tqdm

name = "xxx-xxx"
link = "http://www.xxx.com/xxx/"
page = 7
imagePerPage = 13
downloadedCount = 0

os.makedirs(name, exist_ok=True)

# tqdm: print progress
for i in tqdm(range(1, page+1), desc="Outer loop"):
    for j in range(1, imagePerPage+1):
        url = f"{link}/{name}/{i}/{name}-{j}.jpg"

        try:
            response = requests.get(url, timeout=10)
            response.raise_for_status()
        except requests.RequestException:
            continue

        if response.status_code == 200:
            with open(f"{name}-{downloadedCount}.jpg", "wb") as file:
                file.write(response.content)
            downloadedCount += 1
